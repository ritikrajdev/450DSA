class Solution
{
public:
    pair<int, int> max(pair<int, int>  l, pair<int, int>  r) {
        if (l.first > r.first)
            return l;
        else if (r.first > l.first)
            return r;
        else
            return r.second > l.second ? r : l;
    }
    
    pair<int, int> helper(Node* root) {
        if (!root)
            return {0, 0};

        auto l = helper(root->left);
        auto r = helper(root->right);
        
        auto mx = max(l, r);
        mx.first += 1;
        mx.second += root->data;
        return mx;
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        return helper(root).second;
    }
};
