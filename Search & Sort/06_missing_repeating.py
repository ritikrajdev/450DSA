class Solution:
    def findTwoElement( self,arr, n): 
        repeating = -1;
        sm = 0;
        for i in range(n):
            x = abs(arr[i])
            sm += x;
            if arr[x-1] < 0:
                repeating = x
            arr[x-1] = -arr[x-1]

        missing = (n*(n+1)//2) - sm + repeating
        ans = [repeating, missing]
        return ans
