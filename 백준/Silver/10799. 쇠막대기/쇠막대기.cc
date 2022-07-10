#include <bits/stdc++.h>

using namespace std;

int main(){
	int rslt=0, N=0;
	string str;
	cin >> str;
	for(int i=0;i<str.length();i++){
		if(str[i] == '('){
			if(str[i+1] == ')'){
				rslt += N;
				i++;
			}
			else{
				N++;
			}
		}
		else{
			N--;
			rslt++;
		}
	}
	cout << rslt;
}