#include <iostream>
#include <vector>
#include <string>

#include "general.h"

using namespace std;

namespace ritik {
    int twoWayPartition(vector<int>& array, int start, int end, int x) {
        if (start >= array.size() || end >= array.size())
            return -1;
            
        int i = start, j = end;
        while (i < array.size() && array.at(i) < x)
			i++;
        while (j >= 0 && array.at(j) >= x)
			j--;
        
        while (j > i) {
            if (array.at(i) >= x && array.at(j) < x)
                swap(array.at(i++), array.at(j--));
            else {
                if (array.at(i) < x) i++;
                if (array.at(j) >= x) j--;
            }
        }

        return i;
    }

    void threeWayPartition(vector<int>& array,int a, int b)
    {
        int k = twoWayPartition(array, 0, array.size()-1, a);
        twoWayPartition(array, k, array.size()-1, b+1);
    }
}

int main() {
	vector<int> vec {3, 2, 1};
	ritik::threeWayPartition(vec, 1, 2);
	cout << vec;
	return 0;
}
