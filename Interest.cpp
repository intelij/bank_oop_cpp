#include"Interest.h"

Interest::Interest()
{

}
Interest::Interest(string type, float m, date d, time t)
{

	typeOfInterest = type;
	amount = m;
	Date = d;
	Time = t;
}

void Interest::input()
{

	Date.setDate();
	Time.setTime();
	cout << "Enter transection amount: ";
	cin >> amount;
	do
	{
		cout << "Enter type of interest (daily/monthly/annualy): ";
		cin >> typeOfInterest;
	} while (typeOfInterest != "daily" && typeOfInterest != "monthly" && typeOfInterest != "annually");
}

void Interest::display()
{
	cout << "INT " << Date.getDate() << " " << Time.getTime() << " " << amount << " " << typeOfInterest << endl;
}

string Interest::checkDate()
{
	return Date.getDate();
}

void Interest::saveFile(string filename)
{
	ofstream out(filename.c_str(), ios::app);
	out << "INT " << Date.getDate() << " " << Time.getTime() << " " << amount << " " << typeOfInterest << endl;
}

void Interest::loadFile(string filename)
{

}