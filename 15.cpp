#include <iostream>
#include <assert.h>
#include <ctime>

typedef long long Type;

Type GetNumOfLatticePaths_RecursiveHelper(unsigned int idx_height, unsigned int idx_width, Type **cache)
{
	assert(cache != NULL);
	//if it has been done before(cache[][] initially set to -1)
	if(cache[idx_height][idx_width] != -1) return cache[idx_height][idx_width];
	
	//exit case  f(x,0) = f(0, y) = 1
	if(idx_height == 0 || idx_width == 0) return 1;

	//normal procedure f(x, y) = f(x - 1, y) + f(x, y - 1)
	cache[idx_height][idx_width] = GetNumOfLatticePaths_RecursiveHelper(idx_height - 1, idx_width, cache) + GetNumOfLatticePaths_RecursiveHelper(idx_height, idx_width - 1, cache);
	return cache[idx_height][idx_width];
}

Type GetNumOfLatticePaths(int num)
{
	assert(num > 0);
	//create cache to avoid duplicated calculation
	Type **cache = new Type*[num + 1];
	for(int i = 0 ; i <= num ; i ++)
		cache[i] = new Type[num + 1];
	//set initial value to -1
	for(int i = 0 ; i <= num ; i ++)for(int j = 0 ; j <= num ; j ++)
		cache[i][j] = -1;

	//Main function
	Type ret = GetNumOfLatticePaths_RecursiveHelper(num, num, cache);

	//Clear
	for(int i = 0 ; i <= num ; i ++)
		delete[] cache[i];
	delete[] cache;
	cache = NULL;

	return ret;
}


int main()
{
	int num = 20;

	clock_t start = clock();
	std::cout<<GetNumOfLatticePaths(num)<<std::endl;
	clock_t finish = clock();
	std::cout<<"Time Used: "<<(double)(finish - start) / CLOCKS_PER_SEC<<" seconds"<<std::endl;

	return 0;
}