#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

vector<string> readFile();

int main()
{
    vector<string> input = readFile();
    for_each(input.begin(), input.end(), [](string line) {
        cout << line << endl;
    });
}

vector<string> readFile() 
{
    vector<string> result;
    ifstream file("1-trebuchet-input.txt");
    if(file.is_open()) {
        string line;
        while(getline(file, line)) {
            result.push_back(line);
        }
        file.close();
    }

    return result;
}
