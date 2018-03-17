#include "TShortestPair.h"
#include <ctime>

#define RANGE 10000000

Point GetRandomPoint()
{
	Point rep;
	rep.first=rand()%RANGE;
	rep.second=rand()%RANGE;
	return rep;
}

void test(int POINTNUM)
{
	mCanvas mc;
	for(int i=0;i<POINTNUM;++i)
		mc.AddPoint(GetRandomPoint());

	mc.init();

	clock_t begin=clock();
	mPair minpair=mc.GetShortestPair(0,POINTNUM-1);
	clock_t end=clock();
	//cout<<"$"<<(end-begin)/1000.0<<"$ & ";
	cout<<"D&C Time: "<<(end-begin)/1000.0<<"ms"<<endl;
	cout<<"D&C Ans: "<<minpair.dist<<endl;
	pair<Point,Point> ps=minpair.ps;
	cout<<"("<<ps.first.first<<","<<ps.first.second<<"), "<<"("<<ps.second.first<<","<<ps.second.second<<")"<<endl;
	if(POINTNUM!=1000000)
	{
		begin=clock();
		mPair naiveminpair=NaiveShortestPair(mc.points);
		end=clock();
		//cout<<"$"<<(end-begin)/1000.0<<"$\\\\"<<endl;
		cout<<"Naive Time: "<<(end-begin)/1000.0<<"ms"<<endl;
		cout<<"Naive Ans: "<<naiveminpair.dist<<endl;
		ps=naiveminpair.ps;
		cout<<"("<<ps.first.first<<","<<ps.first.second<<"), "<<"("<<ps.second.first<<","<<ps.second.second<<")"<<endl;
	}
}

int main()
{
	srand((unsigned)time(nullptr));
	int size=10;
	for(int i=0;i<6;++i,size*=10)
	{
		cout<<"Current Size: "<<size<<endl;
		//cout<<"$"<<size<<"$ & ";
		test(size);
		cout<<"------------------"<<endl;
	}
	//test(1000);
	return 0;
}