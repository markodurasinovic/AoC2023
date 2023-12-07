#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

using namespace std;

vector<string> readFile() 
{
    vector<string> result;
    ifstream file("2-cube-conundrum-input.txt");
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
    if(x + 1 < file.at(0).length() && isSymbol(file.at(x).at(y))) return true;
    if(x - n > 0 && isSymbol(file.at(x).at(y))) return true;

    for(int i = x; i > x - n; i--) {
        if(y - 1 >= 0) {
            // check all above
            for(int j = x - n; j <= x + 1; j++) {
                
            }
        }
        if(y + 1 < file.size()) {
            // check all below
        }
    }

    cout << "returning too late from isPart" << endl;
    return false;    
}

int main()
{
    int res = 0;
    // vector<char, char> arr;
    string curStr = "";
    vector<string> file = readFile();
    for(int i = 0; i < file.size(); i++) {
        for(int j = 0; j < file.at(0).size(); j++) {
            // arr[i][j] = c;
            char c = file.at(i).at(j);
            if(isdigit(c)) {
                curStr += c;
            } else if(c == 'c') {
                int n = stoi(curStr);
                if(isPart(file, i, j, curStr.length())) res += n;
                curStr = "";
            }
        }
    }

    cout << res << endl;
}