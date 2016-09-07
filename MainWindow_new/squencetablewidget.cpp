#include "squencetablewidget.h"

SquenceTableWidget::SquenceTableWidget(QVector<SquenceData> &datas, QWidget *parent)
	: QTableWidget(parent),
	m_squenceDatas(datas)
{
	setRowCount(m_squenceDatas.size());
	this->setColumnCount(3);
	QStringList strList;
	strList<<QString::fromLocal8Bit("编号")<<QString::fromLocal8Bit("名称")<<QString::fromLocal8Bit("默认");
	setHorizontalHeaderLabels(strList);
	int width = rect().width();
	setColumnWidth(0, width/6);
	setColumnWidth(1, width/2);
	horizontalHeader()->setStretchLastSection(true);

	updateDataToUI();		//更新数据到界面
	setSelectionBehavior(QAbstractItemView::SelectRows);
	setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
	setEditTriggers ( QAbstractItemView::NoEditTriggers );
	//当表格单元的内容改变时，触发该信号和槽
	//connect(this, SIGNAL(cellChanged(int , int )), this, SLOT(dealCellChanged(int ,int )));
	//当备注栏双击后，显示编辑页面
	connect(this, SIGNAL(cellDoubleClicked(int ,int)), this, SLOT(dealCellDoubleClicked(int, int)));
}

void SquenceTableWidget::dealCellDoubleClicked(int row , int column)
{
	if (row!=-1)
	{
		emit CellDoubleClicked(m_squenceDatas[row]);
	}
}

void SquenceTableWidget::updateDataToUI()
{
	setRowCount(0);
	setRowCount(m_squenceDatas.size());

	for (int i=0;  i<m_squenceDatas.size(); i++)
	{
		setItem(i, 0, new QTableWidgetItem(QString("%1").arg(m_squenceDatas[i].nId)));
		setItem(i, 1, new QTableWidgetItem(QString(m_squenceDatas[i].strName)));
		if (m_squenceDatas[i].isConfiged)
		{
			setItem(i, 2, new QTableWidgetItem(QString("√")));
		}else
		{
			setItem(i, 2, new QTableWidgetItem(QString(" ")));
		}
		
		item(i, 2)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//不可编辑
		//item(i, 2)->setBackground(QBrush(QColor(96,96,96)));
	}
}

void SquenceTableWidget::saveDataFromUI()
{
	for (int i=0; i<rowCount(); i++)
	{
		m_squenceDatas[i].nId = item(i, 0)->data(Qt::DisplayRole).toInt();
		qstrcpy(m_squenceDatas[i].strName, item(i,1)->data(Qt::DisplayRole).toString().toStdString().c_str());
	}
}

SquenceData SquenceTableWidget::removeSelectedData()
{
	int row = currentRow();
	if (row!=-1)
	{
		SquenceData data = m_squenceDatas[row];
		m_squenceDatas.removeAt(row);
		updateDataToUI();
		return data;
	}
}


SquenceData SquenceTableWidget::selectedData()
{
	int row = currentRow();
	if (row!=-1)
	{
		SquenceData data = m_squenceDatas[row];
		return data;
	}
}



SquenceTableWidget::~SquenceTableWidget()
{

}
