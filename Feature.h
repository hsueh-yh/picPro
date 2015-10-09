
//	�ֲ�ͼ��������ȡ��ƥ��
	
#ifndef LOCAL_FEATURE_H
#define LOCAL_FEATURE_H

#include <iostream>
#include <vector>
#include <string>

#include <opencv2/opencv.hpp>
#include "opencv2/nonfree/nonfree.hpp"

using namespace cv;
using namespace std;

class Feature
{
private:

	Ptr<FeatureDetector> m_detector;//����������
	Ptr<DescriptorExtractor> m_extractor;//�������������
	Ptr<DescriptorMatcher> m_matcher;//ƥ����

	string m_detectType;//������������
	string m_extractType;//���������������
	string m_matchType;//ƥ������

public:
	Feature();
	~Feature();

	Feature(const string& detectType, const string& extractType, const string& matchType);


	//ƽ��������
	void objectDetect( Mat& objectImage, Mat& sceneImage , Mat&outImage,
						Mat& objectDescriptor,Mat& sceneDescriptor, vector<DMatch>& matches ,
						vector<KeyPoint>& keypoints_object, vector<KeyPoint>& keypoints_scene);

	// ���������
	void detectKeypoints(const Mat& image, vector<KeyPoint>& keypoints);  

	//��ʾ������
	void drawKeypoints( Mat& image, Mat& outImage, vector<KeyPoint>& keypoints);

	// ��ȡ��������
	void extractDescriptors(const Mat& image, vector<KeyPoint>& keypoints, Mat& descriptor);   

	// �����ƥ��
	void bestMatch(const Mat& objectDescriptor, Mat& sceneDescriptor, vector<DMatch>& matches);  

	// K����ƥ��
	void knnMatch(const Mat& objectDescriptor, Mat& sceneDescriptor, vector<vector<DMatch>>& matches, int k);   

	// ����������
	void saveKeypoints(const Mat& image, const vector<KeyPoint>& keypoints, const string& saveFileName = "");  

	// ����ƥ������ͼƬ��
	void _drawMatches(const Mat& objectImage, const vector<KeyPoint>& objectKeypoints,
					 const Mat& sceneImage, const vector<KeyPoint>& sceneKeypoints,
					  Mat& outImage, const vector<DMatch>& matches );   

};


#endif //LOCAL_FEATURE_H