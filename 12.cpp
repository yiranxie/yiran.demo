#include <iostream>
#include <cmath>
using namespace std;


int GetFactors(int num)
{
	int count = 0;
	for(int i = 1; i <= sqrt(num) ; i ++)
	{
		if(num % i == 0) count += 2;
	}
	return count;
}


int main()
{
	int n = 500;
	int TriNum = 1;
	int i = 2;
	while (GetFactors(TriNum) < n)
	{
		TriNum += i;
		i ++;
	}
	cout<<TriNum<<endl;
}
