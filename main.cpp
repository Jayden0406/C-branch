#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert node at the beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Insert node at the end
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* last = head;
        while (last->next) {
            last = last->next;
        }
        last->next = newNode;
    }

    // Delete the first node
    void deleteFirst() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Delete the last node
    void deleteLast() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete a middle node (node with specific data)
    void deleteMiddle(int data) {
        if (!head) return;
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            if (temp->next->data == data) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                return;
            }
            temp = temp->next;
        }
    }

    // Display the list
    void display() {
        Node* current = head;
        if (!current) {
            cout << "List is empty" << endl;
            return;
        }
        while (current) {
            cout << current->data;
            if (current->next) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << " -> nullptr" << endl;
    }
};

// Test program
void testLinkedList() {
    // Build a forward list using insertAtBeginning
    cout << "Build a forward list" << endl;
    SinglyLinkedList forwardList;
    forwardList.insertAtBeginning(10);
    forwardList.insertAtBeginning(20);
    forwardList.insertAtBeginning(30);
    forwardList.insertAtBeginning(40);
    forwardList.insertAtBeginning(50);
    forwardList.display();

    // Delete the first node
    cout << "Delete the first node" << endl;
    forwardList.deleteFirst();
    forwardList.display();

    // Delete the last node
    cout << "Delete the last node" << endl;
    forwardList.deleteLast();
    forwardList.display();

    // Delete the middle node
    cout << "Delete the middle node" << endl;
    forwardList.deleteMiddle(30);
    forwardList.display();

    // Build a backward list using insertAtEnd
    cout << "Build a backward list" << endl;
    SinglyLinkedList backwardList;
    backwardList.insertAtEnd(10);
    backwardList.insertAtEnd(20);
    backwardList.insertAtEnd(30);
    backwardList.insertAtEnd(40);
    backwardList.insertAtEnd(50);
    backwardList.display();

    // Delete the first node
    cout << "Delete the first node" << endl;
    backwardList.deleteFirst();
    backwardList.display();

    // Delete the last node
    cout << "Delete the last node" << endl;
    backwardList.deleteLast();
    backwardList.display();

    // Delete the middle node
    cout << "Delete the middle node" << endl;
    backwardList.deleteMiddle(30);
    backwardList.display();
}

int main() {
    testLinkedList();
    return 0;
}
