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
   root = nullptr;
 }

 BinarySearchTree(const ItemType& rootItem) 
   :root(std::make_shared<BinaryNode<ItemType>>(rootItem, nullptr, nullptr))
 {}
 
 BinarySearchTree(const ItemType& rootItem,
		const std::shared_ptr<BinarySearchTree<ItemType>> leftTreePtr,
		const std::shared_ptr<BinarySearchTree<ItemType>> rightTreePtr)
   :root(std::make_shared<BinaryNode<ItemType>>(rootItem,
                                                copyTree(leftTreePtr->root),
                                                copyTree(rightTreePtr->root)))
   {}
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
   shared_ptr_BN newNode = std::make_shared<BinaryNode<ItemType>>(newData);
   root = placeNode(root, newNode);

   return true;
 }
 
 bool remove(const ItemType& data) {
   bool success = false;
   root = removeValue(root, data, success);
   return success;
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
   inorder(visit, root);
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
 protected:
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

 shared_ptr_BN placeNode(shared_ptr_BN subTree, shared_ptr_BN newNode) {
   if (subTree == nullptr)
     return newNode;
   
   if (subTree->getItem() > newNode->getItem()) {
     shared_ptr_BN temp = placeNode(subTree->getLeftChildPtr(), newNode);
     subTree->setLeftChildPtr(temp);
   }

   else {
     shared_ptr_BN temp = placeNode(subTree->getRightChildPtr(), newNode);
     subTree->setRightChildPtr(temp);
   }

   return subTree;
 }

 shared_ptr_BN findNode(shared_ptr_BN treePtr, const ItemType& target, bool& success) const {
   if (treePtr == nullptr) // not found here
     return treePtr;
   
   if (treePtr->getItem() == target) {
     success = true;
     return treePtr;
   }
   
   else {
     shared_ptr_BN targetNodePtr = findNode(treePtr->getLeftChildPtr(), target, success);
     if (!success) {
       targetNodePtr = findNode(treePtr->getRightChildPtr(), target, success);
     }
      
     return targetNodePtr;
   }  // end if 
 }  // end findNode

 shared_ptr_BN removeValue(shared_ptr_BN subTree, const ItemType& target, bool& success) {
   if (subTree == nullptr)
     success = false;

   else if (subTree->getItem() == target) {
     subTree = removeNode(subTree);
     success = true;
   }

   else if (subTree->getItem() > target) {
     shared_ptr_BN temp = removeValue(subTree->getRightChildPtr(), target, success);
     subTree->setLeftChildPtr(temp);
   }

   else {
     shared_ptr_BN temp = removeValue(subTree->getLeftChildPtr(), target, success);
     subTree->setRightChildPtr(temp);
   }

   return subTree;
 }

 shared_ptr_BN removeNode(shared_ptr_BN node) {
   if (node->isLeaf()) {
     return node;
   }

   else if ((node->getLeftChildPtr() == nullptr) xor (node->getRightChildPtr() == nullptr)) {
     shared_ptr_BN nodeToConnect;
     if (node->getLeftChildPtr() != nullptr)
       nodeToConnect = node->getLeftChildPtr();
     else
       nodeToConnect = node->getRightChildPtr();
     return nodeToConnect;
   }

   else {
     shared_ptr_BN temp = removeLeftmostNode(node->getRightChildPtr(), 0);
     node->setRightChildPtr(temp);
     node->setItem(0);
     return node;
   }
 }

 shared_ptr_BN removeLeftmostNode(shared_ptr_BN node, ItemType inorderSuccessor) {
   if (node->getLeftChildPtr() == nullptr) {
     inorderSuccessor = node->getItem();
     return removeNode(node);
   }

   else {
     shared_ptr_BN temp = removeLeftmostNode(node->getLeftChildPtr(), inorderSuccessor);
     node->setLeftChildPtr(temp);
     return node;
   }
 }

void inorder(void visit(ItemType&), std::shared_ptr<BinaryNode<ItemType>> treePtr) const
{
   if (treePtr != nullptr)
   {
      inorder(visit, treePtr->getLeftChildPtr());
      ItemType theItem = treePtr->getItem();
      visit(theItem);
      inorder(visit, treePtr->getRightChildPtr());
   }  // end if
}  // end inorder


 
};
