#pragma once
#include"all.h"

#define MAXSIZE 50

//结点类
template<class t>
class LNode
{
public:
	t data;
	LNode<t>* next;
};

//顺序栈
template<class t>
class orderstack
{
	int top;
	t data[MAXSIZE];
public:
	orderstack();
	orderstack(t d);
	orderstack(t d[], int num);
	bool isempty() { return top == -1; }
	bool isfull() { return top == MAXSIZE - 1; }
	~orderstack(){}
	bool pop(t& re);
	bool push(t d);
};
//链栈
template<class t>
class  linkstack
{
	t data;
	LNode<t>* nex;
public:
	linkstack();
	linkstack(t d);
	linkstack(t* d, int num);
	~linkstack();
	bool isempty() { return nex == nullptr; }
	bool pop(t& d);
	bool push(t d);
};

//顺序栈实现
template<class t>
orderstack<t>::orderstack()
{
	top = -1;
}

template<class t>
orderstack<t>::orderstack(t d)
{
	top = 0;
	data[0] = d;
}

template<class t>
orderstack<t>::orderstack(t d[], int num)
{
	top = num - 1;
	for (int i = 0; i < num; i++)
		data[i] = d[i];
}

template<class t>
bool orderstack<t>::pop(t& re)
{
	if (isempty())
		return false;
	re = data[top--];
	return true;
}

template<class t>
bool orderstack<t>::push(t d)
{
	if (isfull())
		return false;
	data[++top] = d;
	return true;
}
//链栈实现
template<class t>
linkstack<t>::linkstack()
{
	nex = new LNode<t>;
	nex->next = nullptr;
}

template<class t>
linkstack<t>::linkstack(t d)
{
	LNode<t>* tmp=new LNode<t>;
	tmp->next = nullptr;
	tmp->data = d;
	tmp->next = nex->next;
	nex->next = tmp;
}

template<class t>
linkstack<t>::linkstack(t* d, int num)
{
	nex = new LNode<t>;
	nex->next = nullptr;
	for (int i = 0; i < num; i++)
	{
		LNode<t>* tmp = new LNode<t>;
		tmp->next = nullptr;
		tmp->data = d[i];
		tmp->next = nex->next;
		nex->next = tmp;
	}
}

template<class t>
linkstack<t>::~linkstack()
{
	while (nex->next != nullptr)
	{
		LNode<t>* tmp = nex->next;
		nex->next = tmp->next;
		delete tmp;
	}
		
}

template<class t>
bool linkstack<t>::pop(t& d)
{
	if (isempty())
		return false;
	d = nex->next->data;
	LNode<t>* tmp = nex->next;
	nex->next = tmp->next;
	delete tmp;
	return true;
}

template<class t>
bool linkstack<t>::push(t d)
{
	LNode<t>* tmp = new LNode<t>;
	tmp->next = nullptr;
	tmp->data = d;
	tmp->next = nex->next;
	nex->next = tmp;
	return true;
}