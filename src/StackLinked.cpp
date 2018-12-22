//NAME: StackLinked.cpp
//DESC: linked list implementation of stack
//USAGE: #include "StackLinked.cpp"
//COMPILER: GNU g++ compiler on Linux
//AUTHOR: Bri Schmidt
//LAST UPDATED: September 30, 2018 20:17

#include "StackLinked.h"

//default constructor
template <typename DataType>
StackLinked<DataType>::StackLinked() : top(nullptr), itemsInStack(0)
{

}

//copy constructor
//precondition: none
//postcondition: stack constructed from another stack
template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other)
{
  StackNode* origPtr = other->top;
  if(other->isEmpty())
  {
    top = nullptr;
    itemsInStack = 0;
  }
  else
  {
    top = new StackNode();
    this->dataItem = other->dataItem;
    StackNode* newPtr = top;
    origPtr = origPtr->next;
    while (origPtr != nullptr)
    {
        DataType nextItem = origPtr->dataItem;

        StackNode* newNodePtr = new StackNode;
        newPtr->dataItem = newNodePtr->dataItem;
        newPtr = newPtr->next;
        origPtr = origPtr->next;
    }
  }
}

//overloaded assignment operator
//precondition: none (accepts empty Stack)
//postcondition: stack with reassigned values from other stack
template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other)
{
  StackNode* origPtr = other->top;
  if(other->isEmpty())
  {
    top = nullptr;
    itemsInStack = 0;
  }
  else
  {
    top = new StackNode();
    this->dataItem = other->dataItem;
    StackNode* newPtr = top;
    origPtr = origPtr->next;
    while (origPtr != nullptr)
    {
        DataType nextItem = origPtr->dataItem;

        StackNode* newNodePtr = new StackNode;
        newPtr->dataItem = newNodePtr->dataItem;
        newPtr = newPtr->next;
        origPtr = origPtr->next;
    }
  }
}

//destructor
//precondition: stack isn't Empty
//postcondition: stack is emptied
template <typename DataType>
StackLinked<DataType>::~StackLinked()
{
  while (!isEmpty())
  {
    pop();
  }
}

//push function
//precondition: data to push
//postcondition: stack has additional item
template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
  itemsInStack++;
  StackNode* newNodePtr = new StackNode(newDataItem, top);
  top = newNodePtr;
  newNodePtr = nullptr;
}

//pop function
//precondition: stack isn't empty
//postcondition: stack loses the item on top
template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error)
{
  DataType popped;
  if(isEmpty())
  {
    cout << "Could not pop, stack is empty" << endl;
  }
  else
  {
    itemsInStack--;
    popped = top->dataItem;
    StackNode* nodeToDeletePtr = top;
    top = top->next;

    nodeToDeletePtr->next = nullptr;
    delete nodeToDeletePtr;
    nodeToDeletePtr = nullptr;
  }

  return popped;
}

//peek function
//precondition: stack is not Empty
//postcondition: copy of the top of stack is returned
template <typename DataType>
DataType StackLinked<DataType>::peek() throw (logic_error)
{
  if(isEmpty())
  {
    cout << "Stack is empty, cannot peek" << endl;
    return 0;
  }
  else
  {
    return top->dataItem;
  }
}

//clear function
//precondition: stack is not Empty
//postcondition: stack is emptied
template <typename DataType>
void StackLinked<DataType>::clear()
{
  if(isEmpty())
  {
    cout << "Could not clear stack, stack is already empty" << endl;
  }
  else
  {
    while (!isEmpty())
    {
      pop();
    }
  }
}

//empty function
//precondition: none
//postcondition: returns true if stack is empty, false otherwise
template <typename DataType>
bool StackLinked<DataType>::isEmpty() const
{
  if(top == nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//only for array implementation?
template <typename DataType>
bool StackLinked<DataType>::isFull() const
{
  return false;
}

//shows the Stack
//precondition: stack must not be Empty
//postcondition: the contents of the stack are displayed
template <typename DataType>
void StackLinked<DataType>::showStructure() const
{

    if( isEmpty() )
    {
	cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
	for (StackNode* temp = top; temp != 0; temp = temp->next) {
	    if( temp == top ) {
		cout << "[" << temp->dataItem << "]\t";
	    }
	    else {
		cout << temp->dataItem << "\t";
	    }
	}
        cout << "Bottom" << endl;
    }


}

//overloaded node constructor, assigns data and next ptr as passed
//precondition: data for the node, pointer for the node
//postcondition: a node is created from the data passed
template <typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType& nodeData, StackNode* nextPtr)
{
  dataItem = nodeData;
  next = nextPtr;
}
