class Solution {
 public:
  /* I had to look this one up to get O(1) spatial complexity and
   * O(log(n + m)) temporal complexity. I spent about a week thinking about it
   * and couldn't really think of a clean way to do it. I still don't think the
   * answer I found on geeks for geeks is really explained well, but here is
   * the reference.
   * https://www.geeksforgeeks.org/
   * median-two-sorted-arrays-different-sizes-ologminn-m/
   * Note: I added to this algorithm because there are edge cases, like out
   * of array indexing that this doesn't account for
   */
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
  {
    if (nums1.size() > nums2.size())
    {
      return findMedianSortedArrays(nums2, nums1);
    }
    int min_index = 0;
    int max_index = nums1.size();
    int i = 0;
    int j = 0;
    double median = 0;
    // Handle these special cases
    if (nums1.size() == 0)
    {
      return calculateMedian(nums2);
    }

    if (nums2.size() == 0)
    {
      return calculateMedian(nums1);
    }
    if (nums1.size() == 1 && nums2.size() == 1)
    {
      return (nums1[0] + nums2[0]) / 2.0;
    }

    while (min_index <= max_index)
    {
      i = (min_index + max_index) / 2;
      j = ((nums1.size() + nums2.size() + 1) / 2) - i;

      if (i < nums1.size() && j > 0 && nums2[j - 1] > nums1[i])
      {
        min_index = i + 1;
      }
      else if (i > 0 && j < nums2.size() && nums2[j] < nums1[i - 1])
      {
        max_index = i - 1;
      }
      else
      {
        if (i == 0)
        {
          median = nums2[j - 1];
        }
        else if (j == 0)
        {
          median = nums1[i - 1];
        }
        else
        {
          median = std::max(nums1[i - 1], nums2[j - 1]);
        }
        break;
      }
    }
    if ((nums1.size() + nums2.size()) % 2 == 1)
    {
      return median;
    }
    if (i == nums1.size())
    {
      return (median + nums2[j]) / 2.0;
    }
    if (j == nums2.size())
    {
      return (median + nums1[i]) / 2.0;
    }

    return (median + std::min(nums1[i], nums2[j])) / 2.0;
  }

  double calculateMedian(vector<int>& nums)
  {
    if (nums.size() % 2 == 0)
    {
      size_t i = nums.size() / 2;
      return (nums[i] + nums[i - 1]) / 2.0;
    }
    else if (nums.size() % 2 == 1)
    {
      size_t i = nums.size() / 2;
      return nums[i];
    }
    return 0;
  }
};

