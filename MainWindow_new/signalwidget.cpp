#include "signalwidget.h"


SignalWidget::SignalWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.typeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateTableWithSquence(int)));

	connect(qApp, SIGNAL(focusChanged( QWidget*, QWidget*)), this, SLOT(foucsChanged(QWidget*, QWidget*)));
}

void SignalWidget::setData(const SgData &data)
{
	m_data = data;
	updateDataToUI();
}

void SignalWidget::setAllColumnsHidden(bool ishide)
{
	for (int i=0; i<ui.typeTableWidget->colorCount(); i++)
	{
		ui.typeTableWidget->setColumnHidden(i, true);
	}
}

void SignalWidget::updateTableWithSquence(int squence)
{
	int ntype = squence+1;		//����ֵ��ʵ�ʵ�����ֵСһ��
	setAllColumnsHidden(true);//��������
	switch (ntype)
	{
	case COLOR_SEQU_ALL_RED:		//ȫ��
		{
			ui.typeTableWidget->setColumnHidden(Red-1, false);
			ui.typeTableWidget->item(0, Red-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Red-1].nDuration);
		}
		break;
	case COLOR_SEQU_ALL_GREEN:  //ȫ��
		{
			ui.typeTableWidget->setColumnHidden(Green-1, false);
			ui.typeTableWidget->item(0, Green-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Green-1].nDuration);
		}
		break;
	case COLOR_SEQU_RED_REDAMBER_GREEN_AMBER:  //��-���-��-��
		{
			ui.typeTableWidget->setColumnHidden(Red-1, false);
			ui.typeTableWidget->setColumnHidden(Red_Amber-1, false);
			ui.typeTableWidget->setColumnHidden(Green-1, false);
			ui.typeTableWidget->setColumnHidden(Amber-1, false);
			ui.typeTableWidget->item(0, Red-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Red-1].nDuration);
			ui.typeTableWidget->item(0, Red_Amber-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Red_Amber-1].nDuration);
			ui.typeTableWidget->item(0, Green-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Green-1].nDuration);
			ui.typeTableWidget->item(0, Amber-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Amber-1].nDuration);
		}
		break;
	case COLOR_SEQU_RED_GREEN:  //��-��
		{
			ui.typeTableWidget->setColumnHidden(Red-1, false);
			ui.typeTableWidget->setColumnHidden(Green-1, false);
			ui.typeTableWidget->item(0, Red-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Red-1].nDuration);
			ui.typeTableWidget->item(0, Green-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Green-1].nDuration);

		}
		break;
	case COLOR_SEQU_RED_REDAMBER_GREEN_GREENFLASH_AMBER: //��-���-��-����-��
		{
			ui.typeTableWidget->setColumnHidden(Red-1, false);
			ui.typeTableWidget->setColumnHidden(Red_Amber-1, false);
			ui.typeTableWidget->setColumnHidden(Green-1, false);
			ui.typeTableWidget->setColumnHidden(Flash_Green-1, false);
			ui.typeTableWidget->setColumnHidden(Amber-1, false);

			ui.typeTableWidget->item(0, Red-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Red-1].nDuration);
			ui.typeTableWidget->item(0, Red_Amber-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Red_Amber-1].nDuration);
			ui.typeTableWidget->item(0, Green-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Green-1].nDuration);
			ui.typeTableWidget->item(0, Flash_Green-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Flash_Green-1].nDuration);
			ui.typeTableWidget->item(0, Amber-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Amber-1].nDuration);
		}
		break;
	case COLOR_SEQU_RED_GREEN_GREENFLASH://��-��-����
		{
			ui.typeTableWidget->setColumnHidden(Red-1, false);
			ui.typeTableWidget->setColumnHidden(Green-1, false);
			ui.typeTableWidget->setColumnHidden(Flash_Green-1, false);
			ui.typeTableWidget->item(0, Red-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Red-1].nDuration);
			ui.typeTableWidget->item(0, Green-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Green-1].nDuration);
			ui.typeTableWidget->item(0, Flash_Green-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Flash_Green-1].nDuration);
		}
		break;
	case COLOR_SEQU_RED_GREEN_AMBER://��-��-��
		{
			ui.typeTableWidget->setColumnHidden(Red-1, false);
			ui.typeTableWidget->setColumnHidden(Green-1, false);
			ui.typeTableWidget->setColumnHidden(Amber-1, false);
			ui.typeTableWidget->item(0, Red-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Red-1].nDuration);
			ui.typeTableWidget->item(0, Green-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Green-1].nDuration);
			ui.typeTableWidget->item(0, Amber-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Amber-1].nDuration);
		}
		break;
	case COLOR_SEQU_AMBERFLASH:  //����
		{
			ui.typeTableWidget->setColumnHidden(Flash_Amber-1, false);
			ui.typeTableWidget->item(0, Flash_Amber-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Flash_Amber-1].nDuration);
		}
		break;
	case COLOR_SEQU_OFF: //�صƣ��ڵƣ�
		{
			ui.typeTableWidget->setColumnHidden(OFF-1, false);
			ui.typeTableWidget->item(0, OFF-1)->setData(Qt::DisplayRole,m_data.defaultDurations[OFF-1].nDuration);
		}
		break;
	case COLOR_SEQU_RED_OFF://���-�صƣ��ڵƣ�
		{
			ui.typeTableWidget->setColumnHidden(Red-1, false);
			ui.typeTableWidget->setColumnHidden(OFF-1, false);
			ui.typeTableWidget->item(0, Red-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Red-1].nDuration);
			ui.typeTableWidget->item(0, OFF-1)->setData(Qt::DisplayRole,m_data.defaultDurations[OFF-1].nDuration);
		}
		break;
	case COLOR_SEQU_RED_OFF_AMBER://���-�صƣ��ڵƣ�-��
		{
			ui.typeTableWidget->setColumnHidden(Red-1, false);
			ui.typeTableWidget->setColumnHidden(OFF-1, false);
			ui.typeTableWidget->setColumnHidden(Amber-1, false);
			ui.typeTableWidget->item(0, Red-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Red-1].nDuration);
			ui.typeTableWidget->item(0, OFF-1)->setData(Qt::DisplayRole,m_data.defaultDurations[OFF-1].nDuration);
			ui.typeTableWidget->item(0, Amber-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Amber-1].nDuration);
		}
		break;
	case COLOR_SEQU_OFF_GREEN://�صƣ��ڵƣ�-��
		{
			ui.typeTableWidget->setColumnHidden(OFF-1, false);
			ui.typeTableWidget->setColumnHidden(Green-1, false);
			ui.typeTableWidget->item(0, OFF-1)->setData(Qt::DisplayRole,m_data.defaultDurations[OFF-1].nDuration);
			ui.typeTableWidget->item(0, Green-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Green-1].nDuration);
		}
		break;
	case COLOR_SEQU_AMBERFLASH_OFF://����-�صƣ��ڵƣ�
		{
			ui.typeTableWidget->setColumnHidden(Flash_Amber-1, false); 
			ui.typeTableWidget->setColumnHidden(OFF-1, false);
			ui.typeTableWidget->item(0, Flash_Amber-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Flash_Amber-1].nDuration);
			ui.typeTableWidget->item(0, OFF-1)->setData(Qt::DisplayRole,m_data.defaultDurations[OFF-1].nDuration);
		}
		break;
	case COLOR_SEQU_RED_GREEN_REDFLASH://��-��-����
		{
			ui.typeTableWidget->setColumnHidden(Red-1, false); 
			ui.typeTableWidget->setColumnHidden(Green-1, false);
			ui.typeTableWidget->setColumnHidden(Flash_Red-1, false); 
			ui.typeTableWidget->item(0, Red-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Red-1].nDuration);
			ui.typeTableWidget->item(0, Green-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Green-1].nDuration);
			ui.typeTableWidget->item(0, Flash_Red-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Flash_Red-1].nDuration);
		}
		break;
	case COLOR_SEQU_REDFLASH_OFF:
		{
			ui.typeTableWidget->setColumnHidden(Flash_Red-1, false); 
			ui.typeTableWidget->setColumnHidden(OFF-1, false);
			ui.typeTableWidget->item(0, Flash_Red-1)->setData(Qt::DisplayRole,m_data.defaultDurations[Flash_Red-1].nDuration);
			ui.typeTableWidget->item(0, OFF-1)->setData(Qt::DisplayRole,m_data.defaultDurations[OFF-1].nDuration);
		}
		break;

	default:
		break;
	}
}

void SignalWidget::saveDurationWithSquence(int squence)
{
	switch (squence)
	{
	case COLOR_SEQU_ALL_RED:		//ȫ��
		{
			m_data.defaultDurations[Red-1].nDuration = ui.typeTableWidget->item(0, Red-1)->data(Qt::DisplayRole).toInt();
		}
		break;
	case COLOR_SEQU_ALL_GREEN:  //ȫ��
		{
			m_data.defaultDurations[Green-1].nDuration = ui.typeTableWidget->item(0, Green-1)->data(Qt::DisplayRole).toInt();
		}
		break;
	case COLOR_SEQU_RED_REDAMBER_GREEN_AMBER:  //��-���-��-��
		{
			m_data.defaultDurations[Red-1].nDuration = ui.typeTableWidget->item(0, Red-1)->data(Qt::DisplayRole).toInt();
			m_data.defaultDurations[Red_Amber-1].nDuration = ui.typeTableWidget->item(0, Red_Amber-1)->data(Qt::DisplayRole).toInt();
			m_data.defaultDurations[Green-1].nDuration = ui.typeTableWidget->item(0, Green-1)->data(Qt::DisplayRole).toInt();
			m_data.defaultDurations[Amber-1].nDuration = ui.typeTableWidget->item(0, Amber-1)->data(Qt::DisplayRole).toInt();
		}
		break;
	case COLOR_SEQU_RED_GREEN:  //��-��
		{
			m_data.defaultDurations[Red-1].nDuration = ui.typeTableWidget->item(0, Red-1)->data(Qt::DisplayRole).toInt();
			m_data.defaultDurations[Green-1].nDuration = ui.typeTableWidget->item(0, Green-1)->data(Qt::DisplayRole).toInt();
		}
		break;
	case COLOR_SEQU_RED_REDAMBER_GREEN_GREENFLASH_AMBER: //��-���-��-����-��
		{
			m_data.defaultDurations[Red-1].nDuration = ui.typeTableWidget->item(0, Red-1)->data(Qt::DisplayRole).toInt();
			m_data.defaultDurations[Red_Amber-1].nDuration = ui.typeTableWidget->item(0, Red_Amber-1)->data(Qt::DisplayRole).toInt();
			m_data.defaultDurations[Green-1].nDuration = ui.typeTableWidget->item(0, Green-1)->data(Qt::DisplayRole).toInt();
			m_data.defaultDurations[Flash_Green-1].nDuration = ui.typeTableWidget->item(0, Flash_Green-1)->data(Qt::DisplayRole).toInt();
			m_data.defaultDurations[Amber-1].nDuration = ui.typeTableWidget->item(0, Amber-1)->data(Qt::DisplayRole).toInt();
		}
		break;
	case COLOR_SEQU_RED_GREEN_GREENFLASH://��-��-����
		{
			m_data.defaultDurations[Red-1].nDuration = ui.typeTableWidget->item(0, Red-1)->data(Qt::DisplayRole).toInt();
			m_data.defaultDurations[Green-1].nDuration = ui.typeTableWidget->item(0, Green-1)->data(Qt::DisplayRole).toInt();
			m_data.defaultDurations[Flash_Green-1].nDuration = ui.typeTableWidget->item(0, Flash_Green-1)->data(Qt::DisplayRole).toInt();
		}
		break;
	case COLOR_SEQU_RED_GREEN_AMBER://��-��-��
		{
			m_data.defaultDurations[Red-1].nDuration = ui.typeTableWidget->item(0, Red-1)->data(Qt::DisplayRole).toInt();
			m_data.defaultDurations[Green-1].nDuration = ui.typeTableWidget->item(0, Green-1)->data(Qt::DisplayRole).toInt();
			m_data.defaultDurations[Amber-1].nDuration = ui.typeTableWidget->item(0, Amber-1)->data(Qt::DisplayRole).toInt();
		}
		break;
	case COLOR_SEQU_AMBERFLASH:  //����
		{
			m_data.defaultDurations[Flash_Amber-1].nDuration = ui.typeTableWidget->item(0, Flash_Amber-1)->data(Qt::DisplayRole).toInt();
		}
		break;
	case COLOR_SEQU_OFF: //�صƣ��ڵƣ�
		{
			m_data.defaultDurations[OFF-1].nDuration = ui.typeTableWidget->item(0, OFF-1)->data(Qt::DisplayRole).toInt();
		}
		break;
	case COLOR_SEQU_RED_OFF://���-�صƣ��ڵƣ�
		{
			m_data.defaultDurations[Red-1].nDuration = ui.typeTableWidget->item(0, Red-1)->data(Qt::DisplayRole).toInt();
			m_data.defaultDurations[OFF-1].nDuration = ui.typeTableWidget->item(0, OFF-1)->data(Qt::DisplayRole).toInt();
		}
		break;
	case COLOR_SEQU_RED_OFF_AMBER://���-�صƣ��ڵƣ�-��
		{
			m_data.defaultDurations[Red-1].nDuration = ui.typeTableWidget->item(0, Red-1)->data(Qt::DisplayRole).toInt();
			m_data.defaultDurations[OFF-1].nDuration = ui.typeTableWidget->item(0, OFF-1)->data(Qt::DisplayRole).toInt();
			m_data.defaultDurations[Amber-1].nDuration = ui.typeTableWidget->item(0, Amber-1)->data(Qt::DisplayRole).toInt();
		}
		break;
	case COLOR_SEQU_OFF_GREEN://�صƣ��ڵƣ�-��
		{
			m_data.defaultDurations[OFF-1].nDuration = ui.typeTableWidget->item(0, OFF-1)->data(Qt::DisplayRole).toInt();
			m_data.defaultDurations[Green-1].nDuration = ui.typeTableWidget->item(0, Green-1)->data(Qt::DisplayRole).toInt();
		}
		break;
	case COLOR_SEQU_AMBERFLASH_OFF://����-�صƣ��ڵƣ�
		{
			m_data.defaultDurations[Flash_Amber-1].nDuration = ui.typeTableWidget->item(0, Flash_Amber-1)->data(Qt::DisplayRole).toInt();
			m_data.defaultDurations[OFF-1].nDuration = ui.typeTableWidget->item(0, OFF-1)->data(Qt::DisplayRole).toInt();
		}
		break;
	case COLOR_SEQU_RED_GREEN_REDFLASH://��-��-����
		{
			m_data.defaultDurations[Red-1].nDuration = ui.typeTableWidget->item(0, Red-1)->data(Qt::DisplayRole).toInt();
			m_data.defaultDurations[Green-1].nDuration = ui.typeTableWidget->item(0, Green-1)->data(Qt::DisplayRole).toInt();
			m_data.defaultDurations[Flash_Red-1].nDuration = ui.typeTableWidget->item(0, Flash_Red-1)->data(Qt::DisplayRole).toInt();
		}
		break;
	case COLOR_SEQU_REDFLASH_OFF:
		{
			m_data.defaultDurations[Flash_Red-1].nDuration = ui.typeTableWidget->item(0, Flash_Red-1)->data(Qt::DisplayRole).toInt();
			m_data.defaultDurations[OFF-1].nDuration = ui.typeTableWidget->item(0, OFF-1)->data(Qt::DisplayRole).toInt();
		}
		break;

	default:
		break;
	}
}

void SignalWidget::updateDataToUI()
{
	ui.nameLineEdit->setText(QString(m_data.strName));
	ui.typeComboBox->setCurrentIndex(m_data.nDefaultSignalSequence-1);
	ui.bakTextEdit->setPlainText(QString(m_data.strNotes));
	updateTableWithSquence(m_data.nDefaultSignalSequence-1);
}

void SignalWidget::saveDataFromUI()
{
	qstrcpy(m_data.strName, ui.nameLineEdit->text().toStdString().c_str());
	qstrcpy(m_data.strNotes, ui.bakTextEdit->toPlainText().toStdString().c_str());
	m_data.nDefaultSignalSequence = ui.typeComboBox->currentIndex()+1;
	saveDurationWithSquence(m_data.nDefaultSignalSequence);
}

void SignalWidget::foucsChanged(QWidget*old, QWidget*now)
{
	if (old!=ui.nameLineEdit && old!=ui.typeTableWidget&&
		old!=ui.bakTextEdit && old!=ui.typeComboBox)
	{
		return;
	}
	saveDataFromUI();
	emit dataChanged(m_data);
}
SignalWidget::~SignalWidget()
{

}
