#include <bits/stdc++.h>

using namespace std;

int main(){
	int m, n;
	int min, rslt=0;
	cin >> m >> n;
	for(int i=n;i>=m;i--){
		for(int j=1;j<=100 && j<=i;j++){
			if(j*j==i){
				min = i;
				rslt += i;
			}
		}
	}
	if(rslt) cout << rslt << "\n" << min;
	else cout << "-1";
}	