#ifndef GREENINTMATRIXWIDGET_H
#define GREENINTMATRIXWIDGET_H

#include <QWidget>
#include "ui_greenintmatrixwidget.h"
#include "common.h"
#include <QTreeWidgetItem>
class GreenIntMatrixWidget : public QWidget
{
	Q_OBJECT

public:
	GreenIntMatrixWidget(QWidget *parent = 0);
	~GreenIntMatrixWidget();
	void setData(const InterGreenMatrixData&data, const QVector<SgData>  &sgsDatas );
	void updateDataToUI();
	void saveDataFromUI();
signals:

	void dataChanged(InterGreenMatrixData data);					//当修改了内容后，要通知主窗口对该条记录进行修改。
public slots:
	void foucsChanged(QWidget*old, QWidget*now);		//当窗口内的焦点发生变化时
private:
	Ui::greenIntMatrixWidget ui;
	
	InterGreenMatrixData m_data;	//消息

	QVector<SgData>  m_sgsDatas;		//所有灯组的数据。
	QMap<int , int>		map;		//记录行列数与信号灯编号的关系
};

#endif // GREENINTMATRIXWIDGET_H
