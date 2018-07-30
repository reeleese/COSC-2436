#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcep.h"
#include "NotFoundException.h"

#include <iostream>
#include <memory>

using shared_ptr_BN = std::shared_ptr<BinaryNode<ItemType>>

template<class ItemType>
class BinarySearchTree : public BinaryTreeInterface<ItemType> {
 private:
  shared_ptr_BN root;

 public:
 //------------------------------------------------------------
 // Constructor and Destructor Section.
 //------------------------------------------------------------
 BinaryNodeTree() {}

 BinaryNodeTree(const ItemType& rootItem) {
   root(std::make_shared<BinaryNode<ItemType>>(rootItem, bullptr, nullptr));
 }
 
 BinaryNodeTree(const ItemType& rootItem,
		const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
		const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr) {
   
 }
 BinaryNodeTree(const BinaryNodeTree<ItemType>& tree);
 virtual ~BinaryNodeTree();
   
 //------------------------------------------------------------
 // Public BinaryTreeInterface Methods Section.
 //------------------------------------------------------------
 bool isEmpty() const;
 int getHeight() const;
 int getNumberOfNodes() const;
 ItemType getRootData() const throw(PrecondViolatedExcep);
 void setRootData(const ItemType& newData);
 bool add(const ItemType& newData); // Adds a node
 bool remove(const ItemType& data); // Removes a node
 void clear();
 ItemType getEntry(const ItemType& anEntry) const throw(NotFoundException);
 bool contains(const ItemType& anEntry) const;
 
 //------------------------------------------------------------
 // Public Traversals Section.
 //------------------------------------------------------------
 void preorderTraverse(void visit(ItemType&)) const;
 void inorderTraverse(void visit(ItemType&)) const;
 void postorderTraverse(void visit(ItemType&)) const;
 
 //------------------------------------------------------------
 // Overloaded Operator Section.
 //------------------------------------------------------------
 BinaryNodeTree& operator=(const BinaryNodeTree& rightHandSide);
 
 
};
