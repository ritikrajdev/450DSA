int countTriplets(DLLNode* head, int x) {
    DLLNode* last = head;
    while (last->next)
        last = last->next;
    
    int c = 0;
    while (head->next->next) {
        DLLNode* i = head->next;
        while (i->next) {
            DLLNode* j = i->next;
            while (j) {
                if (i->data + j->data + head->data == x)
                    c++;
                j = j->next;
            }
            i = i->next;
        }
        head = head->next;
    }
    return c;
}
