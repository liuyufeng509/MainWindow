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
	SgData  m_sgData;			//灯组数据
	SgDataInProg  m_sgDataInProg;		//方案中的信号灯数据
};

#endif // MYCOMBOX_H
