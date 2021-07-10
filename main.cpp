#include"Transaction.h"
#include"Debit.h"
#include"Cashpoint.h"
#include"DirectDebit.h"
#include"Transfer.h"
#include"Creditpoint.h"
#include"Interest.h"
#include"List.h"
using namespace std;

int main()
{
	string option;
	List list;
	while (true)
	{
		system("CLS");
		cout << "\t\t\tMENU\n";
		cout << "Q - Quit\nI - Insert a transaction\nD - Delete a transaction\nC - Display a list of all transactions\n";
		cout << "U - Contents of the upper object\nS - Save transactions to file\nL - Load transactions from file\nN - Linear search\n";
		cout << "T - Sort transactions by date in decreasing order\n\nOption: ";
		cin >> option;

		if (option == "Q" || option == "q")
		{
			exit(0);
		}
		else if (option == "I" || option == "i")
		{
			system("CLS");
			string op;
			Transaction* transaction;
			cout << "\t\tSelect a transection Type\n\n";
			cout << "DB - Debit\nCSP - Cash point\nDD - Direct debit\nTR - Transfer\nCDP - Credit point\nINT - Interest\n";
			cout << "\n\nOption: ";
			cin >> op;

			if (op == "DB" || op == "db")
			{
				transaction = new Debit();
				transaction->input();
				list.add(transaction);
			}
			else if (op == "CSP" || op == "csp")
			{

				transaction = new Cashpoint();
				transaction->input();
				list.add(transaction);
			}
			else if (op == "DD" || op == "dd")
			{

				transaction = new DirectDebit();
				transaction->input();
				list.add(transaction);
			}
			else if (op == "TR" || op == "tr")
			{

				transaction = new Transfer();
				transaction->input();
				list.add(transaction);
			}
			else if (op == "CDP" || op == "cdp")
			{

				transaction = new Creditpoint();
				transaction->input();
				list.add(transaction);
			}
			else if (op == "INT" || op == "int")
			{

				transaction = new Interest();
				transaction->input();
				list.add(transaction);
			}
			else
			{
				cout << "\nInvalid option!\n";
				system("pause");
			}


		}
		else if (option == "D" || option == "d")
		{
			list.remove();
			system("Pause");
		}
		else if (option == "C" || option == "c")
		{
			list.display();
			system("Pause");
		}
		else if (option == "U" || option == "u")
		{
			list.top10transections();
			system("Pause");
		}
		else if (option == "S" || option == "s")
		{
			string filename;
			cout << "Enter filename to save transactions: ";
			cin >> filename;
			list.saveTransactions(filename);
			system("Pause");
		}

		else if (option == "L" || option == "l")
		{
			string filename;
			cout << "Enter filename to load transactions: ";
			cin >> filename;
			list.loadTransactions(filename);
			system("Pause");
		}

		else if (option == "N" || option == "n")
		{
			cout << "\t\tLinear search by Date\n";
			date d;
			d.setDate();
			list.linearSearch(d);
			system("Pause");
		}
		else if (option == "T" || option == "t")
		{
			
		}
	}

	return 0;
}