// Memoized
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        std::vector<int> dp{};
        dp.reserve(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < n + 1; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// Also Memoized but makes more sense in my brain
class Solution {
public:
    int climbStairs(int n) {
        static std::unordered_map<int, int> dp;
        if (n <= 2) {
            dp.emplace(n,n);
            return n;
        }
        if (dp.find(n) != dp.end()) {
            return dp.find(n)->second;
        }
        auto val = climbStairs(n - 1) + climbStairs(n - 2);
        dp.emplace(n, val);
        return val;
    }
};
