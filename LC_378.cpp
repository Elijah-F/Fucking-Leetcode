#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    priority_queue<int, vector<int>, less<int>> q;

    for (size_t i = 0; i < matrix.size(); ++i) {
      for (size_t j = 0; j < matrix[0].size(); ++j) {
        if (q.size() < k)
          q.push(matrix[i][j]);
        else if (q.top() > matrix[i][j]) {
          q.pop();
          q.push(matrix[i][j]);
        }
      }
    }

    return q.top();
  }
};
