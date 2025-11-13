# C++ Stack Practice Problems

Here are several scenario-based problems designed to help you practice and understand the various uses of the Stack data structure.

---

## 🏛️ Problem 1: The Balanced Brackets Checker

### Scenario
You are building a linter for a new code editor. The most fundamental feature is checking for valid syntax. The first step is to ensure that all brackets (or parentheses) are **balanced**. This means every opening bracket has a matching closing bracket in the correct order.

### Task
Write a C++ function `bool areBracketsBalanced(string expression)` that takes a string and returns `true` if all brackets are balanced, and `false` otherwise.

Your function must handle three types of brackets:
* Parentheses: `(` and `)`
* Square Brackets: `[` and `]`
* Curly Braces: `{` and `}`

### Logic Hint
1.  Create a stack that can hold characters (`char`).
2.  Iterate through the `expression` string, character by character.
3.  If you encounter an **opening bracket** (`(`, `[`, or `{`), **push** it onto the stack.
4.  If you encounter a **closing bracket** (`)`, `]`, or `}`):
    * Check if the stack is **empty**. If it is, you found a closing bracket with no opener. Return `false`.
    * If it's not empty, **pop** the top element.
    * Check if the popped element is the **matching opener** for the current closing bracket.
        * If `)` is found, the popped element must be `(`.
        * If `]` is found, the popped element must be `[`.
        * If `}` is found, the popped element must be `{`.
    * If they do **not** match, return `false`.
5.  After the loop finishes, check if the stack is **empty**. If it is, all brackets were matched. Return `true`. If it's *not* empty, it means there are leftover opening brackets. Return `false`.

### Test Cases
* `"{[()]}"` $\to$ **true**
* `"{[(])}"` $\to$ **false** (Mismatched: `]` found, `(` expected)
* `"{{[[(())]]}}"` $\to$ **true**
* `"{"` $\to$ **false** (Leftover opener)
* `")"` $\to$ **false** (Closing bracket with no opener)

---

## 🎶 Problem 2: The Music Player 'Previous Track' Button

### Scenario
You are programming the logic for a music player (like Spotify or Apple Music). The player needs a "history" feature. When a user skips to the next song, the *previous* song should be saved in a "history" list. When the user hits the "Back" button, it should play the last song they were listening to.

This sounds just like a stack!

### Task
Design a `MusicPlayer` class.
* It should have a `string currentTrack`.
* It needs a `playTrack(string newTrack)` method. When this is called, it should:
    1.  Push the `currentTrack` onto a "history" stack.
    2.  Set `currentTrack` to the `newTrack`.
* It needs a `playPrevious()` method. When this is called, it should:
    1.  Check if the "history" stack is empty. If so, print "No previous tracks."
    2.  If not empty, **pop** the top track from the history stack and set it as the `currentTrack`.

### Logic Hint
You will need a stack that can store `string`s. (e.g., `std::stack<string>` or a custom stack that holds `string` data).

### Test Case
1.  `player.playTrack("Bohemian Rhapsody")`
    * (History stack is empty, `currentTrack` becomes "Bohemian Rhapsody")
2.  `player.playTrack("Stairway to Heaven")`
    * (Pushes "Bohemian Rhapsody" onto the stack, `currentTrack` becomes "Stairway to Heaven")
3.  `player.playTrack("Hotel California")`
    * (Pushes "Stairway to Heaven" onto the stack, `currentTrack` becomes "Hotel California")
4.  `player.playPrevious()`
    * (Pops "Stairway to Heaven". `currentTrack` is now "Stairway to Heaven".)
5.  `player.playPrevious()`
    * (Pops "Bohemian Rhapsody". `currentTrack` is now "Bohemian Rhapsody".)
6.  `player.playPrevious()`
    * (Stack is empty. Prints "No previous tracks.")

---

## 🧮 Problem 3: The Reverse Polish Notation (RPN) Calculator

### Scenario
You are asked to build a special calculator that doesn't need parentheses. It uses **Postfix Notation**, also known as Reverse Polish Notation (RPN). In RPN, the operator comes *after* the numbers.

* `2 + 3` becomes `2 3 +`
* `(2 + 3) * 4` becomes `2 3 + 4 *`

### Task
Write a function `int evaluatePostfix(string expression)` that takes a postfix expression string and returns the integer result.

* You can assume the expression has single-digit numbers (0-9) and the operators `+`, `-`, `*`, `/`.
* The numbers and operators will be separated by spaces (e.g., `"5 3 + 2 *"`).

### Logic Hint
1.  Create a stack that can hold `int`s.
2.  Split the input string by spaces.
3.  Iterate through each part of the expression.
4.  If the part is a **number**: **push** it onto the stack.
5.  If the part is an **operator** (`+`, `-`, `*`, `/`):
    * **Pop** the top value (call it `a`).
    * **Pop** the *next* top value (call it `b`).
    * Perform the operation: `b operator a` (Order matters for `-` and `/`!)
    * **Push** the result back onto the stack.
6.  After the loop, the stack should contain exactly one number: the final result. Return it.

### Test Cases
* `"5 3 +"` $\to$ (Pop 3, Pop 5, Push 5+3) $\to$ **8**
* `"5 3 + 2 *"` $\to$ (Push 5, Push 3, Pop 3, Pop 5, Push 8, Push 2, Pop 2, Pop 8, Push 8*2) $\to$ **16**
* `"7 4 - 3 *"` $\to$ (Push 7, Push 4, Pop 4, Pop 7, Push 3, Push 3, Pop 3, Pop 3, Push 3*3) $\to$ **9**
* `"8 4 /"` $\to$ (Pop 4, Pop 8, Push 8/4) $\to$ **2**

---

## 🧗 Problem 4 (Challenge): The Next Greater Element

### Scenario
You are working on a stock market analysis tool. For a list of daily stock prices, you want to find out, for each day, how many days you would have to wait until you find a day with a *higher* price.

A simpler version is: "For each element in an array, find the **next greater element** (NGE) to its right."

### Task
Write a function `vector<int> findNextGreaterElement(vector<int>& numbers)` that takes a vector of integers. It should return a new vector of the same size, where each element `i` is the NGE of `numbers[i]`. If no NGE exists to its right, use `-1`.

### Logic Hint
This is a non-obvious but perfect use of a stack.
1.  Create a stack that holds the **indices** of the numbers, not the numbers themselves.
2.  Create a `result` vector of the same size, initialized with `-1`.
3.  Iterate through the `numbers` array from **left to right** (let's say index `i`).
4.  **While** the stack is *not* empty AND the current number (`numbers[i]`) is *greater than* the number at the index on top of the stack (`numbers[stack.peek()]`):
    * You've found the NGE for the element on the stack!
    * `pop` the index from the stack (call it `topIndex`).
    * Set `result[topIndex] = numbers[i]`.
5.  After the `while` loop, **push** the current index `i` onto the stack.
6.  After the main loop finishes, any indices left in the stack have no NGE, but `result` is already initialized to -1, so you're done. Return `result`.

### Test Cases
* `[4, 5, 2, 10, 8]`
    * `i=0 (4)`: Push 0. Stack: `[0]`
    * `i=1 (5)`: 5 > 4. Pop 0. `result[0] = 5`. Push 1. Stack: `[1]`
    * `i=2 (2)`: 2 < 5. Push 2. Stack: `[1, 2]`
    * `i=3 (10)`: 10 > 2. Pop 2. `result[2] = 10`. 10 > 5. Pop 1. `result[1] = 10`. Push 3. Stack: `[3]`
    * `i=4 (8)`: 8 < 10. Push 4. Stack: `[3, 4]`
    * Loop ends. `result` vector is `[5, 10, 10, -1, -1]`. (Indices 3 and 4 in the stack had no NGE).
    * **Result: `[5, 10, 10, -1, -1]`**
