#include <string>

using namespace std;

int countRev (string s) {
	if (s.size() & 1)
        return -1;
    
    int open = 0, close = 0;
    for (auto x: s) {
        if (x == '{')
            open++;
        else
            open--;
        
        if (open < 0)
            close++, open = 1;
    }

    return close + open / 2;
}
