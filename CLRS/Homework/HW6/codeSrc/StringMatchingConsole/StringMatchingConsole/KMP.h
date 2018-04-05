#ifndef _KMP_H_
#define _KMP_H_

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int KMPFindFirst(string& pattern, string& text);
vector<int> KMPFindAll(string& pattern, string& text);

#endif //_KMP_H_
