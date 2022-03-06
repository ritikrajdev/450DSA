pair<int, int> largestSubtreeSumm(TreeNode<int> *root) {
    pair<int, int> l = {0, INT_MIN};
    pair<int, int> r = {0, INT_MIN};

    if (root->left)
    	l = largestSubtreeSumm(root->left);
    if (root->right)
    	r = largestSubtreeSumm(root->right);
    
    // returns -> sum so far, largest
    return {
        l.first + r.first + root->data,
        max({l.first + r.first + root->data, l.second, r.second})
    };
}

int largestSubtreeSum(TreeNode<int> *root) {
	return largestSubtreeSumm(root).second;
}
