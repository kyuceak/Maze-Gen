//
//  main.cpp
//  hw1.2
//
//  Kutay Yuceak
//


#include "maze.h"
#include "stack.h"
#include <iostream>
#include <fstream>





int main() {
    int maze_num ,M ,N;
    cout << "Enter the number of mazes: ";
    cin >> maze_num;
    cout << "Enter the number of rows and columns (M and N): ";
    cin >> M >> N;
    
    vector<Maze> maze_list;
    
    for(int i = 1; i <= maze_num; i++){
        vector<vector<Cell>> maze = create_maze(M, N);
        
        maze_list.push_back(Maze(maze,i));
        string fileName = "maze_"+ to_string(i) + ".txt";
        ofstream outfile(fileName);
        outfile << M << " " << N <<endl;
        
        for (int k = M-1; k >= 0; k--) {            // looping through 2d vector access walls information
            for (int j = 0; j < N; j++) {
                outfile << "x=" << j << " y=" << M-k-1 <<
                " l=" << (maze[k][j].walls[3] ? "1" : "0") <<
                " r=" << (maze[k][j].walls[1] ? "1" : "0") <<
                " u=" << (maze[k][j].walls[0] ? "1" : "0") <<
                " d=" << (maze[k][j].walls[2] ? "1" : "0") << endl;
            }
        }
        outfile.close();
    }
    
    
    cout << "All mazes are generated." << endl;
    cout << endl;
    
    int maze_id,  x_entry,  y_entry,  x_exit,  y_exit;
    
    cout << "Enter a maze ID between 1 to " << maze_list.size() <<" inclusive to find a path: ";
    cin >> maze_id;
    
    cout << "Enter x and y coordinates of the entry points (x,y) or (column,row): ";
    cin >> x_entry >> y_entry;
    
    cout << "Enter x and y coordinates of the exit points (x,y) or (column,row): ";
    cin >> x_exit >> y_exit;
    
    
    vector<Cell> path = generate_path(maze_list[maze_id-1].maze, x_entry, y_entry, x_exit, y_exit);
    
    string fileName2 = "maze_" + to_string(maze_id) + "_path_" + to_string(x_entry) + "_"
    + to_string(y_entry) + "_" + to_string(x_exit) + "_" + to_string(y_exit) + ".txt";
    
    ofstream outfile2(fileName2);
    
    for(const auto &cell :path){            // looping through the cells to access the cordinates.
        outfile2 << cell.x << " " << cell.y << endl;
    }
    return 0;
}
