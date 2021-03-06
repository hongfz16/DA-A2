#include <iostream>
#include "EditDist.h"

using namespace std;

int main()
{
	string x(" algorithm");
	string y(" altruistic");
	int cost[6] = { 1,2,3,4,2,4 };
	int** costtable = new int*[x.length()];
	int** op = new int*[x.length()];
	for (int i = 0; i < x.length(); ++i)
	{
		costtable[i] = new int[y.length()];
		op[i] = new int[y.length()];
	}
	EditDist(x, y, x.length(), y.length(), costtable, op, cost);

	vector<int> consops = Construct(op, x.length(), y.length());
	for (int i = 0; i < consops.size(); ++i)
	{
		cout << consops[i] << " ";
	}
	cout << endl << endl;

	vector<pair<string, string> > proc = ShowProc(x, y, consops);
	for (int i = 0; i < proc.size(); ++i)
	{
		cout << proc[i].first << "\t" << proc[i].second << endl;
	}
	cout << endl;

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