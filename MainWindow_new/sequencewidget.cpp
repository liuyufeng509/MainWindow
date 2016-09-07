#include "sequencewidget.h"
#include "setsquence.h"
SequenceWidget::SequenceWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.nameLineEdit->setEnabled(false);
	connect(qApp, SIGNAL(focusChanged( QWidget*, QWidget*)), this, SLOT(foucsChanged(QWidget*, QWidget*)));
	ui.tableWidget->setRowCount(MAX_RINGS);
	for (int i=0; i<MAX_RINGS; i++)		//���16����
	{
		QTableWidgetItem *item = new QTableWidgetItem(QString(" "));
		ui.tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));
		ui.tableWidget->setItem(i,1,item);
	}
	ui.tableWidget->horizontalHeader()->setStretchLastSection(true);
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget->setSelectionMode ( QAbstractItemView::SingleSelection); //����ѡ��ģʽ��ѡ����
	ui.tableWidget->setEditTriggers ( QAbstractItemView::NoEditTriggers );

	//����ע��˫������ʾ�༭ҳ��
	connect(ui.tableWidget, SIGNAL(cellDoubleClicked(int ,int)), this, SLOT(dealCellDoubleClicked(int, int)));

	QRegExp regExp("[1-9][0-9]{0,9}");//������ʽ����һλΪ1-9�����֣������0-2λ0-9������
	ui.lineEdit_countStage->setValidator(new QRegExpValidator(regExp,this));

}

void SequenceWidget::dealCellDoubleClicked(int row , int column)
{
	if (row!=-1)  //�����Ի�����������
	{
		QString str = ui.tableWidget->item(row, 1)->data(Qt::DisplayRole).toString();
		SetSquence dialog(m_sgsDatas,str, this);
		if(dialog.exec()==QDialog::Accepted)
		{
			ui.tableWidget->item(row,1)->setData(Qt::DisplayRole, str);
		}
		saveDataFromUI();
	}
}

void SequenceWidget::setData(const SquenceData &data, const QVector<SgData>  &sgsDatas)
{
	m_data = data;
	m_sgsDatas.clear();
	m_sgsDatas = sgsDatas;
	
	updateDataToUI();
}

void SequenceWidget::updateDataToUI()
{
	m_data.nId = m_data.squence.no;
	ui.nameLineEdit->setText(m_data.strName); //��������
	ui.lineEdit_countStage->setText(QString::number(m_data.squence.count_stage));
	ui.startPhaseComboBox->clear();
	ui.startPhaseComboBox->addItem(QString::fromLocal8Bit("��"));
	for (int i=0; i<m_sgsDatas.size();i++)
	{
		ui.startPhaseComboBox->addItem(QString::number(m_sgsDatas[i].nId));
	}
	ui.startPhaseComboBox->setCurrentText(QString::number(m_data.squence.byStartPhase));

	//ui.startPhaselineEdit->setText(QString::number(m_data.squence.byStartPhase));
	
	for (int i=0; i<MAX_RINGS; i++)
	{
		QString squenceStr= "";
		for (int j=0; j<MAX_PHASES; j++)
		{
			if (m_data.squence.bySequence[i][j]!=0)
			{
				squenceStr = squenceStr + QString::number(m_data.squence.bySequence[i][j])+ ";";
			}
		}
		ui.tableWidget->item(i,1)->setData(Qt::DisplayRole, squenceStr);
	}
}

void SequenceWidget::saveDataFromUI()
{
	m_data.squence.no = m_data.nId;
	strcpy(m_data.strName, ui.nameLineEdit->text().toStdString().c_str());
	m_data.squence.byStartPhase = ui.startPhaseComboBox->currentText().toInt();
	m_data.squence.count_stage = ui.lineEdit_countStage->text().toInt();
	memset(m_data.squence.bySequence, 0, sizeof(m_data.squence.bySequence));
	for (int i=0; i<MAX_RINGS; i++)
	{
		QString squenceStr= ui.tableWidget->item(i,1)->data(Qt::DisplayRole).toString();
		QStringList strlist = squenceStr.split(";");
		for (int j=0; j<strlist.size(); j++)
		{
			m_data.squence.bySequence[i][j] = strlist[j].toInt();
		}
	}

	emit squenceDataChanged(m_data);
}


void SequenceWidget::foucsChanged(QWidget*old, QWidget*now)
{
	if (old!=ui.nameLineEdit && old!=ui.tableWidget && old!=ui.startPhaseComboBox && old!=ui.lineEdit_countStage)
	{
		return;
	}
 	saveDataFromUI();
 	
}

SequenceWidget::~SequenceWidget()
{

}
