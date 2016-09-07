#include "sgprogtreewidgetitem.h"

SgProgTreeWidgetItem::SgProgTreeWidgetItem(SignalProgData &data,QTreeWidgetItem *parent)
	: QTreeWidgetItem(parent),
	m_data(data)
{
	
}

void SgProgTreeWidgetItem::InitItem()
{
	//添加树的子节点
	QString strName = QString("%1").arg(QString(m_data.strName));
	setText(0, strName);
	setIcon(0, QIcon(":/Tree/signalTimePlan"));
}

SgProgTreeWidgetItem::~SgProgTreeWidgetItem()
{

}
