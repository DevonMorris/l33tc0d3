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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first = nullptr;
        ListNode** node = &first;
        int sum = 0;
        while (l1 != nullptr || l2 != nullptr || sum > 0)
        {
            // Dereference some boys
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            (*node) = new ListNode(sum % 10);
            sum /= 10;
            node = &((*node)->next);
        }
        return first;
    }
};

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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }
        int carry = 0;
        int new_val = l1->val + l2->val;
        if (l1->val + l2->val > 9) {
            carry = new_val / 10;
            new_val = new_val % 10;
        }
        l1 = l1->next;
        l2 = l2->next;
        ListNode* head = new ListNode(new_val);
        ListNode* prev_node = head;
        ListNode* node = nullptr;

        while (l1 != nullptr || l2 != nullptr) {
            int val1 = l1 == nullptr ? 0 : l1->val;
            int val2 = l2 == nullptr ? 0 : l2->val;
            node = new ListNode(0);
            prev_node->next = node;
            new_val = val1 + val2 + carry;
            carry = 0;
            if (new_val > 9) {
                carry = new_val / 10;
                new_val = new_val % 10;
            }
            node->val = new_val;
            prev_node = node;
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }

        if (carry != 0) {
            node = new ListNode(carry);
            prev_node->next = node;
            prev_node = node;
        }

        return head;
    }
};
