#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int get_numeric_value(string s);

int main() {
    ifstream infile("names.txt"); 
    string line = ""; 
    vector<string> all_words;
    while (getline(infile, line)) {
        stringstream strstr(line);
        string word = ""; 
        while (getline(strstr, word, ',')) all_words.push_back(word);
    }

    sort(all_words.begin(), all_words.end()); 

    int position = 0;
    int total = 0;
    for (unsigned i=0; i < all_words.size(); i++) {
        position++; 
        total += position * get_numeric_value(all_words[i]); 
    }
    cout << total << endl; 
    return 0;
}

int get_numeric_value(string s) {
    int total = 0; 
    for (unsigned i : s) {
        if (i > 64) { 
            total += (i-64);
        }
    }
    return total; 
}
