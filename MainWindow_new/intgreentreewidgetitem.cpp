#include "intgreentreewidgetitem.h"

IntGreenTreeWidgetItem::IntGreenTreeWidgetItem(InterGreenMatrixData &data,QTreeWidgetItem *parent)
	: QTreeWidgetItem(parent),
	m_data(data)
{
	InitItem();
}

void IntGreenTreeWidgetItem::InitItem()
{
	//直接根据数据构造一个节点
	QString strName = QString("%1:%2").arg(m_data.nId).arg(QString(m_data.strName));
	setText(0, strName);
	setIcon(0, QIcon(":/Tree/greenIntervalMatrix"));
}

IntGreenTreeWidgetItem::~IntGreenTreeWidgetItem()
{

}
