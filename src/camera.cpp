#include "cv.h"
#include "highgui.h"

int main( int argc, char** argv ) { 
    cvNamedWindow( "Camera", CV_WINDOW_AUTOSIZE );
    CvCapture* capture;
    if (argc==1) {
        capture = cvCreateCameraCapture( 0 );
    } else {
        capture = cvCreateFileCapture( argv[1] );
    }
    assert( capture != NULL );

    IplImage* frame;
    while(1) {
        frame = cvQueryFrame( capture );
        if( !frame ) break;
        cvShowImage( "Camera", frame );
        char c = cvWaitKey(10);
        if( c == 27 ) break;
    }
    cvReleaseCapture( &capture );
    cvDestroyWindow( "Camera" );
}
