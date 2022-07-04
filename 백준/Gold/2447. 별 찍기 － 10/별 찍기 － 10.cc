#include <bits/stdc++.h>

using namespace std;

bool star[6562][6562];
void boo(int lx, int ly, int n, int fill){
	if(n==1){
		if(fill) star[ly][lx] = 1;
		else star[ly][lx] = 0;
	}
	else{
		for(int i=0;i<3;i++) boo(lx+n/3*i,ly,n/3,fill);
		for(int i=0;i<3;i++) boo(lx+n/3*i,ly+n/3,n/3,(fill?!(i%2):fill));
		for(int i=0;i<3;i++) boo(lx+n/3*i,ly+2*n/3,n/3,fill);
	}
}

int main(){
	int n;
	cin >> n;
	boo(1,1,n,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(star[i][j]) cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}
}