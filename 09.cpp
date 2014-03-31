#include <iostream>
using namespace std;

bool ifTrue(int a, int b, int c)
{
	if(a * a + b * b == c * c) return true;
	else return false;
}

int main()
{
	for(int i = 1 ; i<= 1000 ; i ++)for(int j = 1; j <= 1000 ; j ++)for(int k = 1; k <= 1000 ; k ++)
	{
		if(i + j + k == 1000 && ifTrue(i, j, k))
		{

			cout<<i*j*k<<endl;
			return 1;
		}
	}
	cout<<"Not found"<<endl;
	return 0;
}
