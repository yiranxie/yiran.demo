#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;


/* Big Numbers Operations */
class BigNumber
{
	public:
		//ctors
		BigNumber()
		{
		}
		BigNumber(int num)
		{
			UpdateData(num);
		}
		BigNumber(vector<int> vec)
		{
			data = vec;
		}
		BigNumber(const BigNumber &rhs)
		{
			data = rhs.data;
		}
		
		//operators
		BigNumber& operator =(const BigNumber & rhs)
		{
			data = rhs.data;
			return *this;
		}
		friend ostream& operator <<(ostream& os, const BigNumber &bg);
        friend BigNumber operator *(const BigNumber & lhs, const BigNumber & rhs);

		//other functions
		const vector<int>& GetData() const
		{
			return data;
		}
	private:
		vector<int> data;
		void UpdateData(int num)
		{
			assert(num >= 0);
			data.clear();
			if(num == 0)
			{
				data.push_back(0);
			}
			else
			{
				while(num != 0)
				{
					data.push_back(num % 10);
					num -= num % 10;
					num /= 10;
				}
			}
			return;
		}
};

ostream& operator <<(ostream& os, const BigNumber &bg)
{
	vector<int> data = bg.data;

	for(vector<int>::const_reverse_iterator criter = data.rbegin() ; criter != data.rend() ; criter ++)
	{
		os<<*criter;
	}
	return os;
}

BigNumber operator *(const BigNumber & lhs, const BigNumber & rhs)
{
	vector<int> val1 = lhs.data;
	vector<int> val2 = rhs.data;
	assert(val1.size() != 0 && val2.size() != 0);

	int NewSize = val1.size() + val2.size();
	vector<int> sum(NewSize, 0);

	for(size_t i = 0 ; i < val2.size() ; i ++)for(size_t j = 0 ; j < val1.size() ; j ++)
	{
		sum[i + j] += val2[i] * val1[j];
	}
	for(size_t i = 0 ; i < sum.size() - 1 ; i ++)
	{
		sum[i + 1] += sum[i] / 10;
		sum[i]      = sum[i] % 10;
	}
	//delete the possible zero at the end
	if(sum.back() == 0) sum.erase(-- sum.end());

	return BigNumber(sum);
}
//============================================================================================================
//Problem 16
BigNumber GetFactor(int num)
{
	assert(num >= 0);
	if(num == 0) return 1;
	else 
	{
		BigNumber product = 1;
		for(int i = 1 ; i <= num ; i ++)
		{
			product = product * i;
		}
		return product;
	}
}

int GetSumOfDigits(const BigNumber &bg)
{
	vector<int> vec = bg.GetData();
	int sum = 0;
	for(vector<int>::const_iterator citer = vec.begin() ; citer != vec.end() ; citer ++)
	{
		sum += *citer;
	}
	return sum;
}

//================================================================================================
//Problem 20

BigNumber GetExp2N(int num)
{
	assert(num >= 0);
	if(num == 0) return 1;
	BigNumber product = 1;
	for(int i = 1; i <= num ; i ++)
	{
		product = product * 2;
	}
	return product;
}

int main()
{
	//Problem 16
	//BigNumber bg = GetFactor(100);
	//cout<<bg<<endl;
	//cout<<GetSumOfDigits(bg)<<endl;
	
	//Problem 20
	BigNumber bg = GetExp2N(1000);
	cout<<bg<<endl;
	cout<<GetSumOfDigits(bg)<<endl;


	return 0;
}
