#ifndef SGPROGTREEWIDGETITEM_H
#define SGPROGTREEWIDGETITEM_H

#include <QTreeWidgetItem>
#include "common.h"
class SgProgTreeWidgetItem : public QObject, public QTreeWidgetItem
{
	Q_OBJECT

public:
	SgProgTreeWidgetItem(SignalProgData &data,QTreeWidgetItem *parent=0);
	~SgProgTreeWidgetItem();
	void SetData(SignalProgData &data){m_data = data;InitItem();}
	void InitItem();
public:
	SignalProgData m_data;
};

#endif // SGPROGTREEWIDGETITEM_H
