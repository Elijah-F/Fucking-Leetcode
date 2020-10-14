#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        std::sort(people.begin(), people.end(),
                  [](std::vector<int> &left, std::vector<int> &right) -> bool {
                      if (left[0] > right[0])
                          return true;
                      else if (left[0] < right[0])
                          return false;
                      else if (left[1] < right[1])
                          return true;
                      return false;
                  });

        vector<vector<int>> res(people.size());
        for (auto &v : people) {
            auto it = res.begin();
            for (int k = 0; k < v[1]; ++k)
                it++;
            res.insert(it, v);
        }
        res.resize(people.size());
        return res;
    }
};
