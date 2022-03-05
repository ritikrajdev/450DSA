void mirrorTree(BinaryTreeNode<int> *root) {
    if (!root) return;
    mirrorTree(root->left);
    mirrorTree(root->right);
    swap(root->left, root->right);
}
