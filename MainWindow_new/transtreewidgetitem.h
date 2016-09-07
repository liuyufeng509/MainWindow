#ifndef TRANSTREEWIDGETITEM_H
#define TRANSTREEWIDGETITEM_H
#include "common.h"
#include <QTreeWidgetItem>

class TransTreeWidgetItem : public QObject, public QTreeWidgetItem
{
	Q_OBJECT

public:
	TransTreeWidgetItem(TranslationPlanData &data, QTreeWidgetItem *parent=0);
	~TransTreeWidgetItem();

	void SetData(TranslationPlanData &data){m_data = data;InitItem();}
	void InitItem();
	TranslationPlanData m_data;
private:
	
};

#endif // TRANSTREEWIDGETITEM_H
