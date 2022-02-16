#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    bool areIsomorphic(string str1, string str2) {
        if (str1.size() != str2.size())
            return false;

        unordered_map<char, char> ump1;
        for (int i = 0; i < str1.size(); i++) {
            if (ump1[str1[i]] && ump1[str1[i]] != str2[i])
                return false;
            ump1[str1[i]] = str2[i];
        }

        unordered_map<char, char> ump2;
        for (int i = 0; i < str2.size(); i++) {
            if (ump2[str2[i]] && ump2[str2[i]] != str1[i])
                return false;
            ump2[str2[i]] = str1[i];
        }

        return true;
    }
};
