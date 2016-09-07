/***********************************************************************
 * Module:  Rect.cpp
 * Author:  liuyufeng
 * Modified: 2015年8月11日 10:21:01
 * Purpose: Implementation of the class Rect
 * Comment: 抽象类，但是能够画出一个矩形框，增加以下属性：
 *    m_nYBeg  左上角的y坐标
 *    m_nYend  右下角的y坐标
 ***********************************************************************/

#include "Rect.h"

////////////////////////////////////////////////////////////////////////
// Name:       Rect::Rect(int & nxBeg, int nBScale, int nEScale, int nIterval, int nYbeg, int nYEnd)
// Purpose:    Implementation of Rect::Rect()
// Parameters:
// - nxBeg
// - nBScale
// - nEScale
// - nIterval
// - nYbeg
// - nYEnd
// Return:     
////////////////////////////////////////////////////////////////////////

Rect::Rect(int & nxBeg,int &cycle, int nBScale, int nEScale, int nIterval, int nYbeg, int nYEnd):
	Shap(nxBeg, cycle, nBScale, nEScale, nIterval),
	m_nYBeg(nYbeg),
	m_nYEnd(nYEnd)
{
   // TODO : implement
}


////////////////////////////////////////////////////////////////////////
// Name:       Rect::setYBeg(int nYbeg)
// Purpose:    Implementation of Rect::setYBeg()
// Parameters:
// - nYbeg
// Return:     void
////////////////////////////////////////////////////////////////////////

void Rect::setYBeg(int nYbeg)
{
	// TODO : implement
	m_nYBeg = nYbeg;
}

////////////////////////////////////////////////////////////////////////
// Name:       Rect::setYEnd(int nYEnd)
// Purpose:    Implementation of Rect::setYEnd()
// Parameters:
// - nYEnd
// Return:     void
////////////////////////////////////////////////////////////////////////

void Rect::setYEnd(int nYEnd)
{
	// TODO : implement
	m_nYEnd = nYEnd;
}

////////////////////////////////////////////////////////////////////////
// Name:       Rect::paint(QPainter & painter)
// Purpose:    Implementation of Rect::paint()
// Comment:    画一个矩形，虚函数,但不是纯虚函数
// Parameters:
// - painter
// Return:     void
////////////////////////////////////////////////////////////////////////

void Rect::paint(QPainter & painter)
{
	if (!bPainted)
	{
		return;
	}

	// 保存原来的style
	QPen pen = painter.pen();
	//QBrush brush = painter.brush();

	//画绿框
//	painter.setBrush(QBrush(QColor(Qt::green)));
	

   // TODO : 首先，画一个矩形
	if (m_bSelected)
	{
		if (nCurrenXB<=nCurrenXE)
		{
			painter.drawRect(QRect(QPoint(nCurrenXB, m_nYBeg), QPoint(nCurrenXE, m_nYEnd)));
		}else
		{
			painter.drawRect(QRect(QPoint(nCurrenXB, m_nYBeg), QPoint(m_nxBeg+m_cycle*m_nInterval, m_nYEnd)));
			painter.drawRect(QRect(QPoint(m_nxBeg, m_nYBeg), QPoint(nCurrenXE, m_nYEnd)));
		}
		painter.setPen(QPen(QColor(Qt::black)));
		if(isScalePaint)
		{
			painter.drawText(QPoint(nCurrenXB+10, (m_nYBeg+m_nYEnd)/2),QString::number((nCurrenXB-m_nxBeg)/m_nInterval));
			painter.drawText(QPoint(nCurrenXE-10, (m_nYBeg+m_nYEnd)/2),QString::number((nCurrenXE-m_nxBeg)/m_nInterval));
		}

		painter.setPen(pen);
	}else
	{
		if (m_nBScale<m_nEScale)
		{
			painter.drawRect(QRect(QPoint(m_nxBeg+m_nBScale*m_nInterval, m_nYBeg), QPoint(m_nxBeg+m_nEScale*m_nInterval, m_nYEnd)));
		}else
		{
			painter.drawRect(QRect(QPoint(m_nxBeg+m_nBScale*m_nInterval, m_nYBeg), QPoint(m_nxBeg+m_cycle*m_nInterval, m_nYEnd)));
			painter.drawRect(QRect(QPoint(m_nxBeg, m_nYBeg), QPoint(m_nxBeg+m_nEScale*m_nInterval, m_nYEnd)));
		}
		painter.setPen(QPen(QColor(Qt::black)));
		if(isScalePaint)
		{
			painter.drawText(QPoint(m_nxBeg+m_nBScale*m_nInterval+10,  (m_nYBeg+m_nYEnd)/2),QString::number(m_nBScale));
			painter.drawText(QPoint(m_nxBeg+m_nEScale*m_nInterval-10,  (m_nYBeg+m_nYEnd)/2),QString::number(m_nEScale));
		}
		painter.setPen(pen);
	}
}