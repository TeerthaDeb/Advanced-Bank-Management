#include <bits/stdc++.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
using namespace std;
short int height = 28, width = 118, password_change_fake_try = 0; ////// height = 23 , width = 78 for windows 7
bool access_granted = false, have_record = true;
const double default_interest_rate = 10 / 100; // per year
// Just for modification of the database : CLIENTS_NUMBERS.TXT and EMPLOYERS_INDEX.TXT
// location of clients index		: "C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\CLIENTS_NUMBERS.TXT"
// location of indivisual client   	: "C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Clients_Record\\" + to_string(new_customer.get_account_number()) + ".txt
// location of employers index 		: "C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\EMPLOYERS_INDEX.TXT"
// location of indivisual  employer : "C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Employers_Record\\" + to_string(current_employee.get_employers_number()) + ".txt"
string date_time_function()
{
	time_t rawtime;
	struct tm *timeinfo;
	char buffer[100];
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 100, "%X , %a , %B %d,%Y", timeinfo);
	return buffer;
	/*%a	Abbreviated weekday name *	Thu
	%A	Full weekday name *	Thursday
	%b	Abbreviated month name *	Aug
	%B	Full month name *	August
	%c	Date and time representation *	Thu Aug 23 14:55:02 2001
	%C	Year divided by 100 and truncated to integer (00-99)	20
	%d	Day of the month, zero-padded (01-31)	23
	%D	Short MM/DD/YY date, equivalent to %m/%d/%y	08/23/01
	%e	Day of the month, space-padded ( 1-31)	2
	%F	Short YYYY-MM-DD date, equivalent to %Y-%m-%d	2001-08-23
	%g	Week-based year, last two digits (00-99)	01
	%G	Week-based year	2001
	%h	Abbreviated month name * (same as %b)	Aug
	%H	Hour in 24h format (00-23)	14
	%I	Hour in 12h format (01-12)	02
	%j	Day of the year (001-366)	235
	%m	Month as a decimal number (01-12)	08
	%M	Minute (00-59)	55
	%n	New-line character ('
	')
	%p	AM or PM designation	PM
	%r	12-hour clock time *	02:55:02 pm
	%R	24-hour HH:MM time, equivalent to %H:%M	14:55
	%S	Second (00-61)	02
	%t	Horizontal-tab character ('	')
	%T	ISO 8601 time format (HH:MM:SS), equivalent to %H:%M:%S	14:55:02
	%u	ISO 8601 weekday as number with Monday as 1 (1-7)	4
	%U	Week number with the first Sunday as the first day of week one (00-53)	33
	%V	ISO 8601 week number (01-53)	34
	%w	Weekday as a decimal number with Sunday as 0 (0-6)	4
	%W	Week number with the first Monday as the first day of week one (00-53)	34
	%x	Date representation *	08/23/01
	%X	Time representation *	14:55:02
	%y	Year, last two digits (00-99)	01
	%Y	Year	2001
	%z	ISO 8601 offset from UTC in timezone (1 minute=1, 1 hour=100)
	If timezone cannot be determined, no characters	+100
	%Z	Timezone name or abbreviation *
	If timezone cannot be determined, no characters	CDT
	%%	A % sign	%*/
}

struct transection
{
	double amount = INT_MAX;
	char message[500] = {};
	long long int acount_number = INT_MAX;
	char transection_time[100] = {};
};

void setcolor(int ForgC)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}

void gxy(short col, short row)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {col, row};
	SetConsoleCursorPosition(h, position);
}

void wait(int k)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf(" .");
		Sleep(k);
	}
}

void drawboard()
{
	time_t t;
	time(&t);
	int i, j;
	gxy(0, 0), printf("%c", 201);
	for (i = 0; i < width; i++)
		printf("%c", 205);
	printf("%c", 187);
	for (i = 0; i < height; i++)
	{
		gxy(0, i + 1), printf("%c", 186);
		gxy(width + 1, i + 1), printf("%c", 186);
	}
	gxy(0, height);
	for (i = 0; i < width + 2; i++)
	{
		if (i == 0)
			printf("%c", 200);
		else if (i == width + 1)
			printf("%c", 188);
		else
			printf("%c", 205);
	}
	gxy((width) / 4 + 5, height - 2), printf("Date : %s", ctime(&t)); // shows time
}

class customers
{
private:
	static long long int total_customers;

private:
	// variables:
	bool active_status = true;
	char name[50], address[20], phone_number[50], sex, password[50], city[50], province[50], country[50], account_create_date[100], last_account_modification_date[100];
	double checking_amount = 0, saving_amount = 0, visa_amount = 0, interest_rate, points = 0, loans = 0;
	long long int account_number = 100000000 + (rand() % 899999999), visa_number = 1000000000 + (rand() % 8999999999), account_creators_id = 0, employee_number = 0, last_modifier = 0;
	bool have_visa = 0, is_employee = false;
	short int birth_year, birth_month, birth_date, made_transection = 0;
	transection transfers[50];
	// functions:
public:
	// variables:

	// functions:

	// default constructor:
	customers()
	{
	}

	// constructor(s):
	customers(string user_name, string user_password, string user_address, string user_city, string user_province, string user_country, long long int account_creator_id, short int user_birth_date, short int user_birth_month, short int user_birth_year, char user_sex, string user_phone_number, double user_checking_amount = 0, double user_saving_amount = 0, double user_interest_rate = default_interest_rate)
	{
		total_customers++;
		set_every_thing_for_user(user_name, user_password, user_address, user_city, user_province, user_country, account_creator_id, user_birth_date, user_birth_month, user_birth_year, user_sex, user_phone_number, user_checking_amount, user_saving_amount, user_interest_rate);
	}

	customers(long long int account_creator)
	{
		total_customers++;
		account_creators_id = account_creator;
	}

	// copy constructors:
	/*customers(const customers &object)
	{

		return *this;
	}*/

	// destructor:
	~customers()
	{
	}
	// setters:
	void set_user_password(string new_password)
	{
		strcpy(password, new_password.c_str());
	}
	void set_user_name(string user_name)
	{
		strcpy(name, user_name.c_str());
	}
	void set_user_address(string user_address, string user_city, string user_province, string user_country)
	{
		strcpy(address, user_address.c_str());
		strcpy(city, user_city.c_str());
		strcpy(province, user_province.c_str());
		strcpy(country, user_country.c_str());
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
		if (have_visa)
		{
			visa_amount = user_visa_amount;
		}
		else
		{
			printf("\aSorry. The user don't have any visa card right now.");
		}
	}
	void set_user_birth_date(short int user_birth_date, short int user_birth_month, short int user_birth_year)
	{
		birth_date = user_birth_date;
		birth_month = user_birth_month;
		birth_year = user_birth_year;
	}
	void set_every_thing_for_user(string user_name, string user_password, string user_address, string user_city, string user_province, string user_country, long long int account_creator_id, short int user_birth_date, short int user_birth_month, short int user_birth_year, char user_sex, string user_phone_number, double user_checking_amount = 0, double user_saving_amount = 0, double user_interest_rate = default_interest_rate)
	{
		set_user_name(user_name);
		set_user_address(user_address, user_city, user_province, user_country);
		set_user_password(user_password);
		set_user_checking_amount(user_checking_amount);
		set_user_saving_amount(user_saving_amount);
		visa_amount = 0;
		set_user_interest_rate(user_interest_rate);
		account_creators_id = account_creator_id;
		set_user_birth_date(user_birth_date, user_birth_month, user_birth_year);
		sex = user_sex;
		set_users_phone_number(user_phone_number);
	}
	void set_users_phone_number(string user_phone_number)
	{
		strcpy(phone_number, user_phone_number.c_str());
	}
	void set_user_account_creation_date()
	{
		strcpy(account_create_date, date_time_function().c_str());
	}
	void set_account_modification_date()
	{
		strcpy(last_account_modification_date, date_time_function().c_str());
	}
	void enable_account_status()
	{
		active_status = true;
	}
	void disable_account_status()
	{
		active_status = false;
	}
	// getters:
	void print_everything()
	{
		cout << "Name: " << setw(20) << name << " ;ACC number: " << account_number << " ;interest_rate: " << setw(3) << interest_rate << " ;last modified by: " << last_modifier << "; is manager :" << is_employee << '\n';
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
		if (have_visa)
		{
			return visa_number;
		}
		else
		{
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
	string get_address()
	{
		return address;
	}
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
	// others:
	void request_for_visa(long long int last_modifier_id)
	{
		have_visa = true;
		last_modifier = last_modifier_id;
	}
	void create_new_account_number()
	{
		account_number = 100000000 + (rand() % 899999999) + 3;
	}
	void modify_account(long long int modifiers_id, string user_name, string user_address, string user_city, string user_province, string user_country, double user_interest_rate, short int user_birth_date, short int user_birth_month, short int user_birth_year, char user_sex, string user_phone_number, bool user_is_employee_of_the_bank, long long int user_employee_number)
	{
		set_every_thing_for_user(user_name, password, user_address, user_city, user_province, user_country, account_creators_id, user_birth_date, user_birth_month, user_birth_year, user_sex, user_phone_number, checking_amount, saving_amount, interest_rate);
		last_modified_by(modifiers_id);
	}
	void last_modified_by(long long int employee_id)
	{
		last_modifier = employee_id;
	}
	void print_every_details_for_customer()
	{
		gxy(5, 1), cout << "account number:			" << account_number;
		gxy(5, 2), cout << "Name:				" << name;
		gxy(5, 3), cout << "Address:				" << address << ", " << city << ", " << province << ", " << country;
		gxy(5, 4), cout << "Phone Number:			" << phone_number;
		gxy(5, 5), cout << "Sex:				" << sex;
		gxy(5, 6), cout << "Birh Date:				" << birth_date << "\\" << birth_month << "\\" << birth_year;
		gxy(5, 7), cout << "Checking Amount:			" << checking_amount;
		gxy(5, 8), cout << "Saving Amount:			" << saving_amount;
		if (have_visa)
		{
			gxy(5, 9), cout << "Visa Amount:	" << visa_amount;
		}
		else
		{
			gxy(5, 9), cout << "No Visa for this account";
		}
		gxy(5, 10), cout << "interest rate:			" << interest_rate;
		gxy(5, 11), cout << "account created by:		" << account_creators_id;
		if (is_employee)
		{
			gxy(5, 12), cout << "Employee number:	" << employee_number;
		}
		else
		{
			gxy(5, 12), cout << "Not an bank employee";
		}
		gxy(5, 13), cout << "Last modified by:			" << last_modifier;
		gxy(5, 14), cout << "Made_transections:			" << made_transection;
		gxy(5, 15), cout << "Account created on:		" << account_create_date;
		gxy(5, 16), cout << "Last modified on:			" << last_account_modification_date;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////new
	// getters
	// friend functions:
	// deposits
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
	static long long int total_employers;

private:
	// variables:
	char name[50], address[20], password[50], phone_number[50], sex, city[50], province[20], country[50], account_create_date[100];
	long long int employee_number = 1000000 + (rand() % 8999999), income_per_week;
	bool is_manager = false;
	long int accounts_created = 0;
	short int birth_date, birth_month, birth_year;
	// functions:
public:
	// variables:

	// functions:

	// default constructor:
	bank_employee()
	{
		total_employers++;
	}
	bank_employee(string employee_name, string employee_phone, string employee_password, string employee_address, string employee_city, string employee_province, string employee_country, char employee_sex, long long int employee_income_per_week, short int emplyoee_birth_date, short int employee_birth_month, short int employee_birth_year, bool is_employee_manager = false)
	{
		total_employers++;
		set_everything(employee_name, employee_phone, employee_password, employee_address, employee_city, employee_province, employee_country, employee_sex, employee_income_per_week, emplyoee_birth_date, employee_birth_month, employee_birth_year, is_employee_manager);
	}
	// copy constructors:
	/*bank_employee(const bank_employee &object)
	{
		return *this;
	}*/
	// destructor:
	~bank_employee()
	{
	}
	// setters:
	void set_everything(string employee_name, string employee_phone, string employee_password, string employee_address, string employee_city, string employee_province, string employee_country, char employee_sex, long long int employee_income_per_week, short int emplyoee_birth_date, short int employee_birth_month, short int employee_birth_year, bool is_employee_manager = false)
	{
		strcpy(name, employee_name.c_str());
		strcpy(phone_number, employee_phone.c_str());
		strcpy(password, employee_password.c_str());
		strcpy(address, employee_address.c_str());
		strcpy(city, employee_city.c_str());
		strcpy(province, employee_province.c_str());
		strcpy(country, employee_country.c_str());
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
	void created_new_account(long long int client_id_number)
	{
		accounts_created++;
	}
	void set_account_create_date()
	{
		strcpy(account_create_date, date_time_function().c_str());
	}
	// getters:
	void print_every_thing()
	{
		cout << "name: " << name << " , phone: " << phone_number << " , employee_number : " << employee_number << " , is manager : " << is_manager;
	}
	long long int get_employers_number()
	{
		return employee_number;
	}
	string get_name()
	{
		return name;
	}
	bool check_is_manager()
	{
		return is_manager;
	}
	void show_full_details()
	{
		gxy(5, 1), cout << "Employer Number:			" << employee_number;
		gxy(5, 2), cout << "Name:				" << name;
		gxy(5, 3), cout << "Address:				" << address << ", " << city << ", " << province << ", " << country;
		gxy(5, 4), cout << "Phone Number:			" << phone_number;
		gxy(5, 5), cout << "Sex:				" << sex;
		gxy(5, 6), cout << "Birh Date:				" << birth_date << "\\" << birth_month << "\\" << birth_year;
		gxy(5, 7), cout << "Is Manager:			" << is_manager;
		gxy(5, 8), cout << "accounts created:			" << accounts_created;
		gxy(5, 9), cout << "Income per week:			" << income_per_week;
		gxy(5, 10), cout << "Account was created:		" << account_create_date;
	}
	long long int get_income_per_week()
	{
		return income_per_week;
	}
	string get_phone_number()
	{
		return phone_number;
	}
	string get_address()
	{
		return address;
	}
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
	int get_birthday()
	{
		return birth_date;
	}
	int get_birth_month()
	{
		return birth_month;
	}
	int get_birth_year()
	{
		return birth_year;
	}
	// other functions:
	void change_password(string new_password)
	{
		strcpy(password, new_password.c_str());
	}
	bool check_password(string employee_password)
	{
		return !strcasecmp(password, employee_password.c_str());
	}
};

long long int bank_employee::total_employers = 0;

bool check_password(string password)
{
	if (password.size() < 8)
	{
		return true;
	}
	bool is_alpha, is_didgit;
	is_alpha = is_didgit = false;
	for (int i = 0; password[i]; i++)
	{
		if (is_alpha == false)
		{
			is_alpha = isalpha(password[i]);
		}
		if (is_didgit == false)
		{
			is_didgit = isdigit(password[i]);
		}
	}
	if (is_alpha and is_didgit)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool check_in_others_numbers(long long int new_number, vector<long long int> existing_number)
{
	for (int i = 0; i < existing_number.size(); i++)
	{
		if (new_number == existing_number[i])
		{
			return true;
		}
	}
	return false;
}

bool check_full_numerical_expressions(string given_string)
{
	for (long long int i = 0; i < given_string[i]; i++)
	{
		if ((given_string[i] > '9' or given_string[i] < '0') and (given_string[i] != '-' or given_string[i] != '+'))
		{
			return false;
		}
	}
	return true;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////// 	ALL working function starts here

void create_new_customer(bank_employee current_employee)
{
	fflush(stdin);
	char choice, sex;
	bool check_employee = false;
	vector<customers> clients;
	vector<long long int> other_customers_bank_number;
	customers temp_customer, new_customer;
	string name, address, city, province, country, password, phone_number, temp;
	double checking_amount, saving_amount, interest_rate = default_interest_rate;
	long long int customer_employee_number, number, i;
	short int birth_date, birth_month, birth_year;
	fstream file_pointer, database_file_pointer;
	system("cls");
	system("Color F9");
	drawboard();
	file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\CLIENTS_NUMBERS.TXT", ios::in | ios::binary);
	while (!file_pointer.eof())
	{
		file_pointer >> number;
		if (count(other_customers_bank_number.begin(), other_customers_bank_number.end(), number))
		{
			break;
		}
		other_customers_bank_number.push_back(number);
	}
	file_pointer.close();
	fflush(stdin);
	gxy(2, 2), printf("Enter Customer name: "), getline(cin, name);
	while (name.size() == 0)
	{
		gxy(2, 2), printf("Enter Customer name(name cannot be empty): ");
		for (i = 0; i < name[i]; i++)
			printf(" ");
		for (i = 0; i < name[i]; i++)
			printf("\b");
		getline(cin, name);
	}
	gxy(2, 3), printf("Enter Customer address: "), getline(cin, address);
	gxy(2, 4), printf("Enter customer city: "), getline(cin, city);
	gxy(2, 5), printf("Enter customer province: "), getline(cin, province);
	gxy(2, 6), printf("Enter customer country: "), getline(cin, country);
	gxy(2, 7), printf("Enter Customer checking amount : "), cin >> temp;
	while (temp[0] == '-' or !check_full_numerical_expressions(temp))
	{
		gxy(2, 7), printf("Enter Customer checking amount(can not be less than 0): ");
		for (i = 0; i < temp[i]; i++)
			printf(" ");
		for (i = 0; i < temp[i]; i++)
			printf("\b");
		cin >> temp;
	}
	checking_amount = stoi(temp);
	gxy(2, 8), printf("Enter Customer saving amount: "), cin >> temp;
	while (temp[0] == '-' or !check_full_numerical_expressions(temp))
	{
		gxy(2, 8), printf("Enter Customer saving amount(can not be less than 0):");
		for (i = 0; i < temp[i]; i++)
			printf(" ");
		for (i = 0; i < temp[i]; i++)
			printf("\b");
		cin >> temp;
	}
	saving_amount = stoi(temp);
	gxy(2, 9), printf("Modify_interest_rate(Y/N): ");

	scanf("%c", &choice);
	if (choice == 'Y' or choice == 'y')
	{
		gxy(5, 10), printf("Enter Customer interest_rate: "), cin >> interest_rate;
	}
	gxy(2, 11), printf("Enter Customer birth date: "), cin >> temp;
	if (check_full_numerical_expressions(temp))
	{
		birth_date = stoi(temp);
	}
	while (!check_full_numerical_expressions(temp) or birth_date > 31 or birth_date < 1)
	{
		gxy(2, 11), printf("Enter Customer Birth Date(can not be less than 0 or greater than 31): ");
		for (i = 0; i < temp[i]; i++)
			printf(" ");
		for (i = 0; i < temp[i]; i++)
			printf("\b");
		cin >> temp;
		if (check_full_numerical_expressions(temp))
		{
			birth_date = stoi(temp);
		}
	}
	gxy(2, 12), printf("Enter user birth month: "), cin >> temp;
	if (check_full_numerical_expressions(temp))
	{
		birth_month = stoi(temp);
	}
	while (!check_full_numerical_expressions(temp) or birth_month > 12 or birth_date < 1)
	{
		gxy(2, 12), printf("Enter Customer Birth Month(can not be less than 0 or greater than 12): ");
		for (i = 0; i < temp[i]; i++)
			printf(" ");
		for (i = 0; i < temp[i]; i++)
			printf("\b");
		cin >> temp;
		if (check_full_numerical_expressions(temp))
		{
			birth_month = stoi(temp);
		}
	}
	gxy(2, 13), printf("Enter user birth year: "), cin >> temp;
	if (check_full_numerical_expressions(temp))
	{
		birth_year = stoi(temp);
	}
	while (!check_full_numerical_expressions(temp) or birth_year > 2022 or birth_year < 1910)
	{
		gxy(2, 13), printf("Enter Customer BirthYear(can not be imaginary): ");
		for (i = 0; i < temp[i]; i++)
			printf(" ");
		for (i = 0; i < temp[i]; i++)
			printf("\b");
		cin >> temp;
		if (check_full_numerical_expressions(temp))
		{
			birth_year = stoi(temp);
		}
	}
	gxy(2, 14), printf("Enter sex(M / F / T / O): ");
	scanf("%c", &sex);
	while (sex != 'M' and sex != 'm' and sex != 'F' and sex != 'f' and sex != 'T' and sex != 't' and sex != 'O' and sex != 'o')
	{
		gxy(2, 14), printf("\a	Enter sex(M / F / T / O): ");
		scanf("%c", &sex);
	}
	gxy(2, 15), printf("Is customer employee of the bank(0/1): ");
	cin >> check_employee;
	if (check_employee)
	{
		gxy(2, 16), printf("Employee Number: ");
		cin >> customer_employee_number;
	}
	fflush(stdin);
	gxy(2, 17), printf("Enter Phone number: ");
	getline(cin, phone_number);
	gxy(2, 18), printf("Enter password: ");
	getline(cin, password);
	while (check_password(password))
	{
		gxy(2, 18), printf("Enter password: ");
		for (i = 0; i < password[i]; i++)
			printf(" ");
		for (i = 0; i < password[i]; i++)
			printf("\b");
		fflush(stdin);
		getline(cin, password);
	}
	new_customer.set_every_thing_for_user(name, password, address, city, province, country, current_employee.get_employers_number(), birth_date, birth_month, birth_year, sex, phone_number, checking_amount, saving_amount, interest_rate);
	while (check_in_others_numbers(new_customer.get_account_number(), other_customers_bank_number))
	{
		new_customer.create_new_account_number();
	}
	new_customer.set_user_account_creation_date();
	current_employee.created_new_account(new_customer.get_account_number());
	system("cls");
	drawboard();
	gxy(5, 6);
	new_customer.print_every_details_for_customer();
	gxy(30, 25), printf(">>>>>>>>>>>>>>>>>>#########Account Number : 	"), cout << new_customer.get_account_number();
	file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\CLIENTS_NUMBERS.TXT", ios::app | ios::binary);
	file_pointer << '\n'
				 << new_customer.get_account_number();
	file_pointer.close();
	database_file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Clients_Record\\" + to_string(new_customer.get_account_number()) + ".txt", ios::out | ios::binary);
	database_file_pointer.write(reinterpret_cast<char *>(&new_customer), sizeof(new_customer));
	database_file_pointer.close();
	database_file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Employers_Record\\" + to_string(current_employee.get_employers_number()) + ".txt", ios::out | ios::binary);
	database_file_pointer.write(reinterpret_cast<char *>(&current_employee), sizeof(current_employee));
	database_file_pointer.close();
	gxy(5, 20), printf("Press any key to go to main menu again...\b");
	getch();
	gxy(5, 21), printf("Going to main menu");
	fflush(stdin);
	wait(200);
}

void change_employers_own_account_details(bank_employee current_employee)
{
	fflush(stdin);
	string given_password;
	system("cls");
	drawboard();
	gxy(10, 2), printf(">>>>>>>>>>>>>>	Password can not be changed here	<<<<<<<<<<<<<<<<<");
	gxy(5, 7), printf("Enter current password: ");
	cin >> given_password;
	if (current_employee.check_password(given_password))
	{
		fstream file_pointer;
		file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Employers_Record\\" + to_string(current_employee.get_employers_number()) + ".txt", ios::out | ios::binary);
		string name, address, password, phone_number, city, province, country, temp;
		char sex;
		long long int weekly_income, i;
		short int birth_date, birth_month, birth_year;
		system("cls");
		drawboard();
		gxy(5, 2), printf("Enter your name(default name = %s): ", current_employee.get_name().c_str()), getline(cin, name);
		while (name.size() == 0)
		{
			gxy(5, 2), printf("Enter Full name(Cannot be Empty):               \b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			for (i = 0; i < name[i]; i++)
				printf(" ");
			for (i = 0; i < name[i]; i++)
				printf("\b");
			getline(cin, name);
		}
		gxy(5, 3), printf("Enter employer phone_number(maximum 50 words)(default = %s): ", current_employee.get_phone_number().c_str());
		getline(cin, phone_number);
		while (phone_number.size() == 0 or isalpha(*phone_number.c_str()))
		{
			gxy(5, 3);
			for (i = 0; i < phone_number.size() + sizeof("Enter employer phone_number(maximum 50 words)(default =  ): "); i++)
				printf(" ");
			for (i = 0; i < phone_number.size() + sizeof("Enter employer phone_number(maximum 50 words)(default =  ): "); i++)
				printf("\b");
			gxy(5, 3), printf("Enter valid Phone number:");
			getline(cin, phone_number);
		}
		gxy(5, 4), printf("enter employer address(50 words maximum)(default = %s): ", current_employee.get_address().c_str());
		getline(cin, address);
		gxy(5, 5), printf("Enter employer city(maximum 20 words)(default = %s): ", current_employee.get_city().c_str());
		getline(cin, city);
		gxy(5, 6), printf("Enter employer province(maximum 20 words)(default = %s): ", current_employee.get_province().c_str());
		getline(cin, province);
		gxy(5, 7), printf("Enter employer country(maximum 50 words)(default = %s): ", current_employee.get_country().c_str());
		getline(cin, country);
		gxy(5, 8), printf("Enter employer sex(M/F/T/O): ");
		sex = getch();
		while (sex != 'M' and sex != 'm' and sex != 'F' and sex != 'f' and sex != 'T' and sex != 't' and sex != 'O' and sex != 'o')
		{
			gxy(5, 9), printf(">>>>>>>>\aEnter employer sex(M/F/T/O): ");
			sex = getch();
		}
		gxy(5, 10), printf("Enter employer birth date(int. only)(default = %d): ", current_employee.get_birthday());
		cin >> temp;
		if (!isalpha(*temp.c_str()))
		{
			birth_date = stoi(temp);
		}
		while (birth_date > 31 or birth_date < 1 or isalpha(*temp.c_str()))
		{
			gxy(5, 10), printf("Enter Employer Birthdate(can not be less than 1 and more than 31):");
			for (i = 0; i < temp[i]; i++)
				printf(" ");
			for (i = 0; i < temp[i]; i++)
				printf("\b");
			cin >> temp;
			if (!isalpha(*temp.c_str()))
				birth_date = stoi(temp);
		}
		gxy(5, 11), printf("Enter employer birth month(int. only)(default = %d): ", current_employee.get_birth_month());
		cin >> temp;
		if (!isalpha(*temp.c_str()))
		{
			birth_month = stoi(temp);
		}
		while (birth_month > 12 or birth_month < 1 or isalpha(*temp.c_str()))
		{
			gxy(5, 11), printf("Enter Employer Birthmonth(can not be less than 1 and more than 12): ");
			for (i = 0; i < temp[i]; i++)
				printf(" ");
			for (i = 0; i < temp[i]; i++)
				printf("\b");
			cin >> temp;
			if (!isalpha(*temp.c_str()))
				birth_month = stoi(temp);
		}
		gxy(5, 12), printf("Enter employer birth year(int. only)(default = %d): ", current_employee.get_birth_year());
		cin >> temp;
		if (!isalpha(*temp.c_str()))
		{
			birth_year = stoi(temp);
		}
		while (birth_year > 2022 or birth_year < 1910 or isalpha(*temp.c_str()))
		{
			gxy(5, 12), printf("Enter Employer Birth year(can not be imaginary):");
			for (i = 0; i < temp[i]; i++)
				printf(" ");
			for (i = 0; i < temp[i]; i++)
				printf("\b");
			cin >> temp;
			if (!isalpha(*temp.c_str()))
				birth_year = stoi(temp);
		}
		gxy(5, 13), printf("Enter your salary per week(default = %d) : ", current_employee.get_income_per_week());
		cin >> temp;
		while (!check_full_numerical_expressions(temp))
		{
			gxy(5, 13);
			for (i = 0; temp[i]; i++)
				printf(" ");
			for (i = 0; temp[i]; i++)
				printf("\b");
			printf("Enter your salary per week(default = %d) : ", current_employee.get_income_per_week());
		}
		current_employee.set_everything(name, phone_number, given_password, address, city, province, country, sex, weekly_income, birth_date, birth_month, birth_year, current_employee.check_is_manager());
		file_pointer.write(reinterpret_cast<char *>(&current_employee), sizeof(current_employee));
		file_pointer.close();
		gxy(5, 20), printf("Editing done...");
	}
	else
	{
		gxy(4, 10), printf("Password not matched...");
		wait(10);
	}
	gxy(6, 25), printf("Press any key to go to main menu");
	getch();
	wait(150);
}

void Disable_Customers_account(bank_employee current_employee)
{
	fflush(stdin);
	customers client;
	string temp;
	char surity = 'n';
	long long int account_number, tmp;
	fstream file_pointer, file_pointer_2;
	bool acc_find = 0;
	file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\CLIENTS_NUMBERS.TXT", ios::in | ios::binary);
	system("cls");
	system("Color 4F");
	drawboard();
	gxy(6, 4), printf("Enter the Account Number that you want to modify: ");
	cin >> temp;
	if (check_full_numerical_expressions(temp))
	{
		tmp = stoi(temp);
	}
	else
	{
		gxy(6, 4), printf("Enter Valid Account number without any alphabets: ");
	}
	while (!file_pointer.eof())
	{
		file_pointer >> account_number;
		if (tmp == account_number)
		{
			acc_find = true;
			file_pointer_2.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Clients_Record\\" + to_string(account_number) + ".txt", ios::in | ios::binary);
			file_pointer_2.read(reinterpret_cast<char *>(&client), sizeof(client));
			if (client.get_active_status())
			{
				gxy(15, 7), cout << "Are you sure to disable " << client.get_name() << "'s account?(y/n): ";
			}
			else
			{
				gxy(15, 7), cout << "Are you sure to enable " << client.get_name() << "'s account?(y/n): ";
			}
			surity = getch();

			if (surity == 'y' or surity == 'Y')
			{
				file_pointer_2.close();
				if (client.get_active_status())
				{
					client.disable_account_status();
				}
				else
				{
					client.enable_account_status();
				}
				client.last_modified_by(current_employee.get_employers_number());
				client.set_account_modification_date();
				file_pointer_2.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Clients_Record\\" + to_string(account_number) + ".txt", ios::out | ios::binary);
				file_pointer_2.write(reinterpret_cast<char *>(&client), sizeof(client));
				file_pointer_2.close();
			}
		}
	}
	if (acc_find)
	{
		if (client.get_active_status())
		{
			gxy(10, 12), printf("Enabled Successfully");
		}
		else
		{
			gxy(10, 12), printf("Disabled Successfully");
		}
		gxy(10, 14), printf("Press any key to go to main menu...\b");
		getch();
		wait(500);
	}
	else
	{
		gxy(10, 12), printf("Not found the target account");
		gxy(10, 14), printf("Want to search again? (Y/N)");
		char cho;
		cho = getch();
		if (cho == 'Y' || cho == 'y')
		{
			file_pointer.close();
			file_pointer_2.close();
			Disable_Customers_account(current_employee);
		}
	}
	file_pointer.close();
	file_pointer_2.close();
}

void deposit_into_customers_account(bank_employee current_employee)
{
	fflush(stdin);
	fstream file_pointer, file_pointer_2;
	customers client;
	string temp;
	long long int account_number, record_account_number, i;
	long double amount_to_deposit;
	file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\CLIENTS_NUMBERS.TXT", ios::in | ios::binary);
	bool found_account;
	system("cls");
	drawboard();
	gxy(4, 4), printf("Enter the clients account number : ");
	cin >> temp;
	if (check_full_numerical_expressions(temp))
	{
		account_number = stoi(temp);
	}
	else
	{
		gxy(4, 4), printf("Enter Valid Account number without any alphabets: ");
	}
	while (!file_pointer.eof())
	{
		file_pointer >> record_account_number;
		if (record_account_number == account_number)
		{
			found_account = true;
			file_pointer_2.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Clients_Record\\" + to_string(account_number) + ".txt", ios::in | ios::binary);
			file_pointer_2.read(reinterpret_cast<char *>(&client), sizeof(client));
			gxy(4, 6), printf("[1] deposit into checking");
			gxy(4, 8), printf("[2] deposit into saving");
			gxy(4, 10), printf("Enter selection(1/2): ");
			char ch;
		select_again:
			ch = getch();
		again_deposit:
			gxy(4, 12), printf("Enter amount to deposit into");
			if (ch == '1')
			{
				printf(" checking:                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			}
			else if (ch == '2')
			{
				printf(" saving:                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			}
			else
			{
				gxy(4, 12), printf("                                        \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bWrong Keyword. Going to selection again.");
				wait(300);
				gxy(1, 12), printf("                                                                                \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
				gxy(4, 10), printf("Enter selection(1/2):    \b\b\b");
				goto select_again;
			}
			cin >> temp;
			if (check_full_numerical_expressions(temp))
			{
				amount_to_deposit = stoi(temp);
			}
			else
			{
				gxy(4, 12);
				for (i = 0; i < (temp.size() + sizeof("Enter amount to deposit into ") + 6 + (ch == 1) * 2); i++)
					printf(" ");
				for (i = 0; i < (temp.size() + sizeof("Enter amount to deposit into ") + 6 + (ch == 1) * 2); i++)
					printf("\b");
				goto again_deposit;
			}
			if (amount_to_deposit < 0)
			{
				gxy(6, 13), printf("Are you sure you want to deduct money from the account?(y/n) : ");
				char desition;
				cin >> desition;
				if (desition == 'n' or desition == 'N')
				{
					gxy(6, 13);
					for (int i = 0; i < sizeof("Are you sure you want to deduct money from the account?(y/n) : "); i++)
						printf(" ");
					for (int i = 0; i < sizeof("Are you sure you want to deduct money from the account?(y/n) : "); i++)
						printf("\b");
					goto again_deposit;
				}
			}
			if (ch == '1')
			{
				client.deposit_into_checking(amount_to_deposit);
				gxy(4, 14), printf("Diposited succcessfully in to checking account new balance : ");
				cout << client.get_checking_amount();
			}
			else
			{
				client.deposit_into_saving(amount_to_deposit);
				gxy(3, 14), printf("Diposited succcessfully in to saving account new balance : ");
				cout << client.get_saving_amount();
			}
			client.last_modified_by(current_employee.get_employers_number());
			file_pointer_2.close();
			file_pointer_2.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Clients_Record\\" + to_string(account_number) + ".txt", ios::out | ios::binary);
			file_pointer_2.write(reinterpret_cast<char *>(&client), sizeof(client));
			file_pointer_2.close();
			break;
		}
	}
	if (found_account == false)
	{
		gxy(4, 10), printf("No Accounts found...");
	}
	gxy(10, 16), printf("Press any key to go to main menu...\b");
	getch();
	wait(500);
}

void Modify_customers_account(bank_employee current_emplyoee)
{
	fflush(stdin);
	fstream file_pointer, file_pointer_2;
	file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\CLIENTS_NUMBERS.TXT", ios::in | ios::binary);
	char surity = 'n';
	long long int account_number = 0, tmp, i;
	bool acc_find = false;
	string temp;
	system("cls");
	system("Color E0");
	drawboard();
	gxy(6, 4), printf("Enter the Account Number that you want to modify: ");
	cin >> temp;
	if (check_full_numerical_expressions(temp))
	{
		tmp = stoi(temp);
	}
	else
	{
		gxy(6, 4), printf("Enter Valid Account number without any alphabets: ");
	}
	while (!file_pointer.eof())
	{
		file_pointer >> account_number;
		if (account_number == tmp)
		{
			acc_find = true;
			customers client;
			file_pointer_2.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Clients_Record\\" + to_string(account_number) + ".txt", ios::in | ios::binary);
			file_pointer_2.read(reinterpret_cast<char *>(&client), sizeof(client));
			gxy(15, 7), cout << "Are you sure to modify " << client.get_name() << "'s account?(y/n): ";
			surity = getch();
			if (surity == 'Y' or surity == 'y')
			{
				string name, address, city, province, country, phone_number;
				char choice, sex;
				double interest_rate;
				short int birth_date, birth_month, birth_year;
				bool check_employee = 0;
				long long int customer_employee_number;
				system("cls");
				drawboard();
				gxy(2, 2), printf("Enter Client name(default name = %s): ", client.get_name().c_str()), getline(cin, name);
				while (name.size() == 0)
				{
					gxy(2, 2), printf("Enter Customer name(name cannot be empty):         \b\b\b\b\b\b\b\b"), getline(cin, name);
				}
				gxy(2, 3), printf("Enter Customer address(default : %s): ", client.get_address().c_str()), getline(cin, address);
				gxy(2, 4), printf("Enter customer city(default : %s): ", client.get_city().c_str()), getline(cin, city);
				gxy(2, 5), printf("Enter customer province(default : %s): ", client.get_province().c_str()), getline(cin, province);
				gxy(2, 6), printf("Enter customer country(default : %s): ", client.get_country().c_str()), getline(cin, country);
				gxy(2, 7), printf("Modify_interest_rate(Y/N): ");
				scanf("%c", &choice);
				if (choice == 'Y' or choice == 'y')
				{
					gxy(2, 8), printf("Enter Customer interest_rate: "), cin >> interest_rate;
				}
				gxy(2, 9), printf("Enter Customer birth date: "), cin >> temp;
				if (check_full_numerical_expressions(temp))
				{
					birth_date = stoi(temp);
				}
				while (!check_full_numerical_expressions(temp) or birth_date > 31 or birth_date < 1)
				{
					gxy(2, 9), printf("Enter Customer Birth Date(can not be less than 0 or greater than 31): ");
					for (i = 0; i < temp[i]; i++)
						printf(" ");
					for (i = 0; i < temp[i]; i++)
						printf("\b");
					cin >> temp;
					if (check_full_numerical_expressions(temp))
					{
						birth_date = stoi(temp);
					}
				}
				gxy(2, 10), printf("Enter user birth month: "), cin >> temp;
				if (check_full_numerical_expressions(temp))
				{
					birth_month = stoi(temp);
				}
				while (!check_full_numerical_expressions(temp) or birth_month > 12 or birth_date < 1)
				{
					gxy(2, 10), printf("Enter Customer Birth Month(can not be less than 0 or greater than 12): ");
					for (i = 0; i < temp[i]; i++)
						printf(" ");
					for (i = 0; i < temp[i]; i++)
						printf("\b");
					cin >> temp;
					if (check_full_numerical_expressions(temp))
					{
						birth_month = stoi(temp);
					}
				}
				gxy(2, 11), printf("Enter user birth year: "), cin >> temp;
				if (check_full_numerical_expressions(temp))
				{
					birth_year = stoi(temp);
				}
				while (!check_full_numerical_expressions(temp) or birth_year > 2022 or birth_year < 1910)
				{
					gxy(2, 11), printf("Enter Customer BirthYear(can not be imaginary): ");
					for (i = 0; i < temp[i]; i++)
						printf(" ");
					for (i = 0; i < temp[i]; i++)
						printf("\b");
					cin >> temp;
					if (check_full_numerical_expressions(temp))
					{
						birth_year = stoi(temp);
					}
				}
				gxy(2, 12), printf("Enter sex(M / F / T / O): ");

				scanf("%c", &sex);
				while (sex != 'M' and sex != 'm' and sex != 'F' and sex != 'f' and sex != 'T' and sex != 't' and sex != 'O' and sex != 'o')
				{
					gxy(2, 13), printf("\a	Enter sex(M / F / T / O): ");
					scanf("%c", &sex);
				}

				gxy(2, 14), printf("Enter Customers Phone Number: ");
				getline(cin, phone_number);
				gxy(2, 15), printf("Is customer employee of the bank(0/1): ");
				cin >> check_employee;
				if (check_employee)
				{
					gxy(2, 16), printf("Employee Number: ");
					cin >> customer_employee_number;
				}
				client.modify_account(current_emplyoee.get_employers_number(), name, address, city, province, country, interest_rate, birth_date, birth_month, birth_year, sex, phone_number, check_employee, customer_employee_number);
				client.last_modified_by(current_emplyoee.get_employers_number());
				client.set_account_modification_date();
				file_pointer_2.close();
				file_pointer_2.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Clients_Record\\" + to_string(account_number) + ".txt", ios::out | ios::binary);
				file_pointer_2.write(reinterpret_cast<char *>(&client), sizeof(client));
			}
		}
	}
	system("cls");
	drawboard();
	if (acc_find)
	{
		if (surity == 'y' or surity == 'Y')
		{
			gxy(10, 12), printf("modified the target account");
		}
		gxy(10, 14), printf("Press any key to go to main menu...\b");
		getch();
		wait(500);
	}
	else
	{
		gxy(10, 12), printf("Not found the target account");
		gxy(10, 14), printf("Want to search again? (Y/N)");
		char cho;
		cho = getch();
		if (cho == 'Y' || cho == 'y')
		{
			file_pointer.close();
			file_pointer_2.close();
			Disable_Customers_account(current_emplyoee);
		}
	}
	file_pointer_2.close();
	file_pointer.close();
}

void show_full_account_details()
{
	long long int temp_number, i, account_number;
	bool found_customer = false;
	system("cls");
	drawboard();
	gxy(6, 4), printf("Enter the account number to show full info of the account: ");
	cin >> temp_number;
	fstream file_pointer;
	file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\CLIENTS_NUMBERS.TXT", ios::in | ios::binary);
	gxy(6, 7), printf("Searching");
	while (!file_pointer.eof())
	{
		file_pointer >> account_number;
		if (account_number == temp_number)
		{
			found_customer = true;
			system("cls");
			drawboard();
			customers client;
			file_pointer.close();
			file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Clients_Record\\" + to_string(account_number) + ".txt", ios::in | ios::binary);
			file_pointer.read(reinterpret_cast<char *>(&client), sizeof(client));
			client.print_every_details_for_customer();
			break;
		}
		else if (found_customer == false)
		{
			printf(". ");
		}
	}
	file_pointer.close();
	if (found_customer == false)
	{
		gxy(6, 10), printf("No account found with this number");
	}
	gxy(5, 20);
	printf("Press any key to go to main menu again...\b");
	getch();
	gxy(5, 21);
	printf("Going to main menu");
	wait(100);
}

void read_all_clients()
{
	long long int temp_number, i, j;
	vector<long long int> clients_numbers;
	customers temp_customer;
	fstream file_pointer, data_base_file_pointer;
	file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\CLIENTS_NUMBERS.TXT", ios::in | ios::binary);
	while (!file_pointer.eof())
	{
		file_pointer >> temp_number;
		if (count(clients_numbers.begin(), clients_numbers.end(), temp_number))
		{
			break;
		}
		clients_numbers.push_back(temp_number);
	}
	file_pointer.close();
	sort(clients_numbers.begin(), clients_numbers.end()), clients_numbers.erase(unique(clients_numbers.begin(), clients_numbers.end()), clients_numbers.end()); // Removes Duplicates...
	system("cls");
	system("Color 0E");
	drawboard();
	if (clients_numbers.size() == 0)
	{
		gxy(25, 15), printf("There is no client in your bank");
	}
	else
	{
		for (i = j = 0; i < clients_numbers.size(); i++, j++)
		{
			data_base_file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Clients_Record\\" + to_string(clients_numbers[i]) + ".txt", ios::in | ios::binary);
			if (data_base_file_pointer)
			{
				data_base_file_pointer.read((char *)&temp_customer, sizeof(temp_customer));
				if (temp_customer.get_active_status())
				{
					gxy(2, j + 1), temp_customer.print_everything();
				}
				else
				{
					gxy(2, j + 1), cout << "Account Number :" << clients_numbers[i] << "			Disabled on " << temp_customer.get_last_modification_date() << " by " << temp_customer.get_last_modifiers_number();
				}
				data_base_file_pointer.close();
			}
			else
			{
				gxy(2, i + 1), cout << "Account Number :" << clients_numbers[i] << "Not found !!!";
			}
			if (j == 18 and i < clients_numbers.size() - 1)
			{
				gxy(7, 22), printf("Press any key to show next clients...\b");
				getch();
				j = 0;
				system("cls");
				drawboard();
			}
		}
	}
	gxy(5, 22), printf("Press any key to go to main menu again...\b");
	getch();
	gxy(5, 23), printf("Going to main menu");
	wait(200);
}

void created_accounts_by_the_user(bank_employee current_employee)
{
	long long int i;
	vector<long long int> clients_numbers;
	fstream file_pointer, data_base_file_pointer;
	customers client;
	bool account_found = false;
	long long int temp_client_number;
	file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\CLIENTS_NUMBERS.TXT", ios::in);
	system("cls");
	drawboard();
	system("Color 0B");
	while (!file_pointer.eof())
	{
		file_pointer >> temp_client_number;
		if (count(clients_numbers.begin(), clients_numbers.end(), temp_client_number))
		{
			break;
		}
		clients_numbers.push_back(temp_client_number);
	}
	file_pointer.close();

	sort(clients_numbers.begin(), clients_numbers.end()), clients_numbers.erase(unique(clients_numbers.begin(), clients_numbers.end()), clients_numbers.end()); // Removes Duplicates...

	for (i = 0; clients_numbers.size() > i; i++)
	{
		data_base_file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Clients_Record\\" + to_string(clients_numbers[i]) + ".txt", ios::in | ios::binary);
		data_base_file_pointer.read((char *)&client, sizeof(client));
		if (current_employee.get_employers_number() == client.get_account_creators_id())
		{
			gxy(1, i + 1), client.print_everything();
			account_found = true;
		}
		data_base_file_pointer.close();
	}
	if (account_found == false)
	{
		gxy(25, 15), printf("There is no account that was created by you...");
	}
	gxy(5, 20), printf("Press any key to go to main menu again...\b");
	getch();
	gxy(5, 21), printf("Going to main menu");
	wait(200);
}

void change_employee_password(bank_employee current_employee)
{
	fflush(stdin);
	string given_password, temp;
	bank_employee temp_employer;
	long long int target_employee_index = 0, i;
	fstream file_pointer;
	file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Employers_Record\\" + to_string(current_employee.get_employers_number()) + ".txt", ios::in | ios::out | ios::binary);
	system("cls");
	drawboard();
	gxy(5, 7), printf("Enter current password: ");
	getline(cin, given_password);
	if (current_employee.check_password(given_password))
	{
		gxy(9, 9), printf("Enter new password: ");
		fflush(stdin);
		getline(cin, given_password);
		while (check_password(given_password))
		{
			gxy(9, 9), printf("Enter new password(Include numbers and letters): ");
			getline(cin, given_password);
		}
		fflush(stdin);
		gxy(9, 11), printf("Confirm Password: ");
		getline(cin, temp);
		if (temp == given_password)
		{
			current_employee.change_password(given_password);
			file_pointer.write(reinterpret_cast<char *>(&current_employee), sizeof(current_employee));
			file_pointer.close();
			gxy(5, 15), printf("Changed Password Succesfully");
		}
		else
		{
			gxy(5, 15), printf("Password Not matched. Can not change password");
		}
	}
	else
	{
		gxy(5, 9), printf("Password not matched. Cannot change password");
		if (password_change_fake_try > 2)
		{
			file_pointer.close();
			gxy(5, 17), printf("Too many fail tries. Logging out...\b");
			wait(300);
			exit(0);
		}
		else
		{
			password_change_fake_try++;
		}
	}
	gxy(5, 20), printf("Press any key to go to main menu again...\b");
	getch();
	gxy(5, 21), printf("Going to main menu");
	wait(200);
	file_pointer.close();
}

void log_out(bank_employee);

void main_menu(bank_employee current_employee)
{
	char main_menu_choice;
main_menu_start2:
	system("Color F0");
	system("cls");
	drawboard();
	gxy(width / 2 - 30, 1), printf(">>>>>>>>>>>>>>>>>>>>>>	 Main Menu	<<<<<<<<<<<<<<<<<<<<<<<<<");
	gxy(width / 2 - 30, 3), printf("###################	    New Clients	    ###################");
	gxy(30, 4), printf("[0] create a client account");
	gxy(30, 5), printf("[1] show accounts");
	gxy(30, 6), printf("[2] modify an account");
	gxy(30, 7), printf("[3] Disable an account");
	gxy(30, 8), printf("[4] show full details of an account");
	gxy(30, 9), printf("[5] deposit money into an account");
	gxy(width / 2 - 30, 11), printf("###################	  your account  	###################");
	gxy(30, 13), printf("[6] Show your created accounts");
	gxy(30, 14), printf("[7] change your password");
	gxy(30, 15), printf("[8] change your account details");
	gxy(30, 16), printf("[9] log out");

	gxy(width / 2 - 10, 24), printf("Enter your selection..:  \b");
	main_menu_choice = getch();
	switch (main_menu_choice)
	{
	case '0':
	{
		create_new_customer(current_employee);
		break;
	}
	case '1':
	{
		read_all_clients();
		break;
	}
	case '2':
	{
		Modify_customers_account(current_employee);
		break;
	}
	case '3':
	{
		Disable_Customers_account(current_employee);
		break;
	}
	case '4':
	{
		show_full_account_details();
		break;
	}
	case '5':
	{
		deposit_into_customers_account(current_employee);
		break;
	}
	case '6':
	{
		created_accounts_by_the_user(current_employee);
		break;
	}
	case '7':
	{
		change_employee_password(current_employee);
		break;
	}
	case '8':
	{
		change_employers_own_account_details(current_employee);
		break;
	}
	case '9':
	{
		log_out(current_employee);
		break;
	}
	default:
	{
		gxy(width / 2 - 10, 24), printf("Invalid Selection:  ");
		wait(500);
		break;
	}
	}
	goto main_menu_start2;
}

void read_all_employees()
{
	bank_employee temp_employer;
	long long int number, i, j;
	vector<long long int> employee_numbers;
	fstream file_pointer, database_file_pointer;
	file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\EMPLOYERS_INDEX.TXT", ios::in | ios::binary);
	while (!file_pointer.eof())
	{
		file_pointer >> number;
		if (count(employee_numbers.begin(), employee_numbers.end(), number))
		{
			break;
		}
		employee_numbers.push_back(number);
	}
	file_pointer.close();
	system("cls");
	drawboard();
	for (i = j = 0; i < employee_numbers.size(); i++, j++)
	{
		number = employee_numbers[i];
		database_file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Employers_Record\\" + to_string(number) + ".txt", ios::in | ios::binary);
		database_file_pointer.read(reinterpret_cast<char *>(&temp_employer), sizeof(temp_employer));
		gxy(2, j + 1), temp_employer.print_every_thing();
		database_file_pointer.close();
		if (j == 18 and i < employee_numbers.size() - 1)
		{
			gxy(6, 22), printf("->->->->->->->->->->->->->-> Press any key to show next employers...\b");
			getch();
			j = 0;
			system("cls");
			drawboard();
		}
	}
	gxy(5, 22), printf("Press any key to go to main menu again...\b");
	getch();
	gxy(5, 23), printf("Going to main menu");
	wait(200);
}

void show_full_details_of_an_employee()
{
	fstream file_pointer;
	file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\EMPLOYERS_INDEX.TXT", ios::in | ios::binary);
	bank_employee employee;
	long long int employee_number, index_number, i;
	bool found_employee = false;
	string temp;
	system("cls");
	drawboard();
	gxy(6, 4), printf("Enter the account number to show full info of the account: ");
	cin >> temp;
	while (!check_full_numerical_expressions(temp))
	{
		gxy(6, 4), printf("Enter Valid Account number without any alphabets:                 \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		for (i = 0; temp[i]; i++)
			printf(" ");
		for (i = 0; temp[i]; i++)
			printf("\b");
		cin >> temp;
	}
	employee_number = stoi(temp);
	gxy(6, 7), printf("Searching");
	while (!file_pointer.eof())
	{
		file_pointer >> index_number;
		if (employee_number == index_number)
		{
			found_employee = true;
			fstream database_file_pointer;
			database_file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Employers_Record\\" + to_string(employee_number) + ".txt", ios::in | ios::binary);
			database_file_pointer.read(reinterpret_cast<char *>(&employee), sizeof(employee));
			database_file_pointer.close();
			system("cls");
			drawboard();
			employee.show_full_details();
			break;
		}
		else if (found_employee == false)
		{
			printf(". ");
		}
	}
	if (found_employee == false)
	{
		gxy(6, 10), printf("No account found with this number");
	}
	file_pointer.close();
	gxy(5, 20);
	printf("Press any key to go to main menu again...\b");
	getch();
	gxy(5, 21);
	printf("Going to main menu");
	wait(100);
}

void modify_an_employees_account()
{
	fflush(stdin);
	fstream file_pointer;
	file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\EMPLOYERS_INDEX.TXT", ios::in | ios::binary);
	bank_employee employee;
	long long int employee_number, index_number, i;
	bool found_employee = false;
	string temp;
	system("cls");
	system("Color E0");
	drawboard();
	gxy(6, 4), printf("Enter the account number to edit details: ");
	cin >> temp;
	while (!check_full_numerical_expressions(temp))
	{
		gxy(6, 4), printf("Enter Valid Account number without any alphabets:                 \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		for (i = 0; temp[i]; i++)
			printf(" ");
		for (i = 0; temp[i]; i++)
			printf("\b");
		cin >> temp;
	}
	employee_number = stoi(temp);
	gxy(6, 7), printf("Searching");
	while (!file_pointer.eof())
	{
		file_pointer >> index_number;
		if (employee_number == index_number)
		{
			found_employee = true;
			string given_password;
			gxy(5, 10), printf("Enter employer password: ");
			cin >> given_password;
			fstream database_file_pointer;
			database_file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Employers_Record\\" + to_string(employee_number) + ".txt", ios::in | ios::binary);
			database_file_pointer.read((char *)&employee, sizeof(employee));
			database_file_pointer.close();
			if (employee.check_password(given_password))
			{
				fflush(stdin);
				string name, address, password, phone_number, city, province, country, temp;
				char sex;
				long long int weekly_income;
				short int birth_date, birth_month, birth_year;
				bool is_manager = 0;
				system("cls");
				drawboard();
				gxy(5, 2), printf("Enter your name(default name = %s): ", employee.get_name().c_str()), getline(cin, name);
				while (name.size() == 0)
				{
					gxy(5, 2), printf("Enter Full name(Cannot be Empty):               \b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					for (i = 0; i < name[i]; i++)
						printf(" ");
					for (i = 0; i < name[i]; i++)
						printf("\b");
					getline(cin, name);
				}
				gxy(5, 3), printf("Enter employer phone_number(maximum 50 words)(default = %s) : ", employee.get_phone_number().c_str());
				getline(cin, phone_number);
				while (phone_number.size() == 0 or isalpha(*phone_number.c_str()))
				{
					gxy(5, 3);
					for (i = 0; i < phone_number.size() + sizeof("Enter employer phone_number(maximum 50 words)(default =  ): "); i++)
						printf(" ");
					for (i = 0; i < phone_number.size() + sizeof("Enter employer phone_number(maximum 50 words)(default =  ): "); i++)
						printf("\b");
					gxy(5, 3), printf("Enter valid Phone number:");
					getline(cin, phone_number);
				}
				gxy(5, 4), printf("enter employer address(50 words maximum)(default = %s): ", employee.get_address().c_str());
				getline(cin, address);
				gxy(5, 5), printf("Enter employer city(maximum 20 words)(default = %s): ", employee.get_city().c_str());
				getline(cin, city);
				gxy(5, 6), printf("Enter employer province(maximum 20 words)(default = %s): ", employee.get_province().c_str());
				getline(cin, province);
				gxy(5, 7), printf("Enter employer country(maximum 50 words)(default = %s): ", employee.get_country().c_str());
				getline(cin, country);
				gxy(5, 8), printf("Enter employer sex(M/F/T/O): ");
				sex = getch();
				while (sex != 'M' and sex != 'm' and sex != 'F' and sex != 'f' and sex != 'T' and sex != 't' and sex != 'O' and sex != 'o')
				{
					gxy(5, 9), printf(">>>>>>>>\aEnter employer sex(M/F/T/O): ");
					sex = getch();
				}
				gxy(5, 10), printf("Enter employer birth date(int. only)(default = %d): ", employee.get_birthday());
				cin >> temp;
				if (!isalpha(*temp.c_str()))
				{
					birth_date = stoi(temp);
				}
				while (birth_date > 31 or birth_date < 1 or isalpha(*temp.c_str()))
				{
					gxy(5, 10), printf("Enter Employer Birth date(can not be less than 1 and more than 31): ");
					for (i = 0; i < temp[i]; i++)
						printf(" ");
					for (i = 0; i < temp[i]; i++)
						printf("\b");
					cin >> temp;
					if (!isalpha(*temp.c_str()))
						birth_date = stoi(temp);
				}
				gxy(5, 11), printf("Enter employer birth month(int. only)(default = %d): ", employee.get_birth_month());
				cin >> temp;
				if (!isalpha(*temp.c_str()))
				{
					birth_month = stoi(temp);
				}
				while (birth_month > 12 or birth_month < 1 or isalpha(*temp.c_str()))
				{
					gxy(5, 11), printf("Enter Employer Birth month(can not be less than 1 and more than 12): ");
					for (i = 0; i < temp[i]; i++)
						printf(" ");
					for (i = 0; i < temp[i]; i++)
						printf("\b");
					cin >> temp;
					if (!isalpha(*temp.c_str()))
						birth_month = stoi(temp);
				}
				gxy(5, 12), printf("Enter employer birth year(int. only)(default = %d): ", employee.get_birth_year());
				cin >> temp;
				if (!isalpha(*temp.c_str()))
				{
					birth_year = stoi(temp);
				}
				while (birth_year > 2022 or birth_year < 1910 or isalpha(*temp.c_str()))
				{
					gxy(5, 12), printf("Enter Employer Birth year(can not be imaginary):");
					for (i = 0; i < temp[i]; i++)
						printf(" ");
					for (i = 0; i < temp[i]; i++)
						printf("\b");
					cin >> temp;
					if (!isalpha(*temp.c_str()))
						birth_year = stoi(temp);
				}
				gxy(5, 13), printf("Enter your salary per week(default = %d) : ", employee.get_income_per_week());
				cin >> temp;
				while (!check_full_numerical_expressions(temp))
				{
					gxy(5, 13);
					for (i = 0; temp[i]; i++)
						printf(" ");
					for (i = 0; temp[i]; i++)
						printf("\b");
					printf("Enter your salary per week(default = %d) : ", employee.get_income_per_week());
				}
				gxy(5, 14), printf("Is manager(0/1): "), cin >> is_manager;
				employee.set_everything(name, phone_number, given_password, address, city, province, country, sex, weekly_income, birth_date, birth_month, birth_year, is_manager);
				database_file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Employers_Record\\" + to_string(employee.get_employers_number()) + ".txt", ios::out | ios::binary);
				database_file_pointer.write((char *)&employee, sizeof(employee));
				database_file_pointer.close();
			}
			else
			{
				gxy(6, 11), printf("Password not matched");
				wait(199);
			}
			break;
		}
		else if (found_employee == false)
		{
			printf(". ");
		}
	}
	if (found_employee == false)
	{
		gxy(6, 10), printf("No account found with this number");
	}
	file_pointer.close();
	gxy(5, 20);
	printf("Press any key to go to main menu again...\b");
	getch();
	gxy(5, 21);
	printf("Going to main menu");
	wait(100);
}

void delete_an_employee()
{
	fstream file_pointer, data_base_file_pointer;
	file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\EMPLOYERS_INDEX.TXT", ios::in | ios::binary);
	bank_employee employee;
	long long int employee_number, index_number, i;
	bool found_employee = false;
	vector<long long int> to_be_saved_employee_numbers;
	string temp;
	system("cls");
	system("Color 4F");
	drawboard();
	gxy(6, 4), printf("Enter the account number to delete: ");
	cin >> temp;
	while (!check_full_numerical_expressions(temp))
	{
		gxy(6, 4), printf("Enter Valid Account number without any alphabets:                 \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		for (i = 0; temp[i]; i++)
			printf(" ");
		for (i = 0; temp[i]; i++)
			printf("\b");
		cin >> temp;
	}
	employee_number = stoi(temp);
	gxy(6, 7), printf("Searching");
	while (!file_pointer.eof())
	{
		file_pointer >> index_number;
		if (employee_number == index_number)
		{
			found_employee = true;
			string given_password;
			gxy(5, 10), printf("Enter employer password: ");
			data_base_file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Employers_Record\\" + to_string(employee_number) + ".txt", ios::in | ios::binary);
			data_base_file_pointer.read((char *)&employee, sizeof(employee));
			data_base_file_pointer.close();
			cin >> given_password;
			if (employee.check_password(given_password))
			{
				file_pointer.close();
				if (remove(("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Employers_Record\\" + to_string(employee_number) + ".txt").c_str()) == 0)
				{
					gxy(6, 12), printf("Account Removed Successfully");
				}
				else
				{
					gxy(6, 12), printf("Could not remove the account");
					to_be_saved_employee_numbers.push_back(index_number);
				}
			}
			else
			{
				gxy(6, 11), printf("Password not matched");
				wait(199);
				to_be_saved_employee_numbers.push_back(index_number);
			}
		}
		else if (found_employee == false)
		{
			printf(". ");
			to_be_saved_employee_numbers.push_back(index_number);
		}
	}
	file_pointer.close();
	if (found_employee == false)
	{
		gxy(6, 10), printf("No account found with this number");
	}
	else
	{
		file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\EMPLOYERS_INDEX.TXT", ios::out | ios::binary);
		for (i = 0; i < to_be_saved_employee_numbers.size(); i++)
		{
			file_pointer << to_be_saved_employee_numbers[i] << '\n';
		}
		file_pointer.close();
	}
	file_pointer.close();
	gxy(5, 20);
	printf("Press any key to go to main menu again...\b");
	getch();
	gxy(5, 21);
	printf("Going to main menu");
	wait(100);
}

void create_employee()
{
	fflush(stdin);
	vector<long long int> others_numbers;
	bank_employee temp_employer, new_employer;
	string name, address, password, phone_number, city, province, country, temp;
	char sex;
	long long int employers_numbers_from_index = 1, weekly_income, i;
	short int birth_date, birth_month, birth_year;
	bool is_manager = false;
	fstream index_file_pointer, database_file_pointer;
	index_file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\EMPLOYERS_INDEX.TXT", ios::in | ios::binary);
	have_record = bool(index_file_pointer);
	if (have_record)
	{
		while (!index_file_pointer.eof())
		{ // replace with better idea
			index_file_pointer >> employers_numbers_from_index;
			others_numbers.push_back(employers_numbers_from_index);
		}
	}
	if (have_record)
	{
	}
	else
	{
		is_manager = true;
	}
	system("cls");
	drawboard();
	gxy(5, 2), printf("Enter employer full name(50 words maximum): ");
	getline(cin, name);
	while (name.size() == 0)
	{
		gxy(5, 2), printf("Enter Full name(Cannot be Empty):               \b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		for (i = 0; i < name[i]; i++)
			printf(" ");
		for (i = 0; i < name[i]; i++)
			printf("\b");
		getline(cin, name);
	}
	gxy(5, 3), printf("Enter employer phone_number(maximum 50 words) : ");
	getline(cin, phone_number);
	while (phone_number.size() == 0 or isalpha(*phone_number.c_str()))
	{
		gxy(5, 3);
		for (i = 0; i < phone_number.size() + sizeof("Enter employer phone_number(maximum 50 words)(default =  ): "); i++)
			printf(" ");
		for (i = 0; i < phone_number.size() + sizeof("Enter employer phone_number(maximum 50 words)(default =  ): "); i++)
			printf("\b");
		gxy(5, 3), printf("Enter valid Phone number:");
		getline(cin, phone_number);
	}
	gxy(5, 4), printf("enter employer address(50 words maximum): ");
	getline(cin, address);
	gxy(5, 5), printf("Enter employer city(maximum 20 words): ");
	getline(cin, city);
	gxy(5, 6), printf("Enter employer province(maximum 20 words): ");
	getline(cin, province);
	gxy(5, 7), printf("Enter employer country(maximum 50 words): ");
	getline(cin, country);
	gxy(5, 8), printf("Enter employer sex(M/F/T/O): ");
	sex = getch();
	while (sex != 'M' and sex != 'm' and sex != 'F' and sex != 'f' and sex != 'T' and sex != 't' and sex != 'O' and sex != 'o')
	{
		gxy(5, 9), printf(">>>>>>>>\aEnter employer sex(M/F/T/O): ");
		sex = getch();
	}
	gxy(5, 10), printf("Enter employer birth date(int. only): ");
	cin >> temp;
	if (!isalpha(*temp.c_str()))
	{
		birth_date = stoi(temp);
	}
	while (birth_date > 31 or birth_date < 1 or isalpha(*temp.c_str()))
	{
		gxy(5, 10), printf("Enter Employer Birthdate(can not be less than 1 and more than 31):");
		for (i = 0; i < temp[i]; i++)
			printf(" ");
		for (i = 0; i < temp[i]; i++)
			printf("\b");
		cin >> temp;
		if (!isalpha(*temp.c_str()))
			birth_date = stoi(temp);
	}
	gxy(5, 11), printf("Enter employer birth month(int. only): ");
	cin >> temp;
	if (!isalpha(*temp.c_str()))
	{
		birth_month = stoi(temp);
	}
	while (birth_month > 12 or birth_month < 1 or isalpha(*temp.c_str()))
	{
		gxy(5, 11), printf("Enter Employer Birthmonth(can not be less than 1 and more than 12): ");
		for (i = 0; i < temp[i]; i++)
			printf(" ");
		for (i = 0; i < temp[i]; i++)
			printf("\b");
		cin >> temp;
		if (!isalpha(*temp.c_str()))
			birth_month = stoi(temp);
	}

	gxy(5, 12), printf("Enter employer birth year(int. only): ");
	cin >> temp;
	if (!isalpha(*temp.c_str()))
	{
		birth_year = stoi(temp);
	}
	while (birth_year > 2022 or birth_year < 1910 or isalpha(*temp.c_str()))
	{
		gxy(5, 12), printf("Enter Employer Birth year(can not be imaginary):");
		for (i = 0; i < temp[i]; i++)
			printf(" ");
		for (i = 0; i < temp[i]; i++)
			printf("\b");
		cin >> temp;
		if (!isalpha(*temp.c_str()))
			birth_year = stoi(temp);
	}
	gxy(5, 13), printf("Enter your salary per week: ");
	cin >> temp;
	while (!check_full_numerical_expressions(temp))
	{
		gxy(5, 13);
		for (i = 0; temp[i]; i++)
			printf(" ");
		for (i = 0; temp[i]; i++)
			printf("\b");
		printf("Enter your salary per week: ");
	}
	fflush(stdin);
	gxy(5, 14), printf("Enter password(password should be atleast 8 words and have numbers and alpphabets): ");
	getline(cin, password);
	while (check_password(password))
	{
		gxy(2, 15), printf("\b\b\a>>>>>>>>>>>>>>Enter password(password should be atleast 8 words and have numbers and alpphabets):                \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		getline(cin, password);
	}
	if (is_manager == false)
	{
		gxy(6, 16), printf("Is this employee a manager(1/0) : ");
		cin >> is_manager;
	}
	new_employer.set_everything(name, phone_number, password, address, city, province, country, sex, weekly_income, birth_date, birth_month, birth_year, is_manager);
	while (check_in_others_numbers(new_employer.get_employers_number(), others_numbers))
	{
		new_employer.set_new_employee_number();
	}
	new_employer.set_account_create_date();
	database_file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Employers_Record\\" + to_string(new_employer.get_employers_number()) + ".txt", ios::out | ios::binary);
	database_file_pointer.write(reinterpret_cast<char *>(&new_employer), sizeof(new_employer));
	database_file_pointer.close();
	index_file_pointer.close();
	index_file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\EMPLOYERS_INDEX.TXT", ios::app | ios::binary);
	index_file_pointer << '\n'
					   << new_employer.get_employers_number();
	index_file_pointer.close();
	system("cls");
	drawboard();
	new_employer.show_full_details();
	gxy(6, 16), printf(">>>>>>>>>>New employee id : %d", new_employer.get_employers_number());
	gxy(6, 17), printf("Press any key to go to main menu again...\b");
	getch();
	gxy(6, 18), printf("Going to main menu");
	wait(500);
	fflush(stdin);
}

void main_menu_for_managers(bank_employee current_employee)
{
	fflush(stdin);
	char main_menu_choice;
main_menu_start:
	system("cls");
	system("Color F0");
	drawboard();
	gxy(width / 2 - 30, 1), printf(">>>>>>>>>>>>>>>>>>>>>>	 Main Menu	<<<<<<<<<<<<<<<<<<<<<<<<<");
	gxy(width / 2 - 30, 3), printf("###################	    New Clients	    ###################");
	gxy(30, 4), printf("[0] create a client account");		   // done
	gxy(30, 5), printf("[1] show accounts");				   // done
	gxy(30, 6), printf("[2] modify an account");			   // done
	gxy(30, 7), printf("[3] Disable/Enable an account");	   // done
	gxy(30, 8), printf("[4] show full details of an account"); // done
	gxy(30, 9), printf("[5] deposit money into an account");   // done
	gxy(width / 2 - 30, 11), printf("###################	  your account  	###################");
	gxy(30, 13), printf("[6] Show your created accounts");	// done needs to be optimized
	gxy(30, 14), printf("[7] change your password");		// done
	gxy(30, 15), printf("[8] change your account details"); // done
	gxy(30, 16), printf("[9] log out");						// done
	gxy(width / 2 - 30, 17), printf("###################	  employers account	  ###################");
	gxy(30, 18), printf("[.] Show full details of an employer"); //
	gxy(30, 19), printf("[+] Add new employee.");				 // done
	gxy(30, 20), printf("[*] show all employee");				 // done
	gxy(30, 21), printf("[/] Modify Employers Account");		 //
	gxy(30, 22), printf("[-] Delete an employee");				 //
	gxy(width / 2 - 10, 24), printf("Enter your selection..:  \b");
	main_menu_choice = getch();
	switch (main_menu_choice)
	{
	case '0':
	{
		create_new_customer(current_employee);
		break;
	}
	case '1':
	{
		read_all_clients();
		break;
	}
	case '2':
	{
		Modify_customers_account(current_employee);
		break;
	}
	case '3':
	{
		Disable_Customers_account(current_employee);
		break;
	}
	case '4':
	{
		show_full_account_details();
		break;
	}
	case '5':
	{
		deposit_into_customers_account(current_employee);
		break;
	}
	case '6':
	{
		created_accounts_by_the_user(current_employee);
		break;
	}
	case '7':
	{
		change_employee_password(current_employee);
		break;
	}
	case '8':
	{
		change_employers_own_account_details(current_employee);
		break;
	}
	case '9':
	{
		log_out(current_employee);
		break;
	}
	case '+':
	{
		create_employee();
		break;
	}
	case '*':
	{
		read_all_employees();
		break;
	}
	case '.':
	{
		show_full_details_of_an_employee();
		break;
	}
	case '/':
	{
		modify_an_employees_account();
		break;
	}
	case '-':
	{
		delete_an_employee();
		break;
	}
	default:
	{
		gxy(width / 2 - 10, 24), printf("Invalid Selection:  ");
		wait(500);
		break;
	}
	}
	fflush(stdin);
	goto main_menu_start;
}

void log_in_screen()
{
	fflush(stdin);
	bank_employee employer;
	vector<long long int> employers_numbers;
	bank_employee temp_employer;
	long long int log_in_id, i;
	bool check_employee = false;
	fstream file_pointer;
	string log_in_password;
	log_in_password.clear();
	file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\EMPLOYERS_INDEX.TXT", ios::in | ios::binary);
	system("cls");
	system("Color 0A");
	drawboard();
	if (file_pointer)
	{
		while (!file_pointer.eof())
		{
			file_pointer >> i;
			if (count(employers_numbers.begin(), employers_numbers.end(), i))
			{
				break;
			}
			employers_numbers.push_back(i);
		}
		gxy(10, 14), printf("Type exit to exit from the program. Or enter log in id to log in.");
	}
	else
	{
		gxy(5, 10), printf("No manager found.Create a new id for the manager. Redirectig to manager account creator page...");
		getch();
		have_record = false;
		create_employee();
		file_pointer.close();
		file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\EMPLOYERS_INDEX.TXT", ios::in | ios::binary);
		while (!file_pointer.eof())
		{
			file_pointer >> i;
			if (count(employers_numbers.begin(), employers_numbers.end(), i))
			{
				break;
			}
			employers_numbers.push_back(i);
		}
		system("cls");
		drawboard();
	}
log_in_again:
	gxy(5, 5), printf("Enter id: ");
	cin >> log_in_password;
	if (log_in_password == "exit" or log_in_password == "EXIT" or log_in_password == "Exit")
	{
		gxy(5, 10), printf("Exiting from the program.");
		wait(190);
		exit(0);
	}
	if (check_full_numerical_expressions(log_in_password))
	{
		log_in_id = stoi(log_in_password);
		gxy(10, 14);
		for (i = 0; i < sizeof("Type exit to exit from the program. Or enter log in id to log in."); i++)
			printf(" ");
	}
	else
	{
		gxy(8, 5);
		for (i = 0; log_in_password[i] + 8; i++)
			printf(" ");
		for (i = 0; log_in_password[i] + 8; i++)
			printf("\b");
		for (i = 0; log_in_password[i]; i++)
			printf("\b");
		goto log_in_again;
	}
	for (i = 0; i < employers_numbers.size(); i++)
	{
		if (log_in_id == employers_numbers[i])
		{
			fstream database_file_pointer;
			database_file_pointer.open("C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Employers_Record\\" + to_string(log_in_id) + ".txt", ios::in | ios::binary);
			database_file_pointer.read(reinterpret_cast<char *>(&employer), sizeof(employer));
			database_file_pointer.close();
			check_employee = true;
			break;
		}
	}
	if (check_employee)
	{
		gxy(5, 8), printf("Enter Password: ");
		fflush(stdin);
		getline(cin, log_in_password);
		access_granted = employer.check_password(log_in_password);
	}
	else
	{
		gxy(5, 5), printf("No user found. going to log in screen again");
		wait(700);
		system("cls");
		drawboard();
		file_pointer.close();
		goto log_in_again;
	}
	if (access_granted)
	{
		gxy(width / 2 - 20, height / 2 + 5), printf("Welcome ");
		cout << employer.get_name();
		gxy(width / 2 - 10, height / 2 + 6);
		wait(100);
		gxy(10, height / 2 + 8), printf("Redirecting to main menu .");
		wait(250);
		file_pointer.close();
		if (employer.check_is_manager())
		{
			main_menu_for_managers(employer);
		}
		else
		{
			main_menu(employer);
		}
	}
	else
	{
		gxy(5, 8), printf("Wrong password. Going to log in screen again");
		wait(500);
		check_employee = false;
		system("cls");
		drawboard();
		file_pointer.close();
		goto log_in_again;
	}
}

void log_out(bank_employee current_employee)
{
	fflush(stdin);
	system("cls");
	system("Color E0");
	drawboard();
	char ch;
	gxy(10, 5);
	printf("Are you sure to log out?(Y/N):");
	ch = getch();
	if (ch != 'y' and ch != 'Y')
	{
		return;
	}
	gxy(10, 7);
	cout << current_employee.get_name() << " , loging out of your id";
	gxy(10, 16), printf("Going to log in screen ");
	wait(300);
	system("cls");
	log_in_screen();
	fflush(stdin);
}

int main()
{
	fflush(stdin);
	SetConsoleTitle("                                                                                                         		      Bank Management System");
	/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>							Should run from here                                             <<<<<<<<<<<<<<<<<<<<<<<<<<<*/
	const char *dir = "C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System";
	const char *dirname = "C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Clients_Record";
	const char *dirname_2 = "C:\\Users\\Public\\Documents\\TDsoftwares\\Advanced_Bank_Management_System\\Employers_Record";
	if (mkdir(dir) == -1)
	{
		if (errno != 17)
		{
			gxy(10, 6), printf("Mail teertha.deb579@gmail.com with the errorcode: ");
			cout << errno;
			getch();
		}
	}
	if (mkdir(dirname) == -1)
	{
		if (errno != 17)
		{
			gxy(10, 6), printf("Mail teertha.deb579@gmail.com with the errorcode: ");
			cout << errno;
			getch();
		}
	}
	if (mkdir(dirname_2) == -1)
	{
		if (errno != 17)
		{
			gxy(10, 6), printf("Mail teertha.deb579@gmail.com with the errorcode: ");
			cout << errno;
			getch();
		}
	}
	log_in_screen();
	return 0;
}
