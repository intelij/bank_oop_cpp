#include"Cashpoint.h"

Cashpoint::Cashpoint()
{

}

Cashpoint::Cashpoint(int id, long long card, float m,date d,time t)
{
	locIdOfCashPoint = id;
	cardUsed = card;
	amount = m;
	Date = d;
	Time = t;
}


void Cashpoint::input()
{

	Date.setDate();
	Time.setTime();
	cout << "Enter transection amount: ";
	cin >> amount;
	cout << "Enter machine location Id: ";
	cin >> locIdOfCashPoint;
	cout << "Enter card used: ";
	cin >> cardUsed;
}

void Cashpoint::display()
{
	cout << "CSP " << Date.getDate() << " " << Time.getTime() << " " << amount << " " << cardUsed << " " << locIdOfCashPoint << endl;
}

string Cashpoint::checkDate()
{
	return Date.getDate();
}

void Cashpoint::saveFile(string filename)
{
	ofstream out(filename.c_str(), ios::app);
	out << "CSP " << Date.getDate() << " " << Time.getTime() << " " << amount << " " << cardUsed << " " << locIdOfCashPoint << endl;
}

void Cashpoint::loadFile(string filename)
{
	
	ifstream in(filename.c_str());
	if (in.is_open())
	{
		
	}
	else
		cout << "File " << filename << " doesn't exist\n";
}