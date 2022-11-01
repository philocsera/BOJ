#include <bits/stdc++.h>

using namespace std;

int main(){
	int sum, N, a, b;
	cin >> sum >> N;

	while(N--){
		cin >> a >> b;
		sum -= a*b;
	}

	if(sum) cout << "No";
	else cout << "Yes";
}