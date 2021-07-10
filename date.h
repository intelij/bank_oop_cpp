#pragma once

#include"iostream"
#include<sstream>
using namespace std;

class date
{
private:
	int day;
	int month;
	int year;
public:
	void setDate();
	string getDate();
	void setDate(int d, string m, int y);
	
};