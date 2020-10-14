#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        if (intervals.empty()) return 0;
        std::sort(intervals.begin(), intervals.end(),
                  [](std::vector<int> &left, std::vector<int> &right) -> bool {
                      if (left[1] < right[1]) return true;
                      return false;
                  });

        int end = intervals[0][1], res = 0;
        for (size_t i = 1; i < intervals.size(); ++i) {
            while (i < intervals.size() && intervals[i][0] < end) {
                i++;
                res++;
            }
            if (i < intervals.size()) end = intervals[i][1];
        }
        return res;
    }
};
