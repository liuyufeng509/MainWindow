/***********************************************************************
 * Module:  Rect.h
 * Author:  liuyufeng
 * Modified: 2015年8月11日 10:21:01
 * Purpose: Declaration of the class Rect
 * Comment: 抽象类，但是能够画出一个矩形框，增加以下属性：
 *    m_nYBeg  左上角的y坐标
 *    m_nYend  右下角的y坐标
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_2_Rect_h)
#define __ObjectOrientedModel_2_Rect_h

#include "Shap.h"
#include <QPoint>
class Rect : public Shap
{
public:
   Rect(int & nxBeg, int &cycle, int nBScale=0, int nEScale=0, int nIterval=0, int nYbeg=0, int nYEnd=0);
   /* 画一个矩形，虚函数,但不是纯虚函数 */
   virtual void paint(QPainter & painter);
   void setYBeg(int nYbeg);
   void setYEnd(int nYEnd);

protected:
   /* y起始坐标 */
   int m_nYBeg;
   int m_nYEnd;


};

#endif