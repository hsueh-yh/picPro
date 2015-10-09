
#include "picpro.h"
#include "HarrisDetector.h"
#include "Shi-Tomasi_corner.h"
#include "Feature.h"
#include "match.h"


//Ĭ�Ϲ��캯��
picPro::picPro(QWidget *parent)
	: QMainWindow(parent)
{
	
	ui.setupUi(this);
	ui._setupUi(this);
	
	showImg = &image;
	init_ui();
	//init_connect();

	detectorType = "SIFT";  //HARRIS FAST SURF SIFT ORB MSER STAR
	extractorType = "SIFT";  //SURF SIFT ( ORB+ORB+... )
	matchType = "BruteForce"; //FlannBased BruteForce
	matchAlgorithm = "bestMatch";//knnMatch bestMatch
	
	connect(ui.OpenImageButton, SIGNAL(clicked()), SLOT(OpenImageButton_clicked()));

	//connect(ui.opSlider1,SIGNAL(valueChanged(value)),this,SLOT(on_opSlider1Changed(value)));
	//connect(ui.actionBlur, SIGNAL(triggered(int i)), SLOT(on_actionBlur_triggered(int i)));
	
}


//��������
picPro::~picPro()
{

}


/**************************************����ͼ��**************************************/


//��ȡͼƬ·��
std::string picPro::open()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
	std::string imagepath = fileName.toStdString();
//	if ( imagepath.empty() )
//		return imagepath;
	return imagepath;
}


//��ͼƬ--�ļ�
void picPro::on_actionOpen_triggered()
{
	imagePath = this->open();
	if( imagePath.empty()) return;
	image = cv::imread( imagePath );
	objectImage.release();
	if( image.data == NULL )
	{
		this->showStatusBarMessage("image read error!");
		imagePath.clear();
		return ;
	}
	cv::cvtColor(image, image, CV_BGR2BGRA);
	//cv::cvtColor(image, image, CV_BGR2RGBA);
	this->showImage(image);
	waitKey(0);
	this->showStatusBarMessage("Ready");
}


//��ͼƬ--��ť
void picPro::OpenImageButton_clicked()
{
	ui.statusBar->showMessage("Load image...", 1000);
	//this->showStatusBarMessage("Load image...");
	imagePath = "F:/OpenCV/Resource/14.jpg";
	image = cv::imread(imagePath);
	objectImage.release();
	//ͼƬ��ȡ����
	if( image.data == NULL )
	{
		this->showStatusBarMessage("image read error!");
		return ;
	}
	cv::cvtColor(image, image, CV_BGR2BGRA);
	this->showImage(image);
	
	//this->showStatusBarMessage("Ready");
	
}


//����ͷ����
void picPro::on_actionCamera_triggered()
{
	cvNamedWindow( "avi", CV_WINDOW_AUTOSIZE );
	CvCapture* capture = cvCreateCameraCapture( 0 );
	IplImage* frame;
	
	while( 1 )
	{
		frame = cvQueryFrame( capture );
		if( !frame )
			break;

		QImage images = QImage((const uchar*)frame->imageData, frame->width, frame->height, QImage::Format_RGB888).rgbSwapped(); 
  
		ui.showImageLabel->setPixmap(QPixmap::fromImage(images)); 
		ui.showImageLabel->show();
		//waitKey(1000);
		//
		image = Mat(frame, true);

		cvShowImage ( "avi", frame );
		//imshow("test",image);
		//showImage(image);
		char c = cvWaitKey( 1 );
		if ( c == 27 ) 
		{
			on_CloseImageButton_clicked();
			break;
		}
		else if( c == ' ' )
		{
			cvSaveImage("F:/OpenCV/Resource/save01.jpg", frame);
			//image = Mat(frame, true);
			//cvSaveImage("F:/OpenCV/Resource/save01.jpg", image);
			image = imread("F:/OpenCV/Resource/save01.jpg");
			this->imagePath = "F:/OpenCV/Resource/save01.jpg";
			//imshow("image",image);
			//waitKey(0);
			showImage(image);
			break;
		}
	}
	cvReleaseCapture( &capture );
	cvDestroyWindow( "avi" );
	
 }


//�ı�ö����б����image
void picPro::setImage( cv::Mat img )
{
	image = img;
}


//���ͼ���Ƿ�����
bool picPro::checked()
{
	if( !image.data )
	{ 
		QMessageBox::information(NULL, QString("File empty"), QString("Please open an image!"));
		return false; 
	}
	else
		return true;
}


//����ͼ��
void picPro::on_actionSave_triggered()
{
	//this->showStatusBarMessage("Saving...");
	//imshow( "1",*showImg);
	//waitKey(0);
	if( !checked()) return;
	this->showStatusBarMessage(imagePath);
	if( imagePath.empty() )
	{
		imagePath = on_actionSaveAs_triggered();
	}
	else
	{
		ui.statusBar->showMessage(QString::fromStdString(imagePath), 20000);
		imwrite(imagePath, *showImg);
	}
	
	//ui.statusBar->showMessage("Saved : "+QString::fromStdString(imagePath), 2000);
	//this->showStatusBarMessage("Ready");
}


//���Ϊ
std::string picPro::on_actionSaveAs_triggered()
{
	if( !checked()) return NULL;
	QString fileName = QFileDialog::getSaveFileName(this);
    if (fileName.isEmpty())
    {
		ui.statusBar->showMessage("save error!", 2000);
        return NULL;
    }
	imwrite(fileName.toStdString(), *showImg);
	ui.statusBar->showMessage("Save in "+fileName, 2000);
	return fileName.toStdString();
}


//��ʾͼƬ
void picPro::showImage( Mat& src )
{
	if( src.data == NULL )
	{
		this->showStatusBarMessage("image read error!");
		return ;
	}
	showImg = &src;
	QImage img;
	if(src.type() == CV_8UC1)
		img = QImage((const unsigned char*)(src.data), src.cols, src.rows, QImage::Format_Indexed8); 
	else
		img = QImage((const unsigned char*)(src.data), src.cols, src.rows,QImage::Format_RGB32); 
	
	QLabel *label = ui.showImageLabel;
	label->setStyleSheet("color:white");
	label->move(0, 0);
	label->setPixmap(QPixmap::fromImage(img));
	label->resize(label->pixmap()->size());	
	label->show();
	this->showStatusBarMessage("Ready");
}


//����״̬����Ϣ
void picPro::setStatusBarMessage( std::string message )
{
	statusMessage.clear();
	statusMessage = message;
}


//��ʾ״̬����Ϣ
void picPro::showStatusBarMessage()
{
	ui.msgLabel->setText( QString::fromStdString(statusMessage) );
	ui.msgLabel->show();
}

void picPro::showStatusBarMessage(std::string msg)
{
	setStatusBarMessage(msg);
	ui.msgLabel->setText( QString::fromStdString(msg) );
	ui.msgLabel->show();
}


//�ر���ʾ
void picPro::on_CloseImageButton_clicked()
{
	ui.showImageLabel->clear();
	ui.showImageLabel->show();
}



/**************************************�򵥴���**************************************/


//����
void picPro::on_actionResize_triggered( int flag, double scal )//�Ŵ�
{
	if( !checked()) return;
	proName = "resize";
	//resize_ui();
	init_ui(2,"Enlarge:",1,10,1,"Shrink:",0,9,1);
	//scal = 0.5;
	if(scal<=0)
	{
		scal = 1+(double)scal/10;
	}
	Size dsize;//(image.cols*scal,image.rows*scal);
	dsize.width=image.cols*scal;
	dsize.height = image.rows*scal;
	result.create(dsize,image.type());
	cv::resize(image,result,dsize);  
	showImage(result);
	
}


//��ת 
void picPro::on_actionRotation_triggered( double angle, double scal )//��С
{
	if( !checked()) return;
	proName = "Rotation";
	//rotation_ui();
	init_ui(1,"Rotation:",0,360);
	resizeORrotation( angle, scal );
}

void picPro::resizeORrotation( double angle, double scale )//�ı��С
{
	cv::Point2f center = cv::Point2f(image.cols / 2, image.rows / 2);  // ��ת����  
    //double angle = 30;  // ��ת�Ƕ�  
    //double scale = 0.5; // ���ų߶�  

    cv::Mat rotateMat;   
    rotateMat = cv::getRotationMatrix2D(center, angle, scale);  
 
    cv::warpAffine(image, result, rotateMat, image.size()); 
	showImage(result);
}


//����
void picPro::on_actionDilation_triggered(int value)
{
	if( !checked()) return;
	proName = "Dilation";
	init_ui( 1, "Iteration :", 1, 10, 1 );
	dilate( image, result, cv::Mat() ,cv::Point(-1,-1),value);
	showImage(result);
}


//��ʴ
void picPro::on_actionErode_triggered( int value )
{
	if( !checked()) return;
	proName = "Erode";
	init_ui( 1, "Iteration :", 1, 10, 1 );
	erode(image, result, cv::Mat(), cv::Point(-1,-1),value );
	showImage(result);
}




/**************************************ƽ������**************************************/


//ƽ������
void picPro::on_actionBlur_triggered( int value )//int i)
{
	if( !checked()) return;
	proName="Blur";
	init_ui(1, "kSize :",1,30,2);
	if( value%2 == 0) return;
	blur( image, result, Size( value, value ), Point(-1,-1) );
	
	this->showImage( result );
}
void picPro::on_actionGaussianBlur_triggered( int value )
{
	if( !checked()) return;
	proName="GaussianBlur";
	init_ui(1, "kSize :",1,30,2);
	if( value%2 == 0) return;
	GaussianBlur( image, result, Size( value, value ), 0, 0 );
	this->showImage( result );
}
void picPro::on_actionMedianBlur_triggered( int value )
{
	if( !checked()) return;
	proName="MedianBlur";
	init_ui(1, "kSize :",1,30,2);
	if( value%2 == 0) return;
	medianBlur( image, result, value );
	this->showImage( result );
}
void picPro::on_actionBilateralBlur_triggered( int value )
{
	if( !checked()) return;
	proName="bilateralBlur";
	init_ui(1, "kSize :",1,30,2);
	if( value%2 == 0) return;
	//blur( image, result, Size( value, value ), Point(-1,-1) );
	bilateralFilter( image, result, value, (double)value*2, (double)value/2 );
	//adaptiveBilateralFilter(image, result,Size(7,7),75);
	this->showImage( result );
}



/**************************************��ֵ�ָ�**************************************/


//��ֵ�ָ�
void picPro::on_actionBinary_triggered( int threshold )
{
	if( !checked()) return;
	proName="1FixedThreshold";
	init_ui(1,"Threshold :",1,255,1);
	//int th = 100; 
	cv::threshold(image, result, threshold, 255, CV_THRESH_BINARY);
	this->showImage( result );
}

void picPro::on_actionBinaryInv_triggered( int threshold )
{
	if( !checked()) return;
	proName="2FixedThreshold";
	init_ui(1,"Threshold :",1,255,1);
	//int th = 100; 
	cv::threshold(image, result, threshold, 255, CV_THRESH_BINARY_INV);
	this->showImage( result );
}

void picPro::on_actionTrunc_triggered( int threshold )
{
	if( !checked()) return;
	proName="3FixedThreshold";
	init_ui(1,"Threshold :",1,255,1);
	//int th = 100; 
	cv::threshold(image, result, threshold, 255, CV_THRESH_TRUNC);
	this->showImage( result );
}

void picPro::on_actionTozero_triggered( int threshold )
{
	if( !checked()) return;
	proName="4FixedThreshold";
	init_ui(1,"Threshold :",1,255,1);
	//int th = 100; 
	cv::threshold(image, result, threshold, 255, CV_THRESH_TOZERO);
	this->showImage( result );
}

void picPro::on_actionTozeroInv_triggered( int threshold )
{
	if( !checked()) return;
	proName="5FixedThreshold";
	init_ui(1,"Threshold :",1,255,1);
	//int th = 100; 
	cv::threshold(image, result, threshold, 255, CV_THRESH_TOZERO_INV);
	this->showImage( result );
}

void picPro::on_actionAutoThreshold_triggered()
{
	if( !checked()) return;
	proName="AutoThreshold";
	init_ui();
	int blockSize = 25;
	int constValue = 10;
	Mat temp;
	cv::cvtColor(image,temp,CV_BGRA2GRAY);
	cv::adaptiveThreshold(temp, result, 255, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY_INV, blockSize, constValue);
	//cv::cvtColor(result,result,CV_BGR2BGRA);
	//imshow("1",result);
	//waitKey(0);
	this->showImage( result );
}



/**************************************�߽���ȡ**************************************/


//Sobel
void picPro::on_actionSobel_triggered()
{
	if( !checked()) return;
	proName="Sobel";
	/// ���� grad_x �� grad_y ����
	Mat grad_x, grad_y, src_gray;
	Mat abs_grad_x, abs_grad_y;
	
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;

	GaussianBlur( image, image, Size(3,3), 0, 0, BORDER_DEFAULT );

	/// ת��Ϊ�Ҷ�ͼ
	cvtColor( image, src_gray,0);// CV_RGB2GRAY );CV_BGR2BGRA

	/// ������ʾ����
	// namedWindow( window_name, CV_WINDOW_AUTOSIZE );

	/// �� X�����ݶ�
	//Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
	Sobel( src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );
	convertScaleAbs( grad_x, abs_grad_x );

	/// ��Y�����ݶ�
	//Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
	Sobel( src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT );
	convertScaleAbs( grad_y, abs_grad_y );

	/// �ϲ��ݶ�(����)
	addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, result );

	this->showImage(result);
	// imshow( window_name, result );
}


//Laplace
void picPro::on_actionLaplace_triggered()
{
	if( !checked()) return;
	proName = "Laplace";
	Mat src_gray, dst;
	int kernel_size = 3;
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;
	char* window_name = "Laplace Demo";

	int c;

	/// ʹ�ø�˹�˲���������
	GaussianBlur( image, image, Size(3,3), 0, 0, BORDER_DEFAULT );

	/// ת��Ϊ�Ҷ�ͼ
	cvtColor( image, src_gray, CV_RGB2GRAY );

	/// ʹ��Laplace����
	Mat abs_dst;

	Laplacian( src_gray, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT );
	convertScaleAbs( dst, result );

	showImage(result);
}


//Canny
void picPro::on_actionCanny_triggered( int lowThreshold )
{
	if( !checked()) return;
	proName = "Canny";
	//canny_ui();
	init_ui( 1, "Threshold :", 1, 100, 1 );
	Mat src_gray;
	Mat detected_edges;

	int edgeThresh = 1;
	//int lowThreshold = 50;//
	int const max_lowThreshold = 100;
	int ratio = 3;
	int kernel_size = 3;

	if( !image.data )
	  { return ; }

	/// ������srcͬ���ͺʹ�С�ľ���(dst)
	result.create( image.size(), image.type() );

	/// ԭͼ��ת��Ϊ�Ҷ�ͼ��
	cvtColor( image, src_gray, CV_BGR2GRAY );

	/// ʹ�� 3x3�ں˽���
	blur( src_gray, detected_edges, Size(3,3) );

	/// ����Canny����
	Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );

	/// ʹ�� Canny���������Ե��Ϊ������ʾԭͼ��
	result = Scalar::all(0);

	image.copyTo( result, detected_edges);
	showImage(result);
}



/**************************************�ǵ���**************************************/


//Harris�ǵ���
void picPro::on_actionHarris_triggered( int thresh )
{
	if( !checked()) return;
	this->showStatusBarMessage("Harris processing");
	//harris_ui();
	init_ui( 1, "Thresh :", 1, 255, 1 );
	proName = "Harris";

	cvtColor(image,result,CV_BGR2GRAY);
	HarrisDetector harris;
	harris.detect( result );
	vector<Point>pts;
	harris.getCorners( pts, 0.01 );
	Scalar color = Scalar( 255, 255, 255 );
	harris.drawOnImage( result, pts, color, 3, 1, thresh );
	this->showImage( result );
	this->showStatusBarMessage("Ready");
}


//ShiTomasi�ǵ���
void picPro::on_actionShiTomasi_triggered()
{
	if( !checked()) return;
	proName = "shiTomasi";
	shiTomasiDetector sd;
	sd.detect( image, result );
	this->showImage( result ) ;
}



/**************************************�������**************************************/


//������ȡ�¼�
void picPro::on_actionHARRIS_triggered()
{
	if( !checked()) return;
	proName="FeaturePoint";
	detectorType = "HARRIS";  //HARRIS FAST SURF SIFT ORB MSER STAR
	FeaturePoint();
}

void picPro::on_actionSURF_triggered()
{
	if( !checked()) return;
	proName="FeaturePoint";
	detectorType = "SURF";  //HARRIS FAST SURF SIFT ORB MSER STAR
	FeaturePoint();
}

void picPro::on_actionSIFT_triggered()
{
	if( !checked()) return;
	proName="FeaturePoint";
	detectorType = "SIFT";  //HARRIS FAST SURF SIFT ORB MSER STAR
	FeaturePoint();
}

void picPro::on_actionFAST_triggered()
{
	if( !checked()) return;
	proName="FeaturePoint";
	detectorType = "FAST";  //HARRIS FAST SURF SIFT ORB MSER STAR
	FeaturePoint();
}

void picPro::on_actionORB_triggered()
{
	if( !checked()) return;
	proName="FeaturePoint";
	detectorType = "ORB";  //HARRIS FAST SURF SIFT ORB MSER STAR
	FeaturePoint();
}

void picPro::on_actionMSER_triggered()
{
	if( !checked()) return;
	proName="FeaturePoint";
	detectorType = "MSER";  //HARRIS FAST SURF SIFT ORB MSER STAR
	FeaturePoint();
}

void picPro::on_actionSTAR_triggered()
{
	if( !checked()) return;
	proName="FeaturePoint";
	detectorType = "STAR";  //HARRIS FAST SURF SIFT ORB MSER STAR
	FeaturePoint();
}

void picPro::on_actionExtractorSIFT_triggered()
{
	if( !checked()) return;
	proName="Extractor";
	showStatusBarMessage("Calculating...");
	extractorType = "SIFT";  //SURF SIFT ( ORB+ORB+... )
	//on_actionFeatureMatch2_triggered();
	featureExtractor(image);
	//this->showImage(sceneDescriptor);
	showStatusBarMessage("Ready");
}

void picPro::on_actionExtractorSURF_triggered()
{
	if( !checked()) return;
	proName="Extractor";
	showStatusBarMessage("Calculating...");
	extractorType = "SURF";  //SURF SIFT ( ORB+ORB+... )
	//on_actionFeatureMatch2_triggered();
	featureExtractor(image);
	//this->showImage(sceneDescriptor);
	showStatusBarMessage("Ready");
}

void picPro::on_actionFlannBased_triggered()
{
	if( !checked()) return;
	proName="FlannBased";
	matchType = "FlannBased";  //SURF SIFT ( ORB+ORB+... )
	FeatureMatch();
}

void picPro::on_actionBruteForce_triggered()
{
	if( !checked()) return;
	proName="BruteForce";
	matchType = "BruteForce"; //FlannBased BruteForce
	FeatureMatch();
}

void picPro::on_actionBestMatch_triggered()
{
	if( !checked()) return;
	proName="Match";
	matchAlgorithm.clear();
	matchAlgorithm = "bestMatch";
	FeatureMatch();
}

void picPro::on_actionKnnMatch_triggered()
{
	if( !checked()) return;
	proName="Match";
	matchAlgorithm.clear();
	matchAlgorithm = "knnMatch";
	FeatureMatch();
}


//�����������
void picPro::FeaturePoint()
{
	if( !checked()) return;

	//string detectorType = "STAR";  //HARRIS FAST SURF SIFT STAR ORB MSER
	//string extractorType = "SIFT";  
	//string matchType = "FlannBased"; 

	Mat gray;
	vector<KeyPoint> keypoints;

	cv::cvtColor(image, gray, CV_BGR2GRAY);
	
	Feature test = Feature(detectorType, extractorType, matchType);
	test.detectKeypoints(gray, keypoints);//���������
	test.drawKeypoints(gray,result, keypoints);//����������

	cv::cvtColor(result, result, CV_BGR2BGRA);
	this->showImage( result );

}


//��ȡ ��������
void picPro::featureExtractor(Mat& image)
{
	if( !checked()) return;
	Mat sceneImage;

	cv::cvtColor(image, sceneImage, CV_BGR2GRAY);

	Feature feature( detectorType, extractorType, matchType);
	
	// ���������
	showStatusBarMessage("Detect Keypoints...");
	feature.detectKeypoints(sceneImage,sceneKeypoints);
	  
	//��ȡ��������
	showStatusBarMessage("Detect Descriptors...");
	feature.extractDescriptors(sceneImage,sceneKeypoints,sceneDescriptor);
	this->showImage(sceneDescriptor);
	imshow("Extractor",sceneDescriptor);
	//waitKey(0);
}


//����ƥ�����
void picPro::featureMatch( int flag )//const string& detectorType, const string& extractorType, const string& matchType,int k)
{
	if( !checked()) return;
	if( !objectImage.data )
	{
		QMessageBox::information(NULL, QString("Open object image"), QString("Please select the target image!"));
		std::string objectImg_path = this->open();
		if(objectImg_path.empty()) return;
		objectImage = imread( objectImg_path ,CV_LOAD_IMAGE_GRAYSCALE );
		if( !objectImage.data) return;
	}
	Mat sceneImage;
	int k = 5; 

	cv::cvtColor(image, sceneImage, CV_BGR2GRAY);
	
	if( flag == 1)
	{
		detectorType = "SIFT";  //HARRIS FAST SURF SIFT ORB MSER STAR
		extractorType = "SIFT";  //SURF SIFT ( ORB+ORB+... )
		matchType = "BruteForce"; //FlannBased BruteForce
		matchAlgorithm = "bestMatch";//knnMatch bestMatch
	}

	Feature feature( detectorType, extractorType, matchType);
	  

	// ���������
	showStatusBarMessage("Detect Keypoints...");
	feature.detectKeypoints(objectImage,objectKeypoints); 
	feature.detectKeypoints(sceneImage,sceneKeypoints);
	  
	//��ȡ��������
	showStatusBarMessage("Detect Descriptors...");
	feature.extractDescriptors(objectImage,objectKeypoints,objectDescriptor);
	feature.extractDescriptors(sceneImage,sceneKeypoints,sceneDescriptor);
	  
	//������ƥ��
	showStatusBarMessage("Keypoints Matching...");
	if( matchAlgorithm == "bestMatch" )
		feature.bestMatch(objectDescriptor, sceneDescriptor, matches);  
	else
		feature.knnMatch(objectDescriptor, sceneDescriptor, knnmatches, k );
	  
	//feature.knnMatch(objectDescriptor, sceneDescriptor, knnmatches, 2);  
	  
	feature._drawMatches(objectImage,objectKeypoints, sceneImage,sceneKeypoints, result,matches  ); 
	
	//������
	if( flag == 1)
	{
		showStatusBarMessage("Draw matches...");
		feature.objectDetect( objectImage, sceneImage ,result,
							  objectDescriptor, sceneDescriptor,  matches,
							  objectKeypoints, sceneKeypoints);
	}
}


//������ƥ��
void picPro::FeatureMatch()
{
	if( !checked()) return;
	proName="FeatureMatch";

	string detectorType = "FAST";  //HARRIS FAST SURF SIFT ORB MSER STAR
	string extractorType = "SURF";  //SURF SIFT ( ORB+ORB+... )
	string matchType = "BruteForce"; //FlannBased BruteForce

	showStatusBarMessage("Matching...");

	featureMatch(0);//detectorType, extractorType, matchType, 0);
	
	cv::cvtColor(result, result, CV_BGR2BGRA);

	this->showImage( result );
	showStatusBarMessage("Ready");
}


//ƽ��������
void picPro::on_actionObjectDetect_triggered()
{
	if( !checked()) return;
	proName="ObjectDetect";

	showStatusBarMessage("Object detector processing...");

	featureMatch(1);

	cv::cvtColor(result, result, CV_BGR2BGRA);
	this->showImage( result );
	showStatusBarMessage("Ready");
}


//ģ��ƥ��
void picPro::on_actionTempletMatch_triggered()
{
	if( !checked()) return;
	
	match ma;
	QMessageBox::information(NULL, QString("Open object image"), QString("Please select the target image!"));
	std::string objectImg_path = this->open();
	if(objectImg_path.empty()) return;
	Mat objectImg = imread( objectImg_path ,CV_LOAD_IMAGE_GRAYSCALE );
	if(!objectImg.data) return;
	imshow("object",objectImg);
	cv::cvtColor(image, image, CV_BGR2GRAY);
	ma.detect(image,objectImg, result);
	showImage(result);
}



/**************************************�ؼ�����**************************************/


//������1�ı�
void picPro::on_opSlider1_valueChanged(int value)
{
	ui.opText1->setText(QString::number(value));//������ʾ����
	choseOp(value);
}


//�ı���1�ı�
void picPro::on_opText1_textEdited( QString value )
{
	int i = value.toInt();
	if(i>ui.opSlider1->maximum()) 
		i=ui.opSlider1->maximum();
	else if(i>ui.opSlider1->minimum()) 
		i=ui.opSlider1->minimum();
	ui.opSlider1->setValue(i);
	ui.opText1->setText(QString::number(i));
	choseOp(i);
}


//������2�ı�
void picPro::on_opSlider2_valueChanged(int value)
{
	if(proName[0]=='r')
	{
		value *=-1;
		ui.opText2->setText(QString::number(1+((double)value/10)));//������ʾ����
	}
	else
	ui.opText2->setText(QString::number(value));//������ʾ����
	choseOp(value);
}


//�ı���2�ı�
void picPro::on_opText2_textEdited( QString value )
{
	int i = value.toInt();
	if(i>ui.opSlider2->maximum()) 
		i=ui.opSlider2->maximum();
	else if(i>ui.opSlider2->minimum()) 
		i=ui.opSlider2->minimum();
	ui.opSlider2->setValue(i);
	ui.opText2->setText(QString::number(i));
	//this->showStatusBarMessage(value.toStdString());
	if(proName[0]=='r')
		i*=-1;

	choseOp(i);
}


//��������Ӧѡ��
void picPro::choseOp( int value )
{
	switch(proName[0])
	{
		//�򵥴���
		case 'r':
			on_actionResize_triggered( 0, (double)value);
			break;
		case 'R':
			on_actionRotation_triggered( (double)value, 1 );
			break;
		case 'D':
			on_actionDilation_triggered(value);
			break;
		case 'E':
			on_actionErode_triggered(value);
			break;
		//ƽ������
		case'B':
			on_actionBlur_triggered(value);//value);
			break;
		case 'G':
			on_actionGaussianBlur_triggered( value );
			break;
		case 'M':
			on_actionMedianBlur_triggered( value );
			break;
		case 'b':
			on_actionBilateralBlur_triggered( value );
			break;

		//��ֵ�ָ�
		case '1':
			on_actionBinary_triggered( value );
			break;
		case '2':
			on_actionBinaryInv_triggered( value );
			break;
		case '3':
			on_actionTrunc_triggered( value );
			break;
		case '4':
			on_actionTozero_triggered( value );
			break;
		case '5':
			on_actionTozeroInv_triggered( value );
			break;

		//��Ե��ȡ
		case'S':
			on_actionSobel_triggered();
			break;
		case 'C':
			on_actionCanny_triggered(value);
			break;

		//�ǵ���
		case 'H':
			on_actionHarris_triggered( value );
			break;
		
		
		
		
		
		default:
			break;
	}
}


//��ʼ���������ã�����
void picPro::init_ui( int num, std::string name1, int min1, int max1, int singleStep1, 
							   std::string name2, int min2, int max2, int singleStep2 )
{
	if(num==0)
	{
		ui.opLabel1->hide();
		ui.opText1->hide();
		ui.opSlider1->hide();

		ui.opLabel2->hide();
		ui.opText2->hide();
		ui.opSlider2->hide();

		return;
	}
	if(num == 1 )
	{
		ui.opLabel1->setText(QString::fromStdString(name1));
		//ui.opText1->setText("0");
		ui.opSlider1->setMinimum(min1);
		ui.opSlider1->setMaximum(max1);
		ui.opSlider1->setSingleStep(singleStep1);
		//ui.opSlider1->setValue(0);
		ui.opSlider1->show();
		ui.opText1->show();
		ui.opLabel1->show();
	
		ui.opLabel2->hide();
		ui.opText2->hide();
		ui.opSlider2->hide();
		return;
	}
	if( num == 2 )
	{
		ui.opLabel1->setText(QString::fromStdString(name1));
		//ui.opText1->setText("0");
		ui.opSlider1->setMinimum(min1);
		ui.opSlider1->setMaximum(max1);
		ui.opSlider1->setSingleStep(singleStep1);
		//ui.opSlider1->setValue(0);
		ui.opSlider1->show();
		ui.opText1->show();
		ui.opLabel1->show();

		ui.opLabel2->setText(QString::fromStdString(name2));
		//ui.opText2->setText("0");
		ui.opSlider2->setMinimum(min2);
		ui.opSlider2->setMaximum(max2);
		ui.opSlider2->setSingleStep(singleStep2);
		//ui.opSlider2->setValue(0);

		ui.opSlider2->show();
		ui.opText2->show();
		ui.opLabel2->show();
		return;
	}
}

