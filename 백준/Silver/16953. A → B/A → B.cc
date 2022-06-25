#include <iostream>
#define INF 1e11
using namespace std;

long min(long a, long b){
	return a>b?b:a;
}

long boo(long a, long b){
	if(a>b) return INF;
	if(a==b) return 1;
	return min(boo(a*2,b),boo(a*10+1,b))+1;
}

int main(){
	long a, b;
	cin >> a >> b;
	long rslt = boo(a,b);
	if(rslt<INF) cout << rslt;
	else cout << -1;
}