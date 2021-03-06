#include "LIS.h"

using namespace std;

int bisearch(vector<int>& arr,int low,int high,int k)
{
	while(low<=high)
	{
		if(arr[high]<k)
			return high+1;
		if(arr[low]>k)
			return low;
		int mid=(high+low)/2;
		if(arr[mid]==k)
			return -1;
		if(arr[mid]>k)
			high=mid;
		else if(arr[mid]<k)
			low=mid+1;
	}
	return -1;
}

int getLISLen(vector<int>& arr,vector<int>& dp,vector<int>& index)
{
	vector<int> dpindex;
	vector<int> dppre;
	dppre.resize(arr.size(),0);
	dpindex.resize(arr.size()+2,0);
	if(arr.size()==0)
		return 0;
	dp.resize(arr.size()+2,0);
	dp[1]=arr[0];
	index.push_back(0);
	int len=1;
	for(size_t i=1;i<arr.size();++i)
	{
		int temp=bisearch(dp,1,len,arr[i]);
		if(temp==-1)
			continue;
		else
		{
			dp[temp]=arr[i];
			dpindex[temp]=i;
			dppre[i]=dpindex[temp-1];
			if(temp==len+1)
			{
				++len;
				//index.clear();
				// for(int i=0;i<len-1;++i)
				// {
				// 	index[i]=dpindex[i+1];
				// }
				dppre[i]=dpindex[temp-1];
			}
		}
	}
	index.resize(len,0);
	int count=dpindex[len];
	index[len-1]=count;
	for(int i=len-2;i>=0;--i)
	{
		index[i]=dppre[count];
		count=dppre[count];
	}
	return len;
}

int naiveGetLIS(vector<int>& arr)
{
	vector<int> dpLength(arr.size(),1);
	dpLength[0]=1;
	for(int i=1;i<arr.size();++i)
	{
		int j=i-1;
		int maxl=dpLength[j];
		for(j=0;j<i;++j)
		{
			if(arr[j]<arr[i] && dpLength[j]+1>dpLength[i])
			{
				dpLength[i]=dpLength[j]+1;
			}
		}
	}
	int maxre=-1;
	for(int i=0;i<arr.size();++i)
		if(dpLength[i]>maxre)
			maxre=dpLength[i];

	return maxre;
}