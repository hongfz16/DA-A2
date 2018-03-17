#include "hdrs.h"

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
	cout<<name<<" Sort: "<<time<<" ms"<<endl;
	cout<<"-----"<<endl;
}

int main()
{
	cout << RAND_MAX << endl;
	return 0;
	srand((unsigned)time(nullptr));
	int num=10;
	clock_t time;
	for(int i=0;i<9;++i,num*=10)
	{
		//time=insertionsorttest(num);
		//printtime("Insertion",time);
		time=mergesorttest(num,50);
		printtime("Merge",time);
		time=quicksorttest(num,50);
		printtime("Quick",time);
		//time=shellsorttest(num);
		//printtime("Shell",time);
		time=radixsorttest(num,8);
		printtime("Radix",time);
		cout<<"==============="<<endl;
	}
	return 0;
}