
#include "mainwindow.h"
#include <QSplitter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),addr(0),port(0)
{
    ui.setupUi(this);

	QWidget *pCentWidget = new QWidget;		//中心窗口
	QSplitter *splitterMain = new QSplitter(Qt::Horizontal, pCentWidget);

    treeWdiget = new TreeWidget(m_sgsDatas, m_scData, m_interGreenMatrixs, m_signalProgs,
		m_squenceDatas, m_detectorVehicleDatas, m_detectorBusDatas, m_detectorPedestainsDatas,
		m_translationDatas, m_periodDatas,	splitterMain);
   

    //信号灯组widget
    sgnlsTableWidget = new SgsTableWidget(m_sgsDatas);

    //绿间隔矩阵widget
    intGreenMatrixTableWidget = new IntGrMtrxTableWidget(m_interGreenMatrixs);
	
    //信号灯配时方案widget
    sgProgTableWidget = new SignalProgTableWidget(m_signalProgs);

	squenceTableWidget = new SquenceTableWidget(m_squenceDatas);

	QVector<DetectorVehicleData> vehDatas;
	QVector<DetectorBusData> busDatas;
	QVector<DetectorsPedestrainsData> pedDatas;
	detectVehTableWidget = new DetectorTableWidget<DetectorVehicleData>(m_detectorVehicleDatas,m_detectorVehicleDatas,busDatas, pedDatas, Veh);
 	detectBusTableWidget = new DetectorTableWidget<DetectorBusData>(m_detectorBusDatas, vehDatas, m_detectorBusDatas, pedDatas, Bus);
 	detectPedTableWidget = new DetectorTableWidget<DetectorsPedestrainsData>(m_detectorPedestainsDatas, vehDatas, busDatas, m_detectorPedestainsDatas, Ped);
	periodTableWidget = new PeriodTableWidget(m_periodDatas);
	transTableWidget = new TransTableWidget(m_translationDatas);


	//信号灯信息窗口
	signalWidget = new SignalWidget;
	//绿间隔矩阵信息窗口
	pGreenIntMatrixWidget = new GreenIntMatrixWidget; 
	//配时方案信息窗口
	pSgProgWidget = new SgProgWidget(m_sgsDatas, m_interGreenMatrixs, m_squenceDatas);

	psquenceWidget = new SequenceWidget;
	pTransWidget = new TransWidget;
	pDetectVehWidget = new DetectorWidget(Veh);
	pDetectBusWidget = new DetectorWidget(Bus);
	pDetectPedWidget = new DetectorWidget(Ped);
	pPeriodWidget = new PeriodWidget;
	pScWidget = new ScWidget(m_scData);
	 pScWidget->updateDataToUI();

    stackWidget = new QStackedWidget(splitterMain);
    stackWidget->addWidget(sgnlsTableWidget);
    stackWidget->addWidget(intGreenMatrixTableWidget);
    stackWidget->addWidget(sgProgTableWidget);
	stackWidget->addWidget(signalWidget);
	stackWidget->addWidget(pGreenIntMatrixWidget);
	stackWidget->addWidget(pSgProgWidget);
	stackWidget->addWidget(pScWidget);
	stackWidget->addWidget(squenceTableWidget);
	stackWidget->addWidget(detectVehTableWidget);
	stackWidget->addWidget(detectBusTableWidget);
	stackWidget->addWidget(detectPedTableWidget);
	stackWidget->addWidget(periodTableWidget);
	stackWidget->addWidget(transTableWidget);
	stackWidget->addWidget(psquenceWidget);
	stackWidget->addWidget(pTransWidget);
	stackWidget->addWidget(pDetectVehWidget);
	stackWidget->addWidget(pDetectBusWidget);
	stackWidget->addWidget(pDetectPedWidget);
	stackWidget->addWidget(pPeriodWidget);

	stackWidget->setCurrentWidget(pScWidget);

	treeWdiget->setSgsTableWidget(sgnlsTableWidget);
	treeWdiget->setIntGreenTableWidget(intGreenMatrixTableWidget);
	treeWdiget->setSgProgTableWidget(sgProgTableWidget);
	treeWdiget->setDetectVehTableWidget(detectVehTableWidget);
	treeWdiget->setDetectBusTableWidget(detectBusTableWidget);
	treeWdiget->setDetectPedTableWidget(detectPedTableWidget);
	treeWdiget->setSquenceTableWidget(squenceTableWidget);
	treeWdiget->setTransTableWidget(transTableWidget);
	treeWdiget->setPeriodTableWidget(periodTableWidget);


	splitterMain->setStretchFactor(1,3);
    QHBoxLayout *mainLayout = new QHBoxLayout(pCentWidget);
  //  mainLayout->addWidget(treeWdiget);
  //  mainLayout->addWidget(stackWidget);
	mainLayout->addWidget(splitterMain);
//     mainLayout->setStretchFactor(treeWdiget, 1);
//     mainLayout->setStretchFactor(stackWidget,3);
    this->setCentralWidget(pCentWidget);

	setActionVisible(false);

	m_tcpSocket = new QTcpSocket(this);
	connect(m_tcpSocket, SIGNAL(connected()),this, SLOT(connected()));
	connect(m_tcpSocket, SIGNAL(disconnected()),this, SLOT(disconnected()));
	connect(m_tcpSocket, SIGNAL(readyRead()),this, SLOT(readyRead()));


	//添加按钮信号槽
	connect(ui.actionAdd, SIGNAL(triggered()), treeWdiget, SLOT(addItem()));
	connect(ui.actionDelete, SIGNAL(triggered()), treeWdiget, SLOT(delItem()));
	connect(ui.actionCopy, SIGNAL(triggered()), treeWdiget, SLOT(copyItem()));
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
	connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(saveVISSIMFile()));
	connect(ui.actionSave_As, SIGNAL(triggered()), this, SLOT(saveAsVISSIMFile()));
	connect(ui.localFileSaveAction, SIGNAL(triggered()), this, SLOT(saveVISSIMFile()));
	connect(ui.localFileSaveAsAction, SIGNAL(triggered()), this, SLOT(saveAsVISSIMFile()));
	connect(ui.netFrontAction, SIGNAL(triggered()), this, SLOT(netFrontConfig()));
	connect(ui.aboutAction, SIGNAL(triggered()), this, SLOT(aboutDlg()));

	connect(ui.downLoadAction, SIGNAL(triggered()), this, SLOT(downLoadData()));
	connect(ui.upLoadAction, SIGNAL(triggered()), this, SLOT(upLoadData()));

	connect(ui.saveDefAction, SIGNAL(triggered()), this, SLOT(saveDefFun()));
	connect(ui.loadDefAction, SIGNAL(triggered()), this, SLOT(loadDefFun()));

	connect(treeWdiget, SIGNAL(updateSgsTable()), sgnlsTableWidget, SLOT(updateDataToUI()));
	connect(treeWdiget, SIGNAL(updateIntGrMtrxTable()), intGreenMatrixTableWidget, SLOT(updateDataToUI()));				//更新绿灯间隔矩阵的记录
	connect(treeWdiget, SIGNAL(updateSgProgTable()), sgProgTableWidget, SLOT(updateDataToUI()));
	connect(treeWdiget, SIGNAL(updateSquenceTable()), squenceTableWidget, SLOT(updateDataToUI()));
	connect(treeWdiget, SIGNAL(updatetranslationTable()), transTableWidget, SLOT(updateDataToUI()));
	connect(treeWdiget, SIGNAL(updateDetectVehTable()), detectVehTableWidget, SLOT(updateDataToUI()));
	connect(treeWdiget, SIGNAL(updateDetectBusTable()), detectBusTableWidget, SLOT(updateDataToUI()));
	connect(treeWdiget, SIGNAL(updateDetectPedTable()), detectPedTableWidget, SLOT(updateDataToUI()));
	connect(treeWdiget, SIGNAL(updatePeriodTable()), periodTableWidget, SLOT(updateDataToUI()));
		
	
	connect(treeWdiget, SIGNAL(updateSgInfo(SgData &)), this, SLOT(updateSgDataToUI(SgData &)));
	connect(treeWdiget, SIGNAL(updateIntGrInfo(InterGreenMatrixData &)), this, SLOT(updateIntGrMtrxToUI(InterGreenMatrixData &)));
	connect(treeWdiget, SIGNAL(updateSgProgInfo(SignalProgData &)), this, SLOT(updateSgProgToUI(SignalProgData &)));
	connect(treeWdiget, SIGNAL(updateSquenceInfo(SquenceData &)), this, SLOT(updateSquenceDataToUI(SquenceData &)));
	connect(treeWdiget, SIGNAL(updateTransInfo(TranslationPlanData &)), this, SLOT(updateTransToUI(TranslationPlanData &)));
	connect(treeWdiget, SIGNAL(updateDetectVehInfo(DetectorVehicleData &)), this, SLOT(updateDectVehToUI(DetectorVehicleData &)));
	connect(treeWdiget, SIGNAL(updateDetectBusInfo(DetectorBusData &)), this, SLOT(updateDectBusToUI(DetectorBusData &)));
	connect(treeWdiget, SIGNAL(updateDetectPedInfo(DetectorsPedestrainsData &)), this, SLOT(updateDectPedToUI(DetectorsPedestrainsData &)));
	connect(treeWdiget, SIGNAL(updatePeriodInfo(PeriodData &)), this, SLOT(updatePeriodToUI(PeriodData &)));

	//选中节点，显示列表页面
	connect(treeWdiget, SIGNAL(sgsItemSelected()), this, SLOT(sgWdigetSelected()));
	connect(treeWdiget, SIGNAL(intGrMatrxItemSelected()), this, SLOT(intGrWdigetSelected()));
	connect(treeWdiget, SIGNAL(sgProgsItemSelected()), this, SLOT(sgProgWdigetSelected()));

	connect(treeWdiget, SIGNAL(squenceItemSelected()), this, SLOT(squenceWdigetSelected()));
	connect(treeWdiget, SIGNAL(detectVehItemSelected()), this, SLOT(detectVehWidgetSelected()));
	connect(treeWdiget, SIGNAL(detectBusItemSelected()), this, SLOT(detectBusWidgetSelected()));
	connect(treeWdiget, SIGNAL(detectPedItemSelected()), this, SLOT(detectPedWidgetSelected()));
	connect(treeWdiget, SIGNAL(transItemSelected()), this, SLOT(transWidgetSelected()));
	connect(treeWdiget, SIGNAL(periodItemSelected()), this, SLOT(periodWidgetSelected()));
	

	connect(treeWdiget, SIGNAL(rootItemClicked()), this, SLOT(showScData()));

	connect(sgnlsTableWidget, SIGNAL(cellChanged(SgData)), treeWdiget, SLOT(updateSgItemContentWithSort(SgData )));
	connect(sgnlsTableWidget, SIGNAL(CellDoubleClicked(SgData & )), this, SLOT(updateSgDataToUI(SgData &)));

	connect(signalWidget, SIGNAL(dataChanged(SgData )), treeWdiget, SLOT(updateSgItemContent(SgData )));
	connect(pSgProgWidget, SIGNAL(sgProgDataChanged(SignalProgData)), treeWdiget, SLOT(updateSgProgItemContent(SignalProgData)));
	connect(psquenceWidget, SIGNAL(squenceDataChanged(SquenceData)), treeWdiget, SLOT(updateSquenceItemContent(SquenceData)));
	connect(pTransWidget, SIGNAL(TransDataChanged(TranslationPlanData)), treeWdiget, SLOT(updateTransItemContent(TranslationPlanData)));
	connect(pDetectVehWidget, SIGNAL(detectVehDataChanged(DetectorVehicleData)), treeWdiget, SLOT(updateDetectVehItemContent(DetectorVehicleData)));
	connect(pDetectBusWidget, SIGNAL(detectBusDataChanged(DetectorBusData)), treeWdiget, SLOT(updateDetectBusItemContent(DetectorBusData)));
	connect(pDetectPedWidget, SIGNAL(detectPedDataChanged(DetectorsPedestrainsData)), treeWdiget, SLOT(updateDetectPedItemContent(DetectorsPedestrainsData)));
	connect(pPeriodWidget, SIGNAL(PeriodDataChanged(PeriodData)), treeWdiget, SLOT(updatePeriodItemContent(PeriodData)));

	connect(sgProgTableWidget, SIGNAL(cellChanged(SignalProgData )), treeWdiget, SLOT(updateSgProgItemContentWithSort(SignalProgData)));
	connect(sgProgTableWidget, SIGNAL(CellDoubleClicked(SignalProgData &)), this, SLOT(updateSgProgToUI(SignalProgData&)));

	connect(intGreenMatrixTableWidget, SIGNAL(CellDoubleClicked(InterGreenMatrixData & )), this, SLOT(updateIntGrMtrxToUI(InterGreenMatrixData &)));
	connect(intGreenMatrixTableWidget, SIGNAL(cellChanged(InterGreenMatrixData)), treeWdiget, SLOT(updateIntGrItemContentWithSort(InterGreenMatrixData)));
	connect(pGreenIntMatrixWidget, SIGNAL(dataChanged(InterGreenMatrixData )), treeWdiget, SLOT(updateIntGrItemContent(InterGreenMatrixData )));
	
	connect(squenceTableWidget, SIGNAL(CellDoubleClicked(SquenceData & )), this, SLOT(updateSquenceDataToUI(SquenceData &)));
 	connect(detectVehTableWidget, SIGNAL(VehCellDoubleClicked(DetectorVehicleData & )), this, SLOT(updateDectVehToUI(DetectorVehicleData &)));
 	connect(detectBusTableWidget, SIGNAL(BusCellDoubleClicked(DetectorBusData & )), this, SLOT(updateDectBusToUI(DetectorBusData &)));
 	connect(detectPedTableWidget, SIGNAL(PedCellDoubleClicked(DetectorsPedestrainsData& )), this, SLOT(updateDectPedToUI(DetectorsPedestrainsData &)));
 	connect(transTableWidget, SIGNAL(CellDoubleClicked(TranslationPlanData & )), this, SLOT(updateTransToUI(TranslationPlanData &)));
 	connect(periodTableWidget, SIGNAL(PeriodCellDoubleClicked(PeriodData & )), this, SLOT(updatePeriodToUI(PeriodData &)));

	isConn = false;

	timer = new QTimer(this);

	connect(timer, SIGNAL(timeout()), this, SLOT(freshStatusBar()));
	timer->start(8000);
	label = new QLabel(QString("no connection!"));
	this->statusBar()->addWidget(label);

	verLabel = new QLabel(QString("version:"));
	this->statusBar()->addWidget(verLabel);
}

void MainWindow::connected()
{
	qDebug() << "connected IP:"<<ip<<" PORT:"<<TCPPORT;
	QMessageBox::information(this, "Info",ip+" connected");
	isConn = true;
}

void MainWindow::disconnected()
{
	qDebug() << "disconnected IP:"<<ip<<" PORT"<<TCPPORT;
	QMessageBox::information(this, "Info",ip+" disconnected");
	isConn = false;
}


void MainWindow::readyRead()
{
	
	datagram.append(m_tcpSocket->readAll());
	if (datagram[datagram.size()-1]=='>')
	{
		qDebug() << "reading data:"<<datagram.toHex().data();
		type_fun_conf conf;
		quint32 id_fun=0;
		int sta = do_fram((quint8*)datagram.data(), datagram.size(), conf, id_fun);

		if(sta<0)
		{
			qCritical()<<QString::fromLocal8Bit("信号机数据解析失败\n");
			return;
		}else
		{
			qCritical()<<QString::fromLocal8Bit("信号机数据解析成功!\n");
		}
		//心跳判断
		if( id_fun==FUN_VERSION)	//需要添加异常判断
		{
			qCritical()<<QString::fromLocal8Bit("解析报文知收到为版本号报文：Rev Heart(Version) Msg \n");
			verLabel->setText(QString::fromLocal8Bit("<font color=blue>信号机版本：%1.%2.%3 build_time:%4</font>").arg(conf.version.ver_master)
				.arg(conf.version.ver_slave).arg(conf.version.ver_revise).arg((char*)conf.version.build_time));
		}

		//上载参数
		if (sta==CTRL_RD && id_fun==FUN_MATRIX)		//因为上下载时最后一个数据是FUN_MATRIX的数据
		{
			qCritical()<<"Rev  Plan Data(Red)\n";
			QString errionfo="";	
			streamDataToLocalData(m_sgsDatas, m_interGreenMatrixs, m_signalProgs,
				m_squenceDatas, m_detectorVehicleDatas,m_detectorBusDatas,
				m_detectorPedestainsDatas,m_translationDatas,m_periodDatas , conf, errionfo);
			UpdateDataToUI();
			if (errionfo!="")
			{
				label->setText(QString::fromLocal8Bit("<h2><font color=red>上载成功,但是存在警告：")+errionfo+QString::fromLocal8Bit("</font></h2>"));
			}else
			{
				label->setText(QString::fromLocal8Bit("上载成功"));
			}
			qCritical()<<QString::fromLocal8Bit("上载成功\n");
			QMessageBox::information(this, "infor", QString::fromLocal8Bit("上载成功！"));
		}

		//下载参数流程是，下发流，信号机收到后原数返回，收到返回后，算下载成功。
		//下载参数成功后，需要下发保存参数命令，等保存成功后，才算完全成功。
		if (sta==CTRL_SET && id_fun==FUN_MATRIX)
		{
			label->setText(QString::fromLocal8Bit("下载成功, 发送保存参数命令"));
			qCritical()<<QString::fromLocal8Bit("下载成功, 发送保存参数命令\n");
			SetSaveDataMsg();
			if (m_tcpSocket->write((char*)data, msg_len)>0)
			{
				qCritical()<<"Down Save Data Request to ip("<<ip<<":"<<TCPPORT<<"):"<<QByteArray((char*)data, msg_len).toHex().data()<<"\n";
			}
		}
		if (sta == CTRL_SAVE_CONF)
		{
			label->setText(QString::fromLocal8Bit("保存参数完成，下载成功"));
			qCritical()<<QString::fromLocal8Bit("保存参数完成，下载成功\n");
			QMessageBox::information(this, "infor", QString::fromLocal8Bit("下载成功！"));
		}
		datagram.clear();
	}
}

void MainWindow::aboutDlg()
{
	QMessageBox::about(NULL, QString::fromLocal8Bit("关于"), QString::fromLocal8Bit("版本号：v2.0.5"));
}

void MainWindow::saveDefFun()
{
	SaveDataFromUI();//保存数据
	localDataToStreamData(m_sgsDatas, m_interGreenMatrixs, m_signalProgs, 
		m_squenceDatas, m_detectorVehicleDatas,m_detectorBusDatas,
		m_detectorPedestainsDatas,m_translationDatas,m_periodDatas,m_type_fun_data);
	//char *datas = new char[MAX_PROTOCOL_BYTE];
	char datas[MAX_PROTOCOL_BYTE];
	memset(datas, 0, MAX_PROTOCOL_BYTE);
	memcpy(datas, &m_type_fun_data, sizeof(m_type_fun_data));
	ofstream out;
	out.open("default", ofstream::out);
	if (out)
	{
		out.write(datas, sizeof(m_type_fun_data));
		out.close();
	}
//	delete datas;
}

void MainWindow::loadDefFun()
{
	ifstream in;
//	char *datas = new char[MAX_PROTOCOL_BYTE];
	char datas[MAX_PROTOCOL_BYTE];
	memset(datas, 0, MAX_PROTOCOL_BYTE);
	in.open("default", ofstream::in);
	if (in)
	{
		in.read(datas, sizeof(m_type_fun_data));
		in.close();
	}
	memcpy(&m_type_fun_data, datas, sizeof(m_type_fun_data));
	QString errionfo;
	streamDataToLocalData(m_sgsDatas, m_interGreenMatrixs, m_signalProgs,
		m_squenceDatas, m_detectorVehicleDatas,m_detectorBusDatas,
		m_detectorPedestainsDatas,m_translationDatas,m_periodDatas , m_type_fun_data, errionfo);
	UpdateDataToUI();

	//delete datas;
}




void MainWindow::freshStatusBar()
{
	if (isConn)
	{
		label->setText(QString("IP:%1  Port:%2").arg(ip).arg(port));
	}else
	{
		label->setText(QString("no connection!"));
	}
}


bool MainWindow::newconnect()
{
	if(m_tcpSocket->state()==QAbstractSocket::ConnectedState)
	{
		qCritical()<<"TCP is not connected, disconnect and connect again";
		m_tcpSocket->close();
	}
	//ip = "127.0.0.1";
	m_tcpSocket->connectToHost(ip, TCPPORT);
	// we need to wait...
	if(!m_tcpSocket->waitForConnected(5000))
	{
		qDebug() << "Error: " << m_tcpSocket->errorString();
		QMessageBox::warning(this, "ERROR", m_tcpSocket->errorString());
		return false;
	}else
		return true;
}

void MainWindow::netFrontConfig()
{
	ip = "";
	addr=0;
	QDlgNetConfigFront dlg(ip, port);
	dlg.exec();
	addr = dlg.getAddr();
	if (!ip.isEmpty()&&addr!=0)
	{
		newconnect();
		treeWdiget->setRootName(ip);
		port = TCPPORT;
	}
}


void MainWindow::setActionVisible(bool bVisible)
{
	ui.actionAdd->setVisible(bVisible);
	ui.actionDelete->setVisible(bVisible);
	ui.actionCopy->setVisible(bVisible);
	ui.actionEdit->setVisible(bVisible);
}

void MainWindow::updateSgDataToUI(SgData &data)
{
	stackWidget->setCurrentWidget(signalWidget);
	signalWidget->setData(data);
	setActionVisible(false);
}

void MainWindow::updateSgProgToUI(SignalProgData &data)
{
	stackWidget->setCurrentWidget(pSgProgWidget);
	pSgProgWidget->setData(data);
	setActionVisible(false);
}

void MainWindow::updateSquenceDataToUI(SquenceData &data)
{
	stackWidget->setCurrentWidget(psquenceWidget);
	psquenceWidget->setData(data, m_sgsDatas);
	setActionVisible(false);
}

void MainWindow::updateDectVehToUI(DetectorVehicleData &data)
{
	stackWidget->setCurrentWidget(pDetectVehWidget);
	pDetectVehWidget->setData(data, m_sgsDatas);
	setActionVisible(false);
}

void MainWindow::updateDectBusToUI(DetectorBusData &data)
{
	stackWidget->setCurrentWidget(pDetectBusWidget);
	pDetectBusWidget->setData(data, m_sgsDatas);
	setActionVisible(false);
}


void MainWindow::updateDectPedToUI(DetectorsPedestrainsData &data)
{
	stackWidget->setCurrentWidget(pDetectPedWidget);
	pDetectPedWidget->setData(data, m_sgsDatas);
	setActionVisible(false);
}

void MainWindow::updatePeriodToUI(PeriodData &data)
{
	stackWidget->setCurrentWidget(pPeriodWidget);
	pPeriodWidget->setData(data, m_translationDatas, m_signalProgs);
	setActionVisible(false);
}


void MainWindow::updateTransToUI(TranslationPlanData &data)
{
	stackWidget->setCurrentWidget(pTransWidget);
	pTransWidget->setData(data, m_sgsDatas);
	setActionVisible(false);
}

void MainWindow::updateIntGrMtrxToUI(InterGreenMatrixData &data)
{
	//显示间隔信息
	stackWidget->setCurrentWidget(pGreenIntMatrixWidget);
	pGreenIntMatrixWidget->setData(data, m_sgsDatas);
	setActionVisible(false);
}
void MainWindow::SetPlanStreamData(type_fun_conf &funConfig, quint8 ctrl)
{
	int  sizeconf = sizeof(funConfig);
	type_frame_head frame_head;
	frame_head.head='<';
	frame_head.total_size = sizeof(frame_head.reserve)+sizeof(frame_head.addr)+sizeof(frame_head.ctrl)+sizeof(frame_head.type_fun)
										+1
										+(sizeof(type_protocol_plan)+2)+(sizeof(type_protocol_period)+2)+(sizeof(type_protocol_transitionPlan)+2)
										+(sizeof(type_protocol_sequence)+2)+(sizeof(type_pedestrain_detetcor)+2)+(sizeof(type_bus_detetcor)+2)
										+(sizeof(type_vehicle_detetcor)+2)+(sizeof(type_protocol_matrices)+2);
	frame_head.addr=addr;		
	frame_head.ctrl=ctrl;	
	frame_head.type_fun=0x55;	//type_fun该怎么填--预留
	quint8 *p = (quint8 *)data;

	memset(data, 0, sizeof(data));
	msg_len=0;

	memcpy(data, &frame_head, sizeof(frame_head)-1);
	p = p + sizeof(frame_head)-1;
	*p++ = 8;			//Unit 个数
	int unit_len = sizeof(type_protocol_plan);
	memcpy(p, &unit_len, 2);	//设置第一个Unit长度
	p+=2;
	memcpy(p, &funConfig.plan, sizeof(type_protocol_plan));
	p+=sizeof(type_protocol_plan);

	unit_len = sizeof(type_protocol_period);
	memcpy(p, &unit_len, 2);	//设置第2个Unit长度
	p+=2;
	memcpy(p, &funConfig.period, sizeof(type_protocol_period));
	p+=sizeof(type_protocol_period);

	unit_len = sizeof(type_protocol_transitionPlan);
	memcpy(p, &unit_len, 2);	//设置第3个Unit长度
	p+=2;
	memcpy(p, &funConfig.plan_tran, sizeof(type_protocol_transitionPlan));
	p+=sizeof(type_protocol_transitionPlan);

	unit_len = sizeof(type_protocol_sequence);
	memcpy(p, &unit_len, 2);	//设置第4个Unit长度
	p+=2;
	memcpy(p, &funConfig.ph_seq, sizeof(type_protocol_sequence));
	p+=sizeof(type_protocol_sequence);

	unit_len = sizeof(type_pedestrain_detetcor);
	memcpy(p, &unit_len, 2);	//设置第4个Unit长度
	p+=2;
	memcpy(p, &funConfig.dec_ped, sizeof(type_pedestrain_detetcor));
	p+=sizeof(type_pedestrain_detetcor);

	unit_len = sizeof(type_bus_detetcor);
	memcpy(p, &unit_len, 2);	//设置第4个Unit长度
	p+=2;
	memcpy(p, &funConfig.dec_bus, sizeof(type_bus_detetcor));
	p+=sizeof(type_bus_detetcor);

	unit_len = sizeof(type_vehicle_detetcor);
	memcpy(p, &unit_len, 2);	//设置第4个Unit长度
	p+=2;
	memcpy(p, &funConfig.dec_veh, sizeof(type_vehicle_detetcor));
	p+=sizeof(type_vehicle_detetcor);

	unit_len = sizeof(type_protocol_matrices);
	memcpy(p, &unit_len, 2);	//设置第4个Unit长度
	p+=2;
	memcpy(p, &funConfig.matrices, sizeof(type_protocol_matrices));
	p+=sizeof(type_protocol_matrices);
	
	int len_sum = frame_head.total_size + sizeof(frame_head.head)+sizeof(frame_head.total_size);
	quint16 sum = check_sum(data, len_sum);
	memcpy(p, &sum, 2);
	p+=2;
	*p='>';
	msg_len = frame_head.total_size +sizeof(frame_head.head)+sizeof(frame_head.total_size)+ 2 +1;
}

void MainWindow::downLoadData()
{
	SaveDataFromUI();//保存数据
	localDataToStreamData(m_sgsDatas, m_interGreenMatrixs, m_signalProgs, 
		m_squenceDatas, m_detectorVehicleDatas,m_detectorBusDatas,
		m_detectorPedestainsDatas,m_translationDatas,m_periodDatas,m_type_fun_data);
	SetPlanStreamData(m_type_fun_data, CTRL_SET);

	int verSize = sizeof(type_version);
	int addSize = sizeof(type_addr_conf);
	int planSize = sizeof(type_protocol_plan);
	int periodSize = sizeof(type_protocol_period);

	int tranSize = sizeof(type_protocol_transitionPlan);
	int sqenceSize = sizeof(type_protocol_sequence);
	int detPedSize = sizeof(type_pedestrain_detetcor);
	int detBusSize = sizeof(type_bus_detetcor);
	int detVehSize = sizeof(type_vehicle_detetcor);
	int mtrixSize = sizeof(type_protocol_matrices);
	int total = verSize + addSize + planSize + periodSize + tranSize + sqenceSize + detPedSize + 
		detBusSize + detVehSize + mtrixSize;

	//发送
	if(m_tcpSocket->write((char*)data, msg_len)>0)
	{
		qCritical()<<"Down Load Data Request to ip("<<ip<<":"<<TCPPORT<<"):"<<QByteArray((char*)data, msg_len).toHex().data()<<"\n";
	}else
	{
		qCritical()<<"Fail to Down Load Data Request to ip("<<ip<<":"<<TCPPORT<<"):"<<QByteArray((char*)data, msg_len).toHex().data()<<"\n";
	}

}

void MainWindow::SetSaveDataMsg()
{
	type_frame_head frame_head;
	frame_head.head='<';
	frame_head.total_size = sizeof(frame_head.reserve)+sizeof(frame_head.addr)+sizeof(frame_head.ctrl)+sizeof(frame_head.type_fun);
	frame_head.addr=addr;		
	frame_head.ctrl=CTRL_SAVE_CONF;	
	frame_head.type_fun=0x55;	//type_fun该怎么填--预留
	quint8 *p = (quint8 *)data;

	memset(data, 0, sizeof(data));
	msg_len=0;
	memcpy(data, &frame_head, sizeof(frame_head)-1);
	p = p + sizeof(frame_head)-1;
	int len_sum = frame_head.total_size + sizeof(frame_head.head)+sizeof(frame_head.total_size);
	quint16 sum = check_sum(data, len_sum);
	memcpy(p, &sum, 2);
	p+=2;
	*p='>';
	msg_len = frame_head.total_size +sizeof(frame_head.head)+sizeof(frame_head.total_size)+ 2 +1;
}
void MainWindow::upLoadData()
{
	//1.发送上载数据请求。
	SetPlanStreamData(m_type_fun_data, CTRL_RD);
	//发送

	if(m_tcpSocket->write((char*)data, msg_len)>0)
	{
		qCritical()<<"UpLoadData Request to ip("<<ip<<":"<<TCPPORT<<"):"<<QByteArray((char*)data, msg_len).toHex().data()<<"\n";
	}

}



void MainWindow::sgWdigetSelected()
{
	stackWidget->setCurrentWidget(sgnlsTableWidget);
	sgnlsTableWidget->updateDataToUI();
	setActionVisible(true);
}

void MainWindow::intGrWdigetSelected()
{
	setActionVisible(true);
	stackWidget->setCurrentWidget(intGreenMatrixTableWidget);
}

void MainWindow::sgProgWdigetSelected()
{
	setActionVisible(true);
	stackWidget->setCurrentWidget(sgProgTableWidget);
}

void MainWindow::squenceWdigetSelected()
{
	setActionVisible(true);
	stackWidget->setCurrentWidget(squenceTableWidget);
}

void MainWindow::detectVehWidgetSelected()
{
	setActionVisible(true);
	stackWidget->setCurrentWidget(detectVehTableWidget);
}

void MainWindow::detectBusWidgetSelected()
{
	setActionVisible(true);
	stackWidget->setCurrentWidget(detectBusTableWidget);
}

void MainWindow::detectPedWidgetSelected()
{
	setActionVisible(true);
	stackWidget->setCurrentWidget(detectPedTableWidget);
}

void MainWindow::transWidgetSelected()
{
	setActionVisible(true);
	stackWidget->setCurrentWidget(transTableWidget);
}

void MainWindow::periodWidgetSelected()
{
	setActionVisible(true);
	stackWidget->setCurrentWidget(periodTableWidget);
}

void MainWindow::showScData()
{
	stackWidget->setCurrentWidget(pScWidget);
	pScWidget->updateDataToUI();
	setActionVisible(false);
}

void MainWindow::openFile()
{
	QString path = QFileDialog::getOpenFileName(this, tr("Open Sig"), ".", tr("Xml Files(*.sig)")); 
	//  QString path = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files(*.jpg *.png)"));
	if(path.length() == 0) { 
		QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files.")); 
	} else { 
		//QMessageBox::information(NULL, tr("Path"), tr("You selected ") + path); 
		ParseXmlFile(path);

		//更新数据到窗口
		UpdateDataToUI();
		//更改窗口标题
		m_currentName = path;
		this->setWindowTitle(m_currentName);
	}
}

void MainWindow::UpdateDataToUI()
{
	treeWdiget->UpdateDataToUI();
}

void MainWindow::saveAsVISSIMFile()
{
	m_currentName = QFileDialog::getSaveFileName(this, tr("Save Sig"), "./file.sig", tr("Files(*.sig"));
	if (m_currentName.length()==0)
	{
		QMessageBox::information(NULL, tr("Path"), tr("please intput a fileName")); 
	}else
	{
		//获取界面数据
		SaveDataFromUI();
		//写入到xml中
		SaveXmlFile(m_currentName);
		this->setWindowTitle(m_currentName);
	}
}

void MainWindow::saveVISSIMFile()
{
	if (m_currentName.length()==0)
	{
		m_currentName = QFileDialog::getSaveFileName(this, tr("Save Sig"), "./file.sig", tr("Files(*.sig"));
	}
	
	if (m_currentName.length()==0)
	{
		QMessageBox::information(NULL, tr("Path"), tr("please intput a fileName")); 
	}else
	{
		//获取界面数据
		SaveDataFromUI();
		//写入到xml中
		SaveXmlFile(m_currentName);
		this->setWindowTitle(m_currentName);
	}
}

void MainWindow::SaveDataFromUI()
{
	treeWdiget->SaveDataFromUI();
}

bool MainWindow::ParseXmlFile(QString fileName)
{
	if(fileName.isEmpty())  
		return false;  

	QFile file(fileName);  
	if(!file.open(QFile::ReadOnly | QFile::Text))
	{  
		QMessageBox::information(NULL, QString("title"), QString("open error!"));

		return false;  
	}  
	qDebug()<<"start parse\n";
	QDomDocument document;  
	QString error;  
	int row = 0, column = 0;  
	if(!document.setContent(&file, false, &error, &row, &column))
	{  
		QMessageBox::information(NULL, QString("title"), QString("parse file failed at line row and column") + QString::number(row, 10) + QString(",") + QString::number(column, 10));

		return false;  
	}  
	if(document.isNull())
	{  
		QMessageBox::information(NULL, QString("title"), QString("document is null!"));

		return false;  
	}  

	ScData tmpScData;
	QVector<SgData> tmpSgsDatas;		//所有灯组的数据。
	QVector<InterGreenMatrixData> tmpInterGreenMatrixs;
	QVector<SignalProgData> tmpSignalProgs;	

	QVector<SquenceData> tmpSquenceDatas;					//所有相序数据
	QVector<DetectorVehicleData>tmpDetectorVehicleDatas;			//机动车检测器
	QVector<DetectorBusData> tmpDetectorBusDatas;					//公交车检测器
	QVector<DetectorsPedestrainsData> tmpDetectorPedestainsDatas;	//行人检测器
	QVector<TranslationPlanData>	tmpTranslationDatas;				//过渡方案数据
	QVector<PeriodData>					tmpPeriodDatas;						//时段表数据

	//scData解析
	QDomElement sc = document.documentElement();  
	if(sc.hasAttribute("id"))
	{
		tmpScData.nID = sc.attributeNode("id").value().toInt();	//获取id
	}
	if (sc.hasAttribute("name"))
	{
		qstrcpy(tmpScData.strName, sc.attributeNode("name").value().toStdString().c_str());
	}
	if (sc.hasAttribute("frequency"))
	{
		tmpScData.nFrequency = sc.attributeNode("frequency").value().toInt();	
	}
	if (sc.hasAttribute("steps"))
	{
		tmpScData.nstep = sc.attributeNode("steps").value().toInt();	
	}
	if (sc.hasAttribute("defaultIntergreenMatrix"))
	{
		tmpScData.nDefaultInterGreenMatrix = sc.attributeNode("defaultIntergreenMatrix").value().toInt();	
	}
	qDebug()<<"start SgData parse\n";
	//SgData解析
	QDomElement sgs = sc.firstChildElement();		//<sgs>标签

	QDomNodeList sgList = sgs.childNodes();			//<sg>标签
	int nCount = sgList.count();
	for (int i=0; i<nCount; i++)
	{
		QDomNode sgNod = sgList.item(i);
		QDomElement sg = sgNod.toElement();
		SgData data;
		data.nPrimaryId = i+1;
		data.nId = sg.attributeNode("id").value().toInt();		//id
		qstrcpy(data.strName, sg.attributeNode("name").value().toStdString().c_str());		//name
		data.nDefaultSignalSequence = sg.attributeNode("defaultSignalSequence").value().toInt(); //defaultsignalsequence
		QDomElement notes = sg.firstChildElement("notes");		//notes节点
		qstrcpy(data.strNotes, notes.text().toStdString().c_str());
		QDomElement defaultDurations = sg.firstChildElement("defaultDurations"); //defaultDurations节点
		QDomElement defaultDuration = defaultDurations.firstChildElement();
		int k = 0;
		for (int k=0; k<8; k++)
		{
			if (!defaultDuration.isNull())
			{
				int ndiplay = defaultDuration.attributeNode("display").value().toInt();
				data.defaultDurations[ndiplay-1].nDisplay = ndiplay;
				data.defaultDurations[ndiplay-1].nDuration = defaultDuration.attributeNode("duration").value().toInt()/1000;
				defaultDuration = defaultDuration.nextSiblingElement();
			}
		}
		tmpSgsDatas.push_back(data);
	}

	QDomElement intergreenmatrices = sgs.nextSiblingElement();//<intergreenmatrices>
	QDomNodeList intGrMtrList = intergreenmatrices.childNodes();
	nCount = intGrMtrList.count();
	for (int i=0; i<nCount; i++)
	{
		QDomNode intGrMtrNode = intGrMtrList.item(i);
		QDomElement intGrMtr = intGrMtrNode.toElement();
		InterGreenMatrixData data;
		data.nPrimaryId = i+1;
		data.nId = intGrMtr.attributeNode("id").value().toInt();
		qstrcpy(data.strName, intGrMtr.attributeNode("name").value().toStdString().c_str());
		QDomElement intergreen = intGrMtr.firstChildElement();
		while (!intergreen.isNull())
		{
			InterGreen interGreen;
			interGreen.nClearingSg = intergreen.attributeNode("clearingsg").value().toInt();
			interGreen.nEnteringSg = intergreen.attributeNode("enteringsg").value().toInt();
			interGreen.nValue =  intergreen.attributeNode("value").value().toInt()/1000;
			intergreen = intergreen.nextSiblingElement();
			data.interGreens.push_back(interGreen);
		}
		tmpInterGreenMatrixs.push_back(data);
	}

	QDomElement squences = intergreenmatrices.nextSiblingElement();//<squences>
	QDomNodeList squenceList = squences.childNodes();
	nCount = squenceList.count();
	for (int i=0; i<nCount; i++)
	{
		QDomNode squenceNode = squenceList.item(i);
		QDomElement squence = squenceNode.toElement();
		SquenceData data;
		data.nId = squence.attributeNode("id").value().toInt();
		strcpy(data.strName, squence.attributeNode("name").value().toStdString().c_str());
		data.squence.byStartPhase = squence.attributeNode("byStartPhase").value().toInt();
		data.squence.no = data.nId;
		data.squence.count_stage = squence.attributeNode("countStage").value().toInt();
		for (int j=0; j<MAX_RINGS; j++)
		{
			QDomElement ringSquence = squence.firstChildElement(QString("ringSquence%1").arg(j+1));
			for (int k=0; k<MAX_PHASES; k++)
			{
				data.squence.bySequence[j][k] = ringSquence.attributeNode(QString("p%1").arg(k+1)).value().toInt();
			}
		}
		tmpSquenceDatas.push_back(data);
	}

	QDomElement transPlans = squences.nextSiblingElement();//<transPlans>
	QDomNodeList transPlanList = transPlans.childNodes();
	nCount = transPlanList.count();
	for (int i=0; i<nCount; i++)
	{
		QDomNode transPlanNode = transPlanList.item(i);
		QDomElement transPlan = transPlanNode.toElement();
		TranslationPlanData data;
		strcpy(data.strName, transPlan.attributeNode("name").value().toStdString().c_str());
		data.translationPlan.byTransitionPlanNo = transPlan.attributeNode("byTransitionPlanNo").value().toInt();
		data.translationPlan.byLastPhaseNo = transPlan.attributeNode("byLastPhaseNo").value().toInt();

		tmpTranslationDatas.push_back(data);
	}

	QDomElement progs = transPlans.nextSiblingElement();//<progs>
	QDomNodeList progList = progs.childNodes();
	nCount = progList.count();
	for (int i=0; i<nCount; i++)
	{
		QDomNode progNode = progList.item(i);
		QDomElement prog = progNode.toElement();
		SignalProgData data;
		data.nPrimaryId = i+1;
		data.nId = prog.attributeNode("id").value().toInt();
		strcpy(data.strName, prog.attributeNode("name").value().toStdString().c_str());
		data.nCycleTime =  prog.attributeNode("cycletime").value().toInt()/1000;
		data.nSwitchPoint =  prog.attributeNode("switchpoint").value().toInt();
		data.nOffset =  prog.attributeNode("offset").value().toInt();
		data.nInterGreens =  prog.attributeNode("intergreens").value().toInt();
		data.fitness =  prog.attributeNode("fitness").value().toInt();
		data.nVehicleCount =  prog.attributeNode("vehicleCount").value().toInt();
		data.nSequenceNo = prog.attributeNode("sequenceNo").value().toInt();

		QDomElement sgs = prog.firstChildElement();//<sgs>
		QDomElement sg = sgs.firstChildElement();
		while (!sg.isNull())
		{
			SgDataInProg sgDataInProg;
			sgDataInProg.nSgId = sg.attributeNode("sg_id").value().toInt();
			sgDataInProg.nSignalSequence = sg.attributeNode("signal_sequence").value().toInt();
			sgDataInProg.nPhaseType = sg.attributeNode("nPhaseType").value().toInt();
			sgDataInProg.byIsCoordinate = sg.attributeNode("byIsCoordinate").value().toInt();
			sgDataInProg.byMinGreenTime = sg.attributeNode("byMinGreenTime").value().toInt();
			sgDataInProg.byMax1GreenTime = sg.attributeNode("byMax1GreenTime").value().toInt();
			sgDataInProg.byMax2GreenTime = sg.attributeNode("byMax2GreenTime").value().toInt();
			sgDataInProg.byGreenTimeExtendEachTime = sg.attributeNode("byGreenTimeExtendEachTime").value().toInt();
			QDomElement cmds = sg.firstChildElement();
			QDomElement cmd = cmds.firstChildElement();
			while (!cmd.isNull())
			{
				CmdData cmdData;
				cmdData.nDisplay = cmd.attributeNode("display").value().toInt();
				cmdData.nBegin =  cmd.attributeNode("begin").value().toInt()/1000;
				sgDataInProg.cmds.push_back(cmdData);
				cmd = cmd.nextSiblingElement();
			}
			QDomElement fixedstates = cmds.nextSiblingElement();
			QDomElement fixedstate = fixedstates.firstChildElement();
			while (!fixedstate.isNull())
			{
				FixStateData fixStateData;
				fixStateData.nDisplay = fixedstate.attributeNode("display").value().toInt();
				fixStateData.nDuration = fixedstate.attributeNode("duration").value().toInt()/1000;
				sgDataInProg.fixedStates.push_back(fixStateData);
				fixedstate = fixedstate.nextSiblingElement();
			}
			data.sgDatasInProg.push_back(sgDataInProg);
			sg = sg.nextSiblingElement();
		}
		tmpSignalProgs.push_back(data);
	}

	QDomElement periods = progs.nextSiblingElement();//<periods>
	QDomNodeList periodList = periods.childNodes();
	nCount = periodList.count();
	for (int i=0; i<nCount; i++)
	{
		QDomNode periodNode = periodList.item(i);
		QDomElement period = periodNode.toElement();
		PeriodData data;
		data.nId = period.attributeNode("id").value().toInt();
		strcpy(data.strName, period.attributeNode("name").value().toStdString().c_str());
		data.period.StartTime = period.attributeNode("StartTime").value().toInt();
		data.period.EndTime = period.attributeNode("EndTime").value().toInt();
		data.period.byPlanNumber = period.attributeNode("byPlanNumber").value().toInt();
		data.period.byTransPlanNo = period.attributeNode("byTransPlanNo").value().toInt();
		tmpPeriodDatas.push_back(data);
	}

	QDomElement detectorVehicles = periods.nextSiblingElement();//<detectorVehicles>
	QDomNodeList detectorVehicleList = detectorVehicles.childNodes();
	nCount = detectorVehicleList.count();
	for (int i=0; i<nCount; i++)
	{
		QDomNode detectorVehNode = detectorVehicleList.item(i);
		QDomElement detectorVehicle = detectorVehNode.toElement();
		DetectorVehicleData data;
		strcpy(data.strName, detectorVehicle.attributeNode("name").value().toStdString().c_str());
		data.detector.byDetectorNo = detectorVehicle.attributeNode("byDetectorNo").value().toInt();
		data.detector.byEnable = detectorVehicle.attributeNode("byEnable").value().toInt();
		data.detector.byRequestPhaseNo = detectorVehicle.attributeNode("byRequestPhaseNo").value().toInt();
		data.detector.byRequestPhaseType = detectorVehicle.attributeNode("byRequestPhaseType").value().toInt();
		data.detector.byParamEnableFlag = detectorVehicle.attributeNode("byParamEnableFlag").value().toInt();
		tmpDetectorVehicleDatas.push_back(data);
	}

	QDomElement detectorBuses = detectorVehicles.nextSiblingElement();//<detectorBuses>
	QDomNodeList detectorBusList = detectorBuses.childNodes();
	nCount = detectorBusList.count();
	for (int i=0; i<nCount; i++)
	{
		QDomNode detectorBusNode = detectorBusList.item(i);
		QDomElement detectorBus = detectorBusNode.toElement();
		DetectorBusData data;
		strcpy(data.strName, detectorBus.attributeNode("name").value().toStdString().c_str());
		data.detector.byDetectorNo = detectorBus.attributeNode("byDetectorNo").value().toInt();
		data.detector.byEnable = detectorBus.attributeNode("byEnable").value().toInt();
		data.detector.byRequestPhaseNo = detectorBus.attributeNode("byRequestPhaseNo").value().toInt();
		data.detector.byRequestPhaseType = detectorBus.attributeNode("byRequestPhaseType").value().toInt();
		data.detector.byParamEnableFlag = detectorBus.attributeNode("byParamEnableFlag").value().toInt();
		tmpDetectorBusDatas.push_back(data);
	}

	QDomElement detectorPeds = detectorBuses.nextSiblingElement();//<detectorBuses>
	QDomNodeList detectorPedList = detectorPeds.childNodes();
	nCount = detectorPedList.count();
	for (int i=0; i<nCount; i++)
	{
		QDomNode detectorPedNode = detectorPedList.item(i);
		QDomElement detectorPed = detectorPedNode.toElement();
		DetectorsPedestrainsData data;
		strcpy(data.strName, detectorPed.attributeNode("name").value().toStdString().c_str());
		data.detector.byDetectorNo = detectorPed.attributeNode("byDetectorNo").value().toInt();
		data.detector.byEnable = detectorPed.attributeNode("byEnable").value().toInt();
		data.detector.byRequestPhaseNo = detectorPed.attributeNode("byRequestPhaseNo").value().toInt();
		data.detector.byRequestPhaseType = detectorPed.attributeNode("byRequestPhaseType").value().toInt();
		tmpDetectorPedestainsDatas.push_back(data);
	}

	qDebug()<<"start  parse over\n";
	m_scData = tmpScData;
	m_sgsDatas = tmpSgsDatas;
	m_interGreenMatrixs = tmpInterGreenMatrixs;
	m_signalProgs = tmpSignalProgs;
	m_squenceDatas = tmpSquenceDatas;
	m_translationDatas = tmpTranslationDatas;
	m_periodDatas = tmpPeriodDatas;
	m_detectorBusDatas = tmpDetectorBusDatas;
	m_detectorPedestainsDatas = tmpDetectorPedestainsDatas;
	m_detectorVehicleDatas = tmpDetectorVehicleDatas;
	file.close();
	return true;
}


#define SAVE_DEFAULTDURATION(param_cur)		\
	if (m_sgsDatas[i].defaultDurations[j].nDuration!=param_cur)	\
{												\
	QDomElement defaultDuration = doc.createElement("defaultDuration");	  \
	defaultDuration.setAttribute("display", m_sgsDatas[i].defaultDurations[j].nDisplay);        \
	defaultDuration.setAttribute("duration", m_sgsDatas[i].defaultDurations[j].nDuration*1000);   \
	defaultDurations.appendChild(defaultDuration);   \
}

bool MainWindow::SaveXmlFile(QString fileName)
{
	if (fileName.isEmpty())
	{
		return false;
	}

	QDomDocument doc;
	QDomProcessingInstruction instruction;
	instruction = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
	doc.appendChild(instruction);
	QDomElement sc = doc.createElement("sc");  //<sc>
	sc.setAttribute("id", m_scData.nID);
	sc.setAttribute("name", QString::fromLocal8Bit(m_scData.strName));
	sc.setAttribute("frequency", m_scData.nFrequency);
	sc.setAttribute("steps", m_scData.nstep);
	sc.setAttribute("defaultIntergreenMatrix", m_scData.nDefaultInterGreenMatrix);
	doc.appendChild(sc);

	QDomElement sgs = doc.createElement("sgs");//<sgs>
	sc.appendChild(sgs);
	for (int i=0; i<m_sgsDatas.size(); i++)
	{
		QDomElement sg = doc.createElement("sg"); //<sg>
		sg.setAttribute("id", m_sgsDatas[i].nId);
		sg.setAttribute("name", QString(m_sgsDatas[i].strName));
		sg.setAttribute("defaultSignalSequence", m_sgsDatas[i].nDefaultSignalSequence);
		QDomElement notes = doc.createElement("notes");//<notes>
		QDomText notes_text = doc.createTextNode(QString(m_sgsDatas[i].strNotes));
		notes.appendChild(notes_text);
		sg.appendChild(notes);

		QDomElement defaultDurations = doc.createElement("defaultDurations");//<defaultDurations>

		for (int j=0; j<8; j++)
		{
			QDomElement defaultDuration;
			switch (j+1)
			{
			case Red:
				{
					SAVE_DEFAULTDURATION(1);
				}
				break;
			case Red_Amber:
				{
					SAVE_DEFAULTDURATION(1);
				}
				break;
			case Green:
				{
					SAVE_DEFAULTDURATION(5);
				}
				break;
			case Amber:
				{
					SAVE_DEFAULTDURATION(3);
				}
				break;
			case Flash_Green:
				{
					SAVE_DEFAULTDURATION(4);
				}
				break;
			case Flash_Amber:
				{
					SAVE_DEFAULTDURATION(1);
				}
				break;
			case OFF:
				{
					SAVE_DEFAULTDURATION(1);
				}
				break;
			case Flash_Red:
				{
					SAVE_DEFAULTDURATION(1);
				}
				break;
			}
		}
		sg.appendChild(defaultDurations);

		sgs.appendChild(sg);
	}

	QDomElement intergreenmatrices = doc.createElement("intergreenmatrices");//<intergreenmatrices>
	sc.appendChild(intergreenmatrices);
	for (int i=0; i<m_interGreenMatrixs.size(); i++)
	{
		QDomElement intergreenmatrix = doc.createElement("intergreenmatrix");
		intergreenmatrices.appendChild(intergreenmatrix);
		intergreenmatrix.setAttribute("id", m_interGreenMatrixs[i].nId);
		intergreenmatrix.setAttribute("name", m_interGreenMatrixs[i].strName);//<intergreenmatrix>

		for (int j=0; j<m_interGreenMatrixs[i].interGreens.size(); j++)
		{
			QDomElement intergreen = doc.createElement("intergreen"); //<intergreen>
			intergreenmatrix.appendChild(intergreen);
			intergreen.setAttribute("clearingsg", m_interGreenMatrixs[i].interGreens[j].nClearingSg);
			intergreen.setAttribute("enteringsg", m_interGreenMatrixs[i].interGreens[j].nEnteringSg);
			intergreen.setAttribute("value", m_interGreenMatrixs[i].interGreens[j].nValue*1000);
		}	
	}

	QDomElement squences = doc.createElement("squences");		//<squences>
	sc.appendChild(squences);
	for (int i=0; i<m_squenceDatas.size(); i++)
	{
		QDomElement squence = doc.createElement("squence");//<squence>
		squences.appendChild(squence);
		squence.setAttribute("id", m_squenceDatas[i].nId);
		squence.setAttribute("name", m_squenceDatas[i].strName);
		squence.setAttribute("byStartPhase", m_squenceDatas[i].squence.byStartPhase);
		squence.setAttribute("countStage", m_squenceDatas[i].squence.count_stage);
		for (int j=0; j<MAX_RINGS; j++)
		{
			QDomElement ringSquence = doc.createElement(QString("ringSquence%1").arg(j+1));			//<ringSquence_i>
			squence.appendChild(ringSquence);
			for (int k=0; k<MAX_PHASES; k++)
			{
				ringSquence.setAttribute(QString("p%1").arg(k+1), m_squenceDatas[i].squence.bySequence[j][k]);
			}
		}
	}

	QDomElement transPlans = doc.createElement("transPlans");		//<transPlans>
	sc.appendChild(transPlans);
	for (int i=0; i<m_translationDatas.size(); i++)
	{
		QDomElement transPlan = doc.createElement("transPlan");//<transPlan>
		transPlans.appendChild(transPlan);
	//	transPlan.setAttribute("id", m_squenceDatas[i].nId);
		transPlan.setAttribute("name", m_translationDatas[i].strName);
		transPlan.setAttribute("byTransitionPlanNo", m_translationDatas[i].translationPlan.byTransitionPlanNo);
		transPlan.setAttribute("byLastPhaseNo", m_translationDatas[i].translationPlan.byLastPhaseNo);
	}

	
	QDomElement progs = doc.createElement("progs");//<progs>
	sc.appendChild(progs);
	for (int i=0; i<m_signalProgs.size(); i++)		
	{
		QDomElement prog = doc.createElement("prog");
		progs.appendChild(prog);
		prog.setAttribute("id", m_signalProgs[i].nId);
		prog.setAttribute("cycletime", m_signalProgs[i].nCycleTime*1000);
		prog.setAttribute("switchpoint", m_signalProgs[i].nSwitchPoint);
		prog.setAttribute("offset", m_signalProgs[i].nOffset);
		prog.setAttribute("intergreens", m_signalProgs[i].nInterGreens);
		prog.setAttribute("fitness", m_signalProgs[i].fitness);
		prog.setAttribute("vehicleCount", m_signalProgs[i].nVehicleCount);
		prog.setAttribute("sequenceNo", m_signalProgs[i].nSequenceNo);
		prog.setAttribute("name", m_signalProgs[i].strName);
		prog.setAttribute("countPhase", m_signalProgs[i].countPhase);
		prog.setAttribute("ctrlType", m_signalProgs[i].ctrlType);
		prog.setAttribute("startPhase", m_signalProgs[i].startPhase);

		QDomElement sgs = doc.createElement("sgs");//<sgs>
		prog.appendChild(sgs);

		for (int j=0; j<m_signalProgs[i].sgDatasInProg.size(); j++)
		{
			QDomElement sg = doc.createElement("sg");		//<sg>
			sgs.appendChild(sg);
			sg.setAttribute("sg_id", m_signalProgs[i].sgDatasInProg[j].nSgId);
			sg.setAttribute("signal_sequence", m_signalProgs[i].sgDatasInProg[j].nSignalSequence);
			sg.setAttribute("nPhaseType", m_signalProgs[i].sgDatasInProg[j].nPhaseType);
			sg.setAttribute("byIsCoordinate", m_signalProgs[i].sgDatasInProg[j].byIsCoordinate);
			sg.setAttribute("byMinGreenTime", m_signalProgs[i].sgDatasInProg[j].byMinGreenTime);
			sg.setAttribute("byMax1GreenTime", m_signalProgs[i].sgDatasInProg[j].byMax1GreenTime);
			sg.setAttribute("byMax2GreenTime", m_signalProgs[i].sgDatasInProg[j].byMax2GreenTime);
			sg.setAttribute("byGreenTimeExtendEachTime", m_signalProgs[i].sgDatasInProg[j].byGreenTimeExtendEachTime);

			QDomElement cmds = doc.createElement("cmds");	//<cmds>
			sg.appendChild(cmds);
			for (int k=0; k<m_signalProgs[i].sgDatasInProg[j].cmds.size(); k++)
			{
				QDomElement cmd = doc.createElement("cmd");
				cmds.appendChild(cmd);
				cmd.setAttribute("display", m_signalProgs[i].sgDatasInProg[j].cmds[k].nDisplay);
				cmd.setAttribute("begin", m_signalProgs[i].sgDatasInProg[j].cmds[k].nBegin*1000);
			}

			QDomElement fixedstates = doc.createElement("fixedstates");	//<cmds>
			sg.appendChild(fixedstates);
			for (int k=0; k<m_signalProgs[i].sgDatasInProg[j].fixedStates.size(); k++)
			{
				QDomElement fixedstate = doc.createElement("fixedstate");
				fixedstates.appendChild(fixedstate);
				fixedstate.setAttribute("display", m_signalProgs[i].sgDatasInProg[j].fixedStates[k].nDisplay);
				fixedstate.setAttribute("duration", m_signalProgs[i].sgDatasInProg[j].fixedStates[k].nDuration*1000);
			}
		}
	}

	QDomElement periods = doc.createElement("periods");		//<periods>
	sc.appendChild(periods);
	for (int i=0; i<m_periodDatas.size(); i++)
	{
		QDomElement period = doc.createElement("period");//<period>
		periods.appendChild(period);
		period.setAttribute("id", m_periodDatas[i].nId);
		period.setAttribute("name", m_periodDatas[i].strName);
		period.setAttribute("StartTime", m_periodDatas[i].period.StartTime);
		period.setAttribute("EndTime", m_periodDatas[i].period.EndTime);
		period.setAttribute("byPlanNumber", m_periodDatas[i].period.byPlanNumber);
		period.setAttribute("byTransPlanNo", m_periodDatas[i].period.byTransPlanNo);
	}

	QDomElement detectorVehicles = doc.createElement("detectorVehicles");		//<detectorVehicles>
	sc.appendChild(detectorVehicles);
	for (int i=0; i<m_detectorVehicleDatas.size(); i++)
	{
		QDomElement detectorVehicle = doc.createElement("detectorVehicle");//<detectorVehicle>
		detectorVehicles.appendChild(detectorVehicle);
	//	detectorVehicle.setAttribute("id", m_detectorVehicleDatas[i].nId);
		detectorVehicle.setAttribute("name", m_detectorVehicleDatas[i].strName);
		detectorVehicle.setAttribute("byDetectorNo", m_detectorVehicleDatas[i].detector.byDetectorNo);
		detectorVehicle.setAttribute("byEnable", m_detectorVehicleDatas[i].detector.byEnable);
		detectorVehicle.setAttribute("byRequestPhaseNo", m_detectorVehicleDatas[i].detector.byRequestPhaseNo);
		detectorVehicle.setAttribute("byRequestPhaseType", m_detectorVehicleDatas[i].detector.byRequestPhaseType);
		detectorVehicle.setAttribute("byParamEnableFlag", m_detectorVehicleDatas[i].detector.byParamEnableFlag);
	}

	QDomElement detectorBuses = doc.createElement("detectorBuses");		//<detectorBuses>
	sc.appendChild(detectorBuses);
	for (int i=0; i<m_detectorBusDatas.size(); i++)
	{
		QDomElement detectorBus = doc.createElement("detectorBus");//<detectorBus>
		detectorBuses.appendChild(detectorBus);
		//	detectorBus.setAttribute("id", m_detectorVehicleDatas[i].nId);
		detectorBus.setAttribute("name", m_detectorBusDatas[i].strName);
		detectorBus.setAttribute("byDetectorNo", m_detectorBusDatas[i].detector.byDetectorNo);
		detectorBus.setAttribute("byEnable", m_detectorBusDatas[i].detector.byEnable);
		detectorBus.setAttribute("byRequestPhaseNo", m_detectorBusDatas[i].detector.byRequestPhaseNo);
		detectorBus.setAttribute("byRequestPhaseType", m_detectorBusDatas[i].detector.byRequestPhaseType);
		detectorBus.setAttribute("byParamEnableFlag", m_detectorBusDatas[i].detector.byParamEnableFlag);
	}

	QDomElement detectorPeds = doc.createElement("detectorPeds");		//<detectorPeds>
	sc.appendChild(detectorPeds);
	for (int i=0; i<m_detectorPedestainsDatas.size(); i++)
	{
		QDomElement detectorPed = doc.createElement("detectorPed");//<detectorPed>
		detectorPeds.appendChild(detectorPed);
		//	detectorBus.setAttribute("id", m_detectorVehicleDatas[i].nId);
		detectorPed.setAttribute("name", m_detectorPedestainsDatas[i].strName);
		detectorPed.setAttribute("byDetectorNo", m_detectorPedestainsDatas[i].detector.byDetectorNo);
		detectorPed.setAttribute("byEnable", m_detectorPedestainsDatas[i].detector.byEnable);
		detectorPed.setAttribute("byRequestPhaseNo", m_detectorPedestainsDatas[i].detector.byRequestPhaseNo);
		detectorPed.setAttribute("byRequestPhaseType", m_detectorPedestainsDatas[i].detector.byRequestPhaseType);
	}


	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate |QIODevice::Text))
		return false ;
	QTextStream out(&file);
	out.setCodec("UTF-8");
	doc.save(out,4,QDomNode::EncodingFromTextStream);
	file.close();
}

MainWindow::~MainWindow()
{

}
