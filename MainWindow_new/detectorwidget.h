#ifndef DETECTORWIDGET_H
#define DETECTORWIDGET_H

#include <QWidget>
#include "ui_detectorwidget.h"
#include "common.h"
#include <QTreeWidgetItem>
#include <bitset>
using namespace std;
class DetectorWidget : public QWidget
{
	Q_OBJECT

public:
	DetectorWidget(DetectorType type, QWidget *parent = 0);
	~DetectorWidget();
	void setData(const DetectorVehicleData &data, const QVector<SgData>  &sgsDatas );
	void setData(const DetectorBusData &data, const QVector<SgData>  &sgsDatas );
	void setData(const DetectorsPedestrainsData &data, const QVector<SgData>  &sgsDatas );
	void updateDataToUI();
	void saveDataFromUI();

	
signals:
	void detectVehDataChanged(DetectorVehicleData data);					//当修改了内容后，要通知主窗口对该条记录进行修改。
	void detectBusDataChanged(DetectorBusData data);					//当修改了内容后，要通知主窗口对该条记录进行修改。
	void detectPedDataChanged(DetectorsPedestrainsData data);					//当修改了内容后，要通知主窗口对该条记录进行修改。
	
public slots:
		void foucsChanged(QWidget*old, QWidget*now);		//当窗口内的焦点发生变化时

private:
	Ui::DetectorWidget ui;

	DetectorVehicleData m_vehData;
	DetectorBusData m_busData;
	DetectorsPedestrainsData m_pedData;

	QVector<SgData>m_sgsDatas;

	DetectorType m_type;

	QList<QWidget*> pointVec;
};

#endif // DETECTORWIDGET_H
