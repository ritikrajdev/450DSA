#include <stack>
#include <string>
using namespace std;

class Solution
{
    public:
    bool ispar(string x)
    {
        stack<char> st;
        for (auto c: x) {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else if (st.empty())
                return false;
            else {
                if (c == '}') c = '{';
                else if (c == ']') c = '[';
                else if (c == ')') c = '(';
                
                if (st.empty()) return false;
                if (st.top() == c) st.pop();
                else return false;
            }
        }
        
        return st.empty();
    }
};
