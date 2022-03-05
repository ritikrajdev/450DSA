class Solution
{
    public:
    vector<int> levelOrder(Node* node)
    {
        vector<int> ans;
        queue<Node*> q;
        q.push(node);
        while (q.size()) {
            if (q.front()->left) q.push(q.front()->left);
            if (q.front()->right) q.push(q.front()->right);
            ans.push_back(q.front()->data);
            q.pop();
        }
        return ans;
    }
};
