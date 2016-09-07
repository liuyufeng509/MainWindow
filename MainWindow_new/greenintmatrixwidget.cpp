#include "greenintmatrixwidget.h"

GreenIntMatrixWidget::GreenIntMatrixWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(qApp, SIGNAL(focusChanged( QWidget*, QWidget*)), this, SLOT(foucsChanged(QWidget*, QWidget*)));

}


void GreenIntMatrixWidget::setData(const InterGreenMatrixData&data, const QVector<SgData>  &sgsDatas)
{
	m_data = data;
	m_sgsDatas.clear();
	m_sgsDatas = sgsDatas;
	updateDataToUI();
}

void GreenIntMatrixWidget::updateDataToUI()
{
	ui.nameLineEdit->setText(m_data.strName); //设置名称
	map.clear();
	//重置表格行列数和表头
	ui.matrixTableWidget->setRowCount(0);
	ui.matrixTableWidget->setColumnCount(0);
	ui.matrixTableWidget->setRowCount(m_sgsDatas.size());
	ui.matrixTableWidget->setColumnCount(m_sgsDatas.size());
	QStringList strHList, strVList;
	for (int i=0; i<m_sgsDatas.size(); i++)
	{
		strHList<<QString("%1").arg(m_sgsDatas[i].nId);
		strVList<<QString("%1:%2").arg(m_sgsDatas[i].nId).arg(m_sgsDatas[i].strName);
		map.insert(m_sgsDatas[i].nId, i);

		QTableWidgetItem *item = new QTableWidgetItem(QString(" "));
		ui.matrixTableWidget->setItem(i, i, item);
		
		item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//不可编辑
		item->setBackground(QBrush(QColor(96,96,96)));
	}
	ui.matrixTableWidget->setHorizontalHeaderLabels(strHList);
	ui.matrixTableWidget->setVerticalHeaderLabels(strVList);

	//往表格中插入数据
	for (int i=0; i<m_data.interGreens.size();i++)
	{
		if (map.value(m_data.interGreens[i].nClearingSg)!=map.value(m_data.interGreens[i].nEnteringSg))
		{
			QTableWidgetItem *item = NULL;

			if (m_data.interGreens[i].nValue!=-127)
			{
				item = new QTableWidgetItem(QString("%1").arg(m_data.interGreens[i].nValue));
			}else
			{
				item = new QTableWidgetItem(QString(""));
			}
			ui.matrixTableWidget->setItem(map.value(m_data.interGreens[i].nClearingSg), map.value(m_data.interGreens[i].nEnteringSg), item);	
		}
	}
}

void GreenIntMatrixWidget::saveDataFromUI()
{
	strcpy(m_data.strName, ui.nameLineEdit->text().toStdString().c_str());
	for (int i=0; i<m_data.interGreens.size(); i++)
	{
		if (m_data.interGreens[i].nClearingSg!=m_data.interGreens[i].nEnteringSg)
		{
			QString data =  ui.matrixTableWidget->item(map.value(m_data.interGreens[i].nClearingSg), map.value(m_data.interGreens[i].nEnteringSg))->data(Qt::DisplayRole).toString();
			if (data.length()==0)
			{
				m_data.interGreens[i].nValue = -127;
			}else
			{
				m_data.interGreens[i].nValue = data.toInt();
			}
			
		
		}
	}
}


void GreenIntMatrixWidget::foucsChanged(QWidget*old, QWidget*now)
{
	if (old!=ui.nameLineEdit && old!=ui.matrixTableWidget)
	{
		return;
	}
	saveDataFromUI();
	emit dataChanged(m_data);
}

GreenIntMatrixWidget::~GreenIntMatrixWidget()
{

}
