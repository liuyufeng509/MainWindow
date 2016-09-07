#ifndef SIGNALPROGDATA_H
#define SIGNALPROGDATA_H

#include <QTableWidget>
#include <QHeaderView>
#include "common.h"
class SignalProgTableWidget : public QTableWidget
{
	Q_OBJECT

public:
	SignalProgTableWidget(QVector<SignalProgData> &datas, QWidget *parent=0);
	~SignalProgTableWidget();
	void saveDataFromUI();
	SignalProgData selectedData();
	SignalProgData removeSelectedData();
public slots:
	void updateDataToUI();
	void dealCellChanged(int row,int column);//处理单元格内容改变消息
	void dealCellDoubleClicked(int row , int column);

signals:
	void cellChanged(SignalProgData data);	//发送给树，更新节点显示
	void CellDoubleClicked(SignalProgData &data);

private:
	QVector<SignalProgData> &m_signalProgs;
};

#endif // SIGNALPROGDATA_H
