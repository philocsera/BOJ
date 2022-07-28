#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define con 1000000000
using namespace std;

ll memo[101][1024][10];

ll boo(int N, int now, int BM){
	if(!N){
		if((BM|(1<<now)) == 1023) return 1;
		else return 0;
	}
	ll& m = memo[N][BM][now];
	if(m!=-1) return m;

	N--;
	BM = BM|(1<<now);
	
	if(!now) return m = boo(N,now+1,BM)%con;
	else if(now==9) return m = boo(N,now-1,BM)%con;
	else return m = ( boo(N,now+1,BM)%con + boo(N,now-1,BM)%con )%con;
}

int main(){
	int N;
	ll rslt = 0;
	
	cin >> N;
	
	for(int i=1;i<=N;i++){
		for(int j=0;j<1024;j++){
			for(int k=0;k<10;k++){
				memo[i][j][k] = -1;
			}
		}
	}
	
	
	for(int i=1;i<=9;i++) rslt += boo(N-1,i,1<<i)%con;
	
	cout << rslt%con;
}