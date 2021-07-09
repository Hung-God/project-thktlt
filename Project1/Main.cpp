#include"Header.h"

int main()
{
	int log[1000];
	int top = -1;
	LIST l;
	init(l);
	readFile(l);
	output(l);
	string chu;
	cout << "\n===== Menu ====== " << endl;
	cout << "Delete pos. " << endl;
	cout << "Insert pos val. " << endl;
	cout << "Undo" << endl;
	cout << "Redo" << endl;
	cout << "Save" << endl;
	cout << "Quit. " << endl;
	int n;
	do
	{
		cout << "\nCommand > : ";
		cin >> chu;
		if (chu == "Delete" || chu == "delete")
		{
			n = 1;
		}
		else if (chu == "Insert" || chu == "insert")
		{
			n = 2;
		}
		else if (chu == "Undo" || chu == "undo")
			n = 3;
		else if (chu == "Redo" || chu == "redo")
			n = 4;
		else if (chu == "Save" || chu == "save")
			n = 5;
		else if (chu == "Quit" || chu == "quit")
		{
			n = 0;
		}
		switch (n)
		{
		case 1:
		{
			int a = length(l);
			int k;
			cin >> k;
			if (k == 0 || k > a)
			{
				cout << "Wrong input, re-enter ! ";
			}
			else if (k == 1)
			{
				push(log, 1, top);
				push(log, k, top);
				push(log, l.pHead->data, top);
				deleteHead(l);
			}
			else if (k == a)
			{
				push(log, 1, top);
				push(log, k, top);
				push(log, l.pTail->data, top);
				deleteTail(l);
			}
			else
			{
				push(log, 1, top);
				push(log, k, top);
				push(log, printOutAt(l, k), top);
				deleteAt(l, k);
			}
			output(l);
			cout << endl;
			break;
		}
		case 2:
		{
			int a = length(l);
			int k;
			int x;
			cin >> k >> x;
			if (k == 0)
			{
				cout << "Wrong input, re-enter ! ";
			}
			if (k == 1)
			{
				push(log, 2, top);
				push(log, k, top);
				push(log, x, top);
				addHead(l, x);
			}
			else if (k == a + 1)
			{
				push(log, 2, top);
				push(log, k, top);
				push(log, x, top);
				addTail(l, x);
			}
			else
			{
				push(log, 2, top);
				push(log, k, top);
				push(log, x, top);
				addAt(l, k, x);
			}
			output(l);
			cout << endl;
			break;
		}
		case 3:
		{
			if (log[top-2] == 1)
			{
				int a = length(l);
				if (log[top-1] == 1)
				{
					addHead(l, log[top]);
				}
				else if (log[top-1] == a + 1)
				{
					addTail(l, log[top]);
				}
				else
				{
					addAt(l, log[top-1], log[top]);
				}
				top -= 3;
				output(l);
				cout << endl;
			}
			else if (log[top - 2] == 2)
			{
				int a = length(l);
				if (log[top-1] == 1)
				{
					deleteHead(l);
				}
				else if (log[top-1] == a)
				{
					deleteTail(l);
				}
				else
				{
					deleteAt(l, log[top-1]);
				}
				top -= 3;
				output(l);
				cout << endl;
			}
			break;
		}
		case 4:
		{
			if (log[top + 1] == 1)
			{
				int a = length(l);
				if (log[top + 2] == 1)
				{
					deleteHead(l);
				}
				else if (log[top + 2] == a)
				{
					deleteTail(l);
				}
				else
				{
					deleteAt(l, log[top + 2]);
				}
				top += 3;
				output(l);
				cout << endl;
			}
			if (log[top + 1] == 2)
			{
				int a = length(l);
				if (log[top + 2] == 1)
				{
					addHead(l, log[top]);
				}
				else if (log[top + 2] == a + 1)
				{
					addTail(l, log[top]);
				}
				else
				{
					addAt(l, log[top + 2], log[top+3]);
				}
				top += 3;
				output(l);
				cout << endl;
			}
			break;
		}
		case 5:
		{
			int a = length(l);
			if (a == 0)
				break;
			else
			{
				fstream ofile;
				ofile.open("output.txt", ios::out);
				if (ofile.fail())
				{
					cout << " Opening file fail !" << endl;
					break;
				}
				NODE* temp = l.pHead;
				while (temp != NULL)
				{
					ofile << temp->data << " ";
					temp = temp->pNext;
				}
				cout << "Numbers have been stored." << endl;
				ofile.close();
			}
			break;
		}
		}
	} while (n != 0);
}
