// singly linked list node
class ListNode {
    public:
        int val;
        ListNode* next;

        //constructor that sets 'next' to nullptr by default
        ListNode(int val): val(val), next(nullptr) {}
        //constructor that accepts both value and next node
        ListNode(int val, ListNode* next) : val(val), next(next){}
};

// implementation for singly linked list
class LinkedList {
private:
    ListNode* head;
    ListNode* tail;

public:
    //constructor
    LinkedList() {
        //init list with a 'dummy' node
        head = new ListNode(-1);
        tail = head;
    }

    int get(int index) {
        ListNode* curr = head->next;
        int i = 0;
        while (curr != nullptr){
            if (i == index) {
                return curr->val;
            }
            i++;
            curr = curr->next;
        }
        return -1; // result if index out of bounds or list is empty
    }

    // method to insert at the head
    void insertHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head->next;
        head->next = newNode;
        if (newNode->next == nullptr){
            //if list is empty before insertion
            tail = newNode;
        }
    }
    
    // method to insert at the tail
    void insertTail(int val) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    // method to remove at given index
    bool remove(int index) {
        int i = 0;
        ListNode* curr = head;
        while (i<index && curr != nullptr){
            i++;
            curr = curr->next;
        }

        //remove node ahead of current
        if (curr != nullptr && curr->next != nullptr){
            if(curr->next == tail){
                tail = curr;
            }
            ListNode* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
            return true;
        }
        return false;
    }

    // method to get values of the linked list
    vector<int> getValues() {
        vector<int> result;
        ListNode* curr = head->next;
        while (curr != nullptr){
            result.push_back(curr->val);
            curr = curr->next;
        }
        return result;
    }
};
