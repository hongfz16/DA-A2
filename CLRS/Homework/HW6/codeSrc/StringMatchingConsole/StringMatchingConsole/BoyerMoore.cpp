#include "BoyerMoore.h"

string characters("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890`~!@#$%^&*()\"\'\\[]{};:,.<>/?");

int max(int le, int ri)
{
	if (le < ri)
		return ri;
	else
		return le;
}

unordered_map<char,int> getBMBC(string& pattern)
{
	unordered_map<char, int> re;
	int m = pattern.length() - 1;
	for (const char& c : characters)
	{
		re.insert(pair<char, int>(c, m));
	}
	for (int i = 1; i < m; ++i)
	{
		re[pattern[i]] = m - i;
	}
	return re;
}

vector<int> getOSUFF(string& pattern)
{
	int m = pattern.length() - 1;
	vector<int> OSUFF;
	OSUFF.resize(m + 1, 0);
	for (int i = 1; i <= m; ++i)
	{
		int count = 0;
		for (int j = i; j >= 1; --j)
		{
			if (pattern[j] == pattern[m - (i - j)])
				++count;
			else
				break;
		}
		OSUFF[i] = count;
	}
	return OSUFF;
}

vector<int> getBMGS(string& pattern)
{
	int m = pattern.length() - 1;
	vector<int> OSUFF = getOSUFF(pattern);
	vector<int> bmGS;
	bmGS.resize(m + 1, m);
	int j = 1;
	for (int i = m - 1; i >= 1; --i)
	{
		if(OSUFF[i]==i)
		while (j <= m - i)
		{
			if (bmGS[j] == m)
				bmGS[j] = m - i;
			++j;
		}
	}
	for (int i = 1; i <= m - 1; ++i)
	{
		bmGS[m - OSUFF[i]] = m - i;
	}
	return bmGS;
}

int BMFindFirst(string & pattern, string & text)
{
	string npattern = string(" ") + pattern;
	string ntext = string(" ") + text;
	int n = text.length();
	int m = pattern.length();
	unordered_map<char, int> bmBC = getBMBC(npattern);
	vector<int> bmGS = getBMGS(npattern);
	int s = 0;
	while (s <= n - m)
	{
		int i = m;
		while (npattern[i] == ntext[s + i])
		{
			if (i == 1)
				return s;
			else
				--i;
		}
		s += max(bmGS[i], bmBC[ntext[s + i]] - m + i);
	}
	return -1;
}

vector<int> BMFindAll(string & pattern, string & text)
{
	vector<int> ans;
	string npattern = string(" ") + pattern;
	string ntext = string(" ") + text;
	int n = text.length();
	int m = pattern.length();
	unordered_map<char, int> bmBC = getBMBC(npattern);
	vector<int> bmGS = getBMGS(npattern);
	int s = 0;
	while (s <= n - m)
	{
		int i = m;
		while (npattern[i] == ntext[s + i])
		{
			if (i == 1)
			{
				ans.push_back(s);
				break;
			}
			else
				--i;
		}
		s += max(bmGS[i], bmBC[ntext[s + i]] - m + i);
	}
	return ans;
}
