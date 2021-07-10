#pragma once
#include"Transaction.h"

class Interest :public Transaction
{
private:
	string typeOfInterest;
public:
	Interest();
	Interest(string type, float m, date d, time t);
	void input();
	void display();
	void saveFile(string filename);
	void loadFile(string filename);
	string checkDate();
};
