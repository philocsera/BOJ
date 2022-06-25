#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull boo(ull a, ull b, ull c){
	if(b==0) return 1;
	if(b%2){
		return a*boo(a*a%c,(b-1)/2,c)%c;
	}
	else{
		return boo(a*a%c,b/2,c)%c;
	}
}

int main(){
	ull a,b,c;
	cin >> a >> b >> c;
	cout << boo(a,b,c);
		
}