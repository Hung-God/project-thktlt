#include "Header.h"

void init(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

void addTail(LIST& l, int x)
{
	NODE* p = new NODE;
	if (l.pHead == NULL)
	{
		p->data = x;
		l.pHead = p;
		l.pTail = p;
	}
	else
	{
		p->data = x;
		l.pTail->pNext = p;
		l.pTail = p;
		l.pTail->pNext = NULL;
	}
}

void readFile(LIST& l)
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
		addTail(l, n);
	}
	file.close();
}

void output(LIST l)
{
	if (l.pHead != NULL)
	{
		NODE* p = l.pHead;
		while (p != NULL)
		{
			cout << p->data << "  ";
			p = p->pNext;
		}
	}
}

int length(LIST l)
{
	int count = 0;
	NODE* p = l.pHead;
	while (p != NULL)
	{
		count++;
		p = p->pNext;
	}
	return count;
}

void deleteHead(LIST& l)
{
	if (l.pHead == NULL)
		cout << "Nothing to delete !\n";
	else
	{
		NODE* q = l.pHead;
		l.pHead = l.pHead->pNext;
		delete(q);
	}
}

void deleteTail(LIST& l)
{
	if (l.pHead == NULL)
		cout << "Nothing to delete !\n";
	else
	{
		NODE* q = l.pHead;
		while (q->pNext != l.pTail)
		{
			q = q->pNext;
		}
		delete(q->pNext);
		q->pNext = NULL;
		l.pTail = q;
	}
}

void deleteAt(LIST& l, int pos)
{
	NODE* q = l.pHead;
	for (int i = 2; i < pos; i++)
	{
		q = q->pNext;
	}
	NODE* temp = q->pNext;
	q->pNext = q->pNext->pNext;
	delete(temp);
}

void addHead(LIST& l, int x)
{
	NODE* q = new NODE;
	q->data = x;
	q->pNext = l.pHead;
	l.pHead = q;

}

void addAt(LIST& l, int pos, int x)
{
	NODE* q = l.pHead;
	for (int i = 2; i < pos; i++)
	{
		q = q->pNext;
	}
	NODE* temp = new NODE;
	temp->data = x;
	temp->pNext = q->pNext;
	q->pNext = temp;
}

bool isEmpty(int top) 
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

int printOutAt(LIST l, int pos)
{
	NODE* q = l.pHead;
	for (int i = 2; i <= pos; i++)
	{
		q = q->pNext;
	}
	return q->data;
}

void push(int stack[], int value, int& top) 
{
	top++;
	stack[top] = value;
}

void pop(int stack[], int top) 
{
	if (isEmpty(top) == false) 
	{
		top--;
	}
}

void save(LIST l)
{
	fstream f;
	f.open("output.txt", ios_base::app);
	f << '\n';
	if (f.fail())
	{
		cout << "Opening file fail !" << endl;
		return;
	}
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		f << k->data << " ";
	}
	cout << "Numbers have been stored." << endl;
	f.close();
}

void writeFile(LIST l)
{
	fstream f;
	f.open("output.txt", ios_base::out);
	if (f.fail())
	{
		cout << "Opening file fail !" << endl;
		return;
	}
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		f << k->data << " ";
	}
	f.close();
}

void releaseList(LIST& l)
{

	NODE* k = NULL;
	while (l.pHead != NULL)
	{
		k = l.pHead;
		l.pHead = l.pHead->pNext;
		delete k;
	}
}