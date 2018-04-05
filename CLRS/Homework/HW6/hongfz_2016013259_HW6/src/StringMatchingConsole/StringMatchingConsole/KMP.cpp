#include "KMP.h"

vector<int> GetPrefixFunc(string& pattern)
{
	vector<int> pi;
	int m = pattern.length();
	pi.resize(m);
	pi[0] = -1;
	int k = -1;
	for (int i = 1; i < m; ++i)
	{
		while (k > -1 && pattern[k + 1] != pattern[i])
			k = pi[k];
		if (pattern[k + 1] == pattern[i])
			++k;
		pi[i] = k;
	}
	return pi;
}

int KMPFindFirst(string & pattern, string & text)
{
	int n = text.length();
	int m = pattern.length();
	vector<int> pi = GetPrefixFunc(pattern);
	int q = -1;
	for (int i = 0; i < n; ++i)
	{
		while (q > -1 && pattern[q + 1] != text[i])
			q = pi[q];
		if (pattern[q + 1] == text[i])
			++q;
		if (q == m - 1)
			return i - m + 1;
	}
	return -1;
}

vector<int> KMPFindAll(string & pattern, string & text)
{
	int n = text.length();
	int m = pattern.length();
	vector<int> pi = GetPrefixFunc(pattern);
	int q = -1;
	vector<int> re;
	for (int i = 0; i < n; ++i)
	{
		while (q > -1 && pattern[q + 1] != text[i])
			q = pi[q];
		if (pattern[q + 1] == text[i])
			++q;
		if (q == m - 1)
		{
			re.push_back(i - m + 1);
			q = pi[q];
		}
	}
	return re;
}
