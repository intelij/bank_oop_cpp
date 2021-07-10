#include<iostream>
#include "List.h"
#include"Debit.h"
#include"Cashpoint.h"
#include"DirectDebit.h"
#include"Transfer.h"
#include"Creditpoint.h"
#include"Interest.h"


using namespace std;

List::List()
{
	cout << "Constructor called: empty list" << endl;
	// 'head' points to 0 initially and when the list is empty.  
	// Otherwise 'head' points to most recently added object
	head = 0;
}

int List::add(Transaction *x)
{
	// pointer 'temp' used to instantiate objects to add to list 
	Link* temp;
	// memory allocated and the object is given a value
	temp = new Link(x);
	if (temp == 0)
	{
		return 0;  // shows error in memory allocation
	}
	// the pointer in the object is set to whatever 
	// 'head' is currently pointing at
	temp->Next = head;
	// 'head' is re-directed to point to the last created object
	head = temp;
	return 1;
}

void List::display()
{
	cout << "\n\t\t\tDisplaying list:" << endl;
	// pointer 'temp' used to iterate through the list 
	Link* temp;
	// 'head' points to last object.  The rest can only be located 
	// by pointers inside other objects. Now iterate back through 
	// the linked list until reach the last pointer (which is 0)
	for (temp = head; temp != 0; temp = temp->Next)
	{
		temp->X->display();
	}

}

void List::top10transections()
{
	cout << "Top 10 transections (if exist) are\n";

	// pointer 'temp' used to iterate through the list 
	Link* temp;
	// 'head' points to last object.  The rest can only be located 
	// by pointers inside other objects. Now iterate back through 
	// the linked list until reach the last pointer (which is 0)
	int count = 0;
	for (temp = head; temp != 0; temp = temp->Next)
	{
		temp->X->display();
		count++;
		if (count == 10)
			break;
	}
}

void List::saveTransactions(string filename)
{
	Link* temp;
	// 'head' points to last object.  The rest can only be located 
	// by pointers inside other objects. Now iterate back through 
	// the linked list until reach the last pointer (which is 0)
	for (temp = head; temp != 0; temp = temp->Next)
	{
		temp->X->saveFile(filename);
	}

	cout << "All transaction are saved in " << filename << endl;
}

void List::loadTransactions(string filename)
{
	ifstream in(filename.c_str());
	if (in.is_open())
	{
		Transaction* T;
		string start, month, Time;
		date d; int y, day;
		time t;
		float amount;
		while(in>>start)
		{
			in >> day;
			in >> month;
			in >> y;
			in >> Time;
			d.setDate(day, month, y);
			t.setTime(stoi(Time.substr(0, 2)), stoi(Time.substr(3, 2)), stoi(Time.substr(6, 2)));
			in >> amount;
		
			if (start == "DB")
			{
				long long a;
				string b, c;
				in >> a >> b >> c;
				T = new Debit(a, b, c, amount, d, t);
				add(T);
			}
			else if (start == "CSP")
			{
				long long card;
				int id;
				in >> card >> id;
				T = new Cashpoint(id, card, amount, d, t);
				add(T);
			}
			else if (start == "DD")
			{
				int r;
				in >> r;
				int* ref = &r;
				T = new DirectDebit(ref, amount, d, t);
				add(T);
			}
			else if (start == "TR")
			{
				long long ac;
				string b;
				in >> ac >> b;
				T = new Transfer(ac, b, amount, d, t);
				add(T);
			}
			else if (start == "CDP")
			{
				string pay;
				in >> pay;
				T = new Creditpoint(pay, amount, d, t);
				add(T);
			}
			else if (start == "INT")
			{
				string type;
				in >> type;
				T = new Interest(type, amount, d, t);
				add(T);
			}
		}

		cout << "Transactions Loaded successfully!\n";
	}
	else
		cout << "File doesn't exist\n";
}

void List::remove()
{
	// CODE FOR REMOVE FUNCTION: PASS value AS A PARAMETER
	// This function attempts to remove the first object containing ‘value’
	// It returns 1 if successful and 0 otherwise
	Link* temp;

	if (head == 0)		// check for empty list 
	{
		cout << "List is empty!\n";
		return ;
	}

	else             // top of object is deleted
	{
		temp = head;		// point to one to remove (i.e. first)
		head = head->Next;	// point head second object 
		cout << "Deleting object " << endl;
		delete temp;		// free the memory
		return ;
	}

}

void List::linearSearch(date searchTransactions)
{

	cout << "\t\t\n\nAll transactions on date " << searchTransactions.getDate() << " are \n";
	Link* temp;
	
	for (temp = head; temp != 0; temp = temp->Next)
	{
		if (temp->X->checkDate() == searchTransactions.getDate())
		{
			temp->X->display();
		}
	}
	
	
}

void List::clear()
{
	// CODE FOR CLEAR FUNCTION
	Link* temp;

	cout << "Clear called" << endl;
	while (head != 0)
	{
		temp = head;
		head = head->Next;
		cout << "Deleting object containing " << temp->X << endl;
		delete temp;
	}
}

List::~List()
{
	// CODE FOR DESTRUCTOR
	cout << "Destructor called" << endl;
	List::clear();
}


