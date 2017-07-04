#ifndef _QLOCK_H_
#define _QLOCK_H_

#include "clock.h"

class Qlock : public Clock
{
	private:
		bool dots;
		std::string dot_string();

	public:
		Qlock(std::string _lng, bool _dots);
		std::string to_string();
};

#endif
