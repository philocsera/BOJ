#include <iostream>

using namespace std;

int memo[41];

int fibo(int n) {
    if(!n) return 0;
    if(n == 1) return 1;
    if(memo[n]) return memo[n];	
    return memo[n] = fibo(n-1) + fibo(n-2);
}

int main(){
	int N, T;
	cin >> T;
	while(T--){
		cin >> N;
		cout << (N?fibo(N-1):1) << " " << fibo(N) << "\n";
	}
}