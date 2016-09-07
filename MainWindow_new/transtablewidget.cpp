#include "transtablewidget.h"

TransTableWidget::TransTableWidget(QVector<TranslationPlanData> &datas, QWidget *parent)
	: QTableWidget(parent),
	m_transDatas(datas)
{
	setRowCount(m_transDatas.size());
	this->setColumnCount(3);
	QStringList strList;
	strList<<QString::fromLocal8Bit("���")<<QString::fromLocal8Bit("����")<<QString::fromLocal8Bit("Ĭ��");
	setHorizontalHeaderLabels(strList);
	int width = rect().width();
	setColumnWidth(0, width/6);
	setColumnWidth(1, width/2);
	horizontalHeader()->setStretchLastSection(true);

	updateDataToUI();		//�������ݵ�����

	setSelectionBehavior(QAbstractItemView::SelectRows);
	setSelectionMode ( QAbstractItemView::SingleSelection); //����ѡ��ģʽ��ѡ����
	setEditTriggers ( QAbstractItemView::NoEditTriggers );
	//�����Ԫ�����ݸı�ʱ���������źźͲ�
	//connect(this, SIGNAL(cellChanged(int , int )), this, SLOT(dealCellChanged(int ,int )));
	//����ע��˫������ʾ�༭ҳ��
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
		item(i, 2)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//���ɱ༭
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
