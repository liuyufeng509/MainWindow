#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include <QTreeWidget>
#include <QStackedWidget>
#include <QTableWidget>
#include <QLayout>
#include <QIcon>
#include <QFileDialog>
#include <QMessageBox>
#include <QDomDocument>
#include <QTextStream>
#include "common.h"
#include "treewidget.h"
#include "sgstablewidget.h"
#include "intgrmtrxtablewidget.h"
#include "SignalProgTableWidget.h"
#include "signalwidget.h"
#include "greenintmatrixwidget.h"
#include "scwidget.h"
#include "sgprogwidget.h"
#include <QUdpSocket>
#include "qdlgnetconfigfront.h"
#include "detectortablewidget.h"
#include "transtablewidget.h"
#include "squencetablewidget.h"
#include "periodtablewidget.h"
#include "sequencewidget.h"
#include "transwidget.h"
#include "detectorwidget.h"
#include "periodwidget.h"
#include <QTimer>
#include <QTcpSocket>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
	void setActionVisible(bool bVisible);
	void UpdateDataToUI();
	void SaveDataFromUI();
	void SetPlanStreamData(type_fun_conf &funConfig, quint8 ctrl);
	void SetSaveDataMsg();
public slots:
	void updateSgDataToUI(SgData &data);
	void updateIntGrMtrxToUI(InterGreenMatrixData &data);
	void updateSgProgToUI(SignalProgData &);

	void updateSquenceDataToUI(SquenceData &);
 	void updateDectVehToUI(DetectorVehicleData &);
 	void updateDectBusToUI(DetectorBusData &);
 	void updateDectPedToUI(DetectorsPedestrainsData &);
 	void updateTransToUI(TranslationPlanData &);
 	void updatePeriodToUI(PeriodData &);

	void sgWdigetSelected();
	void intGrWdigetSelected();
	void sgProgWdigetSelected();
	//新的页面响应：注，该流程可以合并之，有时间重构该代码
	void squenceWdigetSelected();
	void detectVehWidgetSelected();
	void detectBusWidgetSelected();
	void detectPedWidgetSelected();
	void transWidgetSelected();
	void periodWidgetSelected();

	void showScData();
	void openFile();
	void saveVISSIMFile();
	void saveAsVISSIMFile();
	void netFrontConfig();
	void aboutDlg();

	void downLoadData();
	void upLoadData();

	void saveDefFun();
	void loadDefFun();

	void freshStatusBar();


	void connected();
	void disconnected();
	void readyRead();

private:
	bool ParseXmlFile(QString fileName);
	bool SaveXmlFile(QString fileName);
	bool newconnect();
private:
	Ui::MainWindowClass ui;

	TreeWidget *treeWdiget;	//树形列表


	SgsTableWidget *sgnlsTableWidget;	//绿灯灯组节点对应的窗口
	IntGrMtrxTableWidget *intGreenMatrixTableWidget; //绿间隔矩阵节点对应的窗口
	SignalProgTableWidget *sgProgTableWidget;	//信号灯配时方案节点对应的窗口

	SquenceTableWidget *squenceTableWidget;
	DetectorTableWidget<DetectorVehicleData> *detectVehTableWidget;
	DetectorTableWidget<DetectorBusData> *detectBusTableWidget;
	DetectorTableWidget<DetectorsPedestrainsData> *detectPedTableWidget;
	PeriodTableWidget *periodTableWidget;
	TransTableWidget *transTableWidget;

	SignalWidget *signalWidget;
	GreenIntMatrixWidget *pGreenIntMatrixWidget;		//绿间隔矩阵
	SgProgWidget *pSgProgWidget;						//配时方案信息窗口

	SequenceWidget *psquenceWidget;
	TransWidget * pTransWidget;
	DetectorWidget *pDetectVehWidget;
	DetectorWidget *pDetectBusWidget;
	DetectorWidget *pDetectPedWidget;
	PeriodWidget *pPeriodWidget;
	ScWidget *pScWidget;
	


	QStackedWidget *stackWidget;		//堆栈窗口


	QVector<SgData>  m_sgsDatas;		//所有灯组的数据。
	QVector<InterGreenMatrixData> m_interGreenMatrixs;
	QVector<SignalProgData> m_signalProgs;		

	QVector<SquenceData> m_squenceDatas;					//所有相序数据
	QVector<DetectorVehicleData>m_detectorVehicleDatas;			//机动车检测器
	QVector<DetectorBusData> m_detectorBusDatas;					//公交车检测器
	QVector<DetectorsPedestrainsData> m_detectorPedestainsDatas;	//行人检测器
	QVector<TranslationPlanData>	m_translationDatas;				//过渡方案数据
	QVector<PeriodData>					m_periodDatas;						//时段表数据

	ScData  m_scData;

	QString m_currentName;			//当前打开的文件

	type_fun_conf	m_type_fun_data;	//与信号机通信的结构体
	QTcpSocket *m_tcpSocket;			//tcp通信

	QByteArray datagram;					//接收数据报文使用

	QString ip;
	int addr;
	int  port;										//udp发送port
	bool isConn;									//是否连接了信号机,点击了【连接】按钮
	QTimer *timer;								//每隔2秒，状态栏显示当前的信号机
	QLabel *label;
	QLabel *verLabel;
	quint8 data[MAX_PROTOCOL_BYTE];
	int msg_len;
	QDateTime	lastRecvTime;	
};

#endif // MAINWINDOW_H
