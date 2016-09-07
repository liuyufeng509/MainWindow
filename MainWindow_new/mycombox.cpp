#include "mycombox.h"

MyComBox::MyComBox(/*SgData sgData,*/ SgDataInProg sgDataInProg,int row, QWidget *parent)
	: QComboBox(parent),
	//m_sgData(sgData),
	m_row(row),
	m_sgDataInProg(sgDataInProg)
{
	QIcon icon;
	icon.addFile(QStringLiteral(":/lights/red"), QSize(), QIcon::Normal, QIcon::Off);
	addItem(icon, QString());
	QIcon icon1;
	icon1.addFile(QStringLiteral(":/lights/green"), QSize(), QIcon::Normal, QIcon::Off);
	addItem(icon1, QString());
	QIcon icon2;
	icon2.addFile(QStringLiteral(":/type/red_redamber_green_amber"), QSize(), QIcon::Normal, QIcon::Off);
	addItem(icon2, QString());
	QIcon icon3;
	icon3.addFile(QStringLiteral(":/type/red_green"), QSize(), QIcon::Normal, QIcon::Off);
	addItem(icon3, QString());
	QIcon icon4;
	icon4.addFile(QStringLiteral(":/type/red_redamber_green_flashgreen_amber"), QSize(), QIcon::Normal, QIcon::Off);
	addItem(icon4, QString());
	QIcon icon5;
	icon5.addFile(QStringLiteral(":/type/red_green_flashgreen"), QSize(), QIcon::Normal, QIcon::Off);
	addItem(icon5, QString());
	QIcon icon6;
	icon6.addFile(QStringLiteral(":/type/red_green_amber"), QSize(), QIcon::Normal, QIcon::Off);
	addItem(icon6, QString());
	QIcon icon7;
	icon7.addFile(QStringLiteral(":/lights/flash_amber"), QSize(), QIcon::Normal, QIcon::Off);
	addItem(icon7, QString());
	QIcon icon8;
	icon8.addFile(QStringLiteral(":/lights/off"), QSize(), QIcon::Normal, QIcon::Off);
	addItem(icon8, QString());
	QIcon icon9;
	icon9.addFile(QStringLiteral(":/type/red_off"), QSize(), QIcon::Normal, QIcon::Off);
	addItem(icon9, QString());
	QIcon icon10;
	icon10.addFile(QStringLiteral(":/type/red_off_amber"), QSize(), QIcon::Normal, QIcon::Off);
	addItem(icon10, QString());
	QIcon icon11;
	icon11.addFile(QStringLiteral(":/type/off_green"), QSize(), QIcon::Normal, QIcon::Off);
	addItem(icon11, QString());
	QIcon icon12;
	icon12.addFile(QStringLiteral(":/type/flashamber_off"), QSize(), QIcon::Normal, QIcon::Off);
	addItem(icon12, QString());
	QIcon icon13;
	icon13.addFile(QStringLiteral(":/type/red_green_flashred"), QSize(), QIcon::Normal, QIcon::Off);
	addItem(icon13, QString());
	QIcon icon14;
	icon14.addFile(QStringLiteral(":/type/flashred_off"), QSize(), QIcon::Normal, QIcon::Off);
	addItem(icon14, QString());
	setObjectName(QStringLiteral("typeComboBox"));
	setMaximumSize(QSize(16777215, 16777215));
	setIconSize(QSize(90, 16));

	setCurrentIndex(m_sgDataInProg.nSignalSequence-1);
	connect(this, SIGNAL(currentIndexChanged(int)), this, SLOT(currentIndexChangedSlot(int )));
}

void MyComBox::currentIndexChangedSlot(int index)
{
	emit currentIndexChanged(index, m_row);
}

MyComBox::~MyComBox()
{

}
