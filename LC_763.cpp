#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> m;
        vector<int>              res;
        for (size_t i = 0; i < S.size(); ++i)
            m[S[i]] = i;

        size_t start = 0, end = 0;
        while (start < S.size()) {
            end = m[S[start]];
            for (size_t i = start + 1; i < end; ++i) {
                end = max(m[S[i]], (int)end);
            }
            res.push_back(end - start + 1);
            start = end + 1;
        }
        return res;
    }
};
