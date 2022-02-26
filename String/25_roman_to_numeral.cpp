#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int romanToDecimal(string &str) {
        unordered_map<string, int> ump = {
            {"I", 1},
            {"IV", 4},
            {"V", 5},
            {"IX", 9},
            {"X", 10},
            {"XL", 40},
            {"L", 50},
            {"XC", 90},
            {"C", 100},
            {"CD", 400},
            {"D", 500},
            {"CM", 900},
            {"M", 1000}
        };
        
        int sm = 0;
        int n = str.size();
        for (int i = str.size()-1; i >= 0; i--) {
            if (i - 1 >= 0 && ump[str.substr(i-1, 2)] > 0) {
                sm += ump[str.substr(i-1,2)];
                i--;
                continue;
            } else
                sm += ump[str.substr(i,1)];
        }
        return sm;
    }
};
