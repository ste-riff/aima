// Exercise 2.7 - performance-measuring environment
#include <cstdlib>
#include <ctime>
#include <iostream>

const unsigned int lifetime = 1000;
enum action {Left, Right, Suck, NoOp};
unsigned int time = 0;
bool** world;

int main() {
  // Program title
  std::cout << "*** Intelligent Vacuum Cleaner Simulator ***" << std::endl;

  // Fetch world
  std::cout << " - World Definition -" << std::endl;
  std::cout << "   Rows: ";
  unsigned int rows;
  std::cin >> rows;
  std::cin.get();
  std::cout << "   Columns: ";
  unsigned int columns;
  std::cin >> columns;
  std::cin.get();
  std::cout << "World: " << rows << "x" << columns << "." << std::endl;
  std::cout << "Done." << std::endl;

  // Initialize world array
  world = new bool*[rows];
  for(int i = 0; i < rows; i++)
    world[i] = new bool[columns];

  // Seed random number generator
  srand(time(NULL));

  // Populate world array
  for(int x = 0; x < rows; x++)
    for(int y = 0; y < columns; y++)
      world[x][y] = rand() % 2;

  // Print world array
  for(int x = 0; x < rows; x++) {
    for(int y = 0; y < columns; y++)
      std::cout << world[x][y];
    std::cout << std::endl;
  }

  // Free world array
  for(int i = 0; i < rows; i++)
    delete [] world[i];
  delete [] world;
  
  return 0;
}
