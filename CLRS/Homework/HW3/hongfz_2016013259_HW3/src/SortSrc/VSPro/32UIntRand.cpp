#include "32UIntRand.h"

using namespace std;

unsigned int UInt32Rand()
{
	unsigned int rdhigh=(static_cast<unsigned int>(rand())<<1)+rand()%2;
	unsigned int rdlow = (static_cast<unsigned int>(rand())<<1)+rand()%2;
	return (rdhigh << 16) + rdlow;
}