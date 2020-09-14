#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  // 拓扑排序判断图是否有环
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    std::unordered_map<int, int> inTable; // 入度表
    std::unordered_map<int, std::vector<int>> mapTable;
    for (int i = 0; i < numCourses; ++i)
      inTable[i] = 0;

    for (auto &row : prerequisites) {
      inTable[row[0]]++;
      mapTable[row[1]].push_back(row[0]);
    }

    while (true) {
      bool exitFlag = true;
      for (auto &x : inTable) {
        if (x.second == 0) {
          exitFlag = false;
          x.second--;
          for (auto y : mapTable[x.first])
            inTable[y]--;
          mapTable.erase(x.first);
        }
      }
      if (exitFlag)
        break;
    }

    return mapTable.empty();
  }
};
