// Objective: find two numbers that sum to target
// Key: use hashmap to keep track of values indices
// do subtraction to find complementary value
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target)
  {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i)
    {
      const int& num = nums[i];
      const int match = target - num;
      const auto& match_it = map.find(match);
      if (match_it != map.end())
      {
        return vector<int>{i, match_it->second};
      }
      else
      {
        map[num] = i;
      }
    }
    return vector<int>{};
  }
};
