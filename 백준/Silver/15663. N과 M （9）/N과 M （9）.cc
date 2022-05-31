#include <bits/stdc++.h>

using namespace std;

void boo(int n,int m, int check[10001], int rslt[9]){
	if(n==m){
		for(int i=0;i<m;i++){
			cout << rslt[i] << " ";
		}
		cout << "\n";
		return;
	}
	for(int i=1;i<10001;i++){
		if(check[i]){
			check[i] -= 1;
			rslt[n] = i;
			boo(n+1,m,check,rslt);
			check[i] += 1;
		}
	}
}

int main(){
	int n, m, input;
	int check[10001] = {0,}, rslt[9]={0,};

	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> input;
		check[input]+=1;
	}
	
	boo(0,m,check,rslt);
}