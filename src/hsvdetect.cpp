#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

 int main( int argc, char** argv )
 {
    VideoCapture cap(0); //capture the video from web cam

    if ( !cap.isOpened() )  // if not success, exit program
    {
        cout << "Cannot open the web cam" << endl;
        return -1;
    }

    namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

    int iLowH = 0;
    int iHighH = 179;

    int iLowS = 0; 
    int iHighS = 255;

    int iLowV = 0;
    int iHighV = 255;

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
        
        //show the original & Thresholded images
        imshow("Original", imgOriginal);
        imshow("Thresholded Image", imgThresholded);
        
        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
            {
                cout << "esc key is pressed by user" << endl;
                break; 
            }
        }


    // Exit
    cvDestroyWindow("Control");
    cvDestroyWindow("Threshold Image");
    cvDestroyWindow("Original");
    return 0;

}