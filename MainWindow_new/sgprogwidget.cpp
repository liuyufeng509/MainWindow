#include "sgprogwidget.h"
#include "combox.h"
#define  StandardWidth 60

SgProgWidget::SgProgWidget(QVector<SgData>  &sgsDatas, QVector<InterGreenMatrixData> &interGreenMatrixs, QVector<SquenceData> &squenceDatas,QWidget *parent)
	: QWidget(parent),
	m_sgsDatas(sgsDatas),
	m_interGreenMatrixs(interGreenMatrixs),
	m_squenceDatas(squenceDatas)
{
	ui.setupUi(this);
	ui.sgProgTableWidget->setColumnWidth(SgNo, StandardWidth/2);
	ui.sgProgTableWidget->setColumnWidth(SgName, StandardWidth);
	ui.sgProgTableWidget->setColumnWidth(SgType, StandardWidth*2);
	ui.sgProgTableWidget->setColumnWidth(ISCoorSg, StandardWidth);
	ui.sgProgTableWidget->setColumnWidth(MINGreen, StandardWidth/2);
	ui.sgProgTableWidget->setColumnWidth(MAXGreen1, StandardWidth/2);
	ui.sgProgTableWidget->setColumnWidth(MAXGreen2, StandardWidth/2);
	ui.sgProgTableWidget->setColumnWidth(ExtendGreen, StandardWidth/2);
	ui.sgProgTableWidget->setColumnWidth(SgSequence, StandardWidth*2);
	ui.sgProgTableWidget->setColumnWidth(PicSet, 8*StandardWidth);
	ui.sgProgTableWidget->setColumnWidth(Red1_End, StandardWidth/2);
	ui.sgProgTableWidget->setColumnWidth(RedFlash1_End, StandardWidth/2);
	ui.sgProgTableWidget->setColumnWidth(Green1_End, StandardWidth/2);
	ui.sgProgTableWidget->setColumnWidth(Red2_End, StandardWidth/2);
	ui.sgProgTableWidget->setColumnWidth(RedFlash2_End, StandardWidth/2);
	ui.sgProgTableWidget->setColumnWidth(Green2_End, StandardWidth/2);
	ui.sgProgTableWidget->setColumnWidth(RedAmber, StandardWidth/2);
	ui.sgProgTableWidget->setColumnWidth(AmBer_Column, StandardWidth/2);
	ui.sgProgTableWidget->setColumnWidth(RedFlash_Column, StandardWidth/2);

 	ui.sgProgTableWidget->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
 	ui.sgProgTableWidget->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行

	//控制方式
	ui.ctrlTypeComboBox->addItem(QString::fromLocal8Bit("无"));
	ui.ctrlTypeComboBox->addItem(QString::fromLocal8Bit("黄闪"));
	ui.ctrlTypeComboBox->addItem(QString::fromLocal8Bit("全红"));
	ui.ctrlTypeComboBox->addItem(QString::fromLocal8Bit("关灯"));
	ui.ctrlTypeComboBox->addItem(QString::fromLocal8Bit("步进"));
	ui.ctrlTypeComboBox->addItem(QString::fromLocal8Bit("定周期"));
	ui.ctrlTypeComboBox->addItem(QString::fromLocal8Bit("感应"));
	ui.ctrlTypeComboBox->addItem(QString::fromLocal8Bit("行人过街"));
	ui.ctrlTypeComboBox->addItem(QString::fromLocal8Bit("定时协调"));
	ui.ctrlTypeComboBox->addItem(QString::fromLocal8Bit("感应协调"));
	ui.ctrlTypeComboBox->addItem(QString::fromLocal8Bit("保留方式1"));
	ui.ctrlTypeComboBox->addItem(QString::fromLocal8Bit("保留方式2"));
	ui.ctrlTypeComboBox->addItem(QString::fromLocal8Bit("保留方式3"));
	ui.ctrlTypeComboBox->addItem(QString::fromLocal8Bit("保留方式4"));
	ui.ctrlTypeComboBox->addItem(QString::fromLocal8Bit("保留方式5"));
	ui.ctrlTypeComboBox->addItem(QString::fromLocal8Bit("保留方式6"));

	connect(ui.cycleSpinBox, SIGNAL(valueChanged(int )), this, SLOT(cycleChangedSlot(int )));
	
	connect(qApp, SIGNAL(focusChanged( QWidget*, QWidget*)), this, SLOT(foucsChanged(QWidget*, QWidget*)));	//控件丧失焦点后，保存数据
	
	QRegExp regx("[0-9]+$");
	QValidator *validator = new QRegExpValidator(regx, this);
	ui. countPhaseLineEdit->setValidator( validator ); 
}


void SgProgWidget::cycleChangedSlot(int cycle)
{
	TestSignalLights * paintWidget=NULL;
	for (int i=0; i<ui.sgProgTableWidget->rowCount(); i++)
	{
		paintWidget = static_cast<TestSignalLights*>(ui.sgProgTableWidget->cellWidget(i, PicSet));
		paintWidget->setCycle(cycle);
	}
	if (paintWidget!=NULL)
	{
		saveDataFromeUI();
	}
	
}

void SgProgWidget::setData(const SignalProgData &data)
{
	m_data = data;
	updateDataToUI();
}

void SgProgWidget::setLightsData(int row, bool isNew)
{
	if (row!=-1)
	{
		if (isNew)
		{
			ui.sgProgTableWidget->setItem(row,Red1_End,  new QTableWidgetItem(QString(" ")));
			ui.sgProgTableWidget->setItem(row,RedFlash1_End,  new QTableWidgetItem(QString(" ")));
			ui.sgProgTableWidget->setItem(row,Green1_End,  new QTableWidgetItem(QString(" ")));
			ui.sgProgTableWidget->setItem(row,Red2_End,  new QTableWidgetItem(QString(" ")));
			ui.sgProgTableWidget->setItem(row,RedFlash2_End,  new QTableWidgetItem(QString(" ")));
			ui.sgProgTableWidget->setItem(row,Green2_End,  new QTableWidgetItem(QString(" ")));
			ui.sgProgTableWidget->setItem(row,RedAmber,  new QTableWidgetItem(QString(" ")));
			ui.sgProgTableWidget->setItem(row,AmBer_Column,  new QTableWidgetItem(QString(" ")));
			ui.sgProgTableWidget->setItem(row,RedFlash_Column,  new QTableWidgetItem(QString(" ")));
		}
		else
		{
			ui.sgProgTableWidget->item(row,Red1_End)->setData(Qt::DisplayRole, QString(" "));
			ui.sgProgTableWidget->item(row, RedFlash1_End)->setData(Qt::DisplayRole, QString(" "));
			ui.sgProgTableWidget->item(row, Green1_End)->setData(Qt::DisplayRole, QString(" "));
			ui.sgProgTableWidget->item(row, RedAmber)->setData(Qt::DisplayRole, QString(" "));
			ui.sgProgTableWidget->item(row, AmBer_Column)->setData(Qt::DisplayRole, QString(" "));
			ui.sgProgTableWidget->item(row, RedFlash_Column)->setData(Qt::DisplayRole, QString(" "));
		}
		
		ui.sgProgTableWidget->item(row,Red1_End)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
		ui.sgProgTableWidget->item(row, RedFlash1_End)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
		ui.sgProgTableWidget->item(row, Green1_End)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);	
		ui.sgProgTableWidget->item(row, Red2_End)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
		ui.sgProgTableWidget->item(row, RedFlash2_End)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
		ui.sgProgTableWidget->item(row, Green2_End)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);	
		ui.sgProgTableWidget->item(row, RedAmber)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
		ui.sgProgTableWidget->item(row, AmBer_Column)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
		ui.sgProgTableWidget->item(row, RedFlash_Column)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
		Qt::ItemFlags flags = Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled;
		MyComBox * combox = static_cast<MyComBox *>(ui.sgProgTableWidget->cellWidget(row, SgSequence));
		TestSignalLights * paintWidget = static_cast<TestSignalLights *>(ui.sgProgTableWidget->cellWidget(row, PicSet));
		int squence = combox->currentIndex()+1;

		switch (squence)
		{
		case COLOR_SEQU_ALL_RED:
		case COLOR_SEQU_RED_OFF:
			{
				if(squence==COLOR_SEQU_ALL_RED)
					ui.sgProgTableWidget->item(row,Red1_End)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);	
				else
					ui.sgProgTableWidget->item(row,Red1_End)->setFlags(flags);	

				ui.sgProgTableWidget->item(row,Red1_End)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->getRedLineEnd()));
			}
			break;
		case COLOR_SEQU_ALL_GREEN:
		case COLOR_SEQU_OFF_GREEN:
			{
				if(squence==COLOR_SEQU_ALL_RED)
					ui.sgProgTableWidget->item(row, Green1_End)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);	
				else
					ui.sgProgTableWidget->item(row, Green1_End)->setFlags(flags);	

				ui.sgProgTableWidget->item(row, Green1_End)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->getGreenEnd()));
			}
			break;
		case COLOR_SEQU_RED_REDAMBER_GREEN_AMBER:
		case COLOR_SEQU_RED_REDAMBER_GREEN_GREENFLASH_AMBER:
			{
				ui.sgProgTableWidget->item(row,Red1_End)->setFlags(flags);	
				ui.sgProgTableWidget->item(row,Red1_End)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->getRedLineEnd()));
				ui.sgProgTableWidget->item(row, Green1_End)->setFlags(flags);	
				ui.sgProgTableWidget->item(row, Green1_End)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->getGreenEnd()));
				ui.sgProgTableWidget->item(row, RedAmber)->setFlags(flags);	
				ui.sgProgTableWidget->item(row, RedAmber)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->getRedAmberFixedState()));
				ui.sgProgTableWidget->item(row, AmBer_Column)->setFlags(flags);	
				ui.sgProgTableWidget->item(row, AmBer_Column)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->getAmberFixedState()));
			}
			break;
		case COLOR_SEQU_RED_GREEN:
		case COLOR_SEQU_RED_GREEN_GREENFLASH:
			{
				ui.sgProgTableWidget->item(row,Red1_End)->setFlags(flags);	
				ui.sgProgTableWidget->item(row,Red1_End)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->getRedLineEnd()));
				ui.sgProgTableWidget->item(row, Green1_End)->setFlags(flags);	
				ui.sgProgTableWidget->item(row, Green1_End)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->getGreenEnd()));
			}
			break;

		case COLOR_SEQU_RED_GREEN_AMBER:
			{
				ui.sgProgTableWidget->item(row,Red1_End)->setFlags(flags);	
				ui.sgProgTableWidget->item(row,Red1_End)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->getRedLineEnd()));
				ui.sgProgTableWidget->item(row, Green1_End)->setFlags(flags);	
				ui.sgProgTableWidget->item(row, Green1_End)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->getGreenEnd()));
				ui.sgProgTableWidget->item(row, AmBer_Column)->setFlags(flags);	
				ui.sgProgTableWidget->item(row, AmBer_Column)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->getAmberFixedState()));
			}
			break;
		case COLOR_SEQU_RED_OFF_AMBER:
			{
				ui.sgProgTableWidget->item(row,Red1_End)->setFlags(flags);	
				ui.sgProgTableWidget->item(row,Red1_End)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->getRedLineEnd()));
				ui.sgProgTableWidget->item(row, AmBer_Column)->setFlags(flags);	
				ui.sgProgTableWidget->item(row, AmBer_Column)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->getAmberFixedState()));
			}
			break;
		case COLOR_SEQU_RED_GREEN_REDFLASH:
			{
				ui.sgProgTableWidget->item(row,Red1_End)->setFlags(flags);	
				ui.sgProgTableWidget->item(row,Red1_End)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->getRedLineEnd()));
				ui.sgProgTableWidget->item(row, Green1_End)->setFlags(flags);	
				ui.sgProgTableWidget->item(row, Green1_End)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->getGreenEnd()));
				ui.sgProgTableWidget->item(row, RedFlash_Column)->setFlags(flags);	
				ui.sgProgTableWidget->item(row, RedFlash_Column)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->getRedFlashFixedState()));
			}
			break;
		case COLOR_SEQU_REDFLASH_OFF:
			{
				ui.sgProgTableWidget->item(row, RedFlash1_End)->setFlags(flags);	
				ui.sgProgTableWidget->item(row, RedFlash1_End)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->getFlashRedEnd()));
			}
			break;
		case COLOR_SEQU_AMBERFLASH:
		case COLOR_SEQU_OFF:
		case COLOR_SEQU_AMBERFLASH_OFF:
			break;
		default:
			break;
		}

	}
}

void SgProgWidget::currentIndexChangedSlot(int  index, int row)
{
//	int row = ui.sgProgTableWidget->currentRow();
	TestSignalLights *paintWidget = static_cast<TestSignalLights*>(ui.sgProgTableWidget->cellWidget(row, PicSet));
	if(paintWidget!=NULL)
	paintWidget->comboxChanged(index);
	setLightsData(row);		//当选项更改后，设置除图形外的其他列。图形列已经使用信号槽进行了处理。
	if (row!=-1)
	{
		saveDataFromeUI();
	}
}
void SgProgWidget::cellChangedSlot(int row, int column, int preRow, int preColum)
{
	if (preColum!=Red1_End&&preColum!=RedFlash1_End&&preColum!=Green1_End&&
		preColum!=RedAmber&&preColum!=AmBer_Column&&preColum!=RedFlash_Column&&
		preColum!=MINGreen&&preColum!=MAXGreen1&&preColum!=MAXGreen2&&
		preColum!=ExtendGreen)
	{
		return;
	}
	TestSignalLights * paintWidget = static_cast<TestSignalLights*>(ui.sgProgTableWidget->cellWidget(row, PicSet));
	if(paintWidget==NULL)
		return;
	//MyComBox * combox = static_cast<MyComBox*> (ui.sgProgTableWidget->cellWidget(row,SgSequence));
	if (preColum==Red1_End)		//红变
	{
		int red_end= ui.sgProgTableWidget->item(preRow, preColum)->data(Qt::DisplayRole).toInt();
		paintWidget->setRedLineEnd(red_end);
	}
	if (preColum==RedFlash1_End)		//
	{
		int red_flash_end= ui.sgProgTableWidget->item(preRow, preColum)->data(Qt::DisplayRole).toInt();
		paintWidget->setFlashRedEnd(red_flash_end);
	}
	if (preColum==Green1_End)		//
	{
		int green_end= ui.sgProgTableWidget->item(preRow, preColum)->data(Qt::DisplayRole).toInt();
		paintWidget->setGreenEnd(green_end);
	}
	if (preColum==RedAmber)		//
	{
		int red_amber= ui.sgProgTableWidget->item(preRow, preColum)->data(Qt::DisplayRole).toInt();
		paintWidget->setRedAmberFixedState(red_amber);
	}
	if (preColum==AmBer_Column)		//
	{
		int amber= ui.sgProgTableWidget->item(preRow, preColum)->data(Qt::DisplayRole).toInt();
		paintWidget->setAmberFixedState(amber);
	}
	if (preColum==RedFlash_Column)		//
	{
		int flash_red= ui.sgProgTableWidget->item(preRow, preColum)->data(Qt::DisplayRole).toInt();
		paintWidget->setRedFlashFixedState(flash_red);
	}

	saveDataFromeUI();
}

void SgProgWidget::updateDataToUI()
{
	ui.nameLineEdit->setText(m_data.strName);
	ui.comboBox->clear();
	ui.comboBox->addItem(QString::fromLocal8Bit("无"));
	int index = 0;
	for (int i=0; i<m_interGreenMatrixs.size(); i++)
	{
		ui.comboBox->addItem(m_interGreenMatrixs[i].strName);
		if (m_data.nInterGreens == m_interGreenMatrixs[i].nId)
		{
			index = i+1;
		}
	}
	ui.comboBox->setCurrentIndex(index);

	ui.ctrlTypeComboBox->setCurrentIndex(m_data.ctrlType);
	ui.countPhaseLineEdit->setText(QString::number(m_data.countPhase));
	ui.startPhaseComboBox->clear();
	ui.startPhaseComboBox->addItem(QString::fromLocal8Bit("无"));
	for (int i=0; i<m_sgsDatas.size();i++)
	{
		ui.startPhaseComboBox->addItem(QString::number(m_sgsDatas[i].nId));
	}
	ui.startPhaseComboBox->setCurrentText(QString::number(m_data.startPhase));

	ui.comboBox_squence->clear();
	ui.comboBox_squence->addItem(QString::fromLocal8Bit("无"));
	for (int i=0; i<m_squenceDatas.size(); i++)
	{
		ui.comboBox_squence->addItem(QString::number(m_squenceDatas[i].nId));
	}
	ui.comboBox_squence->setCurrentText(QString::number(m_data.nSequenceNo));

	//ui.startPhaseLineEdit->setText(QString::number(m_data.startPhase));

	//重置表格行数和表头
	ui.sgProgTableWidget->setRowCount(0);
	ui.sgProgTableWidget->setRowCount(m_sgsDatas.size());
	for (int i=0; i<m_sgsDatas.size(); i++)
	{
		ui.sgProgTableWidget->setItem(i, SgNo, new QTableWidgetItem(QString("%1").arg(m_sgsDatas[i].nId)));
		ui.sgProgTableWidget->setItem(i, SgName, new QTableWidgetItem(QString(m_sgsDatas[i].strName)));
 		ui.sgProgTableWidget->item(i,SgNo)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
 		ui.sgProgTableWidget->item(i,SgName)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
		
		SgDataInProg data;
		for (int j=0; j<m_data.sgDatasInProg.size(); j++)
		{
			if (m_data.sgDatasInProg[j].nSgId == m_sgsDatas[i].nId)
			{
				data = m_data.sgDatasInProg[j];
			}
		}
		Combox *typeCombox = new Combox(i);
		typeCombox->addItem(QString::fromLocal8Bit("无定义"));
		typeCombox->addItem(QString::fromLocal8Bit("机动车相位"));
		typeCombox->addItem(QString::fromLocal8Bit("行人相位"));
		typeCombox->addItem(QString::fromLocal8Bit("公交相位"));
		typeCombox->addItem(QString::fromLocal8Bit("非机动车相位"));
		typeCombox->setCurrentIndex(data.nPhaseType);
		ui.sgProgTableWidget->setItem(i, SgType, new QTableWidgetItem(QString(" ")));
		ui.sgProgTableWidget->setCellWidget(i,SgType, typeCombox);

		Combox* coorSgCombox = new Combox(i);
		coorSgCombox->addItem(QString::fromLocal8Bit("否"));
		coorSgCombox->addItem(QString::fromLocal8Bit("是"));
		coorSgCombox->setCurrentIndex(data.byIsCoordinate);
		ui.sgProgTableWidget->setItem(i, ISCoorSg, new QTableWidgetItem(QString(" ")));
		ui.sgProgTableWidget->setCellWidget(i,ISCoorSg, coorSgCombox);

		ui.sgProgTableWidget->setItem(i, MINGreen, new QTableWidgetItem(QString("%1").arg(data.byMinGreenTime)));
		ui.sgProgTableWidget->setItem(i, MAXGreen1, new QTableWidgetItem(QString("%1").arg(data.byMax1GreenTime)));
		ui.sgProgTableWidget->setItem(i, MAXGreen2, new QTableWidgetItem(QString("%1").arg(data.byMax2GreenTime)));
		ui.sgProgTableWidget->setItem(i, ExtendGreen, new QTableWidgetItem(QString("%1").arg(data.byGreenTimeExtendEachTime)));

		ui.sgProgTableWidget->setItem(i, SgSequence, new QTableWidgetItem(QString(" ")));


		MyComBox *combox = new MyComBox( data, i);
		ui.sgProgTableWidget->setCellWidget(i,SgSequence, combox);

		ui.sgProgTableWidget->setItem(i, PicSet, new QTableWidgetItem(QString(" ")));
		
		TestSignalLights * paintWidget = new TestSignalLights(data,i, m_data.nCycleTime);		//当前的信号灯数据
		ui.sgProgTableWidget->setCellWidget(i,PicSet,paintWidget);

		connect(combox, SIGNAL(currentIndexChanged(int , int)), this, SLOT(currentIndexChangedSlot(int, int)));			//下拉框影响颜色数据列
		connect(typeCombox, SIGNAL(currentIndexChanged(int, int)), this, SLOT(sgTypeOrCoordChanged(int, int)));
		connect(coorSgCombox, SIGNAL(currentIndexChanged(int, int)), this, SLOT(sgTypeOrCoordChanged(int, int)));
		connect(paintWidget, SIGNAL(emitPaintChanged(int, int)), this, SLOT(paintChangedSlot(int, int)));
		setLightsData(i, true);
		connect(ui.sgProgTableWidget, SIGNAL(currentCellChanged(int, int, int, int)), this, SLOT(cellChangedSlot(int, int, int, int)));			//处理最后几列内容改变
	}
	
	ui.cycleSpinBox->setValue(m_data.nCycleTime);
	ui.offSetSpinBox->setValue(m_data.nOffset);
	ui.switchPointSpinBox->setValue(m_data.nSwitchPoint);
	//设置行宽
	for (int i=0; i<m_sgsDatas.size(); i++)
	{
		ui.sgProgTableWidget->setRowHeight(i, StandardWidth*2);
	}
}

void SgProgWidget::sgTypeOrCoordChanged(int index, int row)
{
	if (row!=-1)
	{
		saveDataFromeUI();
	}
}

void SgProgWidget::paintChangedSlot(int squence, int row)
{
	TestSignalLights* paintWidget = static_cast<TestSignalLights*>(ui.sgProgTableWidget->cellWidget(row, PicSet));
	ui.sgProgTableWidget->setCurrentCell(row, 0);
	if (row!=-1)
	{
		switch (squence)
		{
		case COLOR_SEQU_RED_REDAMBER_GREEN_AMBER:
		case COLOR_SEQU_RED_GREEN:
		case COLOR_SEQU_RED_REDAMBER_GREEN_GREENFLASH_AMBER:
		case COLOR_SEQU_RED_GREEN_GREENFLASH:
		case COLOR_SEQU_RED_GREEN_AMBER:
		case COLOR_SEQU_RED_GREEN_REDFLASH:
			{
				ui.sgProgTableWidget->item(row,Red1_End)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->red_line->getEScale()));
				ui.sgProgTableWidget->item(row, Green1_End)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->green_rect->getEScale()));
			}
			break;
		case COLOR_SEQU_RED_OFF:
		case COLOR_SEQU_RED_OFF_AMBER:
			{
				ui.sgProgTableWidget->item(row,Red1_End)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->red_line->getEScale()));
			}
			break;
		case COLOR_SEQU_OFF_GREEN:
			{
				ui.sgProgTableWidget->item(row, Green1_End)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->green_rect->getEScale()));
			}
			break;
		case COLOR_SEQU_REDFLASH_OFF:
			ui.sgProgTableWidget->item(row, RedFlash1_End)->setData(Qt::DisplayRole, QString("%1").arg(paintWidget->flash_red_rect->getEScale()));
			break;
		default:
			break;
		}


		saveDataFromeUI();
	}
}

void SgProgWidget::saveDataFromeUI()
{
	qstrcpy(m_data.strName, ui.nameLineEdit->text().toStdString().c_str());
	int index = ui.comboBox->currentIndex();
	if (index>0)
	{
		m_data.nInterGreens = m_interGreenMatrixs[index-1].nId;
	}
	m_data.nCycleTime = ui.cycleSpinBox->value();
	m_data.nOffset = ui.offSetSpinBox->value();
	m_data.nSwitchPoint = ui.switchPointSpinBox->value();

	m_data.ctrlType = ui.ctrlTypeComboBox->currentIndex();
	m_data.countPhase = ui.countPhaseLineEdit->text().toInt();
//	m_data.startPhase = ui.startPhaseLineEdit->text().toInt();
	m_data.startPhase = ui.startPhaseComboBox->currentText().toInt();
	m_data.nSequenceNo = ui.comboBox_squence->currentText().toInt();
	for (int i=0; i<ui.sgProgTableWidget->rowCount(); i++)
	{
		TestSignalLights *paintWidget = static_cast<TestSignalLights*>(ui.sgProgTableWidget->cellWidget(i, PicSet));
		SgDataInProg data;
		data = paintWidget->getData();

		MyComBox *combox = static_cast<MyComBox*>(ui.sgProgTableWidget->cellWidget(i,SgSequence));
		data.nSignalSequence = combox->currentIndex()+1;
		QComboBox *typeCombox = static_cast<QComboBox*>(ui.sgProgTableWidget->cellWidget(i, SgType));
		data.nPhaseType = typeCombox->currentIndex();
		QComboBox *coordCombox = static_cast<QComboBox*>(ui.sgProgTableWidget->cellWidget(i, ISCoorSg));
		data.byIsCoordinate = coordCombox->currentIndex();
		data.byMinGreenTime = ui.sgProgTableWidget->item(i, MINGreen)->data(Qt::DisplayRole).toInt();
		data.byMax1GreenTime = ui.sgProgTableWidget->item(i, MAXGreen1)->data(Qt::DisplayRole).toInt();
		data.byMax2GreenTime = ui.sgProgTableWidget->item(i, MAXGreen2)->data(Qt::DisplayRole).toInt();
		data.byGreenTimeExtendEachTime = ui.sgProgTableWidget->item(i, ExtendGreen)->data(Qt::DisplayRole).toInt();
		for (int j=0; j<m_data.sgDatasInProg.size(); j++)
		{
			if(m_data.sgDatasInProg[j].nSgId == m_sgsDatas[i].nId)
			{
				m_data.sgDatasInProg[j] = data;
			}
		}
	}

	emit sgProgDataChanged(m_data);
}

void SgProgWidget::foucsChanged(QWidget*old, QWidget*now)
{
	if (old!=ui.nameLineEdit && old!=ui.countPhaseLineEdit && old!=ui.startPhaseComboBox
		&&old!=ui.ctrlTypeComboBox && old!=ui.comboBox && old!=ui.comboBox_squence
		&&old!=ui.cycleSpinBox && old!=ui.offSetSpinBox && old!=ui.switchPointSpinBox)
	{
		return;
	}
	saveDataFromeUI();

}


SgProgWidget::~SgProgWidget()
{

}
