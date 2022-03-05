#include <vector>
#include <algorithm>

typedef struct node Node;

void quickSort(struct node **head) {
    vector<int> vec;
    Node* itr = *head;
    while (itr) {
        vec.push_back(itr->data);
        itr = itr->next;
    }
    
    sort(vec.begin(), vec.end());

    int i = 0;
    itr = *head;
    while (itr) {
        itr->data = vec[i++];
        itr = itr->next;
    }
}
