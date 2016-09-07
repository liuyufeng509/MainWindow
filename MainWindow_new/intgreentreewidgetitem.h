#ifndef INTGREENTREEWIDGETITEM_H
#define INTGREENTREEWIDGETITEM_H

#include <QTreeWidgetItem>
#include "common.h"
class IntGreenTreeWidgetItem : public QObject, public QTreeWidgetItem
{
	Q_OBJECT

public:
	IntGreenTreeWidgetItem(InterGreenMatrixData &data, QTreeWidgetItem *parent = 0);
	~IntGreenTreeWidgetItem();
	void SetData(InterGreenMatrixData &data){m_data = data; InitItem();}

	void InitItem();
	InterGreenMatrixData GetData(){return m_data;}
	public:
	InterGreenMatrixData m_data;
};

#endif // INTGREENTREEWIDGETITEM_H
