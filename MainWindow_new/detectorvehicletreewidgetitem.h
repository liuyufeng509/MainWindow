#ifndef DETECTORVEHICLETREEWIDGETITEM_H
#define DETECTORVEHICLETREEWIDGETITEM_H
#include "common.h"
#include <QTreeWidgetItem>

class DetectorVehicleTreeWidgetItem :  public QObject, public QTreeWidgetItem
{
	Q_OBJECT

public:
	DetectorVehicleTreeWidgetItem(DetectorVehicleData &data,QTreeWidgetItem *parent=0);
	~DetectorVehicleTreeWidgetItem();
	void SetData(DetectorVehicleData &data){m_data = data;InitItem();}
	void InitItem();

	DetectorVehicleData m_data;
private:
	
};

#endif // DETECTORVEHICLETREEWIDGETITEM_H
