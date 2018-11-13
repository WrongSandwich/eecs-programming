#include "BinaryNodeTree.h"
#include "BinaryNode.h"

#include <iostream>

//Still need

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

}

template<class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{

}

template<class ItemType>
void postorderTraverse(void visit(ItemType&)) const
{

}