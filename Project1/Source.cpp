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

void deletehead(list& l)
{
	if (l.head == NULL)
		cout << "Nothing to delete !\n";
	else
	{
		node* q = l.head;
		l.head = l.head->next;
		delete(q);
	}
}

void deletetail(list& l)
{
	if (l.head == NULL)
		cout << "Nothing to delete !\n";
	else
	{
		node* q = l.head;
		while (q->next != l.tail)
		{
			q = q->next;
		}
		delete(q->next);
		q->next = NULL;
		l.tail = q;
	}
}
void deleteat(list& l, int pos)
{
	node* q = l.head;
	for (int i = 2; i < pos; i++)
	{
		q = q->next;
	}
	node* temp = q->next;
	q->next = q->next->next;
	delete(temp);
}


void addhead(list& l, int x)
{
	node* q = new node;
	q->data = x;
	q->next = l.head;
	l.head = q;

}
void addat(list& l, int pos, int x)
{
	node* q = l.head;
	for (int i = 2; i < pos; i++)
	{
		q = q->next;
	}
	node* temp = new node;
	temp->data = x;
	temp->next = q->next;
	q->next = temp;
}

bool IsEmpty(int top) 
{
	if (top == -1) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int printoutat(list l, int pos)
{
	node* q = l.head;
	for (int i = 2; i <= pos; i++)
	{
		q = q->next;
	}
	return q->data;
}

void Push(int stack[], int value, int& top) 
{
	top++;
	stack[top] = value;
}

void Pop(int stack[], int top) 
{
	if (IsEmpty(top) == false) 
	{
		top--;
	}
}

