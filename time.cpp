#include"time.h"

void time::setTime()
{
	cout << "Enter Time(hh mm ss):";
	cin >> hour >> minute >> second;
}

void time::setTime(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}

string time::getTime()
{

	stringstream s;
	s << hour << ":" << minute << ":" << second;
	string result;
	s >> result;
	return result;
}
