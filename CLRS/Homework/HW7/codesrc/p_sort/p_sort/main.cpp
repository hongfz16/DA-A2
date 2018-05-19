#include<iostream>
#include<cstdio>
#include<ctime>
#include"p_merge_sort.h"
#include"p_quick_sort.h"

using namespace std;

#define MAXNUM 100000000

int PV;

unsigned int UInt32Rand()
{
	unsigned int rdhigh = (static_cast<unsigned int>(rand()) << 1) + rand() % 2;
	unsigned int rdlow = (static_cast<unsigned int>(rand()) << 1) + rand() % 2;
	return (rdhigh << 16) + rdlow;
}

unsigned int* generatearray(int n)
{
	unsigned int* arr = new unsigned int[n + 1];
//#pragma omp parallel for
	for (int i = 0; i <= n; ++i)
	{
		int temp = UInt32Rand();
		arr[i] = temp;
	}
	//arr[0] = n;
	return arr;
}

inline bool checkright(unsigned int* arr, int n)
{
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] <= arr[i + 1])
			continue;
		return false;
	}
	return true;
}

void printarr(unsigned int* arr, int n)
{
	for (int i = 1; i <= n; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

clock_t testsort(void(*sort)(unsigned int*A, int p, int r, unsigned int* B, int s), int n, int flag)
{
	unsigned int* A = generatearray(n);
	unsigned int* B = new unsigned int[n + 1];
	clock_t cc = clock();
	(*sort)(A, 1, n, B, 1);
	clock_t recc = clock() - cc;
	if (flag == 0 && !checkright(B, n))
		return -1;
	if (flag == 1 && !checkright(A, n))
		return -1;
	delete[] A;
	delete[] B;
	return recc;
}

int main()
{

	//PV = 4;
	srand((unsigned)time(NULL));
	
	int num = 1;
	for (int i = 0; i < 9; ++i)
	{
		num *= 10;
		cout << "pmergesort: 10^" << i + 1 << " " << testsort(&pmergesort, num, 0) << endl;
		cout << "pquicksort: 10^" << i + 1 << " " << testsort(&pquicksort, num, 1) << endl;
	}
	return 0;
}
