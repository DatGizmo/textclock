#include "strings.h"

const char* de_hour[NUM_HOUR] = 
{ 
	"eins"
	, "zwei" 
	, "drei"
	, "vier"
	, "fünf"
	, "sechs"
	, "sieben"
	, "acht"
	, "neun"
	, "zehn"
	, "elf"
	, "zwölf"
	, "ein"
};

const char* no_hour[NUM_HOUR] = 
{ 
	"ett"
	, "to" 
	, "tre"
	, "fire"
	, "fem"
	, "seks"
	, "sju"
	, "åtte"
	, "ni"
	, "ti"
	, "elleve"
	, "tolv"
	, "ett"
};

const char* de_message[NUM_MSGS] =
{
	"%s Uhr"
	, "fünf nach %s"
	, "zehn nach %s"
	, "viertel nach %s"
	, "zehn vor halb %s"
	, "fünf vor halb %s"
	, "halb %s"
	, "fünf nach halb %s"
	, "zehn nach halb %s"
	, "dreiviertel %s"
	, "zehn vor %s"
	, "fünf vor %s"
};

const char* no_message[NUM_MSGS] =
{
	"Klokka er %s"
    , "fem over %s"
    , "ti over %s"
    , "kvart over %s"
    , "ti på halv %s"
    , "fem på halv %s"
    , "halv %s"
    , "fem over halv %s"
    , "ti over halv %s"
    , "kvart på %s"
    , "ti på %s"
    , "fem på %s"
};

const char** lng_hour[MAX_LNG] = { de_hour, no_hour };
const char** lng_msgs[MAX_LNG] = { de_message, no_message };
const char* languages[MAX_LNG]= { "de", "no" };
