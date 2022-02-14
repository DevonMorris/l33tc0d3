// My solution
class Solution {
public:
    bool judgeSquareSum(int c) {
        std::unordered_set<long long> mem;
        long long i = 0;
        while (i * i <= c) {
            mem.emplace(i * i);
            long long target = c - i * i;
            if(mem.find(target) != mem.end()) {
                return true;
            }

            ++i;
        }
        return false;
    }
};
