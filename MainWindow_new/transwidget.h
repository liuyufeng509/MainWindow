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

	void TransDataChanged(TranslationPlanData data);					//当修改了内容后，要通知主窗口对该条记录进行修改。
	public slots:
		void foucsChanged(QWidget*old, QWidget*now);		//当窗口内的焦点发生变化时
private:
	Ui::TransWidget ui;
	TranslationPlanData m_data;	//消息

	QVector<SgData>  m_sgsDatas;		//所有灯组的数据。
};

#endif // TRANSWIDGET_H
