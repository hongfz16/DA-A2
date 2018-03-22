#ifndef _EDITDIST_H_
#define _EDITDIST_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX 10000000

enum options
{
	COPY=0,
	REPLACE,
	DELETE,
	INSERT,
	TWIDDLE,
	KILL
};

void EditDist(string x, string y, int m, int n, int** costtable, int** op,int* cost);

vector<int> Construct(int** op, int m, int n);

vector<pair<string, string> > ShowProc(string x, string y, vector<int> ops);



#endif //_EDITDIST_H_