template <class itemType>
class Node {
private:
  itemType data;
  Node* next;
public:
  Node(itemType data, Node* next){
    setData(data);
    setNext(next);
  }
  
  itemType getData() const;
  Node* getNext() const;
  void setData(itemType data);
  void setNext(Node* next);
};

template <class itemType>
itemType Node<itemType>::getData() const{
  return data;
}

template <class itemType>
Node<itemType>* Node<itemType>::getNext() const{
  return next;
}

template <class itemType>
void Node<itemType>::setData(itemType data) {
  this->data = data;
}

template <class itemType>
void Node<itemType>::setNext(Node* next) {
  this->next = next;
}
