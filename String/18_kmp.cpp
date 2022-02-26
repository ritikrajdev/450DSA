#include <string>
#include <vector>

using namespace std;

class Solution{
  public:		
	int lps(string s) {
        int i = 0, j = 1;
        vector<int> v (s.size(), 0);
        
        while (j < s.size()) {
            if (s[j] == s[i])
                v[j++] = ++i;
            else if (i > 0)
                i = v[i-1];
            else j++;
        }
        
        return v.back();
	}
};
