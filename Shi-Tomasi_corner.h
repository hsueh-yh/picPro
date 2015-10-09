
#ifndef SHI_TOMASI_H
#define SHI_TOMASI_H

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

RNG rng(12345);

class shiTomasiDetector
{

private:
	Mat src_gray;

	int maxCorners;// = 100;//23;
	int maxTrackbar;// = 100;
	double qualityLevel;// = 0.01;
	double minDistance;// = 10;
	int blockSize;// = 3;
	bool useHarrisDetector;// = false;
	double k;// = 0.04;
	
	char* source_window;// = "Image";

	vector<Point2f> corners;
	//RNG rng();
	/// Global variables


	//RNG rng((12345);

public:
	shiTomasiDetector( )
	{
		//src = image;
		//cvtColor( src, src_gray, CV_BGR2GRAY );
		maxCorners = 100;//23;
		maxTrackbar = 100;
		qualityLevel  = 0.01;
		minDistance = 10;
		blockSize = 3;
		useHarrisDetector = false;
		k = 0.04;

		/// Global variables

		maxCorners = 100;//23;
		maxTrackbar = 100;

		
		source_window = "Image";
	}
	
	//void goodFeaturesToTrack_Demo();


/// Function header
Mat detect( Mat& src , Mat& copy )//( int, void* );
{

	/// Copy the source image
	cvtColor( src, src_gray, CV_BGR2GRAY );
	
	copy = src.clone();

	/// Apply corner detection
  
	goodFeaturesToTrack( src_gray,
				corners,
				maxCorners,
				qualityLevel,
				minDistance,
				Mat(),
				blockSize,
				useHarrisDetector,
				k );


	/// Draw corners detected
	//cout<<"** Number of corners detected: "<<corners.size()<<endl;
	int r = 4;
	for( int i = 0; i < corners.size(); i++ )
		{ circle( copy, corners[i], r, Scalar(rng.uniform(0,255), rng.uniform(0,255),
				rng.uniform(0,255)), -1, 8, 0 ); }
	
	/// Show what you got
	
	//namedWindow( source_window, CV_WINDOW_AUTOSIZE );
	//imshow( source_window, copy );
	//waitKey(0);
	
	return copy;
}

};

#endif //SHI_TOMASI_H