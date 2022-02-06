class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k > nums.size()) {
            return {};
        }
        if (nums.empty()) {
            return {};
        }
        std::vector<int> result;
        std::deque<size_t> window;

        for (size_t i = 0; i < k; ++i) {
            while(!window.empty() && nums[window.back()] < nums[i]) {
                window.pop_back();
            }
            window.push_back(i);
        }
        result.push_back(nums[window.front()]);

        for (size_t i = k; i < nums.size(); ++i) {
            while(!window.empty() && nums[window.back()] < nums[i]) {
                window.pop_back();
            }

            if (!window.empty() && window.front() <= i - k) {
                window.pop_front();
            }
            window.push_back(i);
            result.push_back(nums[window.front()]);
        }
        return result;
    }
};
