#include <bits/stdc++.h>

using namespace std;

int main(){
	int N, K;
	int point[150], check[150]={0};
	int now, rslt=0;
	cin >> N >> K;
	for(int i=0;i<N;i++) cin >> point[i];
	now=0;
	while(1){
		if(check[now]){
			cout << "-1";
			break;
		}
		if(now==K){
			cout << rslt;
			break;
		}
		check[now] = 1;
		rslt++;
		now = point[now];
	}
}