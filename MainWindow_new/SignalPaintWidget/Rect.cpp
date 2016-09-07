/***********************************************************************
 * Module:  Rect.cpp
 * Author:  liuyufeng
 * Modified: 2015��8��11�� 10:21:01
 * Purpose: Implementation of the class Rect
 * Comment: �����࣬�����ܹ�����һ�����ο������������ԣ�
 *    m_nYBeg  ���Ͻǵ�y����
 *    m_nYend  ���½ǵ�y����
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
// Comment:    ��һ�����Σ��麯��,�����Ǵ��麯��
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

	// ����ԭ����style
	QPen pen = painter.pen();
	//QBrush brush = painter.brush();

	//���̿�
//	painter.setBrush(QBrush(QColor(Qt::green)));
	

   // TODO : ���ȣ���һ������
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