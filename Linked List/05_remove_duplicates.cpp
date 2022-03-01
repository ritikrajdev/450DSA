Node *removeDuplicates(Node *head) {
    Node* itr = head;
    
    while (itr->next) {
        if (itr->data == itr->next->data) {
            Node* tmp = itr->next;
            itr->next = itr->next->next;
            delete tmp;
        } else
            itr = itr->next;
    }
    return head;
}
