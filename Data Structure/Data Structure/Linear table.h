#pragma once
#include"all.h"
#define MAXSIZE 100

//结点类
template<class t>
class Node
{
public:
	t data;
	Node* next;
};

//顺序表
template<class t>
class ordertable
{
	t data[MAXSIZE];
	int length;
public:
	ordertable(t dat);
	ordertable(t* dat);
	ordertable(t* dat, int l);
	ordertable() { length = 0; };
	~ordertable() {  }
	int findpos(t dat);
	bool insert(t dat);
	int find(t dat);
	bool insert(t dat, int pos);
	bool delet(int pos, t& e);
	bool get(int pos, t& e);
	bool delet(t e);
	bool get(t e);
	void show()const;
	void reverse();
	void delblock(int i, int j);
	void order();
};

//单链表
template<class t>
class listt
{
	t data;
	Node<t>* first;
public:
	listt();
	listt(const listt&);
	listt(t dat[], int n);
	~listt();
	virtual Node<t>* gethead();
	virtual int getheight();
	virtual bool insert(t dat,int p);
	virtual t delet(int p);
	virtual int locate(t dat);
	virtual t find(int p);
	virtual void show()const;
	virtual void merge(Node<t>*b, Node<t>*& c);
	void redelet();
	void deletsmall();
};

//双链表


//循环单链表


//循环双链表


//静态链表

//顺序表实现
template<class t>
ordertable<t>::ordertable(t dat)
{
	data[0] = dat;
	length = 1;
}

template<class t>
ordertable<t>::ordertable(t* dat)
{
	int num = sizeof(dat);
	for (int i = 0; i < num; i++)
		data[i] = dat[i];
	length = num;
}

template<class t>
ordertable<t>::ordertable(t * dat, int l)
{
	for (int i = 0; i < l; i++)
		data[i] = dat[i];
	length = l;
}

template<class t>
int ordertable<t>::findpos(t dat)
{
	int i;
	for (i = 0; i < length; i++)
	{
		if (dat < data[i])
			return i;
	}
	return i;
}

template<class t>
bool ordertable<t>::insert(t dat)
{
	int p, i;
	p = findpos(dat);
	if (p<0 || p>MAXSIZE - 1 || p > length)
		return false;
	for (i = length - 1; i >= p; --i)
		data[i + 1] = data[i];
	data[p] = dat;
	++length;
	return true;
}

template<class t>
int ordertable<t>::find(t dat)
{
	if (length <= 0)
	{
		cout << "Table is empty!";
		return -1;
	}
	else
		for (int i = 0; i < length; i++)
		{
			if (data[i] == dat)
				return i+1;
		}
	cout << "Not found!";
	return -1;
}

template<class t>
bool ordertable<t>::insert(t dat, int pos)
{
	if (pos<0 || pos>length || pos > MAXSIZE)
		return false;
	for (int i = length - 1; i >= pos-1; --i)
		data[i + 1] = data[i];
	data[pos-1] = dat;
	length++;
	return true;
}

template<class t>
bool ordertable<t>::delet(int pos, t & e)
{
	if (pos<0 || pos>length - 1)
		return false;
	e = data[pos-1];
	for (int i = pos-1; i < length ; i++)
		data[i] = data[i + 1];
	length--;
	return true;
}

template<class t>
bool ordertable<t>::get(int pos, t & e)
{
	if (pos<0 || pos>length - 1)
		return false;
	e = data[pos];
	return true;
}

template<class t>
void ordertable<t>::show()const
{
	for (int i = 0; i < length; i++)
		cout << data[i] << '\t';
}

template<class t>
bool ordertable<t>::delet(t e)
{
	int p;
	p = find(e);
	if (e<0 || e>length)
	{
		cout << "No existance!";
		return false;
	}
	for (int i =p-1;i<length; ++i)
			data[i] = data[i+1];
	length--;
	return true;
}

template<class t>
bool get(t e)
{
	int p;
	p = find(e);
	return p;
}

template<class t>
void ordertable<t>::reverse()
{
	int i, j;
	t temp;
	for (i = 0,j=length-1; i < (length/2); j--,i++)
	{
		temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}
}

template<class t>
void ordertable<t>::delblock(int i, int j)
{
	int k, delta;
	delta = j - i + 1;
	for (k = j + 1; k < length; ++k)
		data[k - delta] = data[k];
	length -= delta;
}

template<class t>
void ordertable<t>::order()
{
	int head = data[0];
	int i = 0, j = length - 1;
	while (i < j)
	{
		while (i<j && data[j]>head)--j;
		if (i < j)
		{
			data[i] = data[j];
			++i;
		}
		while (i < j && data[i] < head)++i;
		if (i < j)
		{
			data[j] = data[i];
			--j;
		}
	}
	data[i] = head;
}

//链表实现
template<class t>
listt<t>::listt()
{
	first = new Node<t>;
	first->next = NULL;
}

template<class t>
listt<t>::listt(const listt& l)
{
	first = new Node<t>;
	first->next = l->gethead();
}

template<class t>
listt<t>::listt(t dat[], int n)
{
	first = new Node<t>;
	Node<t>* ch = first;
	for (int i = 0; i < n; i++)
	{
		Node<t>* tmp = new Node<t>;
		tmp->data = dat[i];
		ch->next = tmp;
		ch = tmp;
	}
	ch->next = NULL;
}

//尾插法
//template<class t>
//listt<t>::listt(t dat[], int n)
//{
//	first = new Node<t>;
//	Node<t> *ch = first;
//	for (int i = 0; i < n; i++)
//	{
//		Node<t> *tmp = new Node<t>;
//		tmp->data = dat[i];
//		ch->next = tmp;
//		ch = tmp;
//	}
//	ch->next = NULL;
//}

template<class t>
listt<t>::~listt()
{
	while (first->next != NULL)
	{
		Node<t>* tmp = first->next;
		first->next = first->next->next;
		delete tmp;
	}
}

template<class t>
Node<t>* listt<t>:: gethead()
{
	return first;
}

template<class t>
int listt<t>::getheight()
{
	Node<t>* tmp = first;
	int count = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		++count;
	}
	return count;
}

template<class t>
bool listt<t>::insert(t dat, int p)
{
	Node<t>* tmp = first;
	int count = 0;
	while (tmp != NULL && count < p - 1)
	{
		tmp = tmp->next;
		++count;
	}
	if (tmp == NULL)
		return false;
	else
	{
		Node<t>* back = new Node<t>;
		back->data = dat;
		back->next = tmp;
		tmp->next = back;
	}
}

template<class t>
t listt<t>::delet(int p)
{
	Node<t>* tmp = first;
	int count = 0;
	while (tmp != NULL && count < p - 1)
	{
		tmp = tmp->next;
		++count;
	}
	if (tmp == NULL || tmp->next == NULL)
	{
		cout << "Error!";
		return -1;
	}
	else
	{
		Node<t>* back = tmp->next;
		int x = back->data;
		tmp->next = tmp->next->next;
		delete back;
		return x;
	}
}

template<class t>
int listt<t>::locate(t dat)
{
	if (first == NULL)
	{
		cout << "List is empty!";
		return -1;
	}
	Node<t>* tmp = first->next;
	int count = 1;
	while (tmp != NULL)
	{
		if (tmp->data == dat)
			return count;
		tmp = tmp->next;
	}
	cout << "Not found!";
	return -1;
}

template<class t>
t listt<t>::find(int p)
{
	if (first == NULL)
	{
		cout << "List is empty!";
		return -1;
	}
	Node<t>* tmp = first->next;
	int count = 1;
	while (tmp != NULL&&count<p)
	{
		tmp = tmp->next;
		++count;
	}
	if (tmp == NULL)
	{
		cout << "Not found!";
		return -1;
	}
	return tmp->data;
}

template<class t>
void listt<t>::show()const
{
	Node<t>* tmp = first->next;
	while (tmp != NULL)
	{
		cout << tmp->data << '\t';
		tmp = tmp->next;
	}
}

template<class t>
void listt<t>::merge(Node<t>*b,Node<t>*&c)
{
	Node<t>* p = first->next;
	Node<t>* q = b->next;
	Node<t>* s;
	c = first;
	c->next = NULL;
	delete b;
	while (p != NULL && q != NULL)
	{
		if (p->data <= q->data)
		{
			s = p;
			p = p->next;
			s->next = c->next;
			c->next = s;
		}
		else
		{
			s = q;
			q = q->next;
			s->next = c->next;
			c->next = s;
		}
	}
	while (p != NULL)
	{
		s = p;
		p = p->next;
		s->next = c->next;
		c->next = s;
	}
	while (q != NULL)
	{
		s = q;
		q = q->next;
		s->next = c->next;
		c->next = s;
	}
}

template<class t>
void listt<t>::redelet()
{
	Node<t>* temp = first->next;
	Node<t>* back;
	while (temp->next != NULL)
	{
		if (temp->data == temp->next->data)
		{
			back = temp->next;
			temp->next = back->next;
			delete back;
		}
		else
			temp = temp->next;
	}
}

template<class t>
void listt<t>::deletsmall()
{
	Node<t>* pre = first, * p = pre->next, * min = p, * minpre = pre;
	while (p != nullptr)
	{
		if (p->data < min->data)
		{
			min = p;
			minpre = pre;
		}
		pre = p;
		p = p->next;
	}
	minpre->next = min->next;
	delete min;
}