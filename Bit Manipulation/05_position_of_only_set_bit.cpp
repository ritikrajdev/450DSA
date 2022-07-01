class Solution {
  public:
    bool isPowerOfTwo(int N) {
        return N && !(N & (N-1));
    }
    int findPosition(int N) {
        return isPowerOfTwo(N) ? log2(N) + 1 : -1;
    }
};
