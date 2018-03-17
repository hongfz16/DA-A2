#ifndef _TSHORTESTPAIR_H_
#define _TSHORTESTPAIR_H_

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> Point;

typedef struct
{
	pair<Point,Point> ps;
	double dist;
} mPair;

mPair NaiveShortestPair(vector<Point>& points);

class mCanvas
{
public:
	mCanvas(){}
	~mCanvas(){}

	void init();
	void AddPoint(Point p);
	mPair GetShortestPair(int lb,int rb);
	vector<Point> points;
	vector<Point> pointsY;

private:
	void SortPointsByY();
	void SortPointsByX();
	const double MAX=1e20;
	int sizex;
	int sizey;
};

#endif