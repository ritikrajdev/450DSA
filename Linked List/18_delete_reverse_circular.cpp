typedef struct Node Node;
void deleteNode(struct Node **head, int key)
{
    Node *prev = 0, *h = *head;
    if (h->next == h)
        *head = 0;

    if (h->data != key) {
        while (h && h->data != key) {
            prev = h;
            h = h->next;
        }
        prev->next = h->next;
    }
    else {
        do {
            prev = h;
            h = h->next;
        } while (h != *head);
        prev->next = h->next;
        *head = prev->next;
    }
}

Node* last(Node* h) {
    auto itr = h;
    while (itr->next != h)
        itr = itr->next;
    return itr;
}

/* Function to reverse the linked list */
 void reverse(struct Node** head)
{
    Node* h = *head;
    Node* rev = last(h);

    do {
        Node* curr = h;
        h = h->next;
        curr->next = rev;
        rev = curr;
    } while (h != *head);

    *head = rev;
}
