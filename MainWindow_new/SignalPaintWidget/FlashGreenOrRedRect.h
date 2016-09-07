/***********************************************************************
 * Module:  FlashGreenRect.h
 * Author:  liuyufeng
 * Modified: 2015��8��11�� 11:34:47
 * Purpose: Declaration of the class FlashGreenRect
 * Comment: �������ο�
 *    ��ɫ���ο�
 *    ÿ���̶Ȼ�һ����ɫ����
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_2_FlashGreenRect_h)
#define __ObjectOrientedModel_2_FlashGreenRect_h

#include "Rect.h"

class FlashGreenOrRedRect : public Rect
{
public:
   FlashGreenOrRedRect(int & nxBeg,int &cycle, int nBScale=0, int nEScale=0, int nIterval=0, int nYbeg=0, int nYEnd=0);
   void paint(QPainter & painter);
   
protected:
private:

};

#endif