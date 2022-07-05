#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, x, y;
	cin >> T;
	while(T--){
		long long dis, test=0;
		int plag=1,min=1;
		cin >> x >> y;
		if(y-x == 1 || y-x == 2){
			cout << y-x << "\n";
			continue;
		}
		dis = y-x-2;
		for(int i=2;plag;i++){
			for(int j=0;j<2;j++){
				test += i;
				if(dis<=test){
					cout << min+2 << "\n";
					plag = 0;
					break;
				}
				min++;
			}
		}
	}
}