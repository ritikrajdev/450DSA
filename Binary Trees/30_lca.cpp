class Solution {
    public:
    Node* lca (Node* root, int n1, int n2) {
        Node *l = 0, *r = 0;
        if (root->left) l = lca(root->left, n1, n2);
        if (root->right) r = lca(root->right, n1, n2);
        
        if (root->data == n1)
            return root;

        if (root->data == n2)
            return root;

        if (l && r)
            return root;
        if (l)
            return l;
        if (r)
            return r;

        return 0;
    }
};
