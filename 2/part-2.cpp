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

string extractId(string const &str)
{
    return str.substr(str.find(" "));
}

void assessHand(string str, map<string, int> &maxRequired)
{
    int spacePos = str.find(" ");
    string count = str.substr(0, spacePos);
    string colour = str.substr(spacePos + 1);
    
    int c = stoi(count);
    if(c > maxRequired[colour]) maxRequired[colour] = c;
}

void assessRound(string str, map<string, int> &maxRequired)
{
    size_t pos = 0;
    while((pos = str.find(",")) != string::npos) {
        assessHand(str.substr(1, pos - 1), maxRequired);
        str.erase(0, pos + 1);
    }

    assessHand(str.substr(1), maxRequired);
}

int getGamePower(string line)
{
    map<string, int> maxRequired = {
        {"red", 0}, {"green", 0}, {"blue", 0}
    };

    size_t pos = line.find(":");
    string id = extractId(line.substr(0, pos));
    line.erase(0, pos + 1);
    
    while((pos = line.find(";")) != string::npos) {
        assessRound(line.substr(0, pos), maxRequired);
        line.erase(0, pos + 1);
    }
    assessRound(line, maxRequired);

    int res = 1;
    for(const auto & [key, value] : maxRequired) res *= value;
    return res;
}

int main()
{
    int res = 0;
    for(string line : readFile()) {
        res += getGamePower(line);
    }
    
    cout << res << endl;
}