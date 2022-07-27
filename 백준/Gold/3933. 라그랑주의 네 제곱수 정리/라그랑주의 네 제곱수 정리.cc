#include <bits/stdc++.h>

using namespace std;

int memo[32769][182][4];

int boo(int now, int i, int cnt){
	if(!now) return 1;
	if(cnt == 4 || !i) return 0;
	
	int& m = memo[now][i][cnt];
	if(m != -1) return m;
	if(now < i*i) return m = boo(now,i-1,cnt);
	return m = boo(now-i*i,i,cnt+1) + boo(now,i-1,cnt);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N,i;
	
	for(int p=0;p<32769;p++){
		for(int q=0;q<182;q++){
			for(int r=0;r<4;r++){
				memo[p][q][r] = -1;
			}
		}
	}
	
	while(1){
		
		cin >> N;
		if(!N) break;
		
		for(i=1;i*i<=N;i++);

		cout << boo(N,i-1,0) << "\n";
	}
}