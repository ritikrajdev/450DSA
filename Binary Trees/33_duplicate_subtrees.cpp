const string x = "x";
vector<Node*> v;
unordered_map<string, int> ump;

string findDuplicateSubTrees(Node* root) {
    
    if (!root)
        return "";
    
    string tree = to_string(root->data);
    
    tree += x + findDuplicateSubTrees(root->left);
    tree += x + findDuplicateSubTrees(root->right);
    
    if (ump[tree] == 1)
        v.push_back(root);
    
    ump[tree] ++;

    return tree;
}

vector<Node*> printAllDups(Node* root) {
    v.clear();
    ump.clear();
    
    findDuplicateSubTrees(root);
    return v;
}
