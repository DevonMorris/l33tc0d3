/// BFS but slow
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        auto cheapestPrices = std::vector(n, std::numeric_limits<int>::max());
        cheapestPrices[src] = 0;

        std::queue<int> q;
        q.push(src);

        for (int i = 0; i < k + 1; ++i) {
            int q_size = q.size();
            auto newCheapestPrices = cheapestPrices;
            for (int j = 0; j < q_size; ++j) {
                int s = q.front();
                q.pop();
                for (const auto& flight : flights) {
                    int d = flight[1];
                    int price = flight[2];
                    if (flight[0] == s) {
                        q.push(d);
                        newCheapestPrices[d] = std::min(newCheapestPrices[d], price + cheapestPrices[s]);
                    }
                }
            }
            cheapestPrices = newCheapestPrices;
        }

        return cheapestPrices[dst] == std::numeric_limits<int>::max() ? -1 : cheapestPrices[dst];
    }
};

// Dijkstra still fails time limit
struct Data {
    int cost;
    int stops;
    int node;
};

struct Edge {
    int dst;
    int cost;
};

bool operator> (const Data& d1, const Data& d2) {
    return d1.cost > d2.cost;
}

class Solution {
public:
    using Graph = std::unordered_map<int, std::vector<Edge>>;
    using PriorityQ = std::priority_queue<Data, std::vector<Data>, std::greater<Data>>;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        Graph graph;
        for (int i = 0; i < n; ++i) {
            graph[i] = {};
        }
        for (const auto& flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }
        auto [minCost, nStops, finalDst] = dijkstra(graph, src, dst, k);
        if (finalDst != dst) {
            return -1;
        }
        return nStops > k ? -1 : minCost;
    }

    Data dijkstra(const Graph& graph, int src, int dst, int k)
    {
        PriorityQ pq;
        for (const auto& edge : graph.at(src)) {
            pq.push({edge.cost, 0, edge.dst});
        }

        while (!pq.empty()) {
            Data d = pq.top();
            pq.pop();
            if (d.node == dst && d.stops <= k) {
                return d;
            }
            for (const auto& edge : graph.at(d.node)) {
                if (d.stops < k) {
                    pq.push({edge.cost + d.cost, d.stops + 1, edge.dst});
                }
            }
        }
        return {-1, -1, -1};
    }
};

// Dijkstra but smarter (not adding certain edges)
struct Data {
    int cost;
    int stops;
    int node;
};

struct Edge {
    int dst;
    int cost;
};

bool operator> (const Data& d1, const Data& d2) {
    return d1.cost > d2.cost;
}

class Solution {
public:
    using Graph = std::unordered_map<int, std::vector<Edge>>;
    using PriorityQ = std::priority_queue<Data, std::vector<Data>, std::greater<Data>>;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        Graph graph;
        for (int i = 0; i < n; ++i) {
            graph[i] = {};
        }
        for (const auto& flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }
        auto [minCost, nStops, finalDst] = dijkstra(graph, n, src, dst, k);
        if (finalDst != dst) {
            return -1;
        }
        return nStops > k ? -1 : minCost;
    }

    Data dijkstra(const Graph& graph, int n, int src, int dst, int k)
    {
        PriorityQ pq;
        std::vector<int> minCosts(n, std::numeric_limits<int>::max());
        std::vector<int> minSteps(n, std::numeric_limits<int>::max());
        minCosts[src] = 0;
        minSteps[src] = 0;
        for (const auto& edge : graph.at(src)) {
            pq.push({edge.cost, 0, edge.dst});
        }

        while (!pq.empty()) {
            Data d = pq.top();
            pq.pop();
            if (d.node == dst && d.stops <= k) {
                return d;
            }
            for (const auto& edge : graph.at(d.node)) {
                int newCost = edge.cost + d.cost;
                int newSteps = d.stops + 1;
                if (d.stops < k && (newCost < minCosts[edge.dst] || newSteps < minSteps[edge.dst])) {
                    pq.push({newCost, d.stops + 1, edge.dst});
                    minCosts[edge.dst] = newCost;
                    minSteps[edge.dst] = newSteps;
                }
            }
        }
        return {-1, -1, -1};
    }
};
