#ifndef DETECTORTABLEWIDGET_H
#define DETECTORTABLEWIDGET_H

#include <QTableWidget>
#include "common.h"
//#include "mainwindow.h"

class VirDetectorTableWidget : public QTableWidget
{
	Q_OBJECT

public:
	VirDetectorTableWidget(QWidget *parent=0):QTableWidget(parent){}
	~VirDetectorTableWidget(){};

	virtual void saveDataFromUI(){}			//从界面保存数据
signals:
	void VehCellDoubleClicked(DetectorVehicleData&data);
	void BusCellDoubleClicked(DetectorBusData&data);
	void PedCellDoubleClicked(DetectorsPedestrainsData&data);

	public slots:
	virtual	void updateDataToUI(){}		//更新数据到界面
	virtual  void dealCellDoubleClicked(int, int)=0;
};

template <class T>
class DetectorTableWidget : public VirDetectorTableWidget
{

public:
	DetectorTableWidget(QVector<T> &datas, QVector<DetectorVehicleData> &vehDatas,QVector<DetectorBusData> &busDatas,
		QVector<DetectorsPedestrainsData> &PedDatas, DetectorType type, QWidget *parent=0);
	~DetectorTableWidget();

	void InitUI();
	void saveDataFromUI();				//从界面保存数据
	T removeSelectedData();	//删除选定的行，并返回该行数据
	T selectedData();				//返回选定行的数据

	void updateDataToUI();			//更新数据到界面
	void dealCellDoubleClicked(int, int);
private:
	QVector<T> &m_detectorDatas;
	QVector<DetectorVehicleData> &m_vehDatas;
	QVector<DetectorBusData> &m_busDatas;
	QVector<DetectorsPedestrainsData> &m_PedDatas;
	DetectorType m_type;
};

template <class T> 
void DetectorTableWidget<T>::InitUI()
{
	setRowCount(m_detectorDatas.size());
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
}

template <class T> 
DetectorTableWidget<T>::DetectorTableWidget(QVector<T> &datas,  QVector<DetectorVehicleData> &vehDatas,
											QVector<DetectorBusData> &busDatas,QVector<DetectorsPedestrainsData> &PedDatas,DetectorType type,QWidget *parent)
	: VirDetectorTableWidget(parent),
	m_detectorDatas(datas),
	m_type(type),
	m_vehDatas(vehDatas),
	m_busDatas(busDatas),
	m_PedDatas(PedDatas)
{
	InitUI();
	//当备注栏双击后，显示编辑页面
	connect(this, SIGNAL(cellDoubleClicked(int ,int)), this, SLOT(dealCellDoubleClicked(int, int)));

}

template <class T> 
void DetectorTableWidget<T>::updateDataToUI()
{
	setRowCount(0);
	setRowCount(m_detectorDatas.size());

	for (int i=0;  i<m_detectorDatas.size(); i++)
	{
		setItem(i, 0, new QTableWidgetItem(QString("%1").arg(m_detectorDatas[i].detector.byDetectorNo)));
		setItem(i, 1, new QTableWidgetItem(QString(m_detectorDatas[i].strName)));
		setItem(i, 2, new QTableWidgetItem(QString(" ")));
		item(i, 2)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//不可编辑
		//item(i, 2)->setBackground(QBrush(QColor(96,96,96)));
	}
}

template <class T>
void DetectorTableWidget<T>::dealCellDoubleClicked(int row, int column)
{
	if (row!=-1)
	{
		switch (m_type)
		{
		case Veh:
			{
				emit VehCellDoubleClicked(m_vehDatas[row]);
			}
			break;
		case Bus:
			{
				emit BusCellDoubleClicked(m_busDatas[row]);
			}
			break;
		case Ped:
			{
				emit PedCellDoubleClicked(m_PedDatas[row]);
			}
			break;
		default:
			break;
		}
	}
}

template <class T>
void DetectorTableWidget<T>::saveDataFromUI()
{
	for (int i=0; i<rowCount(); i++)
	{
		m_detectorDatas[i].detector.byDetectorNo = item(i, 0)->data(Qt::DisplayRole).toInt();
		qstrcpy(m_detectorDatas[i].strName, item(i,1)->data(Qt::DisplayRole).toString().toStdString().c_str());
	}
}

template <class T>
T DetectorTableWidget<T>::removeSelectedData()
{
	int row = currentRow();
	if (row!=-1)
	{
		T data = m_detectorDatas[row];
		m_detectorDatas.removeAt(row);
		updateDataToUI();
		return data;
	}
}

template <class T>
T DetectorTableWidget<T>::selectedData()
{
	int row = currentRow();
	if (row!=-1)
	{
		T data = m_detectorDatas[row];
		return data;
	}
}

template <class T> 
DetectorTableWidget<T>::~DetectorTableWidget()
{

}
#endif // DETECTORTABLEWIDGET_H
