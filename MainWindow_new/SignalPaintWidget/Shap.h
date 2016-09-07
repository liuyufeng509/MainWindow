/***********************************************************************
 * Module:  Shap.h
 * Author:  liuyufeng
 * Modified: 2015��8��7�� 16:47:44
 * Purpose: Declaration of the class Shap
 * Comment: ��״ͼ��
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_2_Shap_h)
#define __ObjectOrientedModel_2_Shap_h
#include <QPainter>
#include<QPoint>
#include <QPen>
#include <QWidget>
#include <QtDebug>
#define  Border_Wid    5

enum enum_Direction		//��귽��
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
   /* ���캯�� */
   Shap(int & nxBeg, int &cycle, int nBScale=0, int nEScale=0, int nIterval=0);
   /* ������ʼ�̶� */
   void setBScale(int nBScale);
   /* ���ý����̶� */
   void setEScale(int nEScale);
   /* ���ü�� */
   void SetInterval(int nInterval);
   /* ��ȡ��ʼ�̶� */
   int getBScale(void);
   /* ��ȡ�����̶� */
   int getEScale(void);
   /* ��ȡ��� */
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
	   if (nCurrenXE==0)		//��������̶�Ϊ0�����Ϊ�̶ܿȽ�βֵ
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
   /* ���麯���������������Ϊ */
   virtual   void paint(QPainter& painter)=0;

   virtual  void mousePress(int x, int y);		//�����
   virtual  void mouseMove(int x, int y);		//����ƶ�
   virtual  void mouseRelease(int x, int y);	//����ͷ�



   enum_Direction PointValid(int x, int y);		//�жϵ�ǰ���������λ�ã������������ĵ�ǰ��״
   bool				isMouseIn(int x,int y);					//�жϵ�ǰ����Ƿ���ͼ����
   void				setCursorStyle(enum_Direction direction);	//���������״
   enum_Direction			    setCursorStyle(int x, int y);
   void				setWidget(QWidget *widget){pWidget = widget;}	//�����ڵ�ָ��

   void				setShapType(ShapType shapType){this->shapType = shapType;}
   ShapType		getShapType(){return shapType;}
   void				setbPainted(bool painted){bPainted = painted;}		//��ʾ��ͼ���Ƿ�ñ�����
   void				ReSetInfo(){m_nBScale=0; m_nEScale=0; m_nInterval=0;bPainted=false;canBeChanged = true;nFixState=0; isFixed=false;isScalePaint= false;}		//������λ
   void				setCanBeChanged(bool can){canBeChanged = can;}			//�Ƿ���Ը����ƶ���ֻ�����ȫ��ȫ�̵������
   void				setSelected(bool isSlect)
   {
	   m_bSelected = isSlect;
   }
   bool				isSelected(){return m_bSelected;}

   void				ChangeXBandE();
   void				caclScaleLen();		
protected:
   /* ��ʼ�̶� */
   int m_nBScale;
   /* �����̶� */
   int m_nEScale;
   /* �̶ȵļ����� */
   int m_nInterval;
   /* 0�̶����� */
   int & m_nxBeg;

   int m_nScaleLen;			//�̶ȳ���

   int & m_cycle;		//���ڳ��ȣ����̶ܿȴ�С

   QWidget *pWidget;			//�����ڣ������ı������״

   bool m_bSelected;		//�Ƿ���

   QPoint	m_pos;			//����λ��
  
   int nCurrenXB;
   int nCurrenXE;			//��ǰ��x����Ŀ�ʼ�ͽ���ֵ��
   QPoint  m_mvPos;		//�ƶ��ľ���

   enum_Direction m_direction;		//����

   ShapType shapType;			//ͼ������

   bool	bPainted;				//�Ƿ񱻻�
   
   bool canBeChanged;		//�Ƿ���Ա��ı䳤�ȣ�����ȫ�죬ȫ�̵ȵ�ɫ�Ƶ����

  
   int nFixState;				//�̶����ȡ�
   bool isFixed;				//�Ƿ��ǹ̶�����

   bool isScalePaint;
public:

};

#endif