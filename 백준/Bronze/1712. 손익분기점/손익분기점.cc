#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	if(c<=b) cout << "-1";
	else{
		cout << (int)(a/(c-b))+1;
	}
}