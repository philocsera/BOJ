#include <bits/stdc++.h>
 
using namespace std;
 
int memo[1000000], goal;
 
int boo(int now){
	if(now==goal) return 1;
	if(now>goal) return 0;
	if(memo[now]) return memo[now];
	return memo[now] = ( boo(now+1) + boo(now+2) )%15746;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	cin >> goal;
	cout << boo(0)%15746;
}	