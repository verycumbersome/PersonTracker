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

void facialDetection::setVariables(std::string fn_haar, std::string fn_csv, int cam_id) {
	haarData = fn_haar;
	csvData = fn_csv;
	deviceId = cam_id;


};

void facialDetection::faceTrainer() {
    vector<Mat> images;
    vector<int> labels;
    // Read in the data (fails if no valid input filename is given, but you'll get an error message):
    try {
        readCsv(csvData, images, labels);
    } catch (cv::Exception& e) {
        cerr << "Error opening file \"" << csvData << "\". Reason: " << e.msg << endl;
        // nothing more we can do
        exit(1);
    }

	Ptr<FaceRecognizer> model = createFisherFaceRecognizer();
	model->train(images, labels);
};
