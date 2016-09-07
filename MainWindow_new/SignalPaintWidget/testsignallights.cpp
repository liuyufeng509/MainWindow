#include "testsignallights.h"
#include <QMap>
TestSignalLights::TestSignalLights(SgDataInProg sgDataInProg,int row, int  cycle, QWidget *parent)
	: QMainWindow(parent),
	m_nWidth(600),
	m_nHeight(200),
	m_nCycle(cycle),
	curShap(NULL),
	m_row(row)
{
	if (m_nCycle<=0)
	{
		m_nCycle = 60;
	}
	QPalette palett = palette();
	palett.setColor(QPalette::Background, QColor(100, 100, 100));
	setPalette(palett);
	this->setAutoFillBackground(true);
	setMouseTracking(true);	//鼠标移动
	resize(m_nWidth, m_nHeight);
	//初始化数据
	//setCycle(100);

	//初始化各个图形
	InitShapse();
	curSgDataInProg = sgDataInProg;
	setDefaultSignalSequece(curSgDataInProg);
}

void TestSignalLights::setRedLineEnd(int end)
{
	red_line->setEScale(end);

	switch (curSquence)
	{
	case COLOR_SEQU_RED_REDAMBER_GREEN_AMBER:
	case COLOR_SEQU_RED_REDAMBER_GREEN_GREENFLASH_AMBER:
		{
			red_amber_rect->setBScale(red_line->getEScale());
			red_amber_rect->setEScale(red_amber_rect->getFixedState()+red_amber_rect->getBScale());
			green_rect->setBScale(red_amber_rect->getEScale());
		}
		break;
	case COLOR_SEQU_RED_GREEN:
	case COLOR_SEQU_RED_GREEN_GREENFLASH:
	case COLOR_SEQU_RED_GREEN_AMBER:
	case COLOR_SEQU_RED_GREEN_REDFLASH:
		{
			green_rect->setBScale(red_line->getEScale());
		}
		break;
	case COLOR_SEQU_RED_OFF:
	case COLOR_SEQU_RED_OFF_AMBER:
		{
			off_line->setBScale(red_line->getEScale());
		}
		break;

	default:
		break;
	}
	update();
}

void TestSignalLights::setFlashRedEnd(int end)
{
	flash_red_rect->setEScale(end);
	off_line->setBScale(flash_red_rect->getEScale());
	update();
}

void TestSignalLights::setGreenEnd(int end)
{
	green_rect->setEScale(end);
	switch (curSquence)
	{
	case COLOR_SEQU_RED_REDAMBER_GREEN_AMBER:
		{
			amber_rect->setBScale(end);
			amber_rect->setEScale(end + amber_rect->getFixedState());
			red_line->setBScale(amber_rect->getEScale());
		}
		break;
	case COLOR_SEQU_RED_GREEN:
		{
			red_line->setBScale(end);
		}
		break;
	case COLOR_SEQU_RED_REDAMBER_GREEN_GREENFLASH_AMBER:
		{
			flash_green_rect->setBScale(end);
			flash_green_rect->setEScale(end+flash_green_rect->getFixedState());
			amber_rect->setBScale(flash_green_rect->getEScale());
			amber_rect->setEScale(amber_rect->getBScale()+amber_rect->getFixedState());
			red_line->setBScale(amber_rect->getEScale());
		}
		break;
	case COLOR_SEQU_RED_GREEN_GREENFLASH:
		{
			flash_green_rect->setBScale(end);
			flash_green_rect->setEScale(end+flash_green_rect->getFixedState());
			red_line->setBScale(flash_green_rect->getEScale());
		}
		break;
	case COLOR_SEQU_RED_GREEN_AMBER:
		{
			amber_rect->setBScale(green_rect->getEScale());
			amber_rect->setEScale(end+amber_rect->getFixedState());
		}
		break;
	case COLOR_SEQU_OFF_GREEN:
		{
			off_line->setBScale(end);
		}
		break;
	case COLOR_SEQU_RED_GREEN_REDFLASH:
		{
			flash_red_rect->setBScale(end);
			flash_red_rect->setEScale(end+ flash_red_rect->getFixedState());
			red_line->setBScale(flash_red_rect->getEScale());
		}
		break;
	default:
		break;
	}
	update();
}

void TestSignalLights::setRedAmberFixedState(int state)
{
	int dx = state-red_amber_rect->getFixedState();
	red_amber_rect->setEScale(red_amber_rect->getEScale()+dx);
	red_amber_rect->setFixedState(state);

	green_rect->setBScale(red_amber_rect->getEScale());
	update();
}

void TestSignalLights::setAmberFixedState(int state)
{
	int dx = state-amber_rect->getFixedState();
	amber_rect->setEScale(amber_rect->getEScale()+dx);
	amber_rect->setFixedState(state);

	red_line->setBScale(amber_rect->getEScale());
	update();
}

void TestSignalLights::setRedFlashFixedState(int state)
{
	int dx = state-flash_red_rect->getFixedState();
	flash_red_rect->setEScale(flash_red_rect->getEScale()+dx);
	flash_red_rect->setFixedState(state);

	red_line->setBScale(flash_red_rect->getEScale());
	update();
}

void TestSignalLights::InitShapse()
{
	//1.创建灯线，初始化为长度为0
	red_line = new Line(m_nXbeg,m_nCycle, 0, 0, m_nInterval, m_nYend/2, true);
	red_line->setShapType(Red_Line);
	red_line->setWidget(this);
	allShapList<<red_line;
	//2.创建关灯黑线，初始化为长度为0
	off_line = new Line(m_nXbeg, m_nCycle,0, 0, m_nInterval, m_nYend/2, false);
	off_line->setShapType(OFF_Line);
	off_line->setWidget(this);
	allShapList<<off_line;
	//3.创建红黄矩形，矩形上下框边界可根据实际图形适当调整
	red_amber_rect = new RedAmberRect(m_nXbeg,m_nCycle, 0, 0, m_nInterval, 30, m_nYend-60);
	red_amber_rect->setShapType(Red_Amber_Rect);
	red_amber_rect->setWidget(this);
	allShapList<<red_amber_rect;
	//4.创建绿灯矩形框
	green_rect = new GreenRect(m_nXbeg,m_nCycle, 0, 0, m_nInterval, 30, m_nYend-30);
	green_rect->setShapType(Green_Rect);
	green_rect->setWidget(this);
	allShapList<<green_rect;
	//5.创建黄灯框
	amber_rect = new AmberRect(m_nXbeg,m_nCycle, 0, 0, m_nInterval, 30, m_nYend-30);
	amber_rect->setShapType(Amber_Rect);
	amber_rect->setWidget(this);
	allShapList<<amber_rect;
	//6.创建绿闪框
	flash_green_rect = new FlashGreenOrRedRect(m_nXbeg, m_nCycle,0, 0, m_nInterval, 30, m_nYend-60);
	flash_green_rect->setShapType(Flash_Green_Rect);
	flash_green_rect->setWidget(this);
	allShapList<<flash_green_rect;
	//5.创建黄闪框
	flash_amber_rect = new FlashAmber(m_nXbeg,m_nCycle, 0, 0, m_nInterval, 30, m_nYend-60);
	flash_amber_rect->setShapType(Flash_Amber_Rect);
	flash_amber_rect->setWidget(this);
	allShapList<<flash_amber_rect;
	//5.创建红闪框
	flash_red_rect = new FlashGreenOrRedRect(m_nXbeg, m_nCycle,0, 0, m_nInterval, 30, m_nYend-60);
	flash_red_rect->setShapType(Flash_Red_Rect);
	flash_red_rect->setWidget(this);
	allShapList<<flash_red_rect;
}

void TestSignalLights::setCycle(int cycle)
{
	m_nCycle = cycle;
	if (m_nCycle<=0)
	{
		m_nCycle=60;
	}
	getBaseData();
	setDefaultSignalSequece(curSgDataInProg);
}

void TestSignalLights::getBaseData()
{
	m_nInterval = m_nWidth/m_nCycle;
	m_nXbeg = (m_nWidth-m_nCycle*m_nInterval)/2;		//0刻度的起始坐标
	m_nYbeg = 0;		//y起始坐标为0
	m_nYend = rect().height();//y结束坐标为矩形底部。
}

//画刻度线
void TestSignalLights::drawScaleLine(QPainter &painter)
{
	
	painter.setBrush(QBrush(QColor(230,230,230)));
	painter.drawRect(m_nXbeg, 0, rect().width()-m_nXbeg*2, rect().height());

	//画刻度和刻度值
	for(int i=0; i<=m_nCycle; i++)
	{
		if(i%5 == 0)
		{
			painter.setPen(QPen(QColor(Qt::red)));
			painter.drawText(QPoint(i*m_nInterval+m_nXbeg-5, m_nYbeg+20),QString::number(i));
			painter.drawText(QPoint(i*m_nInterval+m_nXbeg-5,  m_nYend-10),QString::number(i));
		}else
		{
			painter.setPen(QPen(QColor(Qt::blue)));
		}
		painter.drawLine(i*m_nInterval+m_nXbeg, 0, i*m_nInterval+m_nXbeg, m_nYbeg+10);
		painter.drawLine(i*m_nInterval+m_nXbeg, rect().height(), i*m_nInterval+m_nXbeg, m_nYend-10);
	}
}

//获取窗口大小，图形的大小及刻度的大小是按照窗口大小进行计算调整的。
void TestSignalLights::resizeEvent(QResizeEvent * event)
{
	m_nHeight = event->size().height();
	m_nWidth = event->size().width();	
	getBaseData();
	for (int i=0; i<allShapList.size(); i++)//设置
	{
		if (allShapList.at(i)->getShapType()==Red_Line ||
			allShapList.at(i)->getShapType()==OFF_Line)
		{
			Line *line = static_cast<Line*>(allShapList.at(i));
			line->setYnum(m_nYend/2);
		}else
		{
			Rect *rect = static_cast<Rect*>(allShapList.at(i));
			rect->setYBeg(m_nYbeg+30);
			rect->setYEnd(m_nYend -30);
		}
		allShapList.at(i)->SetInterval(m_nInterval);		//更新间隔
	}
}

//画图
void TestSignalLights::paintEvent(QPaintEvent *p)
{
	QPainter  painter(this);
	if(m_nCycle<=0)
		QWidget::paintEvent(p);
	else
	{
		//画刻度线
		drawScaleLine(painter);
		//画中间信号灯
		for (int i=0; i<shapList.size(); i++)
		{
			shapList.at(i)->paint(painter);
		}
	}
}

void TestSignalLights::mousePressEvent(QMouseEvent *event)
{
	if(event->button() == Qt::LeftButton)
	{
		for (int i=0; i<shapList.size(); i++)
		{ 
			shapList.at(i)->mousePress(event->x(), event->y());
			if (shapList.at(i)->isSelected())
			{
				curShap = shapList.at(i);
			}
		}
	}
	
}

#define TwoShapCasCade() \
	if (curShap->isSelected())					\
{															\
	for (int i=0; i<shapList.size(); i++)		\
	{                                                       \
		if (shapList.at(i)!=curShap)				\
		{                                                   \
			shapList.at(i)->setSelected(true);	\
			shapList.at(i)->setCurrentBX(curShap->getCurrentEX());	\
			shapList.at(i)->setCurrentEX(curShap->getCurrentBX());	\
		}																							\
	}																										\
}

void TestSignalLights:: synchData()
{
	switch (curSquence)
	{
	case COLOR_SEQU_RED_GREEN:		//红绿
		{
			TwoShapCasCade();
		}
		break;
	case COLOR_SEQU_RED_OFF:			//红黑
		{
			TwoShapCasCade();
		}
		break;
	case COLOR_SEQU_OFF_GREEN:			//黑绿
		{
			TwoShapCasCade();
		}
		break;
	case COLOR_SEQU_AMBERFLASH_OFF:			//黄闪-关灯
		{
			TwoShapCasCade();
		}
		break;

	case COLOR_SEQU_REDFLASH_OFF:			//红闪-关灯
		{
			TwoShapCasCade();
		}
		break;	
	case COLOR_SEQU_RED_GREEN_GREENFLASH:  //红 绿 绿闪
		{
			int redBeg=0, greenBeg=0, greenFlashFixed=0;
			if (curShap->getShapType()==Red_Line)
			{
				redBeg = curShap->getCurrentBX();
				
				if (curShap->isSelected())			//鼠标按下后的动作
				{
					green_rect->setSelected(true);
					flash_green_rect->setSelected(true);

					greenFlashFixed = flash_green_rect->getFixedState();
					green_rect->setCurrentBX(curShap->getCurrentEX());	//绿色
					green_rect->setCurrentEX(curShap->getCurrentBX()-greenFlashFixed*m_nInterval);
					flash_green_rect->setCurrentBX(curShap->getCurrentBX()-greenFlashFixed*m_nInterval);
					flash_green_rect->setCurrentEX(curShap->getCurrentBX());
				}
			}

			if (curShap->getShapType()==Green_Rect)
			{
				greenBeg = curShap->getCurrentBX();

				if (curShap->isSelected())			//鼠标按下后的动作
				{
					red_line->setSelected(true);
					flash_green_rect->setSelected(true);

					greenFlashFixed = flash_green_rect->getFixedState();
					flash_green_rect->setCurrentBX(curShap->getCurrentEX());	//绿色
					flash_green_rect->setCurrentEX(curShap->getCurrentEX()+greenFlashFixed*m_nInterval);
					red_line->setCurrentBX(flash_green_rect->getCurrentEX());
					red_line->setCurrentEX(curShap->getCurrentBX());
				}
			}

			if (curShap->getShapType()==Flash_Green_Rect)
			{
				greenFlashFixed = curShap->getFixedState();

				if (curShap->isSelected())			//鼠标按下后的动作
				{
					green_rect->setSelected(true);
					red_line->setSelected(true);

 					green_rect->setCurrentEX(curShap->getCurrentBX());	//绿色
 					red_line->setCurrentBX(curShap->getCurrentBX()+greenFlashFixed*m_nInterval);
					red_line->setCurrentEX(green_rect->getCurrentBX());
				}
			}
		}
		break;
	case COLOR_SEQU_RED_OFF_AMBER:
		{
			int redBeg=0, offBeg=0, amberFixed=0;
			if (curShap->getShapType()==Red_Line)
			{
				redBeg = curShap->getCurrentBX();

				if (curShap->isSelected())			//鼠标按下后的动作
				{
					off_line->setSelected(true);
					amber_rect->setSelected(true);

					amberFixed = amber_rect->getFixedState();
					off_line->setCurrentBX(curShap->getCurrentEX());	//绿色
					off_line->setCurrentEX(curShap->getCurrentBX()-amberFixed*m_nInterval);
					amber_rect->setCurrentBX(curShap->getCurrentBX()-amberFixed*m_nInterval);
					amber_rect->setCurrentEX(curShap->getCurrentBX());
				}
			}

			if (curShap->getShapType()==OFF_Line)
			{
				offBeg = curShap->getCurrentBX();

				if (curShap->isSelected())			//鼠标按下后的动作
				{
					red_line->setSelected(true);
					amber_rect->setSelected(true);

					amberFixed = amber_rect->getFixedState();
					amber_rect->setCurrentBX(curShap->getCurrentEX());	//绿色
					amber_rect->setCurrentEX(curShap->getCurrentEX()+amberFixed*m_nInterval);
					red_line->setCurrentBX(amber_rect->getCurrentEX());
					red_line->setCurrentEX(curShap->getCurrentBX());
				}
			}

			if (curShap->getShapType()==Amber_Rect)
			{
				amberFixed = curShap->getFixedState();

				if (curShap->isSelected())			//鼠标按下后的动作
				{
					off_line->setSelected(true);
					red_line->setSelected(true);

					off_line->setCurrentEX(curShap->getCurrentBX());	//绿色
					red_line->setCurrentBX(curShap->getCurrentBX()+amberFixed*m_nInterval);
					red_line->setCurrentEX(off_line->getCurrentBX());
				}
			}
		}
		break;
	case COLOR_SEQU_RED_GREEN_REDFLASH:		//红 绿 红闪
		{
			int redBeg=0, greenBeg=0, flashRedFixed=0;
			if (curShap->getShapType()==Red_Line)
			{
				redBeg = curShap->getCurrentBX();

				if (curShap->isSelected())			//鼠标按下后的动作
				{
					green_rect->setSelected(true);
					flash_red_rect->setSelected(true);

					flashRedFixed = flash_red_rect->getFixedState();
					green_rect->setCurrentBX(curShap->getCurrentEX());	//绿色
					green_rect->setCurrentEX(curShap->getCurrentBX()-flashRedFixed*m_nInterval);
					flash_red_rect->setCurrentBX(curShap->getCurrentBX()-flashRedFixed*m_nInterval);
					flash_red_rect->setCurrentEX(curShap->getCurrentBX());
				}
			}

			if (curShap->getShapType()==Green_Rect)
			{
				greenBeg = curShap->getCurrentBX();

				if (curShap->isSelected())			//鼠标按下后的动作
				{
					red_line->setSelected(true);
					flash_red_rect->setSelected(true);

					flashRedFixed = flash_red_rect->getFixedState();
					flash_red_rect->setCurrentBX(curShap->getCurrentEX());	//绿色
					flash_red_rect->setCurrentEX(curShap->getCurrentEX()+flashRedFixed*m_nInterval);
					red_line->setCurrentBX(flash_red_rect->getCurrentEX());
					red_line->setCurrentEX(curShap->getCurrentBX());
				}
			}

			if (curShap->getShapType()==Flash_Red_Rect)
			{
				flashRedFixed = curShap->getFixedState();

				if (curShap->isSelected())			//鼠标按下后的动作
				{
					green_rect->setSelected(true);
					red_line->setSelected(true);

					green_rect->setCurrentEX(curShap->getCurrentBX());	//绿色
					red_line->setCurrentBX(curShap->getCurrentBX()+flashRedFixed*m_nInterval);
					red_line->setCurrentEX(green_rect->getCurrentBX());
				}
			}
		}
		break;
	case COLOR_SEQU_RED_GREEN_AMBER:  //红 绿 黄
		{
			int redBeg=0, greenBeg=0, amberFixed=0;
			if (curShap->getShapType()==Red_Line)
			{
				redBeg = curShap->getCurrentBX();

				if (curShap->isSelected())			//鼠标按下后的动作
				{
					green_rect->setSelected(true);
					amber_rect->setSelected(true);

					amberFixed = amber_rect->getFixedState();
					green_rect->setCurrentBX(curShap->getCurrentEX());	//绿色
					green_rect->setCurrentEX(curShap->getCurrentBX()-amberFixed*m_nInterval);
					amber_rect->setCurrentBX(curShap->getCurrentBX()-amberFixed*m_nInterval);
					amber_rect->setCurrentEX(curShap->getCurrentBX());
				}
			}

			if (curShap->getShapType()==Green_Rect)
			{
				greenBeg = curShap->getCurrentBX();

				if (curShap->isSelected())			//鼠标按下后的动作
				{
					red_line->setSelected(true);
					amber_rect->setSelected(true);

					amberFixed = amber_rect->getFixedState();
					amber_rect->setCurrentBX(curShap->getCurrentEX());	//绿色
					amber_rect->setCurrentEX(curShap->getCurrentEX()+amberFixed*m_nInterval);
					red_line->setCurrentBX(amber_rect->getCurrentEX());
					red_line->setCurrentEX(curShap->getCurrentBX());
				}
			}

			if (curShap->getShapType()==Amber_Rect)
			{
				amberFixed = curShap->getFixedState();

				if (curShap->isSelected())			//鼠标按下后的动作
				{
					green_rect->setSelected(true);
					red_line->setSelected(true);

					green_rect->setCurrentEX(curShap->getCurrentBX());	//绿色
					red_line->setCurrentBX(curShap->getCurrentBX()+amberFixed*m_nInterval);
					red_line->setCurrentEX(green_rect->getCurrentBX());
				}
			}
		}
		break;
	case COLOR_SEQU_RED_REDAMBER_GREEN_AMBER:  //红 红黄 绿 黄
		{
			int redBeg = 0, greenBeg=0, amberFixed=0, redAmberFixed=0;
			amberFixed = amber_rect->getFixedState();
			redAmberFixed = red_amber_rect->getFixedState();
			if (curShap->getShapType()==Red_Line)
			{
				redBeg = curShap->getCurrentBX();

				if (curShap->isSelected())
				{
					red_amber_rect->setSelected(true);
					green_rect->setSelected(true);
					amber_rect->setSelected(true);

					red_amber_rect->setCurrentBX(curShap->getCurrentEX());
					red_amber_rect->setCurrentEX(red_amber_rect->getCurrentBX()+redAmberFixed*m_nInterval);
					green_rect->setCurrentEX(curShap->getCurrentBX()-amberFixed*m_nInterval);
					green_rect->setCurrentBX(curShap->getCurrentEX()+redAmberFixed*m_nInterval);
					amber_rect->setCurrentBX(green_rect->getCurrentEX());
					amber_rect->setCurrentEX(curShap->getCurrentBX());
				}
			}

			if (curShap->getShapType()==Green_Rect)
			{
				greenBeg = curShap->getCurrentBX();

				if (curShap->isSelected())
				{
					red_amber_rect->setSelected(true);
					red_line->setSelected(true);
					amber_rect->setSelected(true);

					amber_rect->setCurrentBX(curShap->getCurrentEX());
					amber_rect->setCurrentEX(amber_rect->getCurrentBX()+amberFixed*m_nInterval);

					red_amber_rect->setCurrentBX(curShap->getCurrentBX()-redAmberFixed*m_nInterval);
					red_amber_rect->setCurrentEX(red_amber_rect->getCurrentBX()+redAmberFixed*m_nInterval);

					red_line->setCurrentBX(amber_rect->getCurrentEX());
					red_line->setCurrentEX(curShap->getCurrentBX()-redAmberFixed*m_nInterval);					
				}
			}

			if (curShap->getShapType()==Amber_Rect)
			{

				if (curShap->isSelected())			//鼠标按下后的动作
				{
					green_rect->setSelected(true);
					red_line->setSelected(true);
					red_amber_rect->setSelected(true);

					red_line->setCurrentBX(curShap->getCurrentEX());
					green_rect->setCurrentEX(curShap->getCurrentBX());	//绿色
					red_amber_rect->setCurrentBX(green_rect->getCurrentBX()-redAmberFixed*m_nInterval);
					red_amber_rect->setCurrentEX(red_amber_rect->getCurrentBX()+redAmberFixed*m_nInterval);
				}
			}

			if (curShap->getShapType()==Red_Amber_Rect)
			{
				
				if (curShap->isSelected())			//鼠标按下后的动作
				{
					green_rect->setSelected(true);
					red_line->setSelected(true);
					amber_rect->setSelected(true);

					red_line->setCurrentEX(curShap->getCurrentBX());
					green_rect->setCurrentBX(curShap->getCurrentEX());	//绿色
					amber_rect->setCurrentBX(red_line->getCurrentBX()-amberFixed*m_nInterval);
					amber_rect->setCurrentEX(red_line->getCurrentBX());
				}
			}
		}
		break;
	case COLOR_SEQU_RED_REDAMBER_GREEN_GREENFLASH_AMBER:		//红 红黄 绿 绿闪 黄
		{
			int redBeg = 0, greenBeg=0, amberFixed=0, redAmberFixed=0, flashGreenFixed=0;
			amberFixed = amber_rect->getFixedState();
			redAmberFixed = red_amber_rect->getFixedState();
			flashGreenFixed = flash_green_rect->getFixedState();

			if (curShap->getShapType()==Red_Line)
			{
				redBeg = curShap->getCurrentBX();

				if (curShap->isSelected())
				{
					red_amber_rect->setSelected(true);
					green_rect->setSelected(true);
					amber_rect->setSelected(true);
					flash_green_rect->setSelected(true);

					red_amber_rect->setCurrentBX(red_line->getCurrentEX());
					red_amber_rect->setCurrentEX(red_amber_rect->getCurrentBX()+redAmberFixed*m_nInterval);

					green_rect->setCurrentBX(red_amber_rect->getCurrentEX());
					green_rect->setCurrentEX(red_line->getCurrentBX()-(amberFixed+flashGreenFixed)*m_nInterval);

					amber_rect->setCurrentBX(green_rect->getCurrentEX()+flashGreenFixed*m_nInterval);
					amber_rect->setCurrentEX(red_line->getCurrentBX());

					flash_green_rect->setCurrentBX(green_rect->getCurrentEX());
					flash_green_rect->setCurrentEX(flash_green_rect->getCurrentBX()+flashGreenFixed*m_nInterval);
				}
			}

			if (curShap->getShapType()==Green_Rect)
			{
				greenBeg = curShap->getCurrentBX();

				if (curShap->isSelected())
				{
					red_amber_rect->setSelected(true);
					red_line->setSelected(true);
					amber_rect->setSelected(true);
					flash_green_rect->setSelected(true);

					flash_green_rect->setCurrentBX(green_rect->getCurrentEX());
					flash_green_rect->setCurrentEX(flash_green_rect->getCurrentBX()+flashGreenFixed*m_nInterval);

					amber_rect->setCurrentBX(green_rect->getCurrentEX()+flashGreenFixed*m_nInterval);
					amber_rect->setCurrentEX(amber_rect->getCurrentBX()+amberFixed*m_nInterval);

					red_amber_rect->setCurrentBX(green_rect->getCurrentBX() - redAmberFixed*m_nInterval);
					red_amber_rect->setCurrentEX(red_amber_rect->getCurrentBX()+redAmberFixed*m_nInterval);

					red_line->setCurrentBX(amber_rect->getCurrentEX());
					red_line->setCurrentEX(red_amber_rect->getCurrentBX());

				}
			}

			if (curShap->getShapType()==Amber_Rect)
			{

				if (curShap->isSelected())			//鼠标按下后的动作
				{
					green_rect->setSelected(true);
					red_line->setSelected(true);
					red_amber_rect->setSelected(true);
					flash_green_rect->setSelected(true);

					red_line->setCurrentBX(amber_rect->getCurrentEX());

					flash_green_rect->setCurrentBX(amber_rect->getCurrentBX()-flashGreenFixed*m_nInterval);
					flash_green_rect->setCurrentEX(amber_rect->getCurrentBX());
					red_amber_rect->setCurrentBX(red_line->getCurrentEX());
					red_amber_rect->setCurrentEX(red_amber_rect->getCurrentBX()+redAmberFixed*m_nInterval);
					green_rect->setCurrentEX(flash_green_rect->getCurrentBX());
				}
			}

			if (curShap->getShapType()==Red_Amber_Rect)
			{
				if (curShap->isSelected())			//鼠标按下后的动作
				{
					green_rect->setSelected(true);
					red_line->setSelected(true);
					amber_rect->setSelected(true);
					flash_green_rect->setSelected(true);

					green_rect->setCurrentBX(red_amber_rect->getCurrentEX());
					red_line->setCurrentEX(red_amber_rect->getCurrentBX());

					flash_green_rect->setCurrentBX(green_rect->getCurrentEX());
					flash_green_rect->setCurrentEX(flash_green_rect->getCurrentBX()+flashGreenFixed*m_nInterval);
					amber_rect->setCurrentBX(flash_green_rect->getCurrentEX());
					amber_rect->setCurrentEX(amber_rect->getCurrentBX()+amberFixed*m_nInterval);
				}
			}

			if (curShap->getShapType()==Flash_Green_Rect)
			{
				if (curShap->isSelected())			//鼠标按下后的动作
				{
					green_rect->setSelected(true);
					red_line->setSelected(true);
					amber_rect->setSelected(true);
					red_amber_rect->setSelected(true);

					green_rect->setCurrentEX(flash_green_rect->getCurrentBX());
					red_line->setCurrentBX(flash_green_rect->getCurrentEX()+amberFixed);

					amber_rect->setCurrentBX(flash_green_rect->getCurrentEX());
					amber_rect->setCurrentEX(amber_rect->getCurrentBX()+amberFixed*m_nInterval);

					red_amber_rect->setCurrentBX(red_line->getCurrentEX());
					red_amber_rect->setCurrentEX(red_amber_rect->getCurrentBX()+redAmberFixed*m_nInterval);
				}
			}
		}
		break;
	default:
		break;
	}
	for (int i = 0; i < shapList.size(); i++)
	{
		if (shapList.at(i)!=curShap)
		{
			shapList.at(i)->ChangeXBandE();
		}
	}
}

void TestSignalLights::mouseMoveEvent(QMouseEvent *event)
{

	if(curShap!=NULL)
	{
		curShap->mouseMove(event->x(),event->y());
		//根据当前的序列设置其余的图形的坐标
		synchData();
	}
	update();	//强制刷新界面。
}

void TestSignalLights::updateDataInfo()
{
		for(int i=0; i<curSgDataInProg.cmds.size(); i++)
		{
			switch (curSgDataInProg.cmds[i].nDisplay)
			{
			case Red:
				{
					curSgDataInProg.cmds[i].nBegin = red_line->getBScale();
				}
				break;
			case Red_Amber:
				{
					curSgDataInProg.cmds[i].nBegin = red_amber_rect->getBScale();
				}
				break;
			case Green:
				{
					curSgDataInProg.cmds[i].nBegin = green_rect->getBScale();
				}
				break;
			case Amber:
				{
					curSgDataInProg.cmds[i].nBegin = amber_rect->getBScale();
				}
				break;
			case Flash_Green:
				{
					curSgDataInProg.cmds[i].nBegin = flash_green_rect->getBScale();
				}
				break;
			case Flash_Amber:
				{
					curSgDataInProg.cmds[i].nBegin = flash_amber_rect->getBScale();
				}
				break;
			case OFF:
				{
					curSgDataInProg.cmds[i].nBegin = off_line->getBScale();
				}
				break;
			case Flash_Red:
				{
					curSgDataInProg.cmds[i].nBegin = flash_red_rect->getBScale();
				}
				break;
			default:
				break;
			}
		}

		for (int i=0; i<curSgDataInProg.fixedStates.size(); i++)
		{
			switch (curSgDataInProg.fixedStates[i].nDisplay)
			{
			case Red_Amber:
				{
					curSgDataInProg.fixedStates[i].nDuration = red_amber_rect->getFixedState();
				}
				break;
			case Amber:
				{
					curSgDataInProg.fixedStates[i].nDuration = amber_rect->getFixedState();
				}
				break;
			case Flash_Green:
				{
					curSgDataInProg.fixedStates[i].nDuration = flash_green_rect->getFixedState();
				}
				break;
			case Flash_Amber:
				{
					curSgDataInProg.fixedStates[i].nDuration = flash_amber_rect->getFixedState();
				}
				break;
			case Flash_Red:
				{
					curSgDataInProg.fixedStates[i].nDuration = flash_red_rect->getFixedState();
				}
				break;
			default:
				break;
			}
		}
}

void TestSignalLights::mouseReleaseEvent(QMouseEvent *event)
{
	for (int i=0; i<shapList.size(); i++)
	{
		shapList.at(i)->mouseRelease(event->x(), event->y());
	}
	update();
	updateDataInfo();
	emitPaintChanged(curSquence, m_row);
}

bool insensitiveCMDLessThan(const CmdData &data1, const CmdData &data2) 
{ 
	return data1.nBegin < data2.nBegin; 
}

bool insensitiveFixStatesLessThan(const FixStateData &data1, const FixStateData &data2) 
{ 
	return data1.nDuration < data2.nDuration; 
}

void TestSignalLights::ResetAllShapInfo()
{
	red_line->ReSetInfo();
	off_line->ReSetInfo();
	red_amber_rect->ReSetInfo();
	green_rect->ReSetInfo();
	amber_rect->ReSetInfo();
	flash_green_rect->ReSetInfo();
	flash_amber_rect->ReSetInfo();
	flash_red_rect->ReSetInfo();
}
extern QMap<int ,int >	m_sgColorToDefdur;	
void TestSignalLights::setDefaultCmdAndFixState()
{
	curSgDataInProg.cmds.clear();
	curSgDataInProg.fixedStates.clear();
	switch (curSgDataInProg.nSignalSequence)
	{
	case COLOR_SEQU_ALL_RED:
		{
			CmdData cmdData;
			cmdData.nDisplay = Red;
			cmdData.nBegin = 0;
			curSgDataInProg.cmds.push_back(cmdData);
		}
		break;
	case COLOR_SEQU_ALL_GREEN:
		{
			CmdData cmdData;
			cmdData.nDisplay = Green;
			cmdData.nBegin = 0;
			curSgDataInProg.cmds.push_back(cmdData);
		}
		break;
	case COLOR_SEQU_RED_REDAMBER_GREEN_AMBER:
		{
			CmdData cmdData;
			cmdData.nDisplay = Red;
			cmdData.nBegin = 0;
			curSgDataInProg.cmds.push_back(cmdData);
			cmdData.nDisplay = Green;
			cmdData.nBegin = m_sgColorToDefdur.value(Red_Amber)+3;
			curSgDataInProg.cmds.push_back(cmdData);

			FixStateData fixData;
			fixData.nDisplay = Red_Amber;
			fixData.nDuration = m_sgColorToDefdur.value(Red_Amber);
			curSgDataInProg.fixedStates.push_back(fixData);
			fixData.nDisplay = Amber;
			fixData.nDuration = m_sgColorToDefdur.value(Amber);
			curSgDataInProg.fixedStates.push_back(fixData);
		}
		break;
	case COLOR_SEQU_RED_GREEN:
		{
			CmdData cmdData;
			cmdData.nDisplay = Red;
			cmdData.nBegin = 0;
			curSgDataInProg.cmds.push_back(cmdData);
			cmdData.nDisplay = Green;
			cmdData.nBegin = 3;
			curSgDataInProg.cmds.push_back(cmdData);
		}
		break;
	case COLOR_SEQU_RED_REDAMBER_GREEN_GREENFLASH_AMBER:
		{
			CmdData cmdData;
			cmdData.nDisplay = Red;
			cmdData.nBegin = 0;
			curSgDataInProg.cmds.push_back(cmdData);
			cmdData.nDisplay = Green;
			cmdData.nBegin = m_sgColorToDefdur.value(Red_Amber)+3;
			curSgDataInProg.cmds.push_back(cmdData);

			FixStateData fixData;
			fixData.nDisplay = Red_Amber;
			fixData.nDuration = m_sgColorToDefdur.value(Red_Amber);
			curSgDataInProg.fixedStates.push_back(fixData);
			fixData.nDisplay = Flash_Green;
			fixData.nDuration = m_sgColorToDefdur.value(Flash_Green);
			curSgDataInProg.fixedStates.push_back(fixData);
			fixData.nDisplay = Amber;
			fixData.nDuration = m_sgColorToDefdur.value(Amber);
			curSgDataInProg.fixedStates.push_back(fixData);
		}
		break;
	case COLOR_SEQU_RED_GREEN_GREENFLASH:
		{
			CmdData cmdData;
			cmdData.nDisplay = Red;
			cmdData.nBegin = 0;
			curSgDataInProg.cmds.push_back(cmdData);
			cmdData.nDisplay = Green;
			cmdData.nBegin = 3;
			curSgDataInProg.cmds.push_back(cmdData);

			FixStateData fixData;
			fixData.nDisplay = Flash_Green;
			fixData.nDuration = m_sgColorToDefdur.value(Flash_Green);
			curSgDataInProg.fixedStates.push_back(fixData);
		}
		break;
	case COLOR_SEQU_RED_GREEN_AMBER:
		{
			CmdData cmdData;
			cmdData.nDisplay = Red;
			cmdData.nBegin = 0;
			curSgDataInProg.cmds.push_back(cmdData);
			cmdData.nDisplay = Green;
			cmdData.nBegin =3;
			curSgDataInProg.cmds.push_back(cmdData);

			FixStateData fixData;
			fixData.nDisplay = Amber;
			fixData.nDuration = m_sgColorToDefdur.value(Amber);
			curSgDataInProg.fixedStates.push_back(fixData);
		}
		break;
	case COLOR_SEQU_AMBERFLASH:
		{
			CmdData cmdData;
			cmdData.nDisplay = Flash_Amber;
			cmdData.nBegin = 0;
			curSgDataInProg.cmds.push_back(cmdData);

		}
		break;
	case COLOR_SEQU_OFF:
		{
			CmdData cmdData;
			cmdData.nDisplay = OFF;
			cmdData.nBegin = 0;
			curSgDataInProg.cmds.push_back(cmdData);
		}
		break;
	case COLOR_SEQU_RED_OFF:
		{
			CmdData cmdData;
			cmdData.nDisplay = Red;
			cmdData.nBegin = 0;
			curSgDataInProg.cmds.push_back(cmdData);
			cmdData.nDisplay = OFF;
			cmdData.nBegin = 3;
			curSgDataInProg.cmds.push_back(cmdData);
		}
		break;
	case COLOR_SEQU_RED_OFF_AMBER:
		{
			CmdData cmdData;
			cmdData.nDisplay = Red;
			cmdData.nBegin = 0;
			curSgDataInProg.cmds.push_back(cmdData);
			cmdData.nDisplay = OFF;
			cmdData.nBegin = 3;
			curSgDataInProg.cmds.push_back(cmdData);

			FixStateData fixData;
			fixData.nDisplay = Amber;
			fixData.nDuration = m_sgColorToDefdur.value(Amber);
			curSgDataInProg.fixedStates.push_back(fixData);
		}
		break;
	case COLOR_SEQU_OFF_GREEN:
		{
			CmdData cmdData;
			cmdData.nDisplay = OFF;
			cmdData.nBegin = 0;
			curSgDataInProg.cmds.push_back(cmdData);
			cmdData.nDisplay = Green;
			cmdData.nBegin = 3;
			curSgDataInProg.cmds.push_back(cmdData);
		}
		break;
	case COLOR_SEQU_AMBERFLASH_OFF:
		{
			CmdData cmdData;
			cmdData.nDisplay = OFF;
			cmdData.nBegin = 3;
			curSgDataInProg.cmds.push_back(cmdData);
			cmdData.nDisplay = Flash_Amber;
			cmdData.nBegin = 0;
			curSgDataInProg.cmds.push_back(cmdData);
		}
		break;
	case COLOR_SEQU_RED_GREEN_REDFLASH:
		{
			CmdData cmdData;
			cmdData.nDisplay = Red;
			cmdData.nBegin = 0;
			curSgDataInProg.cmds.push_back(cmdData);
			cmdData.nDisplay = Green;
			cmdData.nBegin = 3;
			curSgDataInProg.cmds.push_back(cmdData);

			FixStateData fixData;
			fixData.nDisplay = Flash_Red;
			fixData.nDuration = m_sgColorToDefdur.value(Flash_Red);
			curSgDataInProg.fixedStates.push_back(fixData);
		}
		break;
	case COLOR_SEQU_REDFLASH_OFF:
		{
			CmdData cmdData;
			cmdData.nDisplay = Flash_Red;
			cmdData.nBegin = 0;
			curSgDataInProg.cmds.push_back(cmdData);
			cmdData.nDisplay = OFF;
			cmdData.nBegin = 3;
			curSgDataInProg.cmds.push_back(cmdData);
		}
		break;
	default:
		break;
	}
}

void TestSignalLights::comboxChanged(int index)
{
	curSgDataInProg.nSignalSequence = index+1;
	setDefaultCmdAndFixState();

	setDefaultSignalSequece(curSgDataInProg);
	update();
}



void TestSignalLights::setDefaultSignalSequece(SgDataInProg sgDataInProg)
{
	curSquence = sgDataInProg.nSignalSequence;
	curSgDataInProg = sgDataInProg;
	qSort(curSgDataInProg.cmds.begin(), curSgDataInProg.cmds.end(),insensitiveCMDLessThan);
	qSort(curSgDataInProg.fixedStates.begin(), curSgDataInProg.fixedStates.end(),insensitiveFixStatesLessThan);
	
	ResetAllShapInfo();
	shapList.clear();
	switch (curSquence)
	{
	case COLOR_SEQU_ALL_RED:		//全红：红线占全部刻度且不能活动
		{
			red_line->setbPainted(true);
			red_line->SetInterval(m_nInterval);
			red_line->setBScale(0);
			red_line->setEScale(m_nCycle);
			red_line->setCanBeChanged(false);
			red_line->setScalePainted(true);
			shapList.append(red_line);
		}
		break;
	case COLOR_SEQU_ALL_GREEN: //全绿
		{
			green_rect->setbPainted(true);
			green_rect->SetInterval(m_nInterval);
			green_rect->setBScale(0);
			green_rect->setEScale(m_nCycle);
			green_rect->setCanBeChanged(false);
			green_rect->setScalePainted(true);
			shapList.append(green_rect);
		}
		break;
	case COLOR_SEQU_OFF:		//全黑
		{
			off_line->setbPainted(true);
			off_line->SetInterval(m_nInterval);
			off_line->setBScale(0);
			off_line->setEScale(m_nCycle);
			off_line->setCanBeChanged(false);
			off_line->setScalePainted(true);
			shapList.append(off_line);
		}
		break;
	case COLOR_SEQU_AMBERFLASH: //黄闪
		{
			flash_amber_rect->setbPainted(true);
			flash_amber_rect->SetInterval(m_nInterval);
			flash_amber_rect->setBScale(0);
			flash_amber_rect->setEScale(m_nCycle);
			flash_amber_rect->setCanBeChanged(false);
			flash_amber_rect->setScalePainted(true);
			shapList.append(flash_amber_rect);
		}
		break;

	case COLOR_SEQU_RED_GREEN:		//红绿
		{
			int redBg = 0, greenBeg=0;
			for (int i=0; i<curSgDataInProg.cmds.size(); i++)
			{
				if (curSgDataInProg.cmds[i].nDisplay==Red)
				{
					redBg = curSgDataInProg.cmds[i].nBegin;
					red_line->setbPainted(true);
					red_line->SetInterval(m_nInterval);
					red_line->setBScale(redBg);
				}else if(curSgDataInProg.cmds[i].nDisplay==Green)
				{
					greenBeg = curSgDataInProg.cmds[i].nBegin;
					green_rect->setbPainted(true);
					green_rect->SetInterval(m_nInterval);
					green_rect->setBScale(greenBeg);
				}
			}
			red_line->setEScale(greenBeg);				//绿色的结束就是红色的开始
			green_rect->setEScale(redBg);				//红色的结束，就是绿色的开始。

			green_rect->setScalePainted(true);
			shapList.append(red_line);
			shapList.append(green_rect);
		}
		break;
	case COLOR_SEQU_RED_OFF:			//红黑
		{
			int redBg = 0, offBeg=0;
			for (int i=0; i<curSgDataInProg.cmds.size(); i++)
			{
				if (curSgDataInProg.cmds[i].nDisplay==Red)
				{
					redBg = curSgDataInProg.cmds[i].nBegin;
					red_line->setbPainted(true);
					red_line->SetInterval(m_nInterval);
					red_line->setBScale(redBg);
				}else if(curSgDataInProg.cmds[i].nDisplay==OFF)
				{
					offBeg = curSgDataInProg.cmds[i].nBegin;
					off_line->setbPainted(true);
					off_line->SetInterval(m_nInterval);
					off_line->setBScale(offBeg);
				}
			}
			red_line->setEScale(offBeg);				//绿色的结束就是红色的开始
			off_line->setEScale(redBg);				//红色的结束，就是绿色的开始。
			red_line->setScalePainted(true);
			shapList.append(red_line);
			shapList.append(off_line);
		}
		break;

	case COLOR_SEQU_OFF_GREEN: 
		{
			int greenBeg = 0, offBeg=0;
			for (int i=0; i<curSgDataInProg.cmds.size(); i++)
			{
				if (curSgDataInProg.cmds[i].nDisplay==Green)
				{
					greenBeg = curSgDataInProg.cmds[i].nBegin;
					green_rect->setbPainted(true);
					green_rect->SetInterval(m_nInterval);
					green_rect->setBScale(greenBeg);
				}else if(curSgDataInProg.cmds[i].nDisplay==OFF)
				{
					offBeg = curSgDataInProg.cmds[i].nBegin;
					off_line->setbPainted(true);
					off_line->SetInterval(m_nInterval);
					off_line->setBScale(offBeg);
				}
			}
			green_rect->setEScale(offBeg);				//绿色的结束就是红色的开始
			off_line->setEScale(greenBeg);				//红色的结束，就是绿色的开始。
			green_rect->setScalePainted(true);
			shapList.append(green_rect);
			shapList.append(off_line);
		}
		break;
	case COLOR_SEQU_AMBERFLASH_OFF:		//黄闪-关灯
		{
			int flasAmbBeg = 0, offBeg=0;
			for (int i=0; i<curSgDataInProg.cmds.size(); i++)
			{
				if (curSgDataInProg.cmds[i].nDisplay==Flash_Amber)
				{
					flasAmbBeg = curSgDataInProg.cmds[i].nBegin;
					flash_amber_rect->setbPainted(true);
					flash_amber_rect->SetInterval(m_nInterval);
					flash_amber_rect->setBScale(flasAmbBeg);
				}else if(curSgDataInProg.cmds[i].nDisplay==OFF)
				{
					offBeg = curSgDataInProg.cmds[i].nBegin;
					off_line->setbPainted(true);
					off_line->SetInterval(m_nInterval);
					off_line->setBScale(offBeg);
				}
			}
			flash_amber_rect->setEScale(offBeg);				//绿色的结束就是红色的开始
			off_line->setEScale(flasAmbBeg);				//红色的结束，就是绿色的开始。
			off_line->setScalePainted(true);
			shapList.append(flash_amber_rect);
			shapList.append(off_line);
		}
		break;
	case COLOR_SEQU_REDFLASH_OFF:			//红闪-关灯
		{
			int flasRedBeg = 0, offBeg=0;
			for (int i=0; i<curSgDataInProg.cmds.size(); i++)
			{
				if (curSgDataInProg.cmds[i].nDisplay==Flash_Red)
				{
					flasRedBeg = curSgDataInProg.cmds[i].nBegin;
					flash_red_rect->setbPainted(true);
					flash_red_rect->SetInterval(m_nInterval);
					flash_red_rect->setBScale(flasRedBeg);
				}else if(curSgDataInProg.cmds[i].nDisplay==OFF)
				{
					offBeg = curSgDataInProg.cmds[i].nBegin;
					off_line->setbPainted(true);
					off_line->SetInterval(m_nInterval);
					off_line->setBScale(offBeg);
				}
			}
			flash_red_rect->setEScale(offBeg);				//绿色的结束就是红色的开始
			off_line->setEScale(flasRedBeg);				//红色的结束，就是绿色的开始。
			off_line->setScalePainted(true);
			shapList.append(flash_red_rect);
			shapList.append(off_line);
		}
		break;
	case COLOR_SEQU_RED_GREEN_GREENFLASH:			//红-绿-绿闪
		{
			int redBeg = 0, greenBeg=0, flashGreenFixed=0;
			for (int i=0; i<curSgDataInProg.fixedStates.size();i++)
			{
				if (curSgDataInProg.fixedStates[i].nDisplay==Flash_Green)
				{
					flashGreenFixed = curSgDataInProg.fixedStates[i].nDuration;
					flash_green_rect->SetInterval(m_nInterval);
					flash_green_rect->setFixedState(flashGreenFixed);
					flash_green_rect->setShapFixed(true);
					flash_green_rect->setbPainted(true);
				}
			}
			for (int i=0; i<curSgDataInProg.cmds.size(); i++)
			{
				if (curSgDataInProg.cmds[i].nDisplay==Red)
				{
					redBeg = curSgDataInProg.cmds[i].nBegin;
					red_line->setbPainted(true);
					red_line->SetInterval(m_nInterval);
					red_line->setBScale(redBeg);
				}else if(curSgDataInProg.cmds[i].nDisplay==Green)
				{
					greenBeg = curSgDataInProg.cmds[i].nBegin;
					green_rect->setbPainted(true);
					green_rect->SetInterval(m_nInterval);
					green_rect->setBScale(greenBeg);
				}
			}
			red_line->setEScale(greenBeg);											//绿色的结束就是红色的开始
			green_rect->setEScale(redBeg-flashGreenFixed);				//红色的结束，就是绿色的开始。
			flash_green_rect->setBScale(redBeg-flashGreenFixed);
			flash_green_rect->setEScale(redBeg);
			green_rect->setScalePainted(true);
			shapList.append(red_line);
			shapList.append(green_rect);
			shapList.append(flash_green_rect);
		}
		break;
	case COLOR_SEQU_RED_GREEN_AMBER:				//红 绿 黄
		{
			int redBeg = 0, greenBeg=0, amberFixed=0;
			for (int i=0; i<curSgDataInProg.fixedStates.size();i++)
			{
				if (curSgDataInProg.fixedStates[i].nDisplay==Amber)
				{
					amberFixed = curSgDataInProg.fixedStates[i].nDuration;
					amber_rect->setbPainted(true);
					amber_rect->SetInterval(m_nInterval);
					amber_rect->setFixedState(amberFixed);
					amber_rect->setShapFixed(true);
				}
			}
			for (int i=0; i<curSgDataInProg.cmds.size(); i++)
			{
				if (curSgDataInProg.cmds[i].nDisplay==Red)
				{
					redBeg = curSgDataInProg.cmds[i].nBegin;
					red_line->setbPainted(true);
					red_line->SetInterval(m_nInterval);
					red_line->setBScale(redBeg);
				}else if(curSgDataInProg.cmds[i].nDisplay==Green)
				{
					greenBeg = curSgDataInProg.cmds[i].nBegin;
					green_rect->setbPainted(true);
					green_rect->SetInterval(m_nInterval);
					green_rect->setBScale(greenBeg);
				}
			}
			red_line->setEScale(greenBeg);											//绿色的结束就是红色的开始
			green_rect->setEScale(redBeg-amberFixed);				//红色的结束，就是绿色的开始。
			amber_rect->setBScale(redBeg-amberFixed);
			amber_rect->setEScale(redBeg);
			green_rect->setScalePainted(true);
			shapList.append(red_line);
			shapList.append(green_rect);
			shapList.append(amber_rect);
		}
		break;
	case COLOR_SEQU_RED_GREEN_REDFLASH:		//红 绿 红闪
		{
			int redBeg = 0, greenBeg=0, flashRedFixed=0;
			for (int i=0; i<curSgDataInProg.fixedStates.size();i++)
			{
				if (curSgDataInProg.fixedStates[i].nDisplay==Flash_Red)
				{
					flashRedFixed = curSgDataInProg.fixedStates[i].nDuration;
					flash_red_rect->SetInterval(m_nInterval);
					flash_red_rect->setFixedState(flashRedFixed);
					flash_red_rect->setShapFixed(true);
					flash_red_rect->setbPainted(true);
				}
			}
			for (int i=0; i<curSgDataInProg.cmds.size(); i++)
			{
				if (curSgDataInProg.cmds[i].nDisplay==Red)
				{
					redBeg = curSgDataInProg.cmds[i].nBegin;
					red_line->setbPainted(true);
					red_line->SetInterval(m_nInterval);
					red_line->setBScale(redBeg);
				}else if(curSgDataInProg.cmds[i].nDisplay==Green)
				{
					greenBeg = curSgDataInProg.cmds[i].nBegin;
					green_rect->setbPainted(true);
					green_rect->SetInterval(m_nInterval);
					green_rect->setBScale(greenBeg);
				}
			}
			red_line->setEScale(greenBeg);											//绿色的结束就是红色的开始
			green_rect->setEScale(redBeg-flashRedFixed);				//红色的结束，就是绿色的开始。
			flash_red_rect->setBScale(redBeg-flashRedFixed);
			flash_red_rect->setEScale(redBeg);
			green_rect->setScalePainted(true);
			shapList.append(red_line);
			shapList.append(green_rect);
			shapList.append(flash_red_rect);
		}
		break;
	case COLOR_SEQU_RED_OFF_AMBER:
		{
			int redBeg = 0, offbeg=0, amberFixed=0;
			for (int i=0; i<curSgDataInProg.fixedStates.size();i++)
			{
				if (curSgDataInProg.fixedStates[i].nDisplay==Amber)
				{
					amberFixed = curSgDataInProg.fixedStates[i].nDuration;
					amber_rect->SetInterval(m_nInterval);
					amber_rect->setFixedState(amberFixed);
					amber_rect->setShapFixed(true);
					amber_rect->setbPainted(true);
				}
			}
			for (int i=0; i<curSgDataInProg.cmds.size(); i++)
			{
				if (curSgDataInProg.cmds[i].nDisplay==Red)
				{
					redBeg = curSgDataInProg.cmds[i].nBegin;
					red_line->setbPainted(true);
					red_line->SetInterval(m_nInterval);
					red_line->setBScale(redBeg);
				}else if(curSgDataInProg.cmds[i].nDisplay==OFF)
				{
					offbeg = curSgDataInProg.cmds[i].nBegin;
					off_line->setbPainted(true);
					off_line->SetInterval(m_nInterval);
					off_line->setBScale(offbeg);
				}
			}
			red_line->setEScale(offbeg);											//绿色的结束就是红色的开始
			off_line->setEScale(redBeg-amberFixed);				//红色的结束，就是绿色的开始。
			amber_rect->setBScale(redBeg-amberFixed);
			amber_rect->setEScale(redBeg);
			//red_line->setScalePainted(true);
			off_line->setScalePainted(true);
			shapList.append(red_line);
			shapList.append(off_line);
			shapList.append(amber_rect);
		}
		break;
	case COLOR_SEQU_RED_REDAMBER_GREEN_AMBER:		//红 红/黄 绿 黄
		{
			int redBeg = 0, greenBeg=0, amberFixed=0, redAmberFixed=0;
			for (int i=0; i<curSgDataInProg.fixedStates.size();i++)
			{
				if (curSgDataInProg.fixedStates[i].nDisplay==Amber)
				{
					amberFixed = curSgDataInProg.fixedStates[i].nDuration;
					amber_rect->SetInterval(m_nInterval);
					amber_rect->setFixedState(amberFixed);
					amber_rect->setShapFixed(true);
					amber_rect->setbPainted(true);
				}else if(curSgDataInProg.fixedStates[i].nDisplay==Red_Amber)
				{
					redAmberFixed = curSgDataInProg.fixedStates[i].nDuration;
					red_amber_rect->SetInterval(m_nInterval);
					red_amber_rect->setFixedState(redAmberFixed);
					red_amber_rect->setShapFixed(true);
					red_amber_rect->setbPainted(true);
				}
			}

			for (int i=0; i<curSgDataInProg.cmds.size(); i++)
			{
				if (curSgDataInProg.cmds[i].nDisplay==Red)
				{
					redBeg = curSgDataInProg.cmds[i].nBegin;
					red_line->setbPainted(true);
					red_line->SetInterval(m_nInterval);
					red_line->setBScale(redBeg);
				}else if(curSgDataInProg.cmds[i].nDisplay==Green)
				{
					greenBeg = curSgDataInProg.cmds[i].nBegin;
					green_rect->setbPainted(true);
					green_rect->SetInterval(m_nInterval);
					green_rect->setBScale(greenBeg);
				}
			}

			red_line->setEScale(green_rect->getBScale()-redAmberFixed);
			red_amber_rect->setBScale(red_line->getEScale());
			red_amber_rect->setEScale(red_amber_rect->getBScale()+redAmberFixed);
			green_rect->setEScale(red_line->getBScale()-amberFixed);
			amber_rect->setBScale(green_rect->getEScale());
			amber_rect->setEScale(amber_rect->getBScale()+amberFixed);
			green_rect->setScalePainted(true);

			shapList.append(red_line);
			shapList.append(red_amber_rect);
			shapList.append(green_rect);
			shapList.append(amber_rect);
		}
		break;
	case COLOR_SEQU_RED_REDAMBER_GREEN_GREENFLASH_AMBER:
		{
			int redBeg = 0, greenBeg=0, amberFixed=0, redAmberFixed=0, flashGreenFixed=0;
			for (int i=0; i<curSgDataInProg.fixedStates.size();i++)
			{
				if (curSgDataInProg.fixedStates[i].nDisplay==Amber)
				{
					amberFixed = curSgDataInProg.fixedStates[i].nDuration;
					amber_rect->SetInterval(m_nInterval);
					amber_rect->setFixedState(amberFixed);
					amber_rect->setShapFixed(true);
					amber_rect->setbPainted(true);
				}else if(curSgDataInProg.fixedStates[i].nDisplay==Red_Amber)
				{
					redAmberFixed = curSgDataInProg.fixedStates[i].nDuration;
					red_amber_rect->SetInterval(m_nInterval);
					red_amber_rect->setFixedState(redAmberFixed);
					red_amber_rect->setShapFixed(true);
					red_amber_rect->setbPainted(true);
				}else if (curSgDataInProg.fixedStates[i].nDisplay==Flash_Green)
				{
					flashGreenFixed = curSgDataInProg.fixedStates[i].nDuration;
					flash_green_rect->SetInterval(m_nInterval);
					flash_green_rect->setFixedState(flashGreenFixed);
					flash_green_rect->setShapFixed(true);
					flash_green_rect->setbPainted(true);
				}
			}

			for (int i=0; i<curSgDataInProg.cmds.size(); i++)
			{
				if (curSgDataInProg.cmds[i].nDisplay==Red)
				{
					redBeg = curSgDataInProg.cmds[i].nBegin;
					red_line->setbPainted(true);
					red_line->SetInterval(m_nInterval);
					red_line->setBScale(redBeg);
				}else if(curSgDataInProg.cmds[i].nDisplay==Green)
				{
					greenBeg = curSgDataInProg.cmds[i].nBegin;
					green_rect->setbPainted(true);
					green_rect->SetInterval(m_nInterval);
					green_rect->setBScale(greenBeg);
				}
			}

			red_line->setEScale(green_rect->getBScale()-redAmberFixed);
			red_amber_rect->setBScale(red_line->getEScale());
			red_amber_rect->setEScale(red_amber_rect->getBScale()+redAmberFixed);
			green_rect->setEScale(red_line->getBScale()-amberFixed-flashGreenFixed);
			flash_green_rect->setBScale(green_rect->getEScale());
			flash_green_rect->setEScale(flash_green_rect->getBScale()+flashGreenFixed);
			amber_rect->setBScale(flash_green_rect->getEScale());
			amber_rect->setEScale(amber_rect->getBScale()+amberFixed);
			green_rect->setScalePainted(true);
			shapList.append(red_line);
			shapList.append(red_amber_rect);
			shapList.append(green_rect);
			shapList.append(flash_green_rect);
			shapList.append(amber_rect);
		}
		break;
	default:
		break;
	}
}

TestSignalLights::~TestSignalLights()
{

}
