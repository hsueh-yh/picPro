

#ifndef MATCH_H
#define MATCH_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

class match
{
private:

	/// 将被显示的原图像
	Mat result;
	int match_method;

public:

	match()
	{
		//mainImage = src ;
		//tempImage = temp;
		match_method  = 0;
	}

	void detect(Mat& mainImage, Mat& tempImage, Mat& outImage){


	  mainImage.copyTo( outImage );

	  /// 创建输出结果的矩阵
	  int result_cols =  mainImage.cols - tempImage.cols + 1;
	  int result_rows = mainImage.rows - tempImage.rows + 1;

	  result.create( result_cols, result_rows, CV_32FC1 );

	  /// 进行匹配和标准化
	  matchTemplate( mainImage, tempImage, result, match_method );
	  normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );

	  /// 通过函数 minMaxLoc 定位最匹配的位置
	  double minVal; double maxVal; Point minLoc; Point maxLoc;
	  Point matchLoc;

	  minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );

	  /// 对于方法 SQDIFF 和 SQDIFF_NORMED, 越小的数值代表更高的匹配结果. 而对于其他方法, 数值越大匹配越好
	  if( match_method  == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED )
		{ matchLoc = minLoc; }
	  else
		{ matchLoc = maxLoc; }

	  /// 让我看看您的最终结果
	  rectangle( outImage, matchLoc, Point( matchLoc.x + tempImage.cols , matchLoc.y + tempImage.rows ), Scalar::all(0), 2, 8, 0 );
	  rectangle( result, matchLoc, Point( matchLoc.x + tempImage.cols , matchLoc.y + tempImage.rows ), Scalar::all(0), 2, 8, 0 );

  }

};
#endif	//MATCH_H