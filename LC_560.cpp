#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        std::unordered_map<int, int> mp = {{0, 1}};

        int pre = 0, res = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            pre += nums[i];
            if (mp.find(pre - k) != mp.end()) res += mp[pre - k];
            // 直接++，默认值是0？
            mp[pre]++;
        }

        return res;
    }
};
