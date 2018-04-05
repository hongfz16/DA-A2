#include "Naive.h"

int NaiveFindFirst(string & pattern, string & text)
{
	int m = 0, n = 0;
	int patternlen = pattern.length();
	int textlen = text.length();
	int firstplace = 0;
	while (n <= textlen - patternlen)
	{
		if (pattern[m] == text[n])
		{
			++m; ++n;
		}
		else
		{
			++firstplace;
			m = 0;
			n = firstplace;
		}
		if (m == patternlen)
			break;
	}
	if (m == patternlen)
		return firstplace;
	else
		return -1;
}

vector<int> NaiveFindAll(string & pattern, string & text)
{
	vector<int> places;
	int m = 0, n = 0;
	int patternlen = pattern.length();
	int textlen = text.length();
	int currentplace = 0;
	while (n <= textlen - patternlen)
	{
		if (pattern[m] == text[n])
		{
			++m; ++n;
		}
		else
		{
			++currentplace;
			m = 0;
			n = currentplace;
		}
		if (m == patternlen)
		{
			places.push_back(currentplace);
			++currentplace;
			m = 0;
			n = currentplace;
		}
	}
	return places;
}
