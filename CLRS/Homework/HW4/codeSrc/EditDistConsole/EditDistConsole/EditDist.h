#ifndef _EDITDIST_H_
#define _EDITDIST_H_

#include <iostream>
#include <string>

using namespace std;

#define MAX 10000000

enum options
{
	COPY=0 ,
	REPLACE,
	DELETE,
	INSERT,
	TWIDDLE,
	KILL
};

void EditDist(string x, string y, int m, int n, int** costtable, int** op,int* cost);



#endif //_EDITDIST_H_