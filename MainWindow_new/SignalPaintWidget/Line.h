/***********************************************************************
 * Module:  Line.h
 * Author:  liuyufeng
 * Modified: 2015年8月11日 8:59:26
 * Purpose: Declaration of the class Line
 * Comment: Red & Black(OFF)
 *    红线和黑线两种
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_2_Line_h)
#define __ObjectOrientedModel_2_Line_h

#include "Shap.h"

class Line : public Shap
{
public:
   Line(int &nxBeg, int &cycle, int nBScale=0, int nEScale=0, int nInterval=0, int yNum=0, bool isRed=true);
   void setYnum(int nYnum);
   /* 设置是红线还是黑线 */
   void setColorType(bool isRed);
   ~Line();
   /* 画线 */
   void paint(QPainter & painter);

protected:
private:
   /* 是否是红线 */
   bool m_bIsRed;
   /* y坐标 */
   int m_nYnum;


};

#endif