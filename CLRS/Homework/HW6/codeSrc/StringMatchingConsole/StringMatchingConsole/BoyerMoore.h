#ifndef _BOYERMOORE_H_
#define _BOYERMOORE_H_

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;


int BMFindFirst(string& pattern, string& text);
vector<int> BMFindAll(string& pattern, string& text);

#endif //_BOYERMOORE_H_