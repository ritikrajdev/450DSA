int length(Node* head) {
    int c = 0;
    while (head)
        c++, head = head->next;
    return c;
}

int intersectPoint(Node* head1, Node* head2) {
    int l1 = length(head1);
    int l2 = length(head2);
    
    if (l1 < l2)
        return intersectPoint(head2, head1);
    
    int c = l1 - l2;
    
    while (c--)
        head1 = head1->next;
    
    c = 0;
    while (head1 && head2 && head1 != head2)
        head1 = head1->next, head2 = head2->next, c++;
    
    if (head1 && head2)
        return head1->data;
    else
        return -1;
}
