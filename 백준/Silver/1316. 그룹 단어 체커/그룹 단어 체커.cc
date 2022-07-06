#include <bits/stdc++.h>
#define toN(str) (str-'a')
using namespace std;

int main(){
	string s;
	int i, N, rslt=0, plag, len;
	cin >> N;
	while(N--){
		int alpha[26]={0};
		cin >> s;
		plag = 1;
		len = s.length();
		alpha[toN(s[0])]=1;
		for(i=1;i<len;i++){
			if(alpha[toN(s[i])] && s[i-1] != s[i]) plag=0;
			alpha[toN(s[i])] = 1;
		}
		if(plag) rslt++;
	}
	cout << rslt;
}	