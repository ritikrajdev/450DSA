#include <string>

using namespace std;

class Solution {
  public:
    int minimumNumberOfSwaps(string S) {
        int swaps = 0, x = 0;
        for (auto c : S) {
            if (c == '[')
                x--;
            else {
                x++;
                if (x > 0)
                    swaps += x;
            }
        }
        return swaps;
    }
};
