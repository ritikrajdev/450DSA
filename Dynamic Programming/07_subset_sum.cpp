class Solution{
    vector<vector<int>> t;
public:
    bool findSum(int N, int* arr, long long sum) {
        if (sum == 0)
            return 1;
        if (N == 0)
            return 0;
        
        if (t[sum][N] != -1)
            return t[sum][N];
        
        bool ans = 0;
        if (sum >= arr[N-1])
            ans = findSum(N-1, arr, sum - arr[N-1]);
    
        return t[sum][N] = (ans || findSum(N-1, arr, sum));
    }
    
    int equalPartition(int N, int arr[])
    {
        long long sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];

        if (sum & 1) return 0;
    
        t = vector<vector<int>>(sum+1, vector<int>(N+1, -1));
        return findSum(N, arr, sum/2);
    }
};
