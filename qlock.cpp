#include "qlock.h"

using namespace std;

string Qlock::dot_string()
{
	int calcdots = 0, min = 0;
	string retval = "";
	min = ti->tm_min;
	calcdots = min % 5;

	switch(calcdots)
	{
		case 1:
			retval = " .";
			break;
		case 2:
			retval = " :";
			break;
		case 3:
			retval = " :.";
			break;
		case 4:
			retval = " ::";
			break;
		default:
			break;
	}
	return retval;
}

Qlock::Qlock(string _lng)
	:Clock(_lng)
{
	mod_calc = 5;
	add_hr_index = 3;
}

string Qlock::to_string()
{
	string retval =	Clock::to_string();
	retval.append(dot_string());

	return retval;

}
