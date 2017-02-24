
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

//-----------------------------------------------------------

IplImage* doCanny(
    IplImage* in,
    double    lowThresh,
    double    highThresh,
    double    aperture)
{
    IplImage* out = cvCreateImage(
        cvGetSize( in ),
        in->depth, //IPL_DEPTH_8U,
        1);

    cvCanny(in,out,lowThresh,highThresh,aperture );

    return(out);
};
//-----------------------------------------------------------

IplImage* doPyrDown(IplImage* in)
{

    // Best to make sure input image is divisible by two.
    assert( in->width%2 == 0 && in->height%2 == 0 );

    IplImage* out = cvCreateImage(
        cvSize( in->width/2, in->height/2 ),
        in->depth,
        in->nChannels
    );
    
    cvPyrDown(in,out);

    return(out);
};

//-----------------------------------------------------------
int main( int argc, char** argv )
{
  IplImage* img_rgb  = cvLoadImage( argv[1] );
  IplImage* img_gry  = cvCreateImage( cvSize( img_rgb->width,img_rgb->height ), img_rgb->depth, 1);

  //start an image processing pipe
  cvCvtColor(img_rgb, img_gry ,CV_BGR2GRAY);
  IplImage* img_pyr  = doPyrDown( img_gry);
  IplImage* img_pyr2 = doPyrDown( img_pyr);
  IplImage* img_cny  = doCanny( img_pyr2, 10, 100, 3 );

  // display results from each stage
  cvNamedWindow("Gray", CV_WINDOW_AUTOSIZE );
  cvNamedWindow("Pyr", CV_WINDOW_AUTOSIZE );
  cvNamedWindow("Canny", CV_WINDOW_AUTOSIZE );
  
  cvShowImage("Gray", img_gry );
  cvShowImage("Pyr", img_pyr2 );
  cvShowImage("Canny", img_cny );
  
  cvWaitKey(0);
  
  cvReleaseImage( &img_rgb);
  cvReleaseImage( &img_gry);
  cvReleaseImage( &img_pyr);
  cvReleaseImage( &img_pyr2);
  cvReleaseImage( &img_cny);
  
  cvDestroyWindow("Gray");
  cvDestroyWindow("Pyr");
  cvDestroyWindow("Canny");
}
