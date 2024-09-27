#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node (int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

struct LinkedList {
    Node* head;
    Node* tail;

    LinkedList () {
        head = nullptr;
        tail = nullptr;
    }

    void display () {
        Node* current = head;
        while (current != nullptr) {
            cout << current->prev << ", " << current->data << ", " << current->next << " | ";
            current = current->next;
        }
        cout << endl;
    }

    int getIndex () {
        if (head == nullptr || tail == nullptr) {
            return 0;
        }
        Node* current = head;
        int index = -1;
        while (current != nullptr) {
            index++;
            current = current->next;
        }
        return index;
    }

    void insertStart (int x) {
        if (head == nullptr) {
            Node* newNode = new Node(x);
            head = newNode;
            tail = newNode;
        } else {
            Node* current = head;
            Node* newNode = new Node(x);
            current->prev = newNode;
            newNode->next = current;
            head = newNode;
        }
    }

    void insertEnd (int x) {
        if (head == nullptr) {
            Node* newNode = new Node(x);
            head = newNode;
            tail = newNode;
        } else {
            Node* current = tail;
            Node* newNode = new Node(x);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertIndex(int x, int n) {
    if (n > getIndex() || n < 0) {
        cout << "Invalid index" << endl;
        return;
    }

    Node* newNode = new Node(x);
    Node* current;

    if (n > getIndex() / 2) {
        current = tail;
        for (int i = getIndex(); i > n; i--) {
            current = current->prev;
        }
        Node* prevNode = current->prev;
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = current;
        current->prev = newNode;
        return;

    } else {
        current = head;
        for (int i = 0; i < n; i++) {
            current = current->next;
        }
        Node* prevNode = current->prev;
        if (prevNode) { 
            prevNode->next = newNode;
            newNode->prev = prevNode;
        } else { 
            head = newNode;
        }
        newNode->next = current;
        current->prev = newNode;
        return;
    }


    }

    void readList (int n) {
        Node* current = head;
        for (int i = 0; i < n; i++) {
            current = current->next;
        }
        cout << "The value at index " << n << " is: " << current->data << endl;
    }

    void searchList (int x) {
        int index = -1;
        Node* current = head;
        while (current != nullptr) {
            index++;
            if (current->data == x) {
                cout << "The value at index " << index << " is: " << current->data << endl;
                return;
            }
            current = current->next;
        }

        cout << "Value not found" << endl;
        return;
    }

    void deleteStart () {
        if (head == nullptr) {
            cout << "Cant delete the head" << endl;
            return;
        }

        Node* secondNode = head->next;
        head = secondNode;
        head->prev = nullptr;
        delete secondNode;
        return;
    }

    void deleteEnd () {
        if (head == nullptr) {
            cout << "Cant delete the head" << endl;
            return;
        }

        Node* secondNode = tail->prev;
        tail = secondNode;
        tail->next = nullptr;
        delete secondNode;
        return;
    }

    void deleteIndex(int n) {
        if (n > getIndex() || n < 0) {
            cout << "Invalid index" << endl;
        }

        Node* current = head;
        for (int i = 0; i < n; i++){
            current = current->next;
        }
        Node* nextNode = current->next;
        Node* prevNode = current->prev;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delete current;
        return;
    }

};



int main () {

    LinkedList list;

    list.insertStart(2);
    list.insertStart(3);
    list.insertEnd(4);
    list.insertEnd(5);
    list.insertEnd(6);
    list.insertIndex(9, 3);
    list.deleteIndex(3);
    list.display();

    return 0;
}