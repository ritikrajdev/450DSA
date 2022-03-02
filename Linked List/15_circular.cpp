bool isCircular(Node *head)
{
    Node* itr = head;
    while (itr) {
        itr = itr->next;
        if (itr == head)
            return true;
    }
    return false;
}
