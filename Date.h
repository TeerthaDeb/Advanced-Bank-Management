#include<bits/stdc++.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
using namespace std;

class Date {
private:
    int day, month , year;
	string months[13] = { "0" , "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

public:
    // Default constructor
		Date()
		{
			day = 1;
			month = 1;
			year = 2023;
		}

    // Parameterized constructor
		Date(int day, int month, int year)
		{
			setDate(day , month , year);
		}

    // Setter methods
		void setDate(int day , int month , int year)
		{
			setDay(day);
			setMonth(month);
			setYear(year);
		}

		void setDay(int day)
		{
			if(day > 31 or day < 0){
				cout<<"Out of bound setting the day = ("<< day << ").\n Returning to the process where this was called from , without setting the Day.";
				return;
			}
			this->day = day;
		}

		void setMonth(int month)
		{
			if(month > 12 or month < 0){
				cout<<"Out of bound setting the Month = ("<< month << ").\n Returning to the process where this was called from , without setting the Month.";
				return;
			}
			this->month = month;
		}

		void setYear(int year)
		{
			if(year < 0){
				cout<<"Out of bound setting the Year = ("<< year << ").\n Returning to the process where this was called from , without setting the Year.";
				return;
			}
			this->year = year;
		}


    // Getter methods
		int getDay()
		{
			return day;
		}
		string getMonth()
		{
			return months[month % 12];
		}
		int getYear()
		{
			return year;
		}

    // Display the date
		void display() const
		{
			cout << day << "/" << months[month] << "/" << year;
		}
		string to_String()
		{
			//return to_string( to_string(day) + "/" + months[month] + "/" + to_string(year));
			string message;
            message += to_string(getDay());
            message += " / ";
            message += months[month];
            message += " / ";
            message += to_string(getYear());\

            return message;
		}


	// Operator Methods:
		// Overloading the assignment operator
		Date& operator=(const Date& other)
		{
			if (this == &other) {
				return *this;
			}
			this->day = other.day;
			this->month = other.month;
			this->year = other.year;
			return *this;
		}
		// Overloading the less than operator
		bool operator<(const Date& other) const
		{
			if (year < other.year)
				return true;
			else if (year == other.year && month < other.month)
				return true;
			else if (year == other.year && month == other.month && day < other.day)
				return true;
			return false;
		}

		// Overloading the greater than operator
		bool operator>(const Date& other) const {
			if (year > other.year)
				return true;
			else if (year == other.year && month > other.month)
				return true;
			else if (year == other.year && month == other.month && day > other.day)
				return true;
			return false;
		}

		// Overloading the equality operator
		bool operator==(const Date& other) const {
			return (day == other.day && month == other.month && year == other.year);
		}

		// Overloading the inequality operator
		bool operator!=(const Date& other) const{
			return !(*this == other);
		}
};
