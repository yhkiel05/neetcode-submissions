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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* node = &dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                node->next = list1; // start of list1 to end
                list1 = list1->next; // now we go to next element
            } else {
                node->next = list2; // start of list2 to end
                list2 = list2->next; // now we go to next element
            }
            node = node->next;
        }
        if (list1) {
            node->next = list1;
        } else {
            node->next = list2;
        }
        return dummy.next;
    }
};
