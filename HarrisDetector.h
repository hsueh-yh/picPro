
//Harris�ǵ���

#ifndef HARRIS_H
#define HARRIS_H

#include <core\core.hpp>
#include <highgui\highgui.hpp>
#include <opencv2\opencv.hpp>
#include "cornerDetector.h"

//using namespace std;
using namespace cv;

//detecte a set of corners 
class HarrisDetector : public cornerDetector
{
private:
	Mat cornerStrength;		//�ǵ�ǿ��ͼ
	Mat cornerTh;	//��ֵ��Ľǵ�ͼ
	Mat localMax;	//�ֲ�����ֵͼ��
	int neighbourhood;	//����ƽ�����������صĳߴ�
	int aperture;	//�ݶȼ���Ŀ׾���С
	double k;	//Harris����
	double maxStrength;		//��ֵ��������ǿ��
	double threshold;	//����õ��ķ�ֵ
	int nonMaxSize;		//�Ǽ������Ƶ��������صĳߴ�
	Mat kernel;		//�Ǽ���ֵ���Ƶĺ�
	Mat temp;

public:

	//���캯��
	HarrisDetector():neighbourhood( 3 ),
					aperture( 3 ),
					k( 0.09 ),
					maxStrength( 0.0 ),
					threshold( 0.01 ),
					nonMaxSize( 10 )
	{
		setLocalMaxWindowSize( nonMaxSize );
	}

	void setLocalMaxWindowSize ( int nonMaxSize )
	{
		this->nonMaxSize = nonMaxSize;
	}

	//����Harris�ǵ�
	void detect( const Mat &image )
	{
		cv::cornerHarris ( image, cornerStrength, neighbourhood, aperture, k );
		normalize( cornerStrength, temp, 0, 255, NORM_MINMAX, CV_32FC1, Mat() );////////
		double minStrength;
		minMaxLoc( cornerStrength , &minStrength, &maxStrength );//��������ȫ����С���ֵ
		Mat dilated;
		dilate( cornerStrength, dilated, Mat() );//����
		compare( cornerStrength, dilated, localMax, CMP_EQ );//�õ��ֲ�����ֵͼ��
	}

	//��Harrisֵ��ȡ�ǵ�ͼ
	Mat getCornerMap( double qualityLevel )
	{
		Mat cornerMap;
		threshold = qualityLevel * maxStrength;
		cv::threshold( cornerStrength, cornerTh, threshold, 255, THRESH_BINARY );
		cornerTh.convertTo( cornerMap, CV_8U );
		bitwise_and( cornerMap, localMax, cornerMap );

		return cornerMap;
	}

	//��Harrisֵ�õ�������
	void getCorners( vector<Point>&points, double qualityLevel)
	{
		Mat cornerMap = getCornerMap( qualityLevel );
		getCorners( points, cornerMap );
	}

	//�ɽǵ�ͼ��ȡ������
	void getCorners( vector<Point>&points, const Mat &cornerMap )
	{
		for( int y = 0; y < cornerMap.rows; y++ )
		{
			const uchar* rowPtr = cornerMap.ptr<uchar>( y );
			for( int x = 0; x < cornerMap.cols; x++ )
			{
				if ( rowPtr[x] )
				{
					points.push_back( Point( x, y ) );
				}
			}
		}
	}


	//��������λ�û���Բ
	void drawOnImage( Mat &image, const vector<Point>&points,	
					  Scalar color = Scalar( 255, 255, 255 ),
					  int radius = 3, int thickness = 1 , int thresh = 200)
	{
		vector<Point>::const_iterator it = points.begin();
		while( it != points.end())
		{
			if( (int) temp.at<float>(it->x,it->y) > thresh )
			{
				circle( image, *it , radius, color, thickness );
			}
			++it;
		}
	}

};

#endif	//HARRIS_H