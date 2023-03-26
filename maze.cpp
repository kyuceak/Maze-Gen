//
//  maze.cpp
//  hw1.2
//
//  Created by Kutay Yüceak on 22.03.2023.
//



#include <random>
#include "stack.h"

#include "maze.h"


vector<pair<int, int>> get_unvisited_n_cells(vector<vector<Cell>>& maze, int x, int y, bool check_walls) {               // getting the unvisited neighbors from a given coordinate.
    vector<pair<int, int>> unvisited_cells;
    int M = maze.size();
    int N = maze[0].size();
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    
    for (int i = 0; i < 4; i++) { // the loop checks the all directions if its visited or in the boundary of the maze.
        int dif_x = x + dx[i];
        int dif_y = y + dy[i];
        
        if (dif_x >= 0 && dif_x < N && dif_y >= 0 && dif_y < M && !maze[M - dif_y - 1][dif_x].visited) {
            if (!check_walls || !maze[M-y-1][x].walls[i]) {
                unvisited_cells.push_back({dif_x, dif_y});
            }
        }
    }
    
    return unvisited_cells;
}








vector<vector<Cell>> create_maze(int M, int N) {
    Stack<pair<int, int>> stack;
    vector<vector<Cell>> maze(M, vector<Cell>(N, Cell(0, 0)));
    
    stack.push(make_pair(0, 0));
    
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 3);
    bool checkwall = false;
    while (!stack.isEmpty()) {
        int x = stack.top().first;
        int y = stack.top().second;
        
        
        
        // initializing the cell coordinate if its not initalized.
        if (!maze[M - y - 1][x].visited) {
            maze[M - y - 1][x].x = x;
            maze[M - y - 1][x].y = y;
            maze[M - y - 1][x].visited = true;
        }
        
        Cell& currentCell = maze[M - y - 1][x];
        
        
        vector<pair<int, int>> unvisitedNeighbors = get_unvisited_n_cells(maze, x, y,checkwall);
        
        if (!unvisitedNeighbors.empty()) {
            pair<int, int> random_cell = unvisitedNeighbors[dis(gen) % unvisitedNeighbors.size()];
            
            int random_X = random_cell.first;
            int random_Y = random_cell.second;
            
            // breaks the walls accordingly between the current cell and neighbor cell.
            if (random_X == x) {
                if (random_Y < y) {
                    currentCell.walls[2] = false;
                    maze[M - random_Y - 1][random_X].walls[0] = false;
                } else {
                    currentCell.walls[0] = false;
                    maze[M - random_Y - 1][random_X].walls[2] = false;
                }
            } else {
                if (random_X < x) {
                    currentCell.walls[3] = false;
                    maze[M - random_Y - 1][random_X].walls[1] = false;
                } else {
                    currentCell.walls[1] = false;
                    maze[M - random_Y - 1][random_X].walls[3] = false;
                }
            }
            
            
            stack.push({random_X, random_Y});
        } else {
            stack.pop();
        }
    }
    return maze;
}

void reset_visited(vector<vector<Cell>> & maze){       // the whole maze visited booleans are set to false.
    for(int i = 0; i < maze.size() ; i++ ){
        for( int j = 0; j < maze[0].size() ; j++){
            maze[i][j].visited = false;
            
            
        }
    }
}


vector<Cell> generate_path(vector<vector<Cell>> & maze, int x , int y, int exit_x, int exit_y){
    
    int M = maze.size();
    vector<Cell> cell_list;
    Stack<pair<int,int>> stack;
    stack.push(make_pair(x,y));
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0,3);
    bool checkwall= true;
    reset_visited(maze); // in order to loop again through the maze the visited boolean must be set to false again.
    while(!stack.isEmpty()){
        
        int top_x = stack.top().first;
        int top_y = stack.top().second;
        
        Cell& currentCell=maze[M-top_y-1][top_x];
        
        currentCell.visited=true;
        vector<pair<int, int>> unvisitedNeighbors = get_unvisited_n_cells(maze, top_x, top_y,checkwall);
        
        if(top_x == exit_x && top_y == exit_y) {    // checks if the found coordinate is the exit coordinate
            cell_list.push_back(currentCell);
            return cell_list;
        }
        
        if(!unvisitedNeighbors.empty()){
            cell_list.push_back(currentCell);
            
            pair<int,int> random_cell = unvisitedNeighbors[dis(gen) % unvisitedNeighbors.size()];
            
            stack.push(random_cell);
            
            
        }else{
            cell_list.pop_back();
            stack.pop();
        }
        
    }
    
    // If the function has not yet returned, the exit point was not found.
    return vector<Cell>();
}
