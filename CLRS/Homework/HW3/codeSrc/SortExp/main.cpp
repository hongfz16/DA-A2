#include "hdrs.h"

#include "algorithm"
#include "vector"

using namespace std;

bool check(unsigned int* arr,int num)
{
	for(int i=0;i<num-1;++i)
	{
		if(arr[i]>arr[i+1])
			return false;
	}
	return true;
}

unsigned int* generateArr(int num)
{
	unsigned int* arr=new unsigned int[num];
	for(int i=0;i<num;++i)
	{
		arr[i]=UInt32Rand();
	}
	return arr;
}

void print(unsigned int* arr,int num)
{
	for(int i=0;i<num;++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

clock_t insertionsorttest(int num)
{
	unsigned int* arr=generateArr(num);
	clock_t start=clock();
	insertionsort(arr,num);
	clock_t end=clock();
	if(check(arr,num))
		cout<<"Insertion Sort Correct! Array Size: "<<num<<endl;
	else
		cout<<"Insertion Sort Wrong! Array Size: "<<num<<endl;
	delete [] arr;
	return end-start;
}

clock_t mergesorttest(int num,int stoppoint)
{
	unsigned int* arr=generateArr(num);
	clock_t start=clock();
	mergesort(arr,0,num-1,stoppoint);
	clock_t end=clock();
	if(check(arr,num))
		cout<<"Merge Sort Correct! Array Size: "<<num<<endl;
	else
		cout<<"Merge Sort Wrong! Array Size: "<<num<<endl;
	delete [] arr;
	return end-start;
}

clock_t quicksorttest(int num,int stoppoint)
{
	unsigned int* arr=generateArr(num);
	clock_t start=clock();
	quicksort(arr,0,num-1,stoppoint);
	clock_t end=clock();
	if(check(arr,num))
		cout<<"Quick Sort Correct! Array Size: "<<num<<endl;
	else
		cout<<"Quick Sort Wrong! Array Size: "<<num<<endl;
	delete [] arr;
	return end-start;
}

clock_t shellsorttest(int num)
{
	unsigned int* arr=generateArr(num);
	int delta[4]={10,5,3,1};
	clock_t start=clock();
	shellsort(arr,num,delta,4);
	clock_t end=clock();
	if(check(arr,num))
		cout<<"Shell Sort Correct! Array Size: "<<num<<endl;
	else
		cout<<"Shell Sort Wrong! Array Size: "<<num<<endl;
	delete [] arr;
	return end-start;
}

clock_t radixsorttest(int num,int r)
{
	unsigned int* arr=generateArr(num);
	clock_t start=clock();
	radixsort(arr,num,r);
	clock_t end=clock();
	if(check(arr,num))
		cout<<"Radix Sort Correct! Array Size: "<<num<<endl;
	else
		cout<<"Radix Sort Wrong! Array Size: "<<num<<endl;
	delete [] arr;
	return end-start;
}

void printtime(string name,clock_t time)
{
	cout<<name<<" Sort: "<<time/1000.0<<" ms"<<endl;
	cout<<"-----"<<endl;
}

int main()
{
	srand((unsigned)time(NULL));
	int num=10;
	clock_t time;
	for(int i=0;i<10;++i)
	{
		time=radixsorttest(num,8);
		printtime("Radix",time);
		time=quicksorttest(num,50);
		printtime("Quick",time);
		time=mergesorttest(num,50);
		printtime("Merge",time);
		if(i<=5)
		{
			time=shellsorttest(num);
			printtime("Shell",time);
		}
		if(i<=4)
		{
			time=insertionsorttest(num);
			printtime("Insertion",time);
		}
		cout<<"==============="<<endl;
		if(num==100000000)
			num*=2;
		else if(num==200000000)
			num*=5;
		else
			num*=10;
	}
	// int size=1000000000;
	// int* testarr=new int[size];
	// for(int i=0;i<size;++i)
	// {
	// 	testarr[i]=rand();
	// }
	// clock_t time=clock();
	// sort(testarr,testarr+size);
	// cout<<(clock()-time)/1000<<endl;
	return 0;
}

// Merge Sort Correct! Array Size: 10
// Merge Sort: 0 ms
// -----
// Quick Sort Correct! Array Size: 10
// Quick Sort: 0 ms
// -----
// Radix Sort Correct! Array Size: 10
// Radix Sort: 0 ms
// -----
// ===============
// Merge Sort Correct! Array Size: 100
// Merge Sort: 0 ms
// -----
// Quick Sort Correct! Array Size: 100
// Quick Sort: 0 ms
// -----
// Radix Sort Correct! Array Size: 100
// Radix Sort: 0 ms
// -----
// ===============
// Merge Sort Correct! Array Size: 1000
// Merge Sort: 0 ms
// -----
// Quick Sort Correct! Array Size: 1000
// Quick Sort: 0 ms
// -----
// Radix Sort Correct! Array Size: 1000
// Radix Sort: 0 ms
// -----
// ===============
// Merge Sort Correct! Array Size: 10000
// Merge Sort: 2 ms
// -----
// Quick Sort Correct! Array Size: 10000
// Quick Sort: 1 ms
// -----
// Radix Sort Correct! Array Size: 10000
// Radix Sort: 2 ms
// -----
// ===============
// Merge Sort Correct! Array Size: 100000
// Merge Sort: 27 ms
// -----
// Quick Sort Correct! Array Size: 100000
// Quick Sort: 19 ms
// -----
// Radix Sort Correct! Array Size: 100000
// Radix Sort: 14 ms
// -----
// ===============
// Merge Sort Correct! Array Size: 1000000
// Merge Sort: 261 ms
// -----
// Quick Sort Correct! Array Size: 1000000
// Quick Sort: 236 ms
// -----
// Radix Sort Correct! Array Size: 1000000
// Radix Sort: 138 ms
// -----
// ===============
// Merge Sort Correct! Array Size: 10000000
// Merge Sort: 3130 ms
// -----
// Quick Sort Correct! Array Size: 10000000
// Quick Sort: 2682 ms
// -----
// Radix Sort Correct! Array Size: 10000000
// Radix Sort: 1260 ms
// -----
// ===============
// Merge Sort Correct! Array Size: 100000000
// Merge Sort: 37055 ms
// -----
// Quick Sort Correct! Array Size: 100000000
// Quick Sort: 31168 ms
// -----
// Radix Sort Correct! Array Size: 100000000
// Radix Sort: 13359 ms
// -----
// ===============
// Merge Sort Correct! Array Size: 1000000000
// Merge Sort: 473326 ms
// -----
// Quick Sort Correct! Array Size: 1000000000
// Quick Sort: 382163 ms
// -----
// ^C
