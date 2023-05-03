#include <iostream>
#include <chrono> //to mesure the time for execution

#include <cstdlib>// for randome arrays
#include <ctime>
#include <vector>
#include <stack>

using namespace std;
using namespace std::chrono;
class Stack1 {
private:
    int top;
    int arr[100];//creat stack with 100 elements 
public:
    Stack1() {
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

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {} //creat node with value and link to next node 
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}
    ~Stack();

    void push(int val);
    int pop();
    bool isEmpty();
};

Stack::~Stack() {
    while (top) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void Stack::push(int val) {
    Node* newNode = new Node(val);
    newNode->next = top;
    cout << "Pushed: " << val << endl;
    top = newNode;
}

int Stack::pop() {
    if (!top) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    Node* temp = top;
    int val = temp->data;
    top = top->next;
    cout << "Poped: " << val << endl;
    delete temp;
    return val;
}


bool Stack::isEmpty() {
    return top == nullptr;
}
int main() {

    auto start = high_resolution_clock::now();
    Stack1 s;
    for (int i=0;i<30;i++){
    s.push1(1);
    s.push1(2);
    s.push1(3);
    s.push1(1);
    s.push1(2);
    s.push1(3);
    cout << "Stack is empty: " << s.isEmpty1() << endl;
    s.pop1();
    s.pop1();
    s.pop1();
    s.pop1();
    s.pop1();
    s.pop1();
    cout << "Stack is empty: " << s.isEmpty1() << endl;
    }
    
    auto stop = high_resolution_clock::now(); 
    auto duration1 = duration_cast<milliseconds>(stop - start);
    cout << "Time taken by code (Linked List): " << duration1.count() << " MilliSeconds _________"<< endl;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    auto start1 = high_resolution_clock::now();

    Stack stack;
     for (int j=0;j<30;j++){
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Stack is empty: " << stack.isEmpty() << endl;
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    cout << "Stack is empty: " << stack.isEmpty() << endl;
    }


    auto stop1 = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop1 - start1);
    cout << "Time taken by code (Array Based): " << duration.count() << " MilliSeconds _________" << endl;

    return 0;
  }