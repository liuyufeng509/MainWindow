#include "qdlgnetconfigfront.h"

#include <QtDebug>
#include <QMessageBox>
QDlgNetConfigFront::QDlgNetConfigFront(QString &ip, int &port,QWidget *parent)
	: QDialog(parent),msg_len(0),strIp(ip), nPort(port)
{
	ui.setupUi(this);

	m_socketBrodCast = new QUdpSocket(this);
	m_socketBrodCast->bind(LocalBrodPORT, QUdpSocket::ShareAddress);
	connect(m_socketBrodCast, SIGNAL(readyRead()),
		this, SLOT(processPendingDatagrams()));

// 	m_sgnalSocket = new QUdpSocket(this);
// 	m_sgnalSocket->bind(LocalBrodPORT, QUdpSocket::ShareAddress);
 	
	connect(ui.searchButton, SIGNAL(clicked()), this, SLOT(searchDev()));
	connect(ui.devListWidget, SIGNAL(currentRowChanged(int)), this,  SLOT(CurrentRowChangedSlot(int)));
	connect(ui.applyButton, SIGNAL(clicked()), this, SLOT(applySlot()));
	//connect(m_sgnalSocket, SIGNAL(readyRead()), this, SLOT(applyReturn()));	//���յ�ԭ��Ϣ��˵�����óɹ���
	connect(ui.connButton, SIGNAL(clicked()), this, SLOT(connClicked()));
	
	memset(data, 0, sizeof(data));

	set_addr_timer = new QTimer(this);
	connect(set_addr_timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()));


	QRegExp regExp("[1-9][0-9]{0,9}");//�������ʽ����һλΪ1-9�����֣������0-2λ0-9������
	ui.sim_port1LineEdit->setValidator(new QRegExpValidator(regExp,this));
	ui.sim_port2LineEdit->setValidator(new QRegExpValidator(regExp,this));
}

void QDlgNetConfigFront::timeOutSlot()
{
	set_addr_timer->stop();
	QMessageBox::information(this, "Info", QString::fromLocal8Bit("�����źŻ���ַ��Ϣ��ʱ"));
}

void QDlgNetConfigFront::connClicked()
{
	int row = ui.devListWidget->currentRow();
	if (row!=-1)
	{
		strIp = QString(m_devList.at(row).ip);		//���ӵ�ip��ʵ�ʵ�ip
		qCritical()<<QString::fromLocal8Bit("�����źŻ���ip��%1").arg(strIp);
		nPort = m_devList.at(row).addrInfo.port;
		naddr = m_devList.at(row).addrInfo.addr;
		QDialog::accept();
	}else
	{
		QMessageBox::information(this, "info", "please chose a dev");
	}
}

void QDlgNetConfigFront::applySlot()
{
	int row = ui.devListWidget->currentRow();
	if (row!=-1)
	{
		addres_conf.addr = ui.addrLineEdit->text().toInt();
		strcpy(addres_conf.ip, ui.ipLineEdit->text().toStdString().c_str());
		strcpy(addres_conf.mac, ui.macLineEdit->text().toStdString().c_str());
		strcpy(addres_conf.mask, ui.maskLineEdit->text().toStdString().c_str());
		strcpy(addres_conf.route, ui.routeLineEdit->text().toStdString().c_str());
		strcpy(addres_conf.sim_ip, ui.sim_ipLineEdit->text().toStdString().c_str());
		addres_conf.sim_port1 = ui.sim_port1LineEdit->text().toUInt();
		addres_conf.sim_port2 = ui.sim_port2LineEdit->text().toUInt();
		sendAddrMsg(addres_conf, CTRL_SET, false);
		//����
		m_socketBrodCast->writeDatagram((char*)data, msg_len,
			QHostAddress(/*"127.0.0.1"*/m_devList.at(row).ip),BrodPORT /*m_devList.at(row).port*/);
		qCritical()<<"Set Dev Addr Info:"<<QByteArray((char*)data, msg_len).toHex().data()<<"\n";
		set_addr_timer->start(3000);			//������ʱ
	}
}

void QDlgNetConfigFront::CurrentRowChangedSlot(int row)
{
	if(row!=-1)
	{
		ui.ipLineEdit->setText(m_devList.at(row).addrInfo.ip);
		ui.addrLineEdit->setText(QString::number(m_devList.at(row).addrInfo.addr));
		ui.macLineEdit->setText(m_devList.at(row).addrInfo.mac);
		ui.maskLineEdit->setText(m_devList.at(row).addrInfo.mask);
		ui.routeLineEdit->setText(m_devList.at(row).addrInfo.route);
		ui.sim_ipLineEdit->setText(m_devList.at(row).addrInfo.sim_ip);
		ui.sim_port1LineEdit->setText(QString::number(m_devList.at(row).addrInfo.sim_port1));
		ui.sim_port2LineEdit->setText(QString::number(m_devList.at(row).addrInfo.sim_port2));
	}
}

void QDlgNetConfigFront::sendAddrMsg(type_addr_conf addr, quint8 ctrl,bool isbroadcast)
{

	//��Ϣ����
	type_frame_head frame_head;
	frame_head.head='<';
	frame_head.total_size = sizeof(frame_head.reserve)+sizeof(frame_head.addr)+sizeof(frame_head.ctrl)+sizeof(frame_head.type_fun)+1+(sizeof(type_addr_conf)+2);
	frame_head.addr=isbroadcast?0xFF:addr.addr;		
	frame_head.ctrl=ctrl;	//�㲥������һ��Unit����ȡ��������
	frame_head.type_fun=0x55;	//type_fun����ô��--Ԥ��
	quint8 *p = (quint8 *)data;

	memset(data, 0, sizeof(data));
	msg_len=0;

	memcpy(data, &frame_head, sizeof(frame_head)-1);
	p = p + sizeof(frame_head)-1;
	*p++ = 1;		//�㲥ֻ��Ҫһ�����ݵ�Ԫ��
	int unit_len = sizeof(type_addr_conf);
	memcpy(p, &unit_len, 2);
	p+=2;
	memcpy(p, &addr, sizeof(type_addr_conf));
	p+=sizeof(type_addr_conf);
	int len_sum = frame_head.total_size + sizeof(frame_head.head)+sizeof(frame_head.total_size);
	quint16 sum = check_sum(data, len_sum);
	memcpy(p, &sum, 2);
	p+=2;
	*p='>';
	msg_len = frame_head.total_size +sizeof(frame_head.head)+sizeof(frame_head.total_size)+ 2 +1;
}

void QDlgNetConfigFront::searchDev()
{
	ui.devListWidget->clear();
	m_devList.clear();
	type_addr_conf addr;
	quint8 ctrl = CTRL_RD;
	sendAddrMsg(addr, ctrl);

	m_socketBrodCast->writeDatagram((char*)data, msg_len,
		QHostAddress::Broadcast, BrodPORT);
	qDebug()<<QString("Send Search Dev Msg:[%1]\n").arg(QByteArray((char*)data,msg_len).toHex().data());
}

void QDlgNetConfigFront::processPendingDatagrams()
{
	while (m_socketBrodCast->hasPendingDatagrams()) {
		QByteArray datagram;
		datagram.resize(m_socketBrodCast->pendingDatagramSize());
		QHostAddress address;
		quint16 port=0;
		m_socketBrodCast->readDatagram(datagram.data(), datagram.size(), &address, &port);
		qDebug()<<tr("Received Search Dev Msg: \"%1\" \n")
			.arg(datagram.toHex().data());

		type_fun_conf conf;
		 quint32 id_fun=0;
		 int sta = do_fram((quint8*)datagram.data(), datagram.size(), conf, id_fun);

		 if (sta==CTRL_SET&&id_fun==FUN_ADDR&&
			 memcmp(&conf.address, &addres_conf, sizeof(type_addr_conf))==0)
		 {
			 set_addr_timer->stop();
			 QMessageBox::information(this, "Info", "set success!");
			 return;
		 }

		if(sta<0 || id_fun!=FUN_ADDR)	//��Ҫ�����쳣�ж�
		{
			qDebug()<<"do_frame()="<<sta<<" id_fun="<<id_fun<<"(!=FUN_ADDR)\n";
			return;
		}
		if (conf.address.addr==0)		//���˵������Լ����͵Ĺ㲥��Ϣ��
		{
			qDebug()<<"addr=0,not vilade\n";
			return;
		}
		//��ȡ���źŻ���Ϣ���ѹ㲥���ܵĵ�ַ�Ͷ˿ڣ���ֵ���źŻ���ַ��Ϣ��
		DevData devData;
		devData.ip = address.toString();
		memcpy(&devData.addrInfo, &conf.address, sizeof(devData.addrInfo));


		m_devList.append(devData);
		ui.devListWidget->addItem(new QListWidgetItem(devData.ip));
	}
}

void QDlgNetConfigFront::applyReturn()
{
// 	while (m_sgnalSocket->hasPendingDatagrams()) {
// 		QByteArray datagram;
// 		datagram.resize(m_sgnalSocket->pendingDatagramSize());
// 		QHostAddress address;
// 		quint16 port=0;
// 		m_sgnalSocket->readDatagram(datagram.data(), datagram.size(), &address, &port);
// 		qDebug()<<tr("Received Set Dev Addr Return datagram: \"%1\" \n")
// 			.arg(datagram.toHex().data());
// 		type_fun_conf conf;
// 		quint32 id_fun=0;
// 		int sta = do_fram((quint8*)datagram.data(), datagram.size(), conf, id_fun);
// 		if (sta==CTRL_SET&&id_fun==FUN_ADDR&&
// 			memcmp(&conf.address, &addres_conf, sizeof(type_addr_conf))==0)
// 		{
// 			set_addr_timer->stop();
// 			QMessageBox::information(this, "Info", "set success!");
// 		}
// 	}
}

QDlgNetConfigFront::~QDlgNetConfigFront()
{
	m_socketBrodCast->close();

}