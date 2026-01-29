// Julio Carvajal, 14/06/2023, C
#ifndef CLASS_H
#define CLASS_H
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdlib>


class Maze {
private:
    struct Node {
        int posX, posY;
        bool visited = false;
        bool onPath = false;
        bool walls[4] = {true, true, true, true};
        Node* parent = nullptr;
        std::vector<Node*> neighbours;
    };

    int mazeWidth;
    int mazeHeight;
    Node* start;
    Node* end;
    std::vector<std::vector<Node>> cells;

public:
    Maze(int width = 6, int height = 6);

    void generateMaze();
    void drawMaze();
    bool solveMazeRecursively(Node* currentCell);
    void resetVisited();
    void solveMaze();
    void generateAndSolveMaze();
    void connectNodes(Node* currentCell, Node* chosenCell);
    std::vector<Maze::Node*> getUnvisitedNeighbours(Maze::Node* currentCell);
};

#endif
