#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    string smallestWindow(string s, string p) {
        unordered_map<char, int> ump;
        for (auto c : p)
            ump[c]++;
        int cnt = ump.size();

        int mi = 0, mj = s.size();
        int i = 0, j = 0;
        while (j < s.size()) {
            if (ump.find(s[j]) != ump.end()) {
                ump[s[j]]--;
                if (ump[s[j]] == 0)
                    cnt--;
            }

            if (cnt == 0) {
                while (i <= j && cnt == 0) {
                    if (ump.find(s[i]) != ump.end()) {
                        ump[s[i]]++;
                        if (ump[s[i]] == 1)
                            cnt++;
                    }
                    i++;
                }
                if (mj - mi > j - i + 1)
                    mj = j, mi = i - 1;
            }

            j++;
        }

        return mj - mi + 1 > s.size() ? "-1" : s.substr(mi, mj - mi + 1);
    }
};
