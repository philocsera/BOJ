#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll memo[1000001];

int boo(int N){
	if(N<=1) return 1;
	if(memo[N]) return memo[N];
	if(2<=N&&N<=4) return N;
	return memo[N] = (3 * boo(N-3))%10007;
}

int main(){
	int N;
	cin >> N;
	if(!N) cout << 0;
	else cout << boo(N);
}