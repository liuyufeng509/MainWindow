/***********************************************************************
 * Module:  AmberRect.h
 * Author:  liuyufeng
 * Modified: 2015年8月11日 11:39:34
 * Purpose: Declaration of the class AmberRect
 * Comment: 黄灯矩形框：
 *    黄色矩形框
 *    黄色对角线
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_2_AmberRect_h)
#define __ObjectOrientedModel_2_AmberRect_h

#include "Rect.h"

class AmberRect : public Rect
{
public:
   AmberRect(int & nxBeg,int &cycle, int nBScale=0, int nEScale=0, int nIterval=0, int nYbeg=0, int nYEnd=0);
   void paint(QPainter & painter);

protected:
private:

};

#endif