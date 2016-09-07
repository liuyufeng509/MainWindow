#ifndef SEQUENCEWIDGET_H
#define SEQUENCEWIDGET_H

#include <QWidget>
#include "ui_sequencewidget.h"
#include "common.h"
#include <QTreeWidgetItem>


class SequenceWidget : public QWidget
{
	Q_OBJECT

public:
	SequenceWidget(QWidget *parent = 0);
	~SequenceWidget();

	void setData(const SquenceData &data, const QVector<SgData>  &sgsDatas );
	void updateDataToUI();
	void saveDataFromUI();

signals:

	void squenceDataChanged(SquenceData data);					//���޸������ݺ�Ҫ֪ͨ�����ڶԸ�����¼�����޸ġ�
public slots:
		void foucsChanged(QWidget*old, QWidget*now);		//�������ڵĽ��㷢���仯ʱ
		void dealCellDoubleClicked(int row, int column);
private:
	Ui::SequenceWidget ui;
	SquenceData m_data;	//��Ϣ

	QVector<SgData>  m_sgsDatas;		//���е�������ݡ�
};

#endif // SEQUENCEWIDGET_H
