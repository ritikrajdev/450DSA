int length(Node* head) {
    // if (head->next == head)
    //     return 1;

    Node* itr = head;
    int l = 0;
    do {
        l++;
        itr = itr->next;
    } while (itr != head);
    
    return l;
}

void splitList(Node *head, Node **head1, Node **head2)
{
    int l = length(head);
    
    int n1 = (l + 1) / 2;
    int n2 = l / 2;
    
    Node* itr = head;
    while (--n1)
        itr = itr->next;

    Node* h2_start = itr->next;
    
    // Making it circular
    itr->next = head;
    
    itr = h2_start;
    while (--n2)
        itr = itr->next;

    itr->next = h2_start;

    *head1 = head;
    *head2 = h2_start;
}
