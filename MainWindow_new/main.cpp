#include "mainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	//ע��MessageHandler
	qInstallMessageHandler(outputMessage);
	w.show();
	return a.exec();
}
