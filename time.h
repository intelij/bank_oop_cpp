#pragma once

#include"iostream"
#include<sstream>
using namespace std;

class time
{
private:
	int second;
	int minute;
	int hour;
public:
	void setTime();
	string getTime();
	void setTime(int h, int m, int s);
};

