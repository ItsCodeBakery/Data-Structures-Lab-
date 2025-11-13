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

