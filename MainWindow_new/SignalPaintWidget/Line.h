/***********************************************************************
 * Module:  Line.h
 * Author:  liuyufeng
 * Modified: 2015��8��11�� 8:59:26
 * Purpose: Declaration of the class Line
 * Comment: Red & Black(OFF)
 *    ���ߺͺ�������
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_2_Line_h)
#define __ObjectOrientedModel_2_Line_h

#include "Shap.h"

class Line : public Shap
{
public:
   Line(int &nxBeg, int &cycle, int nBScale=0, int nEScale=0, int nInterval=0, int yNum=0, bool isRed=true);
   void setYnum(int nYnum);
   /* �����Ǻ��߻��Ǻ��� */
   void setColorType(bool isRed);
   ~Line();
   /* ���� */
   void paint(QPainter & painter);

protected:
private:
   /* �Ƿ��Ǻ��� */
   bool m_bIsRed;
   /* y���� */
   int m_nYnum;


};

#endif