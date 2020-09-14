#include <string>
#include <vector>
using namespace std;

class Solution1 {
public:
  // 动态规划版本
  int countSubstrings(string s) {
    int len = s.size();
    std::vector<std::vector<bool>> dp(len, std::vector<bool>(len, false));
    int res = 0;

    for (int j = 0; j < len; ++j) {
      for (int i = 0; i <= j; ++i) {
        if (s[i] == s[j] && (j - i < 2 || dp[j - 1][i + 1])) {
          dp[j][i] = true;
          res++;
        }
      }
    }

    return res;
  }
};

class Solution {
public:
  // 中心扩展法
  int countSubstrings(string s) {
    int len = s.size();
    int res = 0;
    for (int i = 0; i < len; ++i) {
      res++;
      int p = i - 1, q = i + 1;
      while (p >= 0 && q < len) {
        if (s[p] != s[q])
          break;
        res++;
        p--;
        q++;
      }
    }

    for (int i = 1; i < len; ++i) {
      if (s[i] != s[i - 1])
        continue;
      res++;
      int p = i - 2, q = i + 1;
      while (p >= 0 && q < len) {
        if (s[p] != s[q])
          break;
        res++;
        p--;
        q++;
      }
    }
    return res;
  }
};
