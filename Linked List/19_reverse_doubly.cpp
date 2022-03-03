Node* reverseDLL(struct Node * head)
{
    Node* prev = 0;
    Node* itr = head;
    while (itr) {
        swap(itr->next, itr->prev);
        prev = itr;
        itr = itr->prev;
    }
    return prev;
}
