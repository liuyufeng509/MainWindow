#ifndef COMMON
#define COMMON
#include <QVector>
#include <QtGlobal>
#include <QMap>
#include <fstream>
#include <QtDebug>
#include <QDateTime>
#include <QFile>
#include <time.h>
using namespace std;
//信号序列定义（信号灯各灯色显示顺序）defaultSignalSequence
enum DefaultSignalSequence
{
	COLOR_SEQU_ALL_RED		=					1,		//全红
	COLOR_SEQU_ALL_GREEN			,					//全绿
	COLOR_SEQU_RED_REDAMBER_GREEN_AMBER	,				//红-红黄-绿-黄
	COLOR_SEQU_RED_GREEN				,				//红-绿
	COLOR_SEQU_RED_REDAMBER_GREEN_GREENFLASH_AMBER,		//红-红黄-绿-绿闪-黄
	COLOR_SEQU_RED_GREEN_GREENFLASH	,					//红-绿-绿闪
	COLOR_SEQU_RED_GREEN_AMBER	,						//红-绿-黄
	COLOR_SEQU_AMBERFLASH		,						//黄闪
	COLOR_SEQU_OFF			,							//关灯（黑灯）
	COLOR_SEQU_RED_OFF	,								//红灯-关灯（黑灯）
	COLOR_SEQU_RED_OFF_AMBER	,						//红灯-关灯（黑灯）-黄
	COLOR_SEQU_OFF_GREEN			,				//关灯（黑灯）-绿
	COLOR_SEQU_AMBERFLASH_OFF,							//黄闪-关灯（黑灯）
	COLOR_SEQU_RED_GREEN_REDFLASH,						//红-绿-红闪
	COLOR_SEQU_REDFLASH_OFF								//红闪-关灯（黑灯）
};

enum SignalColor		//灯色
{
	Red = 1,
	Red_Amber,
	Green,
	Amber,
	Flash_Green,
	Flash_Amber,
	OFF,
	Flash_Red
};

//最小默认值
struct DefaultDuration
{
	DefaultDuration():nDisplay(0), nDuration(0)
	{

	}
	int nDisplay;		//显示的颜色 ： 红灯-1，红黄-2，绿灯-3，黄灯-4； 绿闪-5，黄闪-6， 关灯-7，红闪-8
	int nDuration;		//颜色的最小默认值
};

struct SgData	//信号灯结构体
{
	SgData():nPrimaryId(0),nId(0), nDefaultSignalSequence(0)
	{
		memset(strName, 0, sizeof(strName));
		defaultDurations[0].nDisplay = Red;
		defaultDurations[0].nDuration = 1;
		defaultDurations[1].nDisplay = Red_Amber;
		defaultDurations[1].nDuration = 1;
		defaultDurations[2].nDisplay = Green;
		defaultDurations[2].nDuration = 5;
		defaultDurations[3].nDisplay = Amber;
		defaultDurations[3].nDuration = 3;
		defaultDurations[4].nDisplay = Flash_Green;
		defaultDurations[4].nDuration = 4;
		defaultDurations[5].nDisplay = Flash_Amber;
		defaultDurations[5].nDuration = 1;
		defaultDurations[6].nDisplay = OFF;
		defaultDurations[6].nDuration = 1;
		defaultDurations[7].nDisplay = Flash_Red;
		defaultDurations[7].nDuration = 1;
	}
	int nPrimaryId; //主键ID，不可修改，逐个递增
	int nId;		//编号
	char strName[128];//名称
	char strNotes[256];//备注
	//int nPhaseType;		//相位类型
	int nDefaultSignalSequence;	//信号序列定义（信号灯各灯色显示顺序）defaultSignalSequence
	DefaultDuration defaultDurations[8];//                                
};



struct InterGreen		//绿灯间隔
{
	InterGreen():nClearingSg(0), nEnteringSg(0), nValue(-127)
	{

	}
	int nClearingSg;	//结束信号灯id
	int nEnteringSg;	//开始信号灯id
	int nValue;			//间隔值
};

struct InterGreenMatrixData		//绿灯间隔矩阵结构体
{
	InterGreenMatrixData():nPrimaryId(0),nId(0)
	{
		memset(strName, 0, sizeof(strName));
		interGreens.clear();
	}
	int nPrimaryId;			//主键ID，不可修改，逐个递增
	int nId;			//id
	char strName[128];	//名称
	QVector<InterGreen>	interGreens;		//绿灯间隔 个数由信号灯的个数决定
};
//QVector<InterGreenMatrix> interGreenMatrixs;	//所有绿灯间隔矩阵

struct CmdData		//信号灯时间信息
{
	CmdData():nDisplay(0), nBegin(0)
	{

	}
	int nDisplay;		//灯色
	int nBegin;			//开始时间
	int nDuration;		//持续时间
};

struct FixStateData		//灯序中其他灯色的时长信息
{
	FixStateData():nDisplay(0), nDuration(0)
	{

	}
	int nDisplay;		//灯色序号
	int nDuration;		//时长
};

struct SgDataInProg		//配时方案中的信号灯数据
{
	SgDataInProg():nSgId(0), nSignalSequence(0),nPhaseType(0),byIsCoordinate(0),byMinGreenTime(0)
		,byMax1GreenTime(0),byMax2GreenTime(0), byGreenTimeExtendEachTime(0)
	{
		cmds.clear();
		fixedStates.clear();
	}
	int nSgId;			//信号灯id，与SgData中对应
	int nSignalSequence;	//灯序，与SgData中nDefaultSignalSequence对应
	int nPhaseType;		//相位类型
	int byIsCoordinate;   //是否协调相位

	quint16	byMinGreenTime;		//最小绿灯时间
	quint16	byMax1GreenTime;	//第一最大绿灯时间
	quint16	byMax2GreenTime;	//第二最大绿灯时间
	quint16	byGreenTimeExtendEachTime;//绿灯延长时间

	QVector<CmdData> cmds;	//信号灯显示时间，与选择的灯序有关
	QVector<FixStateData> fixedStates;	//灯序中其他灯色的时长信息，与选择的灯序有关
};

struct SignalProgData		//信号灯配时方案结构体
{
	SignalProgData():nPrimaryId(0),nId(0), nCycleTime(0), nSwitchPoint(0),nOffset(0), 
		nInterGreens(0), fitness(0),nVehicleCount(0), countPhase(0),ctrlType(0),startPhase(0)
	{
		sgDatasInProg.clear();
	}

	SignalProgData& operator=(const SignalProgData& data)
	{
		nPrimaryId = data.nPrimaryId;
		nId = data.nId;
		strcpy(strName, data.strName);
		nCycleTime = data.nCycleTime;
		nSwitchPoint = data.nSwitchPoint;
		nOffset = data.nOffset;
		nInterGreens = data.nInterGreens;
		fitness = data.fitness;
		nVehicleCount = data.nVehicleCount;
		countPhase = data.countPhase;
		ctrlType = data.ctrlType;
		startPhase = data.startPhase;

		sgDatasInProg.clear();
		for (int i=0; i<data.sgDatasInProg.size(); i++)
		{
			sgDatasInProg.push_back(data.sgDatasInProg[i]);
		}
		return *this;
	}

	int nPrimaryId; //主键ID，不可修改，逐个递增
	int nId;			//编号
	char strName[128];		//名称
	int nCycleTime;		//周期
	int nSwitchPoint;	//切换点
	int nOffset;		//偏移
	int nInterGreens;	//绿灯间隔矩阵的id, 与绿灯间隔矩阵有关
	float fitness;		//可能没用
	int nVehicleCount;	//过车数量,可能没用
	int nSequenceNo;		//相序号

	int countPhase;				//有效相位数
	quint8 ctrlType;				//控制方式
	quint8 startPhase;			//起始相位号

	QVector<SgDataInProg> sgDatasInProg;		//信号灯信息，与实际信号灯个数有关
};

struct ScData				//信号机控制结构体
{
	ScData():nID(1),nFrequency(0),nstep(0),nDefaultInterGreenMatrix(0)
	{
		memset(strNote, 0, sizeof(strNote));
		memset(strName, 0, sizeof(strName));
		strcpy(strName, "我的信号机控制");
		strcpy(strNote, " ");
	}
	int nID;
	char strName[256];
	char strNote[256];
	int nFrequency;
	int nstep;
	int nDefaultInterGreenMatrix;
};



///////////////////////////////与信号机通信的结构体协议///////////////////////////////////////////

#define FUN_CONF_BASE_0			(quint32)(0x01000000)
#define FUN_ADDR					(quint32)((FUN_CONF_BASE_0)|(0x01))			//信号机地址相关配置
#define FUN_VERSION				(quint32)((FUN_CONF_BASE_0)|(0x02))			//版本号
#define FUN_PLAN					(quint32)((FUN_CONF_BASE_0)|(0x03))			//方案
#define FUN_PERIOD				(quint32)((FUN_CONF_BASE_0)|(0x04))			//时段表
#define FUN_PLAN_TRAN				(quint32)((FUN_CONF_BASE_0)|(0x05))			//过渡方案表
#define FUN_PH_SEQ				(quint32)((FUN_CONF_BASE_0)|(0x06))			//相序表
#define FUN_DEC_PED				(quint32)((FUN_CONF_BASE_0)|(0x07))			//行人检测器
#define FUN_DEC_BUS				(quint32)((FUN_CONF_BASE_0)|(0x08))			//公交检测器
#define FUN_DEC_VEH				(quint32)((FUN_CONF_BASE_0)|(0x09))			//机动车检测器
#define FUN_MATRIX				(quint32)((FUN_CONF_BASE_0)|(0x0A))			//间隔矩阵
#define FUN_DATE_TIME			(quint32)((FUN_CONF_BASE_0)|(0x0b))			//对时间

#define CTRL_RD					(quint8)(0x00)		//单个读取参数;
#define CTRL_RD_FUN				(quint8)(0x01)		//读取某一类参数;
#define CTRL_FLUSH				(quint8)(0x02)		//刷新参数,让配置文件的参数及时生效;

#define CTRL_SET					(quint8)(0xF0)		//设置参数
#define CTRL_SAVE_CONF			(quint8)(0xFE)		//保存参数

#define CTRL_AUTO				(quint8)0xB1		// 自动
#define CTRL_ALL_RED			(quint8)0xB2		//全红
#define CTRL_FLASH				(quint8)0xB3		//闪光
#define CTRL_OFF				(quint8)0xB4		//关灯
#define CTRL_STEP				(quint8)0xB5		//步进

//控制方式宏定义
#define		CONTROL_TYPE_AMBERFLASH				0X01	//黄闪
#define		CONTROL_TYPE_ALLRED					0X02	//全红
#define		CONTROL_TYPE_TURNOFF					0X03	//关灯
#define		CONTROL_TYPE_STEP						0X04	//步进
#define		CONTROL_TYPE_FIXEDTIME				0X05	//定周期
#define		CONTROL_TYPE_INDUCTION				0X06	//感应
#define		CONTROL_TYPE_PEDESTRIANCROSSING		0X07	//行人过街
#define		CONTROL_TYPE_TIMINGCOORDINATION		0X08	//定时协调
#define		CONTROL_TYPE_INDUCECOORDINATION		0X09	//感应协调
#define		CONTROL_TYPE_RESERVE1			0X0A	//保留方式1
#define		CONTROL_TYPE_RESERVE2			0X0B	//保留方式2
#define		CONTROL_TYPE_RESERVE3			0X0C	//保留方式3
#define		CONTROL_TYPE_RESERVE4			0X0D	//保留方式4
#define		CONTROL_TYPE_RESERVE5			0X0E	//保留方式5
#define		CONTROL_TYPE_RESERVE6			0X0F	//保留方式6

//最大值定义
#define		MAX_PHASES				40		//最大相位总数
#define		MAX_VEHICLE_PHASE_NUMBER		16		//最大机动车相位数
#define		MAX_PEDESTRIAN_PHASE_NUMBER		8		//最大行人相位数
#define		MAX_BUS_PHASE_NUMBER			8		//最大公交相位数
#define		MAX_NONMOTOR_NUMBER				8		//最大非机动车数

#define		MAX_DETECTOR_NUMBER				128		//最大检测器总数
#define		MAX_VEHICLE_DETECTORS				64		//最大机动车检测器数
#define		MAX_PEDESTRIAN_DETECTORS			32		//最大行人检测器数
#define		MAX_BUS_DETECTORS								32		//最大公交检测器数

#define    MAX_MTRIXGREEN_NUMBER	    1		//最大绿灯间隔矩阵数量

#define		MAX_PLAN_NUMBER					8  	//最大方案数
#define		MAX_PERIODS								10		//最大时段数

#define		MAX_PHASE_SEQUENCES				10		//最大相序数	//马春飞2015年11月21日 增加
#define		MAX_RINGS									16		//最大环数		//马春飞2015年11月21日 增加
#define		MAX_TRANSITION_PLANS				10		//最大过渡方案	//马春飞2015年11月21日 增加

#define MAX_PROTOCOL_BYTE		(1024*200)		//协议解析最大支持字节数


#define TCPPORT 10000
#define  BrodPORT 9999
#define  LocalBrodPORT 10001
#define LocalUDPPORT 10002

//版本信息
#pragma pack(1) //让编译器对这个结构作1字节对齐
struct type_version
{
	type_version::type_version():id_fun(FUN_VERSION),ver_master(0),ver_slave(0),ver_revise(0)
	{
		memset(build_time, 0, sizeof(build_time));
	}
	const quint32 id_fun/*=FUN_VERSION*/;
	quint8 ver_master;
	quint8 ver_slave;
	quint32 ver_revise;
	quint8 build_time[128];
} ;



// #########################################/信号机地址信息/#########################################//
struct type_addr_conf
{
	type_addr_conf::type_addr_conf():id_fun(FUN_ADDR), addr(0), port(TCPPORT), sim_port1(0),sim_port2(0)
	{
		memset(ip, 0, sizeof(ip));
		memset(mac, 0, sizeof(mac));
		memset(mask, 0, sizeof(mask));
		memset(route, 0, sizeof(route));
		memset(sim_ip, 0, sizeof(sim_ip));
	}
	const quint32 id_fun;
	quint16 addr;		//信号机基地址;
	char		ip[32];
	quint32 port;
	char mac[32];
	char mask[32];
	char route[32];

	char sim_ip[32];  //模拟分析软件IP
	quint32 sim_port1;  //模拟分析软件端口
	quint32 sim_port2;  //模拟分析软件端口
} ;

// 相位
typedef struct
{
	quint8	byPhaseNo;			//相位号

	//通用参数
	quint8	byPhaseType;		//相位类型：0--无定义 1--机动车相位，2--行人相位，3--公交相位， 4--非机动车相位。
	quint8	byColorSequence;	//信号序列（信号灯各灯色显示顺序）defaultSignalSequence
	quint16	byRedDuration;		//红灯持续时间
	quint16	byRedAmberDuration;	//红黄持续时间
	quint16	byGreenDuration;	//绿灯持续时间
	quint16	byAmberDuration;	//黄灯持续时间
	quint16	byGreenFlashDuration;//绿闪持续时间
	quint16	byAmberFlashDuration;//黄闪持续时间
	quint16	byOffDuration;		//关灯持续时间
	quint16	byRedFlashDuration;	//红闪持续时间

	//协调控制使用参数
	quint8	byIsCoordinate;		//是否为协调相位，0-不是，1-是协调相位

	//高级控制使用参数
	quint16	byMinGreenTime;		//最小绿灯时间
	quint16	byMax1GreenTime;	//第一最大绿灯时间
	quint16	byMax2GreenTime;	//第二最大绿灯时间
	quint16	byGreenTimeExtendEachTime;//绿灯延长时间

	//灯色起始时间  progs  begin
	quint16	byRedBegin;			//红灯开始时间
	quint16	byRedAmberBegin;	//红黄开始时间
	quint16	byGreenBegin;		//绿灯开始时间
	quint16	byAmberBegin;		//黄灯开始时间
	quint16	byGreenFlashBegin;	//绿闪开始时间
	quint16	byAmberFlashBegin;	//黄闪开始时间
	quint16	byOffBegin;			//关灯开始时间
	quint16	byRedFlashBegin;	//红闪开始时间

} STRUCT_PHASE;


/**********************************************************************************************************************************
	2015-12-15日增加检测器配置项的功能
**********************************************************************************************************************************/
//机动车检测器,   机动车检测器最大支持64个，每个检测器的属性如下
typedef struct
{
	quint8	byDetectorNo;				//检测器号
	quint8	byEnable;						//检测器是否启用，1=启用，0=不启用
	quint8	byRequestPhaseNo;		//请求相位号
	quint8	byRequestPhaseType;	//请求相位类型  0-无定义，1-机动车相位，2-行人相位，3-公交相位，4-非机动车相位
	quint16	byParamEnableFlag;		/////bit0=Det_Presence
													////bit1=Det_FrontEnds
													////bit2=Det_RearEnds
													////bit3=Det_FrontEndTime
													////bit4=Det_RearEndTime
													////bit5=Det_OccupancyTime
													////bit6=Det_OccupancyRate
													////bit7=Det_OccupancyRateSmoothed
													////bit8=Det_GapTime
													////bit9=Det_VehSpeed
													////bit10=Det_VehLength
	quint8	byReservePara1;		//保留参数1
	quint8	byReservePara2;		//保留参数2
	quint8	byReservePara3;		//保留参数3
} STRUCT_DETECTOR_VEHICLE;

struct type_vehicle_detetcor
{
	type_vehicle_detetcor::type_vehicle_detetcor():id_fun(FUN_DEC_VEH), count_vehicle_detectors(0)
	{
		memset(detectorVehicle, 0, sizeof(detectorVehicle));
	}
	quint32 id_fun; 
	quint8 count_vehicle_detectors;//有效的机动车数量
	STRUCT_DETECTOR_VEHICLE detectorVehicle[MAX_VEHICLE_DETECTORS];
} ;



//公交车检测器, 最多包括32个检测器，每个检测器属性如下
typedef struct
{
	quint8	byDetectorNo;		//检测器号
	quint8	byEnable;			//检测器是否启用，1=启用，0=不启用
	quint8	byRequestPhaseNo;	//请求相位号
	quint8	byRequestPhaseType;	//请求相位类型  0-无定义，1-机动车相位，2-行人相位，3-公交相位，4-非机动车相位配置项
	quint16	byParamEnableFlag;	////bit0=CP_Telegrams
												////bit1=CP_Tele_CP
												////bit2=CP_Tele_Line
												////bit3=CP_Tele_Course
												////bit4=CP_Tele_Route
												////bit5=CP_Tele_Prio
												////bit6=CP_Tele_Length
												////bit7=CP_Tele_ManualDC
												////bit8=CP_Tele_Delay
												////bit9=CP_Tele_Passengers
	quint8	byReservePara1;		//保留参数1
	quint8	byReservePara2;		//保留参数2
	quint8	byReservePara3;		//保留参数3
} STRUCT_DETECTOR_BUS;

struct type_bus_detetcor
{
	type_bus_detetcor::type_bus_detetcor():id_fun(FUN_DEC_BUS), count_vehicle_detectors(0)
	{
		memset(detectorBUS, 0, sizeof(detectorBUS));
	}
	quint32 id_fun; 
	quint8 count_vehicle_detectors;//有效的机动车数量
	STRUCT_DETECTOR_BUS detectorBUS[MAX_BUS_DETECTORS];
};


//行人检测器配置项，最多32个检测器，每个检测器属性如下
typedef struct
{
	quint8	byDetectorNo;		//检测器号
	quint8	byEnable;			//检测器是否启用，1=启用，0=不启用
	quint8	byRequestPhaseNo;	//请求相位号
	quint8	byRequestPhaseType;	//请求相位类型  0-无定义，1-机动车相位，2-行人相位，3-公交相位，4-非机动车相位
	quint8	byReservePara1;		//保留参数1/////bit0=Det_Presence
	quint8	byReservePara2;		//保留参数2	
	quint8	byReservePara3;		//保留参数3
	quint8	byReservePara4;		//保留参数4
	quint8	byReservePara5;		//保留参数5
}STRUCT_DETECTOR_PEDESTRAINS;

struct type_pedestrain_detetcor
{
	type_pedestrain_detetcor::type_pedestrain_detetcor():id_fun(FUN_DEC_PED), count_pedestrain_detectors(0)
	{
		memset(detectorPedestrain, 0, sizeof(detectorPedestrain));
	}
	quint32 id_fun; 
	quint8 count_pedestrain_detectors;//有效的机动车数量
	STRUCT_DETECTOR_PEDESTRAINS detectorPedestrain[MAX_PEDESTRIAN_DETECTORS];

};

/**********************************************************************************************************************************
	2015-12-15日增加时段表
**********************************************************************************************************************************/
typedef	 struct
{
	quint32	StartTime;		//起始时间 单位秒
	quint32	EndTime;		//结束时间 单位秒
	quint8 byPlanNumber;	//时段对应的方案号
	quint8 byTransPlanNo;	//进入该时段时需要执行的过渡方案号
	quint8 byReservePara1;	//保留参数1
	quint8 byReservePara2;	//保留参数2
	quint8 byReservePara3;	//保留参数3
	quint8 byReservePara4;	//保留参数4
	quint8 byReservePara5;	//保留参数5
	quint8 byReservePara6;	//保留参数6
	quint8 byReservePara7;	//保留参数7
	quint8 byReservePara8;	//保留参数8
}type_period;

 struct type_protocol_period
{
	type_protocol_period::type_protocol_period():id_fun(FUN_PERIOD), count_period(0)
	{
		memset(period, 0, sizeof(period));
	}
	quint32 id_fun;
	quint8	count_period;		//有效的时段个数;
	type_period period[MAX_PERIODS];
};

/**********************************************************************************************************************************
	2015-12-15日	增加相续表，最多有10个相序，每个相序包括如下属性
**********************************************************************************************************************************/
typedef	 struct
{
	quint8 no;//相序号
	quint8	byStartPhase;	//起始相位
	quint8 count_stage;//有效阶段数 //马春飞 2016年04月16日 增加
	quint8	bySequence[MAX_RINGS][MAX_PHASES];

}type_sequence;

struct type_protocol_sequence
{
	type_protocol_sequence::type_protocol_sequence():id_fun(FUN_PH_SEQ), count_sequence(0)
	{
		memset(sequence, 0, sizeof(sequence));
	}
	quint32 id_fun;
	quint8	count_sequence;		//有效的相序个数;
	type_sequence sequence[MAX_PHASE_SEQUENCES];
} ;


/**********************************************************************************************************************************
	2015-12-15日 增加过度方案配置 最多支持10个过度方案，每个过度方案属性如下
**********************************************************************************************************************************/
typedef struct 
{
	quint8 byTransitionPlanNo;	//过渡方案号
	quint8 byLastPhaseNo;		//将要结束的相位
	quint8 byReservePara1;	//保留参数1
	quint8 byReservePara2;	//保留参数2
	quint8 byReservePara3;	//保留参数3
	quint8 byReservePara4;	//保留参数4
	quint8 byReservePara5;	//保留参数5
	quint8 byReservePara6;	//保留参数6
	quint8 byReservePara7;	//保留参数7
	quint8 byReservePara8;	//保留参数8

}  type_transitionPlan;

struct type_protocol_transitionPlan
{
	type_protocol_transitionPlan::type_protocol_transitionPlan():id_fun(FUN_PLAN_TRAN), count_transPlan(0)
	{
		memset(transPlan, 0, sizeof(transPlan));
	}
	quint32 id_fun;
	quint8 count_transPlan;	//有效过渡方案数
	type_transitionPlan transPlan[MAX_TRANSITION_PLANS];
} ;

// 方案
typedef	struct
{
	quint16 byPlanNumber;			//添加方案号
	quint8 count_phase;				//有效相位数
	quint8 byControlType;			//控制方式

	quint8 byIsEnableGreenMatix;	//是否启用绿灯间隔矩阵
	quint8 bySequenceNo;					 //相序号  //马春飞 2016年4月16日 增加
	quint8 byStartPhaseNo;			//方案生效时，首先开始的相位号
	quint16 cycleTime;				//周期长
	quint16 offset;					//周期开始的时间偏移，不大于周期长
	quint16 switchPoint;			//周期切换点，不大于周期长
	
	STRUCT_PHASE phase[MAX_PHASES];
	
	quint8 byReservePara1;			//保留参数1
	quint8 byReservePara2;			//保留参数2
	quint8 byReservePara3;			//保留参数3
	quint8 byReservePara4;			//保留参数4
	quint8 byReservePara5;			//保留参数5

}type_plan;

// 方案
#pragma pack(1)
struct type_protocol_plan
{
	type_protocol_plan::type_protocol_plan():id_fun(FUN_PLAN),count_plan(0)
	{
		memset(plan, 0, sizeof(plan));
	}
	const quint32 id_fun;
	quint8 count_plan;  //有效的方案个数;
	type_plan plan[MAX_PLAN_NUMBER];
} ;
//方案-绿灯间隔矩阵
//###########################  绿灯间隔矩阵 intergreenmatrices#################################//
 struct type_unit_matrices
{
	int no;				//绿灯间隔矩阵编号;
	int ph_count;		//有效的相位个数;
	quint8	intergreenmatrices[MAX_PHASES][MAX_PHASES];
} ;

	 struct type_protocol_matrices
{
	type_protocol_matrices::type_protocol_matrices():id_fun(FUN_MATRIX), count(0)
	{
		memset(matrix, 0, sizeof(matrix));
	}
	const quint32 id_fun;
	quint8 count;
	type_unit_matrices matrix[MAX_MTRIXGREEN_NUMBER];
} ;

 struct type_date_time
{
	type_date_time::type_date_time():id_fun(FUN_DATE_TIME),time_t(time(NULL))
	{

	}
	const quint32 id_fun;
	quint32 time_t;			//时间秒数;
};


typedef struct
{

	type_version version;		//版本号;
	type_addr_conf address;	//地址配置
	type_protocol_plan plan;	//方案

	//新添加的量
	type_protocol_period period;			//时段表;
	type_protocol_transitionPlan plan_tran;		//过渡方案表;
	type_protocol_sequence ph_seq;		//相序表
	type_pedestrain_detetcor dec_ped;	//行人检测器
	type_bus_detetcor dec_bus;			//公交检测器
	type_vehicle_detetcor dec_veh;		//机动车检测器
	type_protocol_matrices matrices;				//绿灯间隔;
	type_date_time date_time;			//对时;
}type_fun_conf;

typedef struct
{
	quint8 head;				//包头
	quint32  total_size;		//总长度
	quint32 reserve;			//保留
	quint16 addr;			//信号机地址
	quint8 ctrl;				//读写控制
	quint16 type_fun;		//功能类型号
	quint8 data;
}type_frame_head;



//////////////////////////////////////////////////////////////////////////
//以下为新增的 相序、检测器等数据的结构体定义
//////////////////////////////////////////////////////////////////////////

//相序数据
struct SquenceData
{
	SquenceData():nId(0)
	{
		memset(strName, 0, sizeof(strName));
		memset(&squence, 0, sizeof(squence));
	}
	int nId;
	char strName[128];
	bool isConfiged;		//是否已配置相位
	type_sequence		squence;			//相序内容
};
//机动车检测器数据
struct DetectorVehicleData
{
	DetectorVehicleData()
	{
		memset(strName, 0, sizeof(strName));
		memset(&detector, 0, sizeof(detector));
	}
	char strName[128];			//检测器名称
	STRUCT_DETECTOR_VEHICLE detector;		//检测器的实质内容
};

//公交车检测器数据
struct DetectorBusData
{
	DetectorBusData()
	{
		memset(strName, 0, sizeof(strName));
		memset(&detector, 0, sizeof(detector));
	}
	char strName[128];
	STRUCT_DETECTOR_BUS detector;			//检测器实质内容
};

//行人检测器数据
struct DetectorsPedestrainsData
{
	DetectorsPedestrainsData()
	{
		memset(strName, 0, sizeof(strName));
		memset(&detector, 0, sizeof(detector));
	}
	char strName[128];
	STRUCT_DETECTOR_PEDESTRAINS detector;			//检测器实质内容
};

//过渡方案:依赖灯组（相位)
struct TranslationPlanData
{
	TranslationPlanData()
	{
		memset(strName, 0, sizeof(strName));
		memset(&translationPlan, 0, sizeof(translationPlan));
	}

	char strName[128];				//过渡方案名称
	type_transitionPlan translationPlan;			//过渡方案内容
};

//时段配置数据：依赖于方案号和过渡方案号。
struct PeriodData
{
	PeriodData():nId(0)
	{
		memset(strName, 0, sizeof(strName));
		memset(&period, 0, sizeof(period));
	}
	int nId;					//id编号
	char strName[128];
	type_period period;
};


#pragma pack()

enum DetectorType
{
	Veh=1,
	Bus,
	Ped
};

void localDataToStreamData(QVector<SgData> &sgdatas, QVector<InterGreenMatrixData>&interGreenDatas, QVector<SignalProgData>&sgProgDatas, 
						   QVector<SquenceData> &squenceDatas,QVector<DetectorVehicleData>&detectorVehicleData,QVector<DetectorBusData> &detectorBusDatas,
						   QVector<DetectorsPedestrainsData> &detectorPedestainsDatas,QVector<TranslationPlanData>	&translationDatas,QVector<PeriodData>&periodDatas, 
						   type_fun_conf &data);

void				streamDataToLocalData(QVector<SgData> &sgdatas, QVector<InterGreenMatrixData>&interGreenDatas, QVector<SignalProgData>&sgProgDatas, 
										  QVector<SquenceData> &squenceDatas,QVector<DetectorVehicleData>&detectorVehicleData,QVector<DetectorBusData> &detectorBusDatas,
										  QVector<DetectorsPedestrainsData> &detectorPedestainsDatas,QVector<TranslationPlanData>	&translationDatas,QVector<PeriodData>&periodDatas, 
										  const type_fun_conf &data, QString &errorInfo);

quint16 caclLenth(int beg, int end, int cycle);
quint16 checkBegin(int beg, int cycle);

void getInfo(SgDataInProg & sgDataInprog, STRUCT_PHASE &data, int cycle);
bool isInFun(int id, QVector<SgData>&sgdatas);
bool isInFun(int id, QVector<InterGreen> &interGreens);

/************************************************************************/
/*以下函数为协议解析操作函数                                                        */
/************************************************************************/
extern type_fun_conf global_fun_config;

int do_fram(quint8 *frm_in, int len, type_fun_conf &fun_config, quint32 &id_fun);		//解析数据帧, 返回控制类型。与信号机通信，只有一个Unit单元，所以，可以获取到id_fun判断消息类型。

int check_frame(quint8 *frm_in,int len);	//检查数据帧是否合法;

int check_sum(quint8 *data,int size);		//计算校验和

int check_size_unit(quint8 *data,int size);		//检测数据段下发unit总字节和计算的字节是否一致

quint8 *get_ptr_data(quint8 *frm);		//返回数据段得首指针

int get_len_data(quint8 *frm);				//返回数据段的长度

int set_data_conf_from_stream(quint8 *data,int size,type_fun_conf &fun_config, quint32 &id_fun);		//根据获取到的数据段，解析数据到fun_config中

int set_unit_conf(quint8 *unit,int size,type_fun_conf &fun_config, quint32 &id_fun);	//解析单个unit的配置;

void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);


bool sgsDataLessThan(const SgData data1, const SgData data2);


#endif // COMMON

