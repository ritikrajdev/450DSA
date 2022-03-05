class Solution:
    def min_index(self, arr):
        mn = 10**10
        mn_index = -1
        for i in range(len(arr)):
            if arr[i] and arr[i].data < mn:
                mn = arr[i].data
                mn_index = i
        return mn_index

    def mergeKLists(self, arr, K):
        merged = Node(0)
        m_itr = merged
        while any(arr):
            x = self.min_index(arr)
            m_itr.next = arr[x]
            arr[x] = arr[x].next
            m_itr = m_itr.next
            m_itr.next = None

        return merged.next
