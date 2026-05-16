struct Node {
    int val;
    Node *next;
    Node *prev;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class MyCircularQueue {
private:
    int k = 0;
    int size = 0;
    Node *front = nullptr;
    Node *rear  = nullptr;
    Node *curr  = nullptr;

public:
    MyCircularQueue(int k) {
        this->k = k;
        front = new Node(0);
        rear  = new Node(0);
        // front->next = rear;
        curr = front;
        front->next = rear;
        rear->prev  = front;
    }
    
    bool enQueue(int value) {
        if (size < k) {
            Node *new_node = new Node(value);
            curr->next = new_node;
            new_node->prev = curr;

            new_node->next = rear;
            rear->prev = new_node;

            curr = curr->next;
            size++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if (size > 0) {
            Node *node = front->next;
            front->next = node->next;
            node->next->prev = front;

            if (node == curr) {
                curr = front;
            }
            delete node;
            size--;
            return true;
        }
        return false;
    }
    
    int Front() {
        if (size == 0)  return -1;
        return front->next->val;
    }
    
    int Rear() {
        if (size == 0)  return -1;
        cout << rear->prev->val;
        return rear->prev->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */