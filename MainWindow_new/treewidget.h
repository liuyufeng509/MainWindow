#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QTreeWidget>
#include "common.h"
#include "sgtreewidgetitem.h"
#include "intgreentreewidgetitem.h"
#include "sgprogtreewidgetitem.h"
#include "sgstablewidget.h"
#include "intgrmtrxtablewidget.h"
#include "SignalProgTableWidget.h"
#include "squencetreewidgetitem.h"
#include "detectorvehicletreewidgetitem.h"
#include "detectorbustreewidgetitem.h"
#include "detectorpedtreewdigetitem.h"
#include "transtreewidgetitem.h"
#include "periodtreewidgetitem.h"
#include "detectortablewidget.h"
#include "periodtablewidget.h"
#include "transtablewidget.h"
#include "squencetablewidget.h"
#include <QMenu>
#include <QContextMenuEvent>
#include <QFileDialog>

class TreeWidget : public QTreeWidget
{
	Q_OBJECT
	enum OptionType
	{
		Add = 1,
		Delete,
		Copy
	};
public:
	TreeWidget(QVector<SgData>  &sgsDatas, ScData &scData, QVector<InterGreenMatrixData> &interGreenMatrixs,
		QVector<SignalProgData> &signalProgs,QVector<SquenceData> &squenceDatas,QVector<DetectorVehicleData> &detectorVehicleDatas,
		QVector<DetectorBusData> &detectorBusDatas,QVector<DetectorsPedestrainsData> &detectorPedestainsDatas,
		QVector<TranslationPlanData>	&translationDatas,QVector<PeriodData>	&periodDatas,QWidget *parent=0);

	~TreeWidget();

	void setSgsTableWidget(SgsTableWidget *sgnlsWidget){this->sgnlsTableWidget = sgnlsWidget;}
	void setIntGreenTableWidget(IntGrMtrxTableWidget *intGreenWidget){this->intGreenTableWidget = intGreenWidget;}
	void setSgProgTableWidget(SignalProgTableWidget *sgProgTableWidget){this->sgProgTableWidget = sgProgTableWidget;}
	void setSquenceTableWidget(SquenceTableWidget *squenceTableWidget){this->squenceTableWidget = squenceTableWidget;}
	void setDetectVehTableWidget(DetectorTableWidget<DetectorVehicleData> *detectVehTableWidget){this->detectVehTableWidget = detectVehTableWidget;}
	void setDetectBusTableWidget(DetectorTableWidget <DetectorBusData>*detectBusTableWidget){this->detectBusTableWidget = detectBusTableWidget;}
	void setDetectPedTableWidget(DetectorTableWidget  <DetectorsPedestrainsData>*detectPedTableWidget){this->detectPedTableWidget = detectPedTableWidget;}
	void setTransTableWidget(TransTableWidget *transTableWidget){this->transTableWidget = transTableWidget;}
	void setPeriodTableWidget(PeriodTableWidget *periodTableWidget){this->periodTableWidget = periodTableWidget;}

	void updateSgProgDatasWithIntGrData(const InterGreenMatrixData &data, OptionType type=Add);
	void UpdateDataToUI();
	void SaveDataFromUI();
	void sortSgItems();
	void sortIntGrItems();
	void sortSgProgItems();
	//�¼ӵ��ӽڵ�����
	void sortSquenceItems();
	void sortDetectVehItems();
	void sortDetectBusItems();
	void sortDetectPedItems();
	void sortTransItems();
	void sortPeriodItems();

	//���������������ݵ�ͬ��ʹ��set����������ʹ�����ó�Ա����ʽ
	void SetSquenceDatas(QVector<SquenceData> datas){m_squenceDatas = datas;}
	void SetDetectorVehicleDatas(QVector<DetectorVehicleData>datas) {m_detectorVehicleDatas = datas;}
	void SetDetectorBusDatas(QVector<DetectorBusData>datas) {m_detectorBusDatas = datas;}
	void	SetDetectorsPedestrainsDatas(QVector<DetectorsPedestrainsData>datas){m_detectorPedestainsDatas = datas;}
	void SetTranslationPlanDatas(QVector<TranslationPlanData>datas){m_translationDatas = datas;}
	void SetPeriodDatas(QVector<PeriodData> datas){m_periodDatas = datas;}

	void setRootName(QString ip);
public slots:
		void addItem();	//��ӽڵ�
		void delItem();  //ɾ���ڵ�
		void copyItem(); //���ƽڵ�
		void updateDataWithSgsData(const SgData &data, OptionType type=Add);			//��ӵ���ʱ�����¼���������ʱ��������
		void SetCmdAndFixState(SgDataInProg &data);								//���ݵ��������źŵ���ʾʱ�估������������ɫ����ʾʱ��
		void ItemChangedSlot(QTreeWidgetItem* );						//�������ڵ�仯��Ϣ
		
		void updateSgItemContent(SgData data);
		void updateSgItemContentWithSort(SgData data);
		void updateIntGrItemContent(InterGreenMatrixData data);
		void updateIntGrItemContentWithSort(InterGreenMatrixData data);
		void updateSgProgItemContent(SignalProgData data);
		void updateSgProgItemContentWithSort(SignalProgData data);

		void updateSquenceItemContent(SquenceData data);
		void updateTransItemContent(TranslationPlanData data);
		void updateDetectVehItemContent(DetectorVehicleData data);
		void updateDetectBusItemContent(DetectorBusData data);
		void updateDetectPedItemContent(DetectorsPedestrainsData data);
		void updatePeriodItemContent(PeriodData data);

signals:
		void updateSgsTable();				//������������������������table��
		void updateIntGrMtrxTable();
		void updateSgProgTable();
		void updateSquenceTable();
		void updatetranslationTable();
		void updateDetectVehTable();
		void updateDetectBusTable();
		void updateDetectPedTable();
		void updatePeriodTable();

		void updateSgInfo(SgData &);			//֪ͨ�����ڣ������źŵƴ��ڣ��������ݵ�����
		void updateIntGrInfo(InterGreenMatrixData &);
		void updateSgProgInfo(SignalProgData &);

		void updateSquenceInfo(SquenceData &);
		void updateTransInfo(TranslationPlanData &);
		void updateDetectVehInfo(DetectorVehicleData &);
		void updateDetectBusInfo(DetectorBusData &);
		void updateDetectPedInfo(DetectorsPedestrainsData &);
		void updatePeriodInfo(PeriodData &);

		void sgsItemSelected();			//����ڵ㱻ѡ��
		void intGrMatrxItemSelected();
		void sgProgsItemSelected();

		//����ӵ��ź�
		void squenceItemSelected();
		void detectVehItemSelected();
		void detectBusItemSelected();
		void detectPedItemSelected();
		void transItemSelected();
		void periodItemSelected();

		void rootItemClicked();
private:
	void AddSgData(OptionType type=Add);		//��ʼ��һ���µļ�¼���ݲ����
	void AddIntGrMatrixData(OptionType type=Add); //��ʼ��һ���µ��̵ƾ��󣬲����
	void AddSignalProgData(OptionType type=Add);	//��ʼ��һ���̵���ʱ�����������
	void InitDurationOfSgData(SgData & data);

	void AddSquenceData(OptionType type=Add);
	void AddTransData(OptionType type=Add);
	void AddDetectVehData(OptionType type=Add);
	void AddDetectBusData(OptionType type=Add);
	void AddDetectPedData(OptionType type=Add);
	void AddPeriodData(OptionType type=Add);

private:

	QTreeWidgetItem *rootItem;	//���θ��ڵ�
	QTreeWidgetItem *sgsItem;//�źŵ���ڵ�
	QTreeWidgetItem *interGreenMatrixsItem;//�̼������ڵ�
	QTreeWidgetItem *signalProgsItem;	//�̵�ʱ�䷽���ڵ�

	QTreeWidgetItem *squenceItem;			//����ڵ�
	QTreeWidgetItem *translationItem;		//���ɷ����ڵ�
	QTreeWidgetItem *detectorVehItem;			//������ڵ�
	QTreeWidgetItem *detectorBusItem;			//������ڵ�
	QTreeWidgetItem *detectorPedItem;			//������ڵ�
	QTreeWidgetItem *periodItem;				//ʱ�νڵ�
	
	
	QList<SgTreeWidgetItem*> sgTreeWdigetItemLists;	//������е��źŵƽڵ�
	QList<IntGreenTreeWidgetItem *> intGreenTreeWidgetItemLists;		//��������̵Ƽ�������ڵ�
	QList<SgProgTreeWidgetItem*> sgProgTreeWidgetItemList;			//���������ʱ�������ڵ�
	QList<SquenceTreeWidgetItem*>squenceTreeWidgetItemList;		//�����������ڵ�
	QList<DetectorVehicleTreeWidgetItem*> detectVehTreeWidgetItemList;
	QList<DetectorBusTreeWidgetItem*> detectBusTreeWidgetItemList;
	QList<DetectorPedTreeWdigetItem*> detectPedTreeWidgetItemList;
	QList<TransTreeWidgetItem*>transTreeWidgetItemList;
	QList<PeriodTreeWidgetItem*> periodTreeWidgetItemList;


	QVector<SgData>  &m_sgsDatas;		//���е�������ݡ�
	QVector<InterGreenMatrixData> &m_interGreenMatrixs;		//���м����������
	QVector<SignalProgData> &m_signalProgs;						//�����ź���ʱ����

	QVector<SquenceData> &m_squenceDatas;					//������������
	QVector<DetectorVehicleData> &m_detectorVehicleDatas;			//�����������
	QVector<DetectorBusData> &m_detectorBusDatas;					//�����������
	QVector<DetectorsPedestrainsData> &m_detectorPedestainsDatas;	//���˼����
	QVector<TranslationPlanData>	&m_translationDatas;				//���ɷ�������
	QVector<PeriodData>					&m_periodDatas;						//ʱ�α�����
	

	ScData &m_scData;

	int  m_nSgDataPrimaryID;		
	int  m_nIntGrDataPrimaryID;	
	int  m_nSgProgDataPrimaryID;	

	SgsTableWidget *sgnlsTableWidget;			//����table����
	IntGrMtrxTableWidget *intGreenTableWidget;	//�̵Ƽ��table����
	SignalProgTableWidget *sgProgTableWidget;
	SquenceTableWidget *squenceTableWidget;
	DetectorTableWidget<DetectorVehicleData> *detectVehTableWidget;
	DetectorTableWidget<DetectorBusData> *detectBusTableWidget;
	DetectorTableWidget<DetectorsPedestrainsData> *detectPedTableWidget;
	PeriodTableWidget *periodTableWidget;
	TransTableWidget *transTableWidget;



	//����Ҽ��˵��Ĺ��ܣ�
public:
	void CreateActions();
protected:
	void contextMenuEvent(QContextMenuEvent *event);

protected slots:
	void LoadGreenMtrxFromPua();		//��pua�ļ��ж�ȡ��������

private:
	QAction  *readPuaFile;		//��ȡ�����action
	QMenu *popMenu;			//�Ҽ��˵�
	IntGreenTreeWidgetItem * greenMtrxitem; //�Ҽ�ѡ�е��̾���
};

#endif // TREEWIDGET_H
