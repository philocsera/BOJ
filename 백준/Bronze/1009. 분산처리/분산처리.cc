#include <bits/stdc++.h>

using namespace std;

int main(){
	int T, a, b, rslt;
	int arr[10][4];

	int temp;
	for(int i=2;i<=9;i++){
		temp = i;
		for(int j=1;j<=4;j++){
			arr[i][j%4] = temp%10;
			temp *= i; 
		}
	}
	cin >> T;
	while(T--){
		rslt = 1;
		cin >> a >> b;
		a %= 10;
		if(!a) cout << "10";
		else if(a==1 || a==5 || a==6) cout << a;
		else{
			cout << arr[a][b%4];
		}
		cout << "\n";
	}

}