class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0;
        int max_fruits = 0;
        int fruits_in_window = 0;
        std::unordered_map<int, int> freq_in_window;
        for (int j = 0; j < fruits.size(); ++j) {
            if (freq_in_window.find(fruits[j]) == freq_in_window.end()) {
                freq_in_window[fruits[j]] = 0;
            }
            ++freq_in_window[fruits[j]];
            ++fruits_in_window;
            while (freq_in_window.size() > 2) {
                --freq_in_window[fruits[i]];
                --fruits_in_window;
                if (freq_in_window[fruits[i]] == 0) {
                    auto it = freq_in_window.find(fruits[i]);
                    freq_in_window.erase(it);
                }
                ++i;
            }
            max_fruits = std::max(max_fruits, fruits_in_window);
        }
        return max_fruits;
    }
};
