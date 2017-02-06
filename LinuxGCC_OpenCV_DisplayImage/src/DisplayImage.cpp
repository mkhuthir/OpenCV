/*
 * DisplayImage.cpp
 *
 *  Created on: Feb 6, 2017
 *      Author: mkhuthir
 */

#include <cv.h>
#include <highgui.h>

using namespace cv;

int main( int argc, char** argv )
{
  Mat image;

  if(argc<2)
   {
	  printf("\nUsage: ./DisplayImage [imagefile]\n\nExiting..");
	  return -1;
   };

  printf("Reading image file: %s\n",argv[1]);
  image = imread( argv[1], 1 );

  if( !image.data )
    {
      printf( "No image data ! \n" );
      return -1;
    };

  namedWindow( "Display Image", CV_WINDOW_AUTOSIZE );
  imshow( "Display Image", image );

  waitKey(0);

  cvDestroyWindow("Display Image");

  printf( "Exiting.. \n" );
  return 0;
}


