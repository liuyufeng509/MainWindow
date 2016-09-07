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
	
	void saveDataFromUI();				//从界面保存数据
	PeriodData removeSelectedData();	//删除选定的行，并返回该行数据
	PeriodData selectedData();				//返回选定行的数据

public slots:
		void updateDataToUI();			//更新数据到界面
		void dealCellDoubleClicked(int row , int column);
signals:
		void PeriodCellDoubleClicked(PeriodData&data);

private:
	QVector<PeriodData> &m_periodDatas;
};

#endif // PERIODTABLEWIDGET_H
