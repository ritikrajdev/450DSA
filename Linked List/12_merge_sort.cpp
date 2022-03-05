class Solution{
  public:
    Node* mergeSort(Node* head) {
        vector<int> vec;
        Node* itr = head;
        while (itr) {
            vec.push_back(itr->data);
            itr = itr->next;
        }
        
        sort(vec.begin(), vec.end());

        int i = 0;
        itr = head;
        while (itr) {
            itr->data = vec[i++];
            itr = itr->next;
        }
        
        return head;
    }
};
