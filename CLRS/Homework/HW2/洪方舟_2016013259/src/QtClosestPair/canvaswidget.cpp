#include "canvaswidget.h"

CanvasWidget::CanvasWidget(QWidget *parent) : QWidget(parent)
{
	setFixedSize(600,600);
	size=500;
	allow_click=false;
}

void CanvasWidget::AddRandPoints(int num)
{
	srand((unsigned)time(nullptr));
	for(int i=0;i<num;++i)
	{
		Point temp;
		temp.first=rand()%size;
		temp.second=rand()%size;
		mc.points.push_back(temp);
	}
}

double CanvasWidget::GetClosestPair()
{
	if(allow_click)
		return -1.0;
	if(mc.points.size()<2)
		return -1.0;
	mc.init();
	mPair re=mc.GetShortestPair(0,mc.points.size()-1);
	line.clear();
	line.push_back(re.ps);
	update();
	return re.dist;
}

double CanvasWidget::NaiveGetClosestPair()
{
	if(allow_click)
		return -1.0;
	if(mc.points.size()<2)
		return -1.0;
	mPair re=NaiveShortestPair(mc.points);
	line.clear();
	line.push_back(re.ps);
	update();
	return re.dist;
}

void CanvasWidget::CancelClicked()
{
	line.clear();
	update();
}

void CanvasWidget::ClearClicked()
{
	line.clear();
	mc.points.clear();
	update();
}

void CanvasWidget::StartClicked()
{
	allow_click=true;
}

void CanvasWidget::EndClicked()
{
	allow_click=false;
}

void CanvasWidget::GeneratePointsClicked(int num)
{
	AddRandPoints(num);
	update();
}

void CanvasWidget::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	QPen PointPen(Qt::red);
	QPen LinePen(Qt::green);
	QPen TextPen(Qt::black);
	LinePen.setWidth(2);
	PointPen.setWidth(5);
	TextPen.setWidth(2);
	painter.setPen(PointPen);
	for(size_t i=0;i<mc.points.size();++i)
	{
		QPoint temp;
		temp.setX(mc.points[i].first);
		temp.setY(mc.points[i].second);
		painter.drawPoint(temp);
	}
	painter.setPen(LinePen);
	for(size_t i=0;i<line.size();++i)
	{
		QPoint temp1,temp2;
		temp1.setX(line[i].first.first);
		temp1.setY(line[i].first.second);
		temp2.setX(line[i].second.first);
		temp2.setY(line[i].second.second);
		painter.drawLine(temp1,temp2);
		painter.setFont(QFont("Arial", 15));
		painter.setPen(TextPen);
		int temp1cx,temp1cy,temp2cx,temp2cy;
		temp1cx=line[i].first.first;
		temp1cy=line[i].first.second;
		temp2cx=line[i].second.first;
		temp2cy=line[i].second.second;
		if(line[i].first.second>line[i].second.second)
		{
			temp1cy+=16;
		}
		else
		{
			temp2cy+=16;
		}
		double dist=sqrt(pow(temp1.rx()-temp2.rx(),2)+pow(temp1.ry()-temp2.ry(),2));
		painter.drawText(rect(),Qt::AlignLeft,QString("Closest Distance: ")+QString::number(dist));
		painter.drawText(temp1cx,temp1cy,QString("(")+QString::number(temp1.rx(),10)+QString(",")+QString::number(temp1.ry(),10)+QString(")"));
		painter.drawText(temp2cx,temp2cy,QString("(")+QString::number(temp2.rx(),10)+QString(",")+QString::number(temp2.ry(),10)+QString(")"));
	}
}

void CanvasWidget::mousePressEvent(QMouseEvent *e)
{
	if(!allow_click)
		return;
	int cx=e->x();
	int cy=e->y();
	if(cx>=0 && cx<size && cy>=0 && cy<size)
	{
		mc.AddPoint(Point(cx,cy));
		update();
	}
}
