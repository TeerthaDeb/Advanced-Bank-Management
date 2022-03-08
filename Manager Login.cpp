#include <bits/stdc++.h>
#include <conio.h>
#include <string>
#include <windows.h>
using namespace std;
short int height = 28, width = 118 , password_change_fake_try = 0;       	 											////// height = 23 , width = 78 for windows 7
bool access_granted = false , have_record = true;
const double default_interest_rate = 10/100;  																			//per year
// Just for modification of the database : CUSTOMERS.txt and EMPLOYERS.txt


struct transection
{
	double amount = INT_MAX;
	char message[500] = {};
	long long int acount_number = INT_MAX;
};

void setcolor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut,&csbi)){
        wColor=(csbi.wAttributes&0xF0)+(ForgC&0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void gxy(short col, short row)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { col,row };
	SetConsoleCursorPosition(h, position);
}

void wait(int k)
{
    int i;
    for(i=0;i<5;i++){
        printf(" .");
        Sleep(k);
    }
}

void drawboard()
{
	time_t t;time(&t);
	int i, j;
	gxy(0, 0) , printf("%c", 201);
	for (i = 0; i < width; i++)
		printf("%c", 205);
	printf("%c", 187);
	for (i = 0; i < height; i++){
		gxy(0, i + 1) , printf("%c", 186);
		gxy(width + 1, i + 1) , printf("%c", 186);
	}
	gxy(0, height);
	for (i = 0; i < width + 2; i++){
		if (i == 0)
			printf("%c", 200);
		else if (i == width + 1)
			printf("%c", 188);
		else
			printf("%c", 205);
	}
	gxy((width) / 4 + 5, height - 2),printf("Date : %s", ctime(&t)); //shows time
}

class customers
{
	private:
		static long long int total_customers;
private:
	//variables:
		char name[50] , address[20], phone_number[50] , sex , password[50] , city[50] , province[50] , country[50];
		double checking_amount = 0 , saving_amount = 0 , visa_amount = 0 , interest_rate , points = 0 , loans = 0;
		long long int account_number = 100000000 + (rand() % 899999999) , visa_number = 1000000000 + (rand() % 8999999999) , account_creators_id = 0 , employee_number = 0 , last_modified_by = 0;
		bool have_visa = 0 , is_employee = false;
		short int birth_year , birth_month , birth_date , account_create_date , account_create_month , account_create_year , made_transection = 0;
		transection transfers[50];
		//functions:
public:
	//variables:

	//functions:

	//default constructor:
	customers()
	{
	}

	//constructor(s):
	customers(string user_name , string user_password , string user_address , string user_city , string user_province , string user_country , long long int account_creator_id , short int user_birth_date , short int user_birth_month , short int user_birth_year , char user_sex , string user_phone_number , double user_checking_amount = 0 , double user_saving_amount= 0 , double user_interest_rate = default_interest_rate)
	{
		total_customers++;
		set_every_thing_for_user(user_name , user_password , user_address , user_city , user_province , user_country , account_creator_id , user_birth_date , user_birth_month , user_birth_year , user_sex , user_phone_number ,  user_checking_amount , user_saving_amount , user_interest_rate);
	}

	customers(long long int account_creator)
	{
		total_customers++;
        account_creators_id = account_creator;
	}

	//copy constructors:
	/*customers(const customers &object)
	{

		return *this;
	}*/

	//destructor:
	~customers()
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
	void set_user_address(string user_address , string user_city , string user_province , string user_country)
	{
		strcpy(address , user_address.c_str());
		strcpy(city , user_city.c_str());
		strcpy(province , user_province.c_str());
		strcpy(country , user_country.c_str());
	}
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
	void set_user_birth_date(short int user_birth_date , short int user_birth_month , short int user_birth_year)
	{
		birth_date = user_birth_date;
		birth_month = user_birth_month;
		birth_year = user_birth_year;
	}
	void set_every_thing_for_user(string user_name , string user_password , string user_address , string user_city , string user_province , string user_country , long long int account_creator_id , short int user_birth_date , short int user_birth_month , short int user_birth_year , char user_sex , string user_phone_number , double user_checking_amount = 0 , double user_saving_amount= 0 , double user_interest_rate = default_interest_rate)
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
	}
	void set_users_phone_number(string user_phone_number)
	{
		strcpy(phone_number , user_phone_number.c_str());
	}
	//getters:
	void print_everything()
	{
		cout<<"name: "<<name<<" ;acount_number: "<<account_number<<" ;total: "<<saving_amount + checking_amount + visa_amount<<" ;interest_rate: "<<interest_rate<<" ;Loans: "<<loans<<" ;last modified by: "<<last_modified_by <<'\n';
	}
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
	string get_name()
	{
		return name;
	}
	//others:
	void request_for_visa(long long int last_modifier_id)
	{
		have_visa = true;
		last_modified_by = last_modifier_id;
	}
	void create_new_account_number()
	{
		account_number = 100000000 + (rand() % 899999999) + 3;
	}
	void modify_account(long long int modifiers_id , string user_name , string user_address , string user_city , string user_province , string user_country , double user_interest_rate , short int user_birth_date , short int user_birth_month , short int user_birth_year , char user_sex , string user_phone_number ,  bool user_is_employee_of_the_bank , long long int user_employee_number)
	{
		set_every_thing_for_user(user_name , password , user_address , user_city , user_province , user_country , account_creators_id , user_birth_date , user_birth_month , user_birth_year , user_sex , user_phone_number , checking_amount , saving_amount , interest_rate);
		last_modified_by = modifiers_id;
	}
	void print_every_details_for_customer()
	{
		gxy(5 , 1) , cout<<"account number:			"<<account_number;
		gxy(5 , 2) , cout<<"Name:				"<<name;
		gxy(5 , 3) , cout<<"Address:				"<<address<<", "<<city<<", "<<province<<", "<<country;
		gxy(5 , 4) , cout<<"Phone Number:			"<<phone_number;
		gxy(5 , 5) , cout<<"Sex:				"<<sex;
		gxy(5 , 6) , cout<<"Birh Date:				"<<birth_date<<"\\"<<birth_month<<"\\"<<birth_year;
		gxy(5 , 7) , cout<<"Checking Amount:			"<<checking_amount;
		gxy(5 , 8) , cout<<"Saving Amount:			"<<saving_amount;
		if(have_visa){
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
		gxy(5 , 13) , cout<<"Last modified by:			"<<last_modified_by;
		gxy(5 , 14) , cout<<"Made_transections:			"<<made_transection;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////new
	//getters
	//friend functions:
	//deposits
	void deposit_into_checking(double amount)
	{
		checking_amount += amount;
	}
	void deposit_into_saving(double amount)
	{
		saving_amount += amount;
	}
};

long long int customers::total_customers = 0;

class bank_employee
{
	private:
		static long long int total_employers ;
private:
	//variables:
	char name[50] , address[20] , password[50] , phone_number[50] , sex , city[50] , province[20] , country[50];
    long long int employee_number = 1000000 + (rand() % 8999999) , income_per_week;
	bool is_manager = false;
	long int accounts_created = 0;
	short int birth_date , birth_month , birth_year;
	//functions:

public:
	//variables:

	//functions:

	//default constructor:
	bank_employee()
	{
		total_employers++;
	}

	bank_employee(string employee_name , string employee_phone , string employee_password , string employee_address , string employee_city , string employee_province , string employee_country , char employee_sex , long long int employee_income_per_week , short int emplyoee_birth_date , short int employee_birth_month , short int employee_birth_year , bool is_employee_manager = false)
	{
		total_employers++;
		set_everything(employee_name , employee_phone , employee_password , employee_address , employee_city , employee_province , employee_country , employee_sex , employee_income_per_week , emplyoee_birth_date , employee_birth_month , employee_birth_year , is_employee_manager);
	}

	//copy constructors:
	/*bank_employee(const bank_employee &object)
	{

		return *this;
	}*/

	//destructor:
	~bank_employee()
	{

	}
	//setters:
	void set_everything(string employee_name , string employee_phone , string employee_password , string employee_address , string employee_city , string employee_province , string employee_country , char employee_sex , long long int employee_income_per_week , short int emplyoee_birth_date , short int employee_birth_month , short int employee_birth_year , bool is_employee_manager = false)
	{
		strcpy(name , employee_name.c_str());
		strcpy(phone_number , employee_phone.c_str());
		strcpy(password , employee_password.c_str());
		strcpy(address , employee_address.c_str());
		strcpy(city , employee_city.c_str());
		strcpy(province , employee_province.c_str());
		strcpy(country , employee_country.c_str());
		sex = employee_sex;
		income_per_week = employee_income_per_week;
		is_manager = is_employee_manager;
		birth_date = emplyoee_birth_date;
		birth_month = employee_birth_month;
		birth_year = employee_birth_year;
	}
	void set_new_employee_number()
	{
		employee_number = 1000000 + (rand() % 8999999) + 3;
	}
	void created_new_account()
	{
		accounts_created++;
	}
	//getters:
	void print_every_thing()
	{
		cout<<"name: "<<name<<" , address: " << address<< " , phone: " << phone_number <<" , employee_number : " <<employee_number << " , is manager : " << is_manager;
	}
	long long int get_employers_number()
	{
		return employee_number;
	}
	void print_name()
	{
	    printf("%s" ,name);
	}
	bool check_password(string employee_password)
	{
		return !strcasecmp(password , employee_password.c_str());
	}
	string get_employee_name()
	{
		return name;
	}
	bool check_is_manager()
	{
		return is_manager;
	}
	void show_full_details()
	{
		gxy(5 , 1) , cout<<"Employer Number:			"<<employee_number;
		gxy(5 , 2) , cout<<"Name:				"<<name;
		gxy(5 , 3) , cout<<"Address:				"<<address<<", "<<city<<", "<<province<<", "<<country;
		gxy(5 , 4) , cout<<"Phone Number:			"<<phone_number;
		gxy(5 , 5) , cout<<"Sex:				"<<sex;
		gxy(5 , 6) , cout<<"Birh Date:				"<<birth_date<<"\\"<<birth_month<<"\\"<<birth_year;
		gxy(5 , 7) , cout<<"Is Manager:			"<<is_manager;
		gxy(5 , 8) , cout<<"accounts created:			"<<accounts_created;
		gxy(5 , 9) , cout<<"Income per week:			"<<income_per_week;
	}
	//other functions:
	void change_password(string new_password)
	{
		strcpy(password , new_password.c_str());
	}
};

long long int bank_employee::total_employers = 0;

bool check_password(string password)
{
	if(password.size() < 8){
		return true;
	}
	bool is_alpha , is_didgit;
	is_alpha = is_didgit = false;
	for(int i=0 ; password[i] ; i++){
		if(is_alpha == false){
			is_alpha = isalpha(password[i]);
		}
		if(is_didgit == false){
			is_didgit = isdigit(password[i]);
		}
	}
	if(is_alpha and is_didgit)
	{
		return false;
	}
	else{
		return true;
	}
}

bool check_in_others_numbers(long long int new_number , vector<long long int> existing_number)
{
	for(int i = 0; i < existing_number.size(); i++)
	{
		if(new_number == existing_number[i])
		{
			return true;
		}
	}
	return false;
}

void log_out(bank_employee current_employee)
{
	system("cls");
	drawboard();
	char ch;
	gxy(10 , 5);
	printf("Are you sure to log out?(Y/N):");
	ch = getch();
	cin.ignore();
	if(ch!='y' and ch!='Y'){
		return;
	}
	gxy(10 , 7);
	cout<<current_employee.get_employee_name()<<" , loging out of your id";
	gxy(10 , 16);
	printf("press any key to exit from the program...\b");
	getch();
	exit(0);
}

void create_new_customer(bank_employee current_employee)
{
	cin.ignore();
	system("cls");
	drawboard();
	char choice , sex;
	bool check_employee = false;
	vector<customers> clients;
	vector<long long int> other_customers_bank_number;
	customers temp_customer , new_customer;
	string name , address , city , province , country , password , phone_number;
	double checking_amount , saving_amount , interest_rate = default_interest_rate;
	long long int customer_employee_number ;
	short int birth_date , birth_month , birth_year;
	FILE *customers_file_pointer;
	customers_file_pointer = fopen("CUSTOMERS.txt" , "r+");
	while(fread(&temp_customer , sizeof(temp_customer) , 1 , customers_file_pointer) == 1)
	{
		clients.push_back(temp_customer);
		other_customers_bank_number.push_back(temp_customer.get_account_number());
	}
	gxy(2 , 2) , printf("Enter Customer name: ") , getline(cin , name);
	while(name.size() == 0){
		gxy(2 , 3) , printf("Enter Customer name(name cannot be empty):    \b\b\b") , getline(cin , name);
	}
	gxy(2 , 4) ,printf("Enter Customer address: ") , getline(cin , address);
	gxy(2 , 5) ,printf("Enter customer city: ") , getline(cin , city);
	gxy(2 , 6) ,printf("Enter customer province: "), getline(cin , province);
	gxy(2 , 7) ,printf("Enter customer country: ") , getline(cin , country);
	gxy(2 , 8) ,printf("Enter Customer checking amount : ") , cin>>checking_amount;
	while(checking_amount<0){
		gxy(2 , 9) ,printf("Enter Customer checking amount(can not be less than 0):                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b") , cin>>checking_amount;
	}
	gxy(2 , 10) ,printf("Enter Customer saving amount: ") , cin>>saving_amount ;
	while(saving_amount<0){
		gxy(2 , 11) ,printf("Enter Customer saving amount(can not be less than 0):                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b") , cin>>saving_amount;
	}
	gxy(2 , 12) ,printf("Modify_interest_rate(Y/N): ");
	cin.ignore();
	scanf("%c" ,&choice);
	if(choice == 'Y' or choice == 'y')
	{
		gxy(5 , 13) , printf("Enter Customer interest_rate: ") , cin>>interest_rate;
	}
	gxy(2 , 14) ,printf("Enter Customer birth date: ") , cin>>birth_date;
	while(birth_date>31 or birth_date < 1){
		gxy(2 , 15) ,printf("Enter Customer Birthdate(can not be less than 0):                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b") , cin>>birth_date;
	}
	gxy(2 , 16) ,printf("Enter user birth month: ") , cin>>birth_month;
	while(birth_month>12 or birth_date < 1){
		gxy(2 , 17) ,printf("Enter Customer BirthMonth(can not be less than 0):                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b") , cin>>birth_month;
	}
	gxy(2 , 18) ,printf("Enter user birth year: ") , cin>>birth_year;
	while(birth_year>2022 or birth_year < 1910){
		gxy(2 , 19) ,printf("Enter Customer BirthYear(can not be imaginary):                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b") , cin>>birth_year;
	}
	gxy(2 , 20) ,printf("Enter sex(M / F / T / O): ");
	cin.ignore();
	scanf("%c" ,&sex);
	while(sex != 'M' and sex != 'm' and sex != 'F' and sex != 'f' and sex != 'T' and sex != 't' and sex != 'O' and sex != 'o'){
		gxy(2 , 20) ,printf("\a	Enter sex(M / F / T / O): ");
		scanf("%c" ,&sex);
	}

	gxy(2 , 21) ,printf("Is customer employee of the bank(0/1): "); cin>>check_employee;
	if(check_employee){
		gxy(2 , 22) ,printf("Employee Number: ");
		cin>>customer_employee_number;
	}
	cin.ignore();
	gxy(2 , 23) ,printf("Enter Phone number: ");
	getline(cin , phone_number);
	gxy(2 , 24) ,printf("Enter password: ");
	getline(cin , password);
	while(check_password(password)){
		gxy(2 , 25) , printf("Enter password: ");
		getline(cin , password);
	}
	new_customer.set_every_thing_for_user(name , password , address , city , province , country , current_employee.get_employers_number() , birth_date , birth_month , birth_year , sex , phone_number , checking_amount , saving_amount , interest_rate);
	while(check_in_others_numbers(new_customer.get_account_number() , other_customers_bank_number)){
		new_customer.create_new_account_number();
	}
	current_employee.created_new_account();
	system("cls");
	drawboard();
	gxy(5 , 6);
	new_customer.print_everything();
	gxy(30 , 13) , printf("Account Nmber : ") , cout<<new_customer.get_account_number();
	fclose(customers_file_pointer);
	customers_file_pointer = fopen("CUSTOMERS.txt" , "a+");
	fwrite(&new_customer , sizeof(new_customer) , 1 , customers_file_pointer);
	fclose(customers_file_pointer);
	gxy(5 , 20) , printf("Press any key to go to main menu again...\b");
	getch();
	gxy(5 , 21) , printf("Going to main menu");
	wait(200);
}

void Remove_Customers_account()
{
    FILE *ptr1,*ptr2;
    ptr1=fopen("CUSTOMERS.txt" , "r");
    ptr2=fopen("temp.txt" , "w+");
	system("cls");
    //setcolor(04);
    drawboard();
    customers c1;
	char surity = 'n';
    gxy(6,4),printf("Enter the Account Number that you want to remove: ");
    long long int delacc,tmp;
    cin>>delacc;
    bool acc_find=0;
    while(fread(&c1, sizeof(c1), 1, ptr1)){
        tmp=c1.get_account_number();
        if(tmp==delacc){
            acc_find=999;
			gxy(15 , 7),	cout<<"Are you sure to delete "<<c1.get_name()<<"'s name?(y/n): ";
			surity = getch();
			if(surity != 'Y' and surity != 'y'){
				///////////////////// a warnig of others opening accounts
				fwrite(&c1, sizeof(c1) ,1 , ptr2);
			}
        }
        else{
            fwrite(&c1, sizeof(c1) ,1 , ptr2);
        }
    }
    if(acc_find>0){
		if(surity == 'y' or surity == 'Y'){
			gxy(10,12),printf("Deleted the target account");
		}
        gxy(10,14),printf("Press any key to go to main menu...\b");
		getch();
        wait(500);
    }
    else{
        gxy(10,12),printf("Not found the target account");
        gxy(10,14),printf("Want to search again? (Y/N)");
        char cho;
        cho=getch();
        if(cho=='Y'||cho=='y'){
            fclose(ptr1);
			fclose(ptr2);
            Remove_Customers_account();
        }
    }
    fclose(ptr1),fclose(ptr2);
    remove("CUSTOMERS.txt");
    rename("temp.txt" , "CUSTOMERS.txt");
}

void Modify_customers_account(bank_employee current_emplyoee)
{
    FILE *ptr1,*ptr2;
    ptr1=fopen("CUSTOMERS.txt" , "r");
    ptr2=fopen("temp.txt" , "w+");
	system("cls");
    //setcolor(04);
    drawboard();
    customers c1;
	char surity = 'n';
    gxy(6,4),printf("Enter the Account Number that you want to modify: ");
    long long int acc_number = 0,tmp;
    cin>>acc_number;
    bool acc_find=0;
    while(fread(&c1, sizeof(c1), 1, ptr1)){
        if(acc_number == c1.get_account_number()){
            acc_find=999;
			cin.ignore();
			gxy(15 , 7),	cout<<"Are you sure to modify "<<c1.get_name()<<"'s account?(y/n): ";
			surity = getch();
			if(surity == 'Y' or surity == 'y'){
				system("cls");
				drawboard();
				string name , address , city , province , country , phone_number;
				char choice , sex;
				double interest_rate;
				short int birth_date , birth_month , birth_year;
				bool check_employee = 0;
				long long int customer_employee_number ;
				gxy(2 , 2) , printf("Enter Customer name(default name = %s): " ,c1.get_name().c_str()) , getline(cin , name);
				while(name.size() == 0){
					gxy(2 , 3) , printf("Enter Customer name(name cannot be empty):    \b\b\b") , getline(cin , name);
				}
				gxy(2 , 4) ,printf("Enter Customer address: ") , getline(cin , address);
				gxy(2 , 5) ,printf("Enter customer city: ") , getline(cin , city);
				gxy(2 , 6) ,printf("Enter customer province: "), getline(cin , province);
				gxy(2 , 7) ,printf("Enter customer country: ") , getline(cin , country);
				gxy(2 , 8) ,printf("Modify_interest_rate(Y/N): ");
				cin.ignore();
				scanf("%c" ,&choice);
				if(choice == 'Y' or choice == 'y'){
					printf("Enter Customer interest_rate: ") , cin>>interest_rate;
				}
				gxy(2 , 9) ,printf("Enter Customer birth date: ") , cin>>birth_date;
				while(birth_date>31 or birth_date < 1){
					gxy(2 , 10) ,printf("Enter Customer Birthdate(can not be less than 0):                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b") , cin>>birth_date;
				}
				gxy(2 , 11) ,printf("Enter user birth month: ") , cin>>birth_month;
				while(birth_month>12 or birth_date < 1){
					gxy(2 , 12) ,printf("Enter Customer BirthMonth(can not be less than 0):                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b") , cin>>birth_month;
				}
				gxy(2 , 13) ,printf("Enter user birth year: ") , cin>>birth_year;
				while(birth_year>2022 or birth_year < 1910){
					gxy(2 , 14) ,printf("Enter Customer BirthYear(can not be imaginary):                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b") , cin>>birth_year;
				}
				gxy(2 , 15) ,printf("Enter sex(M / F / T / O): ");
				cin.ignore();
				scanf("%c" ,&sex);
				while(sex != 'M' and sex != 'm' and sex != 'F' and sex != 'f' and sex != 'T' and sex != 't' and sex != 'O' and sex != 'o'){
					gxy(2 , 16) ,printf("\a	Enter sex(M / F / T / O): ");
					scanf("%c" ,&sex);
				}
				cin.ignore();
				gxy(2 , 17) , printf("Enter Customers Phone Number: ");
				getline(cin , phone_number);
				gxy(2 , 18) ,printf("Is customer employee of the bank(0/1): "); cin>>check_employee;
				if(check_employee){
					gxy(2 , 19) ,printf("Employee Number: ");
					cin>>customer_employee_number;
				}
				c1.modify_account(current_emplyoee.get_employers_number() , name , address , city , province , country , interest_rate , birth_date , birth_month , birth_year , sex , phone_number ,  check_employee , customer_employee_number);
			}
        }
        fwrite(&c1, sizeof(c1) ,1 , ptr2);
    }
	system("cls");
	drawboard();
    if(acc_find>0){
		if(surity == 'y' or surity == 'Y'){
			gxy(10,12),printf("modified the target account");
		}
        gxy(10,14),printf("Press any key to go to main menu...\b");
		getch();
        wait(500);
    }
    else{
        gxy(10,12),printf("Not found the target account");
        gxy(10,14),printf("Want to search again? (Y/N)");
        char cho;
        cho=getch();
        if(cho=='Y'||cho=='y'){
            fclose(ptr1);
			fclose(ptr2);
            Remove_Customers_account();
        }
    }
    fclose(ptr1),fclose(ptr2);
    remove("CUSTOMERS.txt");
    rename("temp.txt" , "CUSTOMERS.txt");
}

void show_full_account_details()
{
	FILE *customers_file_pointer;
	customers_file_pointer = fopen("CUSTOMERS.txt" , "r");
	customers customer;
	long long int account_number;
	bool found_customer = false;
	system("cls");
	drawboard();
	gxy(6 , 4),printf("Enter the account number to show full info of the account: ");
	cin>>account_number;
	gxy(6 , 7) , printf("Searching");
	while(fread(&customer, sizeof(customer), 1, customers_file_pointer)){
        if(account_number == customer.get_account_number()){
			found_customer = true;
			system("cls");
			drawboard();
           	customer.print_every_details_for_customer();
    	}
		else if(found_customer == false){
			printf(". ");
		}
	}
	if(found_customer == false){
		gxy(6 , 10) , printf("No account found with this number");
	}
	fclose(customers_file_pointer);
	gxy(5 , 20);
	printf("Press any key to go to main menu again...\b");
	getch();
	gxy(5 , 21);printf("Going to main menu");
	wait(100);
}

void read_all_customers(bank_employee current_employee)
{
	system("cls");
	drawboard();
	vector<customers> clients;
	customers temp_customer;
	FILE *file_pointer;
	file_pointer = fopen("CUSTOMERS.txt" , "r+");
	while(fread(&temp_customer , sizeof(temp_customer) , 1 , file_pointer) == 1){
		clients.push_back(temp_customer);
	}
	fclose(file_pointer);
	for(long long int i=0 ; i < clients.size() ; i++)
	{
		gxy(2 , i+1) , clients[i].print_everything() , cout<<'\n';
	}
	if(clients.size() == 0){
		gxy(25 , 15) , printf("There is no client in your bank");
	}
	gxy(5 , 20) , printf("Press any key to go to main menu again...\b");
	getch();
	gxy(5 , 21) , printf("Going to main menu");
	wait(200);
}

void created_accounts_by_the_user(bank_employee current_employee)
{
	system("cls");
	drawboard();
	vector<customers> clients;
	customers temp_customer;
	FILE *file_pointer;
	file_pointer = fopen("CUSTOMERS.txt" , "r+");
	while(fread(&temp_customer , sizeof(temp_customer) , 1 , file_pointer) == 1){
		if(temp_customer.get_account_creators_id() == current_employee.get_employers_number()){
			clients.push_back(temp_customer);
		}
	}
	fclose(file_pointer);
	for(long long int i=0 ; i < clients.size() ; i++){
		gxy(2 , i+1) , clients[i].print_everything() , cout<<'\n';
	}
	if(clients.size() == 0){
		gxy(25 , 15) , printf("There is no account that was created by you...");
	}
	gxy(5 , 20) , printf("Press any key to go to main menu again...\b");
	getch();
	gxy(5 , 21) , printf("Going to main menu");
	wait(200);
}

void create_employee() //Formating done
{

	vector<bank_employee> employers;
	vector<long long int> others_numbers ;
	bank_employee temp_employer;
	string name , address , password , phone_number , city , province , country;
	char sex;
	long long int size_of_employee = sizeof(bank_employee) , weekly_income;
	short int birth_date , birth_month , birth_year;
	bool is_manager = false;
	FILE *file_pointer;
	file_pointer = fopen("EMPLOYERS.txt" , "r+");
	have_record = file_pointer;
	while(fread(&temp_employer , size_of_employee , 1 , file_pointer) == 1){
		employers.push_back(temp_employer);
		others_numbers.push_back(temp_employer.get_employers_number());
	}
	bank_employee new_employer;
	if(have_record){
		cin.ignore();
	}
	else{
		is_manager = true;
	}
	system("cls");
	drawboard();
	cin.ignore();
	gxy(5 , 2),printf("Enter employer full name(50 words maximum):  "); getline(cin , name);
	while(name.size() == 0){
		gxy(5 , 3) , printf("Enter Full name(Cannot be Empty): "); getline(cin , name);
	}
	gxy(5 , 4),printf("Enter employer phone_number(maximum 50 words) : ");getline(cin , phone_number);
	while(phone_number.size() == 0 or isalpha(*phone_number.c_str())){
		gxy(5 , 5) , printf("Enter valid Phone number:");getline(cin , phone_number);
	}
	gxy(5 , 6),printf("enter employer address(50 words maximum): "); getline(cin , address);
	gxy(5 , 7),printf("Enter employer city(maximum 20 words): "); getline(cin , city);
	gxy(5 , 8),printf("Enter employer province(maximum 20 words): "); getline(cin , province);
	gxy(5 , 9),printf("Enter employer country(maximum 50 words): "); getline(cin , country);
	gxy(5 , 10),printf("Enter employer sex(M/F/T/O): "); sex = getch();
	while(sex!= 'M' and sex!= 'm' and sex!= 'F' and sex!= 'f' and sex!= 'T' and sex!= 't' and sex!= 'O' and sex!= 'o'){
		gxy(5 , 11),printf(">>>>>>>>\aEnter employer sex(M/F/T/O): "); sex = getch();
	}
	gxy(5 , 12),printf("Enter employer birth date(int. only): "); cin>>birth_date;
	while(birth_date>31 or birth_date < 1){
		gxy(5 , 13) ,printf("Enter Employer Birthdate(can not be less than 0 and more than 31):                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b") ;
		cin>>birth_date;
	}
	gxy(5 , 14),printf("Enter employer birth month(int. only): "); cin>>birth_month;
	while(birth_month>12 or birth_date < 1){
		gxy(5 , 15) ,printf("Enter employer BirthMonth(can not be less than 0):                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		cin>>birth_month;
	}
	gxy(5 , 16),printf("Enter employer birth year(int. only): "); cin>>birth_year;
	while(birth_year>2022 or birth_year < 1910){
		gxy(5 , 17) ,printf("Enter Emplyoer BirthYear(can not be imaginary):                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		cin>>birth_year;
	}
	gxy(5 , 18),printf("Enter employer weekly wage(int. only): "); cin>>weekly_income;
	gxy(5 , 19),printf("Enter password(password should be atleast 8 words and have numbers and alpphabets): "); cin.ignore(); getline(cin , password);
	while(check_password(password)){
		gxy(2 , 20),printf("\b\b\a>>>>>>>>>>>>>>Enter password(password should be atleast 8 words and have numbers and alpphabets):                \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"); getline(cin , password);
	}
	if(is_manager == false){
		gxy(6 , 21),printf("Is this employee a manager(1/0) : "); cin>>is_manager;
	}
	new_employer.set_everything(name , phone_number , password , address , city , province , country , sex , weekly_income , birth_date , birth_month , birth_year , is_manager);
	while(check_in_others_numbers(new_employer.get_employers_number() , others_numbers)){
		new_employer.set_new_employee_number();
	}
	employers.push_back(new_employer);
	fclose(file_pointer);
	file_pointer = fopen("EMPLOYERS.txt" , "w+");
	for(long long int i=0 ; i<employers.size() ; i++){
		fwrite(&employers[i] , size_of_employee , 1 , file_pointer);
	}
	fclose(file_pointer);
	system("cls");
	drawboard();
	new_employer.show_full_details();
	gxy(6 , 16),printf(">>>>>>>>>>New employee id : %d" ,new_employer.get_employers_number());
	gxy(6 , 17),printf("Press any key to go to main menu again...\b");
	getch();
	gxy(6 , 18),printf("Going to main menu");
	wait(500);
}

void read_all_employees()
{
	system("cls");
	drawboard();
	vector<bank_employee> employers;
	bank_employee temp_employer;
	long long int size_of_employee = sizeof(bank_employee) ;
	FILE *file_pointer;
	file_pointer = fopen("EMPLOYERS.txt" , "r+");
	while(fread(&temp_employer , size_of_employee , 1 , file_pointer) == 1){
		employers.push_back(temp_employer);
	}
	fclose(file_pointer);
	for(long long int i=0 ; i<employers.size() ; i++){
		gxy(2 , i+1) , employers[i].print_every_thing();
	}
	gxy(5 , 20) , printf("Press any key to go to main menu again...\b");
	getch();
	gxy(5 , 21) , printf("Going to main menu");
	wait(200);
}

void change_employee_password(bank_employee current_employee)
{
    cin.ignore();
	string given_password;
	vector<bank_employee> employers;
	bank_employee temp_employer;
	long long int target_employee_index = 0 , i;
	FILE *file_pointer;
	file_pointer = fopen("EMPLOYERS.txt" , "r");
	system("cls");
	drawboard();
	for(i = 0 ; fread(&temp_employer , sizeof(temp_employer) , 1 , file_pointer) == 1 ; i++){
		employers.push_back(temp_employer);
		if(current_employee.get_employers_number() == temp_employer.get_employers_number()){
			target_employee_index = i;
			gxy(5 , 5) , cout<<temp_employer.get_employee_name()<<" 's password going to be changed.";
		}
	}
	fclose(file_pointer);
	gxy(5 , 7) , printf("Enter current password: "); getline(cin , given_password);
	if(employers[target_employee_index].check_password(given_password)){
		gxy(5 , 9) , printf("Enter new password: ");
		getline(cin , given_password);
		while(check_password(given_password)){
			gxy(5 , 11) , printf("Enter new password(Include numbers and letters): ");
			getline(cin , given_password);
		}
		employers[target_employee_index].change_password(given_password);
		file_pointer = fopen("EMPLOYERS.txt" , "w");
		for(i = 0; i<employers.size() ; i++){
			fwrite(&employers[i] , sizeof(employers[i]) , 1 , file_pointer);
            employers[i].print_every_thing();
		}
		fclose(file_pointer);
		gxy(5 ,15) , printf("Changed Password Succesfully");
	}
	else{
		gxy(5 ,9) , printf("Password not matched. Cannot change password");
		if(password_change_fake_try > 2){
			gxy(5 , 17) , printf("Too many fail tries. Logging out...\b");
			wait(300);
			exit(0);
		}
		else{
			password_change_fake_try++;
		}
	}
	gxy(5 , 20) , printf("Press any key to go to main menu again...\b");
	getch();
	gxy(5 , 21) , printf("Going to main menu");
	wait(200);
}

void main_menu(bank_employee current_employee)
{
	char main_menu_choice;
	main_menu_start2:
	system("cls");
	drawboard();
	gxy(width / 2 - 30 , 1) , 	printf(">>>>>>>>>>>>>>>>>>>>>>	 Main Menu	<<<<<<<<<<<<<<<<<<<<<<<<<");
	gxy(width / 2 - 30 , 3) , 	printf("###################	    New Clients	    ###################");
	gxy(30 , 4),		printf("[0] create a clients account");
	gxy(30 , 5),		printf("[1] show accounts");
	gxy(30 , 6),		printf("[2] modify an account");
	gxy(30 , 7),		printf("[3] delete an account");
	gxy(30 , 8),		printf("[4] show full details of an account");
	gxy(width / 2 - 30 , 9) , 	printf("###################	  your account  	###################");
	gxy(30 , 11),		printf("[5] Show your created accounts");
	gxy(30 , 12),		printf("[6] change your password");
	gxy(30 , 13),		printf("[7] change your account details");
	gxy(30 , 14),		printf("[8] log out");
	gxy(width / 2 - 10 , 23) ,	printf("Enter your selection..:  \b");
	main_menu_choice = getch();
	cin.ignore();
	switch (main_menu_choice){
		case '0' :{
						create_new_customer(current_employee);
						break;
		}
		case '1' :{
						read_all_customers(current_employee);
						//Modify_customers_account();
						break;
		}
		case '2' :{
						Modify_customers_account(current_employee);
						//read_all_customers(current_employee);
						break;
		}
		case '3' :{
						Remove_Customers_account();
						//created_accounts_by_the_user(current_employee);
						break;
		}
		case '4' :{
						show_full_account_details();
						//Remove_Customers_account();
						break;
		}
		case '5' : {
						created_accounts_by_the_user(current_employee);
						//create_employee();
						break;
		}
		case '6' :	{
						change_employee_password(current_employee);
						//read_all_employees();
						break;
		}
		case '8' :	{
						log_out(current_employee);
						break;
		}
		default:{
						gxy(width / 2 - 10 , 24) ,	printf("Invalid Selection:  ");
						wait(500);
						break;
		}
	}
	goto main_menu_start2;
}

void show_full_details_of_an_employee()
{
	FILE *employee_file_pointer;
	employee_file_pointer = fopen("EMPLOYERS.txt" , "r");
	bank_employee employee;
	long long int employee_number;
	bool found_employee = false;
	system("cls");
	drawboard();
	gxy(6 , 4),printf("Enter the account number to show full info of the account: ");
	cin>>employee_number;
	gxy(6 , 7) , printf("Searching");
	while(fread(&employee, sizeof(employee), 1, employee_file_pointer)){
        if(employee_number == employee.get_employers_number()){
			found_employee = true;
			system("cls");
			drawboard();
           	employee.show_full_details();
			break;
    	}
		else if(found_employee == false){
			printf(". ");
		}
	}
	if(found_employee == false){
		gxy(6 , 10) , printf("No account found with this number");
	}
	fclose(employee_file_pointer);
	gxy(5 , 20);
	printf("Press any key to go to main menu again...\b");
	getch();
	gxy(5 , 21);printf("Going to main menu");
	wait(100);
}

void main_menu_for_managers(bank_employee current_employee)
{
	char main_menu_choice;
	main_menu_start:
	system("cls");
	drawboard();
	gxy(width / 2 - 30 , 1) , 	printf(">>>>>>>>>>>>>>>>>>>>>>	 Main Menu	<<<<<<<<<<<<<<<<<<<<<<<<<");
	gxy(width / 2 - 30 , 3) , 	printf("###################	    New Clients	    ###################");
	gxy(30 , 4),		printf("[0] create a client account");
	gxy(30 , 5),		printf("[1] show accounts");
	gxy(30 , 6),		printf("[2] modify an account");
	gxy(30 , 7),		printf("[3] delete an account");
	gxy(30 , 8),		printf("[4] show full details of an account");
	gxy(30 , 9),		printf("[5] deposit money into an account");
	gxy(width / 2 - 30 , 11) , 	printf("###################	  your account  	###################");
	gxy(30 , 13),		printf("[6] Show your created accounts");
	gxy(30 , 14),		printf("[7] change your password");
	gxy(30 , 15),		printf("[8] change your account details");
	gxy(30 , 16),		printf("[9] log out");
	gxy(width / 2 - 30 , 17) , 	printf("###################	  employers account	  ###################");
	gxy(30 , 18),		printf("[.] Show full details of an employer");
	gxy(30 , 19),		printf("[+] Add new employee.");
	gxy(30 , 20),		printf("[*] show all employee");
	gxy(30 , 21),		printf("[/] Modify Employers Account");
	gxy(30 , 22),		printf("[-] Delete an employee");
	gxy(width / 2 - 10 , 24) ,	printf("Enter your selection..:  \b");
	main_menu_choice = getch();
	switch (main_menu_choice){
		case '0' :{
						create_new_customer(current_employee);
						break;
		}
		case '1' :{
						read_all_customers(current_employee);
						//Modify_customers_account();
						break;
		}
		case '2' :{
						Modify_customers_account(current_employee);
						//read_all_customers(current_employee);
						break;
		}
		case '3' :{
						Remove_Customers_account();
						//created_accounts_by_the_user(current_employee);
						break;
		}
		case '4' :{
						show_full_account_details();
						//Remove_Customers_account();
						break;
		}
		case '6' : {
						created_accounts_by_the_user(current_employee);
						//create_employee();
						break;
		}
		case '7' :	{
						change_employee_password(current_employee);
						//read_all_employees();
						break;
		}
		case '9' :	{
						log_out(current_employee);
						break;
		}
		case '+' :	{
						create_employee();
						//change_employee_password(current_employee);
						break;
		}
		case '*' :{
						read_all_employees();
						//log_out(current_employee);
						break;
		}
		case '.' :{
						show_full_details_of_an_employee();
						break;
		}
		default:{
						gxy(width / 2 - 10 , 24) ,	printf("Invalid Selection:  ");
						wait(500);
						break;
		}
	}
	goto main_menu_start;
}

void log_in_screen()
{
	vector<bank_employee> employers;
	bank_employee temp_employer;
	long long int log_in_id , i;
	long long int size_of_employee = sizeof(bank_employee) ;
	bool check_employee = false;
	fstream file_pointer;
	char log_in_password[50];
	file_pointer.open("EMPLOYERS.txt" , ios::in);
	//file_pointer = fopen("EMPLOYERS.txt" , "r+");
	drawboard();
	if (file_pointer)
	{
		while(!file_pointer.eof())
		{
			file_pointer.read((char*) &temp_employer , sizeof(temp_employer));
			employers.push_back(temp_employer);
		}
	}
	else
	{
		gxy(5 , 10),printf("No manager found.Create a new id for the manager. Redirectig to manager account creator page...");
		getch();
		have_record = false;
		create_employee();
		//fclose(file_pointer);
		file_pointer.close();
		file_pointer.open("EMPLOYERS.txt" , ios::in);
		while(!file_pointer.eof())
		{
			file_pointer.read((char*)&temp_employer , sizeof(temp_employer));
			employers.push_back(temp_employer);
		}
		system("cls");
		drawboard();
	}
	log_in_again:
	gxy(5 , 5),printf("Enter id: ");
	cin>>log_in_id;
	for(i=0 ; i<employers.size() ; i++)
	{
		if(log_in_id == employers[i].get_employers_number()){
			temp_employer = employers[i];
			check_employee = true;
			break;
		}
	}
	if(check_employee){
		gxy(5 , 8),printf("Enter Password: ");
		cin>>log_in_password;
		access_granted = temp_employer.check_password(log_in_password);
	}
	else{
		printf("No user found. going to log in screen again");
		wait(700);
		system("cls");
		drawboard();
		file_pointer.close();
		goto log_in_again;
	}
	if(access_granted){
		gxy(width/2 - 20 , height/2 + 5), printf("Welcome "); cout<<temp_employer.get_employee_name();
		gxy(width / 2 - 10 , height/2 + 6); wait(100);
		gxy(10 ,  height/2 + 8), printf("Redirecting to main menu .");
		wait(250);
		file_pointer.close();
		if(temp_employer.check_is_manager()){
			main_menu_for_managers(temp_employer);
		}
		else{
			main_menu(temp_employer);
		}
	}
	else{
		printf("Wrong password. Going to log in screen again");
		wait(500);
		check_employee = false;
		system("cls");
		drawboard();
		file_pointer.close();
		goto log_in_again;
	}
}

int main()
{
	/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>							Should run from here                                             <<<<<<<<<<<<<<<<<<<<<<<<<<<*/
    log_in_screen();
	return 0;
}
