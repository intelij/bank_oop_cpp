#include"DirectDebit.h"

DirectDebit::DirectDebit()
{

}
DirectDebit::DirectDebit(int* ref, float m,date d,time t)
{
	reference = ref;
	amount = m;
	Date = d;
	Time = t;
   
}

void DirectDebit::input()
{

	Date.setDate();
	Time.setTime();
	cout << "Enter transection amount: ";
	cin >> amount;
	int num;
	cout << "Enter refference number: ";
	cin >> num;
	reference = &num;    //storing refernce number
}


void DirectDebit::display()
{
	cout << "DD " << Date.getDate() << " " << Time.getTime() << " " << amount << " " << reference << endl;
}

string DirectDebit::checkDate()
{
	return Date.getDate();
}

void DirectDebit::saveFile(string filename)
{
	ofstream out(filename.c_str(), ios::app);
	out << "DD " << Date.getDate() << " " << Time.getTime() << " " << amount << " " << reference << endl;
}

void DirectDebit::loadFile(string filename)
{

}