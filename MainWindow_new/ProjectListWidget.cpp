#include "ProjectListWidget.h"
#include "QApplication"
#include "QMimeData"
#include "QDrag"
#include <QDebug>
#include <QPainter>
ProjectListWidget::ProjectListWidget(QWidget *parent):QListWidget(parent)
{
	setAcceptDrops(true);
	setMovement(QListView::Free);
	setDragEnabled(true);
}

void ProjectListWidget::mousePressEvent(QMouseEvent *event)
{
	qDebug()<<"mousePressEvent";
	if (event->button() == Qt::LeftButton)
	{
		startPos = event->pos();
	}
	QListWidget::mousePressEvent(event);
}

void ProjectListWidget::mouseMoveEvent(QMouseEvent *event)
{
	qDebug()<<"mouseMoveEvent";
	if (event->buttons() & Qt::LeftButton)
	{
		int distance = (event->pos() - startPos).manhattanLength();
		if(distance >= QApplication::startDragDistance())  //拖拽起作用的最小距离
		{
			performDrag();
		}
	}

	QListWidget::mouseMoveEvent(event);
}

void ProjectListWidget::performDrag()
{
	qDebug()<<"performDrag";
	QListWidgetItem * item = currentItem();
	if (item)
	{
		QMimeData *mimeData = new QMimeData;
		mimeData->setText(item->text());

		QDrag *drag = new QDrag(this);
		drag->setMimeData(mimeData);
		//drag->setPixmap(QPixmap(":/images/person"));
		if (drag->exec(Qt::MoveAction) == Qt::MoveAction)
		{
			int i = row(item);
			delete item;
		}
	}
}

void ProjectListWidget::dragEnterEvent(QDragEnterEvent *event)
{
	qDebug()<<"dragEnterEvent";
	if (event->mimeData()->hasFormat("text/plain"))		
	{
		event->acceptProposedAction();
		event->accept();
	}
}

void ProjectListWidget::dragMoveEvent(QDragMoveEvent *event)
{
	qDebug()<<"dragMoveEvent";
	ProjectListWidget *source = qobject_cast<ProjectListWidget *>(event->source());

	if (source && source ==this)
	{
		QListWidgetItem *item = itemAt(event->pos());
		setCurrentItem(item);
		event->setDropAction(Qt::MoveAction);
		event->accept();
	}
}

void ProjectListWidget::dropEvent(QDropEvent *event)
{
	qDebug()<<"dropEvent";
	ProjectListWidget *source =
		qobject_cast<ProjectListWidget *>(event->source());
	if (source && source == this) {
		QListWidgetItem *item = itemAt(event->pos());
		if(item)
		{
			int rownum = row(item);
			insertItem(row(item), event->mimeData()->text());
			qDebug()<<"insert :"<<rownum;
		}else
		{
			addItem(event->mimeData()->text());
		}
		event->setDropAction(Qt::MoveAction);
		event->accept();
	}
}

ProjectListWidget::~ProjectListWidget(void)
{
}
