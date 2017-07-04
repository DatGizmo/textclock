#ifndef _QLOCK_H_
#define _QLOCK_H_

#include "clock.h"

class Qlock : public Clock
{
	private:
		std::string dot_string();

	public:
		Qlock(std::string _lng);
		std::string to_string();
};

#endif
