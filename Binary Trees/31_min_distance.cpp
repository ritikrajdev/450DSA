class Solution{
    public:
    Node* lca(Node* root, int a, int b) {
        Node *l = 0, *r = 0;
        if (root->left) l = lca(root->left, a, b);
        if (root->right) r = lca(root->right, a, b);
        
        if (root->data == a || root->data == b)
            return root;
        if (l && r)
            return root;
        if (l)
            return l;
        if (r)
            return r;

        return 0;
    }
    
    int distance(Node* root, int x) {
        if (root->data == x)
            return 0;
        
        int l =-1, r =-1;
        if (root->left) l = distance(root->left, x);
        if (root->right) r = distance(root->right, x);

        if (l == -1 && r == -1)
            return -1;

        return 1 + (l == -1 ? r : l);
    }
    
    int findDist(Node* root, int a, int b) {
        Node* LCA = lca(root, a, b);
        return distance(LCA, a) + distance(LCA, b);
    }
};
