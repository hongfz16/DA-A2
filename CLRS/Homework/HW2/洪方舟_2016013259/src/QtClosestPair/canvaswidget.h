#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include "TShortestPair.h"
#include <ctime>
#include <vector>
#include <cmath>

class CanvasWidget : public QWidget
{
	Q_OBJECT
public:
	explicit CanvasWidget(QWidget *parent = nullptr);
	void AddRandPoints(int num);

private:
	vector<pair<Point,Point> > line;
	bool allow_click;

public:
	mCanvas mc;
	int size;
signals:

public slots:
	double GetClosestPair();
	double NaiveGetClosestPair();
	void CancelClicked();
	void ClearClicked();
	void StartClicked();
	void EndClicked();
	void GeneratePointsClicked(int num);

protected:
	void paintEvent(QPaintEvent *e);
	void mousePressEvent(QMouseEvent *e);
};

#endif // CANVASWIDGET_H
