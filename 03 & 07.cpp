#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <assert.h>
using namespace std;

bool isPrime(long long n)
{
	for(long long i = 2 ; i <= sqrt(long double(n)) ; i ++)
	{
		if(n % i == 0) return false;
	}
	return true;
}

long long GetLargestPrimeFactor(long long n)
{
	vector<long long> v;
	while(!isPrime(n))
	{
		for(long long i = 2 ; i <= sqrt(long double(n)) ; i ++)
		{
			if(n % i == 0)
			{
				n /= i;
				v.push_back(i);
				break;
			}
		}
	}
	v.push_back(n);
	sort(v.begin(), v.end());
	
	return v.back();
}

long long GetNthPrime(long long n)
{
	assert(n > 0);
	long long i = 2;
	while(true)
	{
		if(isPrime(i))
		{
			n --;
			if(n == 0) return i;
		}
		i ++;
	}
	return -1;
}

int Compute(int n)
{
	assert(n > 1);
	bool flag;
	for(int i = n ; ; i ++)
	{
		//cout<<i<<endl;
		flag = true;
		for(int j = 2 ; j <= n ; j ++)
		{
			if(i % j != 0) 
			{
				flag = false;
				break;
			}
		}
		if(flag) return i;
	}
}


int main()
{
	int n = 20;
	cout<<Compute(n)<<endl;


	return 0;
}