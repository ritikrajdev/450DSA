#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<string, bool> ump;
public:
    bool wordBreak(string A, vector<string> &B) {
        if (A == "")
            return true;
        
        if (ump.find(A) != ump.end())
            return ump[A];

        for (auto x: B) {
            auto i = A.find(x);
            if (i != string::npos) {
                bool l = wordBreak(A.substr(0, i), B);
                bool r = i + x.length() < A.length() ? wordBreak(A.substr(i+x.length()), B) : true;
                if (l && r)
                    return ump[A] = true;
            }
        }
        return ump[A] = false;
    }
};
