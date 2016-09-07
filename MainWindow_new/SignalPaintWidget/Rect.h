/***********************************************************************
 * Module:  Rect.h
 * Author:  liuyufeng
 * Modified: 2015��8��11�� 10:21:01
 * Purpose: Declaration of the class Rect
 * Comment: �����࣬�����ܹ�����һ�����ο������������ԣ�
 *    m_nYBeg  ���Ͻǵ�y����
 *    m_nYend  ���½ǵ�y����
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_2_Rect_h)
#define __ObjectOrientedModel_2_Rect_h

#include "Shap.h"
#include <QPoint>
class Rect : public Shap
{
public:
   Rect(int & nxBeg, int &cycle, int nBScale=0, int nEScale=0, int nIterval=0, int nYbeg=0, int nYEnd=0);
   /* ��һ�����Σ��麯��,�����Ǵ��麯�� */
   virtual void paint(QPainter & painter);
   void setYBeg(int nYbeg);
   void setYEnd(int nYEnd);

protected:
   /* y��ʼ���� */
   int m_nYBeg;
   int m_nYEnd;


};

#endif