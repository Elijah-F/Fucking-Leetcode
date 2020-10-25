#include <iostream>
#include <string>
using namespace std;

class Solution {
  private:
    bool isDigit(char arg) { return arg <= '9' && arg >= '0'; }

    std::string helper(std::string &s, size_t pos) {
        if (pos >= s.size()) return "";
        std::string res;
        while (pos < s.size()) {
            if (!isDigit(s[pos])) {
                if (s[pos] == ']') return res;
                res += s[pos++];
            } else {
                int times = std::atoi(s.c_str() + pos);
                while (s[pos++] != '[')
                    ;
                std::string child = helper(s, pos);
                while (times--)
                    res += child;
                size_t left = 0;
                while (s[pos] != ']' || left != 0) {
                    if (s[pos] == '[')
                        left++;
                    else if (s[pos] == ']')
                        left--;
                    pos++;
                }
                pos++;
            }
        }
        return res;
    }

  public:
    string decodeString(string s) {
        if (s.empty()) return s;
        return helper(s, 0);
    }
};

int main() {
    Solution s;
    // std::string r   = "000111abc";
    // size_t      pos = 1;
    // std::cout << stoi(r, &pos, 2) << "   pos:" << pos << std::endl;
    std::cout << s.decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef") << std::endl;
    return 0;
}
