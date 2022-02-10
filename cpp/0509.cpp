// Top Down (Memoized)
class Solution {
public:
    int fib(int n) {
        static std::unordered_map<int, int> sols{};
        if (n < 2) {
            sols.emplace(n, n);
            return n;
        }
        if (sols.find(n) != sols.end()) {
            return sols.find(n)->second;
        }

        int fib_n = fib(n - 1) + fib(n - 2);
        sols.emplace(n, fib_n);
        return fib_n;
    }
};

// Bottom Up
class Solution {
public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }

        std::vector<int> fib_n(n+1, 0);
        fib_n[1] = 1;

        for (int i = 2; i <= n; ++i) {
            fib_n[i] = fib_n[i - 1] + fib_n[i-2];
        }
        return fib_n.back();
    }
};
