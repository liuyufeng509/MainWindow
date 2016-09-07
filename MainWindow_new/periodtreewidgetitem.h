#ifndef PERIODTREEWIDGETITEM_H
#define PERIODTREEWIDGETITEM_H
#include "common.h"
#include <QTreeWidgetItem>

class PeriodTreeWidgetItem :  public QObject, public QTreeWidgetItem
{
	Q_OBJECT

public:
	PeriodTreeWidgetItem(PeriodData &data, QTreeWidgetItem *parent=0);
	~PeriodTreeWidgetItem();
	void SetData(PeriodData &data){m_data = data;InitItem();}
	void InitItem();

	PeriodData m_data;
private:
	
};

#endif // PERIODTREEWIDGETITEM_H
