class Solution
{
    pair <Node*, Node*> toDLL(Node* node) {
        if(!node->left && !node->right)
            return {node, node};
        
        pair<Node*, Node*> start_end = {node, node};

        if (node->left) {
            auto l = toDLL(node->left);
            if (l.first) {
                l.second->right = node;
                node->left = l.second;
                start_end.first = l.first;
            }
        }
        
        if (node->right) {
            auto r = toDLL(node->right);
            if (r.first) {
                node->right = r.first;
                r.first->left = node;
                start_end.second = r.second;
            }
        }
            
        // first, last
        return start_end;
    }
    public:
    Node* bToDLL(Node *root) {
        return toDLL(root).first;
    }
};
