#include "sgstablewidget.h"

SgsTableWidget::SgsTableWidget(QVector<SgData>  &sgsDatas,QWidget *parent)
	: QTableWidget(parent),
	m_sgsDatas(sgsDatas)
{
	 this->setRowCount(m_sgsDatas.size());
	 this->setColumnCount(3);
	 QStringList strList;
	 strList<<QString::fromLocal8Bit("���")<<QString::fromLocal8Bit("����")<<QString::fromLocal8Bit("��ע");
	 this->setHorizontalHeaderLabels(strList);

	 int width = rect().width();
	 setColumnWidth(0, width/6);
	 setColumnWidth(1, width/3);
	 horizontalHeader()->setStretchLastSection(true);

	 updateDataToUI();		//���½�������

	 //�����Ԫ�����ݸı�ʱ���������źźͲ�
	 connect(this, SIGNAL(cellChanged(int , int )), this, SLOT(dealCellChanged(int ,int )));
	 //����ע��˫������ʾ�༭ҳ��
	 connect(this, SIGNAL(cellDoubleClicked(int ,int)), this, SLOT(dealCellDoubleClicked(int, int)));
}

void SgsTableWidget::updateDataToUI()
{
	qSort(m_sgsDatas.begin(),m_sgsDatas.end(),sgsDataLessThan);
	
	this->setRowCount(0);		//��������м�¼
	this->setRowCount(m_sgsDatas.size());
	for (int i=0; i<m_sgsDatas.size(); i++)  //��Ӽ�¼
	{
		//insertRow(1);		//1�������
		setItem(i, 0, new QTableWidgetItem(QString("%1").arg(m_sgsDatas[i].nId)));
		setItem(i, 1, new QTableWidgetItem(QString(m_sgsDatas[i].strName)));
		setItem(i, 2, new QTableWidgetItem(QString(m_sgsDatas[i].strNotes)));
		item(i, 2)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//���ɱ༭
	}
}

void SgsTableWidget::saveDataFromUI()
{
	for (int i=0; i<rowCount(); i++)
	{
		m_sgsDatas[i].nId = item(i,0)->data(Qt::DisplayRole).toInt();
		qstrcpy(m_sgsDatas[i].strName, item(i,1)->data(Qt::DisplayRole).toString().toStdString().c_str());
		qstrcpy(m_sgsDatas[i].strNotes, item(i,2)->data(Qt::DisplayRole).toString().toStdString().c_str());
	}
}

SgData SgsTableWidget::removeSelectedData()
{
	int row = currentRow();
	if (row!=-1)
	{
		SgData data = m_sgsDatas[row];
		m_sgsDatas.removeAt(row);		
		updateDataToUI();
		if(row>=0 && row<=rowCount())
			setCurrentCell(row, 0);
		return data;
	}
}

SgData SgsTableWidget::selectedData()
{
	int row = currentRow();
	if (row!=-1)
	{
		SgData data = m_sgsDatas[row];
		return data;
	}
}

void SgsTableWidget::dealCellChanged(int row,int column)
{
	if (row!=-1 && item(row, column)!=NULL)
	{
		switch (column)
		{
		case 0:
			{
				int nid =  item(row, column)->data(Qt::DisplayRole).toInt();
				if (nid>0)
				{
					m_sgsDatas[row].nId =nid;
				}else
				{
					item(row,column)->setData(Qt::DisplayRole, m_sgsDatas[row].nId);
				}
			}
			break;
		case 1:
			qstrcpy(m_sgsDatas[row].strName, item(row,column)->data(Qt::DisplayRole).toString().toStdString().c_str());
			break;
		default:
			break;
		}
	}
	emit cellChanged(m_sgsDatas[row]);
}

void SgsTableWidget::dealCellDoubleClicked(int row , int column)
{
	if (column == 2 && row!=-1)
	{
		emit CellDoubleClicked(m_sgsDatas[row]);
	}
}

SgsTableWidget::~SgsTableWidget()
{

}
