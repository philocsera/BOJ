#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int sum[100001] = {0}, temp, N, M;
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		cin >> temp;
		sum[i] = sum[i-1] + temp;
	}

	int a, b;
	for(int i=0;i<M;i++){
		cin >> a >> b;
		cout << sum[b] - sum[a-1] << "\n";
	}
}