  
#include "assign3.h"
#include <iostream>
#include <set>

using std::set;

void sieve(set<int>& s, int n)
{
	bool numArray[100000] = {0};
	
	set<int>::iterator val;
	
	for(int m = 2; m * m <= n; m++)
	{
		if(numArray[m] == 0)
		{
			for(int k = 2; m * k <= n; k++)
			{
				numArray[m * k] = 1;
				val = s.find(m * k);
				if(val != s.end())
				{
					s.erase(val);
				}
			}
		}	
	}  
}

void print_primes(const set<int>& s)
{
	int count = 0;
	set<int>::iterator val;
	for(val = s.begin(); val != s.end(); val++)
	{
		if(count == NO_ITEMS)
		{
			std::cout << endl;
		}
		std::cout << left << setw(ITEM_W) << *val;
		count++;
	}
	std::cout << endl;
}

int
main()
{
	set<int> val;
	int userVal;
	std::cout << "Upper limit for the set of primes: :";
	std::cin >> userVal;
	
	for(int i = 2; i <= userVal; i++)
	{
		val.insert(i);
	}
	
	sieve(val, userVal);
	print_primes(val);
	
	
	
	
	return 0;
}
