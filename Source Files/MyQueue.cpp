#include "MyQueue.h"

//----------------------------------------------------------------------
// Default constructor of class `MyQueue`; initializes `front`, `rear`,
// and `size` to zero, indicating an empty queue with `elements[0]` as
// the location for the next-added item in the queue.
//----------------------------------------------------------------------
MyQueue::MyQueue()
{
	front = 0;  // Designates the index of the first-added item
	rear = 0;  // Designates the index of the item to add next
	size = 0;
}


//----------------------------------------------------------------------
// Adds `toEnqueue` to the next available slot in the queue, designated
// by `rear`. Rear is then incremented and wraps around to the first
// slot in the array if it would exceed the last slot in memory. This
// method throws a `FullQueue` exception object if the queue is already
// full.
// 
// @param toEnqueue The item to be added to the queue
//----------------------------------------------------------------------
void MyQueue::Enqueue(const ItemType toEnqueue)
{
	if (!IsFull())
	{
		elements[rear] = toEnqueue;
		rear = (rear + 1) % MAX_ITEMS;  // Circular array implementation
		size++;
	}
	else
		throw FullQueue();
}

//----------------------------------------------------------------------
// Returns the item designated by `front` and increments `front` to
// represent the new first element in the queue. `front` wraps around to
// first slot in the array if it reaches the last slot in memory. This
// method throws am `EmptyQueue` exception object if the queue is
// already empty.
// 
// @return The first iten in the queue, designated by `elements[front]`
//----------------------------------------------------------------------
ItemType MyQueue::Dequeue()
{
	if (!IsEmpty())
	{
		ItemType toReturn = elements[front];
		front = (front + 1) % MAX_ITEMS;
		size--;

		return toReturn;
	}
	else
		throw EmptyQueue();
}


//----------------------------------------------------------------------
// Returns the number of items currently stored in the queue, designated
// by the `size` attribute.
// 
// @return The number of items in the queue
//----------------------------------------------------------------------
int MyQueue::GetSize()
{
	return size;
}


//----------------------------------------------------------------------
// Returns whether or not the queue is empty based `size`.
// 
// @return True if the queue is empty or false otherwise
//----------------------------------------------------------------------
bool MyQueue::IsEmpty()
{
	return (size == 0);
}

//---------------------------------------------------------------------
// Returns whether or not the queue is full by comparing `size` to
// `MAX_ITEMS`.
// 
// @return True if the queue is full or false otherwise
//----------------------------------------------------------------------
bool MyQueue::IsFull()
{
	return (size == MAX_ITEMS);
}
