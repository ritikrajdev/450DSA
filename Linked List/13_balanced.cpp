class Solution{
    public:
    bool all(vector<bool> x) {
        for (bool b: x)
            if (!b)
                return 0;
        return 1;
    }

    pair<bool, int> _isBalanced(Node* root) {
        if (!root)
            return {true, 0};
        
        auto l = _isBalanced(root->left);
        auto r = _isBalanced(root->right);
        
        return {
            all({l.first, r.first, abs(l.second - r.second) <= 1}),
            1+max(l.second, r.second)
        };
    }

    bool isBalanced(Node *root)
    {
        return _isBalanced(root).first;
    }
};
