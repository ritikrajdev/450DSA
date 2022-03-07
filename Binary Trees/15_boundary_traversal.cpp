class Solution {
    vector<int> v;
public:
    void left(Node* node) {
        if (!node)
            return;
        if (!node->left && !node->right)
            return;
        
        v.push_back(node->data);
        if (node->left)
            left(node->left);
        else
            left(node->right);
    }
    
    void right(Node* node) {
        if (!node)
            return;
        if (!node->left && !node->right)
            return;
        
        if (node->right)
            right(node->right);
        else
            right(node->left);
        v.push_back(node->data);
    }
    
    void leaf(Node* node) {
        if (!node) return;
        if (!node->left && !node->right) v.push_back(node->data);
        else {
            leaf(node->left);
            leaf(node->right);
        }
    }
    
    vector <int> boundary(Node *root)
    {
        v.push_back(root->data);
        left(root->left);
        leaf(root->left);
        leaf(root->right);
        right(root->right);

        return v;
    }
};
