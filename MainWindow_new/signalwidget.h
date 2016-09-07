#ifndef SIGNALWIDGET_H
#define SIGNALWIDGET_H

#include <QWidget>
#include "ui_signalwidget.h"
#include "common.h"
#include <QTreeWidgetItem>

class SignalWidget : public QWidget
{
	Q_OBJECT

public:
	SignalWidget(QWidget *parent = 0);
	~SignalWidget();

	
	void setData(const SgData &data);
	
	void setAllColumnsHidden(bool ishide);		//隐藏表格全部列
	void updateDataToUI();
	void saveDataFromUI();
	void saveDurationWithSquence(int squence);		//根据灯序，保存默认的duration值
signals:
	
	void dataChanged(SgData data);					//当修改了内容后，要通知主窗口对该条记录进行修改。
public slots:
	void updateTableWithSquence(int squence);   //根据当前的灯序，设置并显示表格灯色默认值
	void foucsChanged(QWidget*old, QWidget*now);		//当窗口内的焦点发生变化时

private:
	Ui::SignalWidget ui;
	SgData m_data;
};

#endif // SIGNALWIDGET_H
