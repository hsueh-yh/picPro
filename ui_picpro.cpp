
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
	msgLabel->setMinimumSize(statusBar->sizeHint()); //设置标签最小尺寸
	msgLabel->setFrameShadow(QFrame::Sunken); //设置标签阴影
	msgLabel->setText("Ready");
	statusBar->addWidget(msgLabel);
}
/*
QLabel *msgLabel;

	void _setupUi(QMainWindow *qtestClass);
*/