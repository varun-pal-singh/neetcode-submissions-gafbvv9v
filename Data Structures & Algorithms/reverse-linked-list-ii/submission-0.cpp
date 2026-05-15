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
   private:
    ListNode* reverse(ListNode* head) {
        ListNode* res = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = res;
            res = head;
            head = next;
        }

        return res;
    }

   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left >= right) return head;
        int i = 0;
        ListNode res(0, head);
        ListNode *dummy = &res;
        ListNode *leftPrev = &res;

        ListNode *cur = head;
        for (int i = 0; i < left - 1; i++) {
            leftPrev = cur;
            cur = cur->next;
        }

        ListNode *prev = nullptr;
        for (int i = 0; i < (right - left + 1); i++) {
            ListNode *tmpNext = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmpNext;
        }

        leftPrev->next->next = cur;
        leftPrev->next = prev;
        
        return res.next;
    }
};