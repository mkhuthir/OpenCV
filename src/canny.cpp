
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

IplImage* doCanny(
    IplImage* in,
    double    lowThresh,
    double    highThresh,
    double    aperture)
{
    if (in->nChannels != 1)
        return(0);

    IplImage* out = cvCreateImage( 
        cvGetSize( in ),
        in->depth, //IPL_DEPTH_8U,    
        1);
        
    cvCanny( in, out, lowThresh, highThresh, aperture );
    return( out );
};

int main( int argc, char** argv )
{

    if(argc<2)
        {
        printf("Usage: ./canny imagefilename\n\nExiting..\n");
        return -1;
        };

    IplImage* img_rgb = cvLoadImage( argv[1] );

    IplImage* img_gry = cvCreateImage( cvSize( img_rgb->width,img_rgb->height ), img_rgb->depth, 1);

    cvCvtColor(img_rgb, img_gry ,CV_BGR2GRAY);
    
    cvNamedWindow("RGB", CV_WINDOW_AUTOSIZE );
    cvNamedWindow("Gray", CV_WINDOW_AUTOSIZE );
    cvNamedWindow("Canny", CV_WINDOW_AUTOSIZE );

    IplImage* img_cny = doCanny( img_gry, 10, 100, 3 );

    cvShowImage("RGB", img_rgb );
    cvShowImage("Canny", img_cny );
    cvShowImage("Gray", img_gry );

    cvWaitKey(0);

    cvReleaseImage( &img_rgb);
    cvReleaseImage( &img_gry);
    cvReleaseImage( &img_cny);

    cvDestroyWindow("RGB");
    cvDestroyWindow("Gray");
    cvDestroyWindow("Canny");
    
    printf("Exiting..\n");
    return 0;
}
