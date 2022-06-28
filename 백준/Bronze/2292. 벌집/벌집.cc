#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, i=1;
	cin >> n;
	n-=1;
	for(;n>0;i++){
		n -= i*6;
	}
	cout << i;
}