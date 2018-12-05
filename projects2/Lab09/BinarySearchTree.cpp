/*******************************************************************************
*@author  Evan Trout
*@file    BinarySearchTree.cpp
*@date    11/27/2018
*@brief   Implementation file for the BinaryNodeTree class. Creates and maintains
*         a Binary Search Tree out of Binary Nodes. Header file created by
*         Carrano and Henry.
*******************************************************************************/

//------------------------------------------------------------
// Protected Utility Methods Section:
// Recursive helper methods for the public methods.
//------------------------------------------------------------
// Recursively finds where the given node should be placed and
// inserts it in a leaf at that point.
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::insertInorder(BinaryNode<ItemType>* subTreePtr,
                                    BinaryNode<ItemType>* newNode)
{
  if (subTreePtr == nullptr)
  {

  }
}

// Removes the given target value from the tree while maintaining a
// binary search tree.
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr,
                                  KeyType aKey,
                                  bool& success)
{

}

// Removes a given node from a tree while maintaining a
// binary search tree.
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeNode(BinaryNode<ItemType>* nodePtr)
{

}

// Removes the leftmost node in the left subtree of the node
// pointed to by nodePtr.
// Sets inorderSuccessor to the value in this node.
// Returns a pointer to the revised subtree.
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeLeftmostNode(BinaryNode<ItemType>* subTreePtr,
                                         ItemType& inorderSuccessor)
{

}

// Returns a pointer to the node containing the given value,
// or nullptr if not found.
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::findNode(BinaryNode<ItemType>* treePtr, KeyType aKey) const
{
  if treePtr == nullptr
  {
    return nullptr;
  }
  else if (treePtr->getItem().getID() == target)
  {
    return subTreePtr;
  }
  else if (treePtr->getItem().getID() < target)
  {
    return (findNode(treePtr->getLeftChildPtr(), aKey));
  }
  else
  {
    return (findNode(treePtr->getRightChildPtr(), aKey));
  }
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const
{
 if (subTreePtr == nullptr)
 {
   return 0;
 }
 else
 {
   return (1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr())));
 }
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const
{
  if (subTreePtr == nullptr)
  {
    return 0;
  }
  else
  {
    return (1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr -> getRightChildPtr()));
  }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{
  if (subTreePtr != nullptr)
  {
    destroyTree(subTreePtr->getLeftChildPtr());
    destroyTree(subTreePtr->getRightChildPtr());
    delete subTreePtr; //Is this the right type of delete?
  }
}

template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::copyTree(const BinaryNode<ItemType>* treePtr)
{
  BinaryNode<ItemType>* newTreePtr = nullptr;
  if (treePtr != nullptr)
  {
    newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(), nullptr, nullptr)
    newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
    newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
  }
  return newTreePtr;
}

// Recursive traversal helper methods:
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if (treePtr != nullptr)
  {
    ItemType item = treePtr->getItem();
    visit(item);
    preorder(visit, treePtr->getLeftChildPtr());
    preorder(visit, treePtr->getRightChildPtr());
  }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
  if (treePtr != nullptr)
  {
    inorder(visit, treePtr->getLeftChildPtr());
    ItemType item = treePtr->getItem();
    visit(item);
    inorder(visit, treePtr->getRightChildPtr());
  }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
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
template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree() : rootPtr(nullptr)
{
}

template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(const ItemType& rootItem)
{
  rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
}

template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(const BinarySearchTree<KeyType, ItemType>& tree)
{
  rootPtr = copyTree(tree.rootPtr);
}

template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
  destroyTree(rootPtr);
}

//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------
template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty() const
{
  return (rootPtr == nullptr);
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getHeight() const
{
  return getHeightHelper(rootPtr);
}

template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getNumberOfNodes() const
{
  return getNumberOfNodesHelper(rootPtr);
}

template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::add(const ItemType& newEntry)
{
  newTreePtr = new BinaryNode<ItemType>(newEntry, nullptr, nullptr)
  insertInorder(rootPtr, newTreePtr);
  //WHAT THE FUCK DO I RETURN
}

template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(const KeyType& aKey)
{
  findNode(rootPtr, aKey);
  removeValue(BinaryNode<ItemType>* subTreePtr, KeyType aKey, bool& success); //FIX FORMATTING ON THIS
}

template<typename KeyType, typename ItemType>
ItemType BinarySearchTree<KeyType, ItemType>::getEntry(const KeyType& aKey) const throw(NotFoundException)
{

}

// An entry in a BST can be set if and only if "item == aKey".
// If this is not the case, throw InvalidSetEntryRequest.
// If "aKey" does not exist in the tree, throw NotFoundException.
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::setEntry(const KeyType& aKey, const ItemType& item) const
 throw(NotFoundException, InvalidSetEntryRequest)
{

}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::contains(const KeyType& aKey) const
{

}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::clear()
{
  destroyTree(rootPtr);
}

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::preorderTraverse(void visit(ItemType&)) const
{
  preorder(visit, rootPtr);
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorderTraverse(void visit(ItemType&)) const
{
  inorder(visit, rootPtr);
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::postorderTraverse(void visit(ItemType&)) const
{
  postorder(visit, rootPtr);
}

//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------
template<typename KeyType, typename ItemType>
BinarySearchTree& BinarySearchTree<KeyType, ItemType>::operator=(const BinarySearchTree& rightHandSide)
{

}
