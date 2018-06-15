/*
Ch. 4, Programming Problem 8, pg. 157

Name the program charchain.cpp. Make sure the following requirements are met. 

    - Program must compile and run.
    - Create an ADT character string as a class 
      (LinkedChar is name I am using) that uses 
      a linked list of each character
    - The LinkedChar class minimally has the methods  
      in the UML diagram below. You can add more methods.
    - Main function will have a menu of options.
        -- Enter new string and store as linked list 
          of characters in an ADT LinkedChar class
        -- Get current length (number of characters stored) from LinkedChar 
        -- Append a LinkedChar to another LinkedChar 
        -- Find index of character in a LinkedChar 
        -- Test if a LinkedChar is substring of another LinkedChar 
        -- Quit
Remember to upload all files before submitting.

    charchain.cpp

*/

#include <iostream>
#include <string>
#include "MyString.h"

// menu functions
void tester();
void storeString(MyString&);
void getLength(MyString&);
void combineString(MyString&);
void getIndex(MyString&);
void isSubstring(MyString&);

int main() {
  std::cout << "MyString is a linked-list implementation of string.\n"
            << "Try it out.\n" << std::endl;
  std::cout << "Make sure to make a MyString before selecting other options.";

  bool done = false;
  while (!done) {
    std::cout << "\nm)ake new MyString, l)ength of MyString,\n"
              << "a)ppend to MyString, get i)ndex of a character,\n"
              << "test s)ubstring, q)uit."
              << std::endl;

    std::cout << "Option: ";
    char choice;
    std::cin.get(choice);
    std::cin.ignore();

    static MyString user_string;
    switch(choice) {
    case 'm' : storeString(user_string);
               break;
    case 'l' : getLength(user_string);
               break;
    case 'a' : combineString(user_string);
               break;
    case 'i' : getIndex(user_string);
               break;
    case 's' : isSubstring(user_string);
               break;
    case 'q' : done = true;
               break;
    } // end switch
  } // end while
} // end main

void storeString(MyString& ms) {
  std::cout << "Enter a string to store as a linked list: ";

  std::string str;
  std::getline(std::cin, str);
  ms = MyString(str);
}

void getLength(MyString& ms) {
  std::cout << "The length of your string is: "
            << ms.length() << std::endl;
}

void combineString(MyString& ms) {
  std::cout << "You will need another string." << std::endl;
  MyString toAppend;
  storeString(toAppend);

  ms.append(toAppend);
  std::cout << "Your new string is: " << ms.toString() << std::endl;
}

void getIndex(MyString& ms) {
  std::cout << "Character to search for (case sensitive): ";

  char toFind;
  std::cin.get(toFind);
  std::cin.ignore();

  int index = ms.index(toFind);
  if (index == -1)
    std::cout << toFind << " was not found." << std::endl;
  else
    std::cout << toFind << " is at: " << index << std::endl; 
}

void isSubstring(MyString& ms) {
  std::cout << "You will need another string." << std::endl;
  MyString sub;
  storeString(sub);

  if (ms.substring(sub))
    std::cout << sub.toString() << " is a substring." << std::endl;
  else
    std::cout << sub.toString() << " is not a substring." << std::endl; 
  
}

void tester() {
  Node<int>* one = new Node<int>(1, nullptr);
  Node<int>* two = new Node<int>(2, nullptr);
  one->setNext(two);
  std::cout << one->getNext()->getData() << std::endl;

  MyString test = MyString("henlo");
  std::cout << test.toString() << std::endl;

  std::cout << "index(h): " << test.index('h') << std::endl;
  std::cout << "index(o): " << test.index('o') << std::endl;
  std::cout << "index(y): " << test.index('y') << std::endl;

  std::cout << "tail: " << test.getTail()->getData() << std::endl;

  MyString test2 = MyString(" friend.");
  test.append(test2);
  std::cout << test.toString() << std::endl;

  MyString test3 = MyString("friend.s");
  std::cout << (test.substring(test3)?"yes":"no") << std::endl;
}

