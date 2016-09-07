#ifndef PHASECHECKBOX_H
#define PHASECHECKBOX_H

#include <QCheckBox>

class PhaseCheckBox : public QCheckBox
{
	Q_OBJECT

public:
	PhaseCheckBox(int phaseNo, QWidget *parent=0);
	~PhaseCheckBox();
	public slots:
		void checkedSlot(bool );

signals:
		void checkedWithNo(bool, int);
private:
	int m_phaseNo;
};

#endif // PHASECHECKBOX_H
