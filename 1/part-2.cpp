#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <map>

using namespace std;

int getValue(string const &line);
int findFirst(string const &line);
int findLast(string const &line);
int checkForDigit(string const &line, int const &i);
int wordToDigit(string const &line, int const &i);
vector<string> readFile();

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
    return findFirst(line) * 10 + findLast(line);
}

int findFirst(string const &line)
{
    for(int i = 0; i < line.length(); i++) {
        int res = checkForDigit(line, i);
        if(res > -1) return res;
    }

    return 0;
}

int findLast(string const &line)
{
    for(int i = line.length() - 1; i >= 0; i--) {
        int res = checkForDigit(line, i);
        if(res > -1) return res;
    }

    return 0;
}

int checkForDigit(string const &line, int const &i)
{
    if(isdigit(line.at(i))) {
        return line.at(i) - '0';
    } else {
        int digit = wordToDigit(line, i);
        if(digit > -1) return digit;
    }

    return -1;
}

int wordToDigit(string const &line, int const &i)
{
    map<string, int> digitMap = {
        {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
        {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };

    for(const auto& pair : digitMap) {
        string word = pair.first;
        if(line.substr(i, word.length()) == word) return pair.second;
    }
    
    return -1;
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