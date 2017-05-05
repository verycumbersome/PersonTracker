#ifndef FACIAL_DETECTION_INCLUDED
#define FACIAL_DETECTION_INCLUDED

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
		static void readCsv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';');
		void faceTrainer();
		void detectFace(Mat frame, CascadeClassifier cascade);
		int faceY;
		int faceX;
	private:
		string haarData;
		string csvData;
};

#endif /* FACIAL_DETECTION_H */

