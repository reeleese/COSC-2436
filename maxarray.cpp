/*
  Lab 1
  Author:   Lee Reese
  Due:      Friday 6/8 
  Filename: maxarray.cpp
*/

#include <iostream>
#include <string>
#include <algorithm> // std::max

template <class ItemType>
ItemType maxArray(ItemType[], int, int);

int main()
{
  double x[] = {1.1, 2.2, 7.7, 3.3, 4.4, 5.5};
  std::cout << maxArray(x, 0, 6) << std::endl;

  int num[] = {5, 1, 2, 3, 4};
  std::cout << maxArray(num, 0, 2) << std::endl;
  
  std::string s[] = {"aa", "bb", "cc"};
  std::cout << maxArray(s, 0, 2) << std::endl; 
} // end main

// Returns the maximum value in the range [first, last] on the array
template <class ItemType>
ItemType maxArray(ItemType array[], int first, int last) {
  // Base Case
  if (first == last)                                   
    return array[first];
  
  // Inductive Case
  else
    return std::max(maxArray(array, first           , (first+last)/2),
                    maxArray(array, (first+last)/2+1, last          ));
} // end maxArray

