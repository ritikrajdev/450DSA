vector<int> ans;

void _preorder(Node* root) {
    ans.push_back(root->data);
    if (root->left) _preorder(root->left);
    if (root->right) _preorder(root->right);
}

vector <int> preorder(Node* root)
{
    _preorder(root);
    vector<int> a = ans;
    ans.clear();
    return a;
}
