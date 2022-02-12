int count_less_than(int c, int* v, int n) {
    int l = 0, r = n - 1;
    int m = 0;

    while (l <= r) {
        m = (l + r) / 2;
        if (v[m] > c) r = m - 1;
        else l = m + 1;
    }

    return l;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int elm = 1;
    
    while (elm <= 10000) {
        int sm = 0;
        for (int i = 0; i < n; i++) {
            sm += count_less_than(elm, mat[i], n);
        }
        if (sm >= k)
            return elm;
        elm ++;
    }
}

