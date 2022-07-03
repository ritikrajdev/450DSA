class Solution{
        string s;
        vector<string> v;
	public:
	    void allSubstrings(string input, int i) {
            if (i == s.size()) {
                if (input.size()) v.push_back(input);
                return;
            }
            
            allSubstrings(input + s[i], i+1);
            allSubstrings(input, i+1);
	    }
	    
		vector<string> AllPossibleStrings(string& s){
		    this->s = s;
		    allSubstrings("", 0);
		    sort(v.begin(), v.end());
		    return v;
		}
};
