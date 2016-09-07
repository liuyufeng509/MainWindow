#include "sgtreewidgetitem.h"

SgTreeWidgetItem::SgTreeWidgetItem(SgData &data,QTreeWidgetItem  *parent,int type)
	: QTreeWidgetItem(parent,type),
	m_data(data)
{
	InitItem();
}

void SgTreeWidgetItem::InitItem()
{
	//ֱ�Ӹ������ݹ���һ���ڵ�
	QString strName = QString("%1:%2").arg(m_data.nId).arg(QString(m_data.strName));
	setText(0, strName);
	setIcon(0, QIcon(":/Tree/signalLight"));
}
SgTreeWidgetItem::~SgTreeWidgetItem()
{

}
