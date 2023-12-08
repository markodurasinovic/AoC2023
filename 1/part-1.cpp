#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <string.h>

using namespace std;

vector<string> readFile();
int getValue(string const &line);

int main()
{
    int res = 0;
    for(string line : readFile()) {
        res += getValue(line);
    }
    cout << res << endl;
}

vector<string> readFile() 
{
    vector<string> result;
    ifstream file("input.txt");
    if(file.is_open()) {
        string line;
        while(getline(file, line)) {
            result.push_back(line);
        }
        file.close();
    }

    return result;
}

int getValue(string const &line) 
{
    vector<int> digit_chars;
    for(char c : line) {
        if(isdigit(c)) digit_chars.push_back(c - '0');
    }
    return (digit_chars.front() * 10) + digit_chars.back();
}
