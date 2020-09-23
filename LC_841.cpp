#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
  void dfs(vector<vector<int>> &rooms, unordered_map<int, bool> &visited,
           int cur) {
    if (visited[cur])
      return;
    visited[cur] = true;
    for (auto x : rooms[cur])
      dfs(rooms, visited, x);
  }

public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    unordered_map<int, bool> visited;
    dfs(rooms, visited, 0);
    return visited.size() == rooms.size();
  }
};

// class Solution {
// public:
// bool canVisitAllRooms(vector<vector<int>> &rooms) {
// std::queue<int> q;
// std::unordered_map<int, bool> visited;
// q.push(0);
// visited[0] = true;

// while (!q.empty()) {
// int index = q.front();
// q.pop();
// for (auto x : rooms[index]) {
// if (visited[x])
// continue;
// q.push(x);
// visited[x] = true;
// }
// }

// return visited.size() == rooms.size();
// }
// };
