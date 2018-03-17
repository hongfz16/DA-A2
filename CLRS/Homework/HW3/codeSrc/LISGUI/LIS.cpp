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

int getLISLen(vector<int>& arr,vector<int>& dp)
{
	if(arr.size()==0)
		return 0;
	dp.resize(arr.size()+2,0);
	dp[1]=arr[0];
	int len=1;
	for(size_t i=1;i<arr.size();++i)
	{
		int temp=bisearch(dp,1,len,arr[i]);
		if(temp==-1)
			continue;
		else
		{
			dp[temp]=arr[i];
			if(temp==len+1)
				++len;
		}
	}
	return len;
}

void getLISIndex(vector<int>& arr,vector<int>& dp,vector<int>& indexarr,int len)
{
    indexarr.resize(len+1,0);
    vector<int> index;
    index.resize(len+2,0);
	index[len+1]=2147483647;
	for(int i=arr.size()-1;i>=0;--i)
	{
		if(len==0)
			break;
		if(arr[i]>=dp[len] && arr[i]<index[len+1])
		{
			index[len]=arr[i];
            indexarr[len]=i;
			--len;
		}
	}
}

int naiveGetLIS(vector<int>& arr)
{
	vector<int> dpLength(arr.size(),1);
	dpLength[0]=1;
	for(int i=1;i<arr.size();++i)
	{
        int j=i-1;
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
