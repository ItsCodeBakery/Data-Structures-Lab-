# Student Performance Analytics System

## Background Story

You have been hired as a software developer for **EduTrack Systems**, a company that provides comprehensive academic performance analysis tools for educational institutions. The company has recently secured a contract with a prestigious university that wants to analyze student performance data from multiple departments across different semesters.

The university's legacy system stores student records in text files, and your task is to develop a robust data processing system that can handle these records efficiently using dynamic memory allocation techniques.

## Problem Description

The university maintains student records where each student has the following information:
- **Student ID** (a unique 6-digit number)
- **Student Name** (string, may contain spaces)
- **Department Code** (3-character string: CSE, EEE, MEC, CIV, etc.)
- **Semester** (integer: 1 to 8)
- **CGPA** (floating-point: 0.00 to 4.00)
- **Credit Hours Completed** (integer)
- **Enrollment Year** (4-digit year)

## Your Task

Develop a comprehensive C++ program that performs the following operations:

### Part 1: Data Ingestion and Storage
1. Read student records from an input file named `students_data.txt`
2. Store all records in a **dynamically allocated linked list structure**
3. Each node should contain one complete student record
4. Handle any number of student records (the count is not known beforehand)

### Part 2: Multi-Criteria Analysis and Reporting

Your program must generate **four separate output files**, each containing differently organized student data:

#### Output File 1: `ranked_by_cgpa.txt`
- Organize students in **descending order of CGPA**
- For students with identical CGPA, arrange them by **Credit Hours Completed** (descending)
- Include ranking numbers (1st, 2nd, 3rd, etc.)
- Display all student information in a formatted table

#### Output File 2: `sorted_by_enrollment.txt`
- Organize students in **ascending order of Enrollment Year**
- Within the same year, sort by **Student ID** (ascending)
- Create separate sections for each enrollment year
- Calculate and display average CGPA for each enrollment year cohort

#### Output File 3: `department_analysis.txt`
- Group students by **Department Code** (alphabetically)
- Within each department, arrange students by **Semester** (ascending)
- Within the same semester, order by **CGPA** (descending)
- Calculate department-wise statistics:
  - Total students in department
  - Average CGPA
  - Highest and lowest CGPA
  - Average credit hours completed

#### Output File 4: `performance_tiers.txt`
- Categorize students into performance tiers:
  - **Elite Tier**: CGPA ≥ 3.70
  - **High Achievers**: 3.30 ≤ CGPA < 3.70
  - **Good Standing**: 3.00 ≤ CGPA < 3.30
  - **Satisfactory**: 2.50 ≤ CGPA < 3.00
  - **Needs Improvement**: CGPA < 2.50
- Within each tier, arrange students alphabetically by name
- Display the count and percentage of students in each tier

## Input File Format

The `students_data.txt` file will follow this format:

```
<Total_Number_of_Students>
<Student_ID> <Student_Name> <Department_Code> <Semester> <CGPA> <Credit_Hours> <Enrollment_Year>
<Student_ID> <Student_Name> <Department_Code> <Semester> <CGPA> <Credit_Hours> <Enrollment_Year>
...
```

**Example:**
```
5
202301 Alice Johnson CSE 5 3.85 142 2020
202145 Bob Smith EEE 6 3.92 168 2019
203012 Charlie Brown MEC 3 3.45 89 2022
201987 Diana Prince CSE 7 3.78 195 2018
202589 Edward Stark CIV 4 3.21 112 2021
```

## Technical Requirements

### Mandatory Implementation Constraints:

1. **Dynamic Memory Management**
   - Use a singly linked list with dynamic node allocation
   - Implement proper memory deallocation (no memory leaks)
   - Do NOT use arrays or vectors for primary storage

2. **Sorting Methodology**
   - You must implement **at least two different comparison-based sorting algorithms**
   - Each sorting algorithm should be applied to different output file requirements
   - Consider algorithms that work efficiently with linked list structures
   - Your implementation should handle sorting by comparing adjacent or selected elements
   - Optimize for scenarios where data might be partially sorted

3. **File Handling**
   - All input must be read from files
   - All output must be written to files (no console output for data)
   - Implement error handling for file operations
   - Format output files for readability with proper alignment

4. **Code Organization**
   - Use separate functions for different sorting operations
   - Implement modular design with clear function purposes
   - Use structures/classes for student records
   - Include appropriate comments and documentation

5. **Data Integrity**
   - Preserve the original linked list data while creating sorted outputs
   - Validate data ranges (CGPA should be 0.00-4.00, Semester 1-8, etc.)
   - Handle edge cases (empty file, single student, identical values)

## Advanced Challenges (Bonus Points)

1. **Search Functionality**: Implement a function to search for students by ID and append search results to a file named `search_results.txt`

2. **Performance Metrics**: Calculate and report the number of comparisons and swaps performed by each sorting algorithm in a file named `algorithm_performance.txt`

3. **Data Validation**: Identify and report any data anomalies (invalid CGPA, impossible credit hours for semester, etc.) in `data_issues.txt`

4. **Duplicate Detection**: Detect and report any duplicate Student IDs in `duplicates_report.txt`

## Deliverables

1. Complete C++ source code files (.cpp and .h files if using header files)
2. Sample input file (`students_data.txt`) with at least 25 student records
3. All four output files generated by your program
4. A brief documentation file (README.txt) explaining:
   - Your sorting algorithm choices and rationale
   - How to compile and run your program
   - Any assumptions made
   - Complexity analysis of your sorting implementations

## Evaluation Criteria

- **Correctness** (40%): Program produces accurate results for all outputs
- **Implementation Quality** (25%): Proper use of linked lists, efficient algorithms
- **Code Quality** (15%): Clean code, modular design, proper documentation
- **File Handling** (10%): Robust input/output operations
- **Edge Case Handling** (10%): Program handles various scenarios gracefully

## Sample Output Format (for `ranked_by_cgpa.txt`):

```
====================================================
        STUDENTS RANKED BY CGPA
====================================================
Rank | ID     | Name              | Dept | Sem | CGPA | Credits | Year
-----|--------|-------------------|------|-----|------|---------|------
  1  | 202145 | Bob Smith         | EEE  |  6  | 3.92 |   168   | 2019
  2  | 202301 | Alice Johnson     | CSE  |  5  | 3.85 |   142   | 2020
  3  | 201987 | Diana Prince      | CSE  |  7  | 3.78 |   195   | 2018
...
====================================================
```

## Important Notes

- Start early! This is a comprehensive problem requiring careful planning
- Test your program with various input sizes and edge cases
- Pay special attention to memory management to avoid leaks
- Consider the efficiency of your sorting approach for linked lists
- Make sure your output files are well-formatted and professional-looking

Good luck, and demonstrate your mastery of data structures and algorithms!
