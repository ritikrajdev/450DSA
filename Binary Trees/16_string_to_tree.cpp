#include<bits/stdc++.h>
#define Node BinaryTreeNode<int>

BinaryTreeNode<int>* treeFromBracket(string &s)
{
    Node* root = new Node(s[0] - '0');
    
    stack<Node*> st;
    st.push(root);
    int i = 1;
    unordered_map<Node*, bool> left_processed;
    while (i < s.size()) {
        if (s[i] == '(') {
            i++;
            if (isdigit(s[i]))
            	st.push(new Node(s[i++] - '0'));
            else
                st.push(0);
		} else {
            Node* t = st.top();
            st.pop();
            if (left_processed[st.top()])
                st.top()->right = t;
            else
            	st.top()->left = t, left_processed[st.top()] = 1;
            i++;
        }
	}
	return root;
}
