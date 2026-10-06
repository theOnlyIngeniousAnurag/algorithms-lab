# Design & Analysis of Algorithms Lab

![Language](https://img.shields.io/badge/Language-C-blue)
![Course](https://img.shields.io/badge/Course-Design%20%26%20Analysis%20of%20Algorithms-orange)
![Lab](https://img.shields.io/badge/Lab-Algorithms-green)
![Status](https://img.shields.io/badge/Status-In%20Progress-success)

A clean, student-friendly collection of programs and practical work completed for the **Design & Analysis of Algorithms Laboratory**.

This repository is organized lab-wise so that every experiment contains its source code, explanations, sample input/output, and other supporting material where required.

---

## 📚 About the Repository

The purpose of this repository is to maintain all Algorithms Laboratory experiments in a **clear, organized, reproducible, and GitHub-ready format**.

The repository focuses on:

- Understanding the logic behind important algorithms.
- Implementing algorithms in **C**.
- Studying how algorithms work step by step.
- Comparing different approaches to solving the same problem.
- Understanding time and space complexity.
- Keeping practical programs simple enough for laboratory use while maintaining correct algorithmic logic.

> **Note:** The programs are written for academic/laboratory purposes and prioritize clarity and correctness over unnecessary optimization or complexity.

---

## 🎯 Course Objectives

By completing the experiments in this repository, the following concepts are practiced:

- Searching techniques
- Sorting techniques
- Divide and conquer
- Greedy algorithms
- Dynamic programming
- Graph algorithms
- Minimum spanning trees
- Algorithm analysis
- Best, average, and worst-case analysis
- Time and space complexity
- Practical implementation of theoretical algorithms

---

## 🧰 Technologies & Tools

| Component | Used |
|---|---|
| Programming Language | **C** |
| Compiler | GCC / MinGW GCC |
| Editor / IDE | VS Code or any C-compatible IDE |
| Version Control | Git |
| Repository Hosting | GitHub |

No external libraries are required for the basic laboratory programs unless specifically mentioned inside an individual lab.

---

## 📁 Repository Structure

```text
Algorithms-Lab/
│
├── README.md
│
├── Lab-01/
│   ├── README.md
│   ├── Linear_Search/
│   │   ├── linear_search.c
│   │   └── explanation.md
│   │
│   └── Binary_Search/
│       ├── binary_search.c
│       └── explanation.md
│
├── Lab-02/
│   └── ...
│
├── Lab-03/
│   └── ...
│
└── ...
```

Each lab is kept in its own folder so that experiments can be added without mixing files from different practicals.

---

## 🔎 Labs Included

| Lab | Main Topic | Status |
|---|---|---|
| 01 | Linear Search & Binary Search | ✅ Completed |
| 02 | — | ⏳ To be added |
| 03 | — | ⏳ To be added |
| 04 | — | ⏳ To be added |
| ... | ... | ... |

The table will be updated as additional laboratory experiments are added.

---

## ▶️ How to Compile and Run

### Using GCC

Open a terminal in the directory containing the C file.

For example:

```bash
gcc linear_search.c -o linear_search
```

Run:

### Windows

```bash
linear_search.exe
```

### Linux / macOS

```bash
./linear_search
```

For Binary Search:

```bash
gcc binary_search.c -o binary_search
```

Then run the generated executable.

---

## 📝 General Lab File Convention

Each experiment is organized with a consistent structure wherever applicable:

1. **Aim**
2. **What the algorithm does**
3. **Algorithm / Logic**
4. **Program**
5. **Sample Input**
6. **Sample Output**
7. **Time Complexity**
8. **Space Complexity**
9. **Observation / Result**

This makes the repository useful not only for running the programs but also for practical-file revision and viva preparation.

---

## 🧠 Complexity Notation

The repository uses standard asymptotic notation:

- **O(1)** — Constant time
- **O(log n)** — Logarithmic time
- **O(n)** — Linear time
- **O(n log n)** — Linearithmic time
- **O(n²)** — Quadratic time

Where relevant, best-case, average-case, and worst-case complexities are documented separately.

---

## 🧪 Sample Input & Output

Sample input/output is included for individual experiments where it helps demonstrate program behavior.

Sample outputs are intended to show **expected program behavior**. Execution time values, when used in practical analysis, may vary depending on the system, compiler, input size, and background processes.

---

## ✅ Repository Quality Guidelines

Every lab added to this repository should follow these principles:

- Use meaningful filenames.
- Keep source code readable.
- Add useful comments for important logic.
- Avoid unnecessary libraries and complicated code.
- Keep the implementation consistent with the algorithm taught in the laboratory.
- Do not include passwords, API keys, personal information, or system-specific temporary files.
- Keep the README synchronized with the actual repository contents.
- Verify that programs compile and run before committing them.

---

## 🚀 Future Additions

As the laboratory progresses, this repository will be expanded with topics such as:

- Sorting algorithms
- Divide-and-conquer algorithms
- Greedy algorithms
- Dynamic programming
- Graph traversal and graph algorithms
- Minimum spanning tree algorithms
- Other syllabus-specific algorithmic techniques

---

## 👨‍💻 Academic Use

This repository is maintained as part of the **Design & Analysis of Algorithms Laboratory** coursework.

The goal is to keep the implementations simple, understandable, and suitable for academic learning, practical submission, viva preparation, and revision.

---

## ⭐ Repository Philosophy

> **Understand the logic → Write the algorithm → Implement it → Analyze it → Test it.**

The focus is not just on getting the program to work, but on understanding **why the algorithm works and how efficiently it solves the problem**.
