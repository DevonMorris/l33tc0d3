// The non-cheating way
class Solution {
  public:
    vector<int> countBits(int num) {
      if (num == 0)
      {
        return {0};
      }
      if (num == 1)
      {
        return {0, 1};
      }
      vector<int> zeros{0, 1};
      int prev_one_idx = 1;
      int copy_idx = 1;
      for (int i = 2; i <= num; ++i)
      {
        if (copy_idx < prev_one_idx)
        {
          zeros.push_back(1 + zeros[copy_idx]);
          ++copy_idx;
        }
        else
        {
          zeros.push_back(1);
          copy_idx = 1;
          prev_one_idx = i;
        }
      }
      return zeros;
    }
};

// The cheating way
class Solution {
  public:
    vector<int> countBits(int num) {
      vector<int> zeros{};
      for (int i = 0; i <= num; ++i)
      {
        zeros.push_back(__builtin_popcount(i));
      }
      return zeros;
    }
};

