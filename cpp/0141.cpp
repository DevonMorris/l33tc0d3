// Using Unordered Set
class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> node_set;
        while (head != nullptr)
        {
            if (node_set.find(head) != node_set.end()) {
                return true;
            }
            node_set.emplace(head);
            head = head->next;
        }
        return false;
    }
};

// Constant Space Solution
