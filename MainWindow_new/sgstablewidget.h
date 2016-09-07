#ifndef SGSTABLEWIDGET_H
#define SGSTABLEWIDGET_H

#include <QTableWidget>
#include <QHeaderView>
#include "common.h"
/************************************************************************/
/* 显示信号灯粗略信息的表格                                                                     */
/************************************************************************/
class SgsTableWidget : public QTableWidget
{
	Q_OBJECT

public:
	SgsTableWidget(QVector<SgData>  &sgsDatas, QWidget *parent=0);
	~SgsTableWidget();
	
	SgData removeSelectedData();  //删除并返回被选中行的数据
	SgData selectedData();		//获取选中行的数据
	void saveDataFromUI();  //保存数据
public slots:
		void updateDataToUI();  //更新表格

		void dealCellChanged(int row,int column);//处理单元格内容改变消息
		void dealCellDoubleClicked(int row , int column);
signals:
		 void cellChanged(SgData data);	//发送给树，更新节点显示
		 void CellDoubleClicked(SgData &data);
private:

	QVector<SgData>  &m_sgsDatas;		//所有灯组的数据。
};

#endif // SGSTABLEWIDGET_H
