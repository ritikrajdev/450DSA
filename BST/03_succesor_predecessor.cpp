void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    while (root && root->key != key) {
        if (key > root->key)
            root = root->right;
        else root = root->left;
    }
    
    if (!root) {
        pre = suc = 0;
        return;
    }
    
    // pre
    Node* itr = root;
    Node* p = 0;
    itr = itr->left;
    while (itr) {
        p = itr;
        itr = itr->right;
    }
    if (p) pre = p;
    else pre = 0;
    
    // succ
    itr = root;
    p = 0;
    itr = itr->right;
    while (itr) {
        p = itr;
        itr = itr->left;
    }
    if (p) suc = p;
    else suc = 0;
}
