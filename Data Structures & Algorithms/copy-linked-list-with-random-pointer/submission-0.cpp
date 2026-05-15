/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)  return nullptr;
        Node res(0);
        Node *dummy = &res;
        Node *temp = head;
        
        // unordered_map<int, Node*>   idxToNodePtr;
        // unordered_map<Node*, int>   nodePtrToIdx;
        unordered_map<Node*, Node*>  nodePtrToNewNodePtr;

        int i = 0, size = 0;
        while (temp) {
            // idxToNodePtr[i] = temp;
            // nodePtrToIdx[temp] = i;

            Node *newNode = new Node(temp->val);
            nodePtrToNewNodePtr[temp] = newNode;

            dummy->next = newNode;
            dummy = dummy->next;

            temp = temp->next;
            i++;
            size++;
        }

        temp = head;
        dummy = res.next;
        i = 0;
        while (size-->0) {
            dummy->random = nodePtrToNewNodePtr[temp->random];
            temp = temp->next;
            dummy = dummy->next;
        }

        // printing idx to nodes;
        // for (unordered_map<int, Node*>::iterator it = idxToNode.begin(); it != idxToNode.end(); it++) {
        //     cout << "idx: " << it->first << ", Node: {val: " << it->second->val << ", next: " << it->second->next << ", random: " << it->second->random << " }\n";
        // }

        return res.next;
    }
};
