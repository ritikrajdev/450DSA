class Solution{
public:
    int inSequence(int A, int B, int C){
        if (C == 0) return A == B;
        if (B > A && C < 0) return false;
        if (B < A && C > 0) return false;
        return (B - A) % C == 0;
    }
};
