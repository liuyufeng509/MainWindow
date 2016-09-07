#include "common.h"
#include <QString>

type_fun_conf  global_fun_config;			//�������Э���������������

quint16 caclLenth(int beg, int end, int cycle)
{
	if (beg>=end)
	{
		 return (end + cycle - beg);
	}else
	{
		return  (end - beg);
	}
}
quint16 checkBegin(int beg, int cycle)
{
	if (beg<0)
	{
		return (beg+cycle);
	}else 	if (beg>=0)
	{
		if (beg>=cycle)
		{
			//return (cycle-beg);
			return (beg-cycle);
		}else
		{
			return beg;
		}
	}
}

void getInfo(SgDataInProg &sgDataInProg, STRUCT_PHASE &data, int cycle)
{
	for (int k=0; k<sgDataInProg.cmds.size(); k++)
	{
		if (sgDataInProg.cmds[k].nBegin>=cycle)
		{
			sgDataInProg.cmds[k].nBegin = sgDataInProg.cmds[k].nBegin-cycle;		//�����ʼʱ����ڻ�������ڴ�Сʱ������һ������
		}

		if (sgDataInProg.cmds[k].nDisplay==Red)
		{
			data.byRedBegin = sgDataInProg.cmds[k].nBegin;
		}
		if (sgDataInProg.cmds[k].nDisplay==Green)
		{
			data.byGreenBegin = sgDataInProg.cmds[k].nBegin;
		}
		if (sgDataInProg.cmds[k].nDisplay==Flash_Amber)
		{
			data.byAmberFlashBegin = sgDataInProg.cmds[k].nBegin;
		}
		if (sgDataInProg.cmds[k].nDisplay==OFF)
		{
			data.byOffBegin = sgDataInProg.cmds[k].nBegin;
		}
		if (sgDataInProg.cmds[k].nDisplay==Flash_Red)
		{
			data.byRedFlashBegin = sgDataInProg.cmds[k].nBegin;
		}
	}
	for (int k = 0; k < sgDataInProg.fixedStates.size(); k++)
	{
		if (sgDataInProg.fixedStates[k].nDisplay==Red_Amber)
		{
			data.byRedAmberDuration = sgDataInProg.fixedStates[k].nDuration;
		}
		if (sgDataInProg.fixedStates[k].nDisplay==Amber)
		{
			data.byAmberDuration = sgDataInProg.fixedStates[k].nDuration;
		}
		if (sgDataInProg.fixedStates[k].nDisplay==Flash_Green)
		{
			data.byGreenFlashDuration = sgDataInProg.fixedStates[k].nDuration;
		}
		if (sgDataInProg.fixedStates[k].nDisplay==Flash_Red)
		{
			data.byRedFlashDuration = sgDataInProg.fixedStates[k].nDuration;
		}
	}
}

void localDataToStreamData(QVector<SgData> &sgdatas, QVector<InterGreenMatrixData>&interGreenDatas, QVector<SignalProgData>&sgProgDatas, 
						   QVector<SquenceData> &squenceDatas,QVector<DetectorVehicleData>&detectorVehicleData,QVector<DetectorBusData> &detectorBusDatas,
						   QVector<DetectorsPedestrainsData> &detectorPedestainsDatas,QVector<TranslationPlanData>	&translationDatas,QVector<PeriodData>&periodDatas, 
						   type_fun_conf &dataInfo)
{

	//�������
	type_fun_conf data;
	//���ݷ���������䷽��
	data.plan.count_plan = sgProgDatas.size();
	for (int i=0; i<sgProgDatas.size(); i++)
	{
		data.plan.plan[i].count_phase = sgdatas.size();
		data.plan.plan[i].byPlanNumber = sgProgDatas[i].nId;
		data.plan.plan[i].byControlType = sgProgDatas[i].ctrlType;
		data.plan.plan[i].byIsEnableGreenMatix = sgProgDatas[i].nInterGreens;
		data.plan.plan[i].byStartPhaseNo = sgProgDatas[i].startPhase;
		data.plan.plan[i].cycleTime = sgProgDatas[i].nCycleTime;
		data.plan.plan[i].offset = sgProgDatas[i].nOffset;
		data.plan.plan[i].switchPoint = sgProgDatas[i].nSwitchPoint;
		data.plan.plan[i].bySequenceNo = sgProgDatas[i].nSequenceNo;
		//��������ȫ������
		data.plan.plan[i].byReservePara1 = 0;
		data.plan.plan[i].byReservePara2 = 0;
		data.plan.plan[i].byReservePara3 = 0;
		data.plan.plan[i].byReservePara4 = 0;
		data.plan.plan[i].byReservePara5 = 0;

		int cycle = sgProgDatas[i].nCycleTime;
		for (int j=0; j<sgProgDatas[i].sgDatasInProg.size(); j++)
		{
			data.plan.plan[i].phase[j].byPhaseNo = sgProgDatas[i].sgDatasInProg[j].nSgId;
			data.plan.plan[i].phase[j].byPhaseType = sgProgDatas[i].sgDatasInProg[j].nPhaseType;
			data.plan.plan[i].phase[j].byColorSequence = sgProgDatas[i].sgDatasInProg[j].nSignalSequence;
			data.plan.plan[i].phase[j].byIsCoordinate = sgProgDatas[i].sgDatasInProg[j].byIsCoordinate;
			data.plan.plan[i].phase[j].byMinGreenTime = sgProgDatas[i].sgDatasInProg[j].byMinGreenTime;
			data.plan.plan[i].phase[j].byMax1GreenTime = sgProgDatas[i].sgDatasInProg[j].byMax1GreenTime;
			data.plan.plan[i].phase[j].byMax2GreenTime = sgProgDatas[i].sgDatasInProg[j].byMax2GreenTime;
			data.plan.plan[i].phase[j].byGreenTimeExtendEachTime = sgProgDatas[i].sgDatasInProg[j].byGreenTimeExtendEachTime;

			getInfo(sgProgDatas[i].sgDatasInProg[j], data.plan.plan[i].phase[j], cycle);
		
			switch (data.plan.plan[i].phase[j].byColorSequence)
			{
			case COLOR_SEQU_ALL_RED:
				{
					data.plan.plan[i].phase[j].byRedDuration = sgProgDatas[i].nCycleTime-data.plan.plan[i].phase[j].byRedBegin;
				}
				break;
			case COLOR_SEQU_ALL_GREEN:
				{
					data.plan.plan[i].phase[j].byGreenDuration = sgProgDatas[i].nCycleTime - data.plan.plan[i].phase[j].byGreenBegin;
				}
				break;
			case COLOR_SEQU_RED_REDAMBER_GREEN_AMBER:
				{
					int redEnd = data.plan.plan[i].phase[j].byGreenBegin-data.plan.plan[i].phase[j].byRedAmberDuration;
					int greenEnd=data.plan.plan[i].phase[j].byRedBegin - data.plan.plan[i].phase[j].byAmberDuration;
					data.plan.plan[i].phase[j].byRedDuration = caclLenth(data.plan.plan[i].phase[j].byRedBegin, redEnd, cycle);
					data.plan.plan[i].phase[j].byGreenDuration = caclLenth(data.plan.plan[i].phase[j].byGreenBegin, greenEnd, cycle);
					data.plan.plan[i].phase[j].byRedAmberBegin = checkBegin(redEnd, cycle);
					data.plan.plan[i].phase[j].byAmberBegin = checkBegin(greenEnd, cycle);
// 					qCritical()<<"RED_REDAMBER_GREEN_AMBER: redEnd="<<redEnd<<" greenEnd="<<greenEnd<<" cycle="<<cycle<<"\n"
// 						<<" data.plan.plan["<<i<<"].phase["<<j<<"].byRedAmberBegin="<<(int)data.plan.plan[i].phase[j].byRedAmberBegin
// 						<<" data.plan.plan["<<i<<"].phase["<<j<<"].byAmberBegin="<<(int)data.plan.plan[i].phase[j].byAmberBegin;
				}
				break;
			case COLOR_SEQU_RED_GREEN:
				{
					data.plan.plan[i].phase[j].byRedDuration = caclLenth(data.plan.plan[i].phase[j].byRedBegin, data.plan.plan[i].phase[j].byGreenBegin, cycle);
					data.plan.plan[i].phase[j].byGreenDuration = caclLenth(data.plan.plan[i].phase[j].byGreenBegin, data.plan.plan[i].phase[j].byRedBegin, cycle);
				}
				break;
			case COLOR_SEQU_RED_REDAMBER_GREEN_GREENFLASH_AMBER:
				{
					int redEnd = data.plan.plan[i].phase[j].byGreenBegin-data.plan.plan[i].phase[j].byRedAmberDuration;
					int greenEnd=data.plan.plan[i].phase[j].byRedBegin - data.plan.plan[i].phase[j].byAmberDuration - data.plan.plan[i].phase[j].byGreenFlashDuration;
					data.plan.plan[i].phase[j].byRedDuration = caclLenth(data.plan.plan[i].phase[j].byRedBegin, redEnd, cycle);
					data.plan.plan[i].phase[j].byGreenDuration = caclLenth(data.plan.plan[i].phase[j].byGreenBegin, greenEnd, cycle);

					data.plan.plan[i].phase[j].byRedAmberBegin = checkBegin(redEnd, cycle);
					data.plan.plan[i].phase[j].byAmberBegin = checkBegin(greenEnd+data.plan.plan[i].phase[j].byGreenFlashDuration, cycle);
					data.plan.plan[i].phase[j].byGreenFlashBegin = checkBegin(greenEnd, cycle);

// 					qCritical()<<"COLOR_SEQU_RED_REDAMBER_GREEN_GREENFLASH_AMBER: redEnd="<<redEnd<<" greenEnd="<<greenEnd<<"greenEnd+byGreenFlashDuration="<<greenEnd+data.plan.plan[i].phase[j].byGreenFlashDuration <<" cycle="<<cycle<<"\n"
// 						<<" data.plan.plan["<<i<<"].phase["<<j<<"].byRedAmberBegin="<<(int)data.plan.plan[i].phase[j].byRedAmberBegin
// 						<<" data.plan.plan["<<i<<"].phase["<<j<<"].byAmberBegin="<<(int)data.plan.plan[i].phase[j].byAmberBegin
// 						<<" data.plan.plan["<<i<<"].phase["<<j<<"].byGreenFlashBegin="<<(int)data.plan.plan[i].phase[j].byGreenFlashBegin;
				}
				break;
			case COLOR_SEQU_RED_GREEN_GREENFLASH:
				{
					int redEnd = data.plan.plan[i].phase[j].byGreenBegin;
					int greenEnd=data.plan.plan[i].phase[j].byRedBegin- data.plan.plan[i].phase[j].byGreenFlashDuration;
					data.plan.plan[i].phase[j].byRedDuration = caclLenth(data.plan.plan[i].phase[j].byRedBegin, redEnd, cycle);
					data.plan.plan[i].phase[j].byGreenDuration = caclLenth(data.plan.plan[i].phase[j].byGreenBegin, greenEnd, cycle);
					data.plan.plan[i].phase[j].byGreenFlashBegin = checkBegin(greenEnd, cycle);
// 					qCritical()<<"COLOR_SEQU_RED_GREEN_GREENFLASH: greenEnd="<<greenEnd<<" cycle="<<cycle<<"\n"
// 						<<" data.plan.plan["<<i<<"].phase["<<j<<"].byGreenFlashBegin="<<(int)data.plan.plan[i].phase[j].byGreenFlashBegin;
				}
				break;
			case COLOR_SEQU_RED_GREEN_AMBER:
				{
					int redEnd = data.plan.plan[i].phase[j].byGreenBegin;
					int greenEnd=data.plan.plan[i].phase[j].byRedBegin- data.plan.plan[i].phase[j].byAmberDuration;
					data.plan.plan[i].phase[j].byRedDuration = caclLenth(data.plan.plan[i].phase[j].byRedBegin, redEnd, cycle);
					data.plan.plan[i].phase[j].byGreenDuration = caclLenth(data.plan.plan[i].phase[j].byGreenBegin, greenEnd, cycle);
					data.plan.plan[i].phase[j].byAmberBegin = checkBegin(greenEnd, cycle);
// 					qCritical()<<"COLOR_SEQU_RED_GREEN_AMBER: greenEnd="<<greenEnd<<" cycle="<<cycle<<"\n"
// 						<<" data.plan.plan["<<i<<"].phase["<<j<<"].byAmberBegin="<<(int)data.plan.plan[i].phase[j].byAmberBegin;
				}
				break;
			case COLOR_SEQU_AMBERFLASH:
				{
					data.plan.plan[i].phase[j].byAmberFlashDuration = sgProgDatas[i].nCycleTime - data.plan.plan[i].phase[j].byAmberFlashBegin;
				}
				break;
			case COLOR_SEQU_OFF:
				{
					data.plan.plan[i].phase[j].byOffDuration = sgProgDatas[i].nCycleTime - data.plan.plan[i].phase[j].byOffBegin;
				}
				break;
			case COLOR_SEQU_RED_OFF:
				{
					int redEnd = data.plan.plan[i].phase[j].byOffBegin;
					int offend=data.plan.plan[i].phase[j].byRedBegin;
					data.plan.plan[i].phase[j].byRedDuration = caclLenth(data.plan.plan[i].phase[j].byRedBegin, redEnd, cycle);
					data.plan.plan[i].phase[j].byOffDuration = caclLenth(data.plan.plan[i].phase[j].byOffBegin, offend, cycle);
				}
				break;
			case COLOR_SEQU_RED_OFF_AMBER:
				{
					int redEnd = data.plan.plan[i].phase[j].byOffBegin;
					int offend=data.plan.plan[i].phase[j].byRedBegin;
					data.plan.plan[i].phase[j].byRedDuration = caclLenth(data.plan.plan[i].phase[j].byRedBegin, redEnd, cycle);
					data.plan.plan[i].phase[j].byOffDuration = caclLenth(data.plan.plan[i].phase[j].byOffBegin, offend, cycle);
					data.plan.plan[i].phase[j].byAmberBegin = checkBegin(offend, cycle);
// 					qCritical()<<"COLOR_SEQU_RED_OFF_AMBER: offend="<<offend<<" cycle="<<cycle<<"\n"
// 						<<" data.plan.plan["<<i<<"].phase["<<j<<"].byAmberBegin="<<(int)data.plan.plan[i].phase[j].byAmberBegin;
				}
				break;
			case COLOR_SEQU_OFF_GREEN:
				{
					int greenEnd = data.plan.plan[i].phase[j].byOffBegin;
					int offend=data.plan.plan[i].phase[j].byGreenBegin;
					data.plan.plan[i].phase[j].byGreenDuration= caclLenth(data.plan.plan[i].phase[j].byGreenBegin, greenEnd, cycle);
					data.plan.plan[i].phase[j].byOffDuration = caclLenth(data.plan.plan[i].phase[j].byOffBegin, offend, cycle);
				}
				break;
			case COLOR_SEQU_AMBERFLASH_OFF:
				{
					int amberFlashEnd = data.plan.plan[i].phase[j].byOffBegin;
					int offend=data.plan.plan[i].phase[j].byAmberFlashBegin;
					data.plan.plan[i].phase[j].byAmberDuration= caclLenth(data.plan.plan[i].phase[j].byAmberBegin, amberFlashEnd, cycle);
					data.plan.plan[i].phase[j].byOffDuration = caclLenth(data.plan.plan[i].phase[j].byOffBegin, offend, cycle);
				}
				break;
			case COLOR_SEQU_RED_GREEN_REDFLASH:
				{
					int redEnd = data.plan.plan[i].phase[j].byGreenBegin;
					int greenEnd=data.plan.plan[i].phase[j].byRedBegin- data.plan.plan[i].phase[j].byRedFlashDuration;
					data.plan.plan[i].phase[j].byRedDuration = caclLenth(data.plan.plan[i].phase[j].byRedBegin, redEnd, cycle);
					data.plan.plan[i].phase[j].byGreenDuration = caclLenth(data.plan.plan[i].phase[j].byGreenBegin, greenEnd, cycle);
					data.plan.plan[i].phase[j].byRedFlashBegin= checkBegin(greenEnd, cycle);
// 					qCritical()<<"COLOR_SEQU_RED_GREEN_REDFLASH: greenEnd="<<greenEnd<<" cycle="<<cycle<<"\n"
// 						<<" data.plan.plan["<<i<<"].phase["<<j<<"].byRedFlashBegin="<<(int)data.plan.plan[i].phase[j].byRedFlashBegin;
				}
				break;
			case COLOR_SEQU_REDFLASH_OFF:
				{
					int redFlashEnd = data.plan.plan[i].phase[j].byOffBegin;
					int offend=data.plan.plan[i].phase[j].byRedFlashBegin;
					data.plan.plan[i].phase[j].byRedFlashDuration= caclLenth(data.plan.plan[i].phase[j].byAmberBegin, redFlashEnd, cycle);
					data.plan.plan[i].phase[j].byOffDuration = caclLenth(data.plan.plan[i].phase[j].byOffBegin, offend, cycle);
				}
				break;
			default:
				break;
			}
		}
	}
	
	//���ݶ��У�����������
	data.ph_seq.count_sequence = squenceDatas.size();
	for (int i=0; i<squenceDatas.size(); i++)
	{
		data.ph_seq.sequence[i] = squenceDatas[i].squence;
	}

	//���ݹ���������������������
	data.dec_veh.count_vehicle_detectors = detectorVehicleData.size();
	for(int i=0; i<data.dec_veh.count_vehicle_detectors; i++)
	{
		data.dec_veh.detectorVehicle[i] = detectorVehicleData[i].detector;
	}

	//���ݹ���������������������
	data.dec_bus.count_vehicle_detectors = detectorBusDatas.size();
	for(int i=0; i<data.dec_bus.count_vehicle_detectors; i++)
	{
		data.dec_bus.detectorBUS[i] = detectorBusDatas[i].detector;
	}

	//�������˼�����������������
	data.dec_ped.count_pedestrain_detectors = detectorPedestainsDatas.size();
	for(int i=0; i<data.dec_ped.count_pedestrain_detectors; i++)
	{
		data.dec_ped.detectorPedestrain[i] = detectorPedestainsDatas[i].detector;
	}

	//���ݹ��ɷ����������������
	data.plan_tran.count_transPlan = translationDatas.size();
	for (int i=0; i<data.plan_tran.count_transPlan; i++)
	{
		data.plan_tran.transPlan[i] = translationDatas[i].translationPlan;
	}

	//����ʱ���������������
	data.period.count_period = periodDatas.size();
	for (int i=0; i<data.period.count_period; i++)
	{
		data.period.period[i] = periodDatas[i].period;
	}

	//�̵Ƽ������
	data.matrices.count = interGreenDatas.size();
	for (int i=0; i<data.matrices.count; i++)
	{
		data.matrices.matrix[i].no = interGreenDatas[i].nId;
		data.matrices.matrix[i].ph_count = interGreenDatas[i].interGreens.size();
		memset(data.matrices.matrix[i].intergreenmatrices, -127, sizeof(data.matrices.matrix[i].intergreenmatrices));
		for (int j=0; j<interGreenDatas[i].interGreens.size(); j++)
		{
			data.matrices.matrix[i].intergreenmatrices[interGreenDatas[i].interGreens[j].nEnteringSg-1][interGreenDatas[i].interGreens[j].nClearingSg-1] = interGreenDatas[i].interGreens[j].nValue;
		}
	}

	ofstream out;
	out.open("data.txt", ofstream::out);
	if (out)
	{
		out<<"##########################data Matrix print begin###############################"<<endl;
		out<<"data.matrices.count_matrix="<<(int)data.matrices.count<<endl;
		for (int i=0; i<data.matrices.count;i++)
		{
			out<<"data.matrices.matrix[i].ph_count="<<data.matrices.matrix[i].ph_count<<endl;
			out<<"data.matrices.matrix[i].no="<<data.matrices.matrix[i].no<<endl;
			for (int j=0; j<MAX_PHASES; j++)
			{
				out<<"data.matrices.matrix["<<i<<"].intergreenmatrices["<<j<<"]= {"<<flush;
				for (int k=0; k<MAX_PHASES; k++)
				{
					out<<" "<<(int)data.matrices.matrix[i].intergreenmatrices[j][k]<<flush;
				}
				out<<" }"<<endl;
			}
		}
		out<<"##########################data Matrix print end################################"<<endl;

		out<<"*****************************************data Plan print begin*******************************************"<<endl;
		out<<"data.plan.count_plan="<<(int)data.plan.count_plan<<endl;
		for (int i=0; i<sgProgDatas.size();i++)
		{
			out<<"data.plan.plan["<<i<<"].count_phase= "<<(int)data.plan.plan[i].count_phase<<endl;
			out<<"data.plan.plan["<<i<<"].byPlanNumber="<<(int)data.plan.plan[i].byControlType<<endl;
			out<<"data.plan.plan["<<i<<"].byControlType="<<(int)data.plan.plan[i].byControlType<<endl;
			out<<"data.plan.plan["<<i<<"].byIsEnableGreenMatix="<<(int)data.plan.plan[i].byIsEnableGreenMatix<<endl;
			out<<"data.plan.plan["<<i<<"].byStartPhaseNo="<<(int)data.plan.plan[i].byStartPhaseNo<<endl;
			out<<"data.plan.plan["<<i<<"].cycleTime="<<(int)data.plan.plan[i].cycleTime<<endl;
			out<<"data.plan.plan["<<i<<"].offset="<<(int)data.plan.plan[i].offset<<endl;
			out<<"data.plan.plan["<<i<<"].switchPoint="<<(int)data.plan.plan[i].switchPoint<<endl;

			for(int j=0; j<data.plan.plan[i].count_phase; j++)
			{
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byPhaseNo="<<(int)data.plan.plan[i].phase[j].byPhaseNo<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byPhaseType="<<(int)data.plan.plan[i].phase[j].byPhaseType<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byColorSequence="<<(int)data.plan.plan[i].phase[j].byColorSequence<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byRedDuration="<<(int)data.plan.plan[i].phase[j].byRedDuration<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byRedAmberDuration="<<(int)data.plan.plan[i].phase[j].byRedAmberDuration<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byGreenDuration="<<(int)data.plan.plan[i].phase[j].byGreenDuration<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byAmberDuration="<<(int)data.plan.plan[i].phase[j].byAmberDuration<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byGreenFlashDuration="<<(int)data.plan.plan[i].phase[j].byGreenFlashDuration<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byAmberFlashDuration="<<(int)data.plan.plan[i].phase[j].byAmberFlashDuration<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byOffDuration="<<(int)data.plan.plan[i].phase[j].byOffDuration<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byRedFlashDuration="<<(int)data.plan.plan[i].phase[j].byRedFlashDuration<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byIsCoordinate="<<(int)data.plan.plan[i].phase[j].byIsCoordinate<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byMinGreenTime="<<(int)data.plan.plan[i].phase[j].byMinGreenTime<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byMax1GreenTime="<<(int)data.plan.plan[i].phase[j].byMax1GreenTime<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byMax2GreenTime="<<(int)data.plan.plan[i].phase[j].byMax2GreenTime<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byGreenTimeExtendEachTime="<<(int)data.plan.plan[i].phase[j].byGreenTimeExtendEachTime<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byRedBegin="<<(int)data.plan.plan[i].phase[j].byRedBegin<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byRedAmberBegin="<<(int)data.plan.plan[i].phase[j].byRedAmberBegin<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byGreenBegin="<<(int)data.plan.plan[i].phase[j].byGreenBegin<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byAmberBegin="<<(int)data.plan.plan[i].phase[j].byAmberBegin<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byGreenFlashBegin="<<(int)data.plan.plan[i].phase[j].byGreenFlashBegin<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byAmberFlashBegin="<<(int)data.plan.plan[i].phase[j].byAmberFlashBegin<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byOffBegin="<<(int)data.plan.plan[i].phase[j].byOffBegin<<endl;
				out<<"data.plan.plan["<<i<<"].phase["<<j<<"].byRedFlashBegin="<<(int)data.plan.plan[i].phase[j].byRedFlashBegin<<endl;
			}
			out<<"****************************************************************************************"<<endl;
		}
		out<<"*****************************************data Plan print end*******************************************"<<endl;

		out<<"##########################data Squence print begin###############################"<<endl;
		out<<"data.ph_seq.count_sequence="<<(int)data.ph_seq.count_sequence<<endl;
		for (int i=0; i<data.ph_seq.count_sequence;i++)
		{
			out<<"data.ph_seq.sequence["<<i<<"].byStartPhase= "<<(int)data.ph_seq.sequence[i].byStartPhase<<endl;
			out<<"data.ph_seq.sequence["<<i<<"].bySequence=";
			for (int j=0; j<MAX_RINGS; j++)
			{
				for (int k=0; k<MAX_PHASES; k++)
				{
					out<<" "<<(int)data.ph_seq.sequence[i].bySequence[j][k];
				}
			}
			out<<endl;
		}
		out<<"##########################data Squence print end################################"<<endl;

		out<<"*****************************************data DetectVeh print begin*******************************************"<<endl;
		out<<"data.dec_veh.count_vehicle_detectors="<<(int)data.dec_veh.count_vehicle_detectors<<endl;
		for (int i=0; i<data.dec_veh.count_vehicle_detectors;i++)
		{
			out<<"data.dec_veh.detectorVehicle["<<i<<"].byDetectorNo= "<<(int)data.dec_veh.detectorVehicle[i].byDetectorNo<<endl;
			out<<"data.dec_veh.detectorVehicle["<<i<<"].byEnable= "<<(int)data.dec_veh.detectorVehicle[i].byEnable<<endl;
			out<<"data.dec_veh.detectorVehicle["<<i<<"].byRequestPhaseNo= "<<(int)data.dec_veh.detectorVehicle[i].byRequestPhaseNo<<endl;
			out<<"data.dec_veh.detectorVehicle["<<i<<"].byRequestPhaseType= "<<(int)data.dec_veh.detectorVehicle[i].byRequestPhaseType<<endl;
			out<<"data.dec_veh.detectorVehicle["<<i<<"].byParamEnableFlag= "<<(int)data.dec_veh.detectorVehicle[i].byParamEnableFlag<<endl;
		}
		out<<"*****************************************data DetectVeh print end*******************************************"<<endl;

		out<<"##########################data DetectBus print begin###############################"<<endl;
		out<<"data.dec_bus.count_vehicle_detectors="<<(int)data.dec_bus.count_vehicle_detectors<<endl;
		for (int i=0; i<data.dec_bus.count_vehicle_detectors;i++)
		{
			out<<"data.dec_bus.detectorBUS["<<i<<"].byDetectorNo= "<<(int)data.dec_bus.detectorBUS[i].byDetectorNo<<endl;
			out<<"data.dec_bus.detectorBUS["<<i<<"].byEnable= "<<(int)data.dec_bus.detectorBUS[i].byEnable<<endl;
			out<<"data.dec_bus.detectorBUS["<<i<<"].byRequestPhaseNo= "<<(int)data.dec_bus.detectorBUS[i].byRequestPhaseNo<<endl;
			out<<"data.dec_bus.detectorBUS["<<i<<"].byRequestPhaseType= "<<(int)data.dec_bus.detectorBUS[i].byRequestPhaseType<<endl;
			out<<"data.dec_bus.detectorBUS["<<i<<"].byParamEnableFlag= "<<(int)data.dec_bus.detectorBUS[i].byParamEnableFlag<<endl;
		}
		out<<"##########################data DetectBus print end###############################"<<endl;

		out<<"*****************************************data DetectPed print begin*******************************************"<<endl;
		out<<"data.dec_ped.count_pedestrain_detectors="<<(int)data.dec_ped.count_pedestrain_detectors<<endl;
		for (int i=0; i<data.dec_ped.count_pedestrain_detectors;i++)
		{
			out<<"data.dec_veh.detectorPedestrain["<<i<<"].byDetectorNo= "<<(int)data.dec_ped.detectorPedestrain[i].byDetectorNo<<endl;
			out<<"data.dec_veh.detectorPedestrain["<<i<<"].byEnable= "<<(int)data.dec_ped.detectorPedestrain[i].byEnable<<endl;
			out<<"data.dec_veh.detectorPedestrain["<<i<<"].byRequestPhaseNo= "<<(int)data.dec_ped.detectorPedestrain[i].byRequestPhaseNo<<endl;
			out<<"data.dec_veh.detectorPedestrain["<<i<<"].byRequestPhaseType= "<<(int)data.dec_ped.detectorPedestrain[i].byRequestPhaseType<<endl;
		}
		out<<"*****************************************data DetectPed print end*******************************************"<<endl;

		out<<"##########################data TransPlan print begin###############################"<<endl;
		out<<"data.plan_tran.count_transPlan="<<(int)data.plan_tran.count_transPlan<<endl;
		for (int i=0; i<data.plan_tran.count_transPlan;i++)
		{
			out<<"data.plan_tran.transPlan["<<i<<"].byTransitionPlanNo= "<<(int)data.plan_tran.transPlan[i].byTransitionPlanNo<<endl;
			out<<"data.plan_tran.transPlan["<<i<<"].byLastPhaseNo= "<<(int)data.plan_tran.transPlan[i].byLastPhaseNo<<endl;
		}
		out<<"##########################data TransPlan print end###############################"<<endl;

		out<<"*****************************************data Period print begin*******************************************"<<endl;
		out<<"data.period.count_period="<<(int)data.period.count_period<<endl;
		for (int i=0; i<data.period.count_period;i++)
		{
			out<<"data.period.period["<<i<<"].StartTime= "<<(int)data.period.period[i].StartTime<<endl;
			out<<"data.period.period["<<i<<"].EndTime= "<<(int)data.period.period[i].EndTime<<endl;
			out<<"data.period.period["<<i<<"].byPlanNumber= "<<(int)data.period.period[i].byPlanNumber<<endl;
			out<<"data.period.period["<<i<<"].byTransPlanNo= "<<(int)data.period.period[i].byTransPlanNo<<endl;
		}
		out<<"*****************************************data Period print end*******************************************"<<endl;

		out.close();
	}

	memcpy(&dataInfo, &data, sizeof(data));
}

void	streamDataToLocalData(QVector<SgData> &sgdatas, QVector<InterGreenMatrixData>&interGreenDatas, QVector<SignalProgData>&sgProgDatas, 
							  QVector<SquenceData> &squenceDatas,QVector<DetectorVehicleData>&detectorVehicleData,QVector<DetectorBusData> &detectorBusDatas,
							  QVector<DetectorsPedestrainsData> &detectorPedestainsDatas,QVector<TranslationPlanData>	&translationDatas,QVector<PeriodData>&periodDatas, 
							  const type_fun_conf &data, QString &errorInfo)
{
	//���������С�ڵ���0��˵���޷�������
// 	if (data.plan.count_plan<=0 ||
// 		data.matrices.count<=0||
// 		data.period.count_period<=0||
// 		data.plan_tran.count_transPlan<=0||
// 		data.ph_seq.count_sequence<=0||
// 		data.dec_bus.count_vehicle_detectors<=0||
// 		data.dec_ped.count_pedestrain_detectors<=0||
// 		data.dec_veh.count_vehicle_detectors<=0)
// 	{
		sgdatas.clear();
		interGreenDatas.clear();
		sgProgDatas.clear();
		squenceDatas.clear();
		detectorPedestainsDatas.clear();
		detectorBusDatas.clear();
		detectorVehicleData.clear();
		translationDatas.clear();
		periodDatas.clear();
// 		return;
// 	}
	if (data.plan.count_plan<=0)
	{
		errorInfo = QString::fromLocal8Bit("������Ϊ��");
	}

	//1.�ȴ����������
	if (data.plan.plan[0].count_phase>0)		//��Ϊÿ����������λ����һ����,���ԣ�ȡ��һ����������
	{
		//������λ�������λ��sgdatas�����ڣ��򴴽�һ������ӵ�������
		for (int i=0; i<data.plan.plan[0].count_phase; i++)
		{
			bool isIn = false;
			for(int j=0; j<sgdatas.size(); j++)
			{
				if (data.plan.plan[0].phase[i].byPhaseNo==sgdatas[j].nId)
				{
					isIn = true;
					break;
				}
			}
			if (!isIn)
			{
				SgData sgdata;
				int num = 0;
				for (int j=0; j<sgdatas.size(); j++)
				{
					if (num<sgdatas[j].nPrimaryId)
					{
						num = sgdatas[j].nPrimaryId;
					}
				}
				sgdata.nPrimaryId = num+1;
				sgdata.nId = data.plan.plan[0].phase[i].byPhaseNo;
				sgdata.nDefaultSignalSequence = COLOR_SEQU_RED_REDAMBER_GREEN_AMBER;
				//	InitDurationOfSgData(data);
				QString strName = QString::fromLocal8Bit("�źŵ��� %1").arg(sgdata.nId);
				qstrcpy(sgdata.strName, strName.toStdString().c_str());
				qstrcpy(sgdata.strNotes, "");
				sgdatas.push_back(sgdata);
			}
		}
		//�������飬����õ�������λ�в����ڣ���ɾ���õ��顣
		for (int i=0; i<sgdatas.size(); i++)
		{
			bool isIn = false;
			for (int j = 0; j < data.plan.plan[0].count_phase; j++)
			{
				if(sgdatas[i].nId==data.plan.plan[0].phase[j].byPhaseNo)
				{
					isIn = true;
					break;
				}
			}
			if (!isIn)
			{
				sgdatas.removeAt(i);
			}
		}
	}else
	{
		sgdatas.clear();
	}

	//��Ϊ���źŻ���������̵Ƽ�����ݣ����ԣ�ֻ��Ҫ���̵Ƽ����գ�������ֵ����
	//2.���ݵ������ݣ������̵Ƽ��:  �̵Ƽ���е���id����ʵ�����в����ڵ�Ҫɾ�����������д��ڣ��̵Ƽ�������ڵ�Ҫ��ӡ�
// 	for (int i=0; i<interGreenDatas.size(); i++)
// 	{
// 		for (int j=0; j<interGreenDatas[i].interGreens.size(); j++)
// 		{
// 			if (!isInFun(interGreenDatas[i].interGreens[j].nClearingSg, sgdatas)||
// 				!isInFun(interGreenDatas[i].interGreens[j].nEnteringSg, sgdatas))
// 			{
// 				interGreenDatas[i].interGreens.remove(j);
// 				j--;
// 			}
// 		}
// 	}
// 	for (int i=0; i<sgdatas.size(); i++)
// 	{
// 		for (int j=0; j<interGreenDatas.size(); j++)
// 		{
// 			if (!isInFun(sgdatas[i].nId, interGreenDatas[j].interGreens))
// 			{
// 				//������ڼ�������У����֮
// 				for (int k=0; k<interGreenDatas.size(); k++)
// 				{
// 					for (int n=0; n<sgdatas.size(); n++)
// 					{
// 						if (sgdatas[i].nId!= sgdatas[n].nId)
// 						{
// 							InterGreen interGreenData;
// 							interGreenData.nClearingSg = sgdatas[i].nId;
// 							interGreenData.nEnteringSg = sgdatas[n].nId;
// 							interGreenData.nValue = -127;
// 							interGreenDatas[k].interGreens.push_back(interGreenData);
// 
// 							InterGreen interGreenData2;
// 							interGreenData2.nClearingSg =  sgdatas[n].nId;
// 							interGreenData2.nEnteringSg = sgdatas[i].nId;
// 							interGreenData2.nValue = -127;
// 							interGreenDatas[k].interGreens.push_back(interGreenData2);
// 						}
// 					}
// 				}
// 			}
// 		}
// 	}

	//�������صľ������ݣ����¼������
	interGreenDatas.clear();
	for (int k=0; k<data.matrices.count; k++)
	{
		InterGreenMatrixData intdata;
		intdata.nPrimaryId = k+1;
		intdata.nId = data.matrices.matrix[k].no;
		QString strName = QString::fromLocal8Bit("�̵Ƽ������ %1").arg(intdata.nId);
		qstrcpy(intdata.strName, strName.toStdString().c_str());
		//�̼��������,�����ݵ�����źŵƸ�����ȷ������ӵľ�����̵Ƽ����
		for (int i=0; i<sgdatas.size(); i++)
		{
			for (int j=0; j<sgdatas.size(); j++)
			{
				InterGreen interGreenData;
				if (i==j)
				{
					interGreenData.nClearingSg = j+1;
					interGreenData.nEnteringSg = i+1;
					interGreenData.nValue = -127;
				}else
				{
					interGreenData.nClearingSg = j+1;
					interGreenData.nEnteringSg = i+1;
					if (data.matrices.matrix[k].intergreenmatrices[i][j]==129)
					{
						interGreenData.nValue = -127;
					}else
						interGreenData.nValue = data.matrices.matrix[k].intergreenmatrices[i][j];
				}
				intdata.interGreens.push_back(interGreenData);
			}
		}

		interGreenDatas.push_back(intdata);
	}

	//3.�������صķ������ݣ�������ʱ������
	sgProgDatas.clear();
	for (int i=0; i<data.plan.count_plan; i++)
	{
		SignalProgData sgProgData;
		sgProgData.nPrimaryId=i+1;
		sgProgData.nId = i;

		if (data.plan.plan[i].count_phase>0)
		{
			sgProgData.nId = data.plan.plan[i].byPlanNumber;		//������ڸ÷������򽫷����Ŵ���ڷ����ṹ����

			QString strName=QString::fromLocal8Bit("�ź���ʱ���� %1").arg(sgProgData.nId);
			strcpy(sgProgData.strName, strName.toStdString().c_str());
			sgProgData.nCycleTime=data.plan.plan[i].cycleTime;
			sgProgData.nSwitchPoint = data.plan.plan[i].switchPoint;
			sgProgData.nOffset = data.plan.plan[i].offset;
			sgProgData.nInterGreens = data.plan.plan[i].byIsEnableGreenMatix;
			sgProgData.countPhase = data.plan.plan[i].count_phase;
			sgProgData.ctrlType = data.plan.plan[i].byControlType;
			sgProgData.startPhase = data.plan.plan[i].byStartPhaseNo;
			sgProgData.nSequenceNo = data.plan.plan[i].bySequenceNo;

			for (int j=0; j<data.plan.plan[i].count_phase; j++)
			{
				SgDataInProg sgDataInProg;
				sgDataInProg.nSgId = data.plan.plan[i].phase[j].byPhaseNo;
				sgDataInProg.nSignalSequence = data.plan.plan[i].phase[j].byColorSequence;
				sgDataInProg.nPhaseType = data.plan.plan[i].phase[j].byPhaseType;
				sgDataInProg.byIsCoordinate = data.plan.plan[i].phase[j].byIsCoordinate;
				sgDataInProg.byMinGreenTime = data.plan.plan[i].phase[j].byMinGreenTime;
				sgDataInProg.byMax1GreenTime = data.plan.plan[i].phase[j].byMax1GreenTime;
				sgDataInProg.byMax2GreenTime = data.plan.plan[i].phase[j].byMax2GreenTime;
				sgDataInProg.byGreenTimeExtendEachTime = data.plan.plan[i].phase[j].byGreenTimeExtendEachTime;

				switch (sgDataInProg.nSignalSequence)
				{
				case COLOR_SEQU_ALL_RED:
					{
						CmdData cmdData;
						cmdData.nDisplay = Red;
						cmdData.nBegin = data.plan.plan[i].phase[j].byRedBegin;
						sgDataInProg.cmds.push_back(cmdData);
					}
					break;
				case COLOR_SEQU_ALL_GREEN:
					{
						CmdData cmdData;
						cmdData.nDisplay = Green;
						cmdData.nBegin = data.plan.plan[i].phase[j].byGreenBegin;
						sgDataInProg.cmds.push_back(cmdData);
					}
					break;
				case COLOR_SEQU_RED_REDAMBER_GREEN_AMBER:
					{
						CmdData cmdData;
						cmdData.nDisplay = Red;
						cmdData.nBegin = data.plan.plan[i].phase[j].byRedBegin;
						sgDataInProg.cmds.push_back(cmdData);
						cmdData.nDisplay = Green;
						cmdData.nBegin = data.plan.plan[i].phase[j].byGreenBegin;
						sgDataInProg.cmds.push_back(cmdData);

						FixStateData fixData;
						fixData.nDisplay = Red_Amber;
						fixData.nDuration = data.plan.plan[i].phase[j].byRedAmberDuration;
						sgDataInProg.fixedStates.push_back(fixData);
						fixData.nDisplay = Amber;
						fixData.nDuration = data.plan.plan[i].phase[j].byAmberDuration;
						sgDataInProg.fixedStates.push_back(fixData);
					}
					break;
				case COLOR_SEQU_RED_GREEN:
					{
						CmdData cmdData;
						cmdData.nDisplay = Red;
						cmdData.nBegin = data.plan.plan[i].phase[j].byRedBegin;
						sgDataInProg.cmds.push_back(cmdData);
						cmdData.nDisplay = Green;
						cmdData.nBegin = data.plan.plan[i].phase[j].byGreenBegin;
						sgDataInProg.cmds.push_back(cmdData);
					}
					break;
				case COLOR_SEQU_RED_REDAMBER_GREEN_GREENFLASH_AMBER:
					{
						CmdData cmdData;
						cmdData.nDisplay = Red;
						cmdData.nBegin = data.plan.plan[i].phase[j].byRedBegin;
						sgDataInProg.cmds.push_back(cmdData);
						cmdData.nDisplay = Green;
						cmdData.nBegin = data.plan.plan[i].phase[j].byGreenBegin;
						sgDataInProg.cmds.push_back(cmdData);

						FixStateData fixData;
						fixData.nDisplay = Red_Amber;
						fixData.nDuration = data.plan.plan[i].phase[j].byRedAmberDuration;
						sgDataInProg.fixedStates.push_back(fixData);
						fixData.nDisplay = Flash_Green;
						fixData.nDuration = data.plan.plan[i].phase[j].byGreenFlashDuration;
						sgDataInProg.fixedStates.push_back(fixData);
						fixData.nDisplay = Amber;
						fixData.nDuration = data.plan.plan[i].phase[j].byAmberDuration;
						sgDataInProg.fixedStates.push_back(fixData);
					}
					break;
				case COLOR_SEQU_RED_GREEN_GREENFLASH:
					{
						CmdData cmdData;
						cmdData.nDisplay = Red;
						cmdData.nBegin = data.plan.plan[i].phase[j].byRedBegin;
						sgDataInProg.cmds.push_back(cmdData);
						cmdData.nDisplay = Green;
						cmdData.nBegin = data.plan.plan[i].phase[j].byGreenBegin;
						sgDataInProg.cmds.push_back(cmdData);

						FixStateData fixData;
						fixData.nDisplay = Flash_Green;
						fixData.nDuration = data.plan.plan[i].phase[j].byGreenFlashDuration;
						sgDataInProg.fixedStates.push_back(fixData);
					}
					break;
				case COLOR_SEQU_RED_GREEN_AMBER:
					{
						CmdData cmdData;
						cmdData.nDisplay = Red;
						cmdData.nBegin = data.plan.plan[i].phase[j].byRedBegin;
						sgDataInProg.cmds.push_back(cmdData);
						cmdData.nDisplay = Green;
						cmdData.nBegin = data.plan.plan[i].phase[j].byGreenBegin;
						sgDataInProg.cmds.push_back(cmdData);

						FixStateData fixData;
						fixData.nDisplay = Amber;
						fixData.nDuration = data.plan.plan[i].phase[j].byAmberDuration;
						sgDataInProg.fixedStates.push_back(fixData);
					}
					break;
				case COLOR_SEQU_AMBERFLASH:
					{
						CmdData cmdData;
						cmdData.nDisplay = Flash_Amber;
						cmdData.nBegin = data.plan.plan[i].phase[j].byAmberFlashBegin;
						sgDataInProg.cmds.push_back(cmdData);
					}
					break;
				case COLOR_SEQU_OFF:
					{
						CmdData cmdData;
						cmdData.nDisplay = OFF;
						cmdData.nBegin = data.plan.plan[i].phase[j].byOffBegin;
						sgDataInProg.cmds.push_back(cmdData);
					}
					break;
				case COLOR_SEQU_RED_OFF:
					{
						CmdData cmdData;
						cmdData.nDisplay = Red;
						cmdData.nBegin = data.plan.plan[i].phase[j].byRedBegin;
						sgDataInProg.cmds.push_back(cmdData);
						cmdData.nDisplay = OFF;
						cmdData.nBegin = data.plan.plan[i].phase[j].byOffBegin;
						sgDataInProg.cmds.push_back(cmdData);
					}
					break;
				case COLOR_SEQU_RED_OFF_AMBER:
					{
						CmdData cmdData;
						cmdData.nDisplay = Red;
						cmdData.nBegin = data.plan.plan[i].phase[j].byRedBegin;
						sgDataInProg.cmds.push_back(cmdData);
						cmdData.nDisplay = OFF;
						cmdData.nBegin = data.plan.plan[i].phase[j].byOffBegin;
						sgDataInProg.cmds.push_back(cmdData);

						FixStateData fixData;
						fixData.nDisplay = Amber;
						fixData.nDuration = data.plan.plan[i].phase[j].byAmberDuration;
						sgDataInProg.fixedStates.push_back(fixData);
					}
					break;
				case COLOR_SEQU_OFF_GREEN:
					{
						CmdData cmdData;
						cmdData.nDisplay = OFF;
						cmdData.nBegin = data.plan.plan[i].phase[j].byOffBegin;
						sgDataInProg.cmds.push_back(cmdData);
						cmdData.nDisplay = Green;
						cmdData.nBegin = data.plan.plan[i].phase[j].byGreenBegin;
						sgDataInProg.cmds.push_back(cmdData);
					}
					break;
				case COLOR_SEQU_AMBERFLASH_OFF:
					{
						CmdData cmdData;
						cmdData.nDisplay = OFF;
						cmdData.nBegin = data.plan.plan[i].phase[j].byOffBegin;
						sgDataInProg.cmds.push_back(cmdData);
						cmdData.nDisplay = Flash_Amber;
						cmdData.nBegin = data.plan.plan[i].phase[j].byAmberFlashBegin;
						sgDataInProg.cmds.push_back(cmdData);
					}
					break;
				case COLOR_SEQU_RED_GREEN_REDFLASH:
					{
						CmdData cmdData;
						cmdData.nDisplay = Red;
						cmdData.nBegin = data.plan.plan[i].phase[j].byRedBegin;
						sgDataInProg.cmds.push_back(cmdData);
						cmdData.nDisplay = Green;
						cmdData.nBegin = data.plan.plan[i].phase[j].byGreenBegin;
						sgDataInProg.cmds.push_back(cmdData);

						FixStateData fixData;
						fixData.nDisplay = Flash_Red;
						fixData.nDuration = data.plan.plan[i].phase[j].byRedFlashDuration;
						sgDataInProg.fixedStates.push_back(fixData);
					}
					break;
				case COLOR_SEQU_REDFLASH_OFF:
					{
						CmdData cmdData;
						cmdData.nDisplay = Flash_Red;
						cmdData.nBegin = data.plan.plan[i].phase[j].byRedFlashBegin;
						sgDataInProg.cmds.push_back(cmdData);
						cmdData.nDisplay = OFF;
						cmdData.nBegin = data.plan.plan[i].phase[j].byOffBegin;
						sgDataInProg.cmds.push_back(cmdData);
					}
					break;
				default:
					break;
				}

				sgProgData.sgDatasInProg.push_back(sgDataInProg);
			}
			sgProgDatas.push_back(sgProgData);
		}
	}
	
	//��ȡsquencedata
	squenceDatas.clear();
	for (int i=0; i<data.ph_seq.count_sequence; i++)
	{
		SquenceData squenceData;
		squenceData.nId = i+1;
		QString strName = QString::fromLocal8Bit("���� %1").arg(squenceData.nId);
		qstrcpy(squenceData.strName, strName.toStdString().c_str());
		squenceData.isConfiged = true;	//�������ݣ�Ĭ��������
		squenceData.squence = data.ph_seq.sequence[i];
		squenceDatas.push_back(squenceData);
	}

	//��ȡdetectorVehicleData
	detectorVehicleData.clear();
	for (int i=0; i<data.dec_veh.count_vehicle_detectors; i++)
	{
		DetectorVehicleData vehData;
		vehData.detector = data.dec_veh.detectorVehicle[i];
		QString strName = QString::fromLocal8Bit("����������� %1").arg(vehData.detector.byDetectorNo);
		qstrcpy(vehData.strName, strName.toStdString().c_str());

		detectorVehicleData.push_back(vehData);
	}

	//��ȡdetectorBusDatas
	detectorBusDatas.clear();
	for (int i=0; i<data.dec_bus.count_vehicle_detectors; i++)
	{
		DetectorBusData busData;
		busData.detector = data.dec_bus.detectorBUS[i];
		QString strName = QString::fromLocal8Bit("����������� %1").arg(busData.detector.byDetectorNo);
		qstrcpy(busData.strName, strName.toStdString().c_str());
		detectorBusDatas.push_back(busData);
	}

	//��ȡdetectorPedestainsDatas
	detectorPedestainsDatas.clear();
	for (int i=0; i<data.dec_ped.count_pedestrain_detectors; i++)
	{
		DetectorsPedestrainsData pedData;
		pedData.detector = data.dec_ped.detectorPedestrain[i];
		QString strName = QString::fromLocal8Bit("���˼���� %1").arg(pedData.detector.byDetectorNo);
		qstrcpy(pedData.strName, strName.toStdString().c_str());
		detectorPedestainsDatas.push_back(pedData);
	}

	//translationDatas
	for (int i=0; i<data.plan_tran.count_transPlan; i++)
	{
		TranslationPlanData transData;
		transData.translationPlan = data.plan_tran.transPlan[i];
		QString strName = QString::fromLocal8Bit("���ɷ��� %1").arg(transData.translationPlan.byTransitionPlanNo);
		qstrcpy(transData.strName, strName.toStdString().c_str());
		translationDatas.push_back(transData);
	}

	//periodDatas
	for (int i=0; i<data.period.count_period; i++)
	{
		PeriodData periodData;
		periodData.nId = i+1;
		QString strName = QString::fromLocal8Bit("ʱ�� %1").arg(periodData.nId);
		qstrcpy(periodData.strName, strName.toStdString().c_str());
		periodData.period = data.period.period[i];
		periodDatas.push_back(periodData);
	}


}

bool isInFun(int id, QVector<SgData>&sgdatas)
{
	bool bIn = false;
	for (int i=0; i<sgdatas.size(); i++)
	{
		if (id==sgdatas[i].nId)
		{
			bIn = true;
		}
	}
	return bIn;
}

bool isInFun(int id, QVector<InterGreen> &interGreens)
{
	bool bIn=false;
	for (int i=0; i<interGreens.size(); i++)
	{
		if (id==interGreens[i].nClearingSg||
			id==interGreens[i].nEnteringSg)
		{
			bIn = true;
		}
	}
	return bIn;
}

/************************************************************************/
/*���º���ΪЭ�������������                                                        */
/************************************************************************/
int check_sum(quint8 *data,int size)	//����У���
{
	quint16 sum = 0;
	int i;

	for (i = 0; i < size; i++)
	{
		sum += *data++;
	}

	return sum;
}

int check_frame(quint8 *frm_in,int len)
{
	int total_size=0;
	int data_size=0;
	unsigned	char *p_sum=0;
	quint16 sum=0;
	int i=0;
	quint16 n_sum=0;
	int len_sum=0;

	type_frame_head *p_frm = (type_frame_head *)frm_in;

	if(len > MAX_PROTOCOL_BYTE)	//���֡�����Ƿ�Ϸ�
	{
		return -1;
	}

	if(p_frm->head != '<')		//���֡ͷ�Ƿ�Ϸ�
	{
		return -1;
	}

	memcpy(&total_size,&p_frm->total_size,sizeof(int));

	if(total_size > len)		//���ݳ��ȴ����ܳ��Ȳ��Ϸ�
	{
		return -1;
	}

	//��֤У���
	data_size = total_size - sizeof(p_frm->reserve) -sizeof(p_frm->addr) - sizeof(p_frm->ctrl) - sizeof(p_frm->type_fun);	//��ȡ���ݶεĳ���
	p_sum = (quint8 *)p_frm  + sizeof(p_frm->head) + sizeof(p_frm->total_size)+total_size;
	memcpy(&sum,p_sum,sizeof(quint16));
	len_sum=p_frm->total_size + sizeof(p_frm->head) + sizeof(p_frm->total_size);
	n_sum = check_sum(frm_in,len_sum);
	if(sum == n_sum)
	{
		return 1;
	}else
	{
		qDebug()<<QString::fromLocal8Bit("ԭʼsum = 0x%1,����sum = 0x%2,total_size=%3\n").arg(sum).arg(n_sum).arg(total_size);
		return -1;
	}
}

quint8 *get_ptr_data(quint8 *frm)		//�������ݶε���ָ��
{
	type_frame_head *p_frm = (type_frame_head *)frm;

	return &p_frm->data;		//��Ԥ���ֶεĵ�ַ�������ݶεĿ�ʼ
}

int get_len_data(quint8 *frm)				//�������ݶεĳ���
{
	type_frame_head *p_frm = (type_frame_head *)frm;
	int data_size;

	data_size = p_frm->total_size - sizeof(p_frm->reserve) -sizeof(p_frm->addr) - sizeof(p_frm->ctrl) - sizeof(p_frm->type_fun);

	return data_size;
}

int set_unit_conf(quint8 *unit,int size,type_fun_conf &fun_config, quint32 &id_fun)//��������unit������;
{
	quint32 fun_id;

	quint8 *p = unit;

	memcpy(&fun_id,p,4);

	//qDebug()<<"id_fun = 0x"<<fun_id<<"\n";
	int n=0;
	id_fun = fun_id;
	switch(fun_id)
	{
	case FUN_VERSION:
		{
			n = sizeof(fun_config.version);
			if (n==size)
			{
				memcpy(&fun_config.version,p,size);
			}else
			{
				qCritical()<<"FUN_VERSION ���ݵ�Ԫ��������: size("<<size<<")!=sizeof(type_version:"<<n<<")\n";
				return -1;
			}
		}
		break;
	case FUN_ADDR:
		n = sizeof(fun_config.address);
		if (n==size)
		{
			memcpy(&fun_config.address,p,size);
		}else
		{
			qCritical()<<"FUN_ADDR ���ݵ�Ԫ��������: size("<<size<<")!=sizeof(type_addr_conf:"<<n<<")\n";
			return -1;
		}
		break;

	case FUN_PLAN:
		n = sizeof(fun_config.plan);
		if (n==size)
		{
			memcpy(&fun_config.plan,p,size);
		}else
		{
			qCritical()<<"FUN_PLAN ���ݵ�Ԫ��������: size("<<size<<")!=sizeof(type_protocol_plan:"<<n<<")\n";
			return -1;
		}
		
		break;

	case FUN_PERIOD:
		n = sizeof(fun_config.period);
		if (n != size)
		{
			qCritical()<<"FUN_PERIOD ���ݵ�Ԫ��������: size("<<size<<")!=sizeof(type_protocol_period:"<<n<<")\n";
			return -1;
		}
		else
		{
			memcpy(&fun_config.period, p, size);
		}
		break;

	case FUN_PLAN_TRAN:
		n = sizeof(fun_config.plan_tran);
		if (n != size)
		{
			qCritical()<<"FUN_PLAN_TRAN ���ݵ�Ԫ��������: size("<<size<<")!=sizeof(type_protocol_transitionPlan:"<<n<<")\n";
			return -1;
		}
		else
		{
			memcpy(&fun_config.plan_tran, p, size);
		}
		break;

	case FUN_PH_SEQ:
		n = sizeof(fun_config.ph_seq);
		if ( n!= size)
		{
			qCritical()<<"FUN_PH_SEQ ���ݵ�Ԫ��������: size("<<size<<")!=sizeof(type_protocol_sequence:"<<n<<")\n";
			return -1;
		}
		else
		{
			memcpy(&fun_config.ph_seq, p, size);
		}
		break;

	case FUN_DEC_PED:
		n = sizeof(fun_config.dec_ped);
		if ( n!= size)
		{
			qCritical()<<"FUN_DEC_PED ���ݵ�Ԫ��������: size("<<size<<")!=sizeof(type_pedestrain_detetcor:"<<n<<")\n";
			return -1;
		}
		else
		{
			memcpy(&fun_config.dec_ped, p, size);
		}
		break;

	case FUN_DEC_BUS:
		n = sizeof(fun_config.dec_bus);
		if ( n!= size)
		{
			qCritical()<<"FUN_DEC_BUS ���ݵ�Ԫ��������: size("<<size<<")!=sizeof(type_bus_detetcor:"<<n<<")\n";
			return -1;
		}
		else
		{
			memcpy(&fun_config.dec_bus, p, size);
		}
		break;

	case FUN_DEC_VEH:
		n = sizeof(fun_config.dec_veh);
		if ( n!= size)
		{
			qCritical()<<"FUN_DEC_VEH ���ݵ�Ԫ��������: size("<<size<<")!=sizeof(type_vehicle_detetcor:"<<n<<")\n";
			return -1;
		}
		else
		{
			memcpy(&fun_config.dec_veh, p, size);
		}
		break;

	case FUN_MATRIX:
		n = sizeof(fun_config.matrices);
		if ( n!= size)
		{
			qCritical()<<"FUN_MATRIX ���ݵ�Ԫ��������: size("<<size<<")!=sizeof(type_protocol_matrix:"<<n<<")\n";
			return -1;
		}
		else
		{
			memcpy(&fun_config.matrices, p, size);
		}
		break;
	}
	
	return 0;
}

int check_size_unit(quint8 *data,int size)		//������ݶ��·�unit���ֽںͼ�����ֽ��Ƿ�һ��
{
	int byte_total_unit=0;		//������������ܹ����ֽڴ�С;
	quint16 size_unit;  //���� ����Ĵ�С;
	int n= data[0];		//���ݵ�Ԫ�ĸ���
	quint8 *p= &data[1];	//���ݵ�Ԫ���ݵ���ʼ��ַ

	byte_total_unit++;
	//qDebug()<<"unit ["<<n<<QString::fromLocal8Bit("]��\n");

	for(int i=0;i<n;i++)
	{
		memcpy(&size_unit,p,2);
		byte_total_unit +=2;
		p +=2;
		byte_total_unit +=size_unit;
		p += size_unit;
	}

	if(byte_total_unit != size)
	{
		qDebug()<<QString::fromLocal8Bit("�������õ�unit ���ֽ�=")<<byte_total_unit<<QString::fromLocal8Bit(",�·����ֽ�=")<<size<<QString::fromLocal8Bit(",�������ܳ�����!!!\n");
		return -1;
	}else
	{
		return 1;
	}
}

int set_data_conf_from_stream(quint8 *data,int size,type_fun_conf &fun_config, quint32 &id_fun)
{
	int n;
	int i;
	quint8 *p;

	quint16 size_unit;  //���� ����Ĵ�С;
	quint8 unit_buf[MAX_PROTOCOL_BYTE];	//�������������;
	memset(unit_buf, 0, sizeof(unit_buf));

	//������ĵ�Ԫ���ݳ������·����Ƿ�һ��
	if(check_size_unit(data,size) < 0)
	{
		return -1;
	}
	n= data[0];		//���ݵ�Ԫ����
	p= &data[1];		//�׸����ݵ�Ԫ
// 	if (n!=1)
// 	{
// 		qCritical()<<QString::fromLocal8Bit("���ݵ�Ԫ������Ϊ1������ʧ��\n");
// 		return -1;
// 	}
	for(i=0;i<n;i++)
	{
		memset(unit_buf,0,sizeof(unit_buf));
		memcpy(&size_unit,p,2);		//Unit�������ݳ���
		p +=2;
		//qDebug()<<"size_unit["<<i<<"] = "<<size_unit<<" \n";

		memcpy(unit_buf,p,size_unit);		//��ȡ��unit�������ݵ�buff��
		p += size_unit;
		if(set_unit_conf(unit_buf,size_unit,fun_config, id_fun)==-1) //��������Unit���ݵ��ṹ����
		{
			return -1;
		}		
	}
	return 0;
}

int do_fram(quint8 *frm_in, int len, type_fun_conf &fun_config, quint32 &id_fun)
{
	type_frame_head *p_frm = (type_frame_head*)frm_in;		//��ȡ��Ϣͷ
	int frm_len=len;

	//#################��ȡ��������Ϣͷ########################
	for(int i=0;i<len;i++)
	{
		if(frm_in[i] == '<')
		{
			p_frm = (type_frame_head *)&frm_in[i];
			frm_len = len-i;
			break;
		}
	}
	//######################################################

	int sta = check_frame((quint8*)p_frm, frm_len);		//���֡��״̬
	if(sta > 0 )
	{
	//	qDebug()<<QString::fromLocal8Bit("����֡���ͨ��!\n");
		int ctrl = p_frm->ctrl;		//��ȡ��������
		/*do_frame���ǽ��ղ�����֡���õ����ݣ�����CTRL_RD �� CTRL_SET��һ���ģ�����Ҫ�����ֶԴ���
		*/
		switch (ctrl) 
		{
		case CTRL_RD:		//��ȡ����
			qDebug()<<QString::fromLocal8Bit("��ȡ����:CTRL_RD\n");
			sta = set_data_conf_from_stream(get_ptr_data((quint8 *)p_frm),get_len_data((quint8 *)p_frm), fun_config, id_fun);
			//socket->sendto_data_raw((u8 *)p_frm,frm_len);
			break;
		case CTRL_SET:		//��������
			qDebug()<<QString::fromLocal8Bit("set����:CTRL_SET\n");
			sta = set_data_conf_from_stream(get_ptr_data((quint8 *)p_frm),get_len_data((quint8 *)p_frm), fun_config, id_fun);
			break;
		default:
			break;
		}
		if (sta>=0)
		{
			return ctrl;
		}
	}
	return sta;
}


void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
	static QMutex mutex;
	mutex.lock();

	QString text;
	switch(type)
	{
	case QtDebugMsg:
		text = QString("Debug:");
		break;

	case QtWarningMsg:
		text = QString("Warning:");
		break;

	case QtCriticalMsg:
		text = QString("Critical:");
		break;

	case QtFatalMsg:
		text = QString("Fatal:");
	}

	QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
	QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
	QString current_date = QString("(%1)").arg(current_date_time);
	QString message = QString("%1 %2 %3 %4").arg(text).arg(current_date).arg(context_info).arg(msg);

	QFile file("log.txt");
	file.open(QIODevice::WriteOnly | QIODevice::Append);
	QTextStream text_stream(&file);
	text_stream << message << "\r\n";
	file.flush();
	file.close();
	mutex.unlock();
}
bool sgsDataLessThan(const SgData data1, const SgData data2)
{
	return data1.nId<data2.nId;
}

