#include <bits/stdc++.h>
using namespace std;

int main(){
	int Big[10003] = {0};
	int aLen, bLen, i;
	string a,b;
	cin >> a >> b;
	aLen = a.length();
	bLen = b.length();
	for(i=1;aLen||bLen;i++){
		if(Big[i-1]>=10){
			Big[i-1] -= 10;
			Big[i] = 1;
		} 
		if(aLen) Big[i] += a[--aLen]-'0';
		if(bLen) Big[i] += b[--bLen]-'0';
	}
	for(int j=i-1;j;j--) cout << Big[j];
}