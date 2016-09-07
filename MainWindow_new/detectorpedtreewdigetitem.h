#ifndef DETECTORPEDTREEWDIGETITEM_H
#define DETECTORPEDTREEWDIGETITEM_H

#include <QTreeWidgetItem>
#include "common.h"
class DetectorPedTreeWdigetItem :  public QObject,  public QTreeWidgetItem
{
	Q_OBJECT

public:
	DetectorPedTreeWdigetItem(DetectorsPedestrainsData &data,QTreeWidgetItem *parent=0);
	~DetectorPedTreeWdigetItem();
	void SetData(DetectorsPedestrainsData &data){m_data = data;InitItem();}
	void InitItem();

	DetectorsPedestrainsData m_data;
private:
	
};

#endif // DETECTORPEDTREEWDIGETITEM_H
