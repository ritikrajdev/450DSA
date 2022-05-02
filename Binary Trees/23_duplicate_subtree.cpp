class Solution {
    unordered_map<string, int> freq;
    bool found = 0;
  public:
    string _dupSub(Node *root) {
        string tree = to_string(root->data);
        tree += root->left ? _dupSub(root->left) : " x";
        if (this->found) return "";

        tree += root->right ? _dupSub(root->right) : " x";
        if (this->found) return "";
        
        if (!root->left && !root->right)
            return tree;
        else {
            freq[tree]++;
    
            if (freq[tree] == 2)
                this->found = 1;
            
            return tree;
        }
    }
    
    bool dupSub(Node *root) {
        _dupSub(root);
        return this->found;
    }
};
