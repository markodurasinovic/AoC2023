// #include <iostream>
#include <vector>
#include <fstream>
#include <string>

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
