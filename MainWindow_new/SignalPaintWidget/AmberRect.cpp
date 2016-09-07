/***********************************************************************
 * Module:  AmberRect.cpp
 * Author:  liuyufeng
 * Modified: 2015��8��11�� 11:39:34
 * Purpose: Implementation of the class AmberRect
 * Comment: �Ƶƾ��ο�
 *    ��ɫ���ο�
 *    ��ɫ�Խ���
 ***********************************************************************/

#include "AmberRect.h"

////////////////////////////////////////////////////////////////////////
// Name:       AmberRect::AmberRect(int & nxBeg, int nBScale, int nEScale, int nIterval, int nYbeg, int nYEnd)
// Purpose:    Implementation of AmberRect::AmberRect()
// Parameters:
// - nxBeg
// - nBScale
// - nEScale
// - nIterval
// - nYbeg
// - nYEnd
// Return:     
////////////////////////////////////////////////////////////////////////

AmberRect::AmberRect(int & nxBeg, int &cycle,int nBScale, int nEScale, int nIterval, int nYbeg, int nYEnd):
	Rect(nxBeg, cycle,nBScale, nEScale, nIterval, nYbeg, nYEnd)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       AmberRect::paint(QPainter & painter)
// Purpose:    Implementation of AmberRect::paint()
// Parameters:
// - painter
// Return:     void
////////////////////////////////////////////////////////////////////////

void AmberRect::paint(QPainter & painter)
{
	if (!bPainted)
	{
		return;
	}
   //1.����ɫ���ο�
	QPen pen;
	pen.setWidth(2);
	pen.setColor(Qt::yellow);
	painter.setPen(pen);
	Rect::paint(painter);

	if (isFixed)		//�Ƿ�̶�����
	{
		m_nEScale = m_nBScale + nFixState;
		if (m_nEScale>m_cycle)
		{
			m_nEScale = m_nEScale - m_cycle;
		}
	}

   //2.���Խ���
	int nxBeg = m_nxBeg + m_nBScale*m_nInterval;
	int nxEnd = m_nxBeg + m_nEScale*m_nInterval;
	if (m_bSelected)
	{
		if (nCurrenXB<=nCurrenXE)
		{
			painter.drawLine(QPoint(nCurrenXB, m_nYEnd), QPoint(nCurrenXE, m_nYBeg));
		}else
		{
			painter.drawLine(QPoint(nCurrenXB,m_nYEnd), QPoint(m_nxBeg +m_cycle*m_nInterval, m_nYBeg));
			painter.drawLine(QPoint(m_nxBeg,m_nYEnd), QPoint(nCurrenXE, m_nYBeg));
		}
		
	}else
	{
		if (m_nBScale<m_nEScale)
		{
			painter.drawLine(QPoint(nxBeg, m_nYEnd), QPoint(nxEnd, m_nYBeg));
		}else
		{
			painter.drawLine(QPoint(nxBeg, m_nYEnd), QPoint(m_nxBeg +m_cycle*m_nInterval, m_nYBeg));
			painter.drawLine(QPoint(m_nxBeg, m_nYEnd), QPoint(nxEnd, m_nYBeg));
		}
	}

}