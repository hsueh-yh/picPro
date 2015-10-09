
//	局部图像特征提取与匹配
	
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

	Ptr<FeatureDetector> m_detector;//特征点检测器
	Ptr<DescriptorExtractor> m_extractor;//特征向量检测器
	Ptr<DescriptorMatcher> m_matcher;//匹配器

	string m_detectType;//特征点检测类型
	string m_extractType;//特征向量检测类型
	string m_matchType;//匹配类型

public:
	Feature();
	~Feature();

	Feature(const string& detectType, const string& extractType, const string& matchType);


	//平面物体检测
	void objectDetect( Mat& objectImage, Mat& sceneImage , Mat&outImage,
						Mat& objectDescriptor,Mat& sceneDescriptor, vector<DMatch>& matches ,
						vector<KeyPoint>& keypoints_object, vector<KeyPoint>& keypoints_scene);

	// 检测特征点
	void detectKeypoints(const Mat& image, vector<KeyPoint>& keypoints);  

	//显示特征点
	void drawKeypoints( Mat& image, Mat& outImage, vector<KeyPoint>& keypoints);

	// 提取特征向量
	void extractDescriptors(const Mat& image, vector<KeyPoint>& keypoints, Mat& descriptor);   

	// 最近邻匹配
	void bestMatch(const Mat& objectDescriptor, Mat& sceneDescriptor, vector<DMatch>& matches);  

	// K近邻匹配
	void knnMatch(const Mat& objectDescriptor, Mat& sceneDescriptor, vector<vector<DMatch>>& matches, int k);   

	// 保存特征点
	void saveKeypoints(const Mat& image, const vector<KeyPoint>& keypoints, const string& saveFileName = "");  

	// 保存匹配结果到图片中
	void _drawMatches(const Mat& objectImage, const vector<KeyPoint>& objectKeypoints,
					 const Mat& sceneImage, const vector<KeyPoint>& sceneKeypoints,
					  Mat& outImage, const vector<DMatch>& matches );   

};


#endif //LOCAL_FEATURE_H