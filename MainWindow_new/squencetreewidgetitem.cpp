#include "squencetreewidgetitem.h"

SquenceTreeWidgetItem::SquenceTreeWidgetItem(SquenceData &data, QTreeWidgetItem *parent, int type)
	: QTreeWidgetItem(parent, type),
	m_data(data)
{
	InitItem();
}

void SquenceTreeWidgetItem::InitItem()
{
	//ֱ�Ӹ������ݹ���һ���ڵ�
	QString strName = QString("%1:%2").arg(m_data.nId).arg(QString(m_data.strName));
	setText(0, strName);
	setIcon(0, QIcon(":/Tree/squence"));
}
SquenceTreeWidgetItem::~SquenceTreeWidgetItem()
{

}
