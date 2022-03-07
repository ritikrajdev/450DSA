class Solution
{
    vector<int> left;
    vector<int> right;
    public:
    
    void leftTopView(Node* root, int vertical_level) {
        if (!root)
            return;
        
        if (vertical_level == -left.size())
            left.push_back(root->data);
        
        leftTopView(root->left, vertical_level-1);
        leftTopView(root->right, vertical_level+1);
    }
    
    void rightTopView(Node* root, int vertical_level) {
        if (!root)
            return;
        
        if (vertical_level == right.size())
            right.push_back(root->data);
        
        rightTopView(root->right, vertical_level+1);
        rightTopView(root->left, vertical_level-1);
    }


    vector<int> topView(Node *root) {
        leftTopView(r, 0);
        rightTopView(r, 0);

        reverse(left.begin(), left.end());

        // 0th will be root
        for (int i = 1; i < right.size(); i++)
            left.push_back(right[i]);

        return left;
    }
};
