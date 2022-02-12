class Solution{
    int count_less_than(int c, vector<int> &v) {
        int l = 0, r = v.size() - 1;
        int m = 0;

        while (l <= r) {
            m = (l + r) / 2;
            if (v[m] > c) r = m - 1;
            else l = m + 1;
        }

        return l;
    }
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        int median = 1;
        int num_leave_elements = r * c / 2;
		// Can be optimised using binary search again but no need as it is accepted, O(2000 * r * log(c))
        while (median <= 2000) {
            int sm = 0;
            for (int i = 0; i < r; i++) {
                sm += this->count_less_than(median, matrix[i]);
            }
            
            if (sm > num_leave_elements) {
                return median;
            }
            median ++;
        }
    }
};
