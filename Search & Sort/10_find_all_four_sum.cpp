#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] > b[i])
            return false;
    return true;
}

class Solution{
    void remove_duplicates(vector<vector<int>>& v) {
        int i = 1;
        while(i < v.size()) {
            if (v[i-1] == v[i])
                v.erase(v.begin() + i);
            else
                i++;
        }
    }

    public:
    vector<vector<int>> fourSum(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> v;
        
        for (int i = 0; i < n-3; i++) {
            for (int j = i+1; j < n-2; j++) {
                int req_sum = k - arr[i] - arr[j];
                int l = j+1, r = n - 1;
                while (l < r) {
                    if (arr[l] + arr[r] == req_sum) {
                        v.push_back({arr[i], arr[j], arr[l], arr[r]});
                        l++, r--;
                    }
                    else if (arr[l] + arr[r] > req_sum)
                        r--;
                    else
                        l++;
                }
            }
        }
        
        for (auto& x: v) sort(x.begin(), x.end());
        sort(v.begin(), v.end(), compare);
        remove_duplicates(v);
        return v;
    }
};
