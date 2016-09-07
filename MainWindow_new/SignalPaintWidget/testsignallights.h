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
	void setCycle(int cycle);		//�������ڴ�С
	void getBaseData();			//��ȡ�������ݣ����ߣ������С�ȣ�
	void InitShapse();				//����ͼ�ζ���
	void drawScaleLine(QPainter &painter);
	SgDataInProg getData(){return curSgDataInProg;}
	void ResetAllShapInfo();
	void synchData();

	//��ȡ������ɫ�Ľ����̶�
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

	
	void setDefaultSignalSequece(SgDataInProg sgDataInProg);//���ݵ�ǰ�ķ�����sg��Ϣ����ͼ����ʾ
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
	void updateDataInfo();			//��ͼ���ƶ�ʱ���ı��źŷ����Ŀ̶�ֵ��
private:

	QList<Shap*> shapList;	//��ǰ��ʾ��ͼ�ε�ָ��
	QList<Shap*> allShapList;	//ͼ�ε�ָ��
	int	m_nCycle;			//�ܵĿ̶�ֵ
	int	m_nWidth;		//���ڳ���
	int	m_nHeight;		//�߶�
	int	m_nInterval;		//���
	int    m_nXbeg;		//0�̶�����
	int    m_nYbeg;			//y����ʼ����
	int	m_nYend;			//y�Ľ�������

	int  curSquence;
	SgDataInProg curSgDataInProg;
	Shap * curShap;

public:
	//ͼ��ָ��
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
