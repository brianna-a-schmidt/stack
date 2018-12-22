//NAME: StackArray.cpp
//DESC: array implementation of stack
//USAGE: #include "StackArray.cpp"
//COMPILER: GNU g++ compiler on Linux
//AUTHOR: Bri Schmidt
//LAST UPDATED: September 30, 2018 19:03

#include <StackArray.h>

//default constructor
//precondition: max stack specified in Stack.h
//postcondition: empty stack constructed
template <typename DataType>
StackArray<DataType>::StackArray() : top(-1)
{

}

//copy constructor
//precondition: valid stack to copy
//postcondition: a second stack is constructed from the first
//welp it says it's supplied by the compiler online soooooo... ???
template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other)
{
//probs don't need cuz all the same size
  maxSize = other->maxSize;

  for(int i = 0; i < maxSize; i++)
  {
    this->dataItems[i] = other->dataItems[i];
  }
}

//overloaded assignment operator
//precondition: valid stack to assigns
//postcondition: the stack now has all the values of the first
template <typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray& other)
{
  for(int i = 0; i < maxSize; i++)
  {
    this->dataItems[i] = other->dataItems[i];
  }
}

//deconstructor
//precondition: none
//postcondition: stack is destroyed
template <typename DataType>
StackArray<DataType>::~StackArray()
{

}

//push function
//precondition: stack is not full
//postcondition: data is added to top of Stack
template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error)
{
  if (top < maxSize - 1) //tests if stack has room
  {
    top++;
    dataItems[top] = newDataItem;
  }
  else
  {
    cout << "Stack is full, could not push" << endl;
  }
}

//pop function
//precondition: stack is not Empty
//postcondition: item from top of stack is removed
template <typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error)
{
  DataType result = 0;
  if(!isEmpty())
  {
    result = dataItems[top];
    top--;
  }
  return result;
}

//peek function
//precondition: stack is not Empty
//postcondition: copy of the top of stack is returned
template <typename DataType>
DataType StackArray<DataType>::peek() throw (logic_error)
{
  if(isEmpty())
  {
    cout << "Stack is empty, cannot peek" << endl;
    return 0;
  }
  else
  {
    return dataItems[top];
  }
}

//clear function
//precondition: stack is not Empty
//postcondition: stack is emptied
template <typename DataType>
void StackArray<DataType>::clear()
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
//isEmpty function
//precondition: stack exists
//postcondition: returns true if empty, false if not
template <typename DataType>
bool StackArray<DataType>::isEmpty() const
{
  return top < 0;
}

//isFull function
//precondition: stack exists
//postcondition: returns false if stack has room, true if not
template <typename DataType>
bool StackArray<DataType>::isFull() const
{
  return (top == (maxSize-1));
}

//show function
//precondition: stack exists
//postcondition: displays Stack
template <typename DataType>
void StackArray<DataType>::showStructure() const
{
  if( isEmpty() ) {
	cout << "Empty stack." << endl;
    }
    else {
	int j;
	cout << "Top = " << top << endl;
	for ( j = 0 ; j < maxSize ; j++ )
	    cout << j << "\t";
	cout << endl;
	for ( j = 0 ; j <= top  ; j++ )
	{
	    if( j == top )
	    {
	        cout << '[' << dataItems[j] << ']'<< "\t"; // Identify top
	    }
	    else
	    {
		cout << dataItems[j] << "\t";
	    }
	}
	cout << endl;
    }
    cout << endl;
  }
