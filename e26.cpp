// C++ program to find repeating sequence in a fraction 
// source borrowed and slightly modified from https://www.geeksforgeeks.org/find-recurring-sequence-fraction/
#include <iostream>
#include "/Users/scottg/euler_problems/stdc++.h"

using namespace std; 

// This function returns repeating sequence of 
// a fraction. If repeating sequence doesn't 
// exits, then returns empty string 
string to_decimal(int n, int d) 
{ 
	string res; // Initialize result 

	// Create a map to store already seen remainders 
	// remainder is used as key and its position in 
	// result is stored as value. Note that we need 
	// position for cases like 1/6. In this case, 
	// the recurring sequence doesn't start from first 
	// remainder. 
	map <int, int> m; 
	m.clear(); 

	// Find first remainder 
	int rem = n % d; 

	// Keep finding remainder until either remainder 
	// becomes 0 or repeats 
	while ( (rem!=0) && (m.find(rem) == m.end()) ) 
	{ 
		m[rem] = res.length(); 
		rem = rem*10; 
		int res_part = rem / d; 
		res += to_string(res_part); 
		rem = rem % d; 
	} 

	return (rem == 0)? "" : res.substr(m[rem]); 
} 

int main() 
{ 
	int n = 1;
	int d;

	int max = 0;

	for (d = 1; d <= 1000; d++) {
	    string res = to_decimal(n, d); 
	    if (res == "") 
		;
	    else
		cout << d << " :  " << res << " : " << res.size() << "\n"; 
	        if (res.size() >= max) 
			max = res.size();
	}
        cout << "Longest recurring cycle: " << max <<  "\n"; 

	return 0; 
} 
