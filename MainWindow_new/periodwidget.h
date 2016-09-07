#ifndef PERIODWIDGET_H
#define PERIODWIDGET_H

#include <QWidget>
#include "ui_periodwidget.h"
#include "common.h"

class PeriodWidget : public QWidget
{
	Q_OBJECT

public:
	PeriodWidget(QWidget *parent = 0);
	~PeriodWidget();
	void setData(const PeriodData &data, 
		const QVector<TranslationPlanData>  &tranPlanDatas, const QVector<SignalProgData>&signalProgs );
	void updateDataToUI();
	void saveDataFromUI();

signals:

	void PeriodDataChanged(PeriodData data);					//���޸������ݺ�Ҫ֪ͨ�����ڶԸ�����¼�����޸ġ�

public slots:
		void foucsChanged(QWidget*old, QWidget*now);		//�������ڵĽ��㷢���仯ʱ
		void setStartTime(const QTime &time);
		void setEndTime(const QTime &time);
private:
	Ui::PeriodWidget ui;

	QVector<TranslationPlanData>  m_tranPlanDatas;
	QVector<SignalProgData>  m_signalProgs;
	PeriodData m_data;
};

#endif // PERIODWIDGET_H
