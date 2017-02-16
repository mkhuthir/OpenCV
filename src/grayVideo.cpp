#include "cv.h"
#include "highgui.h"
#include <stdio.h>

main( int argc, char* argv[] ) {

    cvNamedWindow( "Video", CV_WINDOW_AUTOSIZE );
    cvNamedWindow( "Log_Polar", CV_WINDOW_AUTOSIZE );
    cvNamedWindow( "Gray", CV_WINDOW_AUTOSIZE );

    CvCapture* capture = cvCreateFileCapture( argv[1] );
    if (!capture){
        return -1;
    }

    IplImage* bgr_frame;
    double fps = cvGetCaptureProperty (
        capture,
        CV_CAP_PROP_FPS
    );

	printf("fps=%d\n",(int)fps);

    CvSize size = cvSize(
        (int)cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH),
        (int)cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT)
    );
    
    printf("frame (w, h) = (%d, %d)\n",size.width,size.height);


    IplImage* logpolar_frame    = cvCreateImage(size, IPL_DEPTH_8U,3);
    IplImage* gray_frame        = cvCreateImage(size, IPL_DEPTH_8U,1);
 
    while( (bgr_frame=cvQueryFrame(capture)) != NULL ) {
        
        cvConvertImage(bgr_frame, gray_frame, CV_RGB2GRAY);
        
        cvLogPolar( bgr_frame, logpolar_frame,
                    cvPoint2D32f(bgr_frame->width/2,
                    bgr_frame->height/2), 
                    40, 
                    CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS );

        cvShowImage("Video", bgr_frame );
        cvShowImage("Log_Polar", logpolar_frame );
        cvShowImage("Gray", gray_frame);

        char c = cvWaitKey(33);
        if( c == 27 ) break;
    }

    cvReleaseImage( &gray_frame );
    cvReleaseImage( &logpolar_frame );
    cvReleaseCapture( &capture );

    return (0);
}
