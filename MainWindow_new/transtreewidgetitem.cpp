#include "transtreewidgetitem.h"

TransTreeWidgetItem::TransTreeWidgetItem(TranslationPlanData &data, QTreeWidgetItem *parent)
	: QTreeWidgetItem(parent),
	m_data(data)
{
	InitItem();
}

void TransTreeWidgetItem::InitItem()
{
	//��������ӽڵ�
	QString strName = QString("%1").arg(QString(m_data.strName));
	setText(0, strName);
	setIcon(0, QIcon(":/Tree/translation"));
}

TransTreeWidgetItem::~TransTreeWidgetItem()
{

}
