#pragma once
#include"Transaction.h"

class DirectDebit :public Transaction
{
private:

	int* reference;  //to hold reference of a number
public:
	DirectDebit();
	DirectDebit(int* ref, float m,date d,time t);
	void input();
	void display();
	void saveFile(string filename);
	void loadFile(string filename);
	string checkDate();
};
