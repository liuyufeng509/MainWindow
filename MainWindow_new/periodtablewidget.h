#ifndef PERIODTABLEWIDGET_H
#define PERIODTABLEWIDGET_H

#include <QTableWidget>
#include "common.h"
#include <QHeaderView>

class PeriodTableWidget : public QTableWidget
{
	Q_OBJECT

public:
	PeriodTableWidget(QVector<PeriodData> &datas, QWidget *parent=0);
	~PeriodTableWidget();
	
	void saveDataFromUI();				//�ӽ��汣������
	PeriodData removeSelectedData();	//ɾ��ѡ�����У������ظ�������
	PeriodData selectedData();				//����ѡ���е�����

public slots:
		void updateDataToUI();			//�������ݵ�����
		void dealCellDoubleClicked(int row , int column);
signals:
		void PeriodCellDoubleClicked(PeriodData&data);

private:
	QVector<PeriodData> &m_periodDatas;
};

#endif // PERIODTABLEWIDGET_H
