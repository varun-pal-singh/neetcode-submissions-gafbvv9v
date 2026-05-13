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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode *temp = head;
        while (n-->0 && temp) {
            temp = temp->next;
        }
        ListNode *temp2 = &dummy;
        while (temp2->next && temp) {
            temp = temp->next;
            temp2 = temp2->next;
        }

        temp2->next = temp2->next->next;
        return dummy.next;
    }
};
