#include "Header.h"

void init(list& l)
{
	l.head = NULL;
	l.tail = NULL;
}
void add_tail(list& l, int x)
{
	node* p = new node;
	if (l.head == NULL)
	{
		p->data = x;
		l.head = p;
		l.tail = p;
	}
	else
	{
		p->data = x;
		l.tail->next = p;
		l.tail = p;
		l.tail->next = NULL;
	}
}
void read_file(list& l)
{
	int n = -1;
	ifstream file;
	file.open("input.txt", ios::in);
	if (file.fail())
	{
		cout << " Opening file fail !" << endl;
		exit(0);
	}
	while (file >> n)
	{
		add_tail(l, n);
	}
	file.close();
}
void output(list l)
{
	if (l.head != NULL)
	{
		node* p = l.head;
		while (p != NULL)
		{
			cout << p->data << "  ";
			p = p->next;
		}
	}
}
int length(list l)
{
	int count = 0;
	node* p = l.head;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;

}
node* createnode(int x)
{
	node* temp = new node;
	temp->next = NULL;
	temp->data = x;
	return temp;
}
node* addhead(node* p, int x)
{
	node* temp = new node;
	temp->data = x;
	temp->next = p;
	p = temp;
	return p;

}
node* addtail(node* p, int x)
{
	node* q = p;
	while (p->next != NULL)
	{
		p = p->next;
	}
	node* temp = new node;
	temp->data = x;
	temp->next = NULL;
	q->next = temp;
	return p;
}
node* deletehead(node* p)
{
	node* q = p;
	q = q->next;
	delete(p);
	return q;
}
node* deletetail(node* p)
{
	node* q = p;
	while (q->next->next != NULL)
	{
		q = q->next;
	}
	delete(q->next);
	q->next = NULL;
	return p;
}
node* deleteat(node* p, int pos)
{
	node* q = p;
	for (int i = 0; i < pos - 1; i++)
	{
		q = q->next;
	}
	node* temp = q->next;
	q->next = q->next->next;
	delete(temp);
	return p;
}
void addheadlist(list& l, node* p)
{
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		p->next = l.head;
		l.head = p;
	}
}
void deleteheadlist(list& l)
{
	if (l.head == NULL)
	{
		return;
	}
	else
	{
		node* p = l.head;
		l.head = l.head->next;
		delete p;
	}
}
node* addat(node* p, int pos, int x)
{
	node* q = p;
	for (int i = 0; i < pos - 1; i++)
	{
		q = q->next;
	}
	node* temp = new node;
	temp->data = x;
	temp->next = q->next;
	q->next = temp;
	return p;
}