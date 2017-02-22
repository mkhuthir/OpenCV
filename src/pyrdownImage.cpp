
#include "cv.h"
#include "highgui.h"

IplImage* doPyrDown(IplImage* in)
{

    assert( in->width%2 == 0 && in->height%2 == 0 );

    IplImage* out = cvCreateImage( 
        cvSize( in->width/2, in->height/2 ),
        in->depth,
        in->nChannels
    );
    cvPyrDown( in, out );
    return( out );
};

int main( int argc, char** argv )
{
  	if(argc<2)
		{
		printf("Usage: ./pyrdownImage filename\n\nExiting..\n");
		return -1;
		};

    IplImage* img = cvLoadImage( argv[1] );

    IplImage* img2 = cvCreateImage( cvSize( img->width/2,img->height/2 ), img->depth, img->nChannels);

    cvNamedWindow(argv[1], CV_WINDOW_AUTOSIZE );
    cvNamedWindow("PyrDown", CV_WINDOW_AUTOSIZE );
  
    img2 = doPyrDown( img );

    cvShowImage(argv[1], img );
    cvShowImage("PyrDown", img2 );
  
    cvWaitKey(0);
  
    cvReleaseImage( &img );
    cvReleaseImage( &img2 );
  
    cvDestroyWindow(argv[1]);
    cvDestroyWindow("PyrDown");

    printf("Exiting..\n");
    return 0;
}
