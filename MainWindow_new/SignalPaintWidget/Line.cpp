/***********************************************************************
 * Module:  Line.cpp
 * Author:  liuyufeng
 * Modified: 2015年8月11日 8:59:26
 * Purpose: Implementation of the class Line
 * Comment: Red & Black(OFF)
 *    红线和黑线两种
 ***********************************************************************/

#include "Line.h"

////////////////////////////////////////////////////////////////////////
// Name:       Line::Line(int m_nxBeg, int nBScale, int nEScale, int nInterval, int yNum, bool isRed)
// Purpose:    Implementation of Line::Line()
// Parameters:
// - m_nxBeg
// - nBScale
// - nEScale
// - nInterval
// - yNum
// - isRed
// Return:     
////////////////////////////////////////////////////////////////////////

Line::Line(int &nxBeg, int &cycle,int nBScale, int nEScale, int nInterval, int yNum, bool isRed):
	Shap(nxBeg, cycle, nBScale, nEScale, nInterval),
	m_nYnum(yNum),
	m_bIsRed(isRed)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Line::setYnum(int nYnum)
// Purpose:    Implementation of Line::setYnum()
// Parameters:
// - nYnum
// Return:     void
////////////////////////////////////////////////////////////////////////

void Line::setYnum(int nYnum)
{
   // TODO : implement
	m_nYnum = nYnum;
}

////////////////////////////////////////////////////////////////////////
// Name:       Line::setColorType(bool isRed)
// Purpose:    Implementation of Line::setColorType()
// Comment:    设置是红线还是黑线
// Parameters:
// - isRed
// Return:     void
////////////////////////////////////////////////////////////////////////

void Line::setColorType(bool isRed)
{
   // TODO : implement
	m_bIsRed = isRed;
}

////////////////////////////////////////////////////////////////////////
// Name:       Line::~Line()
// Purpose:    Implementation of Line::~Line()
// Return:     
////////////////////////////////////////////////////////////////////////

Line::~Line()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Line::paint(QPainter & painter)
// Purpose:    Implementation of Line::paint()
// Comment:    画线
// Parameters:
// - painter
// Return:     void
////////////////////////////////////////////////////////////////////////

void Line::paint(QPainter & painter)
{
	if (!bPainted)
	{
		return;
	}
   // TODO : implement
	QPen pen;
	pen.setWidth(1);
	if (m_bIsRed)
	{
		//设置画笔，为红色
		pen.setColor(Qt::red);
		painter.setPen(pen);
	}else
	{
		//设置画笔，为黑色
		pen.setColor(Qt::black);
		painter.setPen(pen);
	}
	
	
	for (int i=-2; i<3; i++)
	{
		if (m_bSelected)
		{
 			if (nCurrenXB<=nCurrenXE)
 			{
 				painter.drawLine(nCurrenXB, m_nYnum+i, nCurrenXE, m_nYnum+i);
 			}else
			{
 				painter.drawLine(nCurrenXB, m_nYnum+i, m_nxBeg+m_cycle*m_nInterval, m_nYnum+i);
				painter.drawLine(m_nxBeg, m_nYnum+i, nCurrenXE, m_nYnum+i);
			}
		}else
		{
			if (m_nBScale<m_nEScale)
			{
				painter.drawLine(m_nxBeg+m_nBScale*m_nInterval, m_nYnum+i, m_nxBeg+m_nEScale*m_nInterval, m_nYnum+i);
			}else
			{
				painter.drawLine(m_nxBeg+m_nBScale*m_nInterval, m_nYnum+i, m_nxBeg+m_cycle*m_nInterval, m_nYnum+i);
				painter.drawLine(m_nxBeg, m_nYnum+i, m_nxBeg+m_nEScale*m_nInterval, m_nYnum+i);
			}
		}
	}
	if (!isScalePaint)
	{
		return;
	}
	if (m_bSelected)
	{
		painter.drawText(QPoint(nCurrenXB+10, m_nYnum),QString::number((nCurrenXB-m_nxBeg)/m_nInterval));
		painter.drawText(QPoint(nCurrenXE-20, m_nYnum),QString::number((nCurrenXE-m_nxBeg)/m_nInterval));
	}else
	{
		painter.drawText(QPoint(m_nxBeg+m_nBScale*m_nInterval+10, m_nYnum),QString::number(m_nBScale));
		painter.drawText(QPoint(m_nxBeg+m_nEScale*m_nInterval-20, m_nYnum),QString::number(m_nEScale));
	}

//	qDebug()<<"m_nBScale="<<m_nBScale<<"m_nEScale"<<m_nEScale<<"type="<<shapType<<"\n";
}