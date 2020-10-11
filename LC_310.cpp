#include <algorithm>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    if (n == 1)
      return vector<int>(1, 0);
    vector<vector<int>> graph(n, vector<int>());
    vector<int> degree(n, 0);
    vector<int> res;
    queue<int> q;

    for (size_t i = 0; i < edges.size(); ++i) {
      graph[edges[i][0]].push_back(edges[i][1]);
      graph[edges[i][1]].push_back(edges[i][0]);
      degree[edges[i][0]]++;
      degree[edges[i][1]]++;
    }

    for (int i = 0; i < n; ++i)
      if (degree[i] == 1)
        q.push(i);

    while (!q.empty()) {
      res.clear();
      int size = q.size();
      while (size--) {
        int front = q.front();
        res.push_back(front);
        q.pop();
        degree[front]--;
        vector<int> &ref = graph[front];
        for (size_t i = 0; i < ref.size(); ++i) {
          if (--degree[ref[i]] == 1)
            q.push(ref[i]);
        }
      }
    }

    return res;
  }
};

// class Solution {
// public:
// vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
// vector<vector<int>> graph(n, vector<int>());
// vector<bool> bitmap(n, false);
// vector<int> res;
// queue<int> q;

// for (size_t i = 0; i < edges.size(); ++i) {
// graph[edges[i][0]].push_back(edges[i][1]);
// graph[edges[i][1]].push_back(edges[i][0]);
// }

// int LEVEL = INT_MAX;
// for (int i = 0; i < n; ++i) {
// fill(bitmap.begin(), bitmap.end(), false);
// int level = 0;
// q.push(i);

// while (!q.empty()) {
// int size = q.size();
// while (size--) {
// int front = q.front();
// q.pop();
// if (bitmap[front])
// continue;
// bitmap[front] = true;
// vector<int> &ref = graph[front];
// for (size_t i = 0; i < ref.size(); ++i) {
// q.push(ref[i]);
// }
// }
// level++;
// }

// if (LEVEL == level)
// res.push_back(i);
// if (LEVEL > level) {
// LEVEL = level;
// res.clear();
// res.push_back(i);
// }
// }

// return res;
// }
// };
