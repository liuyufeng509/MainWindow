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
	void dealCellChanged(int row,int column);//����Ԫ�����ݸı���Ϣ
	void dealCellDoubleClicked(int row , int column);

signals:
	void cellChanged(InterGreenMatrixData data);	//���͸��������½ڵ���ʾ
	void CellDoubleClicked(InterGreenMatrixData &data);

private:
	QVector<InterGreenMatrixData> &m_intGrMtrxDatas;	//�����̵Ƽ��������
};

#endif // INTGRMTRXTABLEWIDGET_H
