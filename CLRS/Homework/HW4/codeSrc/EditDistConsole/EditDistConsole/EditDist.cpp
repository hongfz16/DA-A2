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

vector<int> Construct(int ** op, int m, int n)
{
	vector<int> reops;
	int i = m - 1;
	int j = n - 1;
	while (i != 0 && j != 0)
	{
		reops.insert(reops.begin(), op[i][j]);
		if (op[i][j] == COPY || op[i][j] == REPLACE)
		{
			--i;
			--j;
		}
		else if (op[i][j] == DELETE)
		{
			--i;
		}
		else if (op[i][j] == INSERT)
		{
			--j;
		}
		else if (op[i][j] == TWIDDLE)
		{
			i -= 2;
			j -= 2;
		}
		else if (op[i][j] >= KILL)
		{
			i = op[i][j] - KILL;
			reops[0] = KILL;
		}
	}
	return reops;
}

vector<pair<string, string> > ShowProc(string x, string y, vector<int> ops)
{
	vector<pair<string, string> > re;
	string partx;
	string party;
	int m = 1, n = 1;
	for (int i = 0; i < ops.size(); ++i)
	{
		if (ops[i] == COPY || ops[i] == REPLACE)
		{
			partx += x[m];
			party += y[n];
			++m; ++n;
		}
		else if (ops[i] == INSERT)
		{
			party += y[n];
			++n;
		}
		else if (ops[i] == DELETE)
		{
			partx += x[m];
			++m;
		}
		else if (ops[i] == TWIDDLE)
		{
			partx += x[m];
			partx += x[m + 1];
			party += y[n];
			party += y[n + 1];
			m += 2;
			n += 2;
		}
		else if (ops[i] == KILL)
		{
			partx = x.substr(1,x.length());
			party = y.substr(1,y.length());
		}
		re.push_back(pair<string, string>(partx, party));
	}
	return re;
}
