#include "radixsort.h"

using namespace std;

unsigned int getbasedigit(unsigned int x,int hd,int ld)
{
	unsigned int hh=1,ll=1;
	hh=(hh<<hd)-1;
	ll=(ll<<(ld-1))-1;
	unsigned int mask=hh-ll;
	return (x&mask)>>(ld-1);
}

void countingsort(unsigned int* srcarr,int num,int hd,int ld)
{
	int k=1<<(hd-ld+1);
	int* c=new int[k];
	unsigned int* b=new unsigned int[num];
	for(int i=0;i<k;++i)
		c[i]=0;
	for(int i=0;i<num;++i)
	{
		c[getbasedigit(srcarr[i],hd,ld)]++;
	}
	for(int i=1;i<k;++i)
		c[i]+=c[i-1];
	for(int i=num-1;i>=0;--i)
	{
		b[c[getbasedigit(srcarr[i],hd,ld)]-1]=srcarr[i];
		c[getbasedigit(srcarr[i],hd,ld)]--;
	}
	for(int i=0;i<num;++i)
		srcarr[i]=b[i];
	delete[] b;
	delete[] c;
}

void radixsort(unsigned int* srcarr,int num,int r)
{
	int lowb=1;
	int highb=r;
	while(lowb!=33)
	{
		if(highb>32)
			highb=32;
		countingsort(srcarr,num,highb,lowb);
		lowb=highb+1;
		highb=lowb+r-1;
	}
}