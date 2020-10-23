#include <cmath>
#include <queue>
#include <vector>
using namespace std;

struct Com {
    bool operator()(std::pair<int, int> &left, std::pair<int, int> &right) {
        // 小于号: 大堆
        return (std::pow(left.first, 2) + std::pow(left.second, 2)) <
               (std::pow(right.first, 2) + std::pow(right.second, 2));
    }
};

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>,
                            Com>
            q;

        std::vector<vector<int>> res;

        for (size_t i = 0; i < points.size(); ++i) {
            if ((int)q.size() < K)
                q.push(make_pair(points[i][0], points[i][1]));
            else if ((int)q.size() >= K &&
                (std::pow(q.top().first, 2) + std::pow(q.top().second, 2) >
                 (std::pow(points[i][0], 2) + std::pow(points[i][1], 2)))) {
                q.pop();
                q.push(make_pair(points[i][0], points[i][1]));
            }
        }

        while (!q.empty()) {
            res.push_back({q.top().first, q.top().second});
            q.pop();
        }

        return res;
    }
};
