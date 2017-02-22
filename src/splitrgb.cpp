
#include <stdio.h>
#include <cv.h>
#include <highgui.h>

int main(int argc, char** argv)
{

  // Create a named window with a the name of the file.
  cvNamedWindow( argv[1], 1 );
  cvNamedWindow( "R", 1 );
  cvNamedWindow( "G", 1 );
  cvNamedWindow( "B", 1 );

  // Load the image from the given file name.
  IplImage* src = cvLoadImage( argv[1] );
  IplImage* r = cvCreateImage( cvGetSize(src), IPL_DEPTH_8U, 1 );
  IplImage* g = cvCreateImage( cvGetSize(src), IPL_DEPTH_8U, 1 );
  IplImage* b = cvCreateImage( cvGetSize(src), IPL_DEPTH_8U, 1 );

  cvSplit( src, b, g, r, NULL );

  // Show the image in the named window
  cvShowImage( argv[1], src );
  cvShowImage( "R", r );
  cvShowImage( "G", g );
  cvShowImage( "B", b );

  // Idle until the user hits the "Esc" key.
  while( 1 ) { if( (cvWaitKey( 10 )&0x7f) == 27 ) break; }

  cvDestroyWindow( argv[1] );
  cvDestroyWindow( "R" );
  cvDestroyWindow( "G" );
  cvDestroyWindow( "B" );

  cvReleaseImage( &src );
  cvReleaseImage( &r );
  cvReleaseImage( &g );
  cvReleaseImage( &b );
}
