/*
 * smoothImage.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: mkhuthir
 */

#include <cv.h>
#include <highgui.h>

int main( int argc, char** argv )
{
    
    if(argc<2)
   {
	  printf("\nUsage: ./smoothImage [imagefile]\n\nExiting..\n");
	  return -1;
   };

    printf("Reading image file: %s\n",argv[1]);
    IplImage* img = cvLoadImage( argv[1] );
  
    cvNamedWindow( argv[1], CV_WINDOW_AUTOSIZE );
    cvNamedWindow( "smoothed", CV_WINDOW_AUTOSIZE );
    
    cvShowImage( argv[1], img );
    
    IplImage* out = cvCreateImage(
        cvGetSize(img),
        IPL_DEPTH_8U,
        3
    );
    
    cvSmooth( img, out, CV_GAUSSIAN, 5,5 );
    cvSmooth( out, out, CV_GAUSSIAN, 5, 5);
    cvSmooth( out, out, CV_GAUSSIAN, 5, 5);
    cvSmooth( out, out, CV_GAUSSIAN, 5, 5);

    cvShowImage( "smoothed", out );
    
    cvReleaseImage( &out );
    cvReleaseImage( &img );
    
    cvWaitKey( 0 ); 
    
    cvDestroyWindow(argv[1]);
    cvDestroyWindow("smoothed");
  
    printf( "Exiting.. \n" );
    return 0;
}

