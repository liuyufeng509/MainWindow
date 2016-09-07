#include "detectorpedtreewdigetitem.h"

DetectorPedTreeWdigetItem::DetectorPedTreeWdigetItem(DetectorsPedestrainsData &data,QTreeWidgetItem *parent)
	: QTreeWidgetItem(parent),
	m_data(data)
{
	InitItem();
}

void DetectorPedTreeWdigetItem::InitItem()
{
	//��������ӽڵ�
	QString strName = QString("%1").arg(QString(m_data.strName));
	setText(0, strName);
	setIcon(0, QIcon(":/Tree/detector"));
}

DetectorPedTreeWdigetItem::~DetectorPedTreeWdigetItem()
{

}
