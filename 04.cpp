#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

bool isPalindrome(int val)
{
	assert(val > 0);
	vector<int> digits;
	while(val)
	{
		digits.push_back(val % 10);
		val -= digits.back();
		val /= 10;
	}

	vector<int>::const_iterator citer_f = digits.begin();
	vector<int>::const_iterator citer_b = digits.end() - 1;
	while(citer_b >= citer_f)
	{
		if(*citer_f == *citer_b)
		{
			*citer_f ++;
			*citer_b --;
		}
		else return false;
	}
	return true;
}


int main()
{
	int max = -1;
	for(int i = 100 ; i <= 999 ; i ++)for(int j = 100 ; j <= 999 ; j ++)
	//for(int i = 10 ; i <= 99 ; i ++ )for(int j = 10 ; j <= 99 ; j ++)
	{
		if(isPalindrome(i * j))
		{
			if(i * j > max)
				max = i * j;
		}
	}	
	
	cout<<max<<endl;

	return 0;
}
