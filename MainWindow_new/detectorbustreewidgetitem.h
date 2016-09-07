#ifndef DETECTORBUSTREEWIDGETITEM_H
#define DETECTORBUSTREEWIDGETITEM_H

#include <QTreeWidgetItem>
#include "common.h"
class DetectorBusTreeWidgetItem : public QObject, public QTreeWidgetItem
{
	Q_OBJECT

public:
	DetectorBusTreeWidgetItem(DetectorBusData &data, QTreeWidgetItem *parent=0);
	~DetectorBusTreeWidgetItem();
	void SetData(DetectorBusData &data){m_data = data;InitItem();}
	void InitItem();

	DetectorBusData m_data;
private:
	
};

#endif // DETECTORBUSTREEWIDGETITEM_H
