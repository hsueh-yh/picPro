/********************************************************************************
** Form generated from reading UI file 'picpro.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICPRO_H
#define UI_PICPRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_picProClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionNew;
    QAction *actionDilation;
    QAction *actionRecent;
    QAction *actionSaveAs;
    QAction *actionHarris;
    QAction *actionShiTomasi;
    QAction *actionErode;
    QAction *actionResize;
    QAction *actionRotation;
    QAction *action_5;
    QAction *action_9;
    QAction *action_10;
    QAction *actionSobel;
    QAction *actionLaplace;
    QAction *actionCanny;
    QAction *actionAutoThreshold;
    QAction *actionBlur;
    QAction *actionGaussianBlur;
    QAction *actionMedianBlur;
    QAction *actionBilateralBlur;
    QAction *actionCamera;
    QAction *actionObjectDetect;
    QAction *actionSURF;
    QAction *actionSIFT;
    QAction *actionFAST;
    QAction *actionFlannBased;
    QAction *actionBruteForce;
    QAction *actionORB;
    QAction *actionHARRIS;
    QAction *actionMSER;
    QAction *actionSTAR;
    QAction *actionExtractorSIFT;
    QAction *actionExtractorSURF;
    QAction *actionTempletMatch;
    QAction *actionFeaturePoint2;
    QAction *actionFeatureMatch2;
    QAction *actionObjectDetect2;
    QAction *actionBestMatch;
    QAction *actionKnnMatch;
    QAction *actionBinary;
    QAction *actionBinaryInv;
    QAction *actionTrunc;
    QAction *actionTozeroInv;
    QAction *actionTozero;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_2;
    QLabel *showImageLabel;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *OpenImageButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *CloseImageButton;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *opLabel1;
    QLineEdit *opText1;
    QSpacerItem *verticalSpacer_3;
    QSlider *opSlider1;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *opLabel2;
    QLineEdit *opText2;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_2;
    QSlider *opSlider2;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_7;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuCornerPoint;
    QMenu *menuFeature;
    QMenu *menuFeaturePoint;
    QMenu *menuFeatureMatch;
    QMenu *menuExtractor;
    QMenu *menuBlur;
    QMenu *menuEdge;
    QMenu *menuThreshold;
    QMenu *menuFixThres;
    QMenu *menuPro;
	QLabel *msgLabel;

	void _setupUi(QMainWindow *qtestClass);

    void setupUi(QMainWindow *picProClass)
    {
        if (picProClass->objectName().isEmpty())
            picProClass->setObjectName(QStringLiteral("picProClass"));
        picProClass->resize(1036, 567);
        actionOpen = new QAction(picProClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(picProClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionNew = new QAction(picProClass);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionDilation = new QAction(picProClass);
        actionDilation->setObjectName(QStringLiteral("actionDilation"));
        actionRecent = new QAction(picProClass);
        actionRecent->setObjectName(QStringLiteral("actionRecent"));
        actionSaveAs = new QAction(picProClass);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionHarris = new QAction(picProClass);
        actionHarris->setObjectName(QStringLiteral("actionHarris"));
        actionShiTomasi = new QAction(picProClass);
        actionShiTomasi->setObjectName(QStringLiteral("actionShiTomasi"));
        actionErode = new QAction(picProClass);
        actionErode->setObjectName(QStringLiteral("actionErode"));
        actionResize = new QAction(picProClass);
        actionResize->setObjectName(QStringLiteral("actionResize"));
        actionRotation = new QAction(picProClass);
        actionRotation->setObjectName(QStringLiteral("actionRotation"));
        action_5 = new QAction(picProClass);
        action_5->setObjectName(QStringLiteral("action_5"));
        action_9 = new QAction(picProClass);
        action_9->setObjectName(QStringLiteral("action_9"));
        action_10 = new QAction(picProClass);
        action_10->setObjectName(QStringLiteral("action_10"));
        actionSobel = new QAction(picProClass);
        actionSobel->setObjectName(QStringLiteral("actionSobel"));
        actionLaplace = new QAction(picProClass);
        actionLaplace->setObjectName(QStringLiteral("actionLaplace"));
        actionCanny = new QAction(picProClass);
        actionCanny->setObjectName(QStringLiteral("actionCanny"));
        actionAutoThreshold = new QAction(picProClass);
        actionAutoThreshold->setObjectName(QStringLiteral("actionAutoThreshold"));
        actionBlur = new QAction(picProClass);
        actionBlur->setObjectName(QStringLiteral("actionBlur"));
        actionGaussianBlur = new QAction(picProClass);
        actionGaussianBlur->setObjectName(QStringLiteral("actionGaussianBlur"));
        actionMedianBlur = new QAction(picProClass);
        actionMedianBlur->setObjectName(QStringLiteral("actionMedianBlur"));
        actionBilateralBlur = new QAction(picProClass);
        actionBilateralBlur->setObjectName(QStringLiteral("actionBilateralBlur"));
        actionCamera = new QAction(picProClass);
        actionCamera->setObjectName(QStringLiteral("actionCamera"));
        actionObjectDetect = new QAction(picProClass);
        actionObjectDetect->setObjectName(QStringLiteral("actionObjectDetect"));
        actionSURF = new QAction(picProClass);
        actionSURF->setObjectName(QStringLiteral("actionSURF"));
        actionSIFT = new QAction(picProClass);
        actionSIFT->setObjectName(QStringLiteral("actionSIFT"));
        actionFAST = new QAction(picProClass);
        actionFAST->setObjectName(QStringLiteral("actionFAST"));
        actionFlannBased = new QAction(picProClass);
        actionFlannBased->setObjectName(QStringLiteral("actionFlannBased"));
        actionBruteForce = new QAction(picProClass);
        actionBruteForce->setObjectName(QStringLiteral("actionBruteForce"));
        actionORB = new QAction(picProClass);
        actionORB->setObjectName(QStringLiteral("actionORB"));
        actionHARRIS = new QAction(picProClass);
        actionHARRIS->setObjectName(QStringLiteral("actionHARRIS"));
        actionMSER = new QAction(picProClass);
        actionMSER->setObjectName(QStringLiteral("actionMSER"));
        actionSTAR = new QAction(picProClass);
        actionSTAR->setObjectName(QStringLiteral("actionSTAR"));
        actionExtractorSIFT = new QAction(picProClass);
        actionExtractorSIFT->setObjectName(QStringLiteral("actionExtractorSIFT"));
        actionExtractorSURF = new QAction(picProClass);
        actionExtractorSURF->setObjectName(QStringLiteral("actionExtractorSURF"));
        actionTempletMatch = new QAction(picProClass);
        actionTempletMatch->setObjectName(QStringLiteral("actionTempletMatch"));
        actionFeaturePoint2 = new QAction(picProClass);
        actionFeaturePoint2->setObjectName(QStringLiteral("actionFeaturePoint2"));
        actionFeatureMatch2 = new QAction(picProClass);
        actionFeatureMatch2->setObjectName(QStringLiteral("actionFeatureMatch2"));
        actionObjectDetect2 = new QAction(picProClass);
        actionObjectDetect2->setObjectName(QStringLiteral("actionObjectDetect2"));
        actionBestMatch = new QAction(picProClass);
        actionBestMatch->setObjectName(QStringLiteral("actionBestMatch"));
        actionKnnMatch = new QAction(picProClass);
        actionKnnMatch->setObjectName(QStringLiteral("actionKnnMatch"));
        actionBinary = new QAction(picProClass);
        actionBinary->setObjectName(QStringLiteral("actionBinary"));
        actionBinaryInv = new QAction(picProClass);
        actionBinaryInv->setObjectName(QStringLiteral("actionBinaryInv"));
        actionTrunc = new QAction(picProClass);
        actionTrunc->setObjectName(QStringLiteral("actionTrunc"));
        actionTozeroInv = new QAction(picProClass);
        actionTozeroInv->setObjectName(QStringLiteral("actionTozeroInv"));
        actionTozero = new QAction(picProClass);
        actionTozero->setObjectName(QStringLiteral("actionTozero"));
        centralWidget = new QWidget(picProClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 816, 504));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        showImageLabel = new QLabel(scrollAreaWidgetContents_2);
        showImageLabel->setObjectName(QStringLiteral("showImageLabel"));

        gridLayout_2->addWidget(showImageLabel, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_5->addWidget(scrollArea);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        OpenImageButton = new QPushButton(centralWidget);
        OpenImageButton->setObjectName(QStringLiteral("OpenImageButton"));

        horizontalLayout_3->addWidget(OpenImageButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        CloseImageButton = new QPushButton(centralWidget);
        CloseImageButton->setObjectName(QStringLiteral("CloseImageButton"));

        horizontalLayout_3->addWidget(CloseImageButton);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        opLabel1 = new QLabel(centralWidget);
        opLabel1->setObjectName(QStringLiteral("opLabel1"));

        horizontalLayout->addWidget(opLabel1);

        opText1 = new QLineEdit(centralWidget);
        opText1->setObjectName(QStringLiteral("opText1"));

        horizontalLayout->addWidget(opText1);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        opSlider1 = new QSlider(centralWidget);
        opSlider1->setObjectName(QStringLiteral("opSlider1"));
        opSlider1->setMinimum(1);
        opSlider1->setMaximum(100);
        opSlider1->setOrientation(Qt::Horizontal);
        opSlider1->setTickPosition(QSlider::TicksAbove);

        verticalLayout->addWidget(opSlider1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        opLabel2 = new QLabel(centralWidget);
        opLabel2->setObjectName(QStringLiteral("opLabel2"));

        horizontalLayout_2->addWidget(opLabel2);

        opText2 = new QLineEdit(centralWidget);
        opText2->setObjectName(QStringLiteral("opText2"));

        horizontalLayout_2->addWidget(opText2);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        opSlider2 = new QSlider(centralWidget);
        opSlider2->setObjectName(QStringLiteral("opSlider2"));
        opSlider2->setOrientation(Qt::Horizontal);
        opSlider2->setTickPosition(QSlider::TicksAbove);

        verticalLayout->addWidget(opSlider2);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);


        horizontalLayout_5->addLayout(verticalLayout);

        horizontalLayout_5->setStretch(0, 6);
        horizontalLayout_5->setStretch(2, 1);

        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        picProClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(picProClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        picProClass->setStatusBar(statusBar);
        menuBar = new QMenuBar(picProClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1036, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuFile->setAutoFillBackground(true);
        menuCornerPoint = new QMenu(menuBar);
        menuCornerPoint->setObjectName(QStringLiteral("menuCornerPoint"));
        menuFeature = new QMenu(menuBar);
        menuFeature->setObjectName(QStringLiteral("menuFeature"));
        menuFeaturePoint = new QMenu(menuFeature);
        menuFeaturePoint->setObjectName(QStringLiteral("menuFeaturePoint"));
        menuFeatureMatch = new QMenu(menuFeature);
        menuFeatureMatch->setObjectName(QStringLiteral("menuFeatureMatch"));
        menuExtractor = new QMenu(menuFeature);
        menuExtractor->setObjectName(QStringLiteral("menuExtractor"));
        menuBlur = new QMenu(menuBar);
        menuBlur->setObjectName(QStringLiteral("menuBlur"));
        menuEdge = new QMenu(menuBar);
        menuEdge->setObjectName(QStringLiteral("menuEdge"));
        menuThreshold = new QMenu(menuBar);
        menuThreshold->setObjectName(QStringLiteral("menuThreshold"));
        menuFixThres = new QMenu(menuThreshold);
        menuFixThres->setObjectName(QStringLiteral("menuFixThres"));
        menuPro = new QMenu(menuBar);
        menuPro->setObjectName(QStringLiteral("menuPro"));
        picProClass->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuPro->menuAction());
        menuBar->addAction(menuBlur->menuAction());
        menuBar->addAction(menuThreshold->menuAction());
        menuBar->addAction(menuEdge->menuAction());
        menuBar->addAction(menuCornerPoint->menuAction());
        menuBar->addAction(menuFeature->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionCamera);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuCornerPoint->addAction(actionHarris);
        menuCornerPoint->addAction(actionShiTomasi);
        menuFeature->addAction(menuFeaturePoint->menuAction());
        menuFeature->addAction(menuExtractor->menuAction());
        menuFeature->addAction(menuFeatureMatch->menuAction());
        menuFeature->addSeparator();
        menuFeature->addAction(actionObjectDetect);
        menuFeature->addAction(actionTempletMatch);
        menuFeaturePoint->addAction(actionHARRIS);
        menuFeaturePoint->addAction(actionSURF);
        menuFeaturePoint->addAction(actionSIFT);
        menuFeaturePoint->addAction(actionFAST);
        menuFeaturePoint->addAction(actionORB);
        menuFeaturePoint->addAction(actionMSER);
        menuFeaturePoint->addAction(actionSTAR);
        menuFeatureMatch->addAction(actionBruteForce);
        menuFeatureMatch->addAction(actionFlannBased);
        menuFeatureMatch->addSeparator();
        menuFeatureMatch->addAction(actionBestMatch);
        menuFeatureMatch->addAction(actionKnnMatch);
        menuExtractor->addAction(actionExtractorSIFT);
        menuExtractor->addAction(actionExtractorSURF);
        menuBlur->addAction(actionBlur);
        menuBlur->addAction(actionGaussianBlur);
        menuBlur->addAction(actionMedianBlur);
        menuBlur->addAction(actionBilateralBlur);
        menuEdge->addAction(actionSobel);
        menuEdge->addAction(actionLaplace);
        menuEdge->addAction(actionCanny);
        menuThreshold->addAction(menuFixThres->menuAction());
        menuThreshold->addAction(actionAutoThreshold);
        menuFixThres->addAction(actionBinary);
        menuFixThres->addAction(actionBinaryInv);
        menuFixThres->addAction(actionTrunc);
        menuFixThres->addAction(actionTozero);
        menuFixThres->addAction(actionTozeroInv);
        menuPro->addAction(actionResize);
        menuPro->addAction(actionRotation);
        menuPro->addSeparator();
        menuPro->addAction(actionDilation);
        menuPro->addAction(actionErode);
        menuPro->addSeparator();

        retranslateUi(picProClass);

        QMetaObject::connectSlotsByName(picProClass);
    } // setupUi

    void retranslateUi(QMainWindow *picProClass)
    {
        picProClass->setWindowTitle(QApplication::translate("picProClass", "qtest", 0));
        actionOpen->setText(QApplication::translate("picProClass", "\346\211\223\345\274\200", 0));
        actionSave->setText(QApplication::translate("picProClass", "\344\277\235\345\255\230", 0));
        actionNew->setText(QApplication::translate("picProClass", "\346\226\260\345\273\272", 0));
        actionDilation->setText(QApplication::translate("picProClass", "\350\206\250\350\203\200", 0));
        actionRecent->setText(QApplication::translate("picProClass", "\346\234\200\350\277\221", 0));
        actionSaveAs->setText(QApplication::translate("picProClass", "\345\217\246\345\255\230\344\270\272", 0));
        actionHarris->setText(QApplication::translate("picProClass", "Harris", 0));
        actionShiTomasi->setText(QApplication::translate("picProClass", "Shi-Tomasi", 0));
        actionErode->setText(QApplication::translate("picProClass", "\350\205\220\350\232\200", 0));
        actionResize->setText(QApplication::translate("picProClass", "\347\274\251\346\224\276", 0));
        actionRotation->setText(QApplication::translate("picProClass", "\346\227\213\350\275\254", 0));
        action_5->setText(QApplication::translate("picProClass", "\346\227\213\350\275\254", 0));
        action_9->setText(QApplication::translate("picProClass", "\345\233\272\345\256\232\351\230\200\345\200\274", 0));
        action_10->setText(QApplication::translate("picProClass", "\350\207\252\351\200\202\345\272\224\351\230\200\345\200\274", 0));
        actionSobel->setText(QApplication::translate("picProClass", "Sobel", 0));
        actionLaplace->setText(QApplication::translate("picProClass", "Laplace", 0));
        actionCanny->setText(QApplication::translate("picProClass", "Canny", 0));
        actionAutoThreshold->setText(QApplication::translate("picProClass", "\350\207\252\351\200\202\345\272\224\351\230\200\345\200\274", 0));
        actionBlur->setText(QApplication::translate("picProClass", "\345\235\207\345\200\274\345\271\263\346\273\221", 0));
        actionGaussianBlur->setText(QApplication::translate("picProClass", "\351\253\230\346\226\257\345\271\263\346\273\221", 0));
        actionMedianBlur->setText(QApplication::translate("picProClass", "\344\270\255\345\200\274\345\271\263\346\273\221", 0));
        actionBilateralBlur->setText(QApplication::translate("picProClass", "\345\217\214\350\276\271\345\271\263\346\273\221", 0));
        actionCamera->setText(QApplication::translate("picProClass", "\346\213\215\347\205\247", 0));
        actionObjectDetect->setText(QApplication::translate("picProClass", "\345\271\263\351\235\242\347\211\251\344\275\223\346\243\200\346\265\213", 0));
        actionSURF->setText(QApplication::translate("picProClass", "SURF", 0));
        actionSIFT->setText(QApplication::translate("picProClass", "SIFT", 0));
        actionFAST->setText(QApplication::translate("picProClass", "FAST", 0));
        actionFlannBased->setText(QApplication::translate("picProClass", "FlannBased", 0));
        actionBruteForce->setText(QApplication::translate("picProClass", "BruteForce", 0));
        actionORB->setText(QApplication::translate("picProClass", "ORB", 0));
        actionHARRIS->setText(QApplication::translate("picProClass", "HARRIS", 0));
        actionMSER->setText(QApplication::translate("picProClass", "MSER", 0));
        actionSTAR->setText(QApplication::translate("picProClass", "STAR", 0));
        actionExtractorSIFT->setText(QApplication::translate("picProClass", "SIFT", 0));
        actionExtractorSURF->setText(QApplication::translate("picProClass", "SURF", 0));
        actionTempletMatch->setText(QApplication::translate("picProClass", "\346\250\241\346\235\277\345\214\271\351\205\215", 0));
        actionFeaturePoint2->setText(QApplication::translate("picProClass", "\347\202\271", 0));
        actionFeatureMatch2->setText(QApplication::translate("picProClass", "\345\214\271\351\205\215", 0));
        actionObjectDetect2->setText(QApplication::translate("picProClass", "\346\243\200\346\265\213", 0));
        actionBestMatch->setText(QApplication::translate("picProClass", "BestMatch", 0));
        actionKnnMatch->setText(QApplication::translate("picProClass", "KnnMatch", 0));
        actionBinary->setText(QApplication::translate("picProClass", "\344\272\214\350\277\233\345\210\266", 0));
        actionBinaryInv->setText(QApplication::translate("picProClass", "\345\217\215\344\272\214\350\277\233\345\210\266", 0));
        actionTrunc->setText(QApplication::translate("picProClass", "\346\210\252\346\226\255", 0));
        actionTozeroInv->setText(QApplication::translate("picProClass", "\345\217\215\351\230\200\345\200\274\345\214\226\344\270\272\351\233\266", 0));
        actionTozero->setText(QApplication::translate("picProClass", "\351\230\200\345\200\274\345\214\226\344\270\272\351\233\266", 0));
        showImageLabel->setText(QString());
        OpenImageButton->setText(QApplication::translate("picProClass", "OpenImage", 0));
        CloseImageButton->setText(QApplication::translate("picProClass", "CloseImage", 0));
        opLabel1->setText(QApplication::translate("picProClass", "Threshold:", 0));
        opText1->setText(QApplication::translate("picProClass", "1", 0));
        opLabel2->setText(QApplication::translate("picProClass", "Threshold:", 0));
        opText2->setText(QApplication::translate("picProClass", "0", 0));
        menuFile->setTitle(QApplication::translate("picProClass", "\346\226\207\344\273\266", 0));
        menuCornerPoint->setTitle(QApplication::translate("picProClass", "\350\247\222\347\202\271\346\243\200\346\265\213", 0));
        menuFeature->setTitle(QApplication::translate("picProClass", "\347\211\271\345\276\201\346\243\200\346\265\213", 0));
        menuFeaturePoint->setTitle(QApplication::translate("picProClass", "\347\211\271\345\276\201\347\202\271\346\243\200\346\265\213", 0));
        menuFeatureMatch->setTitle(QApplication::translate("picProClass", "\347\211\271\345\276\201\347\202\271\345\214\271\351\205\215", 0));
        menuExtractor->setTitle(QApplication::translate("picProClass", "\347\211\271\345\276\201\346\217\217\350\277\260", 0));
        menuBlur->setTitle(QApplication::translate("picProClass", "\345\271\263\346\273\221\345\244\204\347\220\206", 0));
        menuEdge->setTitle(QApplication::translate("picProClass", "\350\276\271\347\274\230\346\217\220\345\217\226", 0));
        menuThreshold->setTitle(QApplication::translate("picProClass", "\351\230\200\345\200\274\345\210\206\345\211\262", 0));
        menuFixThres->setTitle(QApplication::translate("picProClass", "\345\233\272\345\256\232\351\230\200\345\200\274", 0));
        menuPro->setTitle(QApplication::translate("picProClass", "\347\256\200\345\215\225\345\244\204\347\220\206", 0));
    } // retranslateUi

};

namespace Ui {
    class picProClass: public Ui_picProClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICPRO_H
