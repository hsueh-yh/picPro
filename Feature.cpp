
/**
*	ͼ��������ȡ��ƥ��  
*/

#include "Feature.h"

//Ĭ�Ϲ��캯��
Feature::Feature()
{
	/*�����ֲ�ͼ�������������+����������������+��ά��������ƥ�䷽����
		1. FAST+SIFT+FLANN 
		2. HARRIS+SIFT+FLANN
		3. SURF+SIFT+FLANN
		4. MSER+SIFT+FLANN
		5. STAR+SIFT+FLANN
		6.SIFT+SIFT+FLANN
		7. ORB+ORB+FLANN
	*/
	m_detectType = "SURF";
	m_extractType = "SIFT";
	m_matchType = "BruteForce";
	initModule_nonfree(); 
}

Feature::~Feature()
{

}

//���캯������ʼ�����������͡������������͡�ƥ�䷽ʽ
Feature::Feature(const string& detectType, const string& extractType, const string& matchType)
{
	assert(!detectType.empty());
	assert(!extractType.empty());
	assert(!matchType.empty());

	m_detectType = detectType;
	m_extractType = extractType;
	m_matchType = matchType;
	initModule_nonfree(); 
}

// ���������
void Feature::detectKeypoints(const Mat& image, std::vector<KeyPoint>& keypoints) 
{
	assert(image.type() == CV_8UC1);
	assert(!m_detectType.empty());

	keypoints.clear();
	m_detector = FeatureDetector::create(m_detectType);
	m_detector->detect(image, keypoints);

}

//���������㵽ͼƬ��
void Feature::drawKeypoints( Mat& image, Mat& outImage, vector<KeyPoint>& keypoints)
{
	cv::drawKeypoints(image, keypoints, outImage, Scalar(255,255,0), DrawMatchesFlags::DRAW_RICH_KEYPOINTS );
}

// ��ȡ��������
void Feature::extractDescriptors(const Mat& image, std::vector<KeyPoint>& keypoints, Mat& descriptor)
{
	assert(image.type() == CV_8UC1);
	assert(!m_extractType.empty());

	m_extractor = DescriptorExtractor::create(m_extractType);
	m_extractor->compute(image, keypoints, descriptor);

}

// �����ƥ��
void Feature::bestMatch(const Mat& objectDescriptor, Mat& sceneDescriptor , std::vector<DMatch>& matches) 
{
	assert(!objectDescriptor.empty());
	assert(!sceneDescriptor.empty());
	assert(!m_matchType.empty());

	matches.clear();
	//cout << m_matchType <<endl;
	m_matcher = DescriptorMatcher::create(m_matchType);
	m_matcher->add(std::vector<Mat>(1, sceneDescriptor));
	m_matcher->train();
	m_matcher->match(objectDescriptor, matches);

}

// K����ƥ��
void Feature::knnMatch(const Mat& objectDescriptor, Mat& sceneDescriptor, std::vector<std::vector<DMatch>>& matches, int k)
{
	assert(k > 0);
	assert(!objectDescriptor.empty());
	assert(!sceneDescriptor.empty());
	assert(!m_matchType.empty());

	matches.clear();

	m_matcher = DescriptorMatcher::create(m_matchType);
	m_matcher->add(std::vector<Mat>(1, sceneDescriptor));
	m_matcher->train();
	m_matcher->knnMatch(objectDescriptor,matches,k);

}


// ����������ͼ���ļ�
void Feature::saveKeypoints(const Mat& image, const vector<KeyPoint>& keypoints, const string& saveFileName)
{

	Mat outImage;//Scalar(255,255,0)
	cv::drawKeypoints(image, keypoints, outImage,Scalar::all(-1) , DrawMatchesFlags::DRAW_RICH_KEYPOINTS );

}


// ����ƥ������ͼƬ��
void Feature::_drawMatches(const Mat& objectImage, const vector<KeyPoint>& objectKeypoints,
						  const Mat& sceneImage, const vector<KeyPoint>& sceneKeypoints,
						  Mat& outImage, const vector<DMatch>& matches )
{
	//Scalar(255, 0, 0), Scalar(0, 255, 255),
	cv::drawMatches(objectImage, objectKeypoints, sceneImage, sceneKeypoints, matches, outImage, 
				Scalar::all(-1), Scalar::all(-1), vector<char>(),  DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
}

//ƽ��������
void Feature::objectDetect( Mat& objectImage, Mat& sceneImage , Mat&outImage,
							Mat& objectDescriptor,Mat& sceneDescriptor, vector<DMatch>& matches,
							vector<KeyPoint>& objectKeypoints, vector<KeyPoint>& sceneKeypoints)
{
	double max_dist = 0; double min_dist = 100;

	//�����������С����
	for( int i = 0; i < objectDescriptor.rows; i++ )
	{ 
		double dist = matches[i].distance;
		if( dist < min_dist ) 
			min_dist = dist;
		if( dist > max_dist ) 
			max_dist = dist;
	}


	//�ҳ�ǿ�Ƚϴ�������㣨Ҳ�����ð뾶��
	std::vector< DMatch > good_matches;
	double acceptedDist = 2*min_dist;

	for( int i = 0; i < objectDescriptor.rows; i++ )
	{
		if( matches[i].distance < acceptedDist )
		{ 
			good_matches.push_back( matches[i]); 
		}
	}
	
	//����ƥ����
	drawMatches( objectImage, objectKeypoints, sceneImage, sceneKeypoints,
				 good_matches, outImage, Scalar::all(-1), Scalar::all(-1),
				 vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );

	//�õ��õ��������λ��
	std::vector<Point2f> object;//Ŀ��ͼƬ�еĵ�
	std::vector<Point2f> scene;//����ͼƬ�еĵ�
	for( int i = 0; i < good_matches.size(); i++ )
	{
		object.push_back( objectKeypoints[ good_matches[i].queryIdx ].pt );
		scene.push_back( sceneKeypoints[ good_matches[i].trainIdx ].pt );
	}

	//Ŀ��ͼƬ�ͳ���ͼƬ��͸�ӱ仯��ϵ
	Mat H = findHomography( object, scene, CV_RANSAC );

	//Ŀ��ͼ����ĸ��ǵ�����
	std::vector<Point2f> object_corners(4);

	object_corners[0] = cvPoint(0,0); 
	object_corners[1] = cvPoint( objectImage.cols, 0 );
	object_corners[2] = cvPoint( objectImage.cols, objectImage.rows ); 
	object_corners[3] = cvPoint( 0, objectImage.rows );

	std::vector<Point2f> scene_corners(4);

	perspectiveTransform( object_corners, scene_corners, H);//͸�ӱ任

	//�����ͼ��ĳ������ֻ����߿�
	line( outImage, scene_corners[0] + Point2f( objectImage.cols, 0), scene_corners[1] + Point2f( objectImage.cols, 0), Scalar(0, 255, 0), 4 );
	line( outImage, scene_corners[1] + Point2f( objectImage.cols, 0), scene_corners[2] + Point2f( objectImage.cols, 0), Scalar( 0, 255, 0), 4 );
	line( outImage, scene_corners[2] + Point2f( objectImage.cols, 0), scene_corners[3] + Point2f( objectImage.cols, 0), Scalar( 0, 255, 0), 4 );
	line( outImage, scene_corners[3] + Point2f( objectImage.cols, 0), scene_corners[0] + Point2f( objectImage.cols, 0), Scalar( 0, 255, 0), 4 );

}
