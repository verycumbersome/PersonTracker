#include "facialDetection.h"

using namespace cv;
using namespace std;

static void readCsv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';') {
    std::ifstream file(filename.c_str(), ifstream::in);
    if (!file) {
        string error_message = "No valid input file was given, please check the given filename.";
        CV_Error(CV_StsBadArg, error_message);
    }
    string line, path, classlabel;
    while (getline(file, line)) {
        stringstream liness(line);
        getline(liness, path, separator);
        getline(liness, classlabel);
        if(!path.empty() && !classlabel.empty()) {
            images.push_back(imread(path, 0));
            labels.push_back(atoi(classlabel.c_str()));
        }
    }
}

void facialDetection::setVariables(std::string fn_haar, std::string fn_csv) {
	haarData = fn_haar;
	csvData = fn_csv;


};

void facialDetection::faceTrainer() {
	cout << csvData;
//    vector<Mat> images;
//    vector<int> labels;
//    // Read in the data (fails if no valid input filename is given, but you'll get an error message):
//    try {
//        readCsv(csvData, images, labels);
//    } catch (Exception& e) {
//        cout << "Error opening file \"" << csvData << "\". Reason: " << e.msg << endl;
//        // nothing more we can do
//        exit(1);
//    }
//
//	Ptr<FaceRecognizer> model = createFisherFaceRecognizer();
//	model->train(images, labels);
};

void facialDetection::detectFace(Mat frame, CascadeClassifier cascade){
	vector<Rect> faces;
	Mat frame_gray;

	cvtColor(frame, frame_gray, CV_BGR2GRAY );
	equalizeHist(frame_gray, frame_gray);

	  //-- Detect faces
	  cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

	  for( size_t i = 0; i < faces.size(); i++ )
	  {
	    Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
	    ellipse( frame, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

	    Mat faceROI = frame_gray( faces[i] );
	    std::vector<Rect> eyes;
	  }

	  imshow("main", frame);
}

