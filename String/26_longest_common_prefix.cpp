#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string x = "";
        x.reserve(strs[0].length());
        
        for (int i = 0; i < strs[0].size(); i++) {
            char prefix = strs[0][i];
            for (int j = 1; j < strs.size(); j++)
                if (i >= strs[j].length() || strs[j][i] != prefix)
                    return x;
            x.push_back(prefix);
        }
        return x;
    }
};
