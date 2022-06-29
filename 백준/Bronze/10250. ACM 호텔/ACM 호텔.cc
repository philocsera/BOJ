#include <bits/stdc++.h>

using namespace std;

int main(){
	int T, H, W, N;
	cin >> T;
	while(T--){
		cin >> H >> W >> N;
		if(N%H) cout << N%H << ((N/H<9)?"0":"") << (int)(N/H)+1;
		else cout << H << ((N/H<10)?"0":"") << (int)(N/H);
		cout << "\n";
	}
}