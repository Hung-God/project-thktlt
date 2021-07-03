#include"Header.h"

int main()
{
	int x;
	list l;
	init(l);
	read_file(l);
	output(l);
	int n;
	cout << "\n===== Menu ====== " << endl;
	cout << "1. Delete pos. " << endl;
	cout << "2. Insert pos val. " << endl;
	cout << "3. Exit. ";
	do
	{
		cout << "\nCommand > : ";
		cin >> n;
		switch (n)
		{
		case 1:
		{
			/*node* q = createnode(0);
			addheadlist(l, q);*/
			int a = length(l);
			node* p = l.head;
			int k;
			cout << " Delete ";
			cin >> k;
			if (k == 1)
			{
				deletehead(l);
			}
			else if (k == a)
			{
				deletetail(l);
			}
			else
			{
				deleteat(l, k);
			}
			output(l);
			break;
		}
		case 2:
		{
			node* q = createnode(0);
			addheadlist(l, q);
			int a = length(l);
			node* p = l.head;
			int k;
			int x;
			cout << "Insert ";
			cin >> k >> x;
			if (k == 0)
			{
				addhead(p, x);
			}
			else if (k == n)
			{
				addtail(p, x);
			}
			else
			{
				addat(p, k, x);
			}
			deleteheadlist(l);
			output(l);
			break;
		}
		}
	} while (n != 3);
}
