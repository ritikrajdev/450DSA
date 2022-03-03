Node *sortedDll(Node *head, int k)
{
    priority_queue<int> q;
    Node* tmp = new Node(0);
    Node* answer = tmp;

    while (head) {
        q.push(head->data);
        if (q.size() > k+1) {
            int max = q.top();
            q.pop();
            
            answer->prev = new Node(max);
            answer->prev->next = answer;
            answer = answer->prev;
        }
        head = head->next;
    }
    
    while (q.size()) {
        int max = q.top();
        q.pop();
        answer->prev = new Node(max);
        answer->prev->next = answer;
        answer = answer->prev;
    }
    
    tmp->prev->next = 0;
    return answer;
}
