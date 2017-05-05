#include "facialDetection.h"

#include <iostream>

//using namespace cv;
//using namespace std;

int main( int argc, const char** argv )
{
	string faceCascadePath = "/usr/local/Cellar/opencv/2.4.13.2/share/OpenCV/haarcascades/haarcascade_frontalface_default.xml";
	CascadeClassifier faceCascade;

	CvCapture* frameCapture;
	VideoCapture capture(0);
	Mat output;
	Mat frame;

	if (!capture.isOpened()){
		cerr << "Cannot open camera." << endl;
	}

	if (!faceCascade.load(faceCascadePath)){
		cerr << "Failed to load face cascade" << endl;
	}

	RNG rng(12345);

	frameCapture = cvCaptureFromCAM( 0 );

	while(1){
		Mat cameraFrame;
		Mat cameraResize;
		facialDetection faceDetect;

		capture.read(cameraFrame);
		resize(cameraFrame, cameraResize, Size(), 0.5, 0.5, CV_INTER_AREA);

		Mat original = cameraResize.clone();
		Mat gray;

		cvtColor(original, gray, CV_BGR2GRAY);
		vector< Rect_<int> > faces;

		inRange(cameraResize, Scalar(0,50,0), Scalar(200,200,100), output);

		frame = cvQueryFrame(frameCapture);

		faceDetect.detectFace(frame, faceCascade);
//		imshow("original", cameraResize);
//		imshow("mask", output);
//		imshow("gray", gray);

		if (waitKey(30) >= 0){
			break;
		}
	}
	return 0;
}
