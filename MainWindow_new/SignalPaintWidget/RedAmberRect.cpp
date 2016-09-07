/***********************************************************************
 * Module:  RedAmberRect.cpp
 * Author:  liuyufeng
 * Modified: 2015��8��11�� 10:39:11
 * Purpose: Implementation of the class RedAmberRect
 * Comment: ��ƾ��Σ�
 *    ��ɫ���ο�
 *    �Խ���Ϊ����
 *    �м�ˮƽƽ����Ϊ��ɫ
 ***********************************************************************/

#include "RedAmberRect.h"

////////////////////////////////////////////////////////////////////////
// Name:       RedAmberRect::RedAmberRect(int & nxBeg, int nBScale, int nEScale, int nIterval, int nYbeg, int nYEnd)
// Purpose:    Implementation of RedAmberRect::RedAmberRect()
// Parameters:
// - nxBeg
// - nBScale
// - nEScale
// - nIterval
// - nYbeg
// - nYEnd
// Return:     
////////////////////////////////////////////////////////////////////////

RedAmberRect::RedAmberRect(int & nxBeg, int &cycle,int nBScale, int nEScale, int nIterval, int nYbeg, int nYEnd):
	Rect(nxBeg, cycle, nBScale, nEScale, nIterval, nYbeg,nYEnd)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       RedAmberRect::paint()
// Purpose:    Implementation of RedAmberRect::paint()
// Return:     void
////////////////////////////////////////////////////////////////////////

void RedAmberRect::paint(QPainter & painter)
{
	if (!bPainted)
	{
		return;
	}
   //1.�Ȼ���ɫ���ο�
	QPen pen;
	pen.setWidth(2);
	pen.setColor(Qt::yellow);
	painter.setPen(pen);
	if (isFixed)		//�Ƿ�̶�����
	{
		m_nEScale = m_nBScale + nFixState;
		if (m_nEScale>m_cycle)
		{
			m_nEScale = m_nEScale - m_cycle;
		}
	}

	Rect::paint(painter);

	//2.���м�ĺ���
	pen.setWidth(1);
	pen.setColor(Qt::red);
	painter.setPen(pen);
	int nxBeg = m_nxBeg+m_nBScale*m_nInterval;
	int nxEnd = m_nxBeg + m_nEScale*m_nInterval;
	int nyNum = m_nYBeg + (m_nYEnd-m_nYBeg)/2;

	if (m_bSelected)
	{
		if (nCurrenXB<=nCurrenXE)
		{
			for (int i=-2; i<3; i++)
			{
				painter.drawLine(QPoint(nCurrenXB, nyNum+i), QPoint(nCurrenXE, nyNum+i));
			}
			pen.setWidth(2);
			painter.drawLine(QPoint(nCurrenXB, m_nYEnd), QPoint(nCurrenXE, m_nYBeg));
		}else
		{
			for (int i=-2; i<3; i++)
			{
				painter.drawLine(QPoint(nCurrenXB, nyNum+i), QPoint(m_nxBeg+m_cycle*m_nInterval, nyNum+i));
				painter.drawLine(QPoint(m_nxBeg, nyNum+i), QPoint(nCurrenXE, nyNum+i));
			}
			pen.setWidth(2);
			painter.drawLine(QPoint(nCurrenXB, m_nYEnd), QPoint(m_nxBeg+m_cycle*m_nInterval, m_nYBeg));
			painter.drawLine(QPoint(m_nxBeg, m_nYEnd), QPoint(nCurrenXE, m_nYBeg));
		}

	}else
	{
		if (m_nBScale<m_nEScale)
		{
			for (int i=-2; i<3; i++)
			{
				painter.drawLine(QPoint(nxBeg, nyNum+i), QPoint(nxEnd, nyNum+i));
			}
			pen.setWidth(2);
			painter.drawLine(QPoint(nxBeg, m_nYEnd), QPoint(nxEnd, m_nYBeg));
		}else
		{
			for (int i=-2; i<3; i++)
			{
				painter.drawLine(QPoint(nxBeg, nyNum+i), QPoint(m_nxBeg+m_cycle*m_nInterval, nyNum+i));
				painter.drawLine(QPoint(m_nxBeg, nyNum+i), QPoint(nxEnd, nyNum+i));
			}
			pen.setWidth(2);
			painter.drawLine(QPoint(nxBeg, m_nYEnd), QPoint(m_nxBeg+m_cycle*m_nInterval, m_nYBeg));
			painter.drawLine(QPoint(m_nxBeg, m_nYEnd), QPoint(nxEnd, m_nYBeg));
		}
	}

	

}