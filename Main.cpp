// Julio Carvajal, 14/06/2023, C
#include <iostream>
#include <limits>
#include <string>
#include "Class.h"

int main() {
    int width;
    int height;
    char command;
    Maze maze;
    std::string input;

    while (true) {
        std::cout << "Välkommen! Välj ett alternativ:\n"
                  << "1. Välj labyrintstorlek.\n"
                  << "2. Generera en standardlabyrint på 6x6.\n"
                  << "3. Avsluta programmet.\n";
        std::getline(std::cin, input);
        if (input.length() != 1) {
            std::cout << "Ogiltigt kommando.\n";
            continue;
        }
        command = input[0];

        if (command == '1') {
            std::cout << "Ange labyrintbredd: ";
            std::cin >> width;
            if (std::cin.fail()) {
                std::cerr << "Error: Invalid input. Please enter a number.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cout << "Ange labyrinthöjd: ";
            std::cin >> height;
            if (std::cin.fail()) {
                std::cerr << "Error: Invalid input. Please enter a number.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            if(width <= 3 || height <=3)
            {
            std::cerr << "Error: Maze width and height must be greater than 3" << std::endl;}
            else {
            maze = Maze(width,height);
            maze.generateAndSolveMaze();
            }
            
            // Ignore any remaining characters in the input stream
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
        } else if (command == '2') {
            width = 6;
            height = 6;
            maze = Maze(width,height);
            maze.generateAndSolveMaze();
        } else if (command == '3') {
            break;
        } else {
            std::cout << "Ogiltigt kommando.\n";
        }
    }

    return 0;
}
