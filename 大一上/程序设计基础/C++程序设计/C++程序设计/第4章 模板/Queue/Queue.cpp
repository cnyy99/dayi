/*
 * Queue.cpp
 *
 *  Created on: 2014-4-7
 *      Author: xuyy
 */

#include "Queue.h"
#include <iostream>
using namespace std;

template<class Type> void Queue<Type>::destroy(){
	while(!empty())
		pop();
}

template<class Type> void Queue<Type>::pop(){
	QueueItem<Type> * p = head;
	head = head->next;
	delete p;
}

template<class Type> void Queue<Type>::push(const Type & val){
	QueueItem<Type> * pt = new QueueItem<Type>(val);
	if(empty())
		head = tail = pt;
	else{
		tail->next = pt;
		tail = pt;
	}
}

template<class Type> void Queue<Type>::copy_elems(const Queue<Type> &orig){
	for(QueueItem<Type> * pt = orig.head; pt; pt = pt->next)
		push(pt->item);
}

template<class Type> Queue<Type> & Queue<Type>::operator=(const Queue<Type> & orig){
	for(QueueItem<Type> * pt = orig.head; pt; pt = pt->next)
			push(pt->item);
	return *this;
}

template<class Type> void Queue<Type>::display() const {
	for(QueueItem<Type> * pt = head; pt; pt = pt->next)
				cout<<pt->item<<" ";
}

template<class Type> ostream & operator<<(ostream & os, const Queue<Type> & q){
	os<<"< ";
	QueueItem<Type> * p;
	for(p = q.head; p; p = p->next)
		os<<p->item<<" ";
	os<<">";
	return os;
}

int main()
{
	Queue<int> qi;
	//short s = 42;
	//int i = 42;
	qi.push(1);
	qi.push(2);
	qi.push(3);
	qi.push(4);
	qi.push(5);
	qi.pop();
	qi.display();
	cout<<"\n";
	cout<<qi;
	cout<<endl;

	Queue<int> qi2(qi);
	qi2.display();
	cout<<endl;

	Queue<int> qi3;
	qi3 = qi;
	cout<<qi3;


	return 0;
}




