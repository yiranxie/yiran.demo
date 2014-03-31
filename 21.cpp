#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <assert.h>
using namespace std;

int GetSumOfDivisors(int num)
{
	assert (num > 0);
	int sum = 0;
	for (int i = 1 ; i < num ; i ++)
	{
		if (num % i == 0)	sum += i;
	}
	return sum;
}

int GetAllDivisors(int num)
{
	assert (num > 1);
	int *cache = new int[num];
	for (int i = 1 ; i < num ; i ++)
	{
		cache[i] = GetSumOfDivisors(i);
	}
	int sum = 0;
	for (int i = 1 ; i < num ; i ++)
	{
		if (cache[i] > i && cache[i] < num && cache[cache[i]] == i)
			sum += i + cache[i];
	}
	delete[] cache;
	return sum;
}

int main()
{
	int num = 10000;
	cout<<GetAllDivisors(num)<<endl;

	return 0;
}