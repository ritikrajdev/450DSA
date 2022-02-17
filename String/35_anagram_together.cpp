#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    bool anagram(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;

        unordered_map<char, size_t> ump1, ump2;

        for (auto x : s1)
            ump1[x]++;
        for (auto x : s2)
            ump2[x]++;

        return ump1 == ump2;
    }

  public:
    vector<vector<string>> Anagrams(vector<string> &string_list) {
        vector<vector<string>> res;
        res.push_back({string_list[0]});

        for (int i = 1; i < string_list.size(); i++) {
            bool anagram_found = false;
            for (int j = 0; j < res.size(); j++) {
                if (anagram(res[j][0], string_list[i])) {
                    res[j].push_back(string_list[i]);
                    anagram_found = true;
                    break;
                }
            }
            if (!anagram_found)
                res.push_back({string_list[i]});
        }
        return res;
    }
};
