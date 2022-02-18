class Solution {
public:
    bool isPalindrome(int x) {
        std::string x_str = std::to_string(x);
        std::string x_str_rev = x_str;
        std::reverse(x_str_rev.begin(), x_str_rev.end());
        return x_str == x_str_rev;
    }
};
