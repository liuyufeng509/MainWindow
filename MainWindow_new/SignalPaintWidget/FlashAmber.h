/***********************************************************************
 * Module:  FlashAmber.h
 * Author:  liuyufeng
 * Modified: 2015年8月11日 10:36:10
 * Purpose: Declaration of the class FlashAmber
 * Comment: 黄闪矩形：
 *    矩形一个刻度的小矩形的对角线
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_2_FlashAmber_h)
#define __ObjectOrientedModel_2_FlashAmber_h

#include "Rect.h"

class FlashAmber : public Rect
{
public:
   FlashAmber(int & nxBeg, int &cycle,int nBScale=0, int nEScale=0, int nIterval=0, int nYbeg=0, int nYEnd=0);
   void paint(QPainter & painter);

protected:
private:

};

#endif