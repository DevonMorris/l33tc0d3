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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        if (head->next == nullptr) {
            return false;
        }
        ListNode* tortoise = head;
        ListNode* hare = head->next;

        while (tortoise != nullptr && hare != nullptr) {
            if (tortoise == hare) {
                return true;
            }

            tortoise = tortoise->next;
            hare = hare->next;
            if (hare == nullptr) {
                return false;
            }
            hare = hare->next;
        }
        return false;
    }
};
