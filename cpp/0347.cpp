struct Node {
    int num;
    int freq;
};

bool operator>(Node const& node1, Node const& node2) {
    return node1.freq > node2.freq;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, Node> nodes;
        for (const auto& num : nums) {
            if (nodes.find(num) == nodes.end()) {
                nodes[num] = {num, 0};
            }
            ++nodes[num].freq;
        }

        std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;

        for (const auto& node : nodes) {
            if (pq.size() < k) {
                pq.push(node.second);
                continue;
            }

            if (node.second.freq > pq.top().freq) {
                pq.pop();
                pq.push(node.second);
            }
        }

        std::vector<int> out;
        while (!pq.empty()) {
            out.push_back(pq.top().num);
            pq.pop();
        }
        return out;
    }
};
