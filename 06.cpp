#include <iostream>
#include <assert.h>
using namespace std;

int GetSquareSum(int n)
{
	assert(n > 0);
	int sum = 0;
	for(int i = 1 ; i <= n ; i ++)
		sum += i * i;
	return sum;
}

int GetSumSquare(int n)
{
	assert(n > 0);
	int sum = 0;
	for(int i = 1 ; i <= n ; i ++)
		sum += i;
	return sum * sum;
}

int main()
{
	int n = 100;
	cout<<GetSumSquare(n) - GetSquareSum(n)<<endl;
	return 0;
}
