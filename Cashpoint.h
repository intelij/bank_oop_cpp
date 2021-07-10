#pragma once
#include"Transaction.h"

class Cashpoint :public Transaction
{
private:
	int locIdOfCashPoint;
	long long cardUsed;
public:
	Cashpoint();
	Cashpoint(int id, long long card, float m,date d,time t);
	void input();
	void display();
	void saveFile(string filename);
	void loadFile(string filename);
	void setCashPoint(int id,long long card,float am);
	string checkDate();

};


