#include "periodtablewidget.h"

PeriodTableWidget::PeriodTableWidget(QVector<PeriodData> &datas, QWidget *parent)
	: QTableWidget(parent),
	m_periodDatas(datas)
{
	setRowCount(m_periodDatas.size());
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


void PeriodTableWidget::updateDataToUI()
{
	setRowCount(0);
	setRowCount(m_periodDatas.size());

	for (int i=0;  i<m_periodDatas.size(); i++)
	{
		setItem(i, 0, new QTableWidgetItem(QString("%1").arg(m_periodDatas[i].nId)));
		setItem(i, 1, new QTableWidgetItem(QString(m_periodDatas[i].strName)));
		setItem(i, 2, new QTableWidgetItem(QString(" ")));
		item(i, 2)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//不可编辑
		//item(i, 2)->setBackground(QBrush(QColor(96,96,96)));
	}
}

void PeriodTableWidget::saveDataFromUI()
{
	for (int i=0; i<rowCount(); i++)
	{
		m_periodDatas[i].nId = item(i, 0)->data(Qt::DisplayRole).toInt();
		qstrcpy(m_periodDatas[i].strName, item(i,1)->data(Qt::DisplayRole).toString().toStdString().c_str());
	}
}

PeriodData PeriodTableWidget::removeSelectedData()
{
	int row = currentRow();
	if (row!=-1)
	{
		PeriodData data = m_periodDatas[row];
		m_periodDatas.removeAt(row);
		updateDataToUI();
		return data;
	}
}

void PeriodTableWidget::dealCellDoubleClicked(int row , int column)
{
	if (row!=-1)
	{
		emit PeriodCellDoubleClicked(m_periodDatas[row]);
	}
}

PeriodData PeriodTableWidget::selectedData()
{
	int row = currentRow();
	if (row!=-1)
	{
		PeriodData data = m_periodDatas[row];
		return data;
	}
}


PeriodTableWidget::~PeriodTableWidget()
{

}
