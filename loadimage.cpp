#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( )
{ 
    Mat image = imread("dat/fruits.jpg", CV_LOAD_IMAGE_COLOR);                                

    namedWindow( "Display window", WINDOW_AUTOSIZE );    

    imshow( "Display window", image );                   

    cout << image;

    waitKey(0);                                          

    return 0;
}
