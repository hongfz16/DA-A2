#include "quicksort.h"

using namespace std;

inline void exchange(unsigned int* ll,unsigned int* rr)
{
	int temp=*ll;
	*ll=*rr;
	*rr=temp;
}

inline int partition(unsigned int* srcarr,int lb,int rb)
{
	unsigned int x=srcarr[rb];
	int i=lb-1;
	for(int j=lb;j<rb;++j)
	{
		if(srcarr[j]<=x)
		{
			++i;
			exchange(&srcarr[i],&srcarr[j]);
		}
	}
	exchange(&srcarr[i+1],&srcarr[rb]);
	return i+1;
}

void quicksort(unsigned int* srcarr,int lb,int rb,int stoppoint)
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
	int mid=partition(srcarr,lb,rb);
	quicksort(srcarr,lb,mid-1,stoppoint);
	quicksort(srcarr,mid+1,rb,stoppoint);
}