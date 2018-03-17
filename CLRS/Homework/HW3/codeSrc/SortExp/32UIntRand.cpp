#include "32UIntRand.h"

using namespace std;

unsigned int UInt32Rand()
{
	unsigned int rd=static_cast<unsigned int>(rand());
	int flag=rand()%2;
	if(flag==0)
		return (rd<<1);
	else
		return (rd<<1)+1;
	//return static_cast<unsigned int >(rand()%100);
}