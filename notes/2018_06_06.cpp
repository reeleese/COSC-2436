
#include<iostream>
struct Node {
  Node* next;
  int item;

  Node(int it):item(it),next(nullptr) {
  }
}; //end Node

struct Bag {
  Node* head;

  Bag() {
    head = nullptr;
  }
  
  void add(int item) {
    Node* newNode = new Node(item);

    if (head != nullptr) {
      newNode->next = head;
    }

    head = newNode;
  } // end add
  
  void remove(int item) {
    Node * curr = head;
    
    while(curr != nullptr && curr->item != item) {

      curr = curr->next;
    } // end while

    if (curr != nullptr) {
      curr->item = head->item;

      Node* oldNode = head;
      head = head->next;
      delete oldNode;
    } // end if
    
  }  //end remove
  
  void display() const {
    Node * curr = head;

    std::cout << "bag";
    while(curr != nullptr) {
      std::cout << " " << curr->item;

      curr = curr->next;
    } // end while
    std::cout << std::endl;
    
  } // end display

  void clear() {
    Node * curr = head;

    while(curr != nullptr) {
      Node* oldNode = curr;
      curr = curr->next;
      delete oldNode;
      curr = curr->next;
    } // end while

    head = nullptr;
  } // end clear
  
  ~Bag() {
    clear();
  } // end destructor
}; //end Bag

int main() {
  Bag b;
  b.display();

  b.add(3);
  b.add(5);
  b.add(7);
  b.display();

  b.remove(7);
  b.display();
  return 0;
}
