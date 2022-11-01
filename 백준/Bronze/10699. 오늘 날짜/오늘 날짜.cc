#include <bits/stdc++.h>
#include <ctime>

using namespace std;

int main(){
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);
	int year = 1900 + t->tm_year;
	int month = t->tm_mon + 1;
	int day = t->tm_mday;

	cout << year << "-";

	if(month < 10) cout << "0";
	cout << month << "-";

	if(day < 10) cout << "0";
	cout << day;
}