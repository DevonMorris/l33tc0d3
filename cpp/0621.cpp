// First try with priority queue
struct Task {
    char id;
    int totalNum;
    int timeAvail;
};

bool operator<(const Task& t1, const Task& t2) {
    return t1.totalNum < t2.totalNum;
}


class Solution {
private:
    using TaskHeap = std::priority_queue<Task, std::vector<Task>, std::less<Task>>;
    using TaskQueue = std::queue<Task>;
public:
    int leastInterval(vector<char>& tasks, int n) {
        int totalTime = 0;
        TaskHeap heap;
        TaskQueue q;

        std::unordered_map<char, int> taskFreq;
        for (const char& c : tasks) {
            if (taskFreq.find(c) == taskFreq.end()) {
                taskFreq[c] = 0;
            }
            ++taskFreq[c];
        }
        for (const auto& it : taskFreq) {
            heap.push({it.first, it.second, 0});
        }

        while(!heap.empty() || !q.empty()) {
            ++totalTime;
            if (!heap.empty()) {
                auto task = heap.top();
                heap.pop();
                --task.totalNum;
                task.timeAvail = totalTime + n;
                if (task.totalNum > 0) {
                    q.push(task);
                }
            }

            while (!q.empty() && q.front().timeAvail <= totalTime) {
                auto task = q.front();
                q.pop();
                heap.push(task);
            }
        }
        return totalTime;

    }
};
