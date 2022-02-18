class Solution {
  public:
    int countSquares(int N) {
        int i = 0;
        int cnt = 0;

        while (++i) {
            if (i * i < N)
                cnt ++;
            else break;
        }
        
        return cnt;
    }
};
