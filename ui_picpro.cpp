
#include "ui_picpro.h"

void Ui_picProClass::_setupUi(QMainWindow *picProClass)
{
	scrollArea->setBackgroundRole(QPalette::Dark);
	//QLabel *msgLabel;
	//std::string str = "Ready";
	//const QString str = "Ready";
	//label= new QLabel(str,this);
	//QLabel msgLabel = new QLabel(str, this);
	msgLabel = new QLabel;
	msgLabel->setMinimumSize(statusBar->sizeHint()); //���ñ�ǩ��С�ߴ�
	msgLabel->setFrameShadow(QFrame::Sunken); //���ñ�ǩ��Ӱ
	msgLabel->setText("Ready");
	statusBar->addWidget(msgLabel);
}
/*
QLabel *msgLabel;

	void _setupUi(QMainWindow *qtestClass);
*/