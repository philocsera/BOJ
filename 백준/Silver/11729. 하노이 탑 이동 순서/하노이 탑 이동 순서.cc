#include <bits/stdc++.h>

using namespace std;

void Hanoi(int from, int by, int to, int n){
	if(n==2){
		cout << from << " " << by << "\n";
		cout << from << " " << to << "\n";
		cout << by << " " << to << "\n";
	}
	else{
		Hanoi(from,to,by,n-1);
		cout << from << " " << to << "\n";
		Hanoi(by,from,to,n-1);
	}
}

int main(){
	int n, rslt=0, pow=1;
	cin >> n;
	for(int i=1;i<=n;i++){
		rslt+=pow;
		pow*=2;
	}
	cout << rslt << "\n";
	if(n==1) cout << "1 3";
	else Hanoi(1,2,3,n);
}