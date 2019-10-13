// C++ program to find repeating sequence in a fraction 
#include <iostream>
#include "/Users/scottg/euler_problems/stdc++.h"

using namespace std; 

// This function returns repeating sequence of 
// a fraction. If repeating sequence doesn't 
// exits, then returns empty string 
string fractionToDecimal(int numr, int denr) 
{ 
	string res; // Initialize result 

	// Create a map to store already seen remainders 
	// remainder is used as key and its position in 
	// result is stored as value. Note that we need 
	// position for cases like 1/6. In this case, 
	// the recurring sequence doesn't start from first 
	// remainder. 
	map <int, int> mp; 
	mp.clear(); 

	// Find first remainder 
	int rem = numr%denr; 

	// Keep finding remainder until either remainder 
	// becomes 0 or repeats 
	while ( (rem!=0) && (mp.find(rem) == mp.end()) ) 
	{ 
		mp[rem] = res.length(); 
		rem = rem*10; 
		int res_part = rem / denr; 
		res += to_string(res_part); 
		rem = rem % denr; 
	} 

	return (rem == 0)? "" : res.substr(mp[rem]); 
} 

// Driver code 
int main() 
{ 
	int numr = 1;
	int denr;

	int max = 0;

	for (denr = 1; denr <= 1000; denr++) {

	    string res = fractionToDecimal(numr, denr); 
	    if (res == "") 
		;
	    else
		cout << denr << " :  " << res << " : " << res.size() << "\n"; 
	        if (res.size() >= max) 
			max = res.size();
	}
        cout << "Longest recurring cycle: " << max <<  "\n"; 

	return 0; 
} 
