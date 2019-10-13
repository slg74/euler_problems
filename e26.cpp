// source borrowed and slightly modified from https://www.geeksforgeeks.org/find-recurring-sequence-fraction/
#include <iostream>
#include "/Users/scottg/euler_problems/stdc++.h"

using namespace std; 

string to_decimal(int n, int d) {
	string res; // Initialize result 

	map <int, int> m; 
	m.clear(); 

	int rem = n % d; 

	// Keep finding remainder until either remainder 
	// becomes 0 or repeats 
	while ( (rem!=0) && (m.find(rem) == m.end()) ) {
		m[rem] = res.length(); 
		rem = rem*10; 
		int res_part = rem / d; 
		res += to_string(res_part); 
		rem = rem % d; 
	} 

        if (rem == 0) 
		return "";

        return res.substr(m[rem]);
} 

int main() {
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
