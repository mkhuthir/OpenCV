
#include "opencv2/highgui/highgui.hpp"
#include <fstream>
#include <iostream>

using namespace cv;
using namespace std;

int        g_slider_position = 0;
CvCapture* g_capture         = NULL;

void onTrackbarSlide(int pos) {
    cvSetCaptureProperty(
        g_capture,
        CV_CAP_PROP_POS_FRAMES,
        pos
    );
}


int getAVIFrames(char * fname) { 
    char tempSize[4];

    ifstream  videoFile( fname , ios::in | ios::binary );

    if ( !videoFile ) {
      cout << "Couldn’t open the input file " << fname << endl;
      exit( 1 );
    }

    videoFile.seekg( 0x30 , ios::beg );
    videoFile.read( tempSize , 4 );
    int frames = (unsigned char ) tempSize[0] + 0x100*(unsigned char ) tempSize[1] + 0x10000*(unsigned char ) tempSize[2] +    0x1000000*(unsigned char ) tempSize[3];
    videoFile.close(  );
    return frames;
}


int main( int argc, char** argv ) {
    cvNamedWindow( "Example2_3", CV_WINDOW_AUTOSIZE );
    g_capture = cvCreateFileCapture( argv[1] );
    IplImage *foo = cvQueryFrame( g_capture);


    int frames = (int) cvGetCaptureProperty(
        g_capture,
        CV_CAP_PROP_FRAME_COUNT
    );
    
    int tmpw = (int) cvGetCaptureProperty(
        g_capture,
        CV_CAP_PROP_FRAME_WIDTH
    );

    int tmph = (int) cvGetCaptureProperty(
        g_capture,
        CV_CAP_PROP_FRAME_HEIGHT
    );

    printf("opencv frames %d w %d h %d\n",frames,tmpw,tmph);

    frames = getAVIFrames(argv[1]);

    printf("hacked frames %d w %d h %d\n",frames,tmpw,tmph);

    cvCreateTrackbar(
        "Position",
        "Example2_3",
        &g_slider_position,
        frames,
        onTrackbarSlide
    );
    IplImage* frame;
    frames = 0;
    while(1) {
        frame = cvQueryFrame( g_capture );
        if( !frame ) break;

	frames++;
	printf("\nFrame number=%d\n",frames);
        cvSetTrackbarPos("Position","Example2_3",frames);
        cvShowImage( "Example2_3", frame );
        char c = (char)cvWaitKey(10);
        if( c == 27 ) break;
    }
    cvReleaseCapture( &g_capture );
    cvDestroyWindow( "Example2_3" );
    return(0);
}
