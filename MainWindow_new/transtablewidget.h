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

	void saveDataFromUI();				//�ӽ��汣������
	TranslationPlanData removeSelectedData();	//ɾ��ѡ�����У������ظ�������
	TranslationPlanData selectedData();				//����ѡ���е�����

	public slots:
		void updateDataToUI();			//�������ݵ�����
		void dealCellDoubleClicked(int row , int column);
signals:
		void CellDoubleClicked(TranslationPlanData&data);


private:
	QVector<TranslationPlanData> &m_transDatas;
	
};

#endif // TRANSTABLEWIDGET_H
