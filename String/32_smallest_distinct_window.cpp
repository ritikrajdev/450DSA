#include <string>
#include <unordered_map>

using namespace std;

class Solution{
    public:
    string findSubString(string str)
    {
        unordered_map<char, int> ump;

        for (auto c: str)
            ump[c] = 1;
        
        int u = ump.size();
        ump.clear();
    
        int mi = 0, mj = str.size()-1;
        int i = 0, j = 0;
        while (j < str.size() && i <= j) {
            ump[str[j]]++;
            if (ump.size() == u) {
                while (ump.size() == u) {
                    ump[str[i]]--;
                    if (ump[str[i]] == 0)
                        ump.erase(str[i]);
                    i++;
                }
                if (j - i + 1 < mj - mi)
                    mi = i - 1, mj = j;
            }
            j++;
        }
        return str.substr(mi, mj - mi + 1);
    }
};
