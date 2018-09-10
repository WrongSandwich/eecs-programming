//See LinkedList.h and main on 268 site
template <typename T>
void LinkedList<T>::insert(int pos, T item) throw(PrecondViolatedExcept)
{
  //Must first confirm that insertion is valid (pos is not too high or low)
  //Main has this list start at pos 1 which is why 0 is not allowed
  if (pos > 0) && (pos <= (itemCount + 1))
  {
    SLNode<T>* n = new SLNode<T>(item);
    if (headPtr == nullptr) //Checking if list is empty, also could check itemCount
    {
      headPtr = n; //Make this node the new head
      itemCount = 1;
    }
    else if (pos == 1) //Adding something to head of list
    {
      n->setNext(headPtr);
      headPtr = n;
      itemCount++;
    }
    else
    {
      SLNode<T>* prev = getNodeAt(pos-1);
      n->setNext(prev->getNext()); //Setting n's pointer to next item in list
      prev->setNext(n);//Setting prev's pointer to point to new addition
      itemCount++;
    }
  }
  else throw PrecondViolatedExcept("error");
}

template<typename T>
SLNode<T>* LinkedList<T>::getNodeAt(int pos)
{
  if ((pos>0) && (pos<=itemCount))
  {
    int p = 1;
    SLNode<T>* ptr = headPtr;
    while(p!=position)
    {
      p++;
      ptr = ptr->getNext();
    }
    return ptr;
  }
  else return nullptr;
}
