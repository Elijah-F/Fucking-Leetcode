#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// 拓扑排序判断是否存在环
class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> inDegrees(numCourses, 0);               // 建立入度表
    vector<vector<int>> lst(numCourses, vector<int>()); // 空间换时间

    for (auto &x : prerequisites) {
      inDegrees[x[0]]++;
      lst[x[1]].push_back(x[0]);
    }

    queue<int> q;
    for (int i = 0; i < numCourses; ++i)
      if (inDegrees[i] == 0)
        q.push(i);

    vector<int> res;
    while (!q.empty()) {
      int course = q.front();
      q.pop();
      res.push_back(course);
      for (auto x : lst[course]) {
        if (--inDegrees[x] == 0)
          q.push(x);
      }
    }
    return (res.size() == numCourses) ? res : vector<int>();
  }
};

// class Solution {
// private:
// bool bfs(vector<vector<int>> &grap, int firstCourse, vector<int> &res) {
// unordered_map<int, bool> visited;
// queue<int> q;
// q.push(firstCourse);
// visited[firstCourse] = true;
// res.push_back(firstCourse);
// while (!q.empty()) {
// int course = q.front();
// q.pop();
// for (auto x : grap[course]) {
// if (visited[x])
// continue;
// visited[x] = true;
// res.push_back(x);
// q.push(x);
// if (res.size() == grap.size())
// return true;
// }
// }
// return visited.size() == grap.size();
// }

// public:
// vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
// vector<vector<int>> grap(numCourses);
// for (auto x : prerequisites)
// grap[x[1]].push_back(x[0]);

// vector<int> res;
// for (int i = 0; i < numCourses; ++i) {
// res.clear();
// if (bfs(grap, i, res))
// return res;
// }
// return {};
// }
// };
