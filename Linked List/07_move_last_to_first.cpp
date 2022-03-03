typedef LinkedListNode<int> Node;
LinkedListNode<int>* moveToFront(LinkedListNode<int> *head) {
    if (!head->next)
        return head;

    Node* prev = 0;
    Node* itr = head;
    
    while (itr->next) {
        prev = itr;
        itr = itr->next;
    }

    prev->next = 0;
    itr->next = head;
    
    return itr;
}
