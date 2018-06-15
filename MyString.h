#include<string>
#include "Node.h"

class MyString {
private:
  Node<char>* head;
  Node<char>* tail;
  int size;
public:
  MyString() {
    head = nullptr;
    size = 0;
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
    tail = prevNode;
    size = s.length();
  }
  Node<char>* getHead() const {
    return this->head;
  }
  Node<char>* getTail() const {
    return this->tail;
  }
  void setHead(Node<char>* head) {
    this->head = head;
  }
  int length() const {
    return size;
  }
  void append(const MyString& ms);              // Done
  int index(char ch) const; // -1 if no match   // Done
  bool substring(const MyString& ms ) const;    // Done
  std::string toString() const;                 // Done
};

void MyString::append(const MyString& ms) {
  Node<char>* next = ms.getHead()->getNext();
  this->tail->setNext(next);
  this->tail = ms.getTail();
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

bool MyString::substring(const MyString& ms) const {
  Node<char>* firstComp = ms.getHead()->getNext();
  Node<char>* curr = getHead()->getNext();

  Node<char>* comp = firstComp;
  while(curr != nullptr) {
    // I found the first char
    while(curr->getData() == comp->getData()) {
      curr = curr->getNext();
      comp = comp->getNext();
      if(comp == nullptr) return true;
      if(curr == nullptr) return false;
    }
    curr = curr->getNext();
    comp = firstComp;
  }
  return false;
}
