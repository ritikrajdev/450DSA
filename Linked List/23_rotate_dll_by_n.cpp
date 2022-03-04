class Solution {
public:
    Node *update(Node *start,int p)
    {
        Node* itr = start;
        while (itr && --p)
            itr = itr->next;

        if (!itr && !itr->next)
            return start;
        
        Node* end = itr;
        
        while (end->next)
            end = end->next;
        
        end->next = start;
        start->prev = end;
        
        start = itr->next;
        start->prev = 0;
        itr->next = 0;
        
        return start;
    }
};
