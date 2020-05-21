class Solution {
  public:
    uint32_t reverseBits(uint32_t n) {
      uint32_t output = 0;
      for (int i = 0; i < 16; ++i)
      {
        output |= ((1ul << i) & n) << (31 - 2 * i);
        output |= ((1ul << (31 - i)) & n) >> (31 - 2 * i);
      }
      return output;
    }
};
