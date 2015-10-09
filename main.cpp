#include "picpro.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	picPro w;
	w.setWindowTitle("picPro");
	w.show();
	return a.exec();
}
