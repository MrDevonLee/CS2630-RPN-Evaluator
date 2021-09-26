#ifndef MY_QUEUE_H_
#define MY_QUEUE_H_

#include "ItemType.h"

// Exception objects to be thrown if an invalid operation occurs:

// Thrown if trying to remove an item from an empty queue
class EmptyQueue {};
// Thrown if trying to add an item to a full queue
class FullQueue {};

//----------------------------------------------------------------------
// This class is a data structure that handles an ordered list of items
// in a "queue" style. It follows a FIFO (first in first out)
// implementation so only the first-added item can be accessed at any
// given time. All of the elements added to an instance of this class
// must be of data type `ItemType`; which data type `ItemType`
// represents can be easily changed in file "ItemType.h" for easy
// reusability of this class. The size and status of the queue (empty or
// full) can be checked at any time.
//----------------------------------------------------------------------
class MyQueue
{
private:
	ItemType elements[MAX_ITEMS];  // Array to store items in queue
	int front, rear, size; // Attributes to store the state of the queue

public:
	//------------------------------------------------------------------
    // MyQueue constructor; initializes an empty queue.
    //------------------------------------------------------------------
	MyQueue();

	//------------------------------------------------------------------
	// Adds an item to the queue or throws a `FullQueue` exception
	// object if the queue is already full.
	// 
	// @param toEnqueue The item to be added to the queue
	//------------------------------------------------------------------
    void Enqueue(const ItemType toEnqueue);

	//------------------------------------------------------------------
	// Removes an item from the queue or throws an `EmptyQueue`
	// exception object if the queue is already empty.
	// 
	// @return The first element of the queue
	//------------------------------------------------------------------
    ItemType Dequeue();

	//------------------------------------------------------------------
	// Returns the number of items currently stored in the queue.
	// 
	// @return The number of items in the queue
	//------------------------------------------------------------------
	int GetSize();

	//------------------------------------------------------------------
	// Returns whether or not the queue is empty.
	// 
	// @return True if the queue is empty or false otherwise
	//------------------------------------------------------------------
	bool IsEmpty();

	//------------------------------------------------------------------
	// Returns whether or not the queue is full.
	// 
	// @return True if the queue is full or false otherwise
	//------------------------------------------------------------------
	bool IsFull();
};

#endif
