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

/****************************************实现ip控件 begin*******************************************************/
#include <QLineEdit> 
class QWidget; 
class QFocusEvent; 
class QKeyEvent;
class QLineEdit; 
class QLabel; 

class MyIpPartLineEdit : public QLineEdit 
{ 
    Q_OBJECT 
public: 
    MyIpPartLineEdit(QWidget *parent = 0); 
    ~MyIpPartLineEdit(void); 

    void set_nexttab_edit(QLineEdit *nexttab) { next_tab_ = nexttab; } 

protected: 
    virtual void focusInEvent(QFocusEvent *e); 
    virtual    void keyPressEvent(QKeyEvent *event);   

private slots: 
    void text_edited(const QString& text); 

private: 
    QLineEdit *next_tab_; 
}; 


class MyIpAddrEdit : public QWidget 
{ 
    Q_OBJECT 
public: 
    MyIpAddrEdit(QWidget* pParent = 0); 
    ~MyIpAddrEdit(); 

    void settext(const QString &text); 
    QString text(); 
    void setStyleSheet(const QString &styleSheet); 

signals: 
    void textchanged(const QString& text); 
    void textedited(const QString &text); 

private slots: 
    void textchangedslot(const QString& text); 
    void texteditedslot(const QString &text); 

private: 
    MyIpPartLineEdit *ip_part1_; 
    MyIpPartLineEdit *ip_part2_; 
    MyIpPartLineEdit *ip_part3_; 
    QLineEdit *ip_part4_; 

    QLabel *labeldot1_; 
    QLabel *labeldot2_;     
    QLabel *labeldot3_; 
};

/****************************************实现ip控件 end*******************************************************/


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

	MyIpAddrEdit *broadIp;		//设置广播地址控件
};

#endif // QDLGNETCONFIGFRONT_H
