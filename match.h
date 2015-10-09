

#ifndef MATCH_H
#define MATCH_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

class match
{
private:

	/// ������ʾ��ԭͼ��
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

	  /// �����������ľ���
	  int result_cols =  mainImage.cols - tempImage.cols + 1;
	  int result_rows = mainImage.rows - tempImage.rows + 1;

	  result.create( result_cols, result_rows, CV_32FC1 );

	  /// ����ƥ��ͱ�׼��
	  matchTemplate( mainImage, tempImage, result, match_method );
	  normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );

	  /// ͨ������ minMaxLoc ��λ��ƥ���λ��
	  double minVal; double maxVal; Point minLoc; Point maxLoc;
	  Point matchLoc;

	  minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );

	  /// ���ڷ��� SQDIFF �� SQDIFF_NORMED, ԽС����ֵ������ߵ�ƥ����. ��������������, ��ֵԽ��ƥ��Խ��
	  if( match_method  == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED )
		{ matchLoc = minLoc; }
	  else
		{ matchLoc = maxLoc; }

	  /// ���ҿ����������ս��
	  rectangle( outImage, matchLoc, Point( matchLoc.x + tempImage.cols , matchLoc.y + tempImage.rows ), Scalar::all(0), 2, 8, 0 );
	  rectangle( result, matchLoc, Point( matchLoc.x + tempImage.cols , matchLoc.y + tempImage.rows ), Scalar::all(0), 2, 8, 0 );

  }

};
#endif	//MATCH_H