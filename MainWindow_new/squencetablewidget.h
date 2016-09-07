#ifndef SQUENCETABLEWIDGET_H
#define SQUENCETABLEWIDGET_H

#include <QTableWidget>
#include "common.h"
#include <QHeaderView>

class SquenceTableWidget : public QTableWidget
{
	Q_OBJECT

public:
	SquenceTableWidget(QVector<SquenceData> &datas, QWidget *parent=0);
	~SquenceTableWidget();
	void saveDataFromUI();				//从界面保存数据
	SquenceData removeSelectedData();	//删除选定的行，并返回该行数据
	SquenceData selectedData();				//返回选定行的数据

public slots:
		void updateDataToUI();			//更新数据到界面
		void dealCellDoubleClicked(int row , int column);
 signals:
		void CellDoubleClicked(SquenceData&data);
private:
	QVector<SquenceData> &m_squenceDatas;
};

#endif // SQUENCETABLEWIDGET_H
