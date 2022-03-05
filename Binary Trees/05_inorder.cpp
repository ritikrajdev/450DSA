class Solution {
    vector<int> ans;
  public:
    void _inorder(Node* root) {
        if (root->left) _inorder(root->left);
        ans.push_back(root->data);
        if (root->right) _inorder(root->right);
    }

    vector<int> inOrder(Node* root) {
        _inorder(root);
        return ans;
    }
};
