Node* LCA(Node *root, int n1, int n2)
{
    if (n1 > n2)
        return LCA(root, n2, n1);
    
    if (n1 <= root->data && root->data <= n2)
        return root;
    
    if (n1 <= root->data && n2 <= root->data)
        return LCA(root->left, n1, n2);
    
    if (n1 >= root->data && n2 >= root->data)
        return LCA(root->right, n1, n2);
}

