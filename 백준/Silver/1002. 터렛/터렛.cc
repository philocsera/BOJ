#include <bits/stdc++.h>

using namespace std;

int main(){
	long x[2],y[2],r[2],rSum,T;
	long double d;
	cin >> T;
	while(T--){
		for(int i=0;i<2;i++) cin >> x[i] >> y[i] >> r[i];
		if(x[0]==x[1]&&y[0]==y[1]){ // 동심원
			if(r[0]==r[1]) cout << -1;
			else cout << 0;
			cout << "\n";
			continue;
		}
		rSum=r[0]+r[1];
		d=sqrt( (x[1]-x[0])*(x[1]-x[0]) + (y[1]-y[0])*(y[1]-y[0]) );
		if(d < rSum){
			if(d+r[1]<r[0]||d+r[0]<r[1]) cout << 0;
			else if(d+r[1]-r[0]<0.01||d+r[0]-r[1]<0.01) cout << 1;
			else cout << 2;
		}
		else if(d == rSum) cout << 1;
		else cout << 0;
		cout << "\n";
	}
}