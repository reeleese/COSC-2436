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
void display(ItemType array[]);


int main()
{
   double x[] = {1.1, 2.2, 3.3, 4.4, 5.5};
   display(x, 5);
   int num[] = {1, 2, 3, 4};
   display (num, 4);
   std::string s[] = {"aa", "bb", "cc"};
   display(s, 3);
   
}

/*-------------------------------------------------------------------------
  Display elements of any type (for which the output operator is defined)
  stored in an array.

  Precondition:  ElementType is a type parameter.
  Postcondition: First numElements of array have been output to cout.
 ------------------------------------------------------------------------*/
template <class itemType>
itemType maxArray(ElementType array[])
{
  if (numElements = 0)
    return array[0];
  else if (numElements > 0)
    return ()
}

/*
1.1  2.2  3.3  4.4  5.5
1  2  3  4
aa  bb  cc

--------------------------------
Process exited after 0.1019 seconds with return value 0
Press any key to continue . . .

*/
