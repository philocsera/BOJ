#include <bits/stdc++.h>

using namespace std;

int main(){
	int X, len, back, cycle = 0;
	string str, temp, ori;

	cin >> X >> str;
	len = str.length();
	back = len - 1 - (len%2);
	ori = str;
	
	do{
		temp = "";	
		for(int i=0;i<len;i+=2) temp += str[i];
		for(int i=back;i>=0;i-=2) temp += str[i];
		str = temp;
		cycle++;
	}while(ori!=str);
	
	X %= cycle;

	while(X--){
		temp = "";	
		for(int i=0;i<len;i+=2) temp += str[i];
		for(int i=back;i>=0;i-=2) temp += str[i];
		str = temp;
	}

	cout << str;
}