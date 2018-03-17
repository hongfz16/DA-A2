#include "mergesort.h"

using namespace std;

void merge(unsigned int* srcarr,int lb,int rb)
{
	int mid=(lb+rb)/2;
	int num=rb-lb+1;
	unsigned int* newarr=new unsigned int[num];
	int j=lb,k=mid+1;
	for(int i=0;i<num;++i)
	{
		if(j==mid+1)
		{
			newarr[i]=srcarr[k];
			++k;
			continue;
		}
		if(k==rb+1)
		{
			newarr[i]=srcarr[j];
			++j;
			continue;
		}
		if(srcarr[j]<srcarr[k])
		{
			newarr[i]=srcarr[j];
			++j;
		}
		else
		{
			newarr[i]=srcarr[k];
			++k;
		}
	}
	for(int i=0;i<num;++i)
	{
		srcarr[i+lb]=newarr[i];
	}
	delete [] newarr;
}

void mergesort(unsigned int* srcarr,int lb,int rb,int stoppoint)
{
	if(rb-lb<=stoppoint)
	{
		for(int i=lb+1;i<=rb;++i)
		{
			unsigned int flag=srcarr[i];
			int j=0;
			for(j=i-1;srcarr[j]>flag && j>=lb;--j)
			{
				srcarr[j+1]=srcarr[j];
			}
			srcarr[j+1]=flag;
		}
		return;
	}
	int mid=(lb+rb)/2;
	mergesort(srcarr,lb,mid,stoppoint);
	mergesort(srcarr,mid+1,rb,stoppoint);
	merge(srcarr,lb,rb);
}