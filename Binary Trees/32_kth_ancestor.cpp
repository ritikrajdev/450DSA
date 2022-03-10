#include<bits/stdc++.h>

int findKthAncestor(BinaryTreeNode<int> *root, int targetNodeVal, int k) {
    stack<BinaryTreeNode<int>*> st;
    st.push(root);
    
    while (!st.empty()) {
        auto itr = st.top();
        if (itr->data == targetNodeVal) {
            break;
        }
        
        if (itr->left) {
            st.push(itr->left);
            itr->left = 0;
        }
        else if (itr->right) {
            st.push(itr->right);
            itr->right = 0;
        } else st.pop();
    }

    while (k-- && !st.empty()) {
        st.pop();
    }

    if (!st.empty())
        return st.top()->data;
    else
        return -1;
}
