#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, n, plag;
	cin >> m >> n;
	if(m==1) m=2;
	for(int i=m;i<=n;i++){
		plag=1;
		for(int j=2;j<=sqrt(i);j++){
			if(!(i%j)){
				plag=0;
				break;
			}
		}
		if(plag) cout << i << "\n";
	}
}