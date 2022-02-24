#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    bool wordBreak(string A, vector<string> &B) {
        if (A == "")
            return true;

        for (auto x : B) {
            auto i = A.find(x);
            if (i != string::npos) {
                bool l = wordBreak(A.substr(0, i), B);
                bool r = i + x.length() < A.length()
                             ? wordBreak(A.substr(i + x.length()), B)
                             : true;
                if (l && r)
                    return true;
            }
        }
        return false;
    }
};
