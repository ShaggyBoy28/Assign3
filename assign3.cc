/*
Joshua Rithaler
z1838785
CSCI 340-2
I certify that this is my own work and where appropriate an extension
of the starter code provided for the assignment.
*/  


#include "assign3.h"
#include <iostream>
#include <set>

using std::set;

/*
this function is designed to go through the value that is cin by the user and then 
sorts the values until there are only prime numbers left in the set

*/
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

/*
this function prints the values and uses the defines values in assign3.h to format the 
way that the output looks
*/

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

/*
the main funtion recieves the value the user want to use and then calls the
two functions needed to produce the list of prime numbers
*/

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
