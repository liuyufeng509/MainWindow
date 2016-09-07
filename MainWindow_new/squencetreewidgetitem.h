#ifndef SQUENCETREEWIDGETITEM_H
#define SQUENCETREEWIDGETITEM_H
#include "common.h"
#include <QTreeWidgetItem>

class SquenceTreeWidgetItem : public QObject, public QTreeWidgetItem
{
	Q_OBJECT

public:
	SquenceTreeWidgetItem(SquenceData &data, QTreeWidgetItem *parent=0, int type = Type);
	~SquenceTreeWidgetItem();
	void SetData(SquenceData &data) {m_data = data; InitItem();}
	void InitItem();
public:
	SquenceData m_data;
};

#endif // SQUENCETREEWIDGETITEM_H
