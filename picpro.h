#ifndef PICPRO_H
#define PICPRO_H

#include <string>
#include <vector>

#include <QtWidgets/QMainWindow>
#include "ui_picpro.h"

#include <QtWidgets/qfiledialog.h>
#include <QLabel>
#include <QMessageBox>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include "opencv2/nonfree/nonfree.hpp"

#include "aImage.h"

using namespace std;
using namespace cv;

class picPro : public QMainWindow
{
	Q_OBJECT

private:
	Ui::picProClass ui;

	cv::Mat image;
	cv::Mat result;
	cv::Mat *showImg;
	std::string statusMessage;
	std::string imagePath;
	std::string proName;

	string detectorType;  //HARRIS FAST SURF SIFT ORB MSER STAR
	string extractorType;  //SURF SIFT ( ORB+ORB+... )
	string matchType; //FlannBased BruteForce
	string matchAlgorithm; //knnMatch bestMatch

	Mat objectImage;

	Mat objectDescriptor, sceneDescriptor;//特征描述子

	vector<KeyPoint> objectKeypoints, sceneKeypoints; //特征点
	vector<DMatch> matches;  
	vector<std::vector<DMatch>> knnmatches; 
	

signals:
	void harrisSignal( double value );

	private slots:
		
		void on_CloseImageButton_clicked();
		void OpenImageButton_clicked();

		//void on_ProcessButton_clicked();
		
		void on_actionOpen_triggered();
		void on_actionCamera_triggered();
		void on_actionSave_triggered();
		std::string on_actionSaveAs_triggered();

		//滑动条 文本框 的值改变
		void on_opSlider1_valueChanged(int value);
		void on_opText1_textEdited( QString value );
		void on_opSlider2_valueChanged(int value);
		void on_opText2_textEdited( QString value );
		//简单操作
		void on_actionResize_triggered( int flag=1, double scal = 1 );//缩放
		void on_actionRotation_triggered( double angle=0, double scal = 1 );//旋转
		void on_actionDilation_triggered(int value = 1);//膨胀
		void on_actionErode_triggered( int value = 1);//腐蚀
		//平滑处理
		void on_actionBlur_triggered( int value=5 );//平滑处理
		void on_actionGaussianBlur_triggered( int value=5 );
		void on_actionMedianBlur_triggered( int value=5 );
		void on_actionBilateralBlur_triggered( int value=5 );
		//阀值化
		void on_actionBinary_triggered( int threshold=1 );
		void on_actionBinaryInv_triggered( int threshold=1 );
		void on_actionTrunc_triggered( int threshold=1 );
		void on_actionTozero_triggered( int threshold=1 );
		void on_actionTozeroInv_triggered( int threshold=1 );

		void on_actionAutoThreshold_triggered();
		//边缘检测
		void on_actionSobel_triggered();
		void on_actionLaplace_triggered();
		void on_actionCanny_triggered( int lowThreshold=1 );
		
		//角点检测
		void on_actionHarris_triggered( int thresh = 200 );
		void on_actionShiTomasi_triggered();

		
		//void on_actionMatch_triggered();actionTest
		void FeaturePoint();//特征点检测
		void FeatureMatch();//特征匹配
		void on_actionObjectDetect_triggered();//物体检测

		void on_actionHARRIS_triggered();
		void on_actionSURF_triggered();
		void on_actionSIFT_triggered();
		void on_actionFAST_triggered();
		void on_actionORB_triggered();
		void on_actionMSER_triggered();
		void on_actionSTAR_triggered();
		void on_actionExtractorSIFT_triggered();
		void on_actionExtractorSURF_triggered();
		void on_actionFlannBased_triggered();
		void on_actionBruteForce_triggered();
		void on_actionBestMatch_triggered();
		void on_actionKnnMatch_triggered();

		void featureExtractor(Mat& image);

		void on_actionTempletMatch_triggered();
		void featureMatch( int flag=0 );//const string& detectorType, const string& extractorType, const string& matchType, int k=0);

public:

	picPro(QWidget *parent = 0);
	~picPro();

	//改变this.image
	void setImage( cv::Mat img );

	//打开图片
	std::string open();

	void resizeORrotation( double angle = 0, double scale=1 );//改变大小
	
	//在窗口中显示图像
	void showImage();//显示this.image
	void showImage( std::string src );//显示src路径下的图像
	void showImage( cv::Mat& image );//显示image图像

	void enlarge( double scal=1 );
	void shrink( double scal=1 );

	bool checked();

	//设置状态栏消息
	void setStatusBarMessage( std::string message );
	//显示状态栏消息
	void showStatusBarMessage();
	void showStatusBarMessage(std::string nessage );

	//设置操作界面
	void init_ui( int num=0, std::string name1=":", int min1=0, int max1=10, int singleStep1=1, std::string name2=":", int min2=0, int max2=10, int singleStep2=1 );
	
	void choseOp( int value );

	
};


#endif // PICPRO_H
