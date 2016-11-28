#ifndef QCHECKTIMEDIALOG_H
#define QCHECKTIMEDIALOG_H

#include <QDialog>
#include "common.h"
#include <QTcpSocket>
#include "ui_qchecktimedialog.h"

class QCheckTimeDialog : public QDialog
{
	Q_OBJECT

public:
	QCheckTimeDialog(QTcpSocket *tcpSocket, int addr, QWidget *parent = 0);
	~QCheckTimeDialog();
	void SetMsg(quint8 type);
public slots:
	void readyReadSlot();
	void cancelButtonSlot();
	void checkBoxSlot(int state);
	void sendCheckMsg();

	void sendGetTimeMsg();

private:
	Ui::QCheckTimeDialog ui;
	type_date_time m_dateTime;
	QTcpSocket *m_tcpSocket;

	QByteArray datagram;					//接收数据报文使用
	int m_addr;
	quint8 data[MAX_PROTOCOL_BYTE];
	int msg_len;
};

#endif // QCHECKTIMEDIALOG_H
