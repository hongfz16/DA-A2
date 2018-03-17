#include "insertionsort.h"

using namespace std;

void insertionsort(unsigned int* srcarr,int num)
{
	for(int i=1;i<num;++i)
	{
		unsigned int flag=srcarr[i];
		int j=0;
		for(j=i-1;j>=0;--j)
		{
			if(srcarr[j]>flag)
			{
				srcarr[j+1]=srcarr[j];
			}
			else
			{
				//srcarr[j+1]=flag;
				break;
			}
		}
		srcarr[j+1]=flag;
	}
}