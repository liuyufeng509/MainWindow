#include "combox.h"

Combox::Combox(int row,QWidget *parent)
	: QComboBox(parent), m_row(row)
{
	connect(this, SIGNAL(currentIndexChanged(int)), this, SLOT(currentIndexChangedSlot(int)));
}
void Combox::currentIndexChangedSlot(int index)
{
	emit currentIndexChanged(index, m_row);
}
Combox::~Combox()
{

}
