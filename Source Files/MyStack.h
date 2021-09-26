#ifndef MY_STACK_H_
#define MY_STACK_H_

#include "ItemType.h"

// Exception objects to be thrown if an invalid operation occurs:

// Thrown if trying to remove an item from an empty stack
class EmptyStack {};
// Thrown if trying to add an item to a full stack
class FullStack {};

//----------------------------------------------------------------------
// This class is a data structure that handles an ordered list of items
// in a "stack" style. It follows a LIFO (last in first out)
// implementation so only the last-added item can be accessed at any
// given time. All of the elements added to an instance of this class
// must be of data type `ItemType`; which data type `ItemType`
// represents can be easily changed in file "ItemType.h" for easy
// reusability of this class. The size and status of the stack (empty or
// full) can be checked at any time.
//----------------------------------------------------------------------
class MyStack
{
private:
	ItemType elements[MAX_ITEMS];   // Array to store items in stack
	int top; // Attribute to store the state of the stack

public:
	//------------------------------------------------------------------
    // Mystack constructor; initializes an empty stack.
    //------------------------------------------------------------------
	MyStack();

	//------------------------------------------------------------------
	// Adds an item to the stack or throws a `FullStack` exception
	// object if the stack is already full.
	// 
	// @param toPush The item to be added to the stack
	//------------------------------------------------------------------
	void Push(const ItemType toPush);

	//------------------------------------------------------------------
	// Removes an item from the stack or throws an `EmptyStack`
	// exception object if the stack is already empty.
	// 
	// @return The first element of the stack
	//------------------------------------------------------------------
	ItemType Pop();

	//------------------------------------------------------------------
	// Returns an item from the stack without removing it or throws an
	// `EmptyStack` exception object if the stack is already empty.
	// 
	// @return The first element of the stack
	//------------------------------------------------------------------
	ItemType Peek();

	//------------------------------------------------------------------
	// Returns the number of items currently stored in the stack.
	// 
	// @return The number of items in the stack
	//------------------------------------------------------------------
	int GetSize();

	//------------------------------------------------------------------
	// Returns whether or not the stack is empty.
	// 
	// @return True if the stack is empty or false otherwise
	//------------------------------------------------------------------
	bool IsEmpty();

	//------------------------------------------------------------------
	// Returns whether or not the stack is full.
	// 
	// @return True if the stack is full or false otherwise
	//------------------------------------------------------------------
	bool IsFull();
};

#endif
