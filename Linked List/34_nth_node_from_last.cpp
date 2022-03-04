typedef struct Node Node;

int length(Node* h) {
    int l = 0;
    while (h)
        l++, h = h->next;
    return l;
}

int getNthFromFirst(Node* head, int n) {
    while (head && --n)
        head = head->next;
    return head ? head->data : -1;
}

int getNthFromLast(struct Node *head, int n) {
    int l = length(head);
    return getNthFromFirst(head, l - n + 1);
}
