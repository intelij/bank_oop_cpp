#include"date.h"

void date::setDate()
{
	cout << "Enter Date(yyyy mm dd): ";
	cin >> year >> month >> day;
}

void date::setDate(int d, string m, int y)
{
	day = d;
	
	if (m == "Jan")
		month = 1;
	else if (m == "Feb")
		month = 2;
	else if (m == "Mar")
		month = 3;
	else if (m == "Apr")
		month = 4;
	else if (m == "May")
		month = 5;
	else if (m == "Jun")
		month = 6;
	else if (m == "Jul")
		month = 7;
	else if (m == "Aug")
		month = 8;
	else if (m == "Sep")
		month = 9;
	else if (m == "Oct")
		month = 10;
	else if (m == "Nov")
		month = 11;
	else
		month = 12;







   
	
	year = y;
}


string date::getDate()
{
	string monthName;
	if (month == 1)
		monthName = "Jan";
	else if (month == 2)
		monthName = "Feb";
	else if (month == 3)
		monthName = "Mar";
	else if (month == 4)
		monthName = "Apr";
	else if (month == 5)
		monthName = "May";
	else if (month == 6)
		monthName = "Jun";
	else if (month == 7)
		monthName = "Jul";
	else if (month == 8)
		monthName = "Aug";
	else if (month == 9)
		monthName = "Sep";
	else if (month == 10)
		monthName = "Oct";
	else if (month == 11)
		monthName = "Nov";
	else
		monthName = "Dec";

	string result;
	if (month < 10)
		result += "0";
	result += to_string(day) + " " +  monthName + " " + to_string(year);
	return result;
}