
//Harris角点检测

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
	Mat cornerStrength;		//角点强度图
	Mat cornerTh;	//阀值后的角点图
	Mat localMax;	//局部极大值图像
	int neighbourhood;	//导数平滑的相邻像素的尺寸
	int aperture;	//梯度计算的孔径大小
	double k;	//Harris参数
	double maxStrength;		//阀值计算的最大强度
	double threshold;	//计算得到的阀值
	int nonMaxSize;		//非极大抑制的相邻像素的尺寸
	Mat kernel;		//非极大值抑制的核
	Mat temp;

public:

	//构造函数
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

	//计算Harris角点
	void detect( const Mat &image )
	{
		cv::cornerHarris ( image, cornerStrength, neighbourhood, aperture, k );
		normalize( cornerStrength, temp, 0, 255, NORM_MINMAX, CV_32FC1, Mat() );////////
		double minStrength;
		minMaxLoc( cornerStrength , &minStrength, &maxStrength );//查找数组全局最小最大值
		Mat dilated;
		dilate( cornerStrength, dilated, Mat() );//膨胀
		compare( cornerStrength, dilated, localMax, CMP_EQ );//得到局部极大值图像
	}

	//由Harris值获取角点图
	Mat getCornerMap( double qualityLevel )
	{
		Mat cornerMap;
		threshold = qualityLevel * maxStrength;
		cv::threshold( cornerStrength, cornerTh, threshold, 255, THRESH_BINARY );
		cornerTh.convertTo( cornerMap, CV_8U );
		bitwise_and( cornerMap, localMax, cornerMap );

		return cornerMap;
	}

	//由Harris值得到特征点
	void getCorners( vector<Point>&points, double qualityLevel)
	{
		Mat cornerMap = getCornerMap( qualityLevel );
		getCorners( points, cornerMap );
	}

	//由角点图获取特征点
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


	//在特征点位置绘制圆
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