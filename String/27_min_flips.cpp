#include <string>

using namespace std;

int flips(const string& s, bool startsFrom) {
    int cnt = 0;
    for (const auto& x: s) {
        if (x - '0' == startsFrom) cnt ++;
        startsFrom = !startsFrom;
    }
    return cnt;
}

int minFlips (string S)
{
    return min(flips(S, 0), flips(S, 1));
}
