// Brute force O(n^2)
class Solution {
  public:
    int maxArea(vector<int>& height) {
      int max_area = 0;
      for (int i = 0; i < height.size(); ++i)
      {
        for (int j = 0; j < height.size(); ++j)
        {
          const int area = abs(i - j) * min(height[i], height[j]);
          if (area > max_area)
          {
            max_area = area;
          }
        }
      }
      return max_area;
    }
};

// Smarter solution O(n)
class Solution {
  public:
    int maxArea(vector<int>& height) {
      int max_area = 0;
      int i = 0;
      int j = height.size() - 1;
      while (j > i)
      {
        int area = abs(j - i) * min(height[i], height[j]);
        if (area > max_area)
        {
          max_area = area;
        }
        if (height[i] > height[j])
        {
          --j;
        }
        else
        {
          ++i;
        }
      }
      return max_area;
    }
};
