#include <iostream>
#include <vector>
using namespace std;

class Queue {
    private:
        vector<int> vec;
        int top;

    public:
        Queue() {
            top = 0;
        }

        void push(int val) {
            vec.resize(top + 1);   
            vec[top] = val;       
            top++;                
        }

        void pop() {
            if (top == 0) {
                cout << "No items in queue" << endl;  
            } else {
                for (int i = 0; i < top - 1; i++) {
                    vec[i] = vec[i+1];
                }
                vec.resize(top - 1);  
                top--;                
            }
        }

        int read() {
            if (top == 0) {
                cout << "Queue is empty." << endl;
                return -1; 
            } else {
                return vec[0];  
            }
        } 

        int getIndex() {
            return vec[0]; 
        }
};

int main() {
    Queue queue;

    queue.push(3);               
    queue.push(4);               
    cout << queue.read() << endl; 

    queue.pop();                 
    cout << queue.read() << endl; 

    queue.pop();                 
    cout << queue.read() << endl; 

    return 0;
}
