
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int main( int argc, char** argv )
{
	if(argc<2)
		{
		printf("Usage: ./showimage imagefile\n\nExiting..\n");
		return -1;
		};
	
    IplImage* img = cvLoadImage(argv[1]);

    cvNamedWindow(argv[1],CV_WINDOW_AUTOSIZE );
    cvShowImage(argv[1],img);

	cvWaitKey(0);

	cvDestroyWindow( "ReadAVI" );

	printf("Exiting..\n");

	return 0;
}


