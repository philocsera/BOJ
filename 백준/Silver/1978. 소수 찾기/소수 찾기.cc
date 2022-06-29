#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, input, rslt=0, arr[1001] = {-1,-1};
	for(int i=2;i<=1000;i++){
		if(arr[i] == -1) continue;
		arr[i] = 0;
		for(int j=2;i*j<=1000;j++) arr[i*j] = -1;		
	}
	cin >> N;
	while(N--){
		cin >> input;
		if(!arr[input]) rslt++;  
	}
	cout << rslt;
}