Node* findIntersection(Node* head1, Node* head2)
{
    Node *head = new Node(0);
    Node *itr1 = head1, *itr2 = head2, *itr = head;
    
    while (itr1 && itr2) {
        int i = itr1->data, j = itr2->data;
        if (i == j) {
            itr->next = new Node(i);
            itr = itr->next;
            itr1 = itr1->next;
            itr2 = itr2->next;
        }
        else if (i < j) itr1 = itr1->next;
        else itr2 = itr2->next;
    }
    
    return head->next;
}
