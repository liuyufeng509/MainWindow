/***********************************************************************
 * Module:  Shap.cpp
 * Author:  liuyufeng
 * Modified: 2015��8��7�� 16:47:44
 * Purpose: Implementation of the class Shap
 * Comment: ��״ͼ��
 ***********************************************************************/

#include "Shap.h"

////////////////////////////////////////////////////////////////////////
// Name:       Shap::Shap(int & nxBeg, int nBScale, int nEScale, int nIterval)
// Purpose:    Implementation of Shap::Shap()
// Comment:    ���캯��
// Parameters:
// - nxBeg
// - nBScale
// - nEScale
// - nIterval
// Return:     
////////////////////////////////////////////////////////////////////////

Shap::Shap(int & nxBeg, int &cycle, int nBScale, int nEScale, int nIterval):
	m_nxBeg(nxBeg),
	m_nBScale(nBScale),
	m_nEScale(nEScale),
	m_nInterval(nIterval),
	m_cycle(cycle),
	m_bSelected(false),
	m_direction(eNone),
	bPainted(false),
	pWidget(NULL),
	nCurrenXE(0),
	nCurrenXB(0),
	canBeChanged(true),
	isFixed(false),
	nFixState(0),
	isScalePaint(0)
{
   // TODO : implement
	
}
void Shap::caclScaleLen()
{
	if (m_nBScale>=m_nEScale)
	{
		m_nScaleLen = m_nEScale + m_cycle - m_nBScale;
	}else
	{
		m_nScaleLen = m_nEScale - m_nBScale;
	}
}
////////////////////////////////////////////////////////////////////////
// Name:       Shap::setBScale(int nBScale)
// Purpose:    Implementation of Shap::setBScale()
// Comment:    ������ʼ�̶�
// Parameters:
// - nBScale
// Return:     void
////////////////////////////////////////////////////////////////////////

void Shap::setBScale(int nBScale)
{
   // TODO : implement
	m_nBScale = nBScale;
	if (m_nBScale<0)
	{
		m_nBScale +=m_cycle;
	}
	if (m_nBScale>=m_cycle)
	{
		m_nBScale -= m_cycle;
	}
	nCurrenXB = m_nxBeg + m_nBScale * m_nInterval;
}

////////////////////////////////////////////////////////////////////////
// Name:       Shap::setEScale(int nEScale)
// Purpose:    Implementation of Shap::setEScale()
// Comment:    ���ý����̶�
// Parameters:
// - nEScale
// Return:     void
////////////////////////////////////////////////////////////////////////

void Shap::setEScale(int nEScale)
{
   // TODO : implement
	m_nEScale = nEScale;
	if (m_nEScale<=0)		//��������̶�Ϊ0�����Ϊ�̶ܿȽ�βֵ
	{
		m_nEScale += m_cycle;
	}
	if(m_nEScale>m_cycle)
	{
		m_nEScale -= m_cycle;
	}
	nCurrenXE = m_nxBeg + m_nEScale * m_nInterval;
}

////////////////////////////////////////////////////////////////////////
// Name:       Shap::SetInterval(int nInterval)
// Purpose:    Implementation of Shap::SetInterval()
// Comment:    ���ü��
// Parameters:
// - nInterval
// Return:     void
////////////////////////////////////////////////////////////////////////

void Shap::SetInterval(int nInterval)
{
   // TODO : implement
	m_nInterval = nInterval;
}

////////////////////////////////////////////////////////////////////////
// Name:       Shap::getBScale()
// Purpose:    Implementation of Shap::getBScale()
// Comment:    ��ȡ��ʼ�̶�
// Return:     int
////////////////////////////////////////////////////////////////////////

int Shap::getBScale(void)
{
   // TODO : implement
   return m_nBScale;
}

////////////////////////////////////////////////////////////////////////
// Name:       Shap::getEScale()
// Purpose:    Implementation of Shap::getEScale()
// Comment:    ��ȡ�����̶�
// Return:     int
////////////////////////////////////////////////////////////////////////

int Shap::getEScale(void)
{
   // TODO : implement
   return m_nEScale;
}

////////////////////////////////////////////////////////////////////////
// Name:       Shap::getInterval()
// Purpose:    Implementation of Shap::getInterval()
// Comment:    ��ȡ���
// Return:     int
////////////////////////////////////////////////////////////////////////

int Shap::getInterval(void)
{
   // TODO : implement
   return m_nInterval;
}

enum_Direction Shap::PointValid(int x, int y)
{
	int nLdx = x-m_nxBeg-m_nBScale*m_nInterval;
	int nRdx = m_nxBeg+m_nEScale*m_nInterval -x;
	//qDebug()<<"nLdx="<<nLdx<<" nRdx="<<nRdx<<"\n";
	if(nLdx<Border_Wid&&nLdx>0)//if(qAbs(nLdx)<Border_Wid)
		return eLeft;
	else if(nRdx<Border_Wid&& nRdx>0) //if(qAbs(nRdx)<Border_Wid)
		return eRight;
	else 
		return eNone;
} 

bool Shap::isMouseIn(int x,int y)
{
	if (m_nEScale>=m_nBScale)
	{
		if (x>=(m_nxBeg+m_nBScale*m_nInterval/*-Border_Wid*/) && x<=(m_nxBeg+m_nEScale*m_nInterval/*+Border_Wid*/))
		{
			return true;
		}else
			return false;
	}else
	{
		if (x>=(m_nxBeg+m_nBScale*m_nInterval/*-Border_Wid*/) && x<=(m_nxBeg+m_cycle*m_nInterval)||
			x>=0&&x<=(m_nxBeg+m_nEScale*m_nInterval/*+Border_Wid*/))
			return true;
		else
		{
			return false;
		}
	}
	
// 	int nLdx = x-m_nxBeg-m_nBScale*m_nInterval;
// 	int nRdx = x-m_nxBeg-m_nEScale*m_nInterval;
// 	if(qAbs(nLdx)<5 || qAbs(nRdx)<5)
// 		return true;
// 	else 
// 		return false;
}

void Shap::mousePress(int x, int y)
{
	if (!canBeChanged)
	{
		return;
	}
	if (!bPainted)
	{
		return;
	}
	if (isMouseIn(x, y))	//��������ͼ���ڰ���
	{
		m_bSelected = true;
		m_pos = QPoint(x,y);
		nCurrenXB = m_nxBeg + m_nBScale*m_nInterval;
		nCurrenXE = m_nxBeg + m_nEScale*m_nInterval;
	}
}

enum_Direction Shap::setCursorStyle(int x, int y)
{
	m_direction = PointValid(x, y);
	setCursorStyle(m_direction);//��ɫ�������ұ߿�5�����ڣ����������״Ϊ����˫��ͷ��ʽ
	return m_direction;
}

void Shap::mouseMove(int x, int y)
{
	if (!canBeChanged)
	{
		return;
	}
	if (!bPainted)
	{
		return;
	}
	if(m_bSelected)
	{
		//1.����ͼ�γ��̲�����
		if (m_direction==eLeft)
		{
			nCurrenXB = x;
			if((shapType==Flash_Green_Rect ||
				shapType ==Amber_Rect || shapType==Flash_Red_Rect
				||shapType==Red_Amber_Rect ) && isFixed)
				nCurrenXE = nCurrenXB + nFixState*m_nInterval;
		}else if(m_direction==eRight)
		{
			nCurrenXE = x;
			if((shapType==Flash_Green_Rect ||
				shapType ==Amber_Rect || shapType==Flash_Red_Rect
				||shapType==Red_Amber_Rect ) && isFixed)
				nCurrenXB = nCurrenXE - nFixState*m_nInterval;
		}else//2.�ƶ�ͼ�β�����
		{
			m_mvPos = QPoint(x, y)-m_pos;		//���°�������
			m_pos = QPoint(x,y);			//��굽�ģ��ƶ����ģ��ɿ�������ȡ�̶���ֵ
			nCurrenXB += m_mvPos.x();
			nCurrenXE += m_mvPos.x();		//�ƶ��õ���ǰ�Ŀ�ʼ�ͽ�������
		}
		ChangeXBandE();
	}else
	{
		setCursorStyle(x, y);
	}
}
void Shap::ChangeXBandE()			//ʹ��ǰ����ֵ�Ϸ�
{
	
	int xEnd = m_nxBeg + m_cycle*m_nInterval; //���̶ȵ�����
	//1.�����϶�ʱ��һ���������̶�ֵ���꣬��Ҫ�����ȥ���ڴ�С
	if (nCurrenXE>xEnd)
	{
		nCurrenXE = m_nxBeg + (nCurrenXE-xEnd);
	}
	if (nCurrenXB>xEnd)
	{
		nCurrenXB = m_nxBeg + (nCurrenXB - xEnd);
	}
	if(nCurrenXB<m_nxBeg)
	{
		nCurrenXB = xEnd - (m_nxBeg-nCurrenXB);
	}
	if (nCurrenXE<m_nxBeg)
	{
		nCurrenXE = xEnd - (m_nxBeg-nCurrenXE);
	}

}

void Shap::mouseRelease(int x, int y)
{
	if (!canBeChanged)
	{
		return;
	}
	if (!bPainted)
	{
		return;
	}
	if (m_bSelected)		//����Ѿ�����,�����ɿ�
	{
		float tmpScaleB = (nCurrenXB-m_nxBeg)%m_nInterval;		//�ƶ��ľ��룬������һ���ġ�

		m_nBScale = (nCurrenXB-m_nxBeg)/m_nInterval;
		m_nEScale = (nCurrenXE-m_nxBeg)/m_nInterval;
		caclScaleLen();			//���㳤��
		
		m_bSelected = false;
// 		nCurrenXE = 0;
// 		nCurrenXB = 0;
	}
}

void Shap::setCursorStyle(enum_Direction direction)
{
	if (pWidget==NULL)
	{
		return;
	}
	switch (direction)
	{
	case eLeft:
	case eRight:
		pWidget->setCursor(Qt::SizeHorCursor);
		break;
	default:
		pWidget->setCursor(Qt::ArrowCursor);
		break;
	}
}
////////////////////////////////////////////////////////////////////////
// Name:       Shap::~Shap()
// Purpose:    Implementation of Shap::~Shap()
// Return:     
////////////////////////////////////////////////////////////////////////
Shap::~Shap()
{
   // TODO : implement
}
