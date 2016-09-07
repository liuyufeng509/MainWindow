#ifndef MYCOMBOX_H
#define MYCOMBOX_H

#include <QComboBox>
#include "common.h"
class MyComBox : public QComboBox
{
	Q_OBJECT

public:
	MyComBox(/*SgData sgData,*/ SgDataInProg sgDataInProg, int row, QWidget *parent=0);
	~MyComBox();
public slots:
	void currentIndexChangedSlot(int index);
signals:
	void currentIndexChanged(int ,int );
private:
	int m_row;
	SgData  m_sgData;			//��������
	SgDataInProg  m_sgDataInProg;		//�����е��źŵ�����
};

#endif // MYCOMBOX_H
