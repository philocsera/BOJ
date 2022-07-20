#include <bits/stdc++.h>

using namespace std;

int len, jmp;
string s;

int boo(int now){
	if(now == len) return 0;

	char& br = s[now];
	int rslt, retn=0;
	jmp = now+1;

	if(br == '('){
		while(jmp!=len){
			rslt = boo(jmp);
			if(rslt == -3 || !rslt) return 0;
			else if(rslt == -2) break;
			else retn += rslt;
		}
		if(rslt != -2) return 0;
		if(retn) return retn*2;
		else return 2;
	}
	else if(br == '['){
		while(jmp!=len){
			rslt = boo(jmp);
			if(rslt == -2 || !rslt) return 0;
			else if(rslt == -3) break;
			else retn += rslt;
		}
		if(rslt != -3) return 0;
		if(retn) return retn*3;
		else return 3;

	}
	else if(br == ')'){
		return -2;
	}
	else if(br == ']'){
		return -3;
	}
	else{
		return 0;
	}
}

int main(){
	int rslt = 0, temp;
	cin >> s;
	len = s.length();

	while(jmp!=len){
		temp = boo(jmp);
		if(temp>0) rslt += temp;
		else{
			rslt = 0;
			break;
		}
	}
	cout << rslt;
}