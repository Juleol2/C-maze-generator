# C-maze-generator

C++ Maze Generator & Solver
A robust C++ application that generates and solves complex labyrinths using Depth-First Search (DFS) algorithms. Developed as a final project for the "Object-Oriented Programming in C++" course at Mid Sweden University.
+1

This project demonstrates proficiency in low-level memory management, algorithmic logic, and data structure manipulation (Vectors, Stacks, and Pointers).

Key Features
Procedural Generation: Utilizes an iterative DFS algorithm with a std::stack to generate perfect mazes (no loops, fully accessible).

Pathfinding Solver: Implements a recursive DFS backtracking algorithm to find and visualize the optimal path from Start (S) to End (E).

Dynamic Memory & Structures: Built using custom Node structs with pointer-based neighbor traversal, avoiding rigid 2D array limitations.

Console Visualization: Renders the maze layout and solution path dynamically in the terminal.

 Technical Implementation
Language: C++ (Standard 11+)

Architecture: Object-Oriented Design (OOP) with strict encapsulation.

Core Algorithms:

Generation: Randomized Iterative Depth-First Search (Backtracking).

Solver: Recursive Depth-First Search.

Data Structures: std::vector, std::stack, custom struct Node.

 How it Works
The maze is modeled as a grid of Node objects. Each node contains pointers to its neighbors and boolean flags for walls.

Initialization: A grid of isolated cells is created.

Generation: The "Drunken Walk" approach (Iterative DFS) visits cells, knocking down walls between neighbors and pushing visited cells to a stack to allow backtracking when a dead-end is reached.

Solving: The solver traverses the generated maze recursively. When the 'End' node is found, the recursion unwinds, marking the successful path boolean onPath = true for visualization.


Build & Run
Prerequisites: G++ Compiler (or any standard C++ compiler).

Bash

# Clone the repository
git clone https://github.com/your-username/cpp-maze-generator.git

# Compile the source files
g++ Main.cpp Class.cpp -o maze_solver

# Run the application
./maze_solver
