// Top Down
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return findTargetSumWays(nums, 0, target);
    }

    int findTargetSumWays(vector<int>& nums, int i, int target) {
        long long key = i * 0xdeadbeef + target;
        if (m_dp.find(key) != m_dp.end()) {
            return m_dp[key];
        }

        if (i == nums.size()) {
            if (target == 0){
                return 1;
            } else {
                return 0;
            }
        }

        int num = findTargetSumWays(nums, i + 1, target - nums[i]) + findTargetSumWays(nums, i + 1, target + nums[i]);
        m_dp[key] = num;
        return m_dp[key];
    }

    std::unordered_map<long long, int> m_dp;
};

// Bottom Up
