#include <stack>

using namespace std;

class Solution {
    int maxAreaHistogram(int *histogram, int n) {
        int maxArea = 0;
        stack<int> inc;
        int right[n];

        for (int i = n - 1; i >= 0; i--) {
            if (inc.empty())
                right[i] = n;
            else {
                while (!inc.empty() && histogram[inc.top()] >= histogram[i])
                    inc.pop();
                if (inc.empty())
                    right[i] = n;
                else
                    right[i] = inc.top();
            }
            inc.push(i);
        }

        while (!inc.empty())
            inc.pop();

        for (int i = 0; i < n; i++) {
            int l = i - 1;
            int r = i;

            if (inc.empty())
                l = -1;
            else {
                while (!inc.empty() && histogram[inc.top()] >= histogram[i])
                    inc.pop();
                if (inc.empty())
                    l = -1;
                else
                    l = inc.top();
            }
            inc.push(i);

            r = right[i];

            int area = (r - l - 1) * histogram[i];
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }

    int customSum(int *a1, int *a2, int n) {
        for (int i = 0; i < n; i++)
            a1[i] = a2[i] == 0 ? 0 : a2[i] + a1[i];
    }

  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int histogram[m] = {0};

        int maxAreaRect = 0;
        for (int i = 0; i < n; i++) {
            customSum(histogram, M[i], m);
            maxAreaRect = max(maxAreaRect, maxAreaHistogram(histogram, m));
        }
        return maxAreaRect;
    }
};
