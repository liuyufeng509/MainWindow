#include "transwidget.h"

TransWidget::TransWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(qApp, SIGNAL(focusChanged( QWidget*, QWidget*)), this, SLOT(foucsChanged(QWidget*, QWidget*)));

}



void TransWidget::setData(const TranslationPlanData &data, const QVector<SgData>  &sgsDatas)
{
	m_data = data;
	m_sgsDatas.clear();
	m_sgsDatas = sgsDatas;

	updateDataToUI();
}

void TransWidget::updateDataToUI()
{
	ui.nameLineEdit->setText(m_data.strName); //ÉèÖÃÃû³Æ
	
	ui.phaseComboBox->clear();
	ui.phaseComboBox->addItem(QString::fromLocal8Bit("ÎÞ"));
	for (int i=0; i<m_sgsDatas.size();i++)
	{
		ui.phaseComboBox->addItem(QString::number(m_sgsDatas[i].nId));
	}

	ui.phaseComboBox->setCurrentText(QString::number(m_data.translationPlan.byLastPhaseNo));

}

void TransWidget::saveDataFromUI()
{
	strcpy(m_data.strName, ui.nameLineEdit->text().toStdString().c_str());
	m_data.translationPlan.byLastPhaseNo = ui.phaseComboBox->currentText().toInt();

	emit TransDataChanged(m_data);
}


void TransWidget::foucsChanged(QWidget*old, QWidget*now)
{
	if (old!=ui.nameLineEdit && old!=ui.phaseComboBox)
	{
		return;
	}
	saveDataFromUI();
}

TransWidget::~TransWidget()
{

}
