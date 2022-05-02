class Solution{
    unordered_map<long long, int> freq = {{0, 1}};
  public:

    int sumK(Node *root,int k, int sum = 0)
    {
        if (!root)
            return 0;
        
        int c = 0;

        sum += root->data;
        if (freq[sum-k]) c += freq[sum-k];
        
        freq[sum]++;
        c += sumK(root->left, k, sum) + sumK(root->right, k, sum);
        freq[sum]--;
        
        return c;
    }
};
