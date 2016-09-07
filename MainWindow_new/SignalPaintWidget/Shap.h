/***********************************************************************
 * Module:  Shap.h
 * Author:  liuyufeng
 * Modified: 2015年8月7日 16:47:44
 * Purpose: Declaration of the class Shap
 * Comment: 形状图形
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_2_Shap_h)
#define __ObjectOrientedModel_2_Shap_h
#include <QPainter>
#include<QPoint>
#include <QPen>
#include <QWidget>
#include <QtDebug>
#define  Border_Wid    5

enum enum_Direction		//鼠标方向
{
	eNone,
	eLeft,
	eRight
};

enum ShapType
{
	Red_Line=1,
	Red_Amber_Rect,
	Green_Rect,
	Amber_Rect,
	Flash_Green_Rect,
	Flash_Amber_Rect,
	OFF_Line,
	Flash_Red_Rect
};
class Shap
{
public:
   /* 构造函数 */
   Shap(int & nxBeg, int &cycle, int nBScale=0, int nEScale=0, int nIterval=0);
   /* 设置起始刻度 */
   void setBScale(int nBScale);
   /* 设置结束刻度 */
   void setEScale(int nEScale);
   /* 设置间隔 */
   void SetInterval(int nInterval);
   /* 获取起始刻度 */
   int getBScale(void);
   /* 获取结束刻度 */
   int getEScale(void);
   /* 获取间隔 */
   int getInterval(void);

   void setCurrentBX(int bx)
   {
	   nCurrenXB = bx;
	   if (nCurrenXB==m_cycle)
	   {
		   nCurrenXB=0;
	   }
   }
   int   getCurrentBX(){return nCurrenXB;}

   void setCurrentEX(int ex)
   {
	    nCurrenXE = ex;
	   if (nCurrenXE==0)		//如果结束刻度为0，则改为总刻度结尾值
	   {
		   nCurrenXE = m_cycle;
	   }
   }
   int   getCurrentEX(){return nCurrenXE;}

   int getFixedState(){return nFixState;}
   void setFixedState(int fixedState){nFixState = fixedState;}

   bool isShapFixed(){return isFixed;}
   void setShapFixed(bool bFixed){isFixed = bFixed;}

   void setScalePainted(bool isPaint){isScalePaint = isPaint;}

   ~Shap();
   /* 纯虚函数，画出自身的行为 */
   virtual   void paint(QPainter& painter)=0;

   virtual  void mousePress(int x, int y);		//鼠标点击
   virtual  void mouseMove(int x, int y);		//鼠标移动
   virtual  void mouseRelease(int x, int y);	//鼠标释放



   enum_Direction PointValid(int x, int y);		//判断当前的鼠标所在位置，用来设置鼠标的当前形状
   bool				isMouseIn(int x,int y);					//判断当前鼠标是否在图形内
   void				setCursorStyle(enum_Direction direction);	//设置鼠标形状
   enum_Direction			    setCursorStyle(int x, int y);
   void				setWidget(QWidget *widget){pWidget = widget;}	//主窗口的指针

   void				setShapType(ShapType shapType){this->shapType = shapType;}
   ShapType		getShapType(){return shapType;}
   void				setbPainted(bool painted){bPainted = painted;}		//表示该图形是否该被画出
   void				ReSetInfo(){m_nBScale=0; m_nEScale=0; m_nInterval=0;bPainted=false;canBeChanged = true;nFixState=0; isFixed=false;isScalePaint= false;}		//重新置位
   void				setCanBeChanged(bool can){canBeChanged = can;}			//是否可以更改移动：只是针对全红全绿灯情况。
   void				setSelected(bool isSlect)
   {
	   m_bSelected = isSlect;
   }
   bool				isSelected(){return m_bSelected;}

   void				ChangeXBandE();
   void				caclScaleLen();		
protected:
   /* 起始刻度 */
   int m_nBScale;
   /* 结束刻度 */
   int m_nEScale;
   /* 刻度的间隔宽度 */
   int m_nInterval;
   /* 0刻度坐标 */
   int & m_nxBeg;

   int m_nScaleLen;			//刻度长度

   int & m_cycle;		//周期长度，即总刻度大小

   QWidget *pWidget;			//主窗口，用来改变鼠标形状

   bool m_bSelected;		//是否按下

   QPoint	m_pos;			//鼠标的位置
  
   int nCurrenXB;
   int nCurrenXE;			//当前的x坐标的开始和结束值。
   QPoint  m_mvPos;		//移动的距离

   enum_Direction m_direction;		//方向

   ShapType shapType;			//图形种类

   bool	bPainted;				//是否被画
   
   bool canBeChanged;		//是否可以被改变长度，用于全红，全绿等单色灯得情况

  
   int nFixState;				//固定长度。
   bool isFixed;				//是否是固定长度

   bool isScalePaint;
public:

};

#endif