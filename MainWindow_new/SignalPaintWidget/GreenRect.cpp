/***********************************************************************
 * Module:  GreenRect.cpp
 * Author:  liuyufeng
 * Modified: 2015年8月11日 11:41:34
 * Purpose: Implementation of the class GreenRect
 * Comment: 绿灯矩形框：
 *    绿色矩形框
 ***********************************************************************/

#include "GreenRect.h"

////////////////////////////////////////////////////////////////////////
// Name:       GreenRect::GreenRect(int & nxBeg, int nBScale, int nEScale, int nIterval, int nYbeg, int nYEnd)
// Purpose:    Implementation of GreenRect::GreenRect()
// Parameters:
// - nxBeg
// - nBScale
// - nEScale
// - nIterval
// - nYbeg
// - nYEnd
// Return:     
////////////////////////////////////////////////////////////////////////

GreenRect::GreenRect(int & nxBeg,int &cycle, int nBScale, int nEScale, int nIterval, int nYbeg, int nYEnd):
	Rect(nxBeg,cycle, nBScale, nEScale, nIterval, nYbeg, nYEnd)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       GreenRect::paint(QPainter & painter)
// Purpose:    Implementation of GreenRect::paint()
// Parameters:
// - painter
// Return:     void
////////////////////////////////////////////////////////////////////////

void GreenRect::paint(QPainter & painter)
{
	if (!bPainted)
	{
		return;
	}
   // 保存原来的style
	QPen pen = painter.pen();
	QBrush brush = painter.brush();

	//画绿框
	painter.setBrush(QBrush(QColor(Qt::green)));
	painter.setPen(QPen(QColor(Qt::black)));

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
		if(isScalePaint)
		{
			painter.drawText(QPoint(nCurrenXB+5, (m_nYBeg+m_nYEnd)/2),QString::number((nCurrenXB-m_nxBeg)/m_nInterval));
			painter.drawText(QPoint(nCurrenXE-20, (m_nYBeg+m_nYEnd)/2),QString::number((nCurrenXE-m_nxBeg)/m_nInterval));
		}
	}else
	{
		int nxBeg = m_nxBeg + m_nBScale*m_nInterval;
		int nxEnd = m_nxBeg + m_nEScale*m_nInterval;

		if (m_nBScale<m_nEScale)
		{
			painter.drawRect(QRect(QPoint(nxBeg, m_nYBeg), QPoint(nxEnd, m_nYEnd)));
		}else
		{
			painter.drawRect(QRect(QPoint(nxBeg, m_nYBeg), QPoint(m_nxBeg+m_cycle*m_nInterval, m_nYEnd)));
			painter.drawRect(QRect(QPoint(m_nxBeg, m_nYBeg), QPoint(nxEnd, m_nYEnd)));
		}
		if(isScalePaint)
		{
			painter.drawText(QPoint(m_nxBeg+m_nBScale*m_nInterval+5,  (m_nYBeg+m_nYEnd)/2),QString::number(m_nBScale));
			painter.drawText(QPoint(m_nxBeg+m_nEScale*m_nInterval-20,  (m_nYBeg+m_nYEnd)/2),QString::number(m_nEScale));
		}
	}
	//qDebug()<<"m_nBScale="<<m_nBScale<<"m_nEScale"<<m_nEScale<<"type="<<shapType<<"\n";
	//画完后，恢复原来的画笔和画刷。
	painter.setPen(pen);
	painter.setBrush(brush);
}