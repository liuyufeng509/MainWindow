#ifndef SCWIDGET_H
#define SCWIDGET_H

#include <QWidget>
#include "ui_scwidget.h"
#include "common.h"

class ScWidget : public QWidget
{
	Q_OBJECT

public:
	ScWidget(ScData &data,QWidget *parent = 0);
	~ScWidget();
	void updateDataToUI();
	void saveDataFromUI();
private:
	Ui::ScWidget ui;
	ScData &m_data;
};
 
#endif // SCWIDGET_H
