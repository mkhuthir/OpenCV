
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int g_switch_value = 1;
void switch_off_function() {printf("Pause\n");}; //YOU COULD DO SOMETHING WITH THESE FUNCTIONS TOO
void switch_on_function() {printf("Run\n");}; 

void switch_callback( int position ) {
  if( position == 0 ) {
    switch_off_function();
  } else {
    switch_on_function();
  }
}
 
int main( int argc, char* argv[] ) {
  	IplImage *frame;
   CvCapture* g_capture         = NULL;
   if((argc < 2 )|| !(g_capture = cvCreateFileCapture( argv[1] ))){
   	printf("Failed to open %s\n",argv[1]);
   	return -1;
   }


  cvNamedWindow( "Example4_2", 1 );
 
  // Create the trackbar.  We give it a name,
  // and tell it the name of the parent window.
  //
  cvCreateTrackbar(
    "Switch",
    "Example4_2",
    &g_switch_value,
    1,
    switch_callback
  );
 
  // This will just cause OpenCV to idle until 
  // someone hits the "Escape" key.
  //
  while( 1 ) {
    if(g_switch_value){
		 frame = cvQueryFrame( g_capture );
   	 if( !frame ) break;
    }
    cvShowImage( "Example4_2", frame);
    if(cvWaitKey(10)==27 ) break;
  }
  

  cvReleaseCapture( &g_capture );
  cvDestroyWindow( "Example4_2" );
  return(0);

}
