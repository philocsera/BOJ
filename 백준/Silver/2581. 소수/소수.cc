#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int M, N, sum=0, min=0, arr[10001] = {-1,-1};
	for(int i=2;i<=10000;i++){
		if(arr[i] == -1) continue;
		arr[i] = 0;
		for(int j=2;i*j<=10000;j++) arr[i*j] = -1;		
	}
	cin >> M >> N;
	for(int i=M;i<=N;i++){
		if(!arr[i]){
			sum += i;
			if(!min) min = i;
		} 
	}
	if(sum)	cout << sum << "\n" << min;
	else cout << "-1";
}