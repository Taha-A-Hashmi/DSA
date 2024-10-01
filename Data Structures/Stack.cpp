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

    stack.push(3);               
    stack.push(4);               
    cout << stack.read() << endl; 

    stack.pop();                 
    cout << stack.read() << endl; 

    stack.pop();                 
    cout << stack.read() << endl; 

    return 0;
}
