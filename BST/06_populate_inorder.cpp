class Solution
{
public:
    Node* prev = 0;
    void populateNext(Node *root)
    {
        if (!root) return;
        populateNext(root->left);
        if (prev)
            prev->next = root;
        prev = root;
        populateNext(root->right);
    }
};
