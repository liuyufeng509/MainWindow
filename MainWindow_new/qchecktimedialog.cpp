#include "qchecktimedialog.h"
#include <QMessageBox>
QCheckTimeDialog::QCheckTimeDialog(QTcpSocket *tcpSocket,int addr, QWidget *parent)
	: m_tcpSocket(tcpSocket),QDialog(parent),m_addr(addr)
{
	ui.setupUi(this);
	connect(m_tcpSocket, SIGNAL(readyRead()),this, SLOT(readyReadSlot()));

	connect(ui.cancelButton, SIGNAL(clicked()),this, SLOT(cancelButtonSlot()));
	connect(ui.checkTimeButton, SIGNAL(clicked()),this, SLOT(sendCheckMsg()));
	connect(ui.getTimeButton, SIGNAL(clicked()),this, SLOT(sendGetTimeMsg()));
	connect(ui.checkBox, SIGNAL(stateChanged(int)), this, SLOT(checkBoxSlot(int)));
	
	QDateTime time = QDateTime::currentDateTime();
	ui.dateEdit->setDate(time.date());
	ui.timeEdit->setTime(time.time());
}

void QCheckTimeDialog::sendGetTimeMsg()
{
	SetMsg(CTRL_RD);
	//发送
	if(m_tcpSocket->write((char*)data, msg_len)>0)
	{
		qCritical()<<"Send CheckTime Msg:"<<QByteArray((char*)data, msg_len).toHex().data()<<"\n";

	}else
	{
		qCritical()<<"Fail to Send CheckTime Msg:"<<QByteArray((char*)data, msg_len).toHex().data()<<"\n";
		QMessageBox::information(this, "info",QString::fromLocal8Bit("发送获取信号机时间命令失败"));
	}
}

void QCheckTimeDialog::SetMsg(quint8 type)
{
	type_frame_head frame_head;
	frame_head.head='<';
	frame_head.total_size = sizeof(frame_head.reserve)+sizeof(frame_head.addr)+sizeof(frame_head.ctrl)+sizeof(frame_head.type_fun)
		+1
		+(sizeof(type_date_time)+2);
	frame_head.addr=m_addr;		
	frame_head.ctrl=type;	
	frame_head.type_fun=0x55;	//type_fun该怎么填--预留
	quint8 *p = (quint8 *)data;

	memset(data, 0, sizeof(data));
	msg_len=0;
	memcpy(data, &frame_head, sizeof(frame_head)-1);
	p = p + sizeof(frame_head)-1;
	*p++=1;
	int unit_len = sizeof(type_date_time);
	memcpy(p, &unit_len, 2);	//设置第一个Unit长度
	p+=2;
	memcpy(p, &m_dateTime, sizeof(type_date_time));
	p+=sizeof(type_date_time);

	int len_sum = frame_head.total_size + sizeof(frame_head.head)+sizeof(frame_head.total_size);
	quint16 sum = check_sum(data, len_sum);
	memcpy(p, &sum, 2);
	p+=2;
	*p='>';
	msg_len = frame_head.total_size +sizeof(frame_head.head)+sizeof(frame_head.total_size)+ 2 +1;
}

void QCheckTimeDialog::sendCheckMsg()
{
	if (ui.checkBox->isChecked())
	{
		m_dateTime.time_t = time(NULL);
	}else
	{
		QDate dateValue = ui.dateEdit->date();
		QTime timeValue = ui.timeEdit->time();
		QDateTime time(dateValue, timeValue);
		m_dateTime.time_t = time.toTime_t();
	}
	SetMsg(CTRL_SET);
	//发送
	if(m_tcpSocket->write((char*)data, msg_len)>0)
	{
		qCritical()<<"Send CheckTime Msg:"<<QByteArray((char*)data, msg_len).toHex().data()<<"\n";
		
	}else
	{
		qCritical()<<"Fail to Send CheckTime Msg:"<<QByteArray((char*)data, msg_len).toHex().data()<<"\n";
		QMessageBox::information(this, "info",QString::fromLocal8Bit("发送校时命令失败"));
	}
}

void QCheckTimeDialog::readyReadSlot()
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
			qCritical()<<QString::fromLocal8Bit("信号机校时数据解析失败\n");
			return;
		}else
		{
			qCritical()<<QString::fromLocal8Bit("信号机校时数据解析成功!\n");
		}
		//心跳判断
// 		if( id_fun==FUN_VERSION)	//需要添加异常判断
// 		{
// 			qCritical()<<QString::fromLocal8Bit("解析报文知收到为版本号报文：Rev Heart(Version) Msg \n");
// 		}

		if (sta==CTRL_SET && id_fun==FUN_DATE_TIME)		
		{
			qCritical()<<"Rev  CheckTime Data(Red)\n";
			QString errionfo="";	
			qCritical()<<QString::fromLocal8Bit("校时成功\n");
			QMessageBox::information(this, "infor", QString::fromLocal8Bit("校时成功！"));
		}

		if (sta==CTRL_RD && id_fun==FUN_DATE_TIME)		
		{
			qCritical()<<"Rev  CheckTime Data(Red)\n";
			QString errionfo="";	
			qCritical()<<QString::fromLocal8Bit("获取信号机时间成功\n");
			m_dateTime.time_t = conf.date_time.time_t;
			QDateTime time = QDateTime::fromTime_t(m_dateTime.time_t);  
			ui.label_3->setText(QString::fromLocal8Bit("信号机当前时间：")+time.toString("yyyy.MM.dd hh:mm:ss"));
		}


		datagram.clear();
	}
}

void QCheckTimeDialog::cancelButtonSlot()
{
	disconnect(m_tcpSocket, SIGNAL(readyRead()),this, SLOT(readyReadSlot()));
	QDialog::reject();
}

void QCheckTimeDialog::checkBoxSlot(int state)
{
	if (state == Qt::Unchecked)
	{
		ui.dateEdit->setEnabled(true);
		ui.timeEdit->setEnabled(true);
	}else if(state == Qt::Checked)
	{
		ui.dateEdit->setEnabled(false);
		ui.timeEdit->setEnabled(false);
	}
}

QCheckTimeDialog::~QCheckTimeDialog()
{

}
