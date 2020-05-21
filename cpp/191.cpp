// My solution
class Solution {
  public:
    int hammingWeight(uint32_t n) {
      int hamming_dist = 0;
      for(size_t i = 0; i < 32; ++i)
      {
        uint32_t digit = (1ul << i) & n;
        if (digit != 0)
        {
          ++hamming_dist;
        }
      }
      return hamming_dist;
    }
};

// The cleanest (but cheating) solution
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};
