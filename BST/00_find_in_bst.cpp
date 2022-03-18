bool findNode(TreeNode <int> * root, int key) {
    if (!root) return false;

    if (root->data == key)
        return true;
    else if (root->data > key)
        return findNode(root->left, key);
    else
        return findNode(root->right, key);
}
