#include <iostream>
using namespace std;

// node
struct Node {
    int data;
    struct Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// linked list
struct LinkedList {
    Node* head;
    LinkedList() {head = NULL;}

    // reverse linked list
    void reverse() {
        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next;

            current->next = prev;

            prev = current;
            current = next;
        }

        head = prev;
    }

    // print linked list
    void print() {
        struct Node* tmp = head;

        while (tmp != NULL) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }

    void push(int data) {
        Node* tmp = new Node(data);
        tmp->next = head;
        head = tmp;
    }
};

int main() {
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);

    cout << "Given linked list: ";
    ll.print();

    ll.reverse();

    cout << "\nReversed linked list: ";
    ll.print();

    return 0;
}
