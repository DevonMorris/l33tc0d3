/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


// Solution 1, using call stack & recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* new_head = reverseList(head, head->next);
        head->next = nullptr;
        return new_head;
    }

    ListNode* reverseList(ListNode* head, ListNode* next) {
        if (next == nullptr) {
            return head;
        }

        ListNode* new_head = reverseList(next, next->next);
        next->next = head;
        return new_head;
    }
};

// Solution 2, using iteration
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};

// Solution 3, using a stack
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        std::stack<ListNode*> stack;
        ListNode* current = head;
        while (current != nullptr) {
            stack.push(current);
            current = current->next;
        }

        ListNode* new_head = stack.top();
        while (!stack.empty()) {
            ListNode* node = stack.top();
            stack.pop();
            node->next = stack.empty() ? nullptr : stack.top();
        }
        return new_head;
    }
};
