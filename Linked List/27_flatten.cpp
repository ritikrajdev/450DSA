Node *flatten(Node *root)
{
    vector<int> v;
    Node* itr = root;
    while (itr) {
        Node* bottom = itr;
        while (bottom) {
            v.push_back(bottom->data);
            bottom = bottom->bottom;
        }
        itr = itr->next;
    }
    
    sort(v.begin(), v.end());
    for (auto x: v) {
        cout << x << ' ';
    }
    return 0;
}
