#include <iostream>
using namespace std;
class Stack {
private:
    int top;
    int arr[100];//creat stack with 100 elements 
public:
    Stack() {
        top = -1; // Initialize top of stack
    }
    bool push1(int val) {
        if (top >= 100 - 1) {
            cout << "Error: Stack is full" << endl;
            return false;
        }
        arr[++top] = val;//increment top by 1 and store value
        cout << "Pushed: " << val << endl;
        return true;
    }
    int pop1() {
        if (top < 0) {
            cout << "Error: Stack is empty" << endl;
            return -1;
        }
        int val = arr[top--];
        cout << "Poped: " << val << endl;
        return val;
    }

    bool isEmpty1() {
        return (top == -1);
    }
    bool isFull1() {
        return (top == 100 - 1);
    }
};

int main() {
    Stack s;
    s.push1(1);
    s.push1(2);
    s.push1(3);
    cout << "Stack is empty: " << s.isEmpty1() << endl;
    s.pop1();
    s.pop1();
    s.pop1();
    cout << "Stack is empty: " << s.isEmpty1() << endl;
    return 0;
}