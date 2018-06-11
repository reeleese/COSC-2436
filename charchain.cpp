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
#include "Node.h"

class MyString {
  //private:
public:
  Node<char>* head;
public:
  MyString() {
    this->head = nullptr;
  }
  MyString(const std::string s) {
    this->head = new Node<char>();
    Node<char>* prevNode = head;
    for (char x: s) {
      Node<char>* currNode = new Node<char>();
      currNode->setData(x);
      prevNode->setNext(currNode);
      prevNode = currNode;
    }
    prevNode = nullptr;
  }
  int length() const;                           //
  void append(const MyString& ms);              //
  int index(char ch) const; // -1 if no match   // Done
  bool substring(const MyString& lc) const;     //
  std::string toString() const;                 // Done
};

int main() {
  Node<int>* one = new Node<int>(1, nullptr);
  Node<int>* two = new Node<int>(2, nullptr);
  one->setNext(two);
  std::cout << one->getNext()->getData() << std::endl;

  MyString test = MyString("henlo");
  std::cout << test.toString() << std::endl;

  std::cout << "index(h): " << test.index('h') << std::endl;
  std::cout << "index(o): " << test.index('o') << std::endl;
  std::cout << "index(y): " << test.index('y') << std::endl;
  
  return 0;
}

void MyString::append(const MyString& ms) {
  Node<char>* currNode = head->getNext();
  while (currNode->getNext() != nullptr) {
    currNode = currNode->getNext();
  }

  currNode->setNext(nullptr);
}

int MyString::index(char ch) const {
  int index = 0;
  Node<char>* currNode = head->getNext();
  while (currNode != nullptr) {
    if(currNode->getData() == ch)
      return index;
    currNode = currNode->getNext();
    ++index;
  }
  return -1;
}

std::string MyString::toString() const {
  std::string s = "";
  Node<char>* currNode = head->getNext();
  while (currNode != nullptr) {
    s.push_back(currNode->getData());
    currNode = currNode->getNext();
  }
  return s;
}
