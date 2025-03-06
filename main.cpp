#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;
    void reversePrintHelper(Node* node) {
        if (node == nullptr) return;
        reversePrintHelper(node->next);
        std::cout << node->data << " ";
    }

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void displayList() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void reversePrint() {
        reversePrintHelper(head);
        std::cout << std::endl;
    }
};

int main() {
    SinglyLinkedList list;
    for (int i = 1; i <= 10; i++) {
        list.insertAtEnd(i);
    }

    std::cout << "Original List: ";
    list.displayList();

    std::cout << "Reversed List (using recursion): ";
    list.reversePrint();

    return 0;
}
