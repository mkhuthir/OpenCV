
#include <cv.h>
#include <highgui.h>

int main(int argc, char** argv)
{
    IplImage* src;
    double M; 
    if( argc < 3)
        {
            printf("usage: ./logpolar imagefilename scalefactor\n");
            return -1;
        }
    src=cvLoadImage(argv[1],1);
    M = atof(argv[2]);

    IplImage* dst = cvCreateImage( cvGetSize(src), 8, 3 );
    IplImage* src2 = cvCreateImage( cvGetSize(src), 8, 3 );

    cvLogPolar( src,  dst, cvPoint2D32f(src->width/2,src->height/2),M, CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS );
    cvLogPolar( dst, src2, cvPoint2D32f(src->width/2,src->height/2),M, CV_INTER_LINEAR+CV_WARP_INVERSE_MAP );
    
    cvNamedWindow( "log-polar", 1 );
    cvShowImage( "log-polar", dst );
    cvNamedWindow( "inverse log-polar", 1 );
    cvShowImage( "inverse log-polar", src2 );

    cvWaitKey();
   
    cvReleaseImage(&src);
    cvReleaseImage(&src2);
    cvReleaseImage(&dst);
    cvDestroyWindow("log-polar");
    cvDestroyWindow("inverse log-polar");

    return 0;
}
