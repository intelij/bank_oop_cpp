#include"Debit.h"

Debit::Debit()
{

}
Debit::Debit(long long c, string name, string loc, float m, date d, time t)
{
	cardNumber = c;
	retailerName = name;
	retailerLoc = loc;
	amount = m;
	Date = d;
	Time = t;
}


void Debit::input()
{
	Date.setDate();
	Time.setTime();
	cout << "Enter transection amount: ";
	cin >> amount;
	cout << "Enter used card number: ";
	cin >> cardNumber;
	cout << "Enter retailer name: ";
	cin >> retailerName;
	cout << "Enter retailer location: ";
	cin >> retailerLoc;
	do
	{
		cout << "Enter Method(online/phone/mailorder): ";
		cin >> Method;

	} while (Method != "online" && Method != "phone" && Method != "mailorder");
}

void Debit::display()
{
	cout << "DB " << Date.getDate() <<" "<< Time.getTime() << " " << amount << " " << cardNumber << " " << retailerName << " " << retailerLoc << " " << Method << endl;
}

string Debit::checkDate()
{
	return Date.getDate();
}


void Debit::saveFile(string filename)
{
	ofstream out(filename.c_str(), ios::app);
	out << "DB " << Date.getDate() << " " << Time.getTime() << " " << amount << " " << cardNumber << " " << retailerName << " " << retailerLoc << " " << Method << endl;
}

void Debit::loadFile(string filename)
{

}
