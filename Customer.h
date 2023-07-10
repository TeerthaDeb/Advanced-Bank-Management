#include <bits/stdc++.h>
#include <string>
#include "Person.h"
#include "gotoxy.h"

using namespace std;


class Cusomer : Person
{
private:
	//variables:
	bool active_status = false , has_visa = false , is_employe = false;
	short number_of_transctions_made = 00;
	double checking_amount = 0 , saving_amount = 0 , visa_amount = 0 , interest_rate , points = 0 , loans = 0;
	long long int account_number = 100000000 + (rand() % 899999999) , visa_number = 1000000000 + (rand() % 8999999999) , employee_number = 0 ;
	
	//functions:

public:
	//variables:

	//functions:

	//default constructor:
	Cusomer()
	{
		
	}

	//constructor(s):
	/*Cusomer()
	{
		
	}*/

	//copy constructors: 
	Cusomer(const Cusomer &object)
	{
		
		return *this;
	}

	//destructor:
	~Cusomer()
	{
		
	}
	//setters:

	//getters:

	//friend functions:

};
