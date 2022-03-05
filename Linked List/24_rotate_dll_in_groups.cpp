vector<Node*> reverseDLL(Node* head, int k) {
    Node* itr = head;
    Node* rev = 0;
    while (itr && k--) {
        swap(itr->next, itr->prev);

        rev = itr;
        itr = itr->prev;
    }
    
    rev->prev = 0;
    if (itr) itr->prev = 0;
    
    // start, end, next
    return {rev, head, itr};
}

Node* reverseDLLInGroups(Node* head, int k)
{	
    if (k == 1)
        	return head;

    Node* reverse = new Node(0);
    Node* r_itr = reverse;
    
    Node* itr = head;
    while (itr) {
        auto start_end_next = reverseDLL(itr, k);
        r_itr->next = start_end_next[0];
        start_end_next[0]->prev = r_itr;
        
        r_itr = start_end_next[1];
        itr = start_end_next[2];
    }
    
    reverse = reverse->next;
    reverse->prev = 0;
    return reverse;
}
