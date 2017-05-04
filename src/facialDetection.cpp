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

CvRect detectFaceInImage(IplImage *inputImg, CascadeClassifier* cascade)
{
	CvSize minFeatureSize = cvSize(20, 20);

	int flags = CV_HAAR_FIND_BIGGEST_OBJECT | CV_HAAR_DO_ROUGH_SEARCH;

	float search_scale_factor = 1.1f;
	IplImage *detectImg;
	IplImage *greyImg = 0;
	CvMemStorage* storage;
	CvRect rc;
	double t;
	CvSeq* rects;
	CvSize size;
	int i, ms, nFaces;

	storage = cvCreateMemStorage(0);
	cvClearMemStorage( storage );

	detectImg = (IplImage*)inputImg;

	t = (double)cvGetTickCount();
	rects = CascadeClassifier( detectImg, cascade, storage,
			search_scale_factor, 3, flags, minFeatureSize);
	t = (double)cvGetTickCount() - t;
	ms = cvRound( t / ((double)cvGetTickFrequency() * 1000.0) );
	nFaces = rects->total;
	printf("Face Detection took %d ms and found %d objects\n", ms, nFaces);

	if (nFaces > 0)
		rc = *(CvRect*)cvGetSeqElem( rects, 0 );
	else
		rc = cvRect(-1,-1,-1,-1);

	if (greyImg)
		cvReleaseImage( &greyImg );
	cvReleaseMemStorage( &storage );
	//cvReleaseHaarClassifierCascade( &cascade );

	return rc;
}
