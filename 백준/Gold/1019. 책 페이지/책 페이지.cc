#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll N, digit, remain;
	ll rslt[10];
	cin >> N;

	for(digit=1;digit<=N;digit*=10);
	digit/= 10;
	for(int i=0;i<10;i++) rslt[i] = 0;
	remain = N;

	ll now = N/digit;
	while(1){
		for(int i=1;i<=9;i++){
			rslt[i] += (N/(digit*10) + (i<=now)) * digit;
		}

		rslt[0] += (N/(digit*10)) * digit;
		rslt[now] -= (digit-1) - (N%digit);

		digit /= 10;
		if(!digit) break;
		remain -= now*digit*10;
	        now = remain / digit;
	}

	for(int i=0;i<10;i++) cout << rslt[i] << " ";
}