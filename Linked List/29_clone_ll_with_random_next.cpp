class Solution
{
    public:
    Node* copyList(Node *head)
    {
        Node* x = new Node(0);
        Node* i = x;
        
        unordered_map<Node*, Node*> ump;
        ump[NULL] = NULL;
        
        while (head) {
            i->next = new Node(head->data);
            i = i->next;
            
            ump[head] = i;
            
            i->arb = head->arb;
            
            head = head->next;
        }

        i = x->next;
        while (i) {
            i->arb = ump[i->arb];
            i = i->next;
        }
        
        return x->next;
    }
};
