/***********************************************************************
 * Module:  Shap.cpp
 * Author:  liuyufeng
 * Modified: 2015年8月7日 16:47:44
 * Purpose: Implementation of the class Shap
 * Comment: 形状图形
 ***********************************************************************/

#include "Shap.h"

////////////////////////////////////////////////////////////////////////
// Name:       Shap::Shap(int & nxBeg, int nBScale, int nEScale, int nIterval)
// Purpose:    Implementation of Shap::Shap()
// Comment:    构造函数
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
// Comment:    设置起始刻度
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
// Comment:    设置结束刻度
// Parameters:
// - nEScale
// Return:     void
////////////////////////////////////////////////////////////////////////

void Shap::setEScale(int nEScale)
{
   // TODO : implement
	m_nEScale = nEScale;
	if (m_nEScale<=0)		//如果结束刻度为0，则改为总刻度结尾值
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
// Comment:    设置间隔
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
// Comment:    获取起始刻度
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
// Comment:    获取结束刻度
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
// Comment:    获取间隔
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
	if (isMouseIn(x, y))	//如果鼠标在图形内按下
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
	setCursorStyle(m_direction);//绿色矩形左右边框5像素内，设置鼠标形状为左右双箭头样式
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
		//1.拉伸图形长短操作。
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
		}else//2.移动图形操作。
		{
			m_mvPos = QPoint(x, y)-m_pos;		//记下按点坐标
			m_pos = QPoint(x,y);			//鼠标到哪，移动到哪，松开鼠标后，再取刻度整值
			nCurrenXB += m_mvPos.x();
			nCurrenXE += m_mvPos.x();		//移动得到当前的开始和结束坐标
		}
		ChangeXBandE();
	}else
	{
		setCursorStyle(x, y);
	}
}
void Shap::ChangeXBandE()			//使当前坐标值合法
{
	
	int xEnd = m_nxBeg + m_cycle*m_nInterval; //最大刻度的坐标
	//1.往右拖动时，一旦超出最大刻度值坐标，需要将其减去周期大小
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
	if (m_bSelected)		//如果已经按下,则处理松开
	{
		float tmpScaleB = (nCurrenXB-m_nxBeg)%m_nInterval;		//移动的距离，两端是一样的。

		m_nBScale = (nCurrenXB-m_nxBeg)/m_nInterval;
		m_nEScale = (nCurrenXE-m_nxBeg)/m_nInterval;
		caclScaleLen();			//计算长度
		
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
