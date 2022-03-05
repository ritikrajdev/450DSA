vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    while (q.size()) {
        if (q.front()->right) q.push(q.front()->right);
        if (q.front()->left) q.push(q.front()->left);
        ans.push_back(q.front()->data);
        q.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
