#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main(){
	int N;
	ull rslt = 1;
	cin >> N;
	if(N == 1){
		cout << "0";
		return 0;
	}
	rslt *= 2;
	for(int i=0;i<N-2;i++){
		rslt *= 3;
		rslt %= 1000000009;
	}
	cout << rslt;
}