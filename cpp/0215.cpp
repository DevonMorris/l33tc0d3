class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int> heap;
        for (const auto& num : nums) {
            heap.push(num);
        }

        for (size_t i = 0; i < k - 1; ++i) {
            heap.pop();
        }
        return heap.top();
    }
};
