class Solution
{
    public:
    vector<int> topView(Node *root) {
        map<int, Node*> mp;
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        while (!q.empty()) {
            if (!mp[q.front().second])
                mp[q.front().second] = q.front().first;
            if (q.front().first->left) q.push({q.front().first->left, q.front().second-1});
            if (q.front().first->right) q.push({q.front().first->right, q.front().second+1});
            q.pop();
        }
        
        vector<int> ans;
        for (auto x: mp)
            ans.push_back(x.second->data);
        
        return ans;
    }
};
