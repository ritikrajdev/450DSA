class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, [](Job l, Job r) {
            return l.profit > r.profit;
        });
        
        vector<bool> slot(n,0);
        int profit = 0;
        int c = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
                if (!slot[j]) {
                    slot[j] = 1;
                    profit += arr[i].profit;
                    c++;
                    break;
                }
            }
        }
        
        return {c, profit};
    } 
};
