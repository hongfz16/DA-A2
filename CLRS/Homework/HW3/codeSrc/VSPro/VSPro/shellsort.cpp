#include "shellsort.h"

using namespace std;

int getshelldelta(int** delta,int n)
{
	(*delta) = new int[32];
	(*delta)[0] = n / 3;
	int count = 1;
	for (int i = 1; (*delta)[i-1] > 1; ++i)
	{
		(*delta)[i] = (*delta)[i - 1] / 2.2;
		count++;
	}
	if((*delta)[count-1]==0)
	{
		(*delta)[count - 1] = 1;
	}
	return count;
}

void shellinsert(unsigned int* srcarr,int num,int d)
{
	for(int i=d;i<num;++i)
	{
		unsigned int flag=srcarr[i];
		int j=0;
		for(j=i-d;j>=0 && srcarr[j]>flag;j-=d)
		{
			srcarr[j+d]=srcarr[j];
		}
		srcarr[j+d]=flag;
	}
}

void shellsort(unsigned int* srcarr,int num,int* delta,int deltanum)
{
	for(int i=0;i<deltanum;++i)
	{
		shellinsert(srcarr,num,delta[i]);
	}
}
