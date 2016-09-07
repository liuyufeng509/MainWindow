/***********************************************************************
 * Module:  GreenRect.h
 * Author:  liuyufeng
 * Modified: 2015年8月11日 11:41:34
 * Purpose: Declaration of the class GreenRect
 * Comment: 绿灯矩形框：
 *    绿色矩形框
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_2_GreenRect_h)
#define __ObjectOrientedModel_2_GreenRect_h

#include "Rect.h"
#include <QBrush>

class GreenRect : public Rect
{
public:
   GreenRect(int & nxBeg,int &cycle, int nBScale=0, int nEScale=0, int nIterval=0, int nYbeg=0, int nYEnd=0);
   void paint(QPainter & painter);

protected:
private:

};

#endif