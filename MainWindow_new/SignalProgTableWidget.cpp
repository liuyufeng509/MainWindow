#include "SignalProgTableWidget.h"

SignalProgTableWidget::SignalProgTableWidget(QVector<SignalProgData> &datas,QWidget *parent)
	: QTableWidget(parent),
	m_signalProgs(datas)
{
	setRowCount(m_signalProgs.size());
	setColumnCount(6);
	QStringList strList;
	strList<<QString::fromLocal8Bit("���")<<QString::fromLocal8Bit("����")<<QString::fromLocal8Bit("�̵Ƽ��")
		<<QString::fromLocal8Bit("����ʱ��")<<QString::fromLocal8Bit("ƫ��")<<QString::fromLocal8Bit("�л���");

	setHorizontalHeaderLabels(strList);
	int  width = rect().width();
	setColumnWidth(0, width/10);
	setColumnWidth(1, width/10 *3);
	setColumnWidth(2, width/10 *3);
	setColumnWidth(3, width/10);
	setColumnWidth(4, width/10);
	horizontalHeader()->setStretchLastSection(true);

	updateDataToUI();
   
	//�����Ԫ�����ݸı�ʱ���������źźͲ�
	connect(this, SIGNAL(cellChanged(int , int )), this, SLOT(dealCellChanged(int ,int )));
	//����ע��˫������ʾ�༭ҳ��
	connect(this, SIGNAL(cellDoubleClicked(int ,int)), this, SLOT(dealCellDoubleClicked(int, int)));
}

void SignalProgTableWidget::dealCellChanged(int row, int column)
{
	if (row!=-1 && item(row, column)!=NULL)
	{
		switch (column)
		{
		case 0:
			m_signalProgs[row].nId = item(row, column)->data(Qt::DisplayRole).toInt();
			break;
		case 1:
			qstrcpy(m_signalProgs[row].strName, item(row,column)->data(Qt::DisplayRole).toString().toStdString().c_str());
			break;
		default:
			break;
		}
	}
	emit cellChanged(m_signalProgs[row]);
}

void SignalProgTableWidget::dealCellDoubleClicked(int row , int column)
{
	if (column >= 2 && row!=-1)
	{
		emit CellDoubleClicked(m_signalProgs[row]);
	}
}

void SignalProgTableWidget::saveDataFromUI()
{
	for (int i=0; i<rowCount(); i++)
	{
		m_signalProgs[i].nId = item(i,0)->data(Qt::DisplayRole).toInt();
		qstrcpy(m_signalProgs[i].strName, item(i,1)->data(Qt::DisplayRole).toString().toStdString().c_str());
		m_signalProgs[i].nInterGreens = item(i, 2)->data(Qt::DisplayRole).toInt();
		m_signalProgs[i].nCycleTime = item(i, 3)->data(Qt::DisplayRole).toInt();
		m_signalProgs[i].nOffset = item(i, 4)->data(Qt::DisplayRole).toInt();
		m_signalProgs[i].nSwitchPoint = item(i, 5)->data(Qt::DisplayRole).toInt();
	}
}

SignalProgData SignalProgTableWidget::selectedData()
{
	int row = currentRow();
	if (row!=-1)
	{
		SignalProgData data = m_signalProgs[row];
		return data;
	}
}

SignalProgData SignalProgTableWidget::removeSelectedData()
{
	int row = currentRow();
	if (row!=-1)
	{
		SignalProgData data = m_signalProgs[row];
		m_signalProgs.removeAt(row);
		updateDataToUI();
		return data;
	}else
	{
		SignalProgData data;
		data.nPrimaryId = 0;
		return data;
	}

}

void SignalProgTableWidget::updateDataToUI()
{
	this->setRowCount(0);		//��������м�¼
	this->setRowCount(m_signalProgs.size());
	for (int i=0; i<m_signalProgs.size(); i++)  //��Ӽ�¼
	{
		//insertRow(1);		//1�������
		setItem(i, 0, new QTableWidgetItem(QString("%1").arg(m_signalProgs[i].nId)));
		setItem(i, 1, new QTableWidgetItem(QString(m_signalProgs[i].strName)));
		setItem(i, 2, new QTableWidgetItem(QString("%1").arg(m_signalProgs[i].nInterGreens)));
		setItem(i, 3, new QTableWidgetItem(QString("%1").arg(m_signalProgs[i].nCycleTime)));
		setItem(i, 4, new QTableWidgetItem(QString("%1").arg(m_signalProgs[i].nOffset)));
		setItem(i, 5, new QTableWidgetItem(QString("%1").arg(m_signalProgs[i].nSwitchPoint)));
	}
}

SignalProgTableWidget::~SignalProgTableWidget()
{

}
