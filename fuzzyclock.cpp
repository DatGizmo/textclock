#include "fuzzyclock.h"

using namespace std;

Fuzzyclock::Fuzzyclock(string _lng)
	:Clock(_lng)
{
	mod_calc = 3;
	add_hr_index = 3;
}

