class Solution{
    public:
    vector <int> zigZagTraversal(Node* root) {
        vector<vector<int>> v = {{}};
        queue <Node*> q;
        
        q.push(root);
        q.push(0);
        
        while (q.size() && q.front()) {
            while (q.front()) {
                Node* f = q.front();
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
                
                v.back().push_back(f->data);
                q.pop();
            }
            q.pop();
            q.push(0);
            v.push_back({});
        }
        
        for (int i = 1; i < v.size(); i+=2)
            reverse(v[i].begin(), v[i].end());
        
        vector<int> ans;
        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < v[i].size(); j++)
                ans.push_back(v[i][j]);
        
        return ans;
    }
};
