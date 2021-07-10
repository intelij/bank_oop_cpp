#pragma once
#include"Transaction.h"

class Debit :public Transaction
{
private:
	long long cardNumber;
	string retailerName;
	string retailerLoc;
	string Method;
public:
	Debit();
	Debit(long long c, string name, string loc, float m, date d, time t);
	void input();
	void display();
	void saveFile(string filename);
	void loadFile(string filename);
	string checkDate();
};

