#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

struct CC {
  char c;
  int count;

  CC(char _c, int _count) : c(_c), count(_count) {}
  bool operator<(const CC &cc) const { return count < cc.count; }
};

class Solution {
public:
  string frequencySort(string s) {
    unordered_map<char, int> char2count;
    priority_queue<CC, vector<CC>, less<CC>> q;

    for (auto c : s) {
      if (char2count.find(c) != char2count.end())
        char2count[c]++;
      else
        char2count[c] = 1;
    }

    for (auto it : char2count) {
      q.push(CC(it.first, it.second));
    }

    string res = "";
    while (q.size()) {
      int count = q.top().count;
      char c = q.top().c;
      while (count--)
        res += c;
      q.pop();
    }
    return res;
  }
};
