#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

#include "../helper/file-helper.cpp"

void processPart(vector<string> file, int x, int y, int n, map<pair<int, int>, vector<int>> &gearNums, int num)
{
    for(int i = x - 1; i <= x + 1; i++) {
        if(i < 0 || i >= file.size()) continue;
        for(int j = y; j >= y - n - 1; j--) {
            if(j < 0 || j >= file.at(i).length()) continue;
            if(file.at(i).at(j) == '*') {
                pair<int, int> coords = {i, j};
                if(gearNums.count(coords) == 0) gearNums.insert({coords, {num}});
                else gearNums.at(coords).push_back(num);
            }
        }
    }
}

int main()
{
    int res = 0;
    string curStr = "";
    vector<string> file = readFile();

    map<pair<int, int>, vector<int>> gearNums;

    for(int i = 0; i < file.size(); i++) {
        for(int j = 0; j < file.at(0).size(); j++) {
            char c = file.at(i).at(j);
            
            if(isdigit(c)) curStr += c;

            bool endOfNumber = !isdigit(c) || j == file.at(0).size() - 1;
            if(endOfNumber && curStr != "") {
                int n = stoi(curStr);
                processPart(file, i, j, curStr.length(), gearNums, n);
                curStr = "";
            }
        }
    }

    for(const auto & [key, value] : gearNums) {
        if(value.size() == 2) res += (value.at(0) * value.at(1));
    }

    cout << res << endl;
}