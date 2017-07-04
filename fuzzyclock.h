#ifndef _FUZZYCLOCK_H_
#define _FUZZYCLOCK_H_

#include "clock.h"

class Fuzzyclock : public Clock
{
	public:
		Fuzzyclock(std::string _lng);
};

#endif
