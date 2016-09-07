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

	void squenceDataChanged(SquenceData data);					//当修改了内容后，要通知主窗口对该条记录进行修改。
public slots:
		void foucsChanged(QWidget*old, QWidget*now);		//当窗口内的焦点发生变化时
		void dealCellDoubleClicked(int row, int column);
private:
	Ui::SequenceWidget ui;
	SquenceData m_data;	//消息

	QVector<SgData>  m_sgsDatas;		//所有灯组的数据。
};

#endif // SEQUENCEWIDGET_H
