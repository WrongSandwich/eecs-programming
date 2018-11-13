#include "BinaryNodeTree.h"
#include "BinaryNode.h"

#include <iostream>

//------------------------------------------------------------
// Protected Utility Methods Section:
// Recursive helper methods for the public methods.
//------------------------------------------------------------

template <class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{
  if (subTreePtr != nullptr)
  {
    destroyTree(subTreePtr->getLeftChildPtr());
    destroyTree(subTreePtr->getRightChildPtr());
    delete subTreePtr; //MIGHT BE WRONG KIND OF DELETE?
  }
}

template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const
{
  BinaryNode<ItemType>* newTreePtr = nullptr;
  if (treePtr != nullptr)
  {
    newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(), nullptr, nullptr);
    newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
    newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
  }
  return newTreePtr;
}

template <class ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if (treePtr != nullptr)
  {
    ItemType item = treePtr->getItem();
    visit(item);
    preorder(visit, treePtr->getLeftChildPtr());
    preorder(visit, treePtr->getRightChildPtr());
  }
}

template <class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if (treePtr != nullptr)
  {
    inorder(visit, treePtr->getLeftChildPtr());
    ItemType item = treePtr->getItem();
    visit(item);
    inorder(visit, treePtr->getRightChildPtr());
  }
}

template <class ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if (treePtr != nullptr)
  {
    postorder(visit, treePtr->getLeftChildPtr());
    postorder(visit, treePtr->getRightChildPtr());
    ItemType item = treePtr->getItem();
    visit(item);
  }
}

//------------------------------------------------------------
// Constructor and Destructor Section.
//------------------------------------------------------------
template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr)
{
}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
{
  rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem,
                                         const BinaryNodeTree<ItemType>* leftTreePtr,
                                         const BinaryNodeTree<ItemType>* rightTreePtr)
{
  rootPtr = new BinaryNode<ItemType>(rootItem, copyTree(leftTreePtr->rootPtr),
                                               copyTree(rightTreePtr->rootPtr);
}

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& tree)
{
  rootPtr = copyTree(treePtr.rootPtr);
}

template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
  destroyTree(rootPtr);
}



//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------

template<class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
  preorder(visit, rootPtr);
}

template<class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
  inorder(visit, rootPtr);
}

template<class ItemType>
void postorderTraverse(void visit(ItemType&)) const
{
  postorder(visit, rootPtr);
}
