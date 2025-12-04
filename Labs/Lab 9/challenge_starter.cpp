#include <iostream>
#include <string>
#include <limits> // For numeric limits if needed

using namespace std;

// =========================================================
// 1. THE NODE: A Single Time Capsule
// =========================================================
struct TimeCapsule {
    int year;               // Key
    string eventName;       // Data
    TimeCapsule* left;      // Left Child (Earlier years)
    TimeCapsule* right;     // Right Child (Later years)

    // Constructor for easy node creation
    TimeCapsule(int y, string n) : year(y), eventName(n), left(nullptr), right(nullptr) {}
};

// =========================================================
// 2. THE BST CLASS: Chronos Time Tree
// =========================================================
class TimeTree {
private:
    TimeCapsule* root;

    // --- STUDENT TODO: Helper Functions for Recursion ---
    // It is highly recommended to use private recursive helper functions.
    // Example: 
    // TimeCapsule* insertHelper(TimeCapsule* node, int year, string name) { ... }
    
    // Helper to clear memory (optional but good practice)
    void destroyTree(TimeCapsule* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    TimeTree() { root = nullptr; }
    
    ~TimeTree() { destroyTree(root); }

    // ---------------------------------------------------------
    // TASK 1: INJECT (Insert)
    // ---------------------------------------------------------
    void inject(int year, string name) {
        cout << "> System: Injecting " << year << "... ";
        
        // TODO: Implement BST Insertion Logic
        // 1. If tree is empty, create root.
        // 2. Else, recurse down: < goes left, > goes right.
        // 3. Print "Timeline stable." when done.
        
        cout << " [NOT IMPLEMENTED]" << endl; // Remove this line when done
    }

    // ---------------------------------------------------------
    // TASK 2: PARADOX (Delete)
    // ---------------------------------------------------------
    void resolveParadox(int year) {
        cout << "> Alert: Paradox detected at " << year << "!" << endl;
        
        // TODO: Implement BST Deletion Logic
        // 1. Find the node.
        // 2. Case 1: Leaf node (no children) -> just delete.
        // 3. Case 2: One child -> replace node with child.
        // 4. Case 3: Two children -> find Inorder Successor (smallest in right subtree),
        //    copy value, and delete successor.
        
        cout << "> System: [NOT IMPLEMENTED] Cannot remove year." << endl; // Remove this line
    }

    // ---------------------------------------------------------
    // TASK 3: SEARCH
    // ---------------------------------------------------------
    void search(int year) {
        cout << "> Query: Searching for " << year << "..." << endl;
        
        // TODO: Search the tree
        // If found, print: "> Result: Event Found! [" << year << ": " << eventName << "]"
        // If not found, print: "> Result: Year not found."
        
        cout << "> Result: [NOT IMPLEMENTED]" << endl; // Remove this line
    }

    // ---------------------------------------------------------
    // TASK 4: REPORT (In-Order Traversal)
    // ---------------------------------------------------------
    void report() {
        cout << "> COMMAND: CHRONOLOGICAL REPORT" << endl;
        cout << "-------------------------------" << endl;
        
        // TODO: Print all events in ascending order (Year)
        // Hint: Recursion (Left -> Root -> Right)
        
        cout << "-------------------------------" << endl;
    }

    // ---------------------------------------------------------
    // BONUS: TIME SPAN
    // ---------------------------------------------------------
    void calculateTimeSpan() {
        // TODO: Find Min Year and Max Year, then print (Max - Min)
    }
};

// =========================================================
// 3. MAIN INTERFACE (Do not modify input parsing)
// =========================================================
int main() {
    TimeTree chronos;
    string command;
    int year;
    string eventName;

    // Introduction
    cout << "--- CHRONOS TIME STABILIZER V1.0 ---" << endl;
    cout << "Waiting for Time Stream Inputs..." << endl << endl;

    // Command Loop
    while (cin >> command) {
        if (command == "INJECT") {
            cin >> year;
            // getline reads the rest of the line, including spaces
            getline(cin >> ws, eventName); 
            chronos.inject(year, eventName);
        }
        else if (command == "PARADOX") {
            cin >> year;
            chronos.resolveParadox(year);
        }
        else if (command == "SEARCH") {
            cin >> year;
            chronos.search(year);
        }
        else if (command == "REPORT") {
            chronos.report();
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            cout << "> Unknown Command." << endl;
            // Clear buffer to prevent infinite loops on bad input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << endl; // Spacing between commands
    }

    return 0;
}
