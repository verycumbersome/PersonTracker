#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, const char** argv )
{
	VideoCapture cap1(0);
	Mat output;

	if (! cap1.isOpened()){
		cout << "Cannot open camera.";
	}

	while(1){
		Mat cameraFrame;
		Mat cameraResize;

		cap1.read(cameraFrame);

		resize(cameraFrame, cameraResize, Size(), 0.5, 0.5, CV_INTER_AREA);

		inRange(cameraResize, Scalar(0,50,0), Scalar(200,200,100), output);

		imshow("original", cameraResize);
		imshow("mask", output);

		if (waitKey(30) >= 0){
			break;
		}
	}
	return 0;
}
