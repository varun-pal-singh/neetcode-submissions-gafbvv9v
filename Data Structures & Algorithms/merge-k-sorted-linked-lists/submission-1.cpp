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

class Compare{
public:
    bool operator()(ListNode *a, ListNode *b) {
        return a->val >= b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
        ListNode dummy(0, nullptr);
        ListNode *temp = &dummy;

        // std::cout << "lists[0]: " << lists[0] << ", lists[0]->val: " << lists[0]->val << "\n";

        while (1) {
            for (int i = 0; i < k; i++) {
                if (lists[i]) {
                    minHeap.push(lists[i]);
                    lists[i] = lists[i]->next;
                }
            }
            if (!minHeap.empty()) {
                temp->next = minHeap.top();
                minHeap.pop();
                temp = temp->next;
            }
            else {
                break;
            }
        }

        return dummy.next;
    }
};
