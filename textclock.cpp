#include "clock.h"
#include "fuzzyclock.h"
#include "qlock.h"
#include "strings.h"
#include <string>
#include <iostream>
#include <unistd.h>

using namespace std;

bool fuzzy = false;
bool qlock = false;
bool qlock_dots = false;
string lng = "de";

void printHelp()
{
	int i = 0;

	cout << "Simple textclock printout." << endl;
	cout << "Usage: textclock <option>" << endl;
	cout << "	options: -f		fuzzy clock mode" << endl;
	cout << "		 -q		qlock clock mode" << endl;
	cout << "		 -d		enable minutes dots for qlock clock mode" << endl;
	cout << "		 -l		set output language." << endl;
	cout << "		 -h		print this help" << endl;
	cout << "	languages:		";
	for(i=0; i<MAX_LNG; ++i)
	{
		cout <<	languages[i];
		if(i+1 < MAX_LNG)
			cout << ", ";
	}
	cout << endl;

	exit(0);
}

void parseOpts(int argc, char* argv[])
{
	bool foundlng = false;
	int opt = 0, i = 0;

	while((opt = getopt(argc, argv, "dfhl:q")) != -1)
	{
		switch(opt)
		{
			case 'd':
				qlock_dots = true;
				break;
			case 'f':
				fuzzy = true;
				break;
			case 'l':
				lng = optarg;
				for(i=0; i<MAX_LNG; ++i)
				{
					if(lng == languages[i])
					{
						foundlng = true;
						break;
					}
				}
				if(!foundlng)
				{
					cout << "Language \"" << lng << "\" is not yet supported" << endl;
					printHelp();
				}
				break;
			case 'q':
				qlock = true;
				break;
			case 'h':
			default:
				printHelp();
				break;
		}
	}
	if(qlock && fuzzy)
	{
		cout << "Qlock and fuzzy can't be set at the same time!" << endl << endl;
		printHelp();
	}
}

int main(int argc, char* argv[])
{
	parseOpts(argc, argv);
	
	Clock *now = new Clock(lng);
	if(fuzzy)
		now = new Fuzzyclock(lng);
	else if(qlock)
		now = new Qlock(lng, qlock_dots);

	cout << now->to_string() << endl;
	 
	delete now;
}
