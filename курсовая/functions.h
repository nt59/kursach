#include <string>
#include <iostream>

using namespace std;

bool isNumber(string s)
{
	bool isNumber = true;
	if (s == "")
		return false;
	for (int i = 0; i < s.length(); i++)
	if (!(s[i] >= '0' && s[i] <= '9'))
	{
		isNumber = false;
		break;
	}
	return isNumber;
}

void makeData(int* day, int* month, int* year)
{
	string buf;
	while (true){
		cout << "¬ведите число: ";
		getline(cin, buf);
		if (isNumber(buf) && (atoi(buf.c_str()) <= 31))
		{
			*day = atoi(buf.c_str());
			break;
		}
		else
		{
			cout << "ќшибка! ¬ведите корректное число\n";
		}
	}
	while (true){
		cout << "¬ведите мес€ц: ";
		getline(cin, buf);
		if (isNumber(buf) && (atoi(buf.c_str()) <= 12) && (atoi(buf.c_str()) >= 1))
		{
			*month = atoi(buf.c_str());
			break;
		}
		else
		{
			cout << "ќшибка! ¬ведите корректное число\n";
		}
	}
	while (true){
		cout << "¬ведите год: ";
		getline(cin, buf);
		if (isNumber(buf) && (atoi(buf.c_str()) >= 2014))
		{
			*year = atoi(buf.c_str());
			break;
		}
		else
		{
			cout << "ќшибка! ¬ведите корректное число\n";
		}
	}

}

int getCountDays(int day, int month, int year){
	int daysOfYear = (year - 2014) * 365;
	int daysOfMonth = 0;
	switch (month - 1)
	{
	case 1: 
		daysOfMonth = 31;
	case 2:
		daysOfMonth = 59;
	case 3:
		daysOfMonth = 90;
	case 4:
		daysOfMonth = 120;
	case 5:
		daysOfMonth = 151;
	case 6:
		daysOfMonth = 181;
	case 7:
		daysOfMonth = 212;
	case 8:
		daysOfMonth = 243;
	case 9:
		daysOfMonth = 273;
	case 10:
		daysOfMonth = 304;
	case 11:
		daysOfMonth = 334;
	}
	return day + daysOfMonth + daysOfYear;
}

int getData()
{
	int* day;
	int* month,
	int* year;
	makeData(day, month, year);
	return getCountDays(*day, *month, *year);
}