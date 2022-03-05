vector<int> ans;

void _postorder(Node* root) {
    if (root->left) _postorder(root->left);
    if (root->right) _postorder(root->right);
    ans.push_back(root->data);
}

vector <int> postOrder(Node* root)
{
    _postorder(root);
    vector<int> a = ans;
    ans.clear();
    return a;
}
