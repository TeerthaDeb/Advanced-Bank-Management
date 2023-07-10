#include<bits/stdc++.h>
#include "Date.h"

using namespace std;


class Time : public Date
{
private:
	//variables:
	short hour , minute , second;
	//functions:

public:
	//variables:

	//functions:

	//default constructor:
	Time()
	{
		hour = minute = second = 0;
	}

	//constructor(s):
	Time(short hour , short  minute , short second)
	{
		set_everything_for_time(hour , minute , second);
	}

	void set_everything_for_time(short hour , short  minute , short second)
	{
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}

	//copy constructors:

	Time(const Time &other)
	{
		this->hour = other.hour;
		this->minute = other.minute;
		this->second = other.second;
		//return this;
	}

	//destructor:
	~Time()
	{

	}
	//setters:

	//getters:
	string to_String()
	{
		return to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
	}

	// Operators
	bool operator == (const Time& other){
		if(typeid(Time) != typeid(other)){
			return false;
		}
		return hour == other.hour and minute == other.minute and second == other.second;
	}
	//friend functions:

};
