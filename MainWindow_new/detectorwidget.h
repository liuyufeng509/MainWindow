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
	void detectVehDataChanged(DetectorVehicleData data);					//���޸������ݺ�Ҫ֪ͨ�����ڶԸ�����¼�����޸ġ�
	void detectBusDataChanged(DetectorBusData data);					//���޸������ݺ�Ҫ֪ͨ�����ڶԸ�����¼�����޸ġ�
	void detectPedDataChanged(DetectorsPedestrainsData data);					//���޸������ݺ�Ҫ֪ͨ�����ڶԸ�����¼�����޸ġ�
	
public slots:
		void foucsChanged(QWidget*old, QWidget*now);		//�������ڵĽ��㷢���仯ʱ

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
