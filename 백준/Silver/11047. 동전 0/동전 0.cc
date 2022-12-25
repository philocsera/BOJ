#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k, temp, rslt = 0;
	int coinV[10];
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> coinV[i];
	}
	for(int i=n-1;i&&k;i--){
		if(coinV[i] <= k){
			k -= coinV[i];
			rslt++;
			i++;
		}
	}
	cout << rslt+k << endl;
}