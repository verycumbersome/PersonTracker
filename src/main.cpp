#include <opencv/cv.h>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "facialDetection.h"

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

		Mat original = cameraResize.clone();
		Mat gray;
		CascadeClassifier face_cascade = CascadeClassifier("/usr/local/Cellar/opencv/2.4.13.2/share/OpenCV/haarcascades/haarcascade_frontalface_default.xml");

		cvtColor(original, gray, CV_BGR2GRAY);
		vector< Rect_<int> > faces;

		inRange(cameraResize, Scalar(0,50,0), Scalar(200,200,100), output);

		facialDetection::detectFaceInImage(gray, face_cascade);
		imshow("original", cameraResize);
		imshow("mask", output);
		imshow("gray", gray);

		if (waitKey(30) >= 0){
			break;
		}
	}
	return 0;
}
