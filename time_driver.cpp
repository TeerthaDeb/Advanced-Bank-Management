#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include "time.h"

using namespace std;
int main()
{
	SetConsoleTitle("    ");

	Time t1(1 , 2 , 3);
	cout<<t1.to_String();
	Time t2(1 , 3 , 3);

	cout<<'\n'<<(t1 == t2);
    cout << sizeof(t1);
	printf("\n\n\nthat's the end of the program. press any key to exit...\n\n");
	getch();
	return 0;
}
