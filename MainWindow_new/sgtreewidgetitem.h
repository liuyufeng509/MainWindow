#ifndef TREEWIDGETITEM_H
#define TREEWIDGETITEM_H
#include "common.h"
#include <QTreeWidgetItem>
class SgTreeWidgetItem :public QObject, public QTreeWidgetItem
{
	Q_OBJECT

public:
	SgTreeWidgetItem(SgData &data,QTreeWidgetItem  *parent=0, int type = Type);
	~SgTreeWidgetItem();
	void SetData(SgData &data){m_data = data; InitItem();}

	void InitItem();
public:
	SgData m_data;
};

#endif // TREEWIDGETITEM_H
