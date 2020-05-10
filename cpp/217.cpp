// First Solution
class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
      std::set<int> set_nums{};
      for (const auto& num : nums)
      {
        if(set_nums.count(num) > 0)
        {
          return true;
        }
        set_nums.emplace(num);
      }
      return false;
    }
};

// Second Solution
class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
      std::unordered_set<int> set_nums(nums.begin(), nums.end());
      return (set_nums.size() != nums.size());
    }
};
