

# 📊 Bubble Sort (C++)

## 📌 Introduction

**Bubble Sort** is one of the simplest and most commonly taught sorting algorithms in Computer Science.
It sorts an array by **repeatedly comparing adjacent elements** and **swapping them if they are in the wrong order**.

Although Bubble Sort is **not suitable for large datasets**, it is extremely valuable for:

* Learning algorithmic thinking
* Understanding nested loops
* Grasping the fundamentals of comparison-based sorting

---

## 🧠 Why Is It Called Bubble Sort?

The algorithm gets its name because:

* The **largest element gradually moves (bubbles) to the end** of the array after each pass
* Similar to how **air bubbles rise to the surface of water**

It is also known as:

* **Exchange Sort**
* **Sinking Sort**

---

## 🔍 How Bubble Sort Works (Concept)

Bubble Sort performs multiple **passes** over the array.

In each pass:

1. Compare two adjacent elements
2. Swap them if the left element is greater than the right
3. Repeat until the largest element reaches its correct position

After each pass:

* The size of the unsorted portion reduces by one

---

## 🪜 Step-by-Step Example (ASCII Visualization)

### Initial Array

```
[ 5 , 1 , 4 , 2 , 8 ]
```

---

### 🔁 Pass 1

```
Compare 5 and 1 → swap
[ 1 , 5 , 4 , 2 , 8 ]

Compare 5 and 4 → swap
[ 1 , 4 , 5 , 2 , 8 ]

Compare 5 and 2 → swap
[ 1 , 4 , 2 , 5 , 8 ]

Compare 5 and 8 → no swap
[ 1 , 4 , 2 , 5 , 8 ]
```

➡ Largest element **8** is now in correct position.

---

### 🔁 Pass 2

```
Compare 1 and 4 → no swap
[ 1 , 4 , 2 , 5 , 8 ]

Compare 4 and 2 → swap
[ 1 , 2 , 4 , 5 , 8 ]

Compare 4 and 5 → no swap
[ 1 , 2 , 4 , 5 , 8 ]
```

➡ Second largest element **5** is fixed.

---

### 🔁 Pass 3

```
Compare 1 and 2 → no swap
Compare 2 and 4 → no swap
```

➡ No swaps needed → array is sorted.

---

## ✅ Final Sorted Array

```
[ 1 , 2 , 4 , 5 , 8 ]
```

---

## 📈 Bubble Sort Visualization (Index Movement)

```
i = 0 → largest moves to last index
i = 1 → second largest moves before last
i = 2 → continues...
```

Each outer loop pass reduces the comparison range.

---

## 🧾 Algorithm (Pseudocode)

```
for i = 0 to n-2
    for j = 0 to n-i-2
        if arr[j] > arr[j+1]
            swap(arr[j], arr[j+1])
```

---

## 💻 C++ Implementation (Basic)

```cpp
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
```

---

## ⚡ Optimized Bubble Sort (Early Termination)

### Why Optimization?

If no swaps occur in a pass:

* The array is already sorted
* Further passes are unnecessary

---

### Optimized C++ Code

```cpp
void bubbleSort(int arr[], int n) {
    bool swapped;
    for(int i = 0; i < n - 1; i++) {
        swapped = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }
}
```

---

## ⏱ Time and Space Complexity

| Case                        | Time Complexity |
| --------------------------- | --------------- |
| Best Case (already sorted)  | **O(n)**        |
| Average Case                | **O(n²)**       |
| Worst Case (reverse sorted) | **O(n²)**       |

**Space Complexity:**

* **O(1)** (In-place sorting)

---

## 🧪 Characteristics of Bubble Sort

| Property         | Description             |
| ---------------- | ----------------------- |
| Stable           | Yes                     |
| In-place         | Yes                     |
| Adaptive         | Yes (optimized version) |
| Recursive        | No                      |
| Comparison-based | Yes                     |

---

## 📌 Applications of Bubble Sort

Bubble Sort is mainly used for **educational and limited practical purposes**:

1. Teaching sorting algorithms to beginners
2. Understanding swapping and comparisons
3. Sorting very small datasets
4. Detecting if a list is already sorted
5. Academic demonstrations and lab exercises

---

## ✅ Advantages of Bubble Sort

1. Very easy to understand and implement
2. Does not require extra memory
3. Stable sorting algorithm
4. Works well for small datasets
5. Good for educational purposes

---

## ❌ Disadvantages of Bubble Sort

1. Very slow for large datasets
2. Poor time complexity (O(n²))
3. Inefficient compared to modern algorithms
4. Not suitable for real-world applications
5. High number of comparisons and swaps

---

## 📊 Bubble Sort 
| Algorithm      | Average Time |
| -------------- | ------------ |
| Bubble Sort    | O(n²)        |

---

## 🎓 Educational Importance

Bubble Sort is often the **first sorting algorithm** taught in:

* Data Structures
* Programming Fundamentals
* Algorithm Design

It builds the foundation for understanding:

* Loop nesting
* Time complexity
* Optimization techniques

---


