#ifndef INTGRMTRXTABLEWIDGET_H
#define INTGRMTRXTABLEWIDGET_H

#include <QTableWidget>
#include "common.h"
#include <QHeaderView>
class IntGrMtrxTableWidget : public QTableWidget
{
	Q_OBJECT

public:
	IntGrMtrxTableWidget(QVector<InterGreenMatrixData> &datas, QWidget *parent=0);
	~IntGrMtrxTableWidget();
	void saveDataFromUI();
	InterGreenMatrixData removeSelectedData();
	InterGreenMatrixData selectedData();
public slots:
	void updateDataToUI();
	void dealCellChanged(int row,int column);//处理单元格内容改变消息
	void dealCellDoubleClicked(int row , int column);

signals:
	void cellChanged(InterGreenMatrixData data);	//发送给树，更新节点显示
	void CellDoubleClicked(InterGreenMatrixData &data);

private:
	QVector<InterGreenMatrixData> &m_intGrMtrxDatas;	//所有绿灯间隔的数据
};

#endif // INTGRMTRXTABLEWIDGET_H
