#include <iostream>
using namespace std;
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
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << stack.isEmpty() << endl;
    return 0;
}