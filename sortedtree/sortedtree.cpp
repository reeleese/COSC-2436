/*
author: lee reese
*/

#include "BinarySearchTree.h"

#include <iostream>
#include <time.h>
#include <stdlib.h>

void display(int thing) {
  std::cout << thing << ' ';
}

int main() {

  srand(time(NULL));
  int rando = 0;
  BinarySearchTree<int> tree = BinarySearchTree<int>();
  for (int i = 0; i < 25; i++) {
    rando = rand() % 100 +1;
    tree.add(rando);
  }

  std::cout << "The list with 21 random integers:\n";
  tree.inorderTraverse(&display(int));

  tree.remove(rando);
  std::cout << "The list without " << rando << ":\n";
  
  return 0;
}
