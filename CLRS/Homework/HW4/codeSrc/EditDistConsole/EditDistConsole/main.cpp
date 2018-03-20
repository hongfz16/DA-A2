#include <iostream>
#include "EditDist.h"

using namespace std;

int main()
{
	string x("algorithm");
	string y("altruistic");
	int cost[6] = { 1,2,3,4,5,4 };
	int** costtable = new int*[x.length()];
	int** op = new int*[x.length()];
	for (int i = 0; i < x.length(); ++i)
	{
		costtable[i] = new int[y.length()];
		op[i] = new int[y.length()];
	}
	EditDist(x, y, x.length(), y.length(), costtable, op, cost);

	for (int i = 0; i < x.length(); ++i)
	{
		for (int j = 0; j < y.length(); ++j)
		{
			cout << costtable[i][j] << " ";
		}
		cout << endl;
	}
	
	for (int i = 0; i < x.length(); ++i)
	{
		for (int j = 0; j < y.length(); ++j)
		{
			cout << op[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}