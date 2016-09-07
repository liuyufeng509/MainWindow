#include "periodwidget.h"

PeriodWidget::PeriodWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(qApp, SIGNAL(focusChanged( QWidget*, QWidget*)), this, SLOT(foucsChanged(QWidget*, QWidget*)));
	connect(ui.startTimeEdit, SIGNAL(timeChanged(const QTime & )), this, SLOT(setStartTime(const QTime &)));
	connect(ui.endTimeEdit, SIGNAL(timeChanged(const QTime & )), this, SLOT(setEndTime(const QTime &)));
}

void PeriodWidget::setStartTime(const QTime &time)
{
	ui.startTimeLabel->setText(QString::number(time.msecsSinceStartOfDay()/1000));
}

void PeriodWidget::setEndTime(const QTime &time)
{
	ui.endTimeLabel->setText(QString::number(time.msecsSinceStartOfDay()/1000));
}

void PeriodWidget::setData(const PeriodData &data, 
						   const QVector<TranslationPlanData>  &tranPlanDatas, const QVector<SignalProgData>&signalProgs)
{
	m_data = data;
	m_tranPlanDatas.clear();
	m_signalProgs.clear();
	m_tranPlanDatas = tranPlanDatas;
	m_signalProgs = signalProgs;

	updateDataToUI();
}

void PeriodWidget::updateDataToUI()
{
	ui.nameLineEdit->setText(m_data.strName); //设置名称
	ui.startTimeEdit->setTime(QTime::fromMSecsSinceStartOfDay(m_data.period.StartTime*1000));
	ui.endTimeEdit->setTime(QTime::fromMSecsSinceStartOfDay(m_data.period.EndTime*1000));
	ui.planComboBox->clear();
	ui.planComboBox->addItem(QString::fromLocal8Bit("无"));
	for (int i=0; i<m_signalProgs.size();i++)
	{
		ui.planComboBox->addItem(QString::number(m_signalProgs[i].nId));
	}

	ui.planComboBox->setCurrentText(QString::number(m_data.period.byPlanNumber));

	ui.transPlanComboBox->clear();
	ui.transPlanComboBox->addItem(QString::fromLocal8Bit("无"));
	for (int i=0; i<m_tranPlanDatas.size();i++)
	{
		ui.transPlanComboBox->addItem(QString::number(m_tranPlanDatas[i].translationPlan.byTransitionPlanNo));
	}

	ui.transPlanComboBox->setCurrentText(QString::number(m_data.period.byTransPlanNo));

}

void PeriodWidget::saveDataFromUI()
{
	strcpy(m_data.strName, ui.nameLineEdit->text().toStdString().c_str());

	m_data.period.StartTime = ui.startTimeEdit->time().msecsSinceStartOfDay()/1000;
	m_data.period.EndTime = ui.endTimeEdit->time().msecsSinceStartOfDay()/1000;
	
	m_data.period.byPlanNumber = ui.planComboBox->currentIndex();
	m_data.period.byTransPlanNo = ui.transPlanComboBox->currentText().toInt();

	emit PeriodDataChanged(m_data);
}


void PeriodWidget::foucsChanged(QWidget*old, QWidget*now)
{
	if (old!=ui.nameLineEdit && old!=ui.startTimeEdit &&
		old!=ui.endTimeEdit && old!=ui.planComboBox&&
		old!=ui.transPlanComboBox)
	{
		return;
	}
	saveDataFromUI();
}


PeriodWidget::~PeriodWidget()
{

}
