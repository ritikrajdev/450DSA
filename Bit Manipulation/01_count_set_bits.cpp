class Solution {
  public:
    int setBits(int N) {
        int c = 0;
        do {
            if (N&1) c++;
        } while (N = N>>1);
        return c;
    }
};
