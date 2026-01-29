// Julio Carvajal, 14/06/2023, C
#include "Class.h"

Maze::Maze(int width, int height) : mazeWidth(width), mazeHeight(height) {
    for (int i = 0; i < mazeHeight; i++) {
        std::vector<Node> row;
        for (int j = 0; j < mazeWidth; j++) {
            row.push_back(Node{j, i});
        }
        cells.push_back(row);
    }
    start = &cells[0][rand() % mazeWidth];
    end = &cells[mazeHeight - 1][rand() % mazeWidth];
    start->walls[0] = false;
    end->walls[2] = false;
}
void Maze::generateMaze() {
    std::stack<Node*> cellStack;
    Node* currentCell = start;
    currentCell->visited = true;
    int totalVisitedCells = 1;

    while (totalVisitedCells < mazeWidth * mazeHeight) {
        std::vector<Node*> unvisitedNeighbours = getUnvisitedNeighbours(currentCell);

        if (!unvisitedNeighbours.empty()) {
            Node* chosenCell = unvisitedNeighbours[rand() % unvisitedNeighbours.size()];

            // Ta bort väggarna mellan nuvarande cell och valda cellen.
            connectNodes(currentCell, chosenCell);

            cellStack.push(currentCell);
            currentCell = chosenCell;
            currentCell->visited = true;
            totalVisitedCells++;
        }
        else if (!cellStack.empty()) {
            currentCell = cellStack.top();
            cellStack.pop();
        }
    }
}
//This function works as stödfuntion
std::vector<Maze::Node*> Maze::getUnvisitedNeighbours(Node* currentCell) {
    std::vector<Node*> unvisitedNeighbours;
    if (currentCell->posY > 0 && !cells[currentCell->posY-1][currentCell->posX].visited) {
        unvisitedNeighbours.push_back(&cells[currentCell->posY-1][currentCell->posX]);
    }
    if (currentCell->posX < mazeWidth-1 && !cells[currentCell->posY][currentCell->posX+1].visited) {
        unvisitedNeighbours.push_back(&cells[currentCell->posY][currentCell->posX+1]);
    }
    if (currentCell->posY < mazeHeight-1 && !cells[currentCell->posY+1][currentCell->posX].visited) {
        unvisitedNeighbours.push_back(&cells[currentCell->posY+1][currentCell->posX]);
    }
    if (currentCell->posX > 0 && !cells[currentCell->posY][currentCell->posX-1].visited) {
        unvisitedNeighbours.push_back(&cells[currentCell->posY][currentCell->posX-1]);
    }
    return unvisitedNeighbours;
}
//This function works as stödfunktion
void Maze::connectNodes(Node* currentCell, Node* chosenCell) {
    if (currentCell->posX < chosenCell->posX) {
        currentCell->walls[1] = false;
        chosenCell->walls[3] = false;
    }
    else if (currentCell->posX > chosenCell->posX) {
        currentCell->walls[3] = false;
        chosenCell->walls[1] = false;
    }
    else if (currentCell->posY < chosenCell->posY) {
        currentCell->walls[2] = false;
        chosenCell->walls[0] = false;
    }
    else if (currentCell->posY > chosenCell->posY) {
        currentCell->walls[0] = false;
        chosenCell->walls[2] = false;
    }
}
void Maze::drawMaze() {
    for (int i = 0; i < mazeWidth; i++) {
        std::cout << "+" << (i == start->posX && start->posY == 0 ? " S " : "---");
    }
    std::cout << "+\n";

    for (int i = 0; i < mazeHeight; i++) {
        for (int j = 0; j < mazeWidth; j++) {
            std::cout << (cells[i][j].walls[3] ? "| " : "  "); 
            std::cout << (cells[i][j].onPath ? ". " : "  ");
        }
        std::cout << "|\n";
        for (int j = 0; j < mazeWidth; j++) {
            std::cout << (j == end->posX && i == mazeHeight - 1 && end->posY == mazeHeight - 1 ? "+ E " : (cells[i][j].walls[2] ? "+---" : "+   "));
        }
        std::cout << "+\n";
    }
}




bool Maze::solveMazeRecursively(Node* currentCell) {
    currentCell->visited = true;
    if (currentCell == end) {
        currentCell->onPath = true; // Sätter onPath till true för slutcellen
        return true;
    }

    std::vector<Node*> unvisitedNeighbours;
    if (currentCell->posY > 0 && !cells[currentCell->posY-1][currentCell->posX].visited && !currentCell->walls[0]) {
        unvisitedNeighbours.push_back(&cells[currentCell->posY-1][currentCell->posX]);
    }
    if (currentCell->posX < mazeWidth-1 && !cells[currentCell->posY][currentCell->posX+1].visited && !currentCell->walls[1]) {
        unvisitedNeighbours.push_back(&cells[currentCell->posY][currentCell->posX+1]);
    }
    if (currentCell->posY < mazeHeight-1 && !cells[currentCell->posY+1][currentCell->posX].visited && !currentCell->walls[2]) {
        unvisitedNeighbours.push_back(&cells[currentCell->posY+1][currentCell->posX]);
    }
    if (currentCell->posX > 0 && !cells[currentCell->posY][currentCell->posX-1].visited && !currentCell->walls[3]) {
        unvisitedNeighbours.push_back(&cells[currentCell->posY][currentCell->posX-1]);
    }

    for (Node* neighbour : unvisitedNeighbours) {
        if (solveMazeRecursively(neighbour)) {
            currentCell->onPath = true; // Sätter onPath till true för alla celler på lösningens väg
            return true;
        }
    }

    currentCell->visited = false;
    return false;
}

void Maze::resetVisited() {
    for (int i = 0; i < mazeHeight; i++) {
        for (int j = 0; j < mazeWidth; j++) {
            cells[i][j].visited = false;
        }
    }
}

void Maze::solveMaze() {
    solveMazeRecursively(start);
}

void Maze::generateAndSolveMaze() {
    generateMaze();
    resetVisited();
    solveMaze();
    drawMaze();
}
