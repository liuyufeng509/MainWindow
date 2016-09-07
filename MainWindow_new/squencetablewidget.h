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
	void saveDataFromUI();				//�ӽ��汣������
	SquenceData removeSelectedData();	//ɾ��ѡ�����У������ظ�������
	SquenceData selectedData();				//����ѡ���е�����

public slots:
		void updateDataToUI();			//�������ݵ�����
		void dealCellDoubleClicked(int row , int column);
 signals:
		void CellDoubleClicked(SquenceData&data);
private:
	QVector<SquenceData> &m_squenceDatas;
};

#endif // SQUENCETABLEWIDGET_H
