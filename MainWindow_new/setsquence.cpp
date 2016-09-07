#include "setsquence.h"
#include "phasecheckbox.h"
#include <QLayout>
#include <QLineEdit>

SetSquence::SetSquence(QVector<SgData>&datas,  QString &squence,QWidget *parent)
	: QDialog(parent),
	m_sgDatas(datas),
	m_squence(squence)
{
	listWid = new ProjectListWidget;
	listWid->clear();

	int rows = m_sgDatas.size()/10;
	int lastNo = m_sgDatas.size()%10;
	if (lastNo>0)
	{
		rows++;
	}

	QStringList list = m_squence.split(";");

	QVBoxLayout *vboxLayout = new QVBoxLayout(this);
	for (int i=0; i<rows-1; i++)
	{
		QHBoxLayout *rowLayout = new QHBoxLayout;
		for (int j=0; j<10; j++)
		{
			PhaseCheckBox *checkBox = new PhaseCheckBox(m_sgDatas[10*i+j].nId);
			if (list.contains(QString::number(m_sgDatas[10*i+j].nId)))
			{
				checkBox->setChecked(true);
				listWid->addItem(QString::number(m_sgDatas[10*i+j].nId));
			}
			rowLayout->addWidget(checkBox);
			connect(checkBox, SIGNAL(checkedWithNo(bool, int)), this, SLOT(ChangeLineEdit(bool, int)));
		}
		vboxLayout->addLayout(rowLayout);
	}

	QHBoxLayout *rowLayout = new QHBoxLayout;
	for (int i=0; i<lastNo; i++)
	{
		PhaseCheckBox *checkBox = new PhaseCheckBox(m_sgDatas[10*(rows-1)+i].nId);
		if (list.contains(QString::number(m_sgDatas[10*(rows-1)+i].nId)))
		{
			checkBox->setChecked(true);
			listWid->addItem(QString::number(m_sgDatas[10*(rows-1)+i].nId));
		}
		rowLayout->addWidget(checkBox);
		connect(checkBox, SIGNAL(checkedWithNo(bool, int)), this, SLOT(ChangeLineEdit(bool, int)));
	}
	vboxLayout->addLayout(rowLayout);

	QHBoxLayout *butnLayout = new QHBoxLayout;
	QPushButton *oKBtn = new QPushButton(QString::fromLocal8Bit("确定"));
	QPushButton *cancelBtn = new QPushButton(QString::fromLocal8Bit("取消"));
	butnLayout->addWidget(oKBtn);
	butnLayout->addWidget(cancelBtn);

	vboxLayout->addWidget(listWid);
	vboxLayout->addLayout(butnLayout);

	connect(oKBtn, SIGNAL(clicked()), this, SLOT(accept()));
	connect(cancelBtn, SIGNAL(clicked()), this, SLOT(reject()));

}

void SetSquence::ChangeLineEdit(bool ischecked, int phaseNo)
{
	if (ischecked)
	{
		//m_squence = m_squence + QString::number(phaseNo) +";";
		listWid->addItem(QString::number(phaseNo));
	}else
	{
		//m_squence.remove(QString::number(phaseNo)+";");
		for (int i=0; i<listWid->count();i++)
		{
			if (listWid->item(i)->text() == QString::number(phaseNo))
			{
				listWid->takeItem(i);
			}
		}
	}
}
void SetSquence::accept()
{
	m_squence = "";
	for (int i=0; i<listWid->count();i++)
	{
		m_squence = m_squence +listWid->item(i)->text()+";";
	}
	QDialog::accept();
}
SetSquence::~SetSquence()
{

}
