#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcep.h"
#include "NotFoundException.h"

#include <iostream>
#include <memory>

#define shared_ptr_BN std::shared_ptr<BinaryNode<ItemType>>

template<class ItemType>
class BinarySearchTree : public BinaryTreeInterface<ItemType> {

  
    
 private:
 shared_ptr_BN root;

 public:
 //------------------------------------------------------------
 // Constructor and Destructor
 //------------------------------------------------------------
 BinarySearchTree() {
   
 }

 BinarySearchTree(const ItemType& rootItem) {
   root(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr));
 }
 
 BinarySearchTree(const ItemType& rootItem,
		const std::shared_ptr<BinarySearchTree<ItemType>> leftTreePtr,
		const std::shared_ptr<BinarySearchTree<ItemType>> rightTreePtr) {
   
 }
 BinarySearchTree(const BinarySearchTree<ItemType>& tree);
 virtual ~BinarySearchTree() {
   root = nullptr;
 }
   
 //------------------------------------------------------------
 // Public Methods
 //------------------------------------------------------------
 bool isEmpty() const {
   return root == nullptr;
 }
 
 int getHeight() const {
   return getHeightHelper(root);
 }
 
 int getNumberOfNodes() const {
   return getNumberOfNodesHelper(root);
 }
 
 ItemType getRootData() const throw(PrecondViolatedExcep) {
   if (isEmpty())
     throw PrecondViolatedExcep("getRootData() called with empty tree."); 
   
   return root->getItem();
 }
 
 void setRootData(const ItemType& newData) {
   if (isEmpty())
     root = std::make_shared<BinaryNode<ItemType>>(newData, nullptr, nullptr);
   else
     root->setItem(newData);
 }
 
 bool add(const ItemType& newData) {
   return false;
 }
 bool remove(const ItemType& data) {
   return false;
 }

 void clear() {
   root = nullptr;
 }
 
 ItemType getEntry(const ItemType& anEntry) const throw(NotFoundException) {
   return anEntry;
 }

 bool contains(const ItemType& anEntry) const {
   return false;
 }
 
 //------------------------------------------------------------
 // Public Traversals
 //------------------------------------------------------------
 void preorderTraverse(void visit(ItemType&)) const {

 }

 void inorderTraverse(void visit(ItemType&)) const {

 }
 
 void postorderTraverse(void visit(ItemType&)) const {

 }
 
 //------------------------------------------------------------
 // Overloaded Operators
 //------------------------------------------------------------
 BinarySearchTree& operator=(const BinarySearchTree& RHS);

 //------------------------------------------------------------
 // Protected Methods
 //------------------------------------------------------------
 int getHeightHelper(shared_ptr_BN subTree) const {
   if (subTree == nullptr)
     return 0;
   else
     return 1 + std::max(getHeightHelper(subTree->getLeftChildPtr()),
			 getHeightHelper(subTree->getRightChildPtr()));
 }

 int getNumberOfNodesHelper(shared_ptr_BN subTree) const {
   if (subTree == nullptr)
      return 0;
   else
      return 1 + getNumberOfNodesHelper(subTree->getLeftChildPtr()) 
               + getNumberOfNodesHelper(subTree->getRightChildPtr());
 }

 
};
