#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

 int main( int argc, char** argv )
 {
    VideoCapture cap(0); //capture the video from webcam

    if ( !cap.isOpened() )  // if not success, exit program
    {
        cout << "Cannot open the web cam" << endl;
        return -1;
    }

    namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

    int iLowH = 27;
    int iHighH = 153;

    int iLowS = 96; 
    int iHighS = 179;

    int iLowV = 190;
    int iHighV = 238;

    //Create trackbars in "Control" window
    //Hue (0 - 179)
    cvCreateTrackbar("LowH","Control",&iLowH,179); 
    cvCreateTrackbar("HighH","Control",&iHighH,179);
    //Saturation (0 - 255)
    cvCreateTrackbar("LowS","Control",&iLowS,255); 
    cvCreateTrackbar("HighS","Control",&iHighS,255);
    //Value (0 - 255)
    cvCreateTrackbar("LowV","Control",&iLowV, 255); 
    cvCreateTrackbar("HighV","Control",&iHighV,255);
    //Add image to control window to set its size!
    IplImage* spacer=cvCreateImage(cvSize(500,2),IPL_DEPTH_8U,1);
    cvZero(spacer);
    cvShowImage("Control",spacer);

    int iLastX = -1; 
    int iLastY = -1;

    //Capture a temporary image from the camera
    Mat imgTmp;
    cap.read(imgTmp); 

    //Create a black image with the size as the camera output
    Mat imgLines = Mat::zeros( imgTmp.size(), CV_8UC3 );;


    while (true)
    {
        Mat imgOriginal;

        // read a new frame from video, break if failed
        bool bSuccess = cap.read(imgOriginal);
        if (!bSuccess)
            {
                cout << "Cannot read a frame from video stream" << endl;
                break;
            }

        //Convert the captured frame from BGR to HSV
        Mat imgHSV;    
        cvtColor(imgOriginal,imgHSV,COLOR_BGR2HSV);

        //Threshold the image
        Mat imgThresholded;   
        inRange(imgHSV, Scalar(iLowH,iLowS,iLowV),Scalar(iHighH,iHighS,iHighV),imgThresholded);
            
        //morphological opening (remove small objects from the foreground)
        erode( imgThresholded,imgThresholded,getStructuringElement(MORPH_ELLIPSE,Size(5,5)));
        dilate(imgThresholded,imgThresholded,getStructuringElement(MORPH_ELLIPSE,Size(5,5))); 

        //morphological closing (fill small holes in the foreground)
        dilate(imgThresholded,imgThresholded,getStructuringElement(MORPH_ELLIPSE,Size(5,5))); 
        erode( imgThresholded,imgThresholded,getStructuringElement(MORPH_ELLIPSE,Size(5,5)));

        //Calculate the moments of the thresholded image
        Moments oMoments = moments(imgThresholded);
        double dM01 = oMoments.m01;
        double dM10 = oMoments.m10;
        double dArea = oMoments.m00;

        // if the area <= 10000, I consider that the there are no object in the image and it's because of the noise, the area is not zero 
        if (dArea > 10000)
            {
                //calculate the position of the ball
                int posX = dM10 / dArea;
                int posY = dM01 / dArea;        
                    
                if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0)
                    {
                        //Draw a red line from the previous point to the current point
                        circle(imgLines, Point(posX, posY), 5, Scalar(0,255,0),1,LINE_8,0);
                    }

                    iLastX = posX;
                iLastY = posY;
            }

        imshow("Thresholded Image", imgThresholded); //show the thresholded image

        imgOriginal = imgOriginal + imgLines;
        imshow("Original", imgOriginal); //show the original image

        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
            {
                    cout << "esc key is pressed by user" << endl;
                    break; 
            }
    }   

    return 0;
}