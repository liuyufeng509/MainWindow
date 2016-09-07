#ifndef TESTSIGNALLIGHTS_H
#define TESTSIGNALLIGHTS_H

#include <QtWidgets/QMainWindow>
#include "Shap.h"
#include <QList>
#include <QResizeEvent>
#include "Line.h"
#include "AmberRect.h"
#include "FlashAmber.h"
#include "FlashGreenOrRedRect.h"
#include "GreenRect.h"
#include "RedAmberRect.h"
#include "../common.h"

class TestSignalLights : public QMainWindow
{
	Q_OBJECT

public:
	TestSignalLights(SgDataInProg sgDataInProg, int row, int cycle, QWidget *parent = 0);
	~TestSignalLights();
	void setCycle(int cycle);		//设置周期大小
	void getBaseData();			//获取基础数据（宽，高，间隔大小等）
	void InitShapse();				//创建图形对象
	void drawScaleLine(QPainter &painter);
	SgDataInProg getData(){return curSgDataInProg;}
	void ResetAllShapInfo();
	void synchData();

	//获取各个颜色的结束刻度
	int getRedLineEnd(){return red_line->getEScale();}
	int getFlashRedEnd(){return flash_red_rect->getEScale();}
	int getGreenEnd(){return green_rect->getEScale();}
	
	void setRedLineEnd(int end);
	void setFlashRedEnd(int end);
	void setGreenEnd(int end);

	int getRedAmberFixedState(){return red_amber_rect->getFixedState();}
	int getAmberFixedState(){return amber_rect->getFixedState();}
	int getRedFlashFixedState(){return flash_red_rect->getFixedState();}
	void setRedAmberFixedState(int state);
	void setAmberFixedState(int state);
	void setRedFlashFixedState(int state);

	
	void setDefaultSignalSequece(SgDataInProg sgDataInProg);//根据当前的方案的sg信息更改图形显示
	void setDefaultCmdAndFixState();
public slots:
	void  comboxChanged(int index);

signals:
	void emitPaintChanged(int sequence, int row);
protected:
	void resizeEvent(QResizeEvent * event);
	void paintEvent(QPaintEvent *paint);
	void mousePressEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void updateDataInfo();			//当图形移动时，改变信号方案的刻度值。
private:

	QList<Shap*> shapList;	//当前显示的图形的指针
	QList<Shap*> allShapList;	//图形的指针
	int	m_nCycle;			//总的刻度值
	int	m_nWidth;		//窗口长度
	int	m_nHeight;		//高度
	int	m_nInterval;		//间隔
	int    m_nXbeg;		//0刻度坐标
	int    m_nYbeg;			//y的起始坐标
	int	m_nYend;			//y的结束坐标

	int  curSquence;
	SgDataInProg curSgDataInProg;
	Shap * curShap;

public:
	//图形指针
	Shap *red_line;
	Shap *off_line;
	Shap *red_amber_rect;
	Shap *green_rect;
	Shap *amber_rect;
	Shap *flash_green_rect;
	Shap *flash_amber_rect;
	Shap *flash_red_rect;
	int m_row;
};

#endif // TESTSIGNALLIGHTS_H
