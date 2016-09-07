#include "scwidget.h"

ScWidget::ScWidget(ScData &data,QWidget *parent)
	: QWidget(parent),
	m_data(data)
{
	ui.setupUi(this);
}

void ScWidget::updateDataToUI()
{
	ui.nameLineEdit->setText(QString::fromLocal8Bit(m_data.strName));
	ui.frenquencySpinBox->setValue(m_data.nFrequency);
	ui.noteTextEdit->setPlainText(QString::fromLocal8Bit(m_data.strNote));
}

void ScWidget::saveDataFromUI()
{
	qstrcpy(m_data.strName, ui.nameLineEdit->text().toStdString().c_str());
	m_data.nFrequency = ui.frenquencySpinBox->value();
	qstrcpy(m_data.strName, ui.noteTextEdit->toPlainText().toStdString().c_str());
}
ScWidget::~ScWidget()
{

}
