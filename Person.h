#include <bits/stdc++.h>
#include <string>
#include "Date.h"
#include "Address.h"
#include "gotoxy.h"

using namespace std;
class Person
{
	private:
	//variables:
		char name[50], phone_number[50] , sex , password[50] , e_mail[70]; //account_create_date[100] , last_account_modification_date[100] has been removed from here.
		/*
			Defining new persons, without any account number or something.
		*/
		//long long int account_number = 100000000 + (rand() % 899999999) , visa_number = 1000000000 + (rand() % 8999999999) , account_creators_id = 0 , employee_number = 0 , last_modifier = 0;
		//bool have_visa = 0 , is_employee = false;
		//short int birth_year , birth_month , birth_date ; made_transection = 0; has been removed from here.
		//transection transfers[50];
		Date Birth_date;
		Address user_address;
		//functions:
	public:
		//variables:

		//functions:

		//default constructor:
			Person()
			{

			}

		//constructor(s):
			/* Initial was:
			Person(string user_name , string user_password , string user_address , string user_city , string user_province , string user_country , long long int account_creator_id , short int user_birth_date , short int user_birth_month , short int user_birth_year , char user_sex , string user_phone_number , string user_email, double user_checking_amount = 0 , double user_saving_amount= 0 , double user_interest_rate = default_interest_rate)
			{
				set_every_thing_for_user(user_name , user_password , user_address , user_city , user_province , user_country , account_creator_id , user_birth_date , user_birth_month , user_birth_year , user_sex , user_phone_number ,  user_email , user_checking_amount , user_saving_amount , user_interest_rate);
			}
			*/

			Person(string user_name , string user_password , string user_street , string user_city , string user_province , string user_country , string user_PostalCode , short int user_birth_date , short int user_birth_month , short int user_birth_year , char user_sex , string user_phone_number , string user_email)
			{
				set_every_thing_for_user(user_name , user_password , user_street , user_city , user_province , user_country , user_PostalCode, user_birth_date , user_birth_month , user_birth_year , user_sex , user_phone_number , user_email);
			}


			//copy constructors:
			/*customers(const customers &object)
			{

				return *this;
			}*/

			//destructor:
			~Person()
			{

			}
		//setters:
			void set_user_password(string new_password)
			{
				strcpy(password , new_password.c_str());
			}
			void set_user_name(string user_name)
			{
				strcpy(name , user_name.c_str());
			}
			void set_user_address(string user_street , string user_city , string user_province , string user_country , string user_PostalCode)
			{
				user_address.set_Address(user_street , user_city , user_province , user_country , user_PostalCode);
			}
			void set_users_phone_number(string user_phone_number)
			{
				strcpy(phone_number , user_phone_number.c_str());
			}
			void set_email(string email)
			{
				strcpy(e_mail , email.c_str());
			}
			/*
			void set_user_checking_amount(double user_checking_amount)
			{
				checking_amount = user_checking_amount;
			}
			void set_user_saving_amount(double user_saving_amount)
			{
			saving_amount = user_saving_amount;
			}
			void set_user_interest_rate(double user_interest_rate = default_interest_rate)
			{
				interest_rate = user_interest_rate / 100;
			}
			void set_user_visa_amount(double user_visa_amount)
			{
				if(have_visa)
				{
					visa_amount = user_visa_amount;
				}
				else
				{
					printf("\aSorry. The user don't have any visa card right now.");
				}
			}
			*/
			void set_user_birth_date(short int user_birth_day , short int user_birth_month , short int user_birth_year)
			{
				Birth_date.setDate(user_birth_day , user_birth_month , user_birth_year);
			}
			/* Intially it was:
			void set_every_thing_for_user(string user_name , string user_password , string user_address , string user_city , string user_province , string user_country , long long int account_creator_id , short int user_birth_date , short int user_birth_month , short int user_birth_year , char user_sex , string user_phone_number , string user_email, double user_checking_amount = 0 , double user_saving_amount= 0 , double user_interest_rate = default_interest_rate)
			{
				set_user_name(user_name);
				set_user_address(user_address , user_city , user_province , user_country);
				set_user_password(user_password);
				set_user_checking_amount(user_checking_amount);
				set_user_saving_amount(user_saving_amount);
				visa_amount = 0;
				set_user_interest_rate(user_interest_rate);
				account_creators_id = account_creator_id;
				set_user_birth_date(user_birth_date , user_birth_month , user_birth_year);
				sex = user_sex;
				set_users_phone_number(user_phone_number);
				set_email(user_email);
			}
			void set_user_account_creation_date()
			{
				strcpy(account_create_date , date_time_function().c_str());
			}
			void set_account_modification_date()
			{
			    strcpy(last_account_modification_date , date_time_function().c_str());
			}
			void enable_account_status()
			{
				active_status = true;
			}
			void disable_account_status()
			{
				active_status = false;
			}
			*/
			void set_every_thing_for_user(string user_name , string user_password , string user_street , string user_city , string user_province , string user_country , string user_PostalCode, short int user_birth_date , short int user_birth_month , short int user_birth_year , char user_sex , string user_phone_number , string user_email)
			{
				set_user_name(user_name);
				set_user_address(user_street , user_city , user_province , user_country , user_PostalCode);
				set_user_password(user_password);
				// set_user_checking_amount(user_checking_amount);
				// set_user_saving_amount(user_saving_amount);
				// visa_amount = 0;
				// set_user_interest_rate(user_interest_rate);
				// account_creators_id = account_creator_id;
				set_user_birth_date(user_birth_date , user_birth_month , user_birth_year);
				sex = user_sex;
				set_users_phone_number(user_phone_number);
				set_email(user_email);
			}
			//getters:
			/*void print_everything()
			{
				cout<<"Name: "<<setw(20)<<name<<" ;ACC number: "<<account_number<<" ;interest_rate: "<<setw(3)<<interest_rate<<" ;last modified by: "<<last_modifier<<"; is manager :"<<is_employee<<'\n';
			}
			*/
			void print_Debugging_info()
			{
				cout<<"Name: " << this->name << "DOB: "
                << this->Birth_date.to_String() << ' '
                << this->user_address.to_String() <<' '
				<< this->sex <<' ' << this->e_mail <<' ' << this->phone_number <<' ' <<  this->password <<' ';
			}
			/*
			long long int get_total_customers()
			{
				return total_customers;
			}
			long long int get_account_number()
			{
				return account_number;
			}
			long long int get_visa_number()
			{
				if(have_visa){
					return visa_number;
				}
				else{
					return -1;
				}
			}
			long long int get_account_creators_id()
			{
				return account_creators_id;
			}
			*/
			string get_name()
			{
				return name;
			}
			string get_address()
			{
				user_address.display();
			}
			/*
			string get_city()
			{
				return city;
			}
			string get_province()
			{
				return province;
			}
			string get_country()
			{
				return country;
			}

			double get_checking_amount()
			{
				return checking_amount;
			}
			double get_saving_amount()
			{
				return saving_amount;
			}
			bool get_active_status()
			{
				return active_status;
			}
			string get_last_modification_date()
			{
				return last_account_modification_date;
			}
			long long int get_last_modifiers_number()
			{
				return last_modifier;
			}
			*/
			string get_email()
			{
				return e_mail;
			}
		//others:
			/*
			void request_for_visa(long long int last_modifier_id)
			{
				have_visa = true;
				last_modifier = last_modifier_id;
			}
			void create_new_account_number()
			{
				account_number = 100000000 + (rand() % 899999999) + 3;
			}
			void modify_account(long long int modifiers_id , string user_name , string user_address , string user_city , string user_province , string user_country , double user_interest_rate , short int user_birth_date , short int user_birth_month , short int user_birth_year , char user_sex , string user_phone_number ,  string user_email ,  bool user_is_employee_of_the_bank , long long int user_employee_number)
			{
				set_every_thing_for_user(user_name , password , user_address , user_city , user_province , user_country , account_creators_id , user_birth_date , user_birth_month , user_birth_year , user_sex , user_phone_number , user_email , checking_amount , saving_amount , interest_rate);
                last_modified_by(modifiers_id);
			}
			void last_modified_by(long long int employee_id)
			{
				last_modifier = employee_id;
			}
			*/
			void print_every_details_of_Person()
			{
				//gxy(5 , 1) , cout<<"account number:			"<<account_number;
				gxy(5 , 2) , cout<<"Name:\t\t"<<name;
				gxy(5 , 3) , cout<<"Address:\t\t" << user_address.to_String();
				gxy(5 , 4) , cout<<"Phone Number:\t\t"<<phone_number;
				gxy(5 , 5) , cout<<"Sex:\t\t"<<sex;
				gxy(5 , 6) , cout<<"Birh Date:\t\t"<< Birth_date.to_String();
				//gxy(5 , 7) , cout<<"Checking Amount:			"<<checking_amount;
				//gxy(5 , 8) , cout<<"Saving Amount:			"<<saving_amount;
				/*if(have_visa){
					gxy(5 , 9) , cout<<"Visa Amount:	"<<visa_amount;
				}
				else{
					gxy(5 , 9) , cout<<"No Visa for this account";
				}
				gxy(5 , 10) , cout<<"interest rate:			"<<interest_rate;
				gxy(5 , 11) , cout<<"account created by:		"<<account_creators_id;
				if(is_employee){
					gxy(5 , 12) , cout<<"Employee number:	"<<employee_number;
				}
				else{
					gxy(5 , 12) , cout<<"Not an bank employee";
				}
				gxy(5 , 13) , cout<<"Last modified by:			"<<last_modifier;
				gxy(5 , 14) , cout<<"Made_transections:			"<<made_transection;
				*/
				gxy(5 , 15) , cout<<"email						"<<e_mail;
				//gxy(5 , 16) , cout<<"Account created on:		"<<account_create_date;
				//gxy(5 , 17) , cout<<"Last modified on:			"<<last_account_modification_date;
			}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////new
		//getters
		//friend functions:
		//deposits
			/*
			void deposit_into_checking(double amount)
			{
				checking_amount += amount;
			}
			void deposit_into_saving(double amount)
			{
				saving_amount += amount;
			}
			*/
};
