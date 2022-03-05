class Solution {
  public:
    int height(Node* node) {
        if (!node) return 0;
        int h1 = height(node->left);
        int h2 = height(node->right);
        int h = h1 >= h2 ? h1 : h2;
        return 1 + h;
    }
    
    int diameter(Node* root) {
        if (!root) return 0;
        int d = height(root->left) + height(root->right) + 1;
        return max({d, diameter(root->left), diameter(root->right)});
    }
};
