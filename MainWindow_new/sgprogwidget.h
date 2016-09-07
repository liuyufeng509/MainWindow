#ifndef SGPROGWIDGET_H
#define SGPROGWIDGET_H

#include <QWidget>
#include "common.h"
#include <QTreeWidgetItem>
#include "ui_sgprogwidget.h"
#include "mycombox.h"
#include "SignalPaintWidget/testsignallights.h"
enum ColumNo
{
	SgNo=0,
	SgName,
	SgType,			//相位类型
	ISCoorSg,		//是否协调相位
	MINGreen,
	MAXGreen1,
	MAXGreen2,
	ExtendGreen,
	SgSequence,
	PicSet,
	Red1_End,
	RedFlash1_End,
	Green1_End,
	Red2_End,
	RedFlash2_End,
	Green2_End,
	RedAmber,
	AmBer_Column,
	RedFlash_Column,
};
class SgProgWidget : public QWidget
{
	Q_OBJECT

public:
	SgProgWidget(QVector<SgData>  &sgsDatas, QVector<InterGreenMatrixData> &interGreenMatrixs, QVector<SquenceData> &squenceDatas,QWidget *parent = 0);
	~SgProgWidget();

	void setData(const SignalProgData &data);
	void setLightsData(int row, bool isNew = false);
	void updateDataToUI();
	void saveDataFromeUI();
public slots:
		void currentIndexChangedSlot(int index, int row);
		void sgTypeOrCoordChanged(int index, int row);
		void cellChangedSlot(int row, int column, int, int);
		void	paintChangedSlot(int, int);
		void cycleChangedSlot(int);
		void foucsChanged(QWidget*old, QWidget*now);		//当窗口内的焦点发生变化时
signals:
		void sgProgDataChanged(SignalProgData data);
private:
	Ui::SgProgWidget ui;

	SignalProgData m_data;			//数据
	QVector<SgData>  &m_sgsDatas;		//所有灯组的数据。
	QVector<InterGreenMatrixData> &m_interGreenMatrixs;
	QVector<SquenceData> &m_squenceDatas;
};

#endif // SGPROGWIDGET_H
