#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	int n = 0, len;

	cin >> str;
	len = str.length();
	
	function<bool(int, char, char)> check = [&](int idx, char a, char b){
		if(str[idx] == a && str[idx+1] == b) return 1;
		else return 0;
	};

	for(int i=0;i<len;i++){
		if(check(i,'d','z') && str[i+2] == '=') i+=2;
		else if(check(i,'c','=') || check(i,'c','-')) i+=1;
		else if(check(i,'d','-') || check(i,'l','j')) i+=1;
		else if(check(i,'n','j') || check(i,'s','=')) i+=1;
		else if(check(i,'z','=')) i+=1;
		n++;
	}

	cout << n;
}