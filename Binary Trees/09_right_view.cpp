class Solution
{
    vector<int> ans;
    public:
    void _rightView(Node* root, int depth) {
        if (!root) return;
        
        if (depth == ans.size())
            ans.push_back(root->data);
            
        _rightView(root->right, depth+1);
        _rightView(root->left, depth+1);
    }

    vector<int> rightView(Node *root)
    {
       _rightView(root, 0);
       return ans;
    }
};
