/*
Ch. 12, Programming Problems 1, pg. 392

Name the program sortedlist.cpp. Make sure the following requirements are met. 

    - Program must compile and run.
    - Driver program should insert 21 random numbers (1-100) on the list.
    - Generate a number from 1-100: rand() % 100 + 1
    - Then delete the last number inserted.
    - Last of all display the list.
    - No user input for driver program.
    - Use the Sorted List ADT SortedListInterface.h 

Remember to upload all files before submitting.

    sortedlist.cpp
*/

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "LinkedSortedList.h"

void displayList(LinkedSortedList<int> list) {
  for (int pos = 1; pos <= list.getLength(); pos++) {
    if (pos == list.getLength())
      std::cout << list.getEntry(pos);
    else
      std::cout << list.getEntry(pos) << ", ";
   }
  
  std::cout << std::endl << std::endl;
}

int main() {

  srand(time(NULL));

  // Populate new list with 21 random ints [1, 100]
  LinkedSortedList<int> sortedList = LinkedSortedList<int>();
  for (int i = 0; i < 21; ++i) {
    int rando = rand() % 100 + 1;
    sortedList.insertSorted(rando);
  }

  std::cout << "The list with 21 random integers:\n";
  displayList(sortedList);
  
  // Remove last item inserted
  sortedList.remove(21);

  // Display new list
  std::cout << "The list minus the last integer:\n";
  displayList(sortedList);
  
  
  return 0;
}
