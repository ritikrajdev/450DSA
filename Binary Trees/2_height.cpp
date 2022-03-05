int height(struct Node* node)
{
    if (!node) return 0;
    int h1 = height(node->left);
    int h2 = height(node->right);
    int h = h1 >= h2 ? h1 : h2;
    return 1 + h;
}
