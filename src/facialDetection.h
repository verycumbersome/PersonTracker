#ifndef __FACIAL_DETECTION_H_INCLUDED
#define __FACIAL_DETECTION_H_INCLUDED

#include <opencv2/core.hpp>
#include <opencv2/contrib/contrib.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
using namespace cv;

class facialDetection {
	public:
		void setVariables(string fn_haar, string fn_csv);
		void readCsv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';');
		void faceTrainer();
		CvRect detectFaceInImage(IplImage *inputImg, CascadeClassifier* cascade);
	private:
		string haarData;
		string csvData;
};

#endif

