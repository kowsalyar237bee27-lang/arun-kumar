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
        ListNode* dummyHead = new ListNode(0); // Temporary head to simplify logic
        ListNode* curr = dummyHead;
        int carry = 0;

        // Loop until both lists are empty and there is no remaining carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            
            int sum = carry + x + y;
            carry = sum / 10; // Extract the carry (1 if sum >= 10, else 0)
            
            // Create a new node with the single digit (sum % 10)
            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            // Advance the input list pointers
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead; // Standard practice to free the dummy node
        return result;
    }
};
