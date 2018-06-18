/*
  Lee Reese
  Lab 2
*/

#include<string>
#include "Node.h"

class MyString {
private:
  Node<char>* head;
  Node<char>* tail;
  int size;
public:
  // Constructors
  MyString() {
    head = nullptr;
    tail = nullptr;
    size = 0;
  }
  MyString(const std::string s) {
    this->head = new Node<char>();
    Node<char>* prevNode = head;

    // Build list from head to tail, reading the string front to back
    for (char x: s) {
      Node<char>* currNode = new Node<char>();
      currNode->setData(x);
      prevNode->setNext(currNode);
      prevNode = currNode;
    }
    
    tail = prevNode;
    size = s.length();
  }

  // Accessors
  Node<char>* getHead() const {
    return this->head;
  }
  Node<char>* getTail() const {
    return this->tail;
  }
  int length() const {
    return size;
  }
  
  // Mutators
  void setHead(Node<char>* head) {
    this->head = head;
  }
  void setTail(Node<char>* tail) {
    this->tail = tail;
  }

  // Miscellaneous Methods
  void append(const MyString& ms);
  int index(char ch) const;
  bool substring(const MyString& ms) const;
  bool substringHelper(Node<char>*, Node<char>*) const;
  std::string toString() const;
  /*~MyString();*/
};

// Sticks a new MyString onto the end of this one
void MyString::append(const MyString& ms) {
  // Point this tail to ms head->next
  Node<char>* next = ms.getHead()->getNext();
  this->getTail()->setNext(next);

  // Change this tail to ms's tail and alter size
  this->setTail(ms.getTail());
  this->size += ms.length();
}

// Finds the first occurence of a character. -1 if failure
int MyString::index(char ch) const {
  int index = 0;
  Node<char>* currNode = head->getNext();
  while (currNode != nullptr) {
    // Found ch, exit loop
    if(currNode->getData() == ch)
      return index;

    // Onwards...
    currNode = currNode->getNext();
    ++index;
  }
  return -1; // Failure
}

// This function just sets up substringHelper
bool MyString::substring(const MyString& ms) const {
  Node<char>* comp = ms.getHead()->getNext();
  Node<char>* curr = this->getHead()->getNext();
  return substringHelper(curr, comp);
}

// Determines if ms (from the helper) is a substring of this MyString
bool MyString::substringHelper(Node<char>* curr, Node<char>* comp) const {
  // Base case: end of this MyString  reached, but ms has more chars: FAIL
  if (curr == nullptr && comp != nullptr) {
    return false;
  }
  // Base case: end of ms reached at or before end of this MyString: PASS
  if (comp == nullptr) {
    return true;
  }
  // Inductive case: curr == comp; move on, incremeneting both chars
  if (curr->getData() == comp->getData())
    return substringHelper(curr->getNext(), comp->getNext());

  // Inductive case: curr != comp; move on, incrementing only curr
  return substringHelper(curr->getNext(), comp);
}

// returns std::string representation of this MyString
std::string MyString::toString() const {
  std::string s = "";
  Node<char>* currNode = head->getNext();
  while (currNode != nullptr) {
    s.push_back(currNode->getData());
    currNode = currNode->getNext();
  }
  return s;
}

/*
MyString::~MyString() {
  Node<char>* nodeToDeletePtr = getHead();
  while (getHead() != nullptr) {
     setHead(getHead()->getNext());

      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      
      nodeToDeletePtr = getHead();
   }  // end while
  size = 0;
}
*/
