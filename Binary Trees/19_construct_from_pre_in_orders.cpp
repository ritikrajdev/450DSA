class Solution{
    public:
    Node* build(int in[], int i1, int i2, int pre[], int p1, int p2) {
        Node* node = new Node(pre[p1]);

        int node_location;
        for (node_location = i1; node_location <= i2; node_location++) {
            if (in[node_location] == pre[p1])
                break;
        }
        
        int num_nodes_left = node_location - i1;
        int num_nodes_right = i2 - i1 - num_nodes_left;
        
        if (num_nodes_left > 0)
            node->left = build(in, i1, node_location - 1, pre, p1 + 1, p1 + num_nodes_left);
        if (num_nodes_right > 0)
            node->right = build(in, node_location + 1, i2, pre, p1 + num_nodes_left + 1, p2);
        
        return node;
    }

    Node* buildTree(int in[],int pre[], int n) {
        return build(in, 0, n-1, pre, 0, n-1);
    }
};
