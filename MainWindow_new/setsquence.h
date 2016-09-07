#ifndef SETSQUENCE_H
#define SETSQUENCE_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include "common.h"
#include "ProjectListWidget.h"
class SetSquence : public QDialog
{
	Q_OBJECT

public:
	SetSquence(QVector<SgData>&datas, QString &squence, QWidget *parent=0);
	~SetSquence();

	public slots:
		void ChangeLineEdit(bool, int);
		void accept();

private:
	QVector<SgData> &m_sgDatas;

	ProjectListWidget *listWid;
	QString &m_squence;
};

#endif // SETSQUENCE_H
