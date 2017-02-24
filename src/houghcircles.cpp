
/*
void HoughCircles(InputArray image, OutputArray circles, int method, double dp, double minDist, double param1=100, double param2=100, int minRadius=0, int maxRadius=0 );
*/

#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int main(int argc, char** argv) {

  IplImage* image = cvLoadImage(argv[1],CV_LOAD_IMAGE_GRAYSCALE);
  IplImage* src = cvLoadImage( argv[1] ); //Changed for prettier show in color
  CvMemStorage* storage = cvCreateMemStorage(0);
  cvSmooth(image, image, CV_GAUSSIAN, 5, 5 );
  CvSeq* results = cvHoughCircles(image,storage,CV_HOUGH_GRADIENT,4,image->width/10); 
  
  for( int i = 0; i < results->total; i++ ) {

    float* p = (float*) cvGetSeqElem( results, i );
    CvPoint pt = cvPoint( cvRound( p[0] ), cvRound( p[1] ) );
    cvCircle(src,pt,cvRound( p[2] ),CV_RGB(0xff,0,0));
    
  }
  
  cvNamedWindow( "cvHoughCircles", 1 );
  cvShowImage( "cvHoughCircles", src);
  
  cvWaitKey(0);
  
  cvReleaseImage(&image);
  cvReleaseImage(&src);
  cvDestroyWindow( "cvHoughCircles" );
  
  return 0;
}

