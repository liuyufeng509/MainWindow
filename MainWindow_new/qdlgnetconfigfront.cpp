#include "qdlgnetconfigfront.h"

#include <QtDebug>
#include <QMessageBox>
#include <QIntValidator> 
#include <QKeyEvent> 
#include <QRegExpValidator> 
#include <QLabel> 

/****************************************实现ip控件 begin*******************************************************/
MyIpPartLineEdit::MyIpPartLineEdit(QWidget *parent/* = 0*/) 
: QLineEdit(parent) 
{ 
    next_tab_ = NULL; 

    this->setMaxLength(3); 
    this->setFrame(false); 
    this->setAlignment(Qt::AlignCenter); 

    QValidator *validator = new QIntValidator(0, 255, this); 
    this->setValidator(validator); 

    connect(this, SIGNAL(textEdited(const QString&)), this, SLOT(text_edited(const QString&))); 
} 

MyIpPartLineEdit::~MyIpPartLineEdit(void) 
{ 
} 

void MyIpPartLineEdit::focusInEvent(QFocusEvent *e) 
{ 
    this->selectAll(); 
    QLineEdit::focusInEvent(e); 
} 

void MyIpPartLineEdit::keyPressEvent(QKeyEvent *event) 
{ 
    if (event->key() == Qt::Key_Period) 
    { 
        if (next_tab_) 
        { 
            next_tab_->setFocus(); 
            next_tab_->selectAll(); 
        } 
    } 
    QLineEdit::keyPressEvent(event); 
} 

void MyIpPartLineEdit::text_edited(const QString& text) 
{ 
    QIntValidator v(0, 255, this); 
    QString ipaddr = text; 
    int pos = 0; 
    QValidator::State state = v.validate(ipaddr, pos);  
    if (state == QValidator::Acceptable) 
    { 
        if (ipaddr.size() > 1) 
        { 
            if (ipaddr.size() == 2) 
            { 
                int ipnum = ipaddr.toInt(); 
                 
                if (ipnum > 25) 
                { 
                    if (next_tab_) 
                    { 
                        next_tab_->setFocus(); 
                        next_tab_->selectAll(); 
                    }     
                } 
            } 
            else 
            { 
                if (next_tab_) 
                { 
                    next_tab_->setFocus(); 
                    next_tab_->selectAll(); 
                }     
            } 
        } 
    } 
}

MyIpAddrEdit::MyIpAddrEdit(QWidget* pParent /* = 0 */) 
: QWidget(pParent) 
{ 
    ip_part1_ = new MyIpPartLineEdit(this); 
    ip_part2_ = new MyIpPartLineEdit(this); 
    ip_part3_ = new MyIpPartLineEdit(this); 
    ip_part4_ = new MyIpPartLineEdit(this); 

    labeldot1_ = new QLabel(this); 
    labeldot2_ = new QLabel(this); 
    labeldot3_ = new QLabel(this); 

    ip_part1_->setGeometry(QRect(0, 0, 30, 20)); 
    ip_part2_->setGeometry(QRect(30, 0, 30, 20)); 
    ip_part3_->setGeometry(QRect(60, 0, 30, 20)); 
    ip_part4_->setGeometry(QRect(90, 0, 30, 20)); 

    labeldot1_->setText(" ."); 
    labeldot1_->setGeometry(QRect(27, 1, 6, 18)); 
    labeldot1_->setAlignment(Qt::AlignCenter); 

    labeldot2_->setText(" ."); 
    labeldot2_->setGeometry(QRect(57, 1, 6, 18)); 
    labeldot2_->setAlignment(Qt::AlignCenter); 

    labeldot3_->setText(" ."); 
    labeldot3_->setGeometry(QRect(87, 1, 6, 18)); 
    labeldot3_->setAlignment(Qt::AlignCenter); 

    QWidget::setTabOrder(ip_part1_, ip_part2_); 
    QWidget::setTabOrder(ip_part2_, ip_part3_); 
    QWidget::setTabOrder(ip_part3_, ip_part4_); 
    ip_part1_->set_nexttab_edit(ip_part2_); 
    ip_part2_->set_nexttab_edit(ip_part3_); 
    ip_part3_->set_nexttab_edit(ip_part4_); 


    connect(ip_part1_, SIGNAL(textChanged(const QString&)), this, SLOT(textchangedslot(const QString&))); 
    connect(ip_part2_, SIGNAL(textChanged(const QString&)), this, SLOT(textchangedslot(const QString&))); 
    connect(ip_part3_, SIGNAL(textChanged(const QString&)), this, SLOT(textchangedslot(const QString&))); 
    connect(ip_part4_, SIGNAL(textChanged(const QString&)), this, SLOT(textchangedslot(const QString&))); 

    connect(ip_part1_, SIGNAL(textEdited (const QString&)), this, SLOT(texteditedslot(const QString&))); 
    connect(ip_part2_, SIGNAL(textEdited (const QString&)), this, SLOT(texteditedslot(const QString&))); 
    connect(ip_part3_, SIGNAL(textEdited (const QString&)), this, SLOT(texteditedslot(const QString&))); 
    connect(ip_part4_, SIGNAL(textEdited (const QString&)), this, SLOT(texteditedslot(const QString&))); 
     
} 

MyIpAddrEdit::~MyIpAddrEdit() 
{ 

} 

void MyIpAddrEdit::textchangedslot(const QString& /*text*/) 
{ 
    QString ippart1, ippart2, ippart3, ippart4; 
    ippart1 = ip_part1_->text(); 
    ippart2 = ip_part2_->text(); 
    ippart3 = ip_part3_->text(); 
    ippart4 = ip_part4_->text(); 

    QString ipaddr = QString("%1.%2.%3.%4") 
                     .arg(ippart1) 
                     .arg(ippart2) 
                     .arg(ippart3) 
                     .arg(ippart4); 

    emit textchanged(ipaddr); 
} 

void MyIpAddrEdit::texteditedslot(const QString &/*text*/) 
{ 
    QString ippart1, ippart2, ippart3, ippart4; 
    ippart1 = ip_part1_->text(); 
    ippart2 = ip_part2_->text(); 
    ippart3 = ip_part3_->text(); 
    ippart4 = ip_part4_->text(); 

    QString ipaddr = QString("%1.%2.%3.%4") 
        .arg(ippart1) 
        .arg(ippart2) 
        .arg(ippart3) 
        .arg(ippart4); 

    emit textedited(ipaddr); 
} 

void MyIpAddrEdit::settext(const QString &text) 
{ 
    QString ippart1, ippart2, ippart3, ippart4; 
    QString qstring_validate = text; 

    // IP地址验证 
    QRegExp regexp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)"); 
    QRegExpValidator regexp_validator(regexp, this); 
    int nPos = 0; 
    QValidator::State state = regexp_validator.validate(qstring_validate, nPos); 
    // IP合法 
    if (state == QValidator::Acceptable) 
    { 
        QStringList ippartlist = text.split("."); 
     
        int strcount = ippartlist.size(); 
        int index = 0; 
        if (index < strcount) 
        { 
            ippart1 = ippartlist.at(index); 
        } 
        if (++index < strcount) 
        { 
            ippart2 = ippartlist.at(index); 
        } 
        if (++index < strcount) 
        { 
            ippart3 = ippartlist.at(index); 
        } 
        if (++index < strcount) 
        { 
            ippart4 = ippartlist.at(index); 
        } 
    } 

    ip_part1_->setText(ippart1); 
    ip_part2_->setText(ippart2); 
    ip_part3_->setText(ippart3); 
    ip_part4_->setText(ippart4); 
} 

QString MyIpAddrEdit::text() 
{ 
    QString ippart1, ippart2, ippart3, ippart4; 
    ippart1 = ip_part1_->text(); 
    ippart2 = ip_part2_->text(); 
    ippart3 = ip_part3_->text(); 
    ippart4 = ip_part4_->text(); 

    return QString("%1.%2.%3.%4") 
        .arg(ippart1) 
        .arg(ippart2) 
        .arg(ippart3) 
        .arg(ippart4); 
} 

void MyIpAddrEdit::setStyleSheet(const QString &styleSheet) 
{ 
    ip_part1_->setStyleSheet(styleSheet); 
    ip_part2_->setStyleSheet(styleSheet); 
    ip_part3_->setStyleSheet(styleSheet); 
    ip_part4_->setStyleSheet(styleSheet); 
}


/****************************************实现ip控件 end*******************************************************/

QDlgNetConfigFront::QDlgNetConfigFront(QString &ip, int &port,QWidget *parent)
	: QDialog(parent),msg_len(0),strIp(ip), nPort(port)
{
	ui.setupUi(this);
	broadIp = new MyIpAddrEdit(this);
	broadIp->setGeometry(QRect(120, 80, 121, 21));
	broadIp->settext("255.255.255.255");
	m_socketBrodCast = new QUdpSocket(this);
	m_socketBrodCast->bind(LocalBrodPORT, QUdpSocket::ShareAddress);
	connect(m_socketBrodCast, SIGNAL(readyRead()),
		this, SLOT(processPendingDatagrams()));

// 	m_sgnalSocket = new QUdpSocket(this);
// 	m_sgnalSocket->bind(LocalBrodPORT, QUdpSocket::ShareAddress);
 	
	connect(ui.searchButton, SIGNAL(clicked()), this, SLOT(searchDev()));
	connect(ui.devListWidget, SIGNAL(currentRowChanged(int)), this,  SLOT(CurrentRowChangedSlot(int)));
	connect(ui.applyButton, SIGNAL(clicked()), this, SLOT(applySlot()));
	//connect(m_sgnalSocket, SIGNAL(readyRead()), this, SLOT(applyReturn()));	//接收到原消息，说明设置成功。
	connect(ui.connButton, SIGNAL(clicked()), this, SLOT(connClicked()));
	
	memset(data, 0, sizeof(data));

	set_addr_timer = new QTimer(this);
	connect(set_addr_timer, SIGNAL(timeout()), this, SLOT(timeOutSlot()));


	QRegExp regExp("[1-9][0-9]{0,9}");//正则表达式，第一位为1-9的数字，后边是0-2位0-9的数字
	ui.sim_port1LineEdit->setValidator(new QRegExpValidator(regExp,this));
	ui.sim_port2LineEdit->setValidator(new QRegExpValidator(regExp,this));
}

void QDlgNetConfigFront::timeOutSlot()
{
	set_addr_timer->stop();
	QMessageBox::information(this, "Info", QString::fromLocal8Bit("设置信号机地址信息超时"));
}

void QDlgNetConfigFront::connClicked()
{
	int row = ui.devListWidget->currentRow();
	if (row!=-1)
	{
		strIp = QString(m_devList.at(row).ip);		//连接的ip是实际的ip
		qCritical()<<QString::fromLocal8Bit("连接信号机的ip：%1").arg(strIp);
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
		//发送
		m_socketBrodCast->writeDatagram((char*)data, msg_len,
			QHostAddress(/*"127.0.0.1"*/m_devList.at(row).ip),BrodPORT /*m_devList.at(row).port*/);
		qCritical()<<"Set Dev Addr Info:"<<QByteArray((char*)data, msg_len).toHex().data()<<"\n";
		set_addr_timer->start(3000);			//开启计时
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

	//消息定义
	type_frame_head frame_head;
	frame_head.head='<';
	frame_head.total_size = sizeof(frame_head.reserve)+sizeof(frame_head.addr)+sizeof(frame_head.ctrl)+sizeof(frame_head.type_fun)+1+(sizeof(type_addr_conf)+2);
	frame_head.addr=isbroadcast?0xFF:addr.addr;		
	frame_head.ctrl=ctrl;	//广播参数是一个Unit，读取参数类型
	frame_head.type_fun=0x55;	//type_fun该怎么填--预留
	quint8 *p = (quint8 *)data;

	memset(data, 0, sizeof(data));
	msg_len=0;

	memcpy(data, &frame_head, sizeof(frame_head)-1);
	p = p + sizeof(frame_head)-1;
	*p++ = 1;		//广播只需要一个数据单元。
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
		/*QHostAddress::Broadcast*/QHostAddress(broadIp->text()), BrodPORT);
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

		if(sta<0 || id_fun!=FUN_ADDR)	//需要添加异常判断
		{
			qDebug()<<"do_frame()="<<sta<<" id_fun="<<id_fun<<"(!=FUN_ADDR)\n";
			return;
		}
		if (conf.address.addr==0)		//过滤掉本机自己发送的广播消息。
		{
			qDebug()<<"addr=0,not vilade\n";
			return;
		}
		//获取到信号机信息，把广播接受的地址和端口，赋值到信号机地址信息中
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
