#include <iostream>
#include <set>

#include "../helper/file-helper.cpp"
#include "../helper/string-helper.cpp"

using namespace std;

int main()
{
    int res = 0;
    vector<string> file = readFile();
    for(string str : file) {
        vector<string> game = split(split(str, ": ")[1], " | ");
        
        set<string> winners;
        for(string w : split(game[0], " ")) winners.insert(w);

        int score = 0;
        for(string n : split(game[1], " ")) {
            if(winners.count(n) != 0) {
                score *= 2;
                if(score == 0) score = 1;
            }
        }
        res += score;
    }
    cout << res << endl;
}