class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::vector<int> stack;
        for (const auto& asteroid : asteroids) {
            if (stack.empty() || asteroid > 0) {
                stack.push_back(asteroid);
                continue;
            }

            // collision detected
            while (!stack.empty() && stack.back() > 0 && stack.back() < std::abs(asteroid)) {
                stack.pop_back();
            }
            if (stack.empty()) {
                stack.push_back(asteroid);
                continue;
            }
            if (stack.back() < 0) {
                stack.push_back(asteroid);
            } else {
                if (stack.back() == std::abs(asteroid)) {
                    stack.pop_back();
                }
            }

        }
        return stack;
    }
};
