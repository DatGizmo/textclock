#include "clock.h"
#include "strings.h"

using namespace std;

Clock::Clock(string _lng)
{
	int i = 0;
	clock = time(0);
	ti = localtime(&clock);
	mod_calc = 5;
	add_hr_index = 3;
	
	for(i=0; i<MAX_LNG; ++i)
	{
		if(_lng == languages[i])
		{
			lngindex = i;
			break;
		}
	}
}

string Clock::to_string()
{
	int min = 0, hr = 0, index = 0, num_bytes;
	char retval[100] = "";
	string timestring = "";
	string hrname = "";
	
	min = ti->tm_min;
	hr = ti->tm_hour;
	if(min > mod_calc)
	{
		index = ((min - mod_calc) / 5 + 1);
		if(index > 11)
		{
			index = 0;
			hr+=1;
		}
	}
	if(index > add_hr_index)
		hr+=1;
	
	timestring = lng_msgs[lngindex][index];
	index = 0;

	if(hr < 1)
		index = 11;
	else if((hr == 1 || hr == 13) && (min < mod_calc || min > 60 - mod_calc))
		index = 12;
	else
		index = (hr - 1) % 12;	
	
	hrname = lng_hour[lngindex][index];
	num_bytes = snprintf(retval, 100, timestring.c_str(), hrname.c_str());

	return retval;
}
