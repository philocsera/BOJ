#include <bits/stdc++.h>

using namespace std;

int main(){
	int K, N = 0, input;
	int arr[100'000] = {0};

	cin >> K;

	while(K--){
		cin >> input;
		if(input) arr[N++] = input;
		else N--;
	}

	int sum = 0;
	for(int i=0;i<N;i++){
		sum += arr[i];
	}
	cout << sum;
}