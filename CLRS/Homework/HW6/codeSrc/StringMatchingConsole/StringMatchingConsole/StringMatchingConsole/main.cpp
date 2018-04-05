#include<iostream>
#include<string>
#include<vector>

#include"Naive.h"

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

int main()
{
	string pattern = "ab";
	string text = "abaiabatga";
	TestNaiveFindFirst(pattern, text);
	TestNaiveFindAll(pattern, text);
	return 0;
}