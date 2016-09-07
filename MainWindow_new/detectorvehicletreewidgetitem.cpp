#include "detectorvehicletreewidgetitem.h"

DetectorVehicleTreeWidgetItem::DetectorVehicleTreeWidgetItem(DetectorVehicleData &data,QTreeWidgetItem *parent)
	: QTreeWidgetItem(parent),
	m_data(data)
{
	InitItem();
}

void DetectorVehicleTreeWidgetItem::InitItem()
{
	//添加树的子节点
	QString strName = QString("%1").arg(QString(m_data.strName));
	setText(0, strName);
	setIcon(0, QIcon(":/Tree/detector"));
}

DetectorVehicleTreeWidgetItem::~DetectorVehicleTreeWidgetItem()
{

}
