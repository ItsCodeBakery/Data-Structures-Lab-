
# ⏳ Project: The Time-Stream Stabilizer

## 📜 Mission Background
**Welcome, Time Agent.**

You work for the **Chronos Corporation**. The fabric of the universe is collapsing because historical events are becoming disordered. To save existence, we have digitized the timeline into a **Binary Search Tree (BST)**.

Your mission is to build the **Time-Stream Stabilizer** software. You must inject events into their correct chronological positions, remove paradoxes, and report the status of history.

## 🧠 The Data Structure
The timeline is strictly linear. You must implement a BST where every node is a **Time Capsule**:

```cpp
struct TimeCapsule {
    int year;               // The Key
    string eventName;       // The Data
    TimeCapsule* left;      // Earlier years
    TimeCapsule* right;     // Later years
};
````

### ⚡ The Laws of Time (BST Properties)

1.  **Chronological Order:** All years **smaller** than the current node must be in the **Left Subtree**.
2.  **Future Progression:** All years **larger** than the current node must be in the **Right Subtree**.
3.  **Uniqueness:** No two events can happen in the exact same year (Duplicate keys are not allowed).

-----

## 🛠️ Required Commands

Your system must accept the following command inputs:

| Command | BST Operation | Description |
| :--- | :--- | :--- |
| **`INJECT <Year> <Name>`** | **Insert** | Insert a new historical event. If the year exists, do nothing. |
| **`PARADOX <Year>`** | **Delete** | A time paradox has occurred\! Remove this year from the tree. (Handle cases with 0, 1, or 2 children). |
| **`SEARCH <Year>`** | **Search** | Check if an event exists in a specific year. Print the event name if found. |
| **`REPORT`** | **In-Order Traversal** | Print the entire timeline in chronological order (Ascending). |

-----

## 🧪 Sample Test Case

**Input Data:**

```text
INJECT 2050 "Mars Colony Established"
INJECT 1969 "Moon Landing"
INJECT 2100 "Warp Drive Invented"
INJECT 2000 "Y2K Bug"
SEARCH 1969
INJECT 1990 "World Wide Web"
PARADOX 2000
REPORT
SEARCH 2000
```

**Expected Console Output:**

```text
> System: Injecting 2050... Timeline stable.
> System: Injecting 1969... Timeline stable.
> System: Injecting 2100... Timeline stable.
> System: Injecting 2000... Timeline stable.

> Query: Searching for 1969...
> Result: Event Found! [1969: Moon Landing]

> System: Injecting 1990... Timeline stable.

> Alert: Paradox detected at 2000!
> System: Year 2000 removed. Timeline stabilized.

> COMMAND: CHRONOLOGICAL REPORT
-------------------------------
1969: Moon Landing
1990: World Wide Web
2050: Mars Colony Established
2100: Warp Drive Invented
-------------------------------

> Query: Searching for 2000...
> Result: Year 2000 not found in current timeline.
```

-----

## 🏆 Boss Level Challenge (Bonus)

If you complete the stabilizer early, implement the **Time Span Calculator**:

  * **Function:** `int CalculateTimeSpan()`
  * **Logic:** Find the earliest year (Min) and the latest year (Max) in the tree.
  * **Return:** `Max - Min`.
  * **Constraint:** You must do this by traversing the tree, not by sorting an array.

Good luck, Agent. 

```



