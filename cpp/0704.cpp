class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        return search(nums, target, 0, nums.size() - 1);
    }

    int search(vector<int>& nums, int target, int start, int end) {
        if (nums[start] == target) {
            return start;
        }
        if (start == end || end < start) {
            return -1;
        }

        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] < target) {
            return search(nums, target, mid + 1, end);
        } else {
            return search(nums, target, start, mid - 1);
        }
        return -1;
    }
};
