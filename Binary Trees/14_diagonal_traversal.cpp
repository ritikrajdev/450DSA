vector<int> diagonal(Node *root)
{
    vector<int> v;
    queue <Node*> q;
    q.push(root);
    
    while (q.size()) {
        Node* itr = q.front();
        while (itr) {
            v.push_back(itr->data);
            if (itr->left) q.push(itr->left);
            itr = itr->right;
        }
        q.pop();
    }
    return v;
}
