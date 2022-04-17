class Solution
{
    public:
    int prev = INT_MIN;
    bool isBST(Node* root) 
    {
        if (!root) return true;
        if (!isBST(root->left))
            return false;
        if (prev >= root->data)
            return false;
        prev = root->data;
        return isBST(root->right);
    }
};

