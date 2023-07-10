#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include "transection.h"
using namespace std;

int main()
{
	SetConsoleTitle("    ");
	Time ttt1(1 , 2 , 3);
	Transection t1(522.22 , 123456789 , ttt1 , "Checking Account" , "Testing");

	t1.print_transection_details();

	printf("\n\n\nthat's the end of the program. press any key to exit...\n\n");
	getch();
	return 0;
}
