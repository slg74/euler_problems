// g++ -o e26 e26.cpp -std=c++11
#include <iostream>
#include "/home/scottg/euler_problems/stdc++.h"

using namespace std; 

string to_decimal(int n, int d) {
    string res; 

    map <int, int> m; 
    m.clear(); 

    int rem = n % d; 

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
            //cout << d << " :  " << res << " : " << res.size() << "\n"; 
            if (res.size() >= max) 
                max = res.size();
    }

    // slow linear search, we don't want to print them all. refactor this.
    for (d = 1; d <= 1000; d++) {
        string res = to_decimal(n, d);
        if (res.size() == max)
            cout << " 1/" << d << " : " << "Longest recurring cycle: " << res <<  " : has " << max << " digits\n"; 
    }

    return 0; 
} 
