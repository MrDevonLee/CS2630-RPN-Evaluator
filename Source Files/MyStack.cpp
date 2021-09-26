#include "MyStack.h"

//----------------------------------------------------------------------
// Default constructor of class `MyStack`; initializes `top` to -1,
// indicating an empty stack with `elements[0]` as the location for the
// next-added item in the stack.
//----------------------------------------------------------------------
MyStack::MyStack()
{
	// Represents the index of the last-added item, so an invalid index for an
	// empty stack makes sense
	top = -1;
}


//----------------------------------------------------------------------
// Adds `toPush` to the next available slot in the stack, designated by
// (`top` + 1). This method throws a `FullStack` exception object if the
// stack is already full.
// 
// @param toPush The item to be added to the stack
//----------------------------------------------------------------------
void MyStack::Push(const ItemType toPush)
{
	if (!IsFull())
		elements[++top] = toPush;
	else
		throw FullStack();
}

//----------------------------------------------------------------------
// Returns the item designated by `top` and decrements `top` to
// represent the new top element in the stack. This method throws am
// `EmptyStack` exception object if the stack is already empty.
// 
// @return The top item of the stack, designated by `elements[top]`
//----------------------------------------------------------------------
ItemType MyStack::Pop()
{
	if (!IsEmpty())
		return elements[top--];
	else
		throw EmptyStack();
}

//----------------------------------------------------------------------
// Returns the item designated by `top` without decrementing `top`. This
// method throws an `EmptyStack` exception object if the stack is
// already empty.
// 
// @return The top item of the stack, designated by `elements[top]`
//----------------------------------------------------------------------
ItemType MyStack::Peek()
{
	if (!IsEmpty())
		return elements[top];
	else
		throw EmptyStack();
}


//----------------------------------------------------------------------
// Returns the number of items currently stored in the stack, designated
// by the `top` attribute + 1 (since arrays in C++ are zero-indexed).
// 
// @return The number of items in the stack
//----------------------------------------------------------------------
int MyStack::GetSize()
{
	return (top + 1);
}


//----------------------------------------------------------------------
// Returns whether or not the stack is empty based `size`.
// 
// @return True if the stack is empty or false otherwise
//----------------------------------------------------------------------
bool MyStack::IsEmpty()
{
    return (top == -1);
}

//---------------------------------------------------------------------
// Returns whether or not the stack is full by comparing (`top` + 1) to
// `MAX_ITEMS`.
// 
// @return True if the stack is full or false otherwise
//----------------------------------------------------------------------
bool MyStack::IsFull()
{
	return ((top + 1) == MAX_ITEMS);
}
