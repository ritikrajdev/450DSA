class Solution {
  public:
    int toSumTree(Node *node) {
        int l = 0, r = 0;
        if (node->left)
            l = toSumTree(node->left);
        if (node->right)
            r = toSumTree(node->right);
        
        int ans = l + r + node->data;
        node->data = l + r;
        return ans;
    }
};
