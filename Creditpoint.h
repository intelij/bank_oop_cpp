#pragma once
#include"Transaction.h"

class Creditpoint :public Transaction
{
private:
	string typeOfPayment;
public:
	Creditpoint();
	Creditpoint(string pay, float m,date d,time t);
	void input();
	void display();
	void saveFile(string filename);
	void loadFile(string filename);
	string checkDate();
};

