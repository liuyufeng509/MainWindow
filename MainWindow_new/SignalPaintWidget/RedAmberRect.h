/***********************************************************************
 * Module:  RedAmberRect.h
 * Author:  liuyufeng
 * Modified: 2015��8��11�� 10:39:11
 * Purpose: Declaration of the class RedAmberRect
 * Comment: ��ƾ��Σ�
 *    ��ɫ���ο�
 *    �Խ���Ϊ����
 *    �м�ˮƽƽ����Ϊ��ɫ
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_2_RedAmberRect_h)
#define __ObjectOrientedModel_2_RedAmberRect_h

#include "Rect.h"

class RedAmberRect : public Rect
{
public:
   RedAmberRect(int & nxBeg, int &cycle,int nBScale=0, int nEScale=0, int nIterval=0, int nYbeg=0, int nYEnd=0);
   void paint(QPainter &painter);

protected:
private:

};

#endif