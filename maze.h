
#ifndef maze_h
#define maze_h
#include <vector>



struct Cell{
    bool visited;
    bool walls[4]; // top = 0 | right = 1 | bottom = 2 | left = 3
    int x , y;
    Cell(int _x, int _y): x(_x), y(_y),visited(false){
        for (int i = 0; i < 4; i++) {
            walls[i] = true;
        }
    }
};

struct Maze{
    int id;
    std::vector<std::vector<Cell>> maze;
    Maze(std::vector<std::vector<Cell>> _maze, int _id): maze(_maze),id(_id){}
    
};

std::vector<std::vector<Cell>> create_maze(int M, int N);

std::vector<Cell> generate_path(std::vector<std::vector<Cell>> & maze, int x , int y, int exit_x, int exit_y);


#endif /* maze_h */

