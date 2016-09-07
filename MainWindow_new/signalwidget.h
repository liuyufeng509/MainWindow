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
	
	void setAllColumnsHidden(bool ishide);		//���ر��ȫ����
	void updateDataToUI();
	void saveDataFromUI();
	void saveDurationWithSquence(int squence);		//���ݵ��򣬱���Ĭ�ϵ�durationֵ
signals:
	
	void dataChanged(SgData data);					//���޸������ݺ�Ҫ֪ͨ�����ڶԸ�����¼�����޸ġ�
public slots:
	void updateTableWithSquence(int squence);   //���ݵ�ǰ�ĵ������ò���ʾ����ɫĬ��ֵ
	void foucsChanged(QWidget*old, QWidget*now);		//�������ڵĽ��㷢���仯ʱ

private:
	Ui::SignalWidget ui;
	SgData m_data;
};

#endif // SIGNALWIDGET_H
