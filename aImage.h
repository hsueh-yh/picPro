/**
 *ͼ���࣬����ͼ�����������
*/

#ifndef AIMAGE_H
#define AIMAGE_H

#include <vector>

#include <opencv2/opencv.hpp>
#include "opencv2/nonfree/nonfree.hpp"
//#include "Feature.h"
using namespace cv;
using namespace std;

class aImage
{
private:

	cv::Mat image;
	cv::Mat result;
	
	std::string statusMessage;
	std::string imagePath;
	std::string proName;

	string detectorType;  //HARRIS FAST SURF SIFT ORB MSER STAR
	string extractorType;  //SURF SIFT ( ORB+ORB+... )
	string matchType; //FlannBased BruteForce
	string matchAlgorithm; //knnMatch bestMatch

	Mat objectImage;

	Mat objectDescriptor, sceneDescriptor;//����������

	vector<KeyPoint> objectKeypoints, sceneKeypoints; //������
	vector<DMatch> matches;  
	vector<std::vector<DMatch>> knnmatches; 


	//�ǵ�
	vector<Point> HarrisPoints;
	vector<Point> Shi_TomasiPoints;


public:

	aImage()
	{
		detectorType = "FAST";  //HARRIS FAST SURF SIFT ORB MSER STAR
		extractorType = "SURF";  //SURF SIFT ( ORB+ORB+... )
		matchType = "FlannBased"; //FlannBased BruteForce
		matchAlgorithm = "bestMatch";//knnMatch bestMatch
	}
	//aImage()
};

#endif //AIMAGE_H