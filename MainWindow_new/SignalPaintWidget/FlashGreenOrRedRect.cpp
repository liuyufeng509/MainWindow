/***********************************************************************
 * Module:  FlashGreenRect.cpp
 * Author:  liuyufeng
 * Modified: 2015��8��11�� 11:34:47
 * Purpose: Implementation of the class FlashGreenRect
 * Comment: �������ο�
 *    ��ɫ���ο�
 *    ÿ���̶Ȼ�һ����ɫ����
 ***********************************************************************/

#include "FlashGreenOrRedRect.h"

////////////////////////////////////////////////////////////////////////
// Name:       FlashGreenRect::FlashGreenRect(int & nxBeg, int nBScale, int nEScale, int nIterval, int nYbeg, int nYEnd)
// Purpose:    Implementation of FlashGreenRect::FlashGreenRect()
// Parameters:
// - nxBeg
// - nBScale
// - nEScale
// - nIterval
// - nYbeg
// - nYEnd
// Return:     
////////////////////////////////////////////////////////////////////////

FlashGreenOrRedRect::FlashGreenOrRedRect(int & nxBeg, int &cycle,int nBScale, int nEScale, int nIterval, int nYbeg, int nYEnd):
	Rect(nxBeg, cycle, nBScale, nEScale, nIterval, nYbeg, nYEnd)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       FlashGreenRect::paint(QPainter & painter)
// Purpose:    Implementation of FlashGreenRect::paint()
// Parameters:
// - painter
// Return:     void
////////////////////////////////////////////////////////////////////////

void FlashGreenOrRedRect::paint(QPainter & painter)
{
	if (!bPainted)
	{
		return;
	}
   // 1.����ɫ���ο�
	QPen pen;
	pen.setWidth(2);
	if (shapType==Flash_Green_Rect)
	{
		pen.setColor(Qt::green);
	}else
		pen.setColor(Qt::red);
	painter.setPen(pen);
	Rect::paint(painter);

	//2.ÿ���̶Ȼ�һ������
	int nxBeg = m_nxBeg + m_nBScale*m_nInterval;
	if (isFixed)
	{
		m_nEScale = m_nBScale + nFixState;
		if (m_nEScale>m_cycle)
		{
			m_nEScale = m_nEScale - m_cycle;
		}
	}
	if (m_bSelected)
	{
		if (nCurrenXB<=nCurrenXE)
		{
			for (int i=0; i<(nCurrenXE-nCurrenXB)/m_nInterval; i++)
			{
				painter.drawLine(QPoint(nCurrenXB+i*m_nInterval,m_nYBeg), QPoint(nCurrenXB+i*m_nInterval, m_nYEnd));
			}
		}
		else
		{
			for (int i=0; i<(m_cycle*m_nInterval+m_nxBeg-nCurrenXB)/m_nInterval; i++)
			{
				painter.drawLine(QPoint(nCurrenXB+i*m_nInterval,m_nYBeg), QPoint(nCurrenXB+i*m_nInterval, m_nYEnd));
			}
			for (int i=0; i<(nCurrenXE-m_nxBeg)/m_nInterval; i++)
			{
				painter.drawLine(QPoint(m_nxBeg+i*m_nInterval,m_nYBeg), QPoint(m_nxBeg+i*m_nInterval, m_nYEnd));
			}
		}
	}
	else
	{
		if (m_nBScale<m_nEScale)
		{
			for (int i=0; i<(m_nEScale-m_nBScale); i++)
			{
				painter.drawLine(QPoint(nxBeg+i*m_nInterval,m_nYBeg), QPoint(nxBeg+i*m_nInterval, m_nYEnd));
			}
		}else
		{
			for (int i=0; i<m_cycle-m_nBScale; i++)
			{
				painter.drawLine(QPoint(nxBeg+i*m_nInterval,m_nYBeg), QPoint(nxBeg+i*m_nInterval, m_nYEnd));
			}
			for (int i=0; i<m_nEScale; i++)
			{
				painter.drawLine(QPoint(m_nxBeg+i*m_nInterval,m_nYBeg), QPoint(m_nxBeg+i*m_nInterval, m_nYEnd));
			}
		}
	}

	//qDebug()<<"m_nBScale="<<m_nBScale<<"m_nEScale"<<m_nEScale<<"type="<<shapType<<"\n";
}