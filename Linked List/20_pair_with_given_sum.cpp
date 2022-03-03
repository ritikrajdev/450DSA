bool findPair(Node* head, int k)
{
    Node *i = head, *j = head;
    while (j->next)
        j = j->next;
    
    while (i != j) {
        if (i->data + j->data > k)
            j = j->prev;
        else if (i->data + j->data < k)
            i = i->next;
        else return true;
    }
    return false;
}
