#pragma once
#include"date.h"
#include"time.h"
#include<fstream>

class Transaction
{
protected:
	date Date;
	time Time;
	float amount;
public:
	virtual void input() = 0;
	virtual void display() = 0;
	virtual void saveFile(string filename) = 0;
	virtual void loadFile(string filename) = 0;
	virtual string checkDate() = 0;
};
