#include <string>

using namespace std;

class Solution {
  public:
    string longestPalin(string S) {
        int n = S.length();

        int mj = 0, mi = 0;
        for (int x = 0; x < n; x++) {
            // let x be the center of palindromic substring
            int i = x, j = x;
            while (i >= 0 && j < n && S[i] == S[j])
                i--, j++;
            int c1 = j - i - 1;

            if (c1 > mj - mi + 1)
                mj = j - 1, mi = i + 1;

            // let x be a center of even lengthed palindromic string
            i = x, j = x + 1;
            if (j == n)
                break;
            while (i >= 0 && j < n && S[i] == S[j])
                i--, j++;
            int c2 = j - i - 1;

            if (c2 > mj - mi + 1)
                mj = j - 1, mi = i + 1;
        }

        return S.substr(mi, mj - mi + 1);
    }
};
