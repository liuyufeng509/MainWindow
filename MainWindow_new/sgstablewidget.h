#ifndef SGSTABLEWIDGET_H
#define SGSTABLEWIDGET_H

#include <QTableWidget>
#include <QHeaderView>
#include "common.h"
/************************************************************************/
/* ��ʾ�źŵƴ�����Ϣ�ı��                                                                     */
/************************************************************************/
class SgsTableWidget : public QTableWidget
{
	Q_OBJECT

public:
	SgsTableWidget(QVector<SgData>  &sgsDatas, QWidget *parent=0);
	~SgsTableWidget();
	
	SgData removeSelectedData();  //ɾ�������ر�ѡ���е�����
	SgData selectedData();		//��ȡѡ���е�����
	void saveDataFromUI();  //��������
public slots:
		void updateDataToUI();  //���±��

		void dealCellChanged(int row,int column);//����Ԫ�����ݸı���Ϣ
		void dealCellDoubleClicked(int row , int column);
signals:
		 void cellChanged(SgData data);	//���͸��������½ڵ���ʾ
		 void CellDoubleClicked(SgData &data);
private:

	QVector<SgData>  &m_sgsDatas;		//���е�������ݡ�
};

#endif // SGSTABLEWIDGET_H
