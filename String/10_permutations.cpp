#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
    void helper(string &S, int l, int r, vector<string> &vec) {
        if (l == r) {
            vec.push_back(S);
            return;
        }

        for (int i = l; i <= r; i++) {
            swap(S[i], S[l]);
            helper(S, l + 1, r, vec);
            swap(S[i], S[l]);
        }
    }

  public:
    vector<string> find_permutation(string S) {
        std::sort(S.begin(), S.end());
        vector<string> vec;
        helper(S, 0, S.size() - 1, vec);
        std::sort(vec.begin(), vec.end());
        return vec;
    }
};
