#include <iostream>
#include <string>
#include <vector>

#include "general.h"

using namespace std;

namespace ritik {
void generate_sentences(vector<vector<string>> &vec, int curr = -1,
                        string output = "") {
    if (curr == -1)
        curr = vec.size();

    if (curr == 0)
        cout << output << '\n';
    else {
        for (int i = 0; i < vec[curr - 1].size(); i++) {
            generate_sentences(vec, curr - 1, vec[curr - 1][i] + ' ' + output);
        }
    }
}
} // namespace ritik

int main() {
    vector<vector<string>> vec{
        {"you", "we"}, {"have", "are"}, {"sleep", "eat", "drink"}};
    ritik::generate_sentences(vec);
    return 0;
}
