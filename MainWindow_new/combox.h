#ifndef COMBOX_H
#define COMBOX_H

#include <QComboBox>

class Combox : public QComboBox
{
	Q_OBJECT

public:
	Combox(int row, QWidget *parent=0);
	~Combox();
public slots:
		void currentIndexChangedSlot(int index);
signals:
		void currentIndexChanged(int ,int );
private:
	int m_row;
};

#endif // COMBOX_H
