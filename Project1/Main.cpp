#include"Header.h"

int main()
{
	list l;
	init(l);
	read_file(l);
	output(l);
	string chu;
	cout << "\n===== Menu ====== " << endl;
	cout << "Delete pos. " << endl;
	cout << "Insert pos val. " << endl;
	cout << "Quit. ";
	int n;
	do
	{
		cout << "\nCommand > : ";
		cin >> chu;
		if (chu == "Delete")
		{
			n = 1;
		}
		else if (chu == "Insert")
		{
			n = 2;
		}
		else if (chu == "Quit")
		{
			n = 3;
		}
		switch (n)
		{
		case 1:
		{
			int a = length(l);
			int k;
			cin >> k;
			if (k == 0)
			{
				cout << "Wrong input, re-enter ! ";
			}
			else if (k == 1)
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
				addhead(l, x);
			}
			else if (k == a + 1)
			{
				add_tail(l, x);
			}
			else
			{
				addat(l, k, x);
			}
			output(l);
			break;
		}
		}
	} while (n != 3);
}
