#include "mainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	//×˘˛áMessageHandler
	qInstallMessageHandler(outputMessage);
	w.show();
	return a.exec();
}
