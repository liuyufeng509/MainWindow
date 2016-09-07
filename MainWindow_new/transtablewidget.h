#ifndef TRANSTABLEWIDGET_H
#define TRANSTABLEWIDGET_H

#include <QTableWidget>
#include "common.h"
#include <QHeaderView>

class TransTableWidget : public QTableWidget
{
	Q_OBJECT

public:
	TransTableWidget(QVector<TranslationPlanData> &datas,QWidget *parent=0);
	~TransTableWidget();

	void saveDataFromUI();				//从界面保存数据
	TranslationPlanData removeSelectedData();	//删除选定的行，并返回该行数据
	TranslationPlanData selectedData();				//返回选定行的数据

	public slots:
		void updateDataToUI();			//更新数据到界面
		void dealCellDoubleClicked(int row , int column);
signals:
		void CellDoubleClicked(TranslationPlanData&data);


private:
	QVector<TranslationPlanData> &m_transDatas;
	
};

#endif // TRANSTABLEWIDGET_H
