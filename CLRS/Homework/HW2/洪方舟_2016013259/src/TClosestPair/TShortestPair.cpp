#include "TShortestPair.h"

bool cmpy(const Point& lp,const Point& rp)
{
	return lp.second<rp.second;
}

bool cmpx(const Point& lp,const Point& rp)
{
	return lp.first<rp.first;
}

double Dist(Point& lp,Point& rp)
{
	return sqrt(pow(lp.first-rp.first,2)+pow(lp.second-rp.second,2));
}

void mCanvas::init()
{
	//SortPointsByY();
	SortPointsByX();
}

void mCanvas::AddPoint(Point p)
{
	points.push_back(p);
	//pointsY.push_back(p);
}

void mCanvas::SortPointsByY()
{
	sort(pointsY.begin(),pointsY.end(),cmpy);
}

void mCanvas::SortPointsByX()
{
	sort(points.begin(),points.end(),cmpx);
}

mPair mCanvas::GetShortestPair(int lb,int rb)
{
	if(rb-lb<=100)
	{
		sort(points.begin()+lb,points.begin()+rb+1,cmpy);
		vector<Point> svp;
		for(int i=lb;i<=rb;++i)
		{
			svp.push_back(points[i]);
		}
		return NaiveShortestPair(svp);
	}
	int mid=(lb+rb)/2;
	mPair lp=GetShortestPair(lb,mid);
	mPair rp=GetShortestPair(mid+1,rb);
	mPair minpair;
	double d=(lp.dist<rp.dist)?lp.dist:rp.dist;
	minpair.dist=d;
	minpair.ps=(lp.dist<rp.dist)?lp.ps:rp.ps;
	vector<Point> inside;
	int ii=lb,jj=mid+1;
	for(int i=0;i<rb-lb+1;++i)
	{
		if(ii==mid+1)
		{
			inside.push_back(points[jj]);
			++jj;
			continue;
		}
		if(jj==rb+1)
		{
			inside.push_back(points[ii]);
			++ii;
			continue;
		}
		if(points[ii].second<points[jj].second)
		{
			inside.push_back(points[ii]);
			++ii;
		}
		else
		{
			inside.push_back(points[jj]);
			++jj;
		}
	}
	for(int i=lb;i<=rb;++i)
	{
		points[i]=inside[i-lb];
	}
	// for(int i=lb;i<=rb;++i)
	// {
	// 	inside.push_back(points[i]);
	// }
	// sort(inside.begin(),inside.end(),cmpy);
	// int lbx=points[lb].first;
	// int rbx=points[rb].first;
	// for(int i=0;i<pointsY.size();++i)
	// {
	// 	if(pointsY[i].first<=rbx && pointsY[i].first>=lbx)
	// 	{
	// 		inside.push_back(pointsY[i]);
	// 	}
	// }
	for(int i=0;i<inside.size();++i)
	{
		for(int j=i+1;j<inside.size() && j<i+8;++j)
		{
			double curdist=Dist(inside[i],inside[j]);
			if(curdist<minpair.dist)
			{
				minpair.dist=curdist;
				minpair.ps.first=inside[i];
				minpair.ps.second=inside[j];
			}
		}
	}
	return minpair;

	// if(lb>=rb)
	// {
	// 	mPair rep;
	// 	rep.dist=MAX;
	// 	return rep;
	// }
	// if(rb-lb<=9000)
	// {
	// 	vector<Point> svp;
	// 	for(int i=0;i<points.size();++i)
	// 	{
	// 		if(points[i].first>=lb && points[i].first<=rb)
	// 			svp.push_back(points[i]);
	// 	}
	// 	return NaiveShortestPair(svp);
	// }
	// int mid=(lb+rb)/2;
	// mPair lp=GetShortestPair(lb,mid);
	// mPair rp=GetShortestPair(mid+1,rb);
	// mPair minpair;
	// double d=(lp.dist<rp.dist)?lp.dist:rp.dist;
	// minpair.dist=d;
	// minpair.ps=(lp.dist<rp.dist)?lp.ps:rp.ps;
	// vector<Point> inside;
	// for(int i=0;i<points.size();++i)
	// 	if(abs(points[i].first-mid)<=d)
	// 		inside.push_back(points[i]);
	// for(int i=0;i<inside.size();++i)
	// {
	// 	for(int j=i+1;j<inside.size() && j<i+8;++j)
	// 	{
	// 		double curdist=Dist(inside[i],inside[j]);
	// 		if(curdist<minpair.dist)
	// 		{
	// 			minpair.dist=curdist;
	// 			minpair.ps.first=inside[i];
	// 			minpair.ps.second=inside[j];
	// 		}
	// 	}
	// }
	// return minpair;
}

mPair NaiveShortestPair(vector<Point>& points)
{
	mPair minpair;
	minpair.dist=1e20;
	for(int i=0;i<points.size();++i)
	{
		for(int j=i+1;j<points.size();++j)
		{
			double curdist=Dist(points[i],points[j]);
			if(curdist<minpair.dist)
			{
				minpair.dist=curdist;
				minpair.ps.first=points[i];
				minpair.ps.second=points[j];
			}
		}
	}
	return minpair;
}