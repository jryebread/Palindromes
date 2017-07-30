#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"
/* ====== Class QUEUE ========*/
//A queue data structure (FIFO)
template<class T>
class Queue
{
public:
	bool isEmpty();
	void enqueue(T value);
	void dequeue();
	void dequeueBack();
	//peek
	T peek();
	T peekBack();
	//Indexes
	int ifront();
	int iback();
private:
	LinkedList<T> qdata;
};


/*Function: isEmpty
Author:	James Riback
Description: returns true if queue is empty, false if not empty
Outputs: boolean expression
*/
template<class T>
bool Queue<T>::isEmpty()
{
	return qdata.isEmpty();
}

/*Function: enqueue
Author:	James Riback
Description: adds a value to the back of the queue
Inputs: user inputted value
*/
template<class T>
void Queue<T>::enqueue(T value)
{
	//create new node add to back of line (enqueue)
	this->qdata.addBack(value);
}

/*Function: dequeue
Author:	James Riback
Description: if not empty, delete the front of the queue (dequeue)
*/
template<class T>
void Queue<T>::dequeue()
{
	if (qdata.isEmpty())
	{
		return;
	}
	else //if not empty
	{
		//delete the next element in line (Head)
		qdata.deleteFront();
	}
}
/*Function: dequeueBack
Author:	James Riback
Description: if not empty, delete the back of the queue
*/
template<class T>
void Queue<T>::dequeueBack()
{
	if (qdata.isEmpty())
	{
		return;
	}
	else //if not empty
	{
		//delete the last element (tail)
		qdata.deleteBack();
	}
}
/*Function: ifront
Author:	James Riback
Description: returns an index of the front of the q
Outputs: Beggining index
*/
template<class T>
int Queue<T>::ifront()
{
	return qdata.indexBegin();
}
/*Function: iback
Author:	James Riback
Description: returns an index for the back of the q
Outputs: ending index
*/
template<class T>
int Queue<T>::iback()
{
	return qdata.indexEnd();
}
/*Function: peek
Author:	James Riback
Description: return the next in line of the queue's data (Head's data)
Outputs: Head data
*/
template<class T>
T Queue<T>::peek()
{
	return qdata.getHead()->data;
}
/*Function: peekBack
Author:	James Riback
Description: return the back in line's Data (tail's Data)
Outputs: Tail data
*/
template<class T>
 T Queue<T>::peekBack()
{
	 return qdata.getTail()->data;
}
#endif