#ifndef _STRINGS_H_
#define _STRINGS_H_

#define MAX_LNG 2
#define NUM_HOUR 13
#define NUM_MSGS 12

enum Languages
{
	LANG_DE,
	LANG_NO
};

enum HourStrings
{
	HR_STR_ONES,
	HR_STR_TWO,
	HR_STR_THREE,
	HR_STR_FORE,
	HR_STR_FIVE,
	HR_STR_SIX,
	HR_STR_SEVEN,
	HR_STR_EIGHT,
	HR_STR_NINE,
	HR_STR_TEN,
	HR_STR_ELEVEN,
	HR_STR_TWELVE,
	HR_STR_ONE
};

enum MessagStrings
{
	MSG_STR_CLOCK,	
	MSG_STR_FIVE,
	MSG_STR_TEN,
	MSG_STR_FIFTEEN,
	MSG_STR_TWENTY,
	MSG_STR_TWENTYFIVE,
	MSG_STR_THIRTY,
	MSG_STR_THIRTDFIVE,
	MSG_STR_FORTY,
	MSG_STR_FORTYFIVE,
	MSG_STR_FIFTY,
	MSG_STR_FIFTYFIVE
};

extern const char* de_hour[NUM_HOUR]; 
extern const char* no_hour[NUM_HOUR];
extern const char* de_message[NUM_MSGS];
extern const char* no_message[NUM_MSGS];
extern const char** lng_hour[MAX_LNG];
extern const char** lng_msgs[MAX_LNG];
extern const char* languages[MAX_LNG];

#endif

