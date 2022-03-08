class Solution
{
    public:
    pair <bool, int> sumTree(Node* node) {
        if (!node->left && !node->right)
            return {1, node->data};

        int l = 0, r = 0;

        if (node->left) {
            auto x = sumTree(node->left);
            if (!x.first) return {0, 0};
            l = x.second;
        }
        if (node->right) {
            auto x = sumTree(node->right);
            if (!x.first) return {0, 0};
            r = x.second;
        }
        
        return {l + r == node->data, l + r + node->data};
    }
    
    bool isSumTree(Node* root)
    {
         return sumTree(root).first;
    }
};
