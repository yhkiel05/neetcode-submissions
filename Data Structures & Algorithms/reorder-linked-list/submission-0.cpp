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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next; // midpoint eventually
        }
        ListNode* second = slow->next;
        ListNode* prevSecond = slow->next = nullptr;
        while (second) {
            ListNode* temp = second->next;
            second->next = prevSecond;
            prevSecond = second;
            second = temp;
        } // reversed
        ListNode* first = head;
        second = prevSecond;
        while (second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        } 
    }
};
