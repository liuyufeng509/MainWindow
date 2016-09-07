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

	void dataChanged(InterGreenMatrixData data);					//���޸������ݺ�Ҫ֪ͨ�����ڶԸ�����¼�����޸ġ�
public slots:
	void foucsChanged(QWidget*old, QWidget*now);		//�������ڵĽ��㷢���仯ʱ
private:
	Ui::greenIntMatrixWidget ui;
	
	InterGreenMatrixData m_data;	//��Ϣ

	QVector<SgData>  m_sgsDatas;		//���е�������ݡ�
	QMap<int , int>		map;		//��¼���������źŵƱ�ŵĹ�ϵ
};

#endif // GREENINTMATRIXWIDGET_H
