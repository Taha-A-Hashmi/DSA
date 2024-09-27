#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node (int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
    public:
        Node* head;

        LinkedList () {
            head = nullptr;
        }

        void readListIndex (int n) {
            Node* current = head;

            if (n < 0) {
                cout << "Invalid index: " << n << endl;
                return;
            }

            for (int i = 0; i < n; i++) {
                if (current == nullptr) {
                    cout << "The index doesn't exist" << endl;
                }
                current = current->next;
            }
            
            cout << "The value at index " << n << " is: " << current->data << endl;   
        }

        void readListValue (int x) {
            Node* current = head;
            int index = 0;
            bool found = false;
            while (current != nullptr) {
                if (current->data == x) {
                    cout << "The value " << x << " was found at index: " << index << endl;
                    found = true;
                }
                current = current->next;
                index++;
            }
            if (!found){
                cout << "Value is not in the list" << endl;
            }
            return;
        }

        int indexCount () {
            Node* current = head;
            int index = -1;
            while (current != nullptr) {
                current = current->next;
                index++;
            }
            return index;
        }

        void display () {
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << ", " << current->next << " " << endl;
                current = current->next;
            }
        }

        void insertStart (int x) {
            Node* inputNode = new Node(x);
            inputNode->next = head;
            head = inputNode;
        }

        void insertEnd (int x) {
            Node* current = head;
            Node* newNode = new Node(x);

            if (head == nullptr) {
                head = newNode;
                return;
            }

            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        void insertAtIndex (int x, int n) {
            Node* current = head;
            Node* newNode = new Node(x);

            if (n > indexCount() + 1 || n < 0) {
                cout << "Can't insert here as your index is bigger than list index + 1" << endl;;
                return;
            } else if (n == 0) {
                insertStart(x);
                return;
            } 
            for (int i = 0; i < n - 1; i++){
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            return;
        }

        void deleteAtStart () {
            if (head == nullptr) {
                cout << "Cannot delete the head";
                return;
            }

            Node* current = head;
            head = current->next;
            delete current;
            return;
        }

        void deleteAtEnd () {
            if (head == nullptr) {
                cout << "Can't delete the head";
                return;
            }

            Node* current = head;
            for (int i = 0; i < indexCount() - 1; i++) {
                current = current->next;
            }
            current->next = nullptr;
            return;
        }

        void deleteAtIndex (int n) {
            Node* current = head;

            if (n > indexCount() || n < 0) {
                cout << "Invalid index";
                return;
            }

            for (int i = 0; i < n - 1; i++) {
                current = current->next;
            }
            current->next = current->next->next;
            return;
        }

};



int main() {

    LinkedList list;
    Node* node1 = new Node(10); 
    Node* node2 = new Node(20); 
    Node* node3 = new Node(30);
    Node* node4 = new Node(30);

    list.head = node1; 
    node1->next = node2;
    node2->next = node3;
    node3->next = node4; 

    list.readListValue(30);
    list.display();

    return 0;
}