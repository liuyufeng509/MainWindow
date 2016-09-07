#include "phasecheckbox.h"

PhaseCheckBox::PhaseCheckBox(int phaseNo, QWidget *parent)
	: QCheckBox(parent),
	m_phaseNo(phaseNo)
{
	setText(QString::number(m_phaseNo));

	connect(this, SIGNAL(toggled(bool)), this, SLOT(checkedSlot(bool)));
}


void PhaseCheckBox::checkedSlot(bool ischecked)
{
	emit checkedWithNo(ischecked, m_phaseNo);
}

PhaseCheckBox::~PhaseCheckBox()
{

}
