#include <iostream>
#include <vector>
#include <string>
#include <string.h>

#include "../helper/file-helper.cpp"

using namespace std;

int getValue(string const &line);

int main()
{
    int res = 0;
    for(string line : readFile()) {
        res += getValue(line);
    }
    cout << res << endl;
}

int getValue(string const &line) 
{
    vector<int> digit_chars;
    for(char c : line) {
        if(isdigit(c)) digit_chars.push_back(c - '0');
    }
    return (digit_chars.front() * 10) + digit_chars.back();
}
