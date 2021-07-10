#include"Transfer.h"

Transfer::Transfer()
{

}
Transfer::Transfer(long long ac, string bank, float m, date d, time t)
{

	accountNumber = ac;
	bankSortCode = bank;
	amount = m;
	Date = d;
	Time = t;
}

void Transfer::input()
{

	Date.setDate();
	Time.setTime();
	cout << "Enter transection amount: ";
	cin >> amount;
	cout << "Enter your account number: ";
	cin >> accountNumber;
	cout << "Enter your bankn sort code (e.g, 12-34-56): ";
	cin >> bankSortCode;
}

void Transfer::display()
{
	cout << "TR " << Date.getDate() << " " << Time.getTime() << " " << amount << " " << accountNumber<<" "<<bankSortCode << endl;
}

void Transfer::saveFile(string filename)
{
	ofstream out(filename.c_str(), ios::app);
	out << "TR " << Date.getDate() << " " << Time.getTime() << " " << amount << " " << accountNumber << " " << bankSortCode << endl;
}

string Transfer::checkDate()
{
	return Date.getDate();
}


void Transfer::loadFile(string filename)
{

}