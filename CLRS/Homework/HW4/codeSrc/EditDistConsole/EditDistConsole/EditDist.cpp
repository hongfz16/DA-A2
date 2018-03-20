#include "EditDist.h"

void EditDist(string x, string y, int m, int n, int ** costtable, int ** op,int* cost)
{
	for (int i = 0; i < m; ++i)
	{
		costtable[i][0] = i*cost[DELETE];
		op[i][0] = DELETE;
	}
	for (int i = 0; i < n; ++i)
	{
		costtable[0][i] = i*cost[INSERT];
		op[0][i] = INSERT;
	}
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			costtable[i][j] = MAX;
			if (x[i] == y[j])
			{
				costtable[i][j] = costtable[i - 1][j - 1] + cost[COPY];
				op[i][j] = COPY;
			}
			if (x[i] != y[j] && costtable[i - 1][j - 1] + cost[REPLACE] < costtable[i][j])
			{
				costtable[i][j] = costtable[i - 1][j - 1] + cost[REPLACE];
				op[i][j] = REPLACE;
			}
			if (i >= 2 && j >= 2 && x[i] == y[j - 1] && x[i - 1] == y[j] && costtable[i - 2][j - 2] + cost[TWIDDLE] < costtable[i][j])
			{
				costtable[i][j] = costtable[i - 2][j - 2] + cost[TWIDDLE];
				op[i][j] = TWIDDLE;
			}
			if (costtable[i - 1][j] + cost[DELETE] < costtable[i][j])
			{
				costtable[i][j] = costtable[i - 1][j] + cost[DELETE];
				op[i][j] = DELETE;
			}
			if (costtable[i][j - 1] + cost[INSERT] < costtable[i][j])
			{
				costtable[i][j] = costtable[i][j - 1] + cost[INSERT];
				op[i][j] = INSERT;
			}
		}
	}
	for (int i = 0; i < m - 1; ++i)
	{
		if (costtable[i][n - 1] + cost[KILL] < costtable[m - 1][n - 1])
		{
			costtable[m - 1][n - 1] = costtable[i][n - 1] + cost[KILL];
			op[m - 1][n - 1] = KILL + i;
		}
	}
}
