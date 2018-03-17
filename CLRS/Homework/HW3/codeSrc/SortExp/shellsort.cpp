#include "shellsort.h"

using namespace std;

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
