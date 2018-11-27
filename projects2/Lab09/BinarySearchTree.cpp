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
BinaryNode<ItemType>* BinarySearchTree<ItemType>::insertInorder(BinaryNode<ItemType>* subTreePtr,
                                    BinaryNode<ItemType>* newNode)
{

}

// Removes the given target value from the tree while maintaining a
// binary search tree.
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr,
                                  KeyType aKey,
                                  bool& success)
{

}

// Removes a given node from a tree while maintaining a
// binary search tree.
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeNode(BinaryNode<ItemType>* nodePtr)
{

}

// Removes the leftmost node in the left subtree of the node
// pointed to by nodePtr.
// Sets inorderSuccessor to the value in this node.
// Returns a pointer to the revised subtree.
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* subTreePtr,
                                         ItemType& inorderSuccessor)
{

}

// Returns a pointer to the node containing the given value,
// or nullptr if not found.
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* treePtr, KeyType aKey) const
 {

 }

// Recursive traversal helper methods:
void BinarySearchTree<ItemType>::preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{

}
void BinarySearchTree<ItemType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{

}
void BinarySearchTree<ItemType>::postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{

}

//------------------------------------------------------------
// Constructor and Destructor Section.
//------------------------------------------------------------
BinarySearchTree<ItemType>::BinarySearchTree()
{

}

BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem)
{

}

BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree)
{

}

BinarySearchTree<ItemType>::~BinarySearchTree()
{

}

//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------
bool BinarySearchTree<ItemType>::isEmpty() const
{

}

int BinarySearchTree<ItemType>::getHeight() const
{

}

int BinarySearchTree<ItemType>::getNumberOfNodes() const
{

}

bool BinarySearchTree<ItemType>::add(const ItemType& newEntry)
{

}

bool BinarySearchTree<ItemType>::remove(const KeyType& aKey)
{

}

ItemType BinarySearchTree<ItemType>::getEntry(const KeyType& aKey) const throw(NotFoundException)
{

}

// An entry in a BST can be set if and only if "item == aKey".
// If this is not the case, throw InvalidSetEntryRequest.
// If "aKey" does not exist in the tree, throw NotFoundException.
void BinarySearchTree<ItemType>::setEntry(const KeyType& aKey, const ItemType& item) const
 throw(NotFoundException, InvalidSetEntryRequest)
{

}

bool BinarySearchTree<ItemType>::contains(const KeyType& aKey) const
{

}

void BinarySearchTree<ItemType>::clear()
{

}

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{

}

void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{

}

void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{

}

//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------
BinarySearchTree& BinarySearchTree<ItemType>::operator=(const BinarySearchTree& rightHandSide)
{

}
