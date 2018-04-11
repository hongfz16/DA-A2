#include<iostream>
#include<string>
#include<vector>
#include<ctime>

#include"Naive.h"
#include"KMP.h"
#include"BoyerMoore.h"

using namespace std;

void TestNaiveFindFirst(string& pattern, string& text);
void TestNaiveFindAll(string& pattern, string& text);
void TestKMPFindFirst(string& pattern, string& text);
void TestKMPFindAll(string& pattern, string& text);
void TestBMFindFirst(string& pattern, string& text);
void TestBMFindAll(string& pattern, string& text);
string GenerateString(int num);

#define _NOT_SHOW_ANS_

int main()
{
	srand((unsigned)time(nullptr));
	string pattern;
	string text;
	int type = 0;
	cout << "Please choose the running model:" << endl << "0: Auto Test" << endl << "1: Input String" << endl;
	cin >> type;
	if (type == 0)
	{
		vector<pair<int, int> > tests;
		tests.push_back(pair<int, int>(1, 1000000));
		tests.push_back(pair<int, int>(10, 1000000));
		tests.push_back(pair<int, int>(100, 1000000));
		tests.push_back(pair<int, int>(1000, 1000000));
		tests.push_back(pair<int, int>(10000, 1000000));
		tests.push_back(pair<int, int>(100000, 1000000));
		tests.push_back(pair<int, int>(1, 10000000));
		tests.push_back(pair<int, int>(10, 10000000));
		tests.push_back(pair<int, int>(100, 10000000));
		tests.push_back(pair<int, int>(1000, 10000000));
		tests.push_back(pair<int, int>(10000, 10000000));
		tests.push_back(pair<int, int>(100000, 10000000));
		tests.push_back(pair<int, int>(1000000, 10000000));
		tests.push_back(pair<int, int>(1, 100000000));
		tests.push_back(pair<int, int>(10, 100000000));
		tests.push_back(pair<int, int>(100, 100000000));
		tests.push_back(pair<int, int>(1000, 100000000));
		tests.push_back(pair<int, int>(10000, 100000000));
		tests.push_back(pair<int, int>(100000, 100000000));
		tests.push_back(pair<int, int>(1000000, 100000000));
		tests.push_back(pair<int, int>(10000000, 100000000));
		for (const auto& test : tests)
		{
			cout << "Pattern Size: " << test.first << endl << "Text Size: " << test.second << endl;
			pattern = GenerateString(test.first);
			text = GenerateString(test.second);
			//TestNaiveFindFirst(pattern, text);
			TestNaiveFindAll(pattern, text);
			//TestKMPFindFirst(pattern, text);
			TestKMPFindAll(pattern, text);
			//TestBMFindFirst(pattern, text);
			TestBMFindAll(pattern, text);
		}
	}
	else
	{
		while (pattern.empty())
		{
			cout << "Please Input the Pattern String:" << endl;
			cin >> pattern;
		}
		while (text.empty())
		{
			cout << "Please Input the Text String: " << endl;
			cin >> text;
		}
		TestNaiveFindFirst(pattern, text);
		TestNaiveFindAll(pattern, text);
		TestKMPFindFirst(pattern, text);
		TestKMPFindAll(pattern, text);
		TestBMFindFirst(pattern, text);
		TestBMFindAll(pattern, text);
	}

	system("pause");

	return 0;
}

void TestNaiveFindFirst(string& pattern, string& text)
{
	clock_t s = clock();
	int ans = NaiveFindFirst(pattern, text);
	cout << "Naive Find First Time: " << clock() - s << endl;
#ifndef _NOT_SHOW_ANS_
	cout << "Test Naive Find First Ans: " << ans << endl;
#endif
	cout << "==========" << endl;
}

void TestNaiveFindAll(string& pattern, string& text)
{
	clock_t s = clock();
	vector<int> Ans = NaiveFindAll(pattern, text);
	cout << "Naive Find All Time: " << clock() - s << endl;
#ifndef _NOT_SHOW_ANS_
	cout << "Test Naive Find All Ans: ";
	for (const int& ans : Ans)
	{
		cout << ans << " ";
	}
	cout << endl;
#endif
	cout << "==========" << endl;
}

void TestKMPFindFirst(string& pattern, string& text)
{
	clock_t s = clock();
	int ans = KMPFindFirst(pattern, text);
	cout << "KMP Find First Time: " << clock() - s << endl;
#ifndef _NOT_SHOW_ANS_
	cout << "Test KMP Find First: " << ans << endl;
#endif
	cout << "==========" << endl;
}

void TestKMPFindAll(string& pattern, string& text)
{
	clock_t s = clock();
	vector<int> Ans = KMPFindAll(pattern, text);
	cout << "KMP Find All Time: " << clock() - s << endl;
#ifndef _NOT_SHOW_ANS_
	cout << "Test KMP Find All: ";
	for (const int& ans : Ans)
	{
		cout << ans << " ";
	}
	cout << endl;
#endif
	cout << "==========" << endl;
}

void TestBMFindFirst(string& pattern, string& text)
{
	clock_t s = clock();
	int ans = BMFindFirst(pattern, text);
	cout << "BM Find First Time: " << clock() - s << endl;
#ifndef _NOT_SHOW_ANS_
	cout << "Test BM Find First: " << ans << endl;
#endif
	cout << "==========" << endl;
}

void TestBMFindAll(string& pattern, string& text)
{
	clock_t s = clock();
	vector<int> Ans = BMFindAll(pattern, text);
	cout << "BM Find All Time: " << clock() - s << endl;
#ifndef _NOT_SHOW_ANS_
	cout << "Test BM Find All: ";
	for (const int& ans : Ans)
	{
		cout << ans << " ";
	}
	cout << endl;
#endif
	cout << "==========" << endl;
}

string GenerateString(int num)
{
	string re;
	for (int i = 0; i < num; ++i)
	{
		re += characters[rand() % characters.size()];
	}
	return re;
}
