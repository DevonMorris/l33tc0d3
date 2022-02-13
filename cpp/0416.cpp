class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.empty()) {
            return true;
        }
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;

        possible_sums.emplace(nums.front());
        possible_sums.emplace(0);
        for (int i = 1; i < nums.size(); ++i) {
            const int& num = nums[i];
            std::unordered_set<int> new_possible_sums{num};
            for (const int& sum : possible_sums) {
                new_possible_sums.emplace(sum + num);
            }
            possible_sums.insert(new_possible_sums.begin(), new_possible_sums.end());
            if (possible_sums.find(target) != possible_sums.end())
            {
                return true;
            }
        }
        return possible_sums.find(target) != possible_sums.end();

    }
    std::unordered_set<int> possible_sums;
};
