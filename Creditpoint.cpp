#include"Creditpoint.h"

Creditpoint::Creditpoint()
{

}

Creditpoint::Creditpoint(string pay, float m,date d,time t)
{
	typeOfPayment = pay;
	amount = m;
	Date = d;
	Time = t;
}

void Creditpoint::input()
{

	Date.setDate();
	Time.setTime();
	cout << "Enter transection amount: ";
	cin >> amount;
	do
	{
		cout << "Enter type of payment (cheque/cash)";
		cin >> typeOfPayment;
	} while (typeOfPayment != "cash" && typeOfPayment != "cheque");
}

void Creditpoint::display()
{
	cout << "CDP " << Date.getDate() << " " << Time.getTime() << " " << amount << " " << typeOfPayment << endl;
}

string Creditpoint::checkDate()
{
	return Date.getDate();
}


void Creditpoint::saveFile(string filename)
{
	ofstream out(filename.c_str(), ios::app);
	out << "CDP " << Date.getDate() << " " << Time.getTime() << " " << amount << " " << typeOfPayment << endl;
}

void Creditpoint::loadFile(string filename)
{

}



CPP.cpp
        Transfer.h
        Transaction.h
        List.h
        Link.h
        Interest.h
        DirectDebit.h
        Debit.h
        data.txt
        CashPoint.h
        CreditPoint.h
        MyTest.txt
        TestData.txt