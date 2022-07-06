#include <bits/stdc++.h>

using namespace std;

int main(){
	int day, cNum, rslt=0;
	cin >> day;
	for(int i=0;i<5;i++){
		cin >> cNum;
		if(cNum == day) rslt++;
	}
	cout << rslt;
}	