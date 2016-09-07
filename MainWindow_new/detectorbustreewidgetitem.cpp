#include "detectorbustreewidgetitem.h"

DetectorBusTreeWidgetItem::DetectorBusTreeWidgetItem(DetectorBusData &data, QTreeWidgetItem *parent)
	: QTreeWidgetItem(parent),
	m_data(data)
{
	InitItem();
}

void DetectorBusTreeWidgetItem::InitItem()
{
	//��������ӽڵ�
	QString strName = QString("%1").arg(QString(m_data.strName));
	setText(0, strName);
	setIcon(0, QIcon(":/Tree/detector"));
}

DetectorBusTreeWidgetItem::~DetectorBusTreeWidgetItem()
{

}
