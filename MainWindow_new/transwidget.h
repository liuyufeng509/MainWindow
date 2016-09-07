#ifndef TRANSWIDGET_H
#define TRANSWIDGET_H

#include <QWidget>
#include "ui_transwidget.h"
#include "common.h"
#include <QTreeWidgetItem>

class TransWidget : public QWidget
{
	Q_OBJECT

public:
	TransWidget(QWidget *parent = 0);
	~TransWidget();

	void setData(const TranslationPlanData &data, const QVector<SgData>  &sgsDatas );
	void updateDataToUI();
	void saveDataFromUI();

signals:

	void TransDataChanged(TranslationPlanData data);					//���޸������ݺ�Ҫ֪ͨ�����ڶԸ�����¼�����޸ġ�
	public slots:
		void foucsChanged(QWidget*old, QWidget*now);		//�������ڵĽ��㷢���仯ʱ
private:
	Ui::TransWidget ui;
	TranslationPlanData m_data;	//��Ϣ

	QVector<SgData>  m_sgsDatas;		//���е�������ݡ�
};

#endif // TRANSWIDGET_H
