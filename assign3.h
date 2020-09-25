#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>

using namespace std;

#ifndef H_PROG3
#define H_PROG3

#define NO_ITEMS 16
#define ITEM_W 5 


// find the prime numbers
void sieve(set<int> &, int);

// to print contents of the array
void print_primes(const set<int> &);

#endif
