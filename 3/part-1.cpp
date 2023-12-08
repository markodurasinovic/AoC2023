#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

using namespace std;

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

bool isSymbol(char c)
{
    return !isdigit(c) && c != '.';
}

bool isPart(vector<string> file, int x, int y, int n)
{
    for(int i = x - 1; i <= x + 1; i++) {
        if(i < 0 || i >= file.size()) continue;
        for(int j = y; j >= y - n - 1; j--) {
            if(j < 0 || j >= file.at(i).length()) continue;
            if(isSymbol(file.at(i).at(j))) return true;
        }
    }

    return false;    
}

int main()
{
    int res = 0;
    string curStr = "";
    vector<string> file = readFile();
    for(int i = 0; i < file.size(); i++) {
        for(int j = 0; j < file.at(0).size(); j++) {
            char c = file.at(i).at(j);
            
            if(isdigit(c)) curStr += c;

            bool endOfNumber = !isdigit(c) || j == file.at(0).size() - 1;
            if(endOfNumber && curStr != "") {
                int n = stoi(curStr);
                if(isPart(file, i, j, curStr.length())) res += n;
                curStr = "";
            }
        }
    }

    cout << res << endl;
}