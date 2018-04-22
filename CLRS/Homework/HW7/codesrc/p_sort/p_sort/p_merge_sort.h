#ifndef _PMERGESORT_H_
#define _PMERGESORT_H_

#include<iostream>
#include<omp.h>

using namespace std;

inline int max(int l, int r)
{
	if (l < r) return r;
	return l;
}

inline void mexchange(int* lp, int* rp)
{
	int temp = *lp;
	*lp = *rp;
	*rp = temp;
}

inline void lmexchange(unsigned int* lp, unsigned int* rp)
{
	unsigned int temp = *lp;
	*lp = *rp;
	*rp = temp;
}

inline unsigned int bisearch(int x, unsigned int* T, int p, int r)
{
	int low = p, high = max(p, r + 1);
	while (low < high)
	{
		int mid = (low + high) / 2;
		if (x < T[mid])
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}
	return high;
}

void pmerge(unsigned int* T, int p1, int r1, int p2, int r2, unsigned int* A, int p3)
{
	int n1 = r1 - p1 + 1;
	int n2 = r2 - p2 + 1;
	if (n1 < n2)
	{
		mexchange(&p1, &p2);
		mexchange(&r1, &r2);
		mexchange(&n1, &n2);
	}
	if (n1 == 0)
		return;
	int q1 = (p1 + r1) / 2;
	int q2 = bisearch(T[q1], T, p2, r2);
	int q3 = p3 + q1 - p1 + q2 - p2;
	A[q3] = T[q1];
	int arg2[2], arg3[2], arg4[2], arg5[2], arg7[2];
	arg2[0] = p1;
	arg2[1] = q1 + 1;
	arg3[0] = q1 - 1;
	arg3[1] = r1;
	arg4[0] = p2;
	arg4[1] = q2;
	arg5[0] = q2 - 1;
	arg5[1] = r2;
	arg7[0] = p3;
	arg7[1] = q3 + 1;
#pragma omp parallel shared(T,A)
#pragma omp for
	for (int i = 0; i < 2; ++i)
	{
		pmerge(T, arg2[i], arg3[i], arg4[i], arg5[i], A, arg7[i]);
		//cout << "From thread" << omp_get_thread_num() << endl;
	}
//#pragma omp parallel sections
//	{
//#pragma omp section
//		pmerge(T, arg2[0], arg3[0], arg4[0], arg5[0], A, arg7[0]);
//#pragma omp section
//		pmerge(T, arg2[1], arg3[1], arg4[1], arg5[1], A, arg7[1]);
//	}
}

void pmergesort(unsigned int* A, int p, int r, unsigned int* B, int s)
{
	int n = r - p + 1;
	if (n <= 100)
	{
		for (int i = p; i <= r; ++i)
		{
			B[s + i - p] = A[i];
		}
		for (int i = s + 1; i <= n + s - 1; ++i)
		{
			for (int j = i; j > s; --j)
			{
				if (B[j] < B[j - 1])
					lmexchange(&B[j], &B[j - 1]);
			}
		}
		return;
	}
	if (n == 1)
	{
		B[s] = A[p];
		return;
	}
	unsigned int* T = new unsigned int[n + 1];
#pragma omp parallel for
	for (int i = 0; i <= n; ++i)
	{
		T[i] = 0;
	}
	int q = (p + r) / 2;
	int q1 = q - p + 1;
	int arg2[2], arg3[2], arg5[2];
	arg2[0] = p;
	arg2[1] = q + 1;
	arg3[0] = q;
	arg3[1] = r;
	arg5[0] = 1;
	arg5[1] = q1 + 1;
#pragma omp parallel shared(A,T)
#pragma omp for
	for (int i = 0; i < 2; ++i)
	{
		pmergesort(A, arg2[i], arg3[i], T, arg5[i]);
		//cout << "From thread " << omp_get_thread_num() << endl;
	}
//#pragma omp parallel sections
//	{
//#pragma omp section
//		pmergesort(A, arg2[0], arg3[0], T, arg5[0]);
//#pragma omp section
//		pmergesort(A, arg2[1], arg3[1], T, arg5[1]);
//	}
	pmerge(T, 1, q1, q1 + 1, n, B, s);
	delete[] T;
}

#endif