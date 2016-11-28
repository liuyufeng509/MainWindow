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
//�ź����ж��壨�źŵƸ���ɫ��ʾ˳��defaultSignalSequence
enum DefaultSignalSequence
{
	COLOR_SEQU_ALL_RED		=					1,		//ȫ��
	COLOR_SEQU_ALL_GREEN			,					//ȫ��
	COLOR_SEQU_RED_REDAMBER_GREEN_AMBER	,				//��-���-��-��
	COLOR_SEQU_RED_GREEN				,				//��-��
	COLOR_SEQU_RED_REDAMBER_GREEN_GREENFLASH_AMBER,		//��-���-��-����-��
	COLOR_SEQU_RED_GREEN_GREENFLASH	,					//��-��-����
	COLOR_SEQU_RED_GREEN_AMBER	,						//��-��-��
	COLOR_SEQU_AMBERFLASH		,						//����
	COLOR_SEQU_OFF			,							//�صƣ��ڵƣ�
	COLOR_SEQU_RED_OFF	,								//���-�صƣ��ڵƣ�
	COLOR_SEQU_RED_OFF_AMBER	,						//���-�صƣ��ڵƣ�-��
	COLOR_SEQU_OFF_GREEN			,				//�صƣ��ڵƣ�-��
	COLOR_SEQU_AMBERFLASH_OFF,							//����-�صƣ��ڵƣ�
	COLOR_SEQU_RED_GREEN_REDFLASH,						//��-��-����
	COLOR_SEQU_REDFLASH_OFF								//����-�صƣ��ڵƣ�
};

enum SignalColor		//��ɫ
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

//��СĬ��ֵ
struct DefaultDuration
{
	DefaultDuration():nDisplay(0), nDuration(0)
	{

	}
	int nDisplay;		//��ʾ����ɫ �� ���-1�����-2���̵�-3���Ƶ�-4�� ����-5������-6�� �ص�-7������-8
	int nDuration;		//��ɫ����СĬ��ֵ
};

struct SgData	//�źŵƽṹ��
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
	int nPrimaryId; //����ID�������޸ģ��������
	int nId;		//���
	char strName[128];//����
	char strNotes[256];//��ע
	//int nPhaseType;		//��λ����
	int nDefaultSignalSequence;	//�ź����ж��壨�źŵƸ���ɫ��ʾ˳��defaultSignalSequence
	DefaultDuration defaultDurations[8];//                                
};



struct InterGreen		//�̵Ƽ��
{
	InterGreen():nClearingSg(0), nEnteringSg(0), nValue(-127)
	{

	}
	int nClearingSg;	//�����źŵ�id
	int nEnteringSg;	//��ʼ�źŵ�id
	int nValue;			//���ֵ
};

struct InterGreenMatrixData		//�̵Ƽ������ṹ��
{
	InterGreenMatrixData():nPrimaryId(0),nId(0)
	{
		memset(strName, 0, sizeof(strName));
		interGreens.clear();
	}
	int nPrimaryId;			//����ID�������޸ģ��������
	int nId;			//id
	char strName[128];	//����
	QVector<InterGreen>	interGreens;		//�̵Ƽ�� �������źŵƵĸ�������
};
//QVector<InterGreenMatrix> interGreenMatrixs;	//�����̵Ƽ������

struct CmdData		//�źŵ�ʱ����Ϣ
{
	CmdData():nDisplay(0), nBegin(0)
	{

	}
	int nDisplay;		//��ɫ
	int nBegin;			//��ʼʱ��
	int nDuration;		//����ʱ��
};

struct FixStateData		//������������ɫ��ʱ����Ϣ
{
	FixStateData():nDisplay(0), nDuration(0)
	{

	}
	int nDisplay;		//��ɫ���
	int nDuration;		//ʱ��
};

struct SgDataInProg		//��ʱ�����е��źŵ�����
{
	SgDataInProg():nSgId(0), nSignalSequence(0),nPhaseType(0),byIsCoordinate(0),byMinGreenTime(0)
		,byMax1GreenTime(0),byMax2GreenTime(0), byGreenTimeExtendEachTime(0)
	{
		cmds.clear();
		fixedStates.clear();
	}
	int nSgId;			//�źŵ�id����SgData�ж�Ӧ
	int nSignalSequence;	//������SgData��nDefaultSignalSequence��Ӧ
	int nPhaseType;		//��λ����
	int byIsCoordinate;   //�Ƿ�Э����λ

	quint16	byMinGreenTime;		//��С�̵�ʱ��
	quint16	byMax1GreenTime;	//��һ����̵�ʱ��
	quint16	byMax2GreenTime;	//�ڶ�����̵�ʱ��
	quint16	byGreenTimeExtendEachTime;//�̵��ӳ�ʱ��

	QVector<CmdData> cmds;	//�źŵ���ʾʱ�䣬��ѡ��ĵ����й�
	QVector<FixStateData> fixedStates;	//������������ɫ��ʱ����Ϣ����ѡ��ĵ����й�
};

struct SignalProgData		//�źŵ���ʱ�����ṹ��
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

	int nPrimaryId; //����ID�������޸ģ��������
	int nId;			//���
	char strName[128];		//����
	int nCycleTime;		//����
	int nSwitchPoint;	//�л���
	int nOffset;		//ƫ��
	int nInterGreens;	//�̵Ƽ�������id, ���̵Ƽ�������й�
	float fitness;		//����û��
	int nVehicleCount;	//��������,����û��
	int nSequenceNo;		//�����

	int countPhase;				//��Ч��λ��
	quint8 ctrlType;				//���Ʒ�ʽ
	quint8 startPhase;			//��ʼ��λ��

	QVector<SgDataInProg> sgDatasInProg;		//�źŵ���Ϣ����ʵ���źŵƸ����й�
};

struct ScData				//�źŻ����ƽṹ��
{
	ScData():nID(1),nFrequency(0),nstep(0),nDefaultInterGreenMatrix(0)
	{
		memset(strNote, 0, sizeof(strNote));
		memset(strName, 0, sizeof(strName));
		strcpy(strName, "�ҵ��źŻ�����");
		strcpy(strNote, " ");
	}
	int nID;
	char strName[256];
	char strNote[256];
	int nFrequency;
	int nstep;
	int nDefaultInterGreenMatrix;
};



///////////////////////////////���źŻ�ͨ�ŵĽṹ��Э��///////////////////////////////////////////

#define FUN_CONF_BASE_0			(quint32)(0x01000000)
#define FUN_ADDR					(quint32)((FUN_CONF_BASE_0)|(0x01))			//�źŻ���ַ�������
#define FUN_VERSION				(quint32)((FUN_CONF_BASE_0)|(0x02))			//�汾��
#define FUN_PLAN					(quint32)((FUN_CONF_BASE_0)|(0x03))			//����
#define FUN_PERIOD				(quint32)((FUN_CONF_BASE_0)|(0x04))			//ʱ�α�
#define FUN_PLAN_TRAN				(quint32)((FUN_CONF_BASE_0)|(0x05))			//���ɷ�����
#define FUN_PH_SEQ				(quint32)((FUN_CONF_BASE_0)|(0x06))			//�����
#define FUN_DEC_PED				(quint32)((FUN_CONF_BASE_0)|(0x07))			//���˼����
#define FUN_DEC_BUS				(quint32)((FUN_CONF_BASE_0)|(0x08))			//���������
#define FUN_DEC_VEH				(quint32)((FUN_CONF_BASE_0)|(0x09))			//�����������
#define FUN_MATRIX				(quint32)((FUN_CONF_BASE_0)|(0x0A))			//�������
#define FUN_DATE_TIME			(quint32)((FUN_CONF_BASE_0)|(0x0b))			//��ʱ��

#define CTRL_RD					(quint8)(0x00)		//������ȡ����;
#define CTRL_RD_FUN				(quint8)(0x01)		//��ȡĳһ�����;
#define CTRL_FLUSH				(quint8)(0x02)		//ˢ�²���,�������ļ��Ĳ�����ʱ��Ч;

#define CTRL_SET					(quint8)(0xF0)		//���ò���
#define CTRL_SAVE_CONF			(quint8)(0xFE)		//�������

#define CTRL_AUTO				(quint8)0xB1		// �Զ�
#define CTRL_ALL_RED			(quint8)0xB2		//ȫ��
#define CTRL_FLASH				(quint8)0xB3		//����
#define CTRL_OFF				(quint8)0xB4		//�ص�
#define CTRL_STEP				(quint8)0xB5		//����

//���Ʒ�ʽ�궨��
#define		CONTROL_TYPE_AMBERFLASH				0X01	//����
#define		CONTROL_TYPE_ALLRED					0X02	//ȫ��
#define		CONTROL_TYPE_TURNOFF					0X03	//�ص�
#define		CONTROL_TYPE_STEP						0X04	//����
#define		CONTROL_TYPE_FIXEDTIME				0X05	//������
#define		CONTROL_TYPE_INDUCTION				0X06	//��Ӧ
#define		CONTROL_TYPE_PEDESTRIANCROSSING		0X07	//���˹���
#define		CONTROL_TYPE_TIMINGCOORDINATION		0X08	//��ʱЭ��
#define		CONTROL_TYPE_INDUCECOORDINATION		0X09	//��ӦЭ��
#define		CONTROL_TYPE_RESERVE1			0X0A	//������ʽ1
#define		CONTROL_TYPE_RESERVE2			0X0B	//������ʽ2
#define		CONTROL_TYPE_RESERVE3			0X0C	//������ʽ3
#define		CONTROL_TYPE_RESERVE4			0X0D	//������ʽ4
#define		CONTROL_TYPE_RESERVE5			0X0E	//������ʽ5
#define		CONTROL_TYPE_RESERVE6			0X0F	//������ʽ6

//���ֵ����
#define		MAX_PHASES				40		//�����λ����
#define		MAX_VEHICLE_PHASE_NUMBER		16		//����������λ��
#define		MAX_PEDESTRIAN_PHASE_NUMBER		8		//���������λ��
#define		MAX_BUS_PHASE_NUMBER			8		//��󹫽���λ��
#define		MAX_NONMOTOR_NUMBER				8		//���ǻ�������

#define		MAX_DETECTOR_NUMBER				128		//�����������
#define		MAX_VEHICLE_DETECTORS				64		//���������������
#define		MAX_PEDESTRIAN_DETECTORS			32		//������˼������
#define		MAX_BUS_DETECTORS								32		//��󹫽��������

#define    MAX_MTRIXGREEN_NUMBER	    1		//����̵Ƽ����������

#define		MAX_PLAN_NUMBER					8  	//��󷽰���
#define		MAX_PERIODS								10		//���ʱ����

#define		MAX_PHASE_SEQUENCES				10		//���������	//����2015��11��21�� ����
#define		MAX_RINGS									16		//�����		//����2015��11��21�� ����
#define		MAX_TRANSITION_PLANS				10		//�����ɷ���	//����2015��11��21�� ����

#define MAX_PROTOCOL_BYTE		(1024*200)		//Э��������֧���ֽ���


#define TCPPORT 10000
#define  BrodPORT 9999
#define  LocalBrodPORT 10001
#define LocalUDPPORT 10002

//�汾��Ϣ
#pragma pack(1) //�ñ�����������ṹ��1�ֽڶ���
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



// #########################################/�źŻ���ַ��Ϣ/#########################################//
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
	quint16 addr;		//�źŻ�����ַ;
	char		ip[32];
	quint32 port;
	char mac[32];
	char mask[32];
	char route[32];

	char sim_ip[32];  //ģ��������IP
	quint32 sim_port1;  //ģ���������˿�
	quint32 sim_port2;  //ģ���������˿�
} ;

// ��λ
typedef struct
{
	quint8	byPhaseNo;			//��λ��

	//ͨ�ò���
	quint8	byPhaseType;		//��λ���ͣ�0--�޶��� 1--��������λ��2--������λ��3--������λ�� 4--�ǻ�������λ��
	quint8	byColorSequence;	//�ź����У��źŵƸ���ɫ��ʾ˳��defaultSignalSequence
	quint16	byRedDuration;		//��Ƴ���ʱ��
	quint16	byRedAmberDuration;	//��Ƴ���ʱ��
	quint16	byGreenDuration;	//�̵Ƴ���ʱ��
	quint16	byAmberDuration;	//�ƵƳ���ʱ��
	quint16	byGreenFlashDuration;//��������ʱ��
	quint16	byAmberFlashDuration;//��������ʱ��
	quint16	byOffDuration;		//�صƳ���ʱ��
	quint16	byRedFlashDuration;	//��������ʱ��

	//Э������ʹ�ò���
	quint8	byIsCoordinate;		//�Ƿ�ΪЭ����λ��0-���ǣ�1-��Э����λ

	//�߼�����ʹ�ò���
	quint16	byMinGreenTime;		//��С�̵�ʱ��
	quint16	byMax1GreenTime;	//��һ����̵�ʱ��
	quint16	byMax2GreenTime;	//�ڶ�����̵�ʱ��
	quint16	byGreenTimeExtendEachTime;//�̵��ӳ�ʱ��

	//��ɫ��ʼʱ��  progs  begin
	quint16	byRedBegin;			//��ƿ�ʼʱ��
	quint16	byRedAmberBegin;	//��ƿ�ʼʱ��
	quint16	byGreenBegin;		//�̵ƿ�ʼʱ��
	quint16	byAmberBegin;		//�Ƶƿ�ʼʱ��
	quint16	byGreenFlashBegin;	//������ʼʱ��
	quint16	byAmberFlashBegin;	//������ʼʱ��
	quint16	byOffBegin;			//�صƿ�ʼʱ��
	quint16	byRedFlashBegin;	//������ʼʱ��

} STRUCT_PHASE;


/**********************************************************************************************************************************
	2015-12-15�����Ӽ����������Ĺ���
**********************************************************************************************************************************/
//�����������,   ��������������֧��64����ÿ�����������������
typedef struct
{
	quint8	byDetectorNo;				//�������
	quint8	byEnable;						//������Ƿ����ã�1=���ã�0=������
	quint8	byRequestPhaseNo;		//������λ��
	quint8	byRequestPhaseType;	//������λ����  0-�޶��壬1-��������λ��2-������λ��3-������λ��4-�ǻ�������λ
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
	quint8	byReservePara1;		//��������1
	quint8	byReservePara2;		//��������2
	quint8	byReservePara3;		//��������3
} STRUCT_DETECTOR_VEHICLE;

struct type_vehicle_detetcor
{
	type_vehicle_detetcor::type_vehicle_detetcor():id_fun(FUN_DEC_VEH), count_vehicle_detectors(0)
	{
		memset(detectorVehicle, 0, sizeof(detectorVehicle));
	}
	quint32 id_fun; 
	quint8 count_vehicle_detectors;//��Ч�Ļ���������
	STRUCT_DETECTOR_VEHICLE detectorVehicle[MAX_VEHICLE_DETECTORS];
} ;



//�����������, ������32���������ÿ���������������
typedef struct
{
	quint8	byDetectorNo;		//�������
	quint8	byEnable;			//������Ƿ����ã�1=���ã�0=������
	quint8	byRequestPhaseNo;	//������λ��
	quint8	byRequestPhaseType;	//������λ����  0-�޶��壬1-��������λ��2-������λ��3-������λ��4-�ǻ�������λ������
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
	quint8	byReservePara1;		//��������1
	quint8	byReservePara2;		//��������2
	quint8	byReservePara3;		//��������3
} STRUCT_DETECTOR_BUS;

struct type_bus_detetcor
{
	type_bus_detetcor::type_bus_detetcor():id_fun(FUN_DEC_BUS), count_vehicle_detectors(0)
	{
		memset(detectorBUS, 0, sizeof(detectorBUS));
	}
	quint32 id_fun; 
	quint8 count_vehicle_detectors;//��Ч�Ļ���������
	STRUCT_DETECTOR_BUS detectorBUS[MAX_BUS_DETECTORS];
};


//���˼������������32���������ÿ���������������
typedef struct
{
	quint8	byDetectorNo;		//�������
	quint8	byEnable;			//������Ƿ����ã�1=���ã�0=������
	quint8	byRequestPhaseNo;	//������λ��
	quint8	byRequestPhaseType;	//������λ����  0-�޶��壬1-��������λ��2-������λ��3-������λ��4-�ǻ�������λ
	quint8	byReservePara1;		//��������1/////bit0=Det_Presence
	quint8	byReservePara2;		//��������2	
	quint8	byReservePara3;		//��������3
	quint8	byReservePara4;		//��������4
	quint8	byReservePara5;		//��������5
}STRUCT_DETECTOR_PEDESTRAINS;

struct type_pedestrain_detetcor
{
	type_pedestrain_detetcor::type_pedestrain_detetcor():id_fun(FUN_DEC_PED), count_pedestrain_detectors(0)
	{
		memset(detectorPedestrain, 0, sizeof(detectorPedestrain));
	}
	quint32 id_fun; 
	quint8 count_pedestrain_detectors;//��Ч�Ļ���������
	STRUCT_DETECTOR_PEDESTRAINS detectorPedestrain[MAX_PEDESTRIAN_DETECTORS];

};

/**********************************************************************************************************************************
	2015-12-15������ʱ�α�
**********************************************************************************************************************************/
typedef	 struct
{
	quint32	StartTime;		//��ʼʱ�� ��λ��
	quint32	EndTime;		//����ʱ�� ��λ��
	quint8 byPlanNumber;	//ʱ�ζ�Ӧ�ķ�����
	quint8 byTransPlanNo;	//�����ʱ��ʱ��Ҫִ�еĹ��ɷ�����
	quint8 byReservePara1;	//��������1
	quint8 byReservePara2;	//��������2
	quint8 byReservePara3;	//��������3
	quint8 byReservePara4;	//��������4
	quint8 byReservePara5;	//��������5
	quint8 byReservePara6;	//��������6
	quint8 byReservePara7;	//��������7
	quint8 byReservePara8;	//��������8
}type_period;

 struct type_protocol_period
{
	type_protocol_period::type_protocol_period():id_fun(FUN_PERIOD), count_period(0)
	{
		memset(period, 0, sizeof(period));
	}
	quint32 id_fun;
	quint8	count_period;		//��Ч��ʱ�θ���;
	type_period period[MAX_PERIODS];
};

/**********************************************************************************************************************************
	2015-12-15��	���������������10������ÿ�����������������
**********************************************************************************************************************************/
typedef	 struct
{
	quint8 no;//�����
	quint8	byStartPhase;	//��ʼ��λ
	quint8 count_stage;//��Ч�׶��� //���� 2016��04��16�� ����
	quint8	bySequence[MAX_RINGS][MAX_PHASES];

}type_sequence;

struct type_protocol_sequence
{
	type_protocol_sequence::type_protocol_sequence():id_fun(FUN_PH_SEQ), count_sequence(0)
	{
		memset(sequence, 0, sizeof(sequence));
	}
	quint32 id_fun;
	quint8	count_sequence;		//��Ч���������;
	type_sequence sequence[MAX_PHASE_SEQUENCES];
} ;


/**********************************************************************************************************************************
	2015-12-15�� ���ӹ��ȷ������� ���֧��10�����ȷ�����ÿ�����ȷ�����������
**********************************************************************************************************************************/
typedef struct 
{
	quint8 byTransitionPlanNo;	//���ɷ�����
	quint8 byLastPhaseNo;		//��Ҫ��������λ
	quint8 byReservePara1;	//��������1
	quint8 byReservePara2;	//��������2
	quint8 byReservePara3;	//��������3
	quint8 byReservePara4;	//��������4
	quint8 byReservePara5;	//��������5
	quint8 byReservePara6;	//��������6
	quint8 byReservePara7;	//��������7
	quint8 byReservePara8;	//��������8

}  type_transitionPlan;

struct type_protocol_transitionPlan
{
	type_protocol_transitionPlan::type_protocol_transitionPlan():id_fun(FUN_PLAN_TRAN), count_transPlan(0)
	{
		memset(transPlan, 0, sizeof(transPlan));
	}
	quint32 id_fun;
	quint8 count_transPlan;	//��Ч���ɷ�����
	type_transitionPlan transPlan[MAX_TRANSITION_PLANS];
} ;

// ����
typedef	struct
{
	quint16 byPlanNumber;			//��ӷ�����
	quint8 count_phase;				//��Ч��λ��
	quint8 byControlType;			//���Ʒ�ʽ

	quint8 byIsEnableGreenMatix;	//�Ƿ������̵Ƽ������
	quint8 bySequenceNo;					 //�����  //���� 2016��4��16�� ����
	quint8 byStartPhaseNo;			//������Чʱ�����ȿ�ʼ����λ��
	quint16 cycleTime;				//���ڳ�
	quint16 offset;					//���ڿ�ʼ��ʱ��ƫ�ƣ����������ڳ�
	quint16 switchPoint;			//�����л��㣬���������ڳ�
	
	STRUCT_PHASE phase[MAX_PHASES];
	
	quint8 byReservePara1;			//��������1
	quint8 byReservePara2;			//��������2
	quint8 byReservePara3;			//��������3
	quint8 byReservePara4;			//��������4
	quint8 byReservePara5;			//��������5

}type_plan;

// ����
#pragma pack(1)
struct type_protocol_plan
{
	type_protocol_plan::type_protocol_plan():id_fun(FUN_PLAN),count_plan(0)
	{
		memset(plan, 0, sizeof(plan));
	}
	const quint32 id_fun;
	quint8 count_plan;  //��Ч�ķ�������;
	type_plan plan[MAX_PLAN_NUMBER];
} ;
//����-�̵Ƽ������
//###########################  �̵Ƽ������ intergreenmatrices#################################//
 struct type_unit_matrices
{
	int no;				//�̵Ƽ��������;
	int ph_count;		//��Ч����λ����;
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
	quint32 time_t;			//ʱ������;
};


typedef struct
{

	type_version version;		//�汾��;
	type_addr_conf address;	//��ַ����
	type_protocol_plan plan;	//����

	//����ӵ���
	type_protocol_period period;			//ʱ�α�;
	type_protocol_transitionPlan plan_tran;		//���ɷ�����;
	type_protocol_sequence ph_seq;		//�����
	type_pedestrain_detetcor dec_ped;	//���˼����
	type_bus_detetcor dec_bus;			//���������
	type_vehicle_detetcor dec_veh;		//�����������
	type_protocol_matrices matrices;				//�̵Ƽ��;
	type_date_time date_time;			//��ʱ;
}type_fun_conf;

typedef struct
{
	quint8 head;				//��ͷ
	quint32  total_size;		//�ܳ���
	quint32 reserve;			//����
	quint16 addr;			//�źŻ���ַ
	quint8 ctrl;				//��д����
	quint16 type_fun;		//�������ͺ�
	quint8 data;
}type_frame_head;



//////////////////////////////////////////////////////////////////////////
//����Ϊ������ ���򡢼���������ݵĽṹ�嶨��
//////////////////////////////////////////////////////////////////////////

//��������
struct SquenceData
{
	SquenceData():nId(0)
	{
		memset(strName, 0, sizeof(strName));
		memset(&squence, 0, sizeof(squence));
	}
	int nId;
	char strName[128];
	bool isConfiged;		//�Ƿ���������λ
	type_sequence		squence;			//��������
};
//���������������
struct DetectorVehicleData
{
	DetectorVehicleData()
	{
		memset(strName, 0, sizeof(strName));
		memset(&detector, 0, sizeof(detector));
	}
	char strName[128];			//���������
	STRUCT_DETECTOR_VEHICLE detector;		//�������ʵ������
};

//���������������
struct DetectorBusData
{
	DetectorBusData()
	{
		memset(strName, 0, sizeof(strName));
		memset(&detector, 0, sizeof(detector));
	}
	char strName[128];
	STRUCT_DETECTOR_BUS detector;			//�����ʵ������
};

//���˼��������
struct DetectorsPedestrainsData
{
	DetectorsPedestrainsData()
	{
		memset(strName, 0, sizeof(strName));
		memset(&detector, 0, sizeof(detector));
	}
	char strName[128];
	STRUCT_DETECTOR_PEDESTRAINS detector;			//�����ʵ������
};

//���ɷ���:�������飨��λ)
struct TranslationPlanData
{
	TranslationPlanData()
	{
		memset(strName, 0, sizeof(strName));
		memset(&translationPlan, 0, sizeof(translationPlan));
	}

	char strName[128];				//���ɷ�������
	type_transitionPlan translationPlan;			//���ɷ�������
};

//ʱ���������ݣ������ڷ����ź͹��ɷ����š�
struct PeriodData
{
	PeriodData():nId(0)
	{
		memset(strName, 0, sizeof(strName));
		memset(&period, 0, sizeof(period));
	}
	int nId;					//id���
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
/*���º���ΪЭ�������������                                                        */
/************************************************************************/
extern type_fun_conf global_fun_config;

int do_fram(quint8 *frm_in, int len, type_fun_conf &fun_config, quint32 &id_fun);		//��������֡, ���ؿ������͡����źŻ�ͨ�ţ�ֻ��һ��Unit��Ԫ�����ԣ����Ի�ȡ��id_fun�ж���Ϣ���͡�

int check_frame(quint8 *frm_in,int len);	//�������֡�Ƿ�Ϸ�;

int check_sum(quint8 *data,int size);		//����У���

int check_size_unit(quint8 *data,int size);		//������ݶ��·�unit���ֽںͼ�����ֽ��Ƿ�һ��

quint8 *get_ptr_data(quint8 *frm);		//�������ݶε���ָ��

int get_len_data(quint8 *frm);				//�������ݶεĳ���

int set_data_conf_from_stream(quint8 *data,int size,type_fun_conf &fun_config, quint32 &id_fun);		//���ݻ�ȡ�������ݶΣ��������ݵ�fun_config��

int set_unit_conf(quint8 *unit,int size,type_fun_conf &fun_config, quint32 &id_fun);	//��������unit������;

void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);


bool sgsDataLessThan(const SgData data1, const SgData data2);


#endif // COMMON

