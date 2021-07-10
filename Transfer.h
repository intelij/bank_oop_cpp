#pragma once
#include"Transaction.h"

class Transfer :public Transaction
{
private:
	long long accountNumber;
	string bankSortCode;
public:
	Transfer();
	Transfer(long long ac,string bank,float m,date d,time t);
	void input();
	void display();
	void saveFile(string filename);
	void loadFile(string filename);
	string checkDate();
};