#ifndef _LIS_H_
#define _LIS_H_

#include <iostream>
#include <vector>

using namespace std;

int bisearch(vector<int>& arr,int low,int high,int k);
int getLISLen(vector<int>& arr,vector<int>& dp,vector<int>& index);
int naiveGetLIS(vector<int>& arr);

#endif //_LIS_H_