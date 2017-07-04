#ifndef _CLOCK_H_
#define _CLOCK_H_

#include <iostream>
#include <ctime>
#include <string>

class Clock
{
	protected:
		time_t clock;
		tm *ti;
		int mod_calc;
		int add_hr_index;
		int lngindex;

	public:
		Clock(std::string _lng);
		virtual std::string to_string();
};

#endif
