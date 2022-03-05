class Solution {
	public:
		string FirstNonRepeating(string A) {
		    string ans = "";
		    ans.reserve(A.size());
		    queue<char> q;
		    unordered_map<char, int> ump;
		    for (char c: A) {
		        if (!ump[c]) q.push(c);
		        ump[c]++;
		        while (q.size() && ump[q.front()] != 1)
		            q.pop();
		        if (q.size()) ans.push_back(q.front());
		        else ans.push_back('#');
		    }
		    
		    return ans;
		}
};
