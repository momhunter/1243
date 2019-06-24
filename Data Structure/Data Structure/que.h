#pragma once
#include"all.h"

#define MAXSIZE 50

//duijiedian
template<class t>
class QNode
{
public:
	t data;
	QNode<t>* next;
};

//顺序队
template<class t>
class orderque
{
	t data[MAXSIZE];
	int front;
	int rear;
public:
	orderque();
	~orderque(){}
	bool enque(t d);
	bool deque(t d, t& ref);
	bool isempty();
	bool isfull();
};

//链队
template<class t>
class linkque
{
	QNode<t>* rear;
	QNode<t>* front;
	int length;
public:
	linkque();
	~linkque();
	bool isempty();
	bool enque(t d);
	bool deque(t& ref);
};

//顺序队实现

template<class t>
orderque<t>::orderque()
{
	front = rear = 0;
}

template<class t>
bool orderque<t>::enque(t d)
{
	if (isfull())
		return false;
	rear = (rear + 1) % MAXSIZE;
	data[rear] = d;
	return true;
}

template<class t>
bool orderque<t>::deque(t d, t& ref)
{
	if (isempty())
		return false;
	front = (front + 1) % MAXSIZE;
	ref = data[front];
	return true;
}

template<class t>
bool orderque<t>::isempty()
{
	return front == rear;
}

template<class t>
bool orderque<t>::isfull()
{
	return (rear + 1) % MAXSIZE == front;
}

//链队实现

template<class t>
linkque<t>::linkque()
{
	rear = new QNode<t>;
	front = new QNode<t>;
	rear->next = front->next = nullptr;
	length = 0;
}

template<class t>
linkque<t>::~linkque()
{
	while (rear != nullptr || front != nullptr)
	{
		if (rear->next!= nullptr)
		{
			QNode<t>* tmp = rear->next;
			rear->next = tmp->next;
			delete tmp;
		}
		if (front->next!= nullptr)
		{
			QNode<t>* tmp = front->next;
			front->next = tmp->next;
			delete tmp;
		}
	}
}

template<class t>
bool linkque<t>::isempty()
{
	return (rear == nullptr || front == nullptr);
}

template<class t>
bool linkque<t>::enque(t d)
{
	QNode<t>* tmp = new QNode<t>;
	tmp->data = d;
	tmp->next = nullptr;
	if (isempty())
		front = rear = tmp;
	else
	{
		rear->next = tmp;
		rear = tmp;
	}
	return true;
}

template<class t>
bool linkque<t>::deque(t& ref)
{
	QNode<t>* tmp = new QNode<t>;
	if (isempty())
		return false;
	else
		tmp = front;
	if (front == rear)
		front = rear = nullptr;
	else
		front = front->next;
	ref = tmp->data;
	delete tmp;
	return true;
}