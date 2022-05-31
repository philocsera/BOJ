#include <iostream>

using namespace std;

int P[10001], memo[1001];

int boo(int n){
	if(memo[n]) return memo[n];
	int max=0,price;
	for(int i=1;i<=n;i++){
		price = boo(n-i) + P[i];
		if(max<price) max=price; 
	}
	return memo[n] = max;
}

int main(){
	int N;
	cin >> N;
	for(int i=1;i<=N;i++) cin >> P[i];
	cout << boo(N);
}