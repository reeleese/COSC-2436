/*
  Lee Reese
  Lab 2
*/

#include <iostream>
#include <string>
#include "MyString.h"

// menu functions
void storeString(MyString&, std::string);
void getLength(MyString&);
void combineString(MyString&);
void getIndex(MyString&);
void isSubstring(MyString&);

int main() {
  // Welcome Message
  std::cout << "MyString is a linked-list implementation of string.\n"
            << "Try it out.\n" << std::endl;

  // Initialize user's MyString
  std::cout << "First, you must make your own MyString" << std::endl;
  MyString user_string;
  storeString(user_string, "Enter a string to store as a MyString");

  // Menu Loop
  bool done = false;
  while (!done) {
    // Main Menu
    std::cout << "\nYour string is: " << user_string.toString() << std::endl;
    std::cout << "R)evise string, L)ength of string,\n"
              << "A)ppend to string, F)ind a character in your string,\n"
              << "T)est for a substring, Q)uit."
              << std::endl;

    // Prompt and record user option
    std::cout << "Option: ";
    char choice;
    std::cin.get(choice);
    std::cin.ignore(255, '\n');
    choice = tolower(choice);

    // Perform action associated with option
    switch(choice) {
      case 'r' : storeString(user_string,
                             "Enter a string to store as a MyString");
                 break;
      case 'l' : getLength(user_string);
                 break;
      case 'a' : combineString(user_string);
                 break;
      case 'f' : getIndex(user_string);
                 break;
      case 't' : isSubstring(user_string);
                 break;
      case 'q' : done = true;
                 break;
      default  : std::cout << "Not a valid option." << std::endl;
                 break;
    } // end switch
  } // end while
  return 0;
} // end main

void storeString(MyString& ms, std::string prompt) {
  std::cout << prompt << ": ";

  std::string str;
  std::getline(std::cin, str);
  ms = MyString(str);
}

void getLength(MyString& ms) {
  std::cout << "The length of your string is: "
            << ms.length() << std::endl;
}

void combineString(MyString& ms) {
  MyString toAppend;
  storeString(toAppend, "Enter a string to append");

  ms.append(toAppend);
}

void getIndex(MyString& ms) {
  std::cout << "Character to search for (case sensitive): ";

  char toFind;
  std::cin.get(toFind);
  std::cin.ignore(255, '\n');

  int index = ms.index(toFind);
  if (index == -1)
    std::cout << toFind << " was not found." << std::endl;
  else
    std::cout << "The first " << toFind << " is at index: "
              << index << std::endl; 
}

void isSubstring(MyString& ms) {
  MyString sub;
  storeString(sub, "Enter a string to test for substring");

  if (ms.substring(sub))
    std::cout << '\"' << sub.toString() << '\"'
              << " is a substring." << std::endl;
  else
    std::cout << '\"' << sub.toString() << '\"'
              << " is not a substring." << std::endl; 
  
}
