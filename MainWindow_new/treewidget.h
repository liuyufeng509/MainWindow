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
	//新加的子节点排序
	void sortSquenceItems();
	void sortDetectVehItems();
	void sortDetectBusItems();
	void sortDetectPedItems();
	void sortTransItems();
	void sortPeriodItems();

	//检测器、相序等数据的同步使用set函数，不在使用引用成员的形式
	void SetSquenceDatas(QVector<SquenceData> datas){m_squenceDatas = datas;}
	void SetDetectorVehicleDatas(QVector<DetectorVehicleData>datas) {m_detectorVehicleDatas = datas;}
	void SetDetectorBusDatas(QVector<DetectorBusData>datas) {m_detectorBusDatas = datas;}
	void	SetDetectorsPedestrainsDatas(QVector<DetectorsPedestrainsData>datas){m_detectorPedestainsDatas = datas;}
	void SetTranslationPlanDatas(QVector<TranslationPlanData>datas){m_translationDatas = datas;}
	void SetPeriodDatas(QVector<PeriodData> datas){m_periodDatas = datas;}

	void setRootName(QString ip);
public slots:
		void addItem();	//添加节点
		void delItem();  //删除节点
		void copyItem(); //复制节点
		void updateDataWithSgsData(const SgData &data, OptionType type=Add);			//添加灯组时，更新间隔矩阵和配时方案数据
		void SetCmdAndFixState(SgDataInProg &data);								//根据灯序，设置信号灯显示时间及灯序中其他灯色的显示时间
		void ItemChangedSlot(QTreeWidgetItem* );						//捕获树节点变化消息
		
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
		void updateSgsTable();				//以下三个函数都是用来更新table的
		void updateIntGrMtrxTable();
		void updateSgProgTable();
		void updateSquenceTable();
		void updatetranslationTable();
		void updateDetectVehTable();
		void updateDetectBusTable();
		void updateDetectPedTable();
		void updatePeriodTable();

		void updateSgInfo(SgData &);			//通知主窗口，调用信号灯窗口，更新数据到界面
		void updateIntGrInfo(InterGreenMatrixData &);
		void updateSgProgInfo(SignalProgData &);

		void updateSquenceInfo(SquenceData &);
		void updateTransInfo(TranslationPlanData &);
		void updateDetectVehInfo(DetectorVehicleData &);
		void updateDetectBusInfo(DetectorBusData &);
		void updateDetectPedInfo(DetectorsPedestrainsData &);
		void updatePeriodInfo(PeriodData &);

		void sgsItemSelected();			//灯组节点被选中
		void intGrMatrxItemSelected();
		void sgProgsItemSelected();

		//新添加的信号
		void squenceItemSelected();
		void detectVehItemSelected();
		void detectBusItemSelected();
		void detectPedItemSelected();
		void transItemSelected();
		void periodItemSelected();

		void rootItemClicked();
private:
	void AddSgData(OptionType type=Add);		//初始化一个新的记录数据并添加
	void AddIntGrMatrixData(OptionType type=Add); //初始化一条新的绿灯矩阵，并添加
	void AddSignalProgData(OptionType type=Add);	//初始化一条绿灯配时方案，并添加
	void InitDurationOfSgData(SgData & data);

	void AddSquenceData(OptionType type=Add);
	void AddTransData(OptionType type=Add);
	void AddDetectVehData(OptionType type=Add);
	void AddDetectBusData(OptionType type=Add);
	void AddDetectPedData(OptionType type=Add);
	void AddPeriodData(OptionType type=Add);

private:

	QTreeWidgetItem *rootItem;	//树形根节点
	QTreeWidgetItem *sgsItem;//信号灯组节点
	QTreeWidgetItem *interGreenMatrixsItem;//绿间隔矩阵节点
	QTreeWidgetItem *signalProgsItem;	//绿灯时间方案节点

	QTreeWidgetItem *squenceItem;			//相序节点
	QTreeWidgetItem *translationItem;		//过渡方案节点
	QTreeWidgetItem *detectorVehItem;			//检测器节点
	QTreeWidgetItem *detectorBusItem;			//检测器节点
	QTreeWidgetItem *detectorPedItem;			//检测器节点
	QTreeWidgetItem *periodItem;				//时段节点
	
	
	QList<SgTreeWidgetItem*> sgTreeWdigetItemLists;	//存放所有的信号灯节点
	QList<IntGreenTreeWidgetItem *> intGreenTreeWidgetItemLists;		//存放所有绿灯间隔的树节点
	QList<SgProgTreeWidgetItem*> sgProgTreeWidgetItemList;			//存放所有配时方案树节点
	QList<SquenceTreeWidgetItem*>squenceTreeWidgetItemList;		//存放所有相序节点
	QList<DetectorVehicleTreeWidgetItem*> detectVehTreeWidgetItemList;
	QList<DetectorBusTreeWidgetItem*> detectBusTreeWidgetItemList;
	QList<DetectorPedTreeWdigetItem*> detectPedTreeWidgetItemList;
	QList<TransTreeWidgetItem*>transTreeWidgetItemList;
	QList<PeriodTreeWidgetItem*> periodTreeWidgetItemList;


	QVector<SgData>  &m_sgsDatas;		//所有灯组的数据。
	QVector<InterGreenMatrixData> &m_interGreenMatrixs;		//所有间隔矩阵数据
	QVector<SignalProgData> &m_signalProgs;						//所有信号配时方案

	QVector<SquenceData> &m_squenceDatas;					//所有相序数据
	QVector<DetectorVehicleData> &m_detectorVehicleDatas;			//机动车检测器
	QVector<DetectorBusData> &m_detectorBusDatas;					//公交车检测器
	QVector<DetectorsPedestrainsData> &m_detectorPedestainsDatas;	//行人检测器
	QVector<TranslationPlanData>	&m_translationDatas;				//过渡方案数据
	QVector<PeriodData>					&m_periodDatas;						//时段表数据
	

	ScData &m_scData;

	int  m_nSgDataPrimaryID;		
	int  m_nIntGrDataPrimaryID;	
	int  m_nSgProgDataPrimaryID;	

	SgsTableWidget *sgnlsTableWidget;			//灯组table窗口
	IntGrMtrxTableWidget *intGreenTableWidget;	//绿灯间隔table窗口
	SignalProgTableWidget *sgProgTableWidget;
	SquenceTableWidget *squenceTableWidget;
	DetectorTableWidget<DetectorVehicleData> *detectVehTableWidget;
	DetectorTableWidget<DetectorBusData> *detectBusTableWidget;
	DetectorTableWidget<DetectorsPedestrainsData> *detectPedTableWidget;
	PeriodTableWidget *periodTableWidget;
	TransTableWidget *transTableWidget;



	//添加右键菜单的功能：
public:
	void CreateActions();
protected:
	void contextMenuEvent(QContextMenuEvent *event);

protected slots:
	void LoadGreenMtrxFromPua();		//从pua文件中读取矩阵数据

private:
	QAction  *readPuaFile;		//读取矩阵的action
	QMenu *popMenu;			//右键菜单
	IntGreenTreeWidgetItem * greenMtrxitem; //右键选中的绿矩阵
};

#endif // TREEWIDGET_H
