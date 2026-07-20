#include <iostream>
using namespace std;
class ListNode {
public:
    int _val;
    ListNode *next = nullptr;
    ListNode(int val) {
        _val = val;
    }
};

class SinglyLinkedList {
private:
    ListNode* head;
    ListNode* tail;

public:
    SinglyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~SinglyLinkedList() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insertAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAtPosition(int val, int position) {
        if (position <= 0) {
            insertAtHead(val);
            return;
        }
        
        ListNode* newNode = new ListNode(val);
        ListNode* temp = head;
        
        for (int i = 0; temp != nullptr && i < position - 1; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            insertAtTail(val);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteHead() {
        if (head == nullptr) return;
        
        ListNode* temp = head;
        head = head->next;
        delete temp;
        
        if (head == nullptr) {
            tail = nullptr;
        }
    }

    void deleteTail() {
        if (head == nullptr) return;
        
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        ListNode* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = nullptr;
    }

    void deleteValue(int val) {
        if (head == nullptr) return;

        if (head->_val == val) {
            deleteHead();
            return;
        }

        ListNode* temp = head;
        while (temp->next != nullptr && temp->next->_val != val) {
            temp = temp->next;
        }

        if (temp->next != nullptr) {
            ListNode* toDelete = temp->next;
            if (toDelete == tail) {
                tail = temp;
            }
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    bool search(int val) {
        ListNode* temp = head;
        while (temp != nullptr) {
            if (temp->_val == val) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void printList() {
        ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->_val << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    SinglyLinkedList list;

    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtHead(5);
    list.insertAtPosition(15, 2);
    list.printList();

    list.deleteHead();
    list.printList();

    list.deleteTail();
    list.printList();

    list.deleteValue(15);
    list.printList();

    return 0;
}