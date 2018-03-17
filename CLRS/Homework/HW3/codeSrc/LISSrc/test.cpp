#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "LIS.h"

using namespace std;

bool increase(vector<int>& arr,vector<int>& index)
{
	for(int i=0;i<index.size()-1;++i)
	{
		if(arr[index[i]]>arr[index[i+1]])
			return false;
	}
	return true;
}

void printvec(vector<int>& a,int ll,int yy)
{
	for(int i=ll;i<yy;++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

bool test(int num)
{
	vector<int> arr;
	arr.resize(num,0);
	for(size_t i=0;i<num;++i)
	{
	 	arr[i]=rand()%100;
	 	while(arr[i]==0)
	 		arr[i]=rand()%100;
	}
	vector<int> dp,index;
	int len=getLISLen(arr,dp,index);
	// cout<<len<<endl;

	// printvec(arr,0,arr.size());
	// printvec(dp,1,len+1);

	int co=naiveGetLIS(arr);

	// for(int i=0;i<index.size();++i)
	// {
	// 	cout<<arr[index[i]]<<" ";
	// }
	// cout<<endl;

	if(co==len && len==index.size() && increase(arr,index))
	{
		cout<<"Correct!"<<endl;
		return true;
	}
	else
	{
		cout<<"Wrong!"<<endl;
		return false;
	}
}

int main()
{
	srand((unsigned)time(nullptr));
	for(int i=0;i<1000;++i)
	{
		if(!test(1000))
			break;
	}
	return 0;
}