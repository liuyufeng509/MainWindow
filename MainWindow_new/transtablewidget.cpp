#include "transtablewidget.h"

TransTableWidget::TransTableWidget(QVector<TranslationPlanData> &datas, QWidget *parent)
	: QTableWidget(parent),
	m_transDatas(datas)
{
	setRowCount(m_transDatas.size());
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

void TransTableWidget::dealCellDoubleClicked(int row , int column)
{
	if (row!=-1)
	{
		emit CellDoubleClicked(m_transDatas[row]);
	}
}

void TransTableWidget::updateDataToUI()
{
	setRowCount(0);
	setRowCount(m_transDatas.size());

	for (int i=0;  i<m_transDatas.size(); i++)
	{
		setItem(i, 0, new QTableWidgetItem(QString("%1").arg(m_transDatas[i].translationPlan.byTransitionPlanNo)));
		setItem(i, 1, new QTableWidgetItem(QString(m_transDatas[i].strName)));
		setItem(i, 2, new QTableWidgetItem(QString(" ")));
		item(i, 2)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//不可编辑
		//item(i, 2)->setBackground(QBrush(QColor(96,96,96)));
	}
}

void TransTableWidget::saveDataFromUI()
{
	for (int i=0; i<rowCount(); i++)
	{
		m_transDatas[i].translationPlan.byLastPhaseNo= item(i, 0)->data(Qt::DisplayRole).toInt();
		qstrcpy(m_transDatas[i].strName, item(i,1)->data(Qt::DisplayRole).toString().toStdString().c_str());
	}
}

TranslationPlanData TransTableWidget::removeSelectedData()
{
	int row = currentRow();
	if (row!=-1)
	{
		TranslationPlanData data = m_transDatas[row];
		m_transDatas.removeAt(row);
		updateDataToUI();
		return data;
	}
}


TranslationPlanData TransTableWidget::selectedData()
{
	int row = currentRow();
	if (row!=-1)
	{
		TranslationPlanData data = m_transDatas[row];
		return data;
	}
}

TransTableWidget::~TransTableWidget()
{

}
