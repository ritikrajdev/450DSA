class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        unordered_map<int, bool> exists;

        Node* itr = head;
        exists[itr->data] = 1;

        while (itr->next) {
            if (exists[itr->next->data])
                itr->next = itr->next->next;
            else {
                exists[itr->next->data] = 1;
                itr = itr->next;
            }
        }
        
        return head;
    }
};
