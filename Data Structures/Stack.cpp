#include <iostream>
#include <vector>
using namespace std;

class Stack {
    public:
        vector<int> vec;
        int top;

        Stack() {
            top = 0;
        }

        void push(int val) {
            vec.resize(top + 1);   
            vec[top] = val;       
            top++;                
        }

        void pop() {
            if (top == 0) {
                cout << "No items in stack" << endl;  
            } else {
                vec.resize(top - 1);  
                top--;                
            }
        }

        int read() {
            if (top == 0) {
                cout << "Stack is empty." << endl;
                return -1; 
            } else {
                return vec[top - 1];  
            }
        } 

        int getIndex() {
            return top; 
        }
};

int main() {
    Stack stack;

    for (int i = 1; i <= 5; i++) {
        stack.push(i);
    }

    int arr[5] = {};
    for (int i = 0; i < 5; i++) {
        arr[i] = stack.read();
        stack.pop();
    }

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
