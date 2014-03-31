#include <iostream>
#include <assert.h>
using namespace std;

typedef int Type;

inline Type GetNextNum(Type num)
{
	if(num % 2) return num * 3 + 1;
	else        return num / 2;
}

int GetChainLength(Type num, Type Max, int *cache)
{
	assert(num >= 1);
	//already computed
	if(cache[num] != -1) return cache[num];
	
	//exit case
	if(num == 1) return 1;

	//Normal Procedure
	int NextNum = GetNextNum(num);
	int Length = GetChainLength(NextNum, Max, cache);
	if(NextNum < Max) cache[NextNum] = Length;
	return Length + 1;
}

int GetLongestChain(Type Max)
{
	assert(Max >= 1);

	//Initial
	int *cache = new int[Max];
	for(int i = 0 ; i < Max ; i ++) cache[i] = -1;
	int MaxLength = -1, CurrentLength;
	Type MaxStartNum = -1;

	//Main Function
	for(int i = 1 ; i <= Max ; i ++)
	{
		CurrentLength = GetChainLength(i, Max, cache);
		if(CurrentLength > MaxLength)
		{
			MaxLength = CurrentLength;
			MaxStartNum = i;
		}
	}

	for(Type i = 1 ; i < Max ; i ++)
		cout<<cache[i]<<endl;

	//clear
	delete[] cache;
	return MaxStartNum;
}

int main()
{
	int num = 10;
	cout<<GetLongestChain(num)<<endl;
	return 0;
}
