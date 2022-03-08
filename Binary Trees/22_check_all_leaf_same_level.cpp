class Solution{
    int depth = 0;
  public:
    bool check_all(Node* node, int d) {
        if (!node->left && !node->right)
            return d == depth;
        
        bool l = 1, r = 1;
        
        if (node->left)
            l = check_all(node->left, d+1);
        if (node->right)
            r = check_all(node->right, d+1);
        
        return l && r;
    }
  
    bool check(Node *root) {
        Node* node = root;
        while (node->left || node->right) {
            if (node->left) node = node->left;
            else if (node->right) node = node->right;
            depth++;
        }
        return check_all(root, 0);
    }
};
