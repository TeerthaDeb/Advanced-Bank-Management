#include<bits/stdc++.h>
#include <string>
#include "time.h"
#include "gotoxy.h"

using namespace std;

class Transection
{
private:
	double amount = INT_MAX;
	long long int account_number = INT_MAX;
	string message , transection_made_from;
	Time time_of_transection;

public:
	//default constructor:
	Transection()
	{
	}

	//constructor(s):
	Transection(double amount , long long int account_number , Time time_of_transection , string transection_made_from , string message)
	{
		set_everything_for_transection(amount , account_number , time_of_transection , transection_made_from , message);
	}

	//copy constructors:
	Transection(const Transection &object)
	{
		this->amount = object.amount;
		this->account_number= object.account_number;
		this->message   = object.message ;
		this->transection_made_from = object.transection_made_from;
		this->time_of_transection = object.time_of_transection;
		//return *this;
	}

	//destructor:
	~Transection()
	{

	}
	//setters:
	void set_everything_for_transection(double amount , long long int account_number , Time time_of_transection , string transection_made_from , string message){
		this->amount = amount ;
		this->account_number = account_number ;
		this->message  = message ;
		this->transection_made_from = transection_made_from;
		this->time_of_transection = time_of_transection;
	}
	//getters:
	void print_transection_details(){
		gxy(5 , 5) , cout<< "Transection was made from : " << this->transection_made_from;
		gxy(5 , 6) , cout<< this->amount << " was transffer to " << this->account_number;
		gxy(5 , 7) , cout<< "Time of Transection : " << this->time_of_transection.to_String();
		gxy(5 , 8) , cout<< "Message about the transection: " << this->message;
	}
	//friend functions:

};
