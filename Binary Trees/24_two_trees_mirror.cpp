bool areMirror(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    if (!root1 && !root2)
        return true;

    if (!root1 || !root2)
        return false;

    return root1->data == root2->data &&
        areMirror(root1->left, root2->right) &&
        areMirror(root1->right, root2->left);
}
