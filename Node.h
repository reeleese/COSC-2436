/*
  Lee Reese
  Lab 2
*/

template <class itemType>
class Node {
private:
  itemType data;
  Node* next;
public:
  // Constructors
  Node() {
    setNext(nullptr);
    setData(itemType{});
  }
  Node(itemType data, Node* next){
    setData(data);
    setNext(next);
  }

  // Accessors
  itemType getData() const {
    return data;
  }

  Node* getNext() const {
    return next;
  }

  // Mutators
  void setData(itemType data) {
    this->data = data;
  }

  void setNext(Node* next) {
    this->next = next;
  }
};
