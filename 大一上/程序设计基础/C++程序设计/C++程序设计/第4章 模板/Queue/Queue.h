/*
 * Queue.h
 *
 *  Created on: 2014-4-7
 *      Author: xuyy
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

template <class Type> class Queue;
template <class Type>
std::ostream & operator<<(std::ostream &, const Queue<Type> &);
template <class Type> class QueueItem{
// private class: no public section
	friend class Queue<Type>;
	QueueItem(const Type &t):item(t),next(0){}
	Type item; //value stored in this element
	QueueItem *next; // pointer to next element in the Queue

	friend std::ostream & operator<< <Type> (std::ostream &, const Queue<Type> &);
};

template <class Type> class Queue {
public:
	Queue(): head(0),tail(0){} // empty Queue
	Queue(const Queue &Q):head(0),tail(0){copy_elems(Q);}
	Queue & operator=(const Queue &);
	~Queue(){destroy();}
    // return element from head of Queue
	Type & front(){return head->item;}
	const Type & front() const {return head->item;}
	void push(const Type &); //add element to back of Queue
	void pop(); // remove element from head of Queue
	bool empty() const {return head==0;}
	void display() const;
private:
	QueueItem<Type> *head;
	QueueItem<Type> *tail;
	void destroy(); //delete all the elements
	void copy_elems(const Queue &);

	friend std::ostream & operator<< <Type> (std::ostream &, const Queue<Type> &);
};

#endif /* QUEUE_H_ */

