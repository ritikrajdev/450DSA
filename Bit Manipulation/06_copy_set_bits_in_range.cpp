class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        int all_zeros_after_l = ~((1 << (l-1)) - 1); // 111L00000
        int all_ones_before_r = r == 32 ? 0 : ~((1 << r) - 1); // 111R000
        int required_bits_all_1 = all_zeros_after_l ^ all_ones_before_r;
        
        return x | (y & required_bits_all_1);
    }
};
