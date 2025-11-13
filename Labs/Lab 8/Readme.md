# C++ Stack Implementation: Array vs. Linked List

This repository contains two fundamental C++ implementations of a Stack data structure:
1.  **Using a static Array:** A fixed-size, memory-efficient implementation.
2.  **Using a Linked List:** A dynamic-size, flexible implementation.

A stack is a linear data structure that follows the **LIFO (Last-In, First-Out)** principle. Think of it as a stack of plates: you can only add a new plate to the top, and you can only remove the topmost plate.



## Key Stack Operations

* **`push(value)`**: Adds an element to the top of the stack.
* **`pop()`**: Removes the element from the top of the stack.
* **`peek()`** (or `top()`): Returns the value of the top element without removing it.
* **`isEmpty()`**: Returns `true` if the stack is empty, `false` otherwise.

---

## 1. Stack Implementation using an Array

This implementation uses a fixed-size array to store elements. It's very fast and memory-efficient but has a limited capacity.

### Pros and Cons

* **Pros:**
    * **Fast:** `push` and `pop` operations are simple array assignments (O(1)).
    * **Memory Efficient:** No extra memory is used for pointers.
* **Cons:**
    * **Fixed Size:** The stack's size must be known at compile time.
    * **Overflow:** If you try to push onto a full stack, it results in a "Stack Overflow."

### Complete Code (ArrayStack.cpp)

```cpp
#include <iostream>
using namespace std;

// Define the maximum size of the stack
const int MAX_SIZE = 5;

class clsStack
{
private:
    int top;             // Index of the top element
    int stack[MAX_SIZE]; // The array to hold stack elements

public:
    // Constructor: Initializes the stack
    clsStack()
    {
        // -1 indicates the stack is empty
        top = -1;
    }

    // Checks if the stack is empty
    bool isEmpty()
    {
        return (top == -1);
    }

    // Checks if the stack is full
    bool isFull()
    {
        return (top == MAX_SIZE - 1);
    }

    // Pushes a new element onto the stack
    void push(int value)
    {
        if (isFull())
        {
            cout << "Error: Stack Overflow. Cannot push " << value << endl;
            return;
        }

        // 1. Increment top
        top++;
        // 2. Add the value at the new top position
        stack[top] = value;
    }

    // Removes the top element
    void pop()
    {
        if (isEmpty())
        {
            cout << "Error: Stack Underflow. Cannot pop." << endl;
            return;
        }

        // Simply decrement top. The old value is still in memory
        // but is now inaccessible and will be overwritten by the next push.
        top--;
    }

    // Returns the top element without removing it
    int peek()
    {
        if (isEmpty())
        {
            cout << "Error: Stack is empty. Returning -1." << endl;
            return -1; // Return a flag value
        }
        return stack[top];
    }

    // Displays all elements in the stack
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty." << endl;
            return;
        }
        cout << "Stack (bottom to top):" << endl;
        for (int i = 0; i <= top; i++)
        {
            cout << stack[i] << endl;
        }
    }
};

// --- Main function to test the Array Stack ---
int main()
{
    clsStack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.display(); // 10, 20, 30

    cout << "Top element is: " << myStack.peek() << endl; // 30

    myStack.pop();
    cout << "After popping:" << endl;
    myStack.display(); // 10, 20

    myStack.push(40);
    myStack.push(50);
    myStack.push(60); // This will cause a Stack Overflow

    cout << "Popping all elements:" << endl;
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop(); // This will cause a Stack Underflow

    return 0;
}
```

---

## 2. Stack Implementation using a Linked List

This implementation uses nodes and pointers. Each node stores a value and a pointer to the next node. This allows the stack to grow and shrink dynamically.

### Pros and Cons

* **Pros:**
    * **Dynamic Size:** The stack can grow as long as memory is available.
    * **No Overflow:** You won't have a stack overflow (unless the system runs out of memory).
* **Cons:**
    * **Memory Overhead:** Each element requires extra memory to store the `next` pointer.
    * **Slightly Slower:** `push` and `pop` require heap allocation (`new`) and deallocation (`delete`), which is slower than array indexing.

### Complete Code (LinkedListStack.cpp)

```cpp
#include <iostream>
using namespace std;

// --- 1. The Node Class ---
// This is the blueprint for each link in our chain.
class Node
{
public:
    int data;    // The value stored in the node
    Node* next;  // The pointer to the next node in the stack

    // Constructor to easily create a new node
    Node(int value)
    {
        data = value;
        next = nullptr; // Initialize 'next' to null (points to nothing)
    }
};

// --- 2. The Stack Class ---
// This class manages the nodes and provides the stack operations.
class clsStack
{
private:
    Node* top; // A single pointer to the top of the stack

public:
    // Constructor: Initializes an empty stack
    clsStack()
    {
        top = nullptr;
    }

    // Destructor: Cleans up all memory
    ~clsStack()
    {
        cout << "\nCleaning up all nodes..." << endl;
        while (!isEmpty())
        {
            pop(); // Pop all elements to free memory
        }
    }

    // Checks if the stack is empty
    bool isEmpty()
    {
        return (top == nullptr);
    }

    // Pushes a new value to the top of the stack
    void push(int value)
    {
        // 1. Create the new node
        Node* newNode = new Node(value);

        // 2. Link the new node to the old top
        newNode->next = top;

        // 3. Update top to be the new node
        top = newNode;
    }

    // Removes the top element from the stack
    void pop()
    {
        if (isEmpty())
        {
            cout << "Error: Stack Underflow. Cannot pop." << endl;
            return;
        }

        // 1. Save a pointer to the old top
        Node* temp = top;

        // 2. Move the main 'top' pointer to the next node
        top = top->next;

        // 3. Delete the old top node
        delete temp;
    }

    // Returns the value of the top element without removing it
    int peek()
    {
        if (isEmpty())
        {
            cout << "Error: Stack is empty. Returning -1." << endl;
            return -1; // Return a flag value
        }
        
        return top->data;
    }

    // Displays all elements in the stack
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty." << endl;
            return;
        }
        
        Node* temp = top;
        cout << "Stack (top to bottom):" << endl;

        // Loop as long as temp is not pointing to null
        while (temp != nullptr)
        {
            cout << temp->data << endl; // Print the node's data
            temp = temp->next;          // Move to the next node
        }
    }
};

// --- 3. The main() Function to Test ---
int main()
{
    clsStack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.display(); // 30, 20, 10

    cout << "Top element is: " << myStack.peek() << endl; // 30

    myStack.pop();
    cout << "After popping:" << endl;
    myStack.display(); // 20, 10

    // Can keep pushing, no overflow
    myStack.push(40);
    myStack.push(50);
    myStack.push(60); 
    myStack.display(); // 60, 50, 40, 20, 10

    cout << "Popping all elements:" << endl;
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.display(); // Stack is Empty.

    myStack.pop(); // This will cause a Stack Underflow

    // Destructor will automatically be called here
    // when myStack goes out of scope.
    return 0;
}
```
