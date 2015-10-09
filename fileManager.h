
/**
*	文件接口
*/


#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <QtWidgets/qfiledialog.h>

class fileManager
{
	std::string open()
	{
		QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
		std::string imagePath = fileName.toStdString();
		if ( imagePath.empty() )
			return NULL;
		return imagePath;
	}
};

#endif FILEMANAGER_H