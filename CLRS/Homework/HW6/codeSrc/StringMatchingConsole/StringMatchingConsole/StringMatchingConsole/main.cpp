#include<iostream>
#include<string>
#include<vector>

#include"Naive.h"
#include"KMP.h"

using namespace std;

void TestNaiveFindFirst(string& pattern, string& text)
{
	int ans = NaiveFindFirst(pattern, text);
	cout << "Test Naive Find First Ans: " << ans << endl;
	cout << "==========" << endl;
}

void TestNaiveFindAll(string& pattern, string& text)
{
	vector<int> Ans = NaiveFindAll(pattern, text);
	cout << "Test Naive Find All Ans: ";
	for (const int& ans : Ans)
	{
		cout << ans << " ";
	}
	cout << endl << "==========" << endl;
}

void TestKMPFindFirst(string& pattern, string& text)
{
	int ans = KMPFindFirst(pattern, text);
	cout << "Test KMP Find First: " << ans << endl;
	cout << "==========" << endl;
}

void TestKMPFindAll(string& pattern, string& text)
{
	vector<int> Ans = KMPFindAll(pattern, text);
	cout << "Test KMP Find All: ";
	for (const int& ans : Ans)
	{
		cout << ans << " ";
	}
	cout << endl << "==========" << endl;
}

int main()
{
	string pattern = "ab";
	string text = "abaiafahlaksdfjsdjncdbkasbabfabbasdbfajsfkbasfjbsfjdjkbatga";
	TestNaiveFindFirst(pattern, text);
	TestNaiveFindAll(pattern, text);
	TestKMPFindFirst(pattern, text);
	TestKMPFindAll(pattern, text);
	return 0;
}