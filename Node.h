/*
  Lee Reese
  Lab 2
*/

template <class ItemType>
class Node {
private:
  ItemType data;
  std::shared_ptr<Node<ItemType>> next;
public:
  // Constructors
  Node() {
    setNext(nullptr);
    setData(ItemType{});
  }
  Node(ItemType data, std::shared_ptr<Node<ItemType>> next){
    setData(data);
    setNext(next);
  }

  // Accessors
  ItemType getData() const {
    return data;
  }

  std::shared_ptr<Node<ItemType>> getNext() const {
    return next;
  }

  // Mutators
  void setData(ItemType data) {
    this->data = data;
  }

  void setNext(std::shared_ptr<Node<ItemType>> next) {
    this->next = next;
  }
};
