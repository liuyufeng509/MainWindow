#include "treewidget.h"
#include <QDebug>
#include <QMessageBox>
QMap<int ,int >	m_sgColorToDefdur;							//��¼��ɫ��Ĭ����Сʱ����ӳ�䡣
int defaultCycle = 60;
bool intGrTreeItemLessThan(const IntGreenTreeWidgetItem *item1, const IntGreenTreeWidgetItem *item2)
{
	return item1->m_data.nId <item2->m_data.nId;
}

bool sgProgTreeItemLessThan(const SgProgTreeWidgetItem*item1, const SgProgTreeWidgetItem*item2)
{
	return item1->m_data.nId <item2->m_data.nId;
}

bool squenceTreeItemLessThan(const SquenceTreeWidgetItem*item1, const SquenceTreeWidgetItem*item2)
{
	return item1->m_data.nId <item2->m_data.nId;
}

bool detectVehTreeItemLessThan(const DetectorVehicleTreeWidgetItem*item1, const DetectorVehicleTreeWidgetItem*item2)
{
	return item1->m_data.detector.byDetectorNo <item2->m_data.detector.byDetectorNo;
}

bool detectBusTreeItemLessThan(const DetectorBusTreeWidgetItem*item1, const DetectorBusTreeWidgetItem*item2)
{
	return item1->m_data.detector.byDetectorNo <item2->m_data.detector.byDetectorNo;
}

bool detectPedTreeItemLessThan(const DetectorPedTreeWdigetItem*item1, const DetectorPedTreeWdigetItem*item2)
{
	return item1->m_data.detector.byDetectorNo <item2->m_data.detector.byDetectorNo;
}

bool transTreeItemLessThan(const TransTreeWidgetItem*item1, const TransTreeWidgetItem*item2)
{
	return item1->m_data.translationPlan.byTransitionPlanNo <item2->m_data.translationPlan.byTransitionPlanNo;
}

bool periodTreeItemLessThan(const PeriodTreeWidgetItem*item1, const PeriodTreeWidgetItem*item2)
{
	return item1->m_data.nId <item2->m_data.nId;
}

bool sgTreeItemLessThan(const SgTreeWidgetItem*item1, const SgTreeWidgetItem*item2)
{
	return item1->m_data.nId <item2->m_data.nId;
}

bool insensitiveLessThan(const InterGreen &data1, const InterGreen &data2) 
{ 
	if (data1.nClearingSg<data2.nClearingSg)
	{
		return true;
	}else if (data1.nClearingSg == data2.nClearingSg)
	{
		if (data1.nEnteringSg< data2.nEnteringSg)
		{
			return true;
		}else
		{
			return false;
		}
	}else
	{
		return false;
	}
}

TreeWidget::TreeWidget(QVector<SgData>  &sgsDatas,ScData &scData, QVector<InterGreenMatrixData> &interGreenMatrixs,
					   QVector<SignalProgData> &signalProgs,QVector<SquenceData> &squenceDatas,QVector<DetectorVehicleData> &detectorVehicleDatas,
					   QVector<DetectorBusData> &detectorBusDatas,QVector<DetectorsPedestrainsData> &detectorPedestainsDatas,
					   QVector<TranslationPlanData>	&translationDatas,QVector<PeriodData>	&periodDatas,QWidget *parent)
	: QTreeWidget(parent),
	m_sgsDatas(sgsDatas),
	m_interGreenMatrixs(interGreenMatrixs),
	m_signalProgs(signalProgs),
	m_nSgDataPrimaryID(0),		
	m_nIntGrDataPrimaryID(0),
	m_nSgProgDataPrimaryID(0),
	m_scData(scData),
	m_squenceDatas(squenceDatas),
	m_detectorVehicleDatas(detectorVehicleDatas),
	m_detectorBusDatas(detectorBusDatas),
	m_detectorPedestainsDatas(detectorPedestainsDatas),
	m_translationDatas(translationDatas),
	m_periodDatas(periodDatas)
{
	setColumnCount(1);	//��������
	setHeaderHidden(true);

	//�ȴ��������ڵ� ���顢�̼�����̵���ʱ������
	rootItem = new QTreeWidgetItem(this,QStringList(QString::fromLocal8Bit(m_scData.strName)));
	rootItem->setIcon(0, QIcon(":/Tree/signalCtrl"));
	
	sgsItem = new QTreeWidgetItem(rootItem, QStringList(QString::fromLocal8Bit("�źŵ���")));
	sgsItem->setIcon(0, QIcon(":/Tree/signalGroup"));

	interGreenMatrixsItem = new QTreeWidgetItem(rootItem, QStringList(QString::fromLocal8Bit("�̵Ƽ������")));
	interGreenMatrixsItem->setIcon(0, QIcon(":/Tree/greenIntervalMatrixs"));

	//����������ڵ�
	squenceItem = new QTreeWidgetItem(rootItem, QStringList(QString::fromLocal8Bit("��������")));
	squenceItem->setIcon(0, QIcon(":/Tree/squence"));

	translationItem = new QTreeWidgetItem(rootItem, QStringList(QString::fromLocal8Bit("���ɷ�������")));
	translationItem->setIcon(0, QIcon(":/Tree/translation"));

	signalProgsItem = new QTreeWidgetItem(rootItem, QStringList(QString::fromLocal8Bit("��ʱ����")));
	signalProgsItem->setIcon(0, QIcon(":/Tree/signalTimePlans"));

	periodItem = new QTreeWidgetItem(rootItem, QStringList(QString::fromLocal8Bit("ʱ�α�����")));
	periodItem->setIcon(0, QIcon(":/Tree/period"));

	detectorVehItem = new QTreeWidgetItem(rootItem, QStringList(QString::fromLocal8Bit("�������������")));
	detectorVehItem->setIcon(0, QIcon(":/Tree/detector"));
	detectorBusItem = new QTreeWidgetItem(rootItem, QStringList(QString::fromLocal8Bit("�������������")));
	detectorBusItem->setIcon(0, QIcon(":/Tree/detector"));
	detectorPedItem = new QTreeWidgetItem(rootItem, QStringList(QString::fromLocal8Bit("���˼��������")));
	detectorPedItem->setIcon(0, QIcon(":/Tree/detector"));


	this->setCurrentItem(rootItem);
	rootItem->setExpanded(true);

	//����Ĭ�ϵĵ�ɫ��ʱ���Ķ�Ӧ��ϵ���Ժ�����޸�dur����ʱ�������map
	m_sgColorToDefdur.insert(Red, 1);
	m_sgColorToDefdur.insert(Red_Amber, 1);
	m_sgColorToDefdur.insert(Green, 5);
	m_sgColorToDefdur.insert(Amber, 3);
	m_sgColorToDefdur.insert(Flash_Green, 4);
	m_sgColorToDefdur.insert(Flash_Amber, 1);
	m_sgColorToDefdur.insert(OFF, 1);
	m_sgColorToDefdur.insert(Flash_Red, 1);


	//������ӽڵ�ʱ,��Ҫ��ȡ��Ӧ�Ľ���
	 connect(this, SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)), this, SLOT(ItemChangedSlot(QTreeWidgetItem* )));


	 //����Ҽ��˵���
	 CreateActions();
	 popMenu = new QMenu(this);

}
void TreeWidget::setRootName(QString ip)
{
	QString nameStr="";
	nameStr =  QString::fromLocal8Bit("�źŻ�:" )+ ip;
	qstrcpy(m_scData.strName, nameStr.toLocal8Bit().toStdString().c_str());
	rootItem->setText(0, nameStr);
}
//�Ҽ��˵���Ӧ����
void TreeWidget::contextMenuEvent(QContextMenuEvent *event)
{
	QTreeWidgetItem *item = NULL;
	greenMtrxitem = NULL;
	QPoint point = QCursor::pos();//�õ�����λ�ã�ȫ������
	point = mapFromGlobal(point);//mapFromGlobal��ȫ������ת���ɴ�������
	item = this->itemAt(point);//Ϊʲô���ﷵ�صĶ���NULL��
	if(item != NULL)
	{
		if (item->parent()==interGreenMatrixsItem)
		{
			greenMtrxitem = static_cast<IntGreenTreeWidgetItem*>(item);

			popMenu->addAction(readPuaFile);
			popMenu->exec(QCursor::pos());//�˵����ֵ�λ��Ϊ��ǰ����λ��
		}
		
	}
	
	event->accept();
}
void TreeWidget::CreateActions()
{
	readPuaFile = new QAction(QString::fromLocal8Bit("��ȡ��������"),this);

	connect(readPuaFile, SIGNAL(triggered()), this, SLOT(LoadGreenMtrxFromPua()));
}

void TreeWidget::LoadGreenMtrxFromPua()
{
	//1.�����ļ�
	QString path = QFileDialog::getOpenFileName(this, tr("Open Pua"), ".", tr("Xml Files(*.pua)")); 
	if(path.length() == 0) 
	{ 
		QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files.")); 
		return;
	}

	QFile f(path);
	if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "Open file:"<<path<<"  Failed" << endl;
		return ;
	}

	QTextStream txtInput(&f);
	QString lineStr;

	QVector<int> intGreenValues;

	while(!txtInput.atEnd())
	{
		lineStr = txtInput.readLine();
		qDebug() <<"Read content: "<< lineStr << endl;
		if (lineStr == "$IGM")
		{
			txtInput.readLine();			//�Ե� ��$"��
			txtInput.readLine();			//�Ե� ��ͷ��
			int index = 0;
			while ((lineStr=txtInput.readLine()) != "")						//��ȡ�������ݣ�ֱ������
			{
				lineStr = lineStr.simplified();
				QStringList strList = lineStr.split(" ");
				strList.removeFirst();
				if (strList.size()!=m_sgsDatas.size())
				{
					QMessageBox::warning(this, "Warining", QString::fromLocal8Bit("�ļ��еĵ��������ʵ�ʲ�ƥ�䣬��ֹ����"));
					f.close();
					return;
				}
				//��ȡÿһ�е����ݣ���������
				for (int i=0; i<strList.size(); i++)
				{
					if (i!=index)		//ȥ����ͬ��
					{
						intGreenValues.push_back(strList[i].toInt());
					}
				}

				index ++;
			}
			break;
		}
	}
	f.close();
	
	//�Ѷ�ȡ�������ݣ���������item��������
	if (greenMtrxitem!=NULL)
	{
		InterGreenMatrixData data = greenMtrxitem->GetData();

		qSort(data.interGreens.begin(), data.interGreens.end(), insensitiveLessThan);
		for (int i=0; i<data.interGreens.size(); i++)
		{
			data.interGreens[i].nValue = intGreenValues[i];
		}
		greenMtrxitem->SetData(data);
		ItemChangedSlot(greenMtrxitem);
	}
}


void TreeWidget::ItemChangedSlot(QTreeWidgetItem* current)
{
	if (current->parent() == sgsItem)	//�źŵ���Ϣ
	{
		SgTreeWidgetItem * item = static_cast<SgTreeWidgetItem*> (current);
		if (item!=NULL)
		{
			emit updateSgInfo(item->m_data);
		}else
			qDebug()<<" item = null! \n";
	}else if (current->parent() == interGreenMatrixsItem)
	{
		IntGreenTreeWidgetItem * item = static_cast<IntGreenTreeWidgetItem*>(current);
		if (item!=NULL)
		{
			emit updateIntGrInfo(item->m_data);
		}
	}else if (current->parent() ==signalProgsItem )
	{
		SgProgTreeWidgetItem * item = static_cast<SgProgTreeWidgetItem*>(current);
		if (item!=NULL)
		{
			emit updateSgProgInfo(item->m_data);
		}
	}else if (current->parent() == squenceItem)
	{
		SquenceTreeWidgetItem *item = static_cast<SquenceTreeWidgetItem*>(current);
		if (item!=NULL)
		{
			emit updateSquenceInfo(item->m_data);
		}
	}else if (current->parent() == translationItem)
	{
		TransTreeWidgetItem *item = static_cast<TransTreeWidgetItem*>(current);
		if (item!=NULL)
		{
			emit updateTransInfo(item->m_data);
		}
	}else if (current->parent() == detectorVehItem)
	{
		DetectorVehicleTreeWidgetItem *item = static_cast<DetectorVehicleTreeWidgetItem*>(current);
		if (item!=NULL)
		{
			emit updateDetectVehInfo(item->m_data);
		}
	}else if (current->parent() == detectorBusItem)
	{
		DetectorBusTreeWidgetItem *item = static_cast<DetectorBusTreeWidgetItem*>(current);
		if (item!=NULL)
		{
			emit updateDetectBusInfo(item->m_data);
		}
	}else if (current->parent() == detectorPedItem)
	{
		DetectorPedTreeWdigetItem *item = static_cast<DetectorPedTreeWdigetItem*>(current);
		if (item!=NULL)
		{
			emit updateDetectPedInfo(item->m_data);
		}
	}else if (current->parent() == periodItem)
	{
		PeriodTreeWidgetItem *item = static_cast<PeriodTreeWidgetItem*>(current);
		if (item!=NULL)
		{
			emit updatePeriodInfo(item->m_data);
		}
	}else if (current == sgsItem)		//������Ϣ�������Ҳ൱ǰ��ʾ��ҳ��
	{
		emit sgsItemSelected();
		sortSgItems();
	}else if (current == interGreenMatrixsItem)
	{
		emit intGrMatrxItemSelected();
		sortIntGrItems();
	}else if (current == signalProgsItem)
	{
		emit sgProgsItemSelected();
		sortSgProgItems();
	}else if(current == squenceItem)		//�������ڵ㱻ѡ�У������źŵ������ڣ���ʾ�����б�
	{
		emit squenceItemSelected();
		sortSquenceItems();
	}else if (current == detectorVehItem)
	{
		emit detectVehItemSelected();
		sortDetectVehItems();
	}else if (current == detectorBusItem)
	{
		emit detectBusItemSelected();
		sortDetectBusItems();
	}else if(current == detectorPedItem)
	{
		emit detectPedItemSelected();
		sortDetectPedItems();
	}else if(current == translationItem)
	{
		emit transItemSelected();
		sortTransItems();
	}else if(current == periodItem)
	{
		emit periodItemSelected();
		sortPeriodItems();
	}else if (current==rootItem)
	{
		emit rootItemClicked();
	}
}

void TreeWidget::InitDurationOfSgData(SgData & data)
{
	memset(data.defaultDurations, 0, sizeof(data.defaultDurations));
	switch (data.nDefaultSignalSequence)
	{
	case COLOR_SEQU_ALL_RED:
		{
			data.defaultDurations[Red-1].nDisplay = Red;
			data.defaultDurations[Red-1].nDuration = m_sgColorToDefdur.value(Red);
		}
		break;
	case COLOR_SEQU_ALL_GREEN:
		{
			data.defaultDurations[Green-1].nDisplay = Green;
			data.defaultDurations[Green-1].nDuration = m_sgColorToDefdur.value(Green);
		}
		break;
	case COLOR_SEQU_RED_REDAMBER_GREEN_AMBER:
		{
			data.defaultDurations[Red-1].nDisplay = Red;
			data.defaultDurations[Red-1].nDuration = m_sgColorToDefdur.value(Red);
			data.defaultDurations[Red_Amber-1].nDisplay = Red_Amber;
			data.defaultDurations[Red_Amber-1].nDuration = m_sgColorToDefdur.value(Red_Amber);
			data.defaultDurations[Green-1].nDisplay = Green;
			data.defaultDurations[Green-1].nDuration = m_sgColorToDefdur.value(Green);
			data.defaultDurations[Amber-1].nDisplay = Amber;
			data.defaultDurations[Amber-1].nDuration = m_sgColorToDefdur.value(Amber);
		}
		break;
	case COLOR_SEQU_RED_GREEN:
		{
			data.defaultDurations[Red-1].nDisplay = Red;
			data.defaultDurations[Red-1].nDuration = m_sgColorToDefdur.value(Red);
			data.defaultDurations[Green-1].nDisplay = Green;
			data.defaultDurations[Green-1].nDuration = m_sgColorToDefdur.value(Green);
		}
		break;
	case COLOR_SEQU_RED_REDAMBER_GREEN_GREENFLASH_AMBER:
		{
			data.defaultDurations[Red-1].nDisplay = Red;
			data.defaultDurations[Red-1].nDuration = m_sgColorToDefdur.value(Red);
			data.defaultDurations[Red_Amber-1].nDisplay = Red_Amber;
			data.defaultDurations[Red_Amber-1].nDuration = m_sgColorToDefdur.value(Red_Amber);
			data.defaultDurations[Green-1].nDisplay = Green;
			data.defaultDurations[Green-1].nDuration = m_sgColorToDefdur.value(Green);
			data.defaultDurations[Flash_Green-1].nDisplay = Flash_Green;
			data.defaultDurations[Flash_Green-1].nDuration = m_sgColorToDefdur.value(Flash_Green);
			data.defaultDurations[Amber-1].nDisplay = Amber;
			data.defaultDurations[Amber-1].nDuration = m_sgColorToDefdur.value(Amber);
		}
		break;
	case COLOR_SEQU_RED_GREEN_GREENFLASH:
		{
			data.defaultDurations[Red-1].nDisplay = Red;
			data.defaultDurations[Red-1].nDuration = m_sgColorToDefdur.value(Red);
			data.defaultDurations[Green-1].nDisplay = Green;
			data.defaultDurations[Green-1].nDuration = m_sgColorToDefdur.value(Green);
			data.defaultDurations[Flash_Green-1].nDisplay = Flash_Green;
			data.defaultDurations[Flash_Green-1].nDuration = m_sgColorToDefdur.value(Flash_Green);
		}
		break;
	case COLOR_SEQU_RED_GREEN_AMBER:
		{
			data.defaultDurations[Red-1].nDisplay = Red;
			data.defaultDurations[Red-1].nDuration = m_sgColorToDefdur.value(Red);
			data.defaultDurations[Green-1].nDisplay = Green;
			data.defaultDurations[Green-1].nDuration = m_sgColorToDefdur.value(Green);
			data.defaultDurations[Amber-1].nDisplay = Amber;
			data.defaultDurations[Amber-1].nDuration = m_sgColorToDefdur.value(Amber);
		}
		break;
	case COLOR_SEQU_AMBERFLASH:
		{
			data.defaultDurations[Flash_Amber-1].nDisplay = Flash_Amber;
			data.defaultDurations[Flash_Amber-1].nDuration = m_sgColorToDefdur.value(Flash_Amber);
		}
		break;
	case COLOR_SEQU_OFF:
		{
			data.defaultDurations[OFF-1].nDisplay = OFF;
			data.defaultDurations[OFF-1].nDuration = m_sgColorToDefdur.value(OFF);
		}
		break;
	case COLOR_SEQU_RED_OFF:
		{
			data.defaultDurations[Red-1].nDisplay = Red;
			data.defaultDurations[Red-1].nDuration = m_sgColorToDefdur.value(Red);
			data.defaultDurations[OFF-1].nDisplay = OFF;
			data.defaultDurations[OFF-1].nDuration = m_sgColorToDefdur.value(OFF);
		}
		break;
	case COLOR_SEQU_RED_OFF_AMBER:
		{
			data.defaultDurations[Red-1].nDisplay = Red;
			data.defaultDurations[Red-1].nDuration = m_sgColorToDefdur.value(Red);
			data.defaultDurations[OFF-1].nDisplay = OFF;
			data.defaultDurations[OFF-1].nDuration = m_sgColorToDefdur.value(OFF);
			data.defaultDurations[Amber-1].nDisplay = Amber;
			data.defaultDurations[Amber-1].nDuration = m_sgColorToDefdur.value(Amber);
		}
		break;
	case COLOR_SEQU_OFF_GREEN:
		{
			data.defaultDurations[OFF-1].nDisplay = OFF;
			data.defaultDurations[OFF-1].nDuration = m_sgColorToDefdur.value(OFF);
			data.defaultDurations[Green-1].nDisplay = Green;
			data.defaultDurations[Green-1].nDuration = m_sgColorToDefdur.value(Green);
		}
		break;
	case COLOR_SEQU_AMBERFLASH_OFF:
		{
			data.defaultDurations[Flash_Amber-1].nDisplay = Flash_Amber;
			data.defaultDurations[Flash_Amber-1].nDuration = m_sgColorToDefdur.value(Flash_Amber);
			data.defaultDurations[OFF-1].nDisplay = OFF;
			data.defaultDurations[OFF-1].nDuration = m_sgColorToDefdur.value(OFF);
		}
		break;
	case COLOR_SEQU_RED_GREEN_REDFLASH:
		{
			data.defaultDurations[Red-1].nDisplay = Red;
			data.defaultDurations[Red-1].nDuration = m_sgColorToDefdur.value(Red);
			data.defaultDurations[Green-1].nDisplay = Green;
			data.defaultDurations[Green-1].nDuration = m_sgColorToDefdur.value(Green);
			data.defaultDurations[OFF-1].nDisplay = Flash_Red;
			data.defaultDurations[OFF-1].nDuration = m_sgColorToDefdur.value(Flash_Red);
		}
		break;
	case COLOR_SEQU_REDFLASH_OFF:
		{
			data.defaultDurations[Flash_Red-1].nDisplay = Flash_Red;
			data.defaultDurations[Flash_Red-1].nDuration = m_sgColorToDefdur.value(Flash_Red);
			data.defaultDurations[OFF-1].nDisplay = OFF;
			data.defaultDurations[OFF-1].nDuration = m_sgColorToDefdur.value(OFF);
		}
		break;
	default:
		break;
	}
}

void TreeWidget::AddSgData(OptionType type)
{
	//1.�������е��飬�ҵ����ı��
	int num = 0;
	for (int i=0; i<m_sgsDatas.size(); i++)
	{
		if (num<m_sgsDatas[i].nId)
		{
			num = m_sgsDatas[i].nId;
		}
		if (m_nSgDataPrimaryID<m_sgsDatas[i].nPrimaryId)
		{
			m_nSgDataPrimaryID = m_sgsDatas[i].nPrimaryId;
		}
	}
	m_nSgDataPrimaryID++;
	SgData data;
	if (type == TreeWidget::Copy)
	{
		if (sgnlsTableWidget!=NULL)
		{
			SgData tmp = sgnlsTableWidget->selectedData();
			data = tmp;
		}
	}
	data.nPrimaryId = m_nSgDataPrimaryID;
	data.nId = num+1;
	if (type==TreeWidget::Add)
	{
		data.nDefaultSignalSequence = COLOR_SEQU_RED_REDAMBER_GREEN_AMBER;
	//	InitDurationOfSgData(data);
		QString strName = QString::fromLocal8Bit("�źŵ��� %1").arg(data.nId);
		qstrcpy(data.strName, strName.toStdString().c_str());
		qstrcpy(data.strNotes, "");
	}
	m_sgsDatas.push_back(data);
}

void TreeWidget::AddSquenceData(OptionType type)
{
	//1.�������������ҵ����ı��
	int num = 0;
	for (int i=0; i<m_squenceDatas.size(); i++)
	{
		if (num<m_squenceDatas[i].nId)
		{
			num = m_squenceDatas[i].nId;
		}
	}
	SquenceData data;
	if (type == TreeWidget::Copy)
	{
		if (squenceTableWidget!=NULL)
		{
			SquenceData tmp = squenceTableWidget->selectedData();
			QString strName = QString::fromLocal8Bit("���� %1").arg(num+1);
			data = tmp;
			qstrcpy(data.strName, strName.toStdString().c_str());
		}
	}
	data.nId = num+1;
	if (type==TreeWidget::Add)
	{
		QString strName = QString::fromLocal8Bit("���� %1").arg(data.nId);
		qstrcpy(data.strName, strName.toStdString().c_str());
		memset(&data.squence, 0, sizeof(data.squence));
		data.squence.no = data.nId;
		data.isConfiged = false;
	}
	m_squenceDatas.push_back(data);
}

void TreeWidget::AddDetectVehData(OptionType type)
{
	//1.�������������ҵ����ı��
	int num = 0;
	for (int i=0; i<m_detectorVehicleDatas.size(); i++)
	{
		if (num<m_detectorVehicleDatas[i].detector.byDetectorNo)
		{
			num = m_detectorVehicleDatas[i].detector.byDetectorNo;
		}
	}
	DetectorVehicleData data;
	if (type == TreeWidget::Copy)
	{
		if (detectVehTableWidget!=NULL)
		{
			DetectorVehicleData tmp = detectVehTableWidget->selectedData();
			QString strName = QString::fromLocal8Bit("����������� %1").arg(num+1);
			data = tmp;
			qstrcpy(data.strName, strName.toStdString().c_str());
		}
	}
	data.detector.byDetectorNo = num+1;
	if (type==TreeWidget::Add)
	{
		QString strName = QString::fromLocal8Bit("����������� %1").arg(data.detector.byDetectorNo);
		qstrcpy(data.strName, strName.toStdString().c_str());
		memset(&data.detector, 0, sizeof(data.detector));
		data.detector.byDetectorNo = num+1;
	}
	m_detectorVehicleDatas.push_back(data);
}

void TreeWidget::AddDetectBusData(OptionType type)
{
	//1.�������������ҵ����ı��
	int num = 0;
	for (int i=0; i<m_detectorBusDatas.size(); i++)
	{
		if (num<m_detectorBusDatas[i].detector.byDetectorNo)
		{
			num = m_detectorBusDatas[i].detector.byDetectorNo;
		}
	}
	DetectorBusData data;
	if (type == TreeWidget::Copy)
	{
		if (detectBusTableWidget!=NULL)
		{
			DetectorBusData tmp = detectBusTableWidget->selectedData();
			QString strName = QString::fromLocal8Bit("��������� %1").arg(num+1);
			data = tmp;
			qstrcpy(data.strName, strName.toStdString().c_str());
		}
	}
	data.detector.byDetectorNo = num+1;
	if (type==TreeWidget::Add)
	{
		QString strName = QString::fromLocal8Bit("��������� %1").arg(data.detector.byDetectorNo);
		qstrcpy(data.strName, strName.toStdString().c_str());
		memset(&data.detector, 0, sizeof(data.detector));
		data.detector.byDetectorNo = num+1;
	}
	m_detectorBusDatas.push_back(data);
}

void TreeWidget::AddDetectPedData(OptionType type)
{
	//1.�������������ҵ����ı��
	int num = 0;
	for (int i=0; i<m_detectorPedestainsDatas.size(); i++)
	{
		if (num<m_detectorPedestainsDatas[i].detector.byDetectorNo)
		{
			num = m_detectorPedestainsDatas[i].detector.byDetectorNo;
		}
	}
	DetectorsPedestrainsData data;
	if (type == TreeWidget::Copy)
	{
		if (detectPedTableWidget!=NULL)
		{
			DetectorsPedestrainsData tmp = detectPedTableWidget->selectedData();
			QString strName = QString::fromLocal8Bit("���˼���� %1").arg(num+1);
			data = tmp;
			qstrcpy(data.strName, strName.toStdString().c_str());
		}
	}
	data.detector.byDetectorNo = num+1;
	if (type==TreeWidget::Add)
	{
		QString strName = QString::fromLocal8Bit("���˼���� %1").arg(data.detector.byDetectorNo);
		qstrcpy(data.strName, strName.toStdString().c_str());
		memset(&data.detector, 0, sizeof(data.detector));
		data.detector.byDetectorNo = num+1;
	}
	m_detectorPedestainsDatas.push_back(data);
}
void TreeWidget::AddPeriodData(OptionType type)
{
	//1.�������������ҵ����ı��
	int num = 0;
	for (int i=0; i<m_periodDatas.size(); i++)
	{
		if (num<m_periodDatas[i].nId)
		{
			num = m_periodDatas[i].nId;
		}
	}
	PeriodData data;
	if (type == TreeWidget::Copy)
	{
		if (periodTableWidget!=NULL)
		{
			PeriodData tmp = periodTableWidget->selectedData();
			QString strName = QString::fromLocal8Bit("ʱ�� %1").arg(num+1);
			data = tmp;
			qstrcpy(data.strName, strName.toStdString().c_str());
		}
	}
	data.nId= num+1;
	if (type==TreeWidget::Add)
	{
		QString strName = QString::fromLocal8Bit("ʱ�� %1").arg(data.nId);
		qstrcpy(data.strName, strName.toStdString().c_str());
		memset(&data.period, 0, sizeof(data.period));
	}
	m_periodDatas.push_back(data);
}

void TreeWidget::AddTransData(OptionType type)
{
	//1.�������������ҵ����ı��
	int num = 0;
	for (int i=0; i<m_translationDatas.size(); i++)
	{
		if (num<m_translationDatas[i].translationPlan.byTransitionPlanNo)
		{
			num = m_translationDatas[i].translationPlan.byTransitionPlanNo;
		}
	}
	TranslationPlanData data;
	if (type == TreeWidget::Copy)
	{
		if (transTableWidget!=NULL)
		{
			TranslationPlanData tmp = transTableWidget->selectedData();
			QString strName = QString::fromLocal8Bit("���ɷ��� %1").arg(num+1);
			data = tmp;
			qstrcpy(data.strName, strName.toStdString().c_str());
		}
	}
	data.translationPlan.byTransitionPlanNo = num+1;
	if (type==TreeWidget::Add)
	{
		QString strName = QString::fromLocal8Bit("���ɷ��� %1").arg(data.translationPlan.byTransitionPlanNo);
		qstrcpy(data.strName, strName.toStdString().c_str());
		memset(&data.translationPlan, 0, sizeof(data.translationPlan));
		data.translationPlan.byTransitionPlanNo = num+1;
	}
	m_translationDatas.push_back(data);
}

void TreeWidget::AddIntGrMatrixData(OptionType type)
{
	//1.���������̵ƾ����ҵ����ı��
	int num = 0;
	for (int i=0; i<m_interGreenMatrixs.size(); i++)
	{
		if (num<m_interGreenMatrixs[i].nId)
		{
			num = m_interGreenMatrixs[i].nId;
		}
		if (m_nIntGrDataPrimaryID<m_interGreenMatrixs[i].nPrimaryId)
		{
			m_nIntGrDataPrimaryID = m_interGreenMatrixs[i].nPrimaryId;
		}
	}
	m_nIntGrDataPrimaryID++;

	InterGreenMatrixData data;
	if (type == TreeWidget::Copy)
	{
		if (intGreenTableWidget!=NULL)
		{
			InterGreenMatrixData tmp = intGreenTableWidget->selectedData();
			data = tmp;
		}
	}
	data.nId = num+1;
	data.nPrimaryId = m_nIntGrDataPrimaryID;
	if (type == TreeWidget::Add)
	{
		QString strName = QString::fromLocal8Bit("�̵Ƽ������ %1").arg(data.nId);
		qstrcpy(data.strName, strName.toStdString().c_str());
		//�̼��������,�����ݵ�����źŵƸ�����ȷ������ӵľ�����̵Ƽ����
		for (int i=0; i<m_sgsDatas.size(); i++)
		{
			for (int j=0; j<m_sgsDatas.size(); j++)
			{
				if (m_sgsDatas[i].nId!=m_sgsDatas[j].nId)
				{
					InterGreen interGreenData;
					interGreenData.nClearingSg = m_sgsDatas[i].nId;
					interGreenData.nEnteringSg = m_sgsDatas[j].nId;
					interGreenData.nValue = -127;
					data.interGreens.push_back(interGreenData);
				}
			}
		}
	}
	
	m_interGreenMatrixs.push_back(data);
}

void TreeWidget::AddSignalProgData(OptionType type)
{
	//1.���������̵ƾ����ҵ����ı��
	int num = 0;
	for (int i=0; i<m_signalProgs.size(); i++)
	{
		if (num<m_signalProgs[i].nId)
		{
			num = m_signalProgs[i].nId;
		}
		if (m_nSgProgDataPrimaryID<m_signalProgs[i].nPrimaryId)
		{
			m_nSgProgDataPrimaryID = m_signalProgs[i].nPrimaryId;
		}
	}
	m_nSgProgDataPrimaryID++;
	SignalProgData data;
	if (type == TreeWidget::Copy)
	{
		SignalProgData tmp = sgProgTableWidget->selectedData();
		data = tmp;
	}
	data.nPrimaryId = m_nSgProgDataPrimaryID;
	data.nId = num+1;
	if (type == TreeWidget::Add)
	{
		QString strName = QString::fromLocal8Bit("�ź���ʱ���� %1").arg(data.nId);
		qstrcpy(data.strName, strName.toStdString().c_str());
		data.nCycleTime = defaultCycle;
		data.nSwitchPoint = 0;
		data.nOffset = 0;
		data.nInterGreens = 0;
		for (int i = 0; i < m_sgsDatas.size(); i++)
		{
			SgDataInProg sgDataInProg;
			sgDataInProg.nSgId = m_sgsDatas[i].nId;
			sgDataInProg.nSignalSequence = COLOR_SEQU_ALL_RED;
			SetCmdAndFixState(sgDataInProg);
			data.sgDatasInProg.push_back(sgDataInProg);
		}
	}
	m_signalProgs.push_back(data);
}



void TreeWidget::updateDataWithSgsData(const SgData &data, OptionType ntype)
{
	if (ntype == TreeWidget::Add || ntype == TreeWidget::Copy)
	{
		//����һ���źŵƺ�ÿ������Ҫ������Ӧ���̵Ƽ��
		for (int i=0; i<m_interGreenMatrixs.size(); i++)
		{
			for (int j=0; j<m_sgsDatas.size(); j++)
			{
				if (data.nId != m_sgsDatas[j].nId)
				{
					InterGreen interGreenData;
					interGreenData.nClearingSg = data.nId;
					interGreenData.nEnteringSg = m_sgsDatas[j].nId;
					interGreenData.nValue = -127;
					m_interGreenMatrixs[i].interGreens.push_back(interGreenData);

					InterGreen interGreenData2;
					interGreenData2.nClearingSg = m_sgsDatas[j].nId;
					interGreenData2.nEnteringSg = data.nId;
					interGreenData2.nValue = -127;
					m_interGreenMatrixs[i].interGreens.push_back(interGreenData2);
				}
			}
			//����clearingId����
			qSort(m_interGreenMatrixs[i].interGreens.begin(), m_interGreenMatrixs[i].interGreens.end(), insensitiveLessThan);
			//�����ĺ�����ݣ����µ����ڵ��Ա�У�ʹ������ʾ�����ݴ洢����һ�¡�
			for (QList<IntGreenTreeWidgetItem*>::iterator it=intGreenTreeWidgetItemLists.begin(); it!=intGreenTreeWidgetItemLists.end(); it++)
			{
				if (m_interGreenMatrixs[i].nPrimaryId == (*it)->m_data.nPrimaryId)
				{
					(*it)->SetData(m_interGreenMatrixs[i]);
					break;
				}
			}
		}

		//������ʱ�����������źŵ�ʱ��ÿ����ʱ������Ҫ������Ӧ������
		for (int i=0; i<m_signalProgs.size(); i++)
		{
			SgDataInProg sgDataInProg;
			sgDataInProg.nSgId = data.nId;
			sgDataInProg.nSignalSequence = data.nDefaultSignalSequence;
			SetCmdAndFixState(sgDataInProg);
			m_signalProgs[i].sgDatasInProg.push_back(sgDataInProg);

			//�����ĺ�����ݣ����µ����ڵ��Ա�У�ʹ������ʾ�����ݴ洢����һ�¡�
			for (QList<SgProgTreeWidgetItem*>::iterator it=sgProgTreeWidgetItemList.begin(); it!=sgProgTreeWidgetItemList.end(); it++)
			{
				if (m_signalProgs[i].nPrimaryId == (*it)->m_data.nPrimaryId)
				{
					(*it)->SetData(m_signalProgs[i]);
					break;
				}
			}
		}
	}

	if (ntype == TreeWidget::Delete)
	{
		//ɾ��һ���źŵ����ݣ�������Ӧ���̵Ƽ������
		for (int i=0; i<m_interGreenMatrixs.size(); i++)
		{
			for (int j=0; j<m_interGreenMatrixs[i].interGreens.size(); j++)
			{
				if (m_interGreenMatrixs[i].interGreens[j].nEnteringSg==data.nId ||
					m_interGreenMatrixs[i].interGreens[j].nClearingSg==data.nId)
				{
					m_interGreenMatrixs[i].interGreens.remove(j);
					j--;
				}
			}
			//�����ĺ�����ݣ����µ����ڵ��Ա�У�ʹ������ʾ�����ݴ洢����һ�¡�
			for (QList<IntGreenTreeWidgetItem*>::iterator it=intGreenTreeWidgetItemLists.begin(); it!=intGreenTreeWidgetItemLists.end(); it++)
			{
				if (m_interGreenMatrixs[i].nPrimaryId == (*it)->m_data.nPrimaryId)
				{
					(*it)->SetData(m_interGreenMatrixs[i]);
					break;
				}
			}
		}

		//������Ӧ����ʱ��������
		for (int i=0; i<m_signalProgs.size(); i++)
		{
			for (int j=0; j<m_signalProgs[i].sgDatasInProg.size(); j++)
			{
				if (m_signalProgs[i].sgDatasInProg[j].nSgId == data.nId)
				{
					m_signalProgs[i].sgDatasInProg.remove(j);
					j--;
					break;
				}
			}

			//�����ĺ�����ݣ����µ����ڵ��Ա�У�ʹ������ʾ�����ݴ洢����һ�¡�
			for (QList<SgProgTreeWidgetItem*>::iterator it=sgProgTreeWidgetItemList.begin(); it!=sgProgTreeWidgetItemList.end(); it++)
			{
				if (m_signalProgs[i].nPrimaryId == (*it)->m_data.nPrimaryId)
				{
					(*it)->SetData(m_signalProgs[i]);
					break;
				}
			}
		}
	}

	
}

void TreeWidget::SetCmdAndFixState(SgDataInProg &data)
{
	data.cmds.clear();
	data.fixedStates.clear();
	switch (data.nSignalSequence)
	{
	case COLOR_SEQU_ALL_RED:
		{
			CmdData cmdData;
			cmdData.nDisplay = Red;
			cmdData.nBegin = 0;
			data.cmds.push_back(cmdData);
		}
		break;
	case COLOR_SEQU_ALL_GREEN:
		{
			CmdData cmdData;
			cmdData.nDisplay = Green;
			cmdData.nBegin = 0;
			data.cmds.push_back(cmdData);
		}
		break;
	case COLOR_SEQU_RED_REDAMBER_GREEN_AMBER:
		{
			CmdData cmdData;
			cmdData.nDisplay = Red;
			cmdData.nBegin = 0;
			data.cmds.push_back(cmdData);
			cmdData.nDisplay = Green;
			cmdData.nBegin = m_sgColorToDefdur.value(Red_Amber)+3;
			data.cmds.push_back(cmdData);

			FixStateData fixData;
			fixData.nDisplay = Red_Amber;
			fixData.nDuration = m_sgColorToDefdur.value(Red_Amber);
			data.fixedStates.push_back(fixData);
			fixData.nDisplay = Amber;
			fixData.nDuration = m_sgColorToDefdur.value(Amber);
			data.fixedStates.push_back(fixData);
		}
		break;
	case COLOR_SEQU_RED_GREEN:
		{
			CmdData cmdData;
			cmdData.nDisplay = Red;
			cmdData.nBegin = 0;
			data.cmds.push_back(cmdData);
			cmdData.nDisplay = Green;
			cmdData.nBegin = 3;
			data.cmds.push_back(cmdData);
		}
		break;
	case COLOR_SEQU_RED_REDAMBER_GREEN_GREENFLASH_AMBER:
		{
			CmdData cmdData;
			cmdData.nDisplay = Red;
			cmdData.nBegin = 0;
			data.cmds.push_back(cmdData);
			cmdData.nDisplay = Green;
			cmdData.nBegin = m_sgColorToDefdur.value(Red_Amber)+3;
			data.cmds.push_back(cmdData);

			FixStateData fixData;
			fixData.nDisplay = Red_Amber;
			fixData.nDuration = m_sgColorToDefdur.value(Red_Amber);
			data.fixedStates.push_back(fixData);
			fixData.nDisplay = Flash_Green;
			fixData.nDuration = m_sgColorToDefdur.value(Flash_Green);
			data.fixedStates.push_back(fixData);
			fixData.nDisplay = Amber;
			fixData.nDuration = m_sgColorToDefdur.value(Amber);
			data.fixedStates.push_back(fixData);
		}
		break;
	case COLOR_SEQU_RED_GREEN_GREENFLASH:
		{
			CmdData cmdData;
			cmdData.nDisplay = Red;
			cmdData.nBegin = 0;
			data.cmds.push_back(cmdData);
			cmdData.nDisplay = Green;
			cmdData.nBegin = 3;
			data.cmds.push_back(cmdData);

			FixStateData fixData;
			fixData.nDisplay = Flash_Green;
			fixData.nDuration = m_sgColorToDefdur.value(Flash_Green);
			data.fixedStates.push_back(fixData);
		}
		break;
	case COLOR_SEQU_RED_GREEN_AMBER:
		{
			CmdData cmdData;
			cmdData.nDisplay = Red;
			cmdData.nBegin = 0;
			data.cmds.push_back(cmdData);
			cmdData.nDisplay = Green;
			cmdData.nBegin =3;
			data.cmds.push_back(cmdData);

			FixStateData fixData;
			fixData.nDisplay = Amber;
			fixData.nDuration = m_sgColorToDefdur.value(Amber);
			data.fixedStates.push_back(fixData);
		}
		break;
	case COLOR_SEQU_AMBERFLASH:
		{
			CmdData cmdData;
			cmdData.nDisplay = Flash_Amber;
			cmdData.nBegin = 0;
			data.cmds.push_back(cmdData);

		}
		break;
	case COLOR_SEQU_OFF:
		{
			CmdData cmdData;
			cmdData.nDisplay = OFF;
			cmdData.nBegin = 0;
			data.cmds.push_back(cmdData);
		}
		break;
	case COLOR_SEQU_RED_OFF:
		{
			CmdData cmdData;
			cmdData.nDisplay = Red;
			cmdData.nBegin = 0;
			data.cmds.push_back(cmdData);
			cmdData.nDisplay = OFF;
			cmdData.nBegin = 3;
			data.cmds.push_back(cmdData);
		}
		break;
	case COLOR_SEQU_RED_OFF_AMBER:
		{
			CmdData cmdData;
			cmdData.nDisplay = Red;
			cmdData.nBegin = 0;
			data.cmds.push_back(cmdData);
			cmdData.nDisplay = OFF;
			cmdData.nBegin = 3;
			data.cmds.push_back(cmdData);

			FixStateData fixData;
			fixData.nDisplay = Amber;
			fixData.nDuration = m_sgColorToDefdur.value(Amber);
			data.fixedStates.push_back(fixData);
		}
		break;
	case COLOR_SEQU_OFF_GREEN:
		{
			CmdData cmdData;
			cmdData.nDisplay = OFF;
			cmdData.nBegin = 0;
			data.cmds.push_back(cmdData);
			cmdData.nDisplay = Green;
			cmdData.nBegin = 3;
			data.cmds.push_back(cmdData);
		}
		break;
	case COLOR_SEQU_AMBERFLASH_OFF:
		{
			CmdData cmdData;
			cmdData.nDisplay = OFF;
			cmdData.nBegin = 3;
			data.cmds.push_back(cmdData);
			cmdData.nDisplay = Flash_Amber;
			cmdData.nBegin = 0;
			data.cmds.push_back(cmdData);
		}
		break;
	case COLOR_SEQU_RED_GREEN_REDFLASH:
		{
			CmdData cmdData;
			cmdData.nDisplay = Red;
			cmdData.nBegin = 0;
			data.cmds.push_back(cmdData);
			cmdData.nDisplay = Green;
			cmdData.nBegin = 3;
			data.cmds.push_back(cmdData);

			FixStateData fixData;
			fixData.nDisplay = Flash_Red;
			fixData.nDuration = m_sgColorToDefdur.value(Flash_Red);
			data.fixedStates.push_back(fixData);
		}
		break;
	case COLOR_SEQU_REDFLASH_OFF:
		{
			CmdData cmdData;
			cmdData.nDisplay = Flash_Red;
			cmdData.nBegin = 0;
			data.cmds.push_back(cmdData);
			cmdData.nDisplay = OFF;
			cmdData.nBegin = 3;
			data.cmds.push_back(cmdData);
		}
		break;
	default:
		break;
	}
}

void TreeWidget::copyItem()		//��������Ӳ�������һ�£���ʱ��ɿ��Ǻϲ�Ϊһ���ۺ�����
{
	QTreeWidgetItem * crtItem = currentItem();
	if(crtItem==sgsItem && sgnlsTableWidget->selectedItems().count()!=0)
	{
		AddSgData(TreeWidget::Copy);
		SgTreeWidgetItem *item = new SgTreeWidgetItem(m_sgsDatas[m_sgsDatas.size()-1], sgsItem);
		sgTreeWdigetItemLists<<item;	//������ӵ����ڵ�
		updateDataWithSgsData(m_sgsDatas[m_sgsDatas.size()-1], TreeWidget::Copy);		//��ӽڵ��Ҫ���¾������ʱ������
		//���µ����б�
		emit updateSgsTable();
	}else    if(crtItem==interGreenMatrixsItem&&intGreenTableWidget->selectedItems().count()!=0)
	{
		AddIntGrMatrixData(TreeWidget::Copy);		//���һ���̵Ƽ����¼
		IntGreenTreeWidgetItem *item = new IntGreenTreeWidgetItem(m_interGreenMatrixs[m_interGreenMatrixs.size()-1], interGreenMatrixsItem);
		//������ʱ�����е��̵Ƽ��������,ֻ��Ҫ�����̵Ƽ�����ݼ���
		intGreenTreeWidgetItemLists<<item;
		//�����̵ƾ����б�
		emit updateIntGrMtrxTable();
	}else if(crtItem==signalProgsItem && sgProgTableWidget->selectedItems().count()!=0)
	{
		AddSignalProgData(TreeWidget::Copy);
		SgProgTreeWidgetItem *item = new SgProgTreeWidgetItem(m_signalProgs[m_signalProgs.size()-1], signalProgsItem);
		sgProgTreeWidgetItemList<<item;
		//������ʱ�����б�
		emit updateSgProgTable();
	}else if (crtItem == squenceItem && squenceTableWidget->selectedItems().count()!=0)
	{
		AddSquenceData(TreeWidget::Copy);
		SquenceTreeWidgetItem *item = new SquenceTreeWidgetItem(m_squenceDatas[m_squenceDatas.size()-1], squenceItem);
		squenceTreeWidgetItemList<<item;
		//������ʱ�����б�
		emit updateSquenceTable();
	}else if (crtItem == translationItem && transTableWidget->selectedItems().count()!=0)
	{
		AddTransData(TreeWidget::Copy);
		TransTreeWidgetItem *item = new TransTreeWidgetItem(m_translationDatas[m_translationDatas.size()-1], translationItem);
		transTreeWidgetItemList<<item;
		//������ʱ�����б�
		emit updatetranslationTable();
	}else if (crtItem == detectorVehItem && detectVehTableWidget->selectedItems().count()!=0)
	{
		AddDetectVehData(TreeWidget::Copy);
		DetectorVehicleTreeWidgetItem *item = new DetectorVehicleTreeWidgetItem(m_detectorVehicleDatas[m_detectorVehicleDatas.size()-1], detectorVehItem);
		detectVehTreeWidgetItemList<<item;
		//������ʱ�����б�
		emit updateDetectVehTable();
	}else if (crtItem == detectorBusItem && detectBusTableWidget->selectedItems().count()!=0)
	{
		AddDetectBusData(TreeWidget::Copy);
		DetectorBusTreeWidgetItem *item = new DetectorBusTreeWidgetItem(m_detectorBusDatas[m_detectorBusDatas.size()-1], detectorBusItem);
		detectBusTreeWidgetItemList<<item;
		//������ʱ�����б�
		emit updateDetectBusTable();
	}else if (crtItem == detectorPedItem && detectPedTableWidget->selectedItems().count()!=0)
	{
		AddDetectPedData(TreeWidget::Copy);
		DetectorPedTreeWdigetItem *item = new DetectorPedTreeWdigetItem(m_detectorPedestainsDatas[m_detectorPedestainsDatas.size()-1], detectorPedItem);
		detectPedTreeWidgetItemList<<item;
		//������ʱ�����б�
		emit updateDetectPedTable();
	}else if (crtItem == periodItem && periodTableWidget->selectedItems().count()!=0)
	{
		AddPeriodData(TreeWidget::Copy);
		PeriodTreeWidgetItem *item = new PeriodTreeWidgetItem(m_periodDatas[m_periodDatas.size()-1], periodItem);
		periodTreeWidgetItemList<<item;
		//������ʱ�����б�
		emit updatePeriodTable();
	}
	
}
//��Ӧ��Ӱ�ť
void TreeWidget::addItem()
{
	QTreeWidgetItem * crtItem = currentItem();
	if(crtItem==sgsItem)
	{
		if (m_sgsDatas.size()>MAX_PHASES-1)
		{
			QMessageBox::warning(this, "Warning!", QString::fromLocal8Bit("���������ɳ���%1��").arg(MAX_PHASES));
			return;
		}
		AddSgData();
		SgTreeWidgetItem *item = new SgTreeWidgetItem(m_sgsDatas[m_sgsDatas.size()-1], sgsItem);
		sgTreeWdigetItemLists<<item;	//������ӵ����ڵ�
		updateDataWithSgsData(m_sgsDatas[m_sgsDatas.size()-1]);		//��ӽڵ��Ҫ���¾������ʱ������
		//���µ����б�
		emit updateSgsTable();
	}else    if(crtItem==interGreenMatrixsItem)
	{
		if (m_interGreenMatrixs.size()>MAX_MTRIXGREEN_NUMBER-1)
		{
			QMessageBox::warning(this, "Warining", QString::fromLocal8Bit("�̵Ƽ�������ܳ���%1��").arg(MAX_MTRIXGREEN_NUMBER));
			return;
		}
		AddIntGrMatrixData();		//���һ���̵Ƽ����¼
		IntGreenTreeWidgetItem *item = new IntGreenTreeWidgetItem(m_interGreenMatrixs[m_interGreenMatrixs.size()-1], interGreenMatrixsItem);
		//������ʱ�����е��̵Ƽ��������,ֻ��Ҫ�����̵Ƽ�����ݼ���
		intGreenTreeWidgetItemLists<<item;
		//�����̵ƾ����б�
		emit updateIntGrMtrxTable();
	}else if(crtItem==signalProgsItem)
	{
		if (m_signalProgs.size()>MAX_PLAN_NUMBER-1)
		{
			QMessageBox::warning(this, "Warning!", QString::fromLocal8Bit("��ʱ�������ܳ���%1��").arg(MAX_PLAN_NUMBER));
			return;
		}
		AddSignalProgData();
		SgProgTreeWidgetItem *item = new SgProgTreeWidgetItem(m_signalProgs[m_signalProgs.size()-1], signalProgsItem);
		sgProgTreeWidgetItemList<<item;
		//������ʱ�����б�
		emit updateSgProgTable();
	}
	else if (crtItem == squenceItem)
	{
		if (m_squenceDatas.size()>MAX_PHASE_SEQUENCES-1)
		{
			QMessageBox::warning(this, "Warning!", QString::fromLocal8Bit("���������ɳ���%1��").arg(MAX_PHASE_SEQUENCES));
			return;
		}
		AddSquenceData();
		SquenceTreeWidgetItem *item = new SquenceTreeWidgetItem(m_squenceDatas[m_squenceDatas.size()-1], squenceItem);
		squenceTreeWidgetItemList<<item;	//������ӵ����ڵ�
		//���������б��б�
		emit updateSquenceTable();
	}else if (crtItem == translationItem)
	{
		if (m_translationDatas.size()>MAX_TRANSITION_PLANS-1)
		{
			QMessageBox::warning(this, "Warning!", QString::fromLocal8Bit("���ɷ��������ɳ���%1��").arg(MAX_TRANSITION_PLANS));
			return;
		}
		AddTransData();
		TransTreeWidgetItem *item = new TransTreeWidgetItem(m_translationDatas[m_translationDatas.size()-1], translationItem);
		transTreeWidgetItemList<<item;	//������ӵ����ڵ�
		//���������б��б�
		emit updatetranslationTable();
	}else if (crtItem == detectorVehItem)
	{
		if (m_detectorVehicleDatas.size()>MAX_VEHICLE_DETECTORS-1)
		{
			QMessageBox::warning(this, "Warning!", QString::fromLocal8Bit("��������������ɳ���%1��").arg(MAX_VEHICLE_DETECTORS));
			return;
		}
		AddDetectVehData();
		DetectorVehicleTreeWidgetItem *item = new DetectorVehicleTreeWidgetItem(m_detectorVehicleDatas[m_detectorVehicleDatas.size()-1], detectorVehItem);
		detectVehTreeWidgetItemList<<item;	//������ӵ����ڵ�
		//���������б��б�
		emit updateDetectVehTable();
	}else if (crtItem == detectorBusItem)
	{
		if (m_detectorBusDatas.size()>MAX_BUS_DETECTORS-1)
		{
			QMessageBox::warning(this, "Warning!", QString::fromLocal8Bit("������������ɳ���%1��").arg(MAX_BUS_DETECTORS));
			return;
		}
		AddDetectBusData();
		DetectorBusTreeWidgetItem *item = new DetectorBusTreeWidgetItem(m_detectorBusDatas[m_detectorBusDatas.size()-1], detectorBusItem);
		detectBusTreeWidgetItemList<<item;	//������ӵ����ڵ�
		//���������б��б�
		emit updateDetectBusTable();
	}else if (crtItem == detectorPedItem)
	{
		if (m_detectorPedestainsDatas.size()>MAX_PEDESTRIAN_DETECTORS-1)
		{
			QMessageBox::warning(this, "Warning!", QString::fromLocal8Bit("���˼�������ɳ���%1��").arg(MAX_PEDESTRIAN_DETECTORS));
			return;
		}
		AddDetectPedData();
		DetectorPedTreeWdigetItem *item = new DetectorPedTreeWdigetItem(m_detectorPedestainsDatas[m_detectorPedestainsDatas.size()-1], detectorPedItem);
		detectPedTreeWidgetItemList<<item;	//������ӵ����ڵ�
		//���������б��б�
		emit updateDetectPedTable();
	}else if (crtItem == periodItem)
	{
		if (m_periodDatas.size()>MAX_PERIODS-1)
		{
			QMessageBox::warning(this, "Warning!", QString::fromLocal8Bit("ʱ�θ������ɳ���%1��").arg(MAX_PERIODS));
			return;
		}
		AddPeriodData();
		PeriodTreeWidgetItem *item = new PeriodTreeWidgetItem(m_periodDatas[m_periodDatas.size()-1], periodItem);
		periodTreeWidgetItemList<<item;	//������ӵ����ڵ�
		//���������б��б�
		emit updatePeriodTable();
	}
}

void TreeWidget::delItem()
{
	QTreeWidgetItem * crtItem = currentItem();
	if(crtItem==sgsItem)
	{
		if (sgnlsTableWidget!=NULL)
		{
			SgData data = sgnlsTableWidget->removeSelectedData();
			for (QList<SgTreeWidgetItem*>::iterator it=sgTreeWdigetItemLists.begin(); it!=sgTreeWdigetItemLists.end(); it++)
			{
				if ((*it)->m_data.nPrimaryId == data.nPrimaryId)
				{
					sgsItem->removeChild((*it));
					sgTreeWdigetItemLists.erase(it);
					updateDataWithSgsData(data, TreeWidget::Delete);
					break;
				}
			}
		}

	}else    if(crtItem==interGreenMatrixsItem)
	{
		if (intGreenTableWidget != NULL)
		{
			InterGreenMatrixData data = intGreenTableWidget->removeSelectedData();
			for (QList<IntGreenTreeWidgetItem*>::iterator it = intGreenTreeWidgetItemLists.begin(); it!=intGreenTreeWidgetItemLists.end();it++)
			{
				if ((*it)->m_data.nPrimaryId == data.nPrimaryId)
				{
					interGreenMatrixsItem->removeChild((*it));
					intGreenTreeWidgetItemLists.erase(it);
					updateSgProgDatasWithIntGrData(data, TreeWidget::Delete);
					break;		
				}
			}
		}
	}else if(crtItem==signalProgsItem)
	{
		SignalProgData data = sgProgTableWidget->removeSelectedData();
		for (QList<SgProgTreeWidgetItem*>::iterator it = sgProgTreeWidgetItemList.begin(); it!=sgProgTreeWidgetItemList.end();it++)
		{
			if ((*it)->m_data.nPrimaryId == data.nPrimaryId)
			{
				signalProgsItem->removeChild((*it));
				sgProgTreeWidgetItemList.erase(it);
				break;		
			}
		}
	}else if (crtItem == squenceItem)
	{
		SquenceData data = squenceTableWidget->removeSelectedData();
		for (QList<SquenceTreeWidgetItem*>::iterator it = squenceTreeWidgetItemList.begin(); it!=squenceTreeWidgetItemList.end();it++)
		{
			if ((*it)->m_data.nId == data.nId)
			{
				squenceItem->removeChild((*it));
				squenceTreeWidgetItemList.erase(it);
				break;		
			}
		}
	}else if (crtItem == translationItem)
	{
		TranslationPlanData data = transTableWidget->removeSelectedData();
		for (QList<TransTreeWidgetItem*>::iterator it = transTreeWidgetItemList.begin(); it!=transTreeWidgetItemList.end();it++)
		{
			if ((*it)->m_data.translationPlan.byTransitionPlanNo == data.translationPlan.byTransitionPlanNo)
			{
				translationItem->removeChild((*it));
				transTreeWidgetItemList.erase(it);
				break;		
			}
		}
	}else if (crtItem == detectorVehItem)
	{
		DetectorVehicleData data = detectVehTableWidget->removeSelectedData();
		for (QList<DetectorVehicleTreeWidgetItem*>::iterator it = detectVehTreeWidgetItemList.begin(); it!=detectVehTreeWidgetItemList.end();it++)
		{
			if ((*it)->m_data.detector.byDetectorNo== data.detector.byDetectorNo)
			{
				detectorVehItem->removeChild((*it));
				detectVehTreeWidgetItemList.erase(it);
				break;		
			}
		}
	}else if (crtItem == detectorBusItem)
	{
		DetectorBusData data = detectBusTableWidget->removeSelectedData();
		for (QList<DetectorBusTreeWidgetItem*>::iterator it = detectBusTreeWidgetItemList.begin(); it!=detectBusTreeWidgetItemList.end();it++)
		{
			if ((*it)->m_data.detector.byDetectorNo== data.detector.byDetectorNo)
			{
				detectorBusItem->removeChild((*it));
				detectBusTreeWidgetItemList.erase(it);
				break;		
			}
		}
	}else if (crtItem == detectorPedItem)
	{
		DetectorsPedestrainsData data = detectPedTableWidget->removeSelectedData();
		for (QList<DetectorPedTreeWdigetItem*>::iterator it = detectPedTreeWidgetItemList.begin(); it!=detectPedTreeWidgetItemList.end();it++)
		{
			if ((*it)->m_data.detector.byDetectorNo== data.detector.byDetectorNo)
			{
				detectorPedItem->removeChild((*it));
				detectPedTreeWidgetItemList.erase(it);
				break;		
			}
		}
	}else if (crtItem == periodItem)
	{
		PeriodData data = periodTableWidget->removeSelectedData();
		for (QList<PeriodTreeWidgetItem*>::iterator it = periodTreeWidgetItemList.begin(); it!=periodTreeWidgetItemList.end();it++)
		{
			if ((*it)->m_data.nId== data.nId)
			{
				periodItem->removeChild((*it));
				periodTreeWidgetItemList.erase(it);
				break;		
			}
		}
	}
}

void TreeWidget::updateSgProgDatasWithIntGrData(const InterGreenMatrixData &data, OptionType type)
{
	if (type==TreeWidget::Delete)
	{
		for (int i=0; i<m_signalProgs.size(); i++)
		{
			if (data.nId == m_signalProgs[i].nInterGreens)
			{
				m_signalProgs[i].nInterGreens = 0;
				break;
			}
		}
	}
	
}
void TreeWidget::sortSgItems()
{
	sgsItem->takeChildren();
	qSort(sgTreeWdigetItemLists.begin(),sgTreeWdigetItemLists.end(),sgTreeItemLessThan);
	for (int i=0; i<sgTreeWdigetItemLists.size(); i++)
	{
		sgsItem->addChild(sgTreeWdigetItemLists[i]);
	}
}
void TreeWidget::sortIntGrItems()
{
	interGreenMatrixsItem->takeChildren();
	qSort(intGreenTreeWidgetItemLists.begin(),intGreenTreeWidgetItemLists.end(),intGrTreeItemLessThan);
	for (int i=0; i<intGreenTreeWidgetItemLists.size(); i++)
	{
		interGreenMatrixsItem->addChild(intGreenTreeWidgetItemLists[i]);
	}
}
void TreeWidget::sortSgProgItems()
{
	signalProgsItem->takeChildren();
	qSort(sgProgTreeWidgetItemList.begin(),sgProgTreeWidgetItemList.end(),sgProgTreeItemLessThan);
	for (int i=0; i<sgProgTreeWidgetItemList.size(); i++)
	{
		signalProgsItem->addChild(sgProgTreeWidgetItemList[i]);
	}
}

void TreeWidget::sortSquenceItems()
{
	squenceItem->takeChildren();
	qSort(squenceTreeWidgetItemList.begin(),squenceTreeWidgetItemList.end(),squenceTreeItemLessThan);
	for (int i=0; i<squenceTreeWidgetItemList.size(); i++)
	{
		squenceItem->addChild(squenceTreeWidgetItemList[i]);
	}
}

void TreeWidget::sortDetectVehItems()
{
	detectorVehItem->takeChildren();
	qSort(detectVehTreeWidgetItemList.begin(),detectVehTreeWidgetItemList.end(),detectVehTreeItemLessThan);
	for (int i=0; i<detectVehTreeWidgetItemList.size(); i++)
	{
		detectorVehItem->addChild(detectVehTreeWidgetItemList[i]);
	}
}
void TreeWidget::sortDetectBusItems()
{
	detectorBusItem->takeChildren();
	qSort(detectBusTreeWidgetItemList.begin(),detectBusTreeWidgetItemList.end(),detectBusTreeItemLessThan);
	for (int i=0; i<detectBusTreeWidgetItemList.size(); i++)
	{
		detectorBusItem->addChild(detectBusTreeWidgetItemList[i]);
	}
}
void TreeWidget::sortDetectPedItems()
{
	detectorPedItem->takeChildren();
	qSort(detectPedTreeWidgetItemList.begin(),detectPedTreeWidgetItemList.end(),detectPedTreeItemLessThan);
	for (int i=0; i<detectPedTreeWidgetItemList.size(); i++)
	{
		detectorPedItem->addChild(detectPedTreeWidgetItemList[i]);
	}
}
void TreeWidget::sortTransItems()
{
	translationItem->takeChildren();
	qSort(transTreeWidgetItemList.begin(),transTreeWidgetItemList.end(),transTreeItemLessThan);
	for (int i=0; i<transTreeWidgetItemList.size(); i++)
	{
		translationItem->addChild(transTreeWidgetItemList[i]);
	}
}
void TreeWidget::sortPeriodItems()
{
	periodItem->takeChildren();
	qSort(periodTreeWidgetItemList.begin(),periodTreeWidgetItemList.end(),periodTreeItemLessThan);
	for (int i=0; i<periodTreeWidgetItemList.size(); i++)
	{
		periodItem->addChild(periodTreeWidgetItemList[i]);
	}
}

void TreeWidget::updateSgItemContentWithSort(SgData data)
{
	updateSgItemContent(data);
	sortSgItems();
}

void TreeWidget::updateSgProgItemContentWithSort(SignalProgData data)
{
	updateSgProgItemContent(data);
	sortSgProgItems();
}

void TreeWidget::updateSgItemContent(SgData data)
{
	for (int i=0; i<sgTreeWdigetItemLists.size(); i++)
	{
		if (sgTreeWdigetItemLists.at(i)->m_data.nPrimaryId == data.nPrimaryId)
		{
			sgTreeWdigetItemLists.at(i)->SetData(data);
			break;
		}
	}
	for (int i=0; i<m_sgsDatas.size(); i++)
	{
		if (m_sgsDatas[i].nPrimaryId == data.nPrimaryId)
		{
			m_sgsDatas[i] = data;
		}
	}
	//�����̼���������ʱ��������
// 	for (int i=0; i<m_signalProgs.size(); i++)
// 	{
// 		for (int j=0; j<m_signalProgs[i].sgDatasInProg.size(); j++)
// 		{
// 			if (data.nId == m_signalProgs[i].sgDatasInProg[j].nSgId)
// 			{
// 				m_signalProgs[i].sgDatasInProg[j].nSignalSequence = data.nDefaultSignalSequence;
// 				SetCmdAndFixState(m_signalProgs[i].sgDatasInProg[j]);		
// 
// 				for (int k=0; k<sgProgTreeWidgetItemList.size(); k++)
// 				{
// 					
// 					if (sgProgTreeWidgetItemList.at(i)->m_data.nPrimaryId == m_signalProgs[i].nPrimaryId)
// 					{
// 						sgProgTreeWidgetItemList.at(i)->SetData(m_signalProgs[i]);
// 					}
// 				}
// 			}
// 		}	
// 	}

}


void  TreeWidget::updateSgProgItemContent(SignalProgData data)
{
	for (int i=0; i<sgProgTreeWidgetItemList.size(); i++)
	{
		if (sgProgTreeWidgetItemList.at(i)->m_data.nPrimaryId == data.nPrimaryId)
		{
			sgProgTreeWidgetItemList.at(i)->SetData(data);
			break;
		}
	}

	for (int i=0; i<m_signalProgs.size(); i++)
	{
		if (m_signalProgs[i].nPrimaryId == data.nPrimaryId)
		{
			m_signalProgs[i] = data;
		}
	}
}

void TreeWidget::updateSquenceItemContent(SquenceData data)
{
	for (int i=0; i<squenceTreeWidgetItemList.size(); i++)
	{
		if (squenceTreeWidgetItemList.at(i)->m_data.nId == data.nId)
		{
			squenceTreeWidgetItemList.at(i)->SetData(data);
			break;
		}
	}

	for (int i=0; i<m_squenceDatas.size(); i++)
	{
		if (m_squenceDatas[i].nId == data.nId)
		{
			m_squenceDatas[i] = data;
		}
	}
}

void TreeWidget::updateTransItemContent(TranslationPlanData data)
{
	for (int i=0; i<transTreeWidgetItemList.size(); i++)
	{
		if (transTreeWidgetItemList.at(i)->m_data.translationPlan.byTransitionPlanNo == data.translationPlan.byTransitionPlanNo)
		{
			transTreeWidgetItemList.at(i)->SetData(data);
			break;
		}
	}

	for (int i=0; i<m_translationDatas.size(); i++)
	{
		if (m_translationDatas[i].translationPlan.byTransitionPlanNo == data.translationPlan.byTransitionPlanNo)
		{
			m_translationDatas[i] = data;
		}
	}
}

void TreeWidget::updateDetectVehItemContent(DetectorVehicleData data)
{
	for (int i=0; i<detectVehTreeWidgetItemList.size(); i++)
	{
		if (detectVehTreeWidgetItemList.at(i)->m_data.detector.byDetectorNo== data.detector.byDetectorNo)
		{
			detectVehTreeWidgetItemList.at(i)->SetData(data);
			break;
		}
	}

	for (int i=0; i<m_detectorVehicleDatas.size(); i++)
	{
		if (m_detectorVehicleDatas[i].detector.byDetectorNo == data.detector.byDetectorNo)
		{
			m_detectorVehicleDatas[i] = data;
		}
	}
}

void TreeWidget::updateDetectBusItemContent(DetectorBusData data)
{
	for (int i=0; i<detectBusTreeWidgetItemList.size(); i++)
	{
		if (detectBusTreeWidgetItemList.at(i)->m_data.detector.byDetectorNo== data.detector.byDetectorNo)
		{
			detectBusTreeWidgetItemList.at(i)->SetData(data);
			break;
		}
	}

	for (int i=0; i<m_detectorBusDatas.size(); i++)
	{
		if (m_detectorBusDatas[i].detector.byDetectorNo == data.detector.byDetectorNo)
		{
			m_detectorBusDatas[i] = data;
		}
	}
}

void TreeWidget::updateDetectPedItemContent(DetectorsPedestrainsData data)
{
	for (int i=0; i<detectPedTreeWidgetItemList.size(); i++)
	{
		if (detectPedTreeWidgetItemList.at(i)->m_data.detector.byDetectorNo== data.detector.byDetectorNo)
		{
			detectPedTreeWidgetItemList.at(i)->SetData(data);
			break;
		}
	}

	for (int i=0; i<m_detectorPedestainsDatas.size(); i++)
	{
		if (m_detectorPedestainsDatas[i].detector.byDetectorNo == data.detector.byDetectorNo)
		{
			m_detectorPedestainsDatas[i] = data;
		}
	}
}

void TreeWidget::updatePeriodItemContent(PeriodData data)
{
	for (int i=0; i<periodTreeWidgetItemList.size(); i++)
	{
		if (periodTreeWidgetItemList.at(i)->m_data.nId== data.nId)
		{
			periodTreeWidgetItemList.at(i)->SetData(data);
			break;
		}
	}

	for (int i=0; i<m_periodDatas.size(); i++)
	{
		if (m_periodDatas[i].nId== data.nId)
		{
			m_periodDatas[i] = data;
		}
	}
}


void TreeWidget::updateIntGrItemContentWithSort(InterGreenMatrixData data)
{
	updateIntGrItemContent(data);
	sortIntGrItems();
}

void TreeWidget::updateIntGrItemContent(InterGreenMatrixData data)
{
	for (int i=0; i<intGreenTreeWidgetItemLists.size(); i++)
	{
		if (intGreenTreeWidgetItemLists.at(i)->m_data.nPrimaryId == data.nPrimaryId)
		{
			intGreenTreeWidgetItemLists.at(i)->SetData(data);
			break;
		}
	}
	for (int i=0; i<m_interGreenMatrixs.size(); i++)
	{
		if (m_interGreenMatrixs[i].nPrimaryId == data.nPrimaryId)
		{
			m_interGreenMatrixs[i] = data;
		}
	}
}

void TreeWidget::SaveDataFromUI()
{
	//�������κβ���������
}

void TreeWidget::UpdateDataToUI()
{
	sgsItem->takeChildren();		//��������ӽڵ�
	interGreenMatrixsItem->takeChildren();
	signalProgsItem->takeChildren();
	squenceItem->takeChildren();
	translationItem->takeChildren();
	detectorVehItem->takeChildren();
	detectorBusItem->takeChildren();
	detectorPedItem->takeChildren();
	periodItem->takeChildren();

	sgTreeWdigetItemLists.clear();//����ӽڵ�list
	intGreenTreeWidgetItemLists.clear();
	sgProgTreeWidgetItemList.clear();

	squenceTreeWidgetItemList.clear();
	detectVehTreeWidgetItemList.clear();
	detectBusTreeWidgetItemList.clear();
	detectPedTreeWidgetItemList.clear();
	transTreeWidgetItemList.clear();
	periodTreeWidgetItemList.clear();

	//��������id����Ҫ������0,��Ϊ�ڶ�ȡxmlʱ���Ѿ���ÿ�����ݶ�ָ����һ��nPrimaryId��
// 	m_nSgDataPrimaryID = 0;
// 	m_nIntGrDataPrimaryID = 0;
// 	m_nSgProgDataPrimaryID = 0;

	//1.��ӵ������ݵ����ڵ�
	for (int i=0; i<m_sgsDatas.size(); i++)
	{
		SgTreeWidgetItem *item = new SgTreeWidgetItem(m_sgsDatas[i], sgsItem);
		sgTreeWdigetItemLists<<item;	//������ӵ����ڵ�
	}

	//2.����̵Ƽ����������ڵ�
	for (int i=0; i<m_interGreenMatrixs.size(); i++)
	{
		IntGreenTreeWidgetItem *item = new IntGreenTreeWidgetItem(m_interGreenMatrixs[i], interGreenMatrixsItem);
		//������ʱ�����е��̵Ƽ��������,ֻ��Ҫ�����̵Ƽ�����ݼ���
		intGreenTreeWidgetItemLists<<item;
	}

	//3.�����ʱ�������̵Ƽ����������ڵ�
	for (int i=0; i<m_signalProgs.size(); i++)
	{
		SgProgTreeWidgetItem *item = new SgProgTreeWidgetItem(m_signalProgs[i], signalProgsItem);
		sgProgTreeWidgetItemList<<item;
	}

	//4.��ӵ������ڵ�
	for (int i=0; i<m_squenceDatas.size(); i++)
	{
		SquenceTreeWidgetItem *item = new SquenceTreeWidgetItem(m_squenceDatas[i], squenceItem);
		squenceTreeWidgetItemList<<item;
	}

	//5.��ӹ�����������ڵ�
	for (int i=0; i<m_detectorVehicleDatas.size(); i++)
	{
		DetectorVehicleTreeWidgetItem *item = new DetectorVehicleTreeWidgetItem(m_detectorVehicleDatas[i], detectorVehItem);
		detectVehTreeWidgetItemList<<item;
	}
	//6.��ӹ�����������ڵ�
	for (int i=0; i<m_detectorBusDatas.size(); i++)
	{
		DetectorBusTreeWidgetItem *item = new DetectorBusTreeWidgetItem(m_detectorBusDatas[i], detectorBusItem);
		detectBusTreeWidgetItemList<<item;
	}
	//7.������˼�������ڵ�
	for (int i=0; i<m_detectorPedestainsDatas.size(); i++)
	{
		DetectorPedTreeWdigetItem *item = new DetectorPedTreeWdigetItem(m_detectorPedestainsDatas[i], detectorPedItem);
		detectPedTreeWidgetItemList<<item;
	}
	//8.��ӹ��ɷ������ڵ�
	for (int i=0; i<m_translationDatas.size(); i++)
	{
		TransTreeWidgetItem *item = new TransTreeWidgetItem(m_translationDatas[i], translationItem);
		transTreeWidgetItemList<<item;
	}
	//9.��ӹ��ɷ������ڵ�
	for (int i=0; i<m_periodDatas.size(); i++)
	{
		PeriodTreeWidgetItem *item = new PeriodTreeWidgetItem(m_periodDatas[i], periodItem);
		periodTreeWidgetItemList<<item;
	}

	//��tablewidget����updatedatatoui��
	sgnlsTableWidget->updateDataToUI();
	intGreenTableWidget->updateDataToUI();
	sgProgTableWidget->updateDataToUI();

	squenceTableWidget->updateDataToUI();
	detectVehTableWidget->updateDataToUI();
	detectBusTableWidget->updateDataToUI();
	detectPedTableWidget->updateDataToUI();
	periodTableWidget->updateDataToUI();
	transTableWidget->updateDataToUI();

	this->setCurrentItem(sgsItem);
}

TreeWidget::~TreeWidget()
{

}
