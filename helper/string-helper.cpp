#include <vector>
#include <string>

using namespace std;

vector<string> split(string str, string delim)
{
    vector<string> result;
    size_t pos = 0;
    while((pos = str.find(delim)) != string::npos) {
        string token = str.substr(0, pos);
        if(token != "") result.push_back(token);
        str.erase(0, pos + delim.length());
    }
    result.push_back(str);
    return result;
}