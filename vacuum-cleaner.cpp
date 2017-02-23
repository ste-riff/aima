// Exercise 2.7 - performance-measuring environment
#include <cstdlib>
#include <ctime>
#include <iostream>

const unsigned int lifetime = 1000;
enum action {Left, Right, Suck, NoOp};
unsigned int rounds = 0;
bool** world;

struct coord{
  unsigned int x;
  unsigned int y;
};

void welcome();
coord define_world();
void initialize_world(coord);
void free_world(coord);
void print_world(coord);

int main() {
  welcome();

  coord size = define_world();

  initialize_world(size);

  print_world(size);
  
  free_world(size);
  
  return 0;
}

void welcome() {
  // Program title
  std::cout << "*** Intelligent Vacuum Cleaner Simulator ***" << std::endl;
}

coord define_world() {
  coord world;
  
  // Fetch world
  std::cout << " - World Definition -" << std::endl;
  std::cout << "   Rows: ";
  std::cin >> world.x;
  std::cin.get();
  
  std::cout << "   Columns: ";
  std::cin >> world.y;
  std::cin.get();
  std::cout << "World: " << world.x << "x" << world.y << "." << std::endl;

  return world;
}

void initialize_world(coord size) {
  // Initialize world array
  world = new bool*[size.x];
  for(int i = 0; i < size.x; i++)
    world[i] = new bool[size.y];

  // Seed random number generator
  srand(time(NULL));

  // Populate world array
  for(int x = 0; x < size.x; x++)
    for(int y = 0; y < size.y; y++)
      world[x][y] = rand() % 2;
}

void free_world(coord size) {
  // Free world array
  for(int i = 0; i < size.x; i++)
    delete [] world[i];
  delete [] world;
}

void print_world(coord size) {
  // Print world array
  for(int x = 0; x < size.x; x++) {
    for(int y = 0; y < size.y; y++)
      std::cout << world[x][y];
    std::cout << std::endl;
  }
}
