vector<int> ans;

void _leftView(Node* root, int depth) {
    if (!root) return;

    if (depth == ans.size())
        ans.push_back(root->data);

    _leftView(root->left, depth + 1);
    _leftView(root->right, depth + 1);
}

vector<int> leftView(Node *root)
{
    _leftView(root, 0);
   vector<int> a = ans;
   ans.clear();
   return a;
}
