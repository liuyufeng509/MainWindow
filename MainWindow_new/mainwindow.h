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
	//�µ�ҳ����Ӧ��ע�������̿��Ժϲ�֮����ʱ���ع��ô���
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

	TreeWidget *treeWdiget;	//�����б�


	SgsTableWidget *sgnlsTableWidget;	//�̵Ƶ���ڵ��Ӧ�Ĵ���
	IntGrMtrxTableWidget *intGreenMatrixTableWidget; //�̼������ڵ��Ӧ�Ĵ���
	SignalProgTableWidget *sgProgTableWidget;	//�źŵ���ʱ�����ڵ��Ӧ�Ĵ���

	SquenceTableWidget *squenceTableWidget;
	DetectorTableWidget<DetectorVehicleData> *detectVehTableWidget;
	DetectorTableWidget<DetectorBusData> *detectBusTableWidget;
	DetectorTableWidget<DetectorsPedestrainsData> *detectPedTableWidget;
	PeriodTableWidget *periodTableWidget;
	TransTableWidget *transTableWidget;

	SignalWidget *signalWidget;
	GreenIntMatrixWidget *pGreenIntMatrixWidget;		//�̼������
	SgProgWidget *pSgProgWidget;						//��ʱ������Ϣ����

	SequenceWidget *psquenceWidget;
	TransWidget * pTransWidget;
	DetectorWidget *pDetectVehWidget;
	DetectorWidget *pDetectBusWidget;
	DetectorWidget *pDetectPedWidget;
	PeriodWidget *pPeriodWidget;
	ScWidget *pScWidget;
	


	QStackedWidget *stackWidget;		//��ջ����


	QVector<SgData>  m_sgsDatas;		//���е�������ݡ�
	QVector<InterGreenMatrixData> m_interGreenMatrixs;
	QVector<SignalProgData> m_signalProgs;		

	QVector<SquenceData> m_squenceDatas;					//������������
	QVector<DetectorVehicleData>m_detectorVehicleDatas;			//�����������
	QVector<DetectorBusData> m_detectorBusDatas;					//�����������
	QVector<DetectorsPedestrainsData> m_detectorPedestainsDatas;	//���˼����
	QVector<TranslationPlanData>	m_translationDatas;				//���ɷ�������
	QVector<PeriodData>					m_periodDatas;						//ʱ�α�����

	ScData  m_scData;

	QString m_currentName;			//��ǰ�򿪵��ļ�

	type_fun_conf	m_type_fun_data;	//���źŻ�ͨ�ŵĽṹ��
	QTcpSocket *m_tcpSocket;			//tcpͨ��

	QByteArray datagram;					//�������ݱ���ʹ��

	QString ip;
	int addr;
	int  port;										//udp����port
	bool isConn;									//�Ƿ��������źŻ�,����ˡ����ӡ���ť
	QTimer *timer;								//ÿ��2�룬״̬����ʾ��ǰ���źŻ�
	QLabel *label;
	QLabel *verLabel;
	quint8 data[MAX_PROTOCOL_BYTE];
	int msg_len;
	QDateTime	lastRecvTime;	
};

#endif // MAINWINDOW_H
