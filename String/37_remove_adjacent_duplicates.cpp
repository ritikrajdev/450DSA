#include <string>

using namespace std;

class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        string result;
        result.reserve(S.size());
        
        result.push_back(S[0]);
        for (int i = 1; i < S.size(); i++)
            if (result.back() != S[i])
                result.push_back(S[i]);
        return result;
    }
};
