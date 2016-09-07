#include "detectorwidget.h"

DetectorWidget::DetectorWidget(DetectorType type, QWidget *parent)
	: QWidget(parent),
	m_type(type)
{
	ui.setupUi(this);
	switch (m_type)
	{

	case Veh:
		ui.BusGroupBox->setVisible(false);
		ui.vehGroupBox->setVisible(true);
		break;
	case Bus:
		ui.BusGroupBox->setVisible(true);
		ui.vehGroupBox->setVisible(false);
		break;
	case Ped:
		ui.BusGroupBox->setVisible(false);
		ui.vehGroupBox->setVisible(false);
		break;
	default:
		break;
	}

	ui.phaseTypeComboBox->addItem(QString::fromLocal8Bit("无"));
	ui.phaseTypeComboBox->addItem(QString::fromLocal8Bit("机动车相位"));
	ui.phaseTypeComboBox->addItem(QString::fromLocal8Bit("行人相位"));
	ui.phaseTypeComboBox->addItem(QString::fromLocal8Bit("公交相位"));
	ui.phaseTypeComboBox->addItem(QString::fromLocal8Bit("非机动车相位"));

	ui.phaseTypeComboBox->setCurrentIndex(0);

	pointVec<<ui.vehGroupBox<<ui.presenceCheckBox<<
					ui.frontEndsCheckBox<<ui.rearEndsCheckBox<<
					ui.frontEndTimeCheckBox<<ui.rearEndTimeCheckBox<<
					ui.occupancyRateCheckBox<<ui.occupancyRateSmoothedCheckBox<<
					ui.gapTimeCheckBox<<ui.vehSpeedCheckBox<<
					ui.vehLengthCheckBox<<ui.occupancyTimeCheckBox<<
					ui.BusGroupBox<<ui.telegramsCheckBox<<
					ui.tele_CPCheckBox<<ui.tele_CourseCheckBox<<
					ui.tele_RouteCheckBox<<ui.tele_LengthCheckBox<<
					ui.tele_ManualDCCheckBox<<ui.tele_DelayCheckBox<<
					ui.tele_PassengersCheckBox<<ui.tele_PrioCheckBox<<
					ui.tele_LineCheckBox<<ui.label<<
					ui.nameLineEdit<<ui.label_2<<
					ui.phaseComboBox<<ui.label_3<<
					ui.phaseTypeComboBox<<ui.label_4<<
					ui.isUsedCheckBox;

	QLineEdit *nameLineEdit;
	QLabel *label_2;
	QComboBox *phaseComboBox;
	QLabel *label_3;
	QComboBox *phaseTypeComboBox;
	QLabel *label_4;
	QCheckBox *isUsedCheckBox;

	connect(qApp, SIGNAL(focusChanged( QWidget*, QWidget*)), this, SLOT(foucsChanged(QWidget*, QWidget*)));
}

void DetectorWidget::setData(const DetectorVehicleData &data, const QVector<SgData>  &sgsDatas)
{
	m_vehData = data;
	m_sgsDatas.clear();
	m_sgsDatas = sgsDatas;
	updateDataToUI();
}

void DetectorWidget::setData(const DetectorBusData &data, const QVector<SgData>  &sgsDatas)
{
	m_busData = data;
	m_sgsDatas.clear();
	m_sgsDatas = sgsDatas;
	updateDataToUI();
}

void DetectorWidget::setData(const DetectorsPedestrainsData &data, const QVector<SgData>  &sgsDatas)
{
	m_pedData = data;
	m_sgsDatas.clear();
	m_sgsDatas = sgsDatas;
	updateDataToUI();
}

void DetectorWidget::updateDataToUI()
{
	switch (m_type)
	{
	case Veh:
		{
			ui.nameLineEdit->setText(m_vehData.strName); //设置名称
			ui.phaseComboBox->clear();
			ui.phaseComboBox->addItem(QString::fromLocal8Bit("无"));
			for (int i=0; i<m_sgsDatas.size();i++)
			{
				ui.phaseComboBox->addItem(QString::number(m_sgsDatas[i].nId));
			}
			ui.phaseComboBox->setCurrentText(QString::number(m_vehData.detector.byRequestPhaseNo));
			ui.phaseTypeComboBox->setCurrentIndex(m_vehData.detector.byRequestPhaseType);
			ui.isUsedCheckBox->setChecked(m_vehData.detector.byEnable);
			bitset<16> bs(m_vehData.detector.byParamEnableFlag);
			ui.presenceCheckBox->setChecked(bs[0]);
			ui.frontEndsCheckBox->setChecked(bs[1]);
			ui.rearEndsCheckBox->setChecked(bs[2]);
			ui.frontEndTimeCheckBox->setChecked(bs[3]);
			ui.rearEndTimeCheckBox->setChecked(bs[4]);
			ui.occupancyTimeCheckBox->setChecked(bs[5]);
			ui.occupancyRateCheckBox->setChecked(bs[6]);
			ui.occupancyRateSmoothedCheckBox->setChecked(bs[7]);
			ui.gapTimeCheckBox->setChecked(bs[8]);
			ui.vehSpeedCheckBox->setChecked(bs[9]);
			ui.vehLengthCheckBox->setChecked(bs[10]);
		}
		break;
	case Bus:
		{
			ui.nameLineEdit->setText(m_busData.strName); //设置名称
			ui.phaseComboBox->clear();
			ui.phaseComboBox->addItem(QString::fromLocal8Bit("无"));
			for (int i=0; i<m_sgsDatas.size();i++)
			{
				ui.phaseComboBox->addItem(QString::number(m_sgsDatas[i].nId));
			}
			ui.phaseComboBox->setCurrentText(QString::number(m_busData.detector.byRequestPhaseNo));
			ui.phaseTypeComboBox->setCurrentIndex(m_busData.detector.byRequestPhaseType);
			ui.isUsedCheckBox->setChecked(m_busData.detector.byEnable);
			bitset<16> bs(m_busData.detector.byParamEnableFlag);
			ui.telegramsCheckBox->setChecked(bs[0]);
			ui.tele_CPCheckBox->setChecked(bs[1]);
			ui.tele_LineCheckBox->setChecked(bs[2]);
			ui.tele_CourseCheckBox->setChecked(bs[3]);
			ui.tele_RouteCheckBox->setChecked(bs[4]);
			ui.tele_PrioCheckBox->setChecked(bs[5]);
			ui.tele_LengthCheckBox->setChecked(bs[6]);
			ui.tele_ManualDCCheckBox->setChecked(bs[7]);
			ui.tele_DelayCheckBox->setChecked(bs[8]);
			ui.tele_PassengersCheckBox->setChecked(bs[9]);
		}
		break;
	case Ped:
		{
			ui.nameLineEdit->setText(m_pedData.strName); //设置名称
			ui.phaseComboBox->clear();
			ui.phaseComboBox->addItem(QString::fromLocal8Bit("无"));
			for (int i=0; i<m_sgsDatas.size();i++)
			{
				ui.phaseComboBox->addItem(QString::number(m_sgsDatas[i].nId));
			}
			ui.phaseComboBox->setCurrentText(QString::number(m_pedData.detector.byRequestPhaseNo));
			ui.phaseTypeComboBox->setCurrentIndex(m_pedData.detector.byRequestPhaseType);
			ui.isUsedCheckBox->setChecked(m_pedData.detector.byEnable);
		}
		break;
	default:
		break;
	}
}

void DetectorWidget::saveDataFromUI()
{
	switch (m_type)
	{
	case Veh:
		{
			strcpy(m_vehData.strName, ui.nameLineEdit->text().toStdString().c_str());
			m_vehData.detector.byRequestPhaseNo = ui.phaseComboBox->currentText().toInt();
			
			m_vehData.detector.byRequestPhaseType = ui.phaseTypeComboBox->currentIndex();
			m_vehData.detector.byEnable = ui.isUsedCheckBox->isChecked();

			bitset<16> bs;
			bs.reset();
			bs[0] = ui.presenceCheckBox->isChecked();
			bs[1] = ui.frontEndsCheckBox->isChecked();
			bs[2] = ui.rearEndsCheckBox->isChecked();
			bs[3] = ui.frontEndTimeCheckBox->isChecked();
			bs[4] = ui.rearEndTimeCheckBox->isChecked();
			bs[5] = ui.occupancyTimeCheckBox->isChecked();
			bs[6] = ui.occupancyRateCheckBox->isChecked();
			bs[7] = ui.occupancyRateSmoothedCheckBox->isChecked();
			bs[8] = ui.gapTimeCheckBox->isChecked();
			bs[9] = ui.vehSpeedCheckBox->isChecked();
			bs[10] = ui.vehLengthCheckBox->isChecked();
			m_vehData.detector.byParamEnableFlag = bs.to_ulong();

			emit detectVehDataChanged(m_vehData);
		}
		break;
	case Bus:
		{
			strcpy(m_busData.strName, ui.nameLineEdit->text().toStdString().c_str());
			m_busData.detector.byRequestPhaseNo = ui.phaseComboBox->currentIndex();

			m_busData.detector.byRequestPhaseType = ui.phaseTypeComboBox->currentIndex();
			m_busData.detector.byEnable = ui.isUsedCheckBox->isChecked();
			bitset<16> bs;
			bs.reset();
			bs[0] = ui.telegramsCheckBox->isChecked();
			bs[1] = ui.tele_CPCheckBox->isChecked();
			bs[2] = ui.tele_LineCheckBox->isChecked();
			bs[3] = ui.tele_CourseCheckBox->isChecked();
			bs[4] = ui.tele_RouteCheckBox->isChecked();
			bs[5] = ui.tele_PrioCheckBox->isChecked();
			bs[6] = ui.tele_LengthCheckBox->isChecked();
			bs[7] = ui.tele_ManualDCCheckBox->isChecked();
			bs[8] = ui.tele_DelayCheckBox->isChecked();
			bs[9] = ui.tele_PassengersCheckBox->isChecked();
			m_busData.detector.byParamEnableFlag = bs.to_ulong();
			emit detectBusDataChanged(m_busData);
		}
		break;
	case Ped:
		{
			strcpy(m_pedData.strName, ui.nameLineEdit->text().toStdString().c_str());
			m_pedData.detector.byRequestPhaseNo = ui.phaseComboBox->currentIndex();

			m_pedData.detector.byRequestPhaseType = ui.phaseTypeComboBox->currentIndex();
			m_pedData.detector.byEnable = ui.isUsedCheckBox->isChecked();
			emit detectPedDataChanged(m_pedData);
		}
		break;
	default:
		break;
	}
}

void DetectorWidget::foucsChanged(QWidget*old, QWidget*now)
{
	if (!pointVec.contains(old))
	{
		return;
	}
	saveDataFromUI();

}


DetectorWidget::~DetectorWidget()
{

}
