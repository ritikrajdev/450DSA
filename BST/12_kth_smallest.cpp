class Solution {
    int i = 0;
    bool found = false;
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root,int k) {
        int l = -1, r = -1;
        if (root->left) l = KthSmallestElement(root->left, k);
        if (found)
            return l;
    
        i += 1;
        if (i == k) {
            found = true;
            return root->data;
        }
    
        if (root->right) r = KthSmallestElement(root->right, k);
        return r;
    }
};
