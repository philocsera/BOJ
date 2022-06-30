#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, arr[246913]={-1,-1}, rslt;
	for(int i=2;i<246913;i++){
		if(arr[i] == -1) continue;
		arr[i] = 0;
		for(int j=2;i*j<246913;j++) arr[i*j] = -1;
	}
	while(1){
		cin >> n;
		if(!n) break;
		rslt = 0;
		for(int i=n+1;i<=2*n;i++){
			if(!arr[i]) rslt++;
		}
		cout << rslt << "\n";
	}
	
}