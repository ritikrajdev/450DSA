#include <iostream>
#include <vector>
#include <string>

#include "general.h"

using namespace std;

namespace ritik {
	bool isPalindrome(const string& S)
	{
	    size_t i = 0, j = S.size() - 1;
	    while (i < j)
	        if (S.at(i++) != S.at(j--))
	            return false;
	   return true;
	}
}

int main() {
	string S = "abba";
	cout << ritik::isPalindrome(S);
	return 0;
}
