#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

using namespace std;

map<string, int> maxCounts = {
    {"red", 12}, {"green", 13}, {"blue", 14}
};

vector<string> readFile() 
{
    vector<string> result;
    ifstream file("2-cube-conundrum-input-part-1.txt");
    if(file.is_open()) {
        string line;
        while(getline(file, line)) {
            result.push_back(line);
        }
        file.close();
    }

    return result;
}

string extractId(string const &str)
{
    return str.substr(str.find(" "));
}

bool isValidHand(string str)
{
    // bullshit hack - see why the leading space happens
    while(str.at(0) == ' ') str.erase(0, 1);
    int spacePos = str.find(" ");
    string count = str.substr(0, spacePos);
    string colour = str.substr(spacePos + 1);
    
    return maxCounts[colour] >= stoi(count);
}

bool isValidRound(string str)
{
    size_t pos = 0;
    while((pos = str.find(",")) != string::npos) {
        if(!isValidHand(str.substr(0, pos))) return false;
        str.erase(0, pos + 1);
    }

    return isValidHand(str);
}

int getValue(string line)
{
    size_t pos = line.find(":");
    string id = extractId(line.substr(0, pos));
    line.erase(0, pos + 1);
    while((pos = line.find(";")) != string::npos) {
        if(!isValidRound(line.substr(0, pos))) return -1;
        line.erase(0, pos + 1);
    }
    if(!isValidRound(line)) return -1;

    return stoi(id);
}

int main()
{
    int res = 0;
    for(string line : readFile()) {
        int id = getValue(line);
        if(id > -1) {
            res += id;
        }
    }
    cout << res << endl;
}