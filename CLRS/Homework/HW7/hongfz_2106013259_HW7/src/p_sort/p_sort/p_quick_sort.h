#ifndef _PQUICKSORT_H_
#define _PQUICKSORT_H_

#include<iostream>
#include<omp.h>

using namespace std;

extern int PV;

inline void exchange(unsigned int* ll, unsigned int* rr)
{
	int temp = *ll;
	*ll = *rr;
	*rr = temp;
}

inline int partition(unsigned int* srcarr, int lb, int rb)
{
	unsigned int x = srcarr[rb];
	int i = lb - 1;
	for (int j = lb; j<rb; ++j)
	{
		if (srcarr[j] <= x)
		{
			++i;
			exchange(&srcarr[i], &srcarr[j]);
		}
	}
	exchange(&srcarr[i + 1], &srcarr[rb]);
	return i + 1;
}

void pquicksort(unsigned int* srcarr, int lb, int rb,unsigned int* B, int s)
{
	if (rb - lb <= 50)
	{
		for (int i = lb + 1; i <= rb; ++i)
		{
			unsigned int flag = srcarr[i];
			int j = 0;
			for (j = i - 1; srcarr[j]>flag && j >= lb; --j)
			{
				srcarr[j + 1] = srcarr[j];
			}
			srcarr[j + 1] = flag;
		}
		return;
	}
	int mid = partition(srcarr, lb, rb);

	//if (PV >= 2)
	//{
	//	PV -= 2;
#pragma omp parallel sections
		{
#pragma omp section
			pquicksort(srcarr, lb, mid - 1, B, s);
#pragma omp section
			pquicksort(srcarr, mid + 1, rb, B, s);
		}
	//	PV += 2;
	//}
	//else
	//{
	//	pquicksort(srcarr, lb, mid - 1, B, s);
	//	pquicksort(srcarr, mid + 1, rb, B, s);
	//}
}

#endif