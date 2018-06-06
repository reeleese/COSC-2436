/*
Ch. 2,  Programming Problems 2, pg. 94

Name the program maxarray.cpp. Make sure the following requirements are met. 

    - Program must compile and run.
    - maxArray function must be a recursive template function.
    - Add a main function to test the maxArray function
      so that you have a complete program.
    - Test the maxArray function on two arrays of different types.

Remember to upload all files before submitting.

      maxarray.cpp
*/

#include <iostream>
#include <string>

template <class ItemType>
ItemType maxArray(ItemType array[]);


int main()
{
  double x[] = {1.1, 2.2, 7.7, 3.3, 4.4, 5.5};
  std::cout << maxArray(x) << std::endl;

  int num[] = {5, 1, 2, 3, 4};
  std::cout << maxArray(num) << std::endl;
  
  std::string s[] = {"aa", "bb", "cc"};
  std::cout << maxArray(s) << std::endl; 
}

template <class ItemType>
ItemType maxArray(ItemType array[]) {
  return array[0];
}

