// Top Down
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        return maxAlternatingSum(nums, 0, true);
    }

    long long maxAlternatingSum(vector<int>& nums, int i, bool isAdd) {
        if (i == nums.size()) {
            return 0;
        }
        long long key = isAdd ? i : i + 0xdeadbeef;
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        int delta = isAdd ? nums[i] : -1 * nums[i];
        dp[key] = std::max(delta + maxAlternatingSum(nums, i+1, !isAdd), maxAlternatingSum(nums, i+1, isAdd));
        return dp[key];
    }
    std::unordered_map<long long, long long> dp;
};

// Bottom Up
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long max_add = 0;
        long long max_sub = 0;

        for (const int& num : nums) {
            long long a = max_add + num;
            long long b = max_sub - num;

            max_sub = std::max(max_sub, a);
            max_add = std::max(max_add, b);
        }
        return std::max(max_sub, max_add);
    }
};
