#include <vector>
#include <unordered_map>

#define ll long long

using namespace std;

class Solution{
    public:
    ll findSubarray(vector<ll> arr, int n ) {
        unordered_map<int,int> ump;
        ll count = 0;
        ll sum = 0;
        ump[0] = 1;
        for (auto x: arr) {
            sum += x;
            if (ump[sum])
                count += ump[sum];
            ump[sum]++;
        }
        return count;
    }
};
