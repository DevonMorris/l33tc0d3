struct Edge {
    int src;
    int dst;
    int weight;
};

struct Data {
    int node;
    int cost;
};

using Graph = std::unordered_map<int, std::vector<Edge>>;

bool operator>(const Data& d1, const Data& d2) {
    return d1.cost > d2.cost;
}

using Heap = std::priority_queue<Data, std::vector<Data>, std::greater<Data>>;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // initialization
        std::unordered_map<int, int> costs;
        Graph graph;
        for (int i = 1; i <= n; ++i) {
            costs[i] = std::numeric_limits<int>::max();
            graph[i] = {};
        }

        // construct graph
        for (const auto& time : times) {
            graph[time[0]].push_back({time[0], time[1], time[2]});
        }

        // prepare heap
        Heap heap;
        heap.push({k, 0});
        costs[k] = 0;

        // dijkstra
        while(!heap.empty()) {
            auto d = heap.top();
            heap.pop();
            for (const auto& edge : graph[d.node]) {
                if (costs[edge.dst] > costs[d.node] + edge.weight) {
                    heap.push({edge.dst, costs[d.node] + edge.weight});
                    costs[edge.dst] = costs[d.node] + edge.weight;
                }
            }
        }

        int totalTime = 0;
        for (const auto& cost : costs) {
            if (cost.second == std::numeric_limits<int>::max()) {
                return -1;
            }
            totalTime = std::max(totalTime, cost.second);
        }
        return totalTime;

    }
};
