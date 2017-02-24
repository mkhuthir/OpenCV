
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int main()
{
  // Create an OpenCV Matrix containing some fixed data.
  //
  float vals[] = { 0.866025, -0.500000, 0.500000, 0.866025};
   
  CvMat rotmat;
   
  cvInitMatHeader(
    &rotmat,
    2,
    2, 
    CV_32FC1,
    vals
  );
  
  printf("cvMat matrix initialized\n");

  return (0);
}
