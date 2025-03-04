#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;
    Node* tail;
    int count;
public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    void display() {
        Node* current = head;
        cout << "list: (" << count << "): ";
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
        count = 0;
    }

    Node* getHead() { return head; }
    void setHead(Node* newHead) { head = newHead; }
    void setTail(Node* newTail) { tail = newTail; }
    int getCount() { return count; }
    void decrementCount() { count--; }
};

class SplitLinkedList : public SinglyLinkedList {
public:
    void splitEvenOdd(SinglyLinkedList& evens, SinglyLinkedList& odds) {
        Node* current = getHead();

        while (current) {
            if (current->data % 2 == 0) {
                evens.append(current->data);
            } else {
                odds.append(current->data);
            }
            current = current->next;
        }
        clear();
    }
};

int main() {
    SplitLinkedList linkedList;
    int numbers[] = {34, 21, 10, 15, 90, 66, 53, 7, 88, 36, 90, 11, 17, 24, 10};
    for (int num : numbers) {
        linkedList.append(num);
    }

    linkedList.display();

    SinglyLinkedList evens, odds;
    linkedList.splitEvenOdd(evens, odds);

    evens.display();
    odds.display();
    linkedList.display();

    return 0;
}
