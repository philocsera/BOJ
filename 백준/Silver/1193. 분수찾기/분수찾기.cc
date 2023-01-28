#include <bits/stdc++.h>

using namespace std;

int main(){
	int x, i=1;
	cin >> x;
	for(;x>i;i++) x-=i;
	if(i%2) cout << (i+1)-x << "/" << x;
	else cout << x << "/" << (i+1)-x;
}