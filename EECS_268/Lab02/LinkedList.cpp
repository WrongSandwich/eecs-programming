template<class itemType>
Node<itemType>* LinkedList<itemType>::getNodeAt(int position) const
{
  if ((position>0) && (position<=itemCount))
  {
    int p = 1;
    Node<itemType>* ptr = headPtr;
    while(p!=position)
    {
      p++;
      ptr = ptr->getNext();
    }
    return ptr;
  }
  else return nullptr;
}


//See LinkedList.h and main on 268 site

template <class itemType>
LinkedList<itemType>::LinkedList() : headPtr(nullptr)
{
}

template <class itemType>
LinkedList<itemType>::LinkedList(const LinkedList<ItemType>& aList);
{
}

template <class itemType>
LinkedList<itemType>::~LinkedList()
{
}

template <class itemType>
bool LinkedList<itemType>::isEmpty() const;
{
  if (headPtr == nullptr) //If headPtr is nullptr then list is empty
  {
    return true;
  }
  else return false;
}

template <class itemType>
void LinkedList<T>::insert(int newPosition, const itemType& newEntry) throw (PrecondViolatedExcep)
{
  //Must first confirm that insertion is valid (pos is not too high or low)
  //Main has this list start at pos 1 which is why 0 is not allowed
  if (newPosition > 0) && (newPosition <= (itemCount + 1))
  {
    Node<itemType>* n = new Node<itemType>(newEntry);
    if (headPtr == nullptr) //Checking if list is empty, also could check itemCount
    {
      headPtr = n; //Make this node the new head
      itemCount = 1;
    }
    else if (newPosition == 1) //Adding something to head of list
    {
      n->setNext(headPtr);
      headPtr = n;
      itemCount++;
    }
    else
    {
      Node<itemType>* prev = getNodeAt(pos-1);
      n->setNext(prev->getNext()); //Setting n's pointer to next item in list
      prev->setNext(n);//Setting prev's pointer to point to new addition
      itemCount++;
    }
  }
  else throw PrecondViolatedExcep("error");
}
