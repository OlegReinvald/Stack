#include <iostream>

class Stack {
private:
    int* stackArray;
    int top;
    int capacity;

public:
    Stack(int size) {
        stackArray = new int[size];
        top = -1;
        capacity = size;
    }

    ~Stack() {
        delete[] stackArray;
    }

    void push(int element) {
        if (top == capacity - 1) {
            std::cout << "Stack overflow" << std::endl;
            return;
        }
        stackArray[++top] = element;
    }

    void pop() {
        if (top == -1) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        top--;
    }

    int& operator[](int index) {
        return stackArray[index];
    }

    Stack& operator=(const Stack& other) {
        if (this != &other) {
            capacity = other.capacity;
            top = other.top;
            stackArray = new int[capacity];
            for (int i = 0; i <= top; i++) {
                stackArray[i] = other.stackArray[i];
            }
        }
        return *this;
    }

    bool operator<(const Stack& other) {
        return top < other.top;
    }

    bool operator==(const Stack& other) {
        if (top != other.top) {
            return false;
        }
        for (int i = 0; i <= top; i++) {
            if (stackArray[i] != other.stackArray[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Stack stack(3);
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Stack elements: ";
    for (int i = 0; i <= stack[2]; i++) {
        std::cout << stack[i] << " ";
    }
    std::cout << std::endl;

    stack.pop();

    std::cout << "Stack elements after pop: ";
    for (int i = 0; i <= stack[1]; i++) {
        std::cout << stack[i] << " ";
    }
    std::cout << std::endl;

    Stack stackNew(5);
    stackNew = stack;

    if (stackNew < stack) {
        std::cout << "Stack2 is smaller than stack" << std::endl;
    } else if (stackNew == stack) {
        std::cout << "Stack2 is equal to stack" << std::endl;
    } else {
        std::cout << "Stack2 is larger than stack" << std::endl;
    }

    return 0;
}
