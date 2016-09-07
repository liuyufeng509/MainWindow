/***********************************************************************
 * Module:  FlashAmber.cpp
 * Author:  liuyufeng
 * Modified: 2015年8月11日 10:36:10
 * Purpose: Implementation of the class FlashAmber
 * Comment: 黄闪矩形：
 *    矩形一个刻度的小矩形的对角线
 ***********************************************************************/

#include "FlashAmber.h"

////////////////////////////////////////////////////////////////////////
// Name:       FlashAmber::FlashAmber(int & nxBeg, int nBScale, int nEScale, int nIterval, int nYbeg, int nYEnd)
// Purpose:    Implementation of FlashAmber::FlashAmber()
// Parameters:
// - nxBeg
// - nBScale
// - nEScale
// - nIterval
// - nYbeg
// - nYEnd
// Return:     
////////////////////////////////////////////////////////////////////////

FlashAmber::FlashAmber(int & nxBeg, int &cycle,int nBScale, int nEScale, int nIterval, int nYbeg, int nYEnd):
	Rect(nxBeg,cycle, nBScale, nEScale, nIterval, nYbeg, nYEnd)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       FlashAmber::paint(QPainter & painter)
// Purpose:    Implementation of FlashAmber::paint()
// Parameters:
// - painter
// Return:     void
////////////////////////////////////////////////////////////////////////

void FlashAmber::paint(QPainter & painter)
{
	if (!bPainted)
	{
		return;
	}
   // 1.先画一个黄色矩形
	QPen pen;
	pen.setWidth(2);
	pen.setColor(Qt::yellow);
	painter.setPen(pen);
	Rect::paint(painter);	//画黄色矩形框


	//画对角线：一个刻度一个
	int nxBeg = m_nxBeg+m_nBScale*m_nInterval;	//矩形框的左边线坐标

	if (m_bSelected)
	{
		if (nCurrenXB<=nCurrenXE)
		{
			for (int i=0; i<(nCurrenXE-nCurrenXB)/m_nInterval; i++)
			{
				if (i%2==0)
				{
					painter.drawLine(QPoint(nCurrenXB + i*m_nInterval, m_nYBeg), QPoint(nCurrenXB+(i+1)*m_nInterval, m_nYEnd));
				}else
				{
					painter.drawLine(QPoint(nCurrenXB + i*m_nInterval, m_nYEnd), QPoint(nCurrenXB+(i+1)*m_nInterval, m_nYBeg));
				}
			}
		}else
		{
			for (int i=0; i<(m_cycle*m_nInterval+m_nxBeg-nCurrenXB)/m_nInterval; i++)
			{
				if (i%2==0)
				{
					painter.drawLine(QPoint(nCurrenXB + i*m_nInterval, m_nYBeg), QPoint(nCurrenXB+(i+1)*m_nInterval, m_nYEnd));
				}else
				{
					painter.drawLine(QPoint(nCurrenXB + i*m_nInterval, m_nYEnd), QPoint(nCurrenXB+(i+1)*m_nInterval, m_nYBeg));
				}
			}
			for (int i=0; i<(nCurrenXE-m_nxBeg)/m_nInterval; i++)
			{
				if (i%2==0)
				{
					painter.drawLine(QPoint( m_nxBeg+ i*m_nInterval, m_nYBeg), QPoint(m_nxBeg+(i+1)*m_nInterval, m_nYEnd));
				}else
				{
					painter.drawLine(QPoint( m_nxBeg+ i*m_nInterval, m_nYEnd), QPoint(m_nxBeg+(i+1)*m_nInterval, m_nYBeg));
				}
			}
		}
	
	}
	else
	{
	
		if (m_nBScale<m_nEScale)
		{
			for (int i=0; i<(m_nEScale-m_nBScale); i++)
			{
				if (i%2==0)
				{
					painter.drawLine(QPoint(nxBeg + i*m_nInterval, m_nYBeg), QPoint(nxBeg+(i+1)*m_nInterval, m_nYEnd));
				}else
				{
					painter.drawLine(QPoint(nxBeg + i*m_nInterval, m_nYEnd), QPoint(nxBeg+(i+1)*m_nInterval, m_nYBeg));
				}
			}
		}else
		{
			for (int i=0; i<m_cycle-m_nBScale; i++)
			{
				if (i%2==0)
				{
					painter.drawLine(QPoint(nxBeg + i*m_nInterval, m_nYBeg), QPoint(nxBeg+(i+1)*m_nInterval, m_nYEnd));
				}else
				{
					painter.drawLine(QPoint(nxBeg + i*m_nInterval, m_nYEnd), QPoint(nxBeg+(i+1)*m_nInterval, m_nYBeg));
				}
			}
			for (int i=0; i<m_nEScale; i++)
			{
				if (i%2==0)
				{
					painter.drawLine(QPoint( m_nxBeg+ i*m_nInterval, m_nYBeg), QPoint(m_nxBeg+(i+1)*m_nInterval, m_nYEnd));
				}else
				{
					painter.drawLine(QPoint( m_nxBeg+ i*m_nInterval, m_nYEnd), QPoint(m_nxBeg+(i+1)*m_nInterval, m_nYBeg));
				}
			}
		}
	}
	
}