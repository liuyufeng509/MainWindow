#include "squencetreewidgetitem.h"

SquenceTreeWidgetItem::SquenceTreeWidgetItem(SquenceData &data, QTreeWidgetItem *parent, int type)
	: QTreeWidgetItem(parent, type),
	m_data(data)
{
	InitItem();
}

void SquenceTreeWidgetItem::InitItem()
{
	//直接根据数据构造一个节点
	QString strName = QString("%1:%2").arg(m_data.nId).arg(QString(m_data.strName));
	setText(0, strName);
	setIcon(0, QIcon(":/Tree/squence"));
}
SquenceTreeWidgetItem::~SquenceTreeWidgetItem()
{

}
