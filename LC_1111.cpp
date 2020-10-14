#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        int         depth = 0;
        for (auto &c : seq) {
            if (c == '(') {
                depth++;
                res.push_back(depth % 2);
            } else {
                res.push_back(depth % 2);
                depth++;
            }
        }
        return res;
    }
};
