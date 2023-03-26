#Maze Generator and Solver

This project implements a maze generator and solver program in C++. The program generates a random maze of size MxN and finds the path between designated entry and exit points in the maze. A stack implementation using a linked list data structure is used to solve the problem.

#Features

Generates random mazes of size MxN
Finds the path between designated entry and exit points in the maze
Implements stack using linked list data structure
Outputs maze files in a specific format for easy visualization
Uses mazeDrawer program for maze visualization
Requirements

C++11 or higher


Clone the repository to your local machine.
Open a terminal and navigate to the project directory.
Compile the project using the following command:
css
Copy code
g++ -std=c++11 main.cpp -o main
Run the program using the following command:
bash
Copy code
./main
Follow the instructions provided by the program to generate mazes and find the path.
Output Files

Maze Files
The mazes generated by the program are written to a file named maze_mazeID.txt, where mazeID ranges from 1 to K, with K being the number of mazes generated. The format of the file is as follows:

The first line lists the size of the maze, M and N.
For each cell in the maze, the x and y coordinates of the cell and the walls of the cell are listed. If there is a wall on the left (l), right (r), up (u), or down (d), 1 is assigned to the wall. Otherwise, 0 is assigned.
Path Files
The path generated by the program is written to a file named maze_mazeID_path_entryX_entryY_exitX_exitY.txt. The format of the file is as follows:

The file lists the coordinates of the cells to get from the entry point to the exit point, line by line.
