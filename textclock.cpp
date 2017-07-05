#include "clock.h"
#include "fuzzyclock.h"
#include "qlock.h"
#include "strings.h"
#include <string>
#include <iostream>
#include <unistd.h>

using namespace std;

bool qlock = false;
string lng = "de";

void printHelp()
{
	int i = 0;

	cout << "Simple textclock printout, fuzzy mode is default." << endl;
	cout << "Usage: textclock <option>" << endl;
	cout << "	options: -q		qlock clock mode" << endl;
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

	while((opt = getopt(argc, argv, "hl:q")) != -1)
	{
		switch(opt)
		{
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
}

int main(int argc, char* argv[])
{
	Clock *now = NULL;
	parseOpts(argc, argv);
	
	if(qlock)
		now = new Qlock(lng);
	else
		now = new Fuzzyclock(lng);

	if(NULL != now)
	{
		cout << now->to_string() << endl;
		delete now;
	}
}
