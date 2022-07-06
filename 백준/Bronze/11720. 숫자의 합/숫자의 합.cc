#include <bits/stdc++.h>

using namespace std;

int main(){
	char input;
	int n, rslt=0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> input;
		rslt += input-'0';
	}
	cout << rslt;
}	