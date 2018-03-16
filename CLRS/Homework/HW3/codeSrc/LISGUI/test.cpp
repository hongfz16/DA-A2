#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "LIS.h"

using namespace std;

void printvec(vector<int>& a,int ll,int yy)
{
	for(int i=ll;i<yy;++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void test(int num)
{
	vector<int> arr;
	for(size_t i=0;i<num;++i)
	{
		arr.push_back(rand()%50);
	}
	vector<int> dp;
	int len=getLISLen(arr,dp);
	vector<int> index;
	getLISIndex(arr,dp,index,len);
	// cout<<len<<endl;

	// printvec(arr,0,arr.size());
	// printvec(dp,1,len+1);
	// printvec(index,1,len+1);

	int co=naiveGetLIS(arr);
//	cout<<co<<endl;

	if(co==len)
		cout<<"Correct!"<<endl;
	else
		cout<<"Wrong!"<<endl;
}

int main()
{
	srand((unsigned)time(nullptr));
	test(10000);
	return 0;
}