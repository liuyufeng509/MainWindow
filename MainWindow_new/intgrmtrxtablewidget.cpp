#include "intgrmtrxtablewidget.h"

IntGrMtrxTableWidget::IntGrMtrxTableWidget(QVector<InterGreenMatrixData> &datas, QWidget *parent)
	: QTableWidget(parent),
	m_intGrMtrxDatas(datas)
{
	setRowCount(m_intGrMtrxDatas.size());
	this->setColumnCount(3);
	QStringList strList;
	strList<<QString::fromLocal8Bit("编号")<<QString::fromLocal8Bit("名称")<<QString::fromLocal8Bit("默认");
	setHorizontalHeaderLabels(strList);
	int width = rect().width();
	setColumnWidth(0, width/6);
	setColumnWidth(1, width/2);
	horizontalHeader()->setStretchLastSection(true);

	updateDataToUI();		//更新数据到界面

	//当表格单元的内容改变时，触发该信号和槽
	connect(this, SIGNAL(cellChanged(int , int )), this, SLOT(dealCellChanged(int ,int )));
	//当备注栏双击后，显示编辑页面
	connect(this, SIGNAL(cellDoubleClicked(int ,int)), this, SLOT(dealCellDoubleClicked(int, int)));

}

void IntGrMtrxTableWidget::updateDataToUI()
{
	setRowCount(0);
	setRowCount(m_intGrMtrxDatas.size());

	for (int i=0;  i<m_intGrMtrxDatas.size(); i++)
	{
		setItem(i, 0, new QTableWidgetItem(QString("%1").arg(m_intGrMtrxDatas[i].nId)));
		setItem(i, 1, new QTableWidgetItem(QString(m_intGrMtrxDatas[i].strName)));
		setItem(i, 2, new QTableWidgetItem(QString(" ")));
		item(i, 2)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//不可编辑
		//item(i, 2)->setBackground(QBrush(QColor(96,96,96)));
	}
}

void IntGrMtrxTableWidget::saveDataFromUI()
{
	for (int i=0; i<rowCount(); i++)
	{
		m_intGrMtrxDatas[i].nId = item(i, 0)->data(Qt::DisplayRole).toInt();
		qstrcpy(m_intGrMtrxDatas[i].strName, item(i,1)->data(Qt::DisplayRole).toString().toStdString().c_str());
	}
}

InterGreenMatrixData IntGrMtrxTableWidget::removeSelectedData()
{
	int row = currentRow();
	if (row!=-1)
	{
		InterGreenMatrixData data = m_intGrMtrxDatas[row];
		m_intGrMtrxDatas.removeAt(row);
		updateDataToUI();
		return data;
	}

}
InterGreenMatrixData IntGrMtrxTableWidget::selectedData()
{
	int row = currentRow();
	if (row!=-1)
	{
		InterGreenMatrixData data = m_intGrMtrxDatas[row];
		return data;
	}
}

void IntGrMtrxTableWidget::dealCellChanged(int row,int column)
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
					m_intGrMtrxDatas[row].nId =nid;
				}else
				{
					item(row,column)->setData(Qt::DisplayRole, m_intGrMtrxDatas[row].nId);
				}
			}
			break;
		case 1:
			qstrcpy(m_intGrMtrxDatas[row].strName, item(row,column)->data(Qt::DisplayRole).toString().toStdString().c_str());
			break;
		default:
			break;
		}
	}
	emit cellChanged(m_intGrMtrxDatas[row]);
}

void IntGrMtrxTableWidget::dealCellDoubleClicked(int row , int column)
{
	if (column == 2 && row!=-1)
	{
		emit CellDoubleClicked(m_intGrMtrxDatas[row]);
	}
}


IntGrMtrxTableWidget::~IntGrMtrxTableWidget()
{

}
