class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, [](Item l, Item r) {
            return (double) l.value / l.weight > (double) r.value / r.weight;
        });
        
        double profit = 0;
        for (int i = 0; i < n; i++) {
            auto item = arr[i];
            double w = min(W, item.weight);
            profit +=  (item.value * w) / item.weight;
            W -= w;
            
            if (W == 0)
                break;
        }

        return profit;
    }
};
