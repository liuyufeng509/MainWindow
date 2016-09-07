#ifndef QDLGNETCONFIGFRONT_H
#define QDLGNETCONFIGFRONT_H

#include <QDialog>
#include "ui_qdlgnetconfigfront.h"
#include <QUdpSocket>
#include<QListWidgetItem>
#include <QList>
#include <QTimer>
#include "common.h"
#include <QTcpSocket>
struct DevData
{
	QString ip;
	type_addr_conf addrInfo;
};
class QDlgNetConfigFront : public QDialog
{
	Q_OBJECT

public:
	QDlgNetConfigFront(QString &ip, int &port, QWidget *parent = 0);
	~QDlgNetConfigFront();
	void sendAddrMsg(type_addr_conf addr, quint8 ctrl,bool isbroadcast=true);
	int getAddr(){return naddr;}
public slots:
	void processPendingDatagrams();
	void applyReturn();

	void searchDev();
	void CurrentRowChangedSlot(int row);
	void applySlot();
	void connClicked();
	void timeOutSlot();
private:
	Ui::QDlgNetConfigFront ui;
	QUdpSocket *m_socketBrodCast;
	//QUdpSocket *m_sgnalSocket;			//主窗口中传进来的socket，负责与信号机进行互动
	QList<DevData> m_devList;

	quint8 data[1024*10];
	int msg_len;

	type_addr_conf addres_conf;

	QString &strIp;
	int &nPort;
	int naddr;


	QTimer *set_addr_timer;			//设置信号机信息时，启动计时器，判断是否超时
};

#endif // QDLGNETCONFIGFRONT_H
