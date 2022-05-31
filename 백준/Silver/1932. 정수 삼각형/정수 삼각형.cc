#include <iostream>
using namespace std;

int tri[501][501], memo[501][501], n;

int max(int a,int b){
	return a>b?a:b;
}

long boo(int i, int j){
	if(i == n) return 0;
	if(memo[i][j]) return memo[i][j];
	return memo[i][j] = tri[i][j] + max(boo(i+1,j),boo(i+1,j+1));
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++) for(int j=0;j<=i;j++) cin >> tri[i][j];
	cout << boo(0,0);
}