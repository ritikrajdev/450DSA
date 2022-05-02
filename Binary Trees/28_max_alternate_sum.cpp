class Solution{
    unordered_map<Node*, int> memory;
  public:
    int getMaxSum(Node *root) 
    {
        if (!root) return 0;
        
        if (memory[root]) return memory[root];

        int excluding_sum = 0, including_sum = root->data;

        // Includes
        if (root->left)
            including_sum += getMaxSum(root->left->left) + getMaxSum(root->left->right);
        if (root->right)
            including_sum += getMaxSum(root->right->left) + getMaxSum(root->right->right);

        // Excludes
        excluding_sum += getMaxSum(root->left) + getMaxSum(root->right);
        
        return memory[root] = max(including_sum, excluding_sum);
    }
};
